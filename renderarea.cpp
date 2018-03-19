#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent),autoCell(10),zoom(1)
{
   // OneD(int width, int cellWidth, int cellHeight,int cellStates,int r,int nb_neighborhood)
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(play()));
}

QSize RenderArea::sizeHint() const
{
    return QSize(width(),height());
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(400,200);
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
//if()
if(autoCell.getWidth()>autoCell.getHeight())
    zoom=(double)width()/(double)(autoCell.getWidth()*autoCell.getCellWidth());
if(autoCell.getHeight()*autoCell.getCellHeight()*zoom>height())
    zoom=(double)height()/(double)(autoCell.getHeight()*autoCell.getCellHeight());

qDebug() << width() << "//"<< height() << "//" << autoCell.getCellWidth() <<"//" <<autoCell.getWidth() << zoom;
    painter.scale(zoom,zoom);
    drawOneD(painter);
}


void RenderArea::next()
{
    for(int i =0;i<1;i++)
    autoCell.nextState();
    update();
}



void RenderArea::play()
{
    timer->start(10);
    autoCell.nextState();
    update();
    if(autoCell.getWidth()>1920)
    {
        timer->stop();
        emit pause();
    }
}

void RenderArea::playIsChecked(bool checked)
{
    if(checked)
    {
        play();
    }
    else{
        timer->stop();
    }
}


void RenderArea::mousePressEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::LeftButton) {
        autoCell.changeCellState(QPoint(ev->pos().x()/zoom,ev->pos().y()/zoom));
        update();

    }
}
