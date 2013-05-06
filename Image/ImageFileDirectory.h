#ifndef IMAGEFILEDIRECTORY_H
#define IMAGEFILEDIRECTORY_H

#include <QObject>
#include <QString>
#include <QQmlListProperty>

#include "ImageFile.h"

class ImageFileDirectory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString directory READ getDirectory WRITE setDirectory NOTIFY directoryChanged)
    Q_PROPERTY(QList<QObject*> imageFiles READ getImageFiles NOTIFY imageFilesChanged)

public:
    explicit ImageFileDirectory(QObject *parent = 0);

    QString getDirectory() const;
    void setDirectory(const QString& dir);

    const QList<QObject*>& getImageFiles() const;


signals:
    void directoryChanged();
    void imageFilesChanged();
    
public slots:

private:
    QString directory;
    QList<QObject*> imageFiles;
    
};

#endif // IMAGEFILEDIRECTORY_H
