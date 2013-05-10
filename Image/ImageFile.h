#ifndef IMAGEFILE_H
#define IMAGEFILE_H

#include <QObject>
#include <QImage>
#include <QString>

class ImageFile : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(int width READ getWidth WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ getHeight WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(int fileSize READ getFileSize WRITE setFileSize NOTIFY fileSizeChanged)

public:
    explicit ImageFile(QObject *parent = 0);
    explicit ImageFile(const QString& fn, QObject *parent = 0);

    void setFileName(const QString& fn) {
        if (fn != fileName) {
            fileName = fn;
            emit fileNameChanged();
        }
    }

    QString getFileName() const {
        return fileName;
    }

    void setWidth(int w) {
        if (width != w) {
            width = w;
            emit widthChanged();
        }
    }

    int getWidth() const {
        return width;
    }

    void setHeight(int h) {
        if (height != h) {
            height = h;
            emit heightChanged();
        }
    }

    int getHeight() const {
        return height;
    }

    void setFileSize(int fs) {
        if (fs != fileSize) {
            fileSize = fs;
            emit fileSizeChanged();
        }
    }

    int getFileSize() const {
        return fileSize;
    }

signals:
    void fileNameChanged();
    void widthChanged();
    void heightChanged();
    void fileSizeChanged();

public slots:

private:
    QString fileName;
    int width;
    int height;
    int fileSize;
};

#endif // IMAGEFILE_H
