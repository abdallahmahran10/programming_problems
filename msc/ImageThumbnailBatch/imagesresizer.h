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
