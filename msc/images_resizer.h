#ifndef COMMON_H
#define COMMON_H
#include <vector>
#include <string>
#include <QImage>
#include <QString>
#include <QFile>
#include <QDir>
#include <queue>
#include <iostream>

using std::queue;
using std::vector;
using std::string;
using std::cout;
using std::endl;

inline QString join(QString mOutputFolder, QString name)
{
    return QDir(mOutputFolder).filePath(name);
}

#endif // COMMON_H


/*************************************************************************************************************************/
#ifndef IMAGE_H
#define IMAGE_H
#include "common.h"
#include <QFileInfo>

class Image: public QImage
{
    QString mPath;
    QString mFilename;

    void init()
    {
        QFileInfo fi(mPath);
        mFilename = fi.fileName();
    }
public:

    Image(const QString &path):QImage(path),mPath(path)
    {
        init();
    }
    // getters
    QString path() { return mPath;}
    QString filename() {return mFilename;}
};
#endif // IMAGE_H

/*************************************************************************************************************************/
#ifndef IMAGESRESIZER_H
#define IMAGESRESIZER_H


#include "resizerthread.h"

class ImagesResizer
{
    SafeQueue<Image> imagesQueue;
    ResizerThread *mResizer1;
    ResizerThread *mResizer2;
    unsigned int mImagesQueueLimit;
    QString mOutputFolder;

    void runResizers();
    bool isFull();
    void finalize();
public:
    ImagesResizer(unsigned int imagesQueueLimit, QString outputFolder);
    void resize(vector<QString> inputs);
};

#endif // IMAGESRESIZER_H

/*************************************************************************************************************************/
#ifndef RESIZERTHREAD_H
#define RESIZERTHREAD_H
#include "safequeue.h"
#include "image.h"

#include <QThread>

class ResizerThread : public QThread
{
    Q_OBJECT
    SafeQueue<Image> &mImagesQueue;
    QString mOutputFolder;

public:
    string name;

    ResizerThread(SafeQueue<Image> &imagesQueue, const QString &outputFolder):mImagesQueue(imagesQueue), mOutputFolder(outputFolder)
    {
        connect(this, SIGNAL(finished()), this, SLOT(OnFinished()));
    }

public slots:
    virtual void OnFinished()
    {
        cout<<"OnFinished"<<endl;
        if(!mImagesQueue.empty())
        {
            cout<<"mImagesQueue is not empty"<<endl;
            start();
        }
    }

protected:
    void run()
    {
        while(!mImagesQueue.empty())
        {
            Image image = mImagesQueue.dequeue();
            cout<<name<< "resize: "<<image.filename().toStdString()<<endl;
            resizeAndSave(image);
        }
    }

private:
    void resizeAndSave(Image &image)
    {
        QImage img = image.scaledToWidth(100);
        QString name = image.filename();
        QString path = join(mOutputFolder, name);
        img.save(path);
    }

};

#endif // RESIZERTHREAD_H

/*************************************************************************************************************************/
#ifndef SAFEQUEUE_H
#define SAFEQUEUE_H
#include <mutex>
#include <condition_variable>
#include "common.h"

// A threadsafe-queue.
template <class T>
class SafeQueue
{
public:
  SafeQueue(void)
    : q()
    , m()
    , c()
  {}

  ~SafeQueue(void)
  {}

  // Add an element to the queue.
  void enqueue(T t)
  {
    std::lock_guard<std::mutex> lock(m);
    q.push(t);
    c.notify_one();
  }

  T dequeue(void)
  {
    std::unique_lock<std::mutex> lock(m);
    T val = q.front();
    q.pop();
    c.notify_one();
    return val;
  }

//  void pop(void)
//  {
//    std::unique_lock<std::mutex> lock(m);
//    q.pop();
//    c.notify_one();
//  }

  int size()
  {
      std::lock_guard<std::mutex> lock(m);
      int s = q.size();
      return s;
  }

  int empty()
  {
      std::lock_guard<std::mutex> lock(m);
      bool empty = q.empty();
      return empty;
  }

private:
  queue<T> q;
  mutable std::mutex m;
  std::condition_variable c;
};
#endif // SAFEQUEUE_H

/*************************************************************************************************************************/
#include "imagesresizer.h"

ImagesResizer::ImagesResizer(unsigned int imagesQueueLimit, QString outputFolder)
    :mOutputFolder(outputFolder),mImagesQueueLimit(imagesQueueLimit), mResizer1(NULL), mResizer2(NULL)
{

}

bool ImagesResizer::isFull()
{
    return imagesQueue.size() >= mImagesQueueLimit;
}

void ImagesResizer::runResizers()
{
    if(!mResizer1->isRunning() )
        mResizer1->start();
    if(!mResizer2->isRunning() )
        mResizer2->start();
}
void ImagesResizer::finalize()
{
    runResizers();
    mResizer1->wait();
    mResizer2->wait();
    delete mResizer1;
    delete mResizer2;
}
void ImagesResizer::resize(vector<QString> inputs)
{
    mResizer1 = new ResizerThread(imagesQueue, mOutputFolder);
    mResizer2 = new ResizerThread(imagesQueue, mOutputFolder);
    mResizer1->name = "Thread 1: ";
    mResizer2->name = "Thread 2: ";
    for(int i=0; i<inputs.size(); i++)
    {
        if(isFull())
        {
            runResizers();
            while(isFull());
        }
        imagesQueue.enqueue(Image(inputs[i]));
    }
    finalize();
}

/*************************************************************************************************************************/
#include "imagesresizer.h"

#define QUEUE_LIMIT 10


bool file_exits(string p)
{
    return true;
}

int main(int argc, char *argv[])
{
    vector<QString> inputs;
    int i;
    for(i=1; i<argc-1; i++)
        if(file_exits(argv[i]))
            inputs.push_back(argv[i]);
    QString outputFolder = argv[i];
    ImagesResizer imgsResizer(QUEUE_LIMIT, outputFolder);
    imgsResizer.resize(inputs);
}
