#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include "renderarea.h"
#include <QToolBar>
#include "newautocell.h"
#include "openautocell.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    NewAutoCell *newCellDialog;
    OpenAutoCell *openCellDialog;

public slots:
    void pause();
    void createNewAutoCell();
    void openAutoCell();
    void saveAutoCell();
};

#endif // MAINWINDOW_H
