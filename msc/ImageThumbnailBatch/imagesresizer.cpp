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
