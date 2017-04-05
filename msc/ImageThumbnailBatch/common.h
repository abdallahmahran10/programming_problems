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
#include <fstream>

using std::queue;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

inline QString join(QString mOutputFolder, QString name)
{
    return QDir(mOutputFolder).filePath(name);
}

inline bool file_exists(const string& name) {
    ifstream f(name.c_str());
    return f.good();
}
#endif // COMMON_H
