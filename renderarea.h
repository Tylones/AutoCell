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
    void drawOneD(QPainter &painter);
    void drawOneD(QPainter &painter,int state);

	AutoCell *getAutoCell() const;
	void setAutoCell(AutoCell *value);

public slots:
    void next();
    void play();
    void playIsChecked(bool checked);

signals:
     void pause();


protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
	AutoCell *autoCell;
    double zoom;
    QTimer *timer;




private:


};

#endif // RENDERAREA_H
