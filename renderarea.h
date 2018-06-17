#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include<QPainter>
#include <QMouseEvent>
#include "autocell.h"
#include "quadlife.h"
#include"oned.h"
#include"jeuvie.h"
#include "sleeper.h"
#include <QTimer>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    /*!
     * \brief drawAutoCell affiche l'état actuel de l'automate
     * \param painter - QPainter
     */
    void drawAutoCell(QPainter &painter);
	void drawAutoCell(QPainter &painter,int state);

    AutoCell *getAutoCell() const;
	void setAutoCell(AutoCell *value);

public slots:
    /*!
     * \brief next passe à l'état suivant
     */
    void next();
    /*!
     * \brief changeVitesse change la vitesse d'exécution de l'automate
     */
    void changeVitesse(int);
    /*!
     * \brief previous passe à l'état précédent
     */
	void previous();
    /*!
     * \brief play lance l'exécution de l'automate
     */
    void play();
    /*!
     * \brief si le bouton play est enclenché, lance play(), sinon arrête le timer
     * \param checked - booléen vrai si le bouton play est enclenché
     */
    void playIsChecked(bool checked);
    /*!
     * \brief generate_randomly génère un état aléatoire
     */
	void generate_randomly();
    /*!
     * \brief reinit remet l'automate à zéro
     */
	void reinit();

signals:
    /*!
      * \brief pause mets l'exécution de l'automate en pause
      */
     void pause();


protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
	/*!
	 * \brief autoCell affiché dans le renderArea
	 */
	AutoCell *autoCell;
    double zoom;
    QTimer *timer;
	/*!
	 * \brief vitesse de générations de nouveaux états lors du "play" pour l'automate affiché
	 */
    int vitesse;



private:


};

#endif // RENDERAREA_H
