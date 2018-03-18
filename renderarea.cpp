#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent),autoCell(20),zoom(1)
{

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(play()));



}

QSize RenderArea::sizeHint() const
{
    return QSize(autoCell.getWidth()*autoCell.getCellWidth()*zoom, autoCell.getHeight()*autoCell.getCellHeight()*zoom);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(autoCell.getWidth()*10,autoCell.getHeight()*10);
}



void RenderArea::drawOneD(QPainter &painter)
{

QVector< QVector<int> > matrice=autoCell.getMatrice();
    QVector< QVector<int> >::iterator row;
    QVector<int>::iterator col;
    for (row = matrice.begin(); row != matrice.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            //painter.drawRect((row-matrice.begin())*10,(col-row->begin())*10,10,10);
            if(*col==1)
                painter.fillRect((row-matrice.begin())*10,(col-row->begin())*10,10,10,Qt::SolidPattern);
        }
    }


}

void RenderArea::drawOneD(QPainter &painter,int state)
{

    QVector< QVector<int> > matrice=autoCell.getMatrice();
        QVector< QVector<int> >::iterator row;
        QVector<int>::iterator col;
        for (row = matrice.begin(); row != matrice.end(); row++) {
            col = row->begin()+state;
                painter.drawRect((row-matrice.begin())*10,(col-row->begin())*10,10,10);
                if(*col==1)
                    painter.fillRect((row-matrice.begin())*10,(col-row->begin())*10,10,10,Qt::SolidPattern);

        }



}



void RenderArea::paintEvent(QPaintEvent * /* event */)
{

QPainter painter(this);
if(autoCell.getWidth()>autoCell.getHeight())
    zoom=(double)width()/(double)(autoCell.getWidth()*autoCell.getCellWidth());
else
    zoom=(double)height()/(double)(autoCell.getHeight()*autoCell.getCellHeight());

    painter.scale(zoom,zoom);
    drawOneD(painter);
}


void RenderArea::next()
{
    for(int i =0;i<1000;i++)
    autoCell.nextState();
    update();
}

void RenderArea::pause()
{
    timer->stop();
}

void RenderArea::play()
{
    timer->start(10);
    autoCell.nextState();
    update();
}


void RenderArea::mousePressEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::LeftButton) {
        autoCell.changeCellState(QPoint(ev->pos().x()/zoom,ev->pos().y()/zoom));
        update();

    }
}
