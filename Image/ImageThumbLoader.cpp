#include "ImageThumbLoader.h"

ImageLoader::ImageLoader()
    : QQuickImageProvider(Image)
    , thumbWidth(280)
    , thumbHeight(120)
{
}

QImage ImageLoader::requestImage(const QString &id, QSize *size, const QSize& requestedSize) {
    qDebug() << id;
    return loadFile("");
//    if (!imageFiles.contains(id)) {
//        return *loadFile(id);
//    }

//    return *imageFiles.value(id);
//    image.load("D:\\Photo\\greece\\IMG_2269.jpg");
//    image = image.scaled(120, 50);
//    return *image;
}

void ImageLoader::resetImageCache() {
//   imageFiles.clear(); // TODO delete all images
}

QImage ImageLoader::loadFile(const QString& fileName) {
    QImage image;
    if (!image.load(":/Resources/test_image.jpg")) {
        return QImage();
    }

    return image.scaled(thumbWidth, thumbHeight);
}
