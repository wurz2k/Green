#include <QApplication>
#include <QtGlobal>
#include <QtCore>
#include <QtQuick/QQuickView>
#include <QQmlContext>
#include <QTime>
#include <QtQml/qqml.h>

#include "Image/ImageThumbLoader.h"
#include "Image/ImageFile.h"
#include "Image/ImageFileDirectory.h"

#include <fstream>

using namespace std;
ofstream logfile;

#define PREFIX QTime::currentTime().toString("hh:mm:ss.zzz").toStdString()

void simpleLoggingHandler(QtMsgType type, const QMessageLogContext &ctx, const QString &msg) {
    logfile << QTime::currentTime().toString("hh:mm:ss.zzz").toStdString();

    switch (type) {
    case QtDebugMsg:
        logfile << " DEB ";
        break;
    case QtWarningMsg:
        logfile << " WARN ";
        break;
    case QtCriticalMsg:
        logfile << " CRITICAL ";
        break;
    case QtFatalMsg:
        logfile << " FATAL ";
        break;
    }

    logfile << msg.toStdString();

    logfile << " [" << ctx.file << ":" << ctx.line << "]";

    logfile  << std::endl;
}


int main(int argc, char *argv[])
{
    logfile.open("./green.log", ios::app);
    qInstallMessageHandler(simpleLoggingHandler);

    QApplication a(argc, argv);

    ImageFileDirectory imageDirectory;
    QQuickView view;
    ImageLoader imageLoader;

    view.engine()->addImageProvider("imagethumb", &imageLoader);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.engine()->rootContext()->setContextProperty("imageDirectory", &imageDirectory);
    view.engine()->rootContext()->setContextProperty("imageThumbLoader", &imageLoader);
    view.setSource(QUrl("qrc:/ImagesList.qml"));
//    view.setSource(QUrl("qrc:/Dashboard.qml"));
    view.show();

    
    return a.exec();
}
