#ifndef IMAGEFILEDIRECTORY_H
#define IMAGEFILEDIRECTORY_H

#include <QObject>
#include <QString>
#include <QtCore>
#include <QQmlListProperty>
#include <QQuickImageProvider>
#include <QImage>
#include <QCache>
#include <QSize>

#include "ImageFile.h"

class ImageFileDirectory : public QObject, public QQuickImageProvider
{
    Q_OBJECT
    Q_PROPERTY(QString directory READ getDirectory WRITE setDirectory NOTIFY directoryChanged)
    Q_PROPERTY(QList<QObject*> imageFiles READ getImageFiles NOTIFY imageFilesChanged)
    Q_PROPERTY(QSize thumbSize READ getThumbSize WRITE setThumbSize NOTIFY thumbSizeChanged)

public:
    explicit ImageFileDirectory(const QString& dir, const QSize& thumbSize, QObject *parent = 0);

    QString getDirectory() const;
    void setDirectory(const QString& dir);

    void setThumbSize(const QSize& size);
    QSize getThumbSize();

    const QList<QObject*>& getImageFiles() const;

    virtual QImage requestImage(const QString &id, QSize *size, const QSize& requestedSize);

signals:
    void directoryChanged();
    void imageFilesChanged();
    void thumbSizeChanged();
    
public slots:

private:
    QSize thumbSize;

    QString directory;
    QList<QObject*> imageFiles;
    QCache<QString, QImage> thumbImages;

    QImage loadFile(const QString& fileName);
};

#endif // IMAGEFILEDIRECTORY_
