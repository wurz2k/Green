#include "ImageFileDirectory.h"

ImageFileDirectory::ImageFileDirectory(const QString& dir, const QSize& size, QObject *parent)
    : QObject(parent)
    , QQuickImageProvider(Image)
    , directory(dir)
    , thumbSize(size)
{
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
    imageFiles.append(new ImageFile("D:\\Photo\\greece\\IMG_2269.jpg"));
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

void ImageFileDirectory::setThumbSize(const QSize& size) {
    if (thumbSize != size) {
        thumbSize = size;
        thumbSizeChanged();
    }
}

QSize ImageFileDirectory::getThumbSize() {
    return thumbSize;
}

QImage ImageFileDirectory::requestImage(const QString &id, QSize *size, const QSize& requestedSize) {
    QImage image;
    if (!image.load(":/Resources/test_image.jpg")) {
        return QImage();
    }

    return image.scaled(thumbSize.width(), thumbSize.height());
}
