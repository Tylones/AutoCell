#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);


    MainWindow w;
    w.show();
	QObject::connect(&a, &QApplication::aboutToQuit,&w,&MainWindow::saveAutoCellQuit);

    return a.exec();
}
