#include "ImageFile.h"

ImageFile::ImageFile(QObject *parent) :
    QObject(parent)
{
}

ImageFile::ImageFile(const QString& fn, QObject *parent) :
    QObject(parent), fileName(fn)
{

}

