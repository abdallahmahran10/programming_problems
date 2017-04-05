#include "image.h"

Image::Image(const QString &path):QImage(path),mPath(path)
{
    init();
}
void Image::init()
{
    QFileInfo fi(mPath);
    mFilename = fi.fileName();
}

// getters
QString Image::path()
{
    return mPath;
}
QString Image::filename()
{
    return mFilename;
}
