#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include "renderarea.h"
#include <QToolBar>
#include "newautocell.h"
#include "openautocell.h"
#include <QSlider>
namespace Ui {
class MainWindow;
}

/*!
 * \brief La classe MainWindow
 */
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
    QSlider *vitesseSlider;

public slots:
    /*!
     * \brief mets l'automate en pause
     */
    void pause();
    /*!
     * \brief createNewAutoCell crée un automate cellulaire à partir des données récupérées de la fenêtre NewAutoCell
     */
    void createNewAutoCell();
    /*!
     * \brief openAutoCell ouvre l'automate sélectionné (config+dernier état) dans la fenêtre OpenAutoCell
     */
    void openAutoCell();
    /*!
     * \brief saveAutoCell sauvegarde la configuration de l'automate
     */
    void saveAutoCell();
    /*!
     * \brief saveAutoCellandState sauvegarde la configuration et le dernier état de l'automate
     */
	void saveAutoCellandState();
    /*!
     * \brief saveAutoCellQuit sauvegarde le contexte de l'application
     */
	void saveAutoCellQuit();
    /*!
     * \brief openContextAutoCell charge le contexte à l'ouverture
     */
	void openContextAutoCell();
};

#endif // MAINWINDOW_H
