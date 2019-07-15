#include "mainwindow.h"
#include <QtGui>
#include<QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    NoteBook *window = new NoteBook();
    window->resize(850,450);
    window->show();




    return app.exec();
}
