#include "resizerthread.h"


ResizerThread::ResizerThread(SafeQueue<Image> &imagesQueue, const QString &outputFolder):mImagesQueue(imagesQueue), mOutputFolder(outputFolder)
{
    connect(this, SIGNAL(finished()), this, SLOT(OnFinished()));
}


void ResizerThread::OnFinished()
{
    cout<<"OnFinished"<<endl;
    if(!mImagesQueue.empty())
    {
        cout<<"mImagesQueue is not empty"<<endl;
        start();
    }
}

void ResizerThread::run()
{
    while(!mImagesQueue.empty())
    {
        Image image = mImagesQueue.dequeue();
        cout<<name<< "resize: "<<image.filename().toStdString()<<endl;
        resizeAndSave(image);
    }
}


void ResizerThread::resizeAndSave(Image &image)
{
    QImage img = image.scaledToWidth(100);
    QString name = image.filename();
    QString path = join(mOutputFolder, name);
    img.save(path);
}
