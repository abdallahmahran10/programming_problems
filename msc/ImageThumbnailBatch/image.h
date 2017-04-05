#ifndef IMAGE_H
#define IMAGE_H
#include "common.h"
#include <QFileInfo>

class Image: public QImage
{
private:
    QString mPath;
    QString mFilename;

    void init();
public:

    Image(const QString &path);
    QString path();
    QString filename();
};
#endif // IMAGE_H
