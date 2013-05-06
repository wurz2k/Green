#include "ImageFileDirectory.h"

ImageFile* loadImage(ImageFile* file) {
    QImage image;
    if (image.load(file->getFileName())) {
        file->setImage(image);
    }

    return file;
}

ImageFileDirectory::ImageFileDirectory(QObject *parent) :
    QObject(parent)
{
    imageFiles.append(loadImage(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg")));




    directory = "d:\\photo";
}

QString ImageFileDirectory::getDirectory() const {
    return directory;
}

void ImageFileDirectory::setDirectory(const QString& dir) {
    if (dir != directory) {
        directory = dir;
        emit directoryChanged();
    }
}

const QList<QObject*>& ImageFileDirectory::getImageFiles() const {
    return imageFiles;
}
