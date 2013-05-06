#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QtCore>
#include <QQuickImageProvider>
#include <QCache>

class ImageLoader : public QObject, public QQuickImageProvider
{
    Q_OBJECT
    Q_PROPERTY(int thumbWidth READ getThumbWidth WRITE setThumbWidth NOTIFY thumbWidthChanged)
    Q_PROPERTY(int thumbHeight READ getThumbHeight WRITE setThumbHeight NOTIFY thumbHeightChanged)
public:
    ImageLoader();

    virtual QImage requestImage(const QString &id, QSize *size, const QSize& requestedSize);

    int getThumbWidth() const {
        return thumbWidth;
    }

    void setThumbWidth(int w) {
        if (thumbWidth != w) {
            thumbWidth = w;
            resetImageCache();
            emit thumbWidthChanged();
        }
    }

    int getThumbHeight() const {
        return thumbHeight;
    }

    void setThumbHeight(int h) {
        if (thumbHeight != h) {
            thumbHeight = h;
            resetImageCache();
            emit thumbHeightChanged();
        }
    }

signals:
    void thumbWidthChanged();
    void thumbHeightChanged();

public slots:
    void resetImageCache();

private:
    int thumbWidth;
    int thumbHeight;
    QCache<QString, QImage> imageFiles;

    QImage loadFile(const QString& fileName);
};

#endif // IMAGELOADER_H
