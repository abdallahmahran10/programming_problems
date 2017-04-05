#ifndef RESIZERTHREAD_H
#define RESIZERTHREAD_H

#include "safequeue.h"
#include "image.h"

#include <QThread>

class ResizerThread : public QThread
{
private:
    Q_OBJECT
    SafeQueue<Image> &mImagesQueue;
    QString mOutputFolder;

    void resizeAndSave(Image &image);
public:
    string name;
    ResizerThread(SafeQueue<Image> &imagesQueue, const QString &outputFolder);

public slots:
    virtual void OnFinished();

protected:
    void run();


};

#endif // RESIZERTHREAD_H
