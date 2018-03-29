#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent),zoom(1),autoCell(nullptr)
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
    if(autoCell!=nullptr)
    {
        QVector< QVector<int> > matrice=autoCell->getMatrice();
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
}




void RenderArea::paintEvent(QPaintEvent * /* event */)
{

    QPainter painter(this);
    if(autoCell!=nullptr)
    {
        if(autoCell->getWidth()>autoCell->getHeight())
            zoom=(double)width()/(double)(autoCell->getWidth()*autoCell->getCellWidth());
        if(autoCell->getHeight()*autoCell->getCellHeight()*zoom>height())
            zoom=(double)height()/(double)(autoCell->getHeight()*autoCell->getCellHeight());

        qDebug() << width() << "//"<< height() << "//" << autoCell->getCellWidth() <<"//" <<autoCell->getWidth() << zoom;
        painter.scale(zoom,zoom);
        drawOneD(painter);
    }
}


void RenderArea::next()
{
    if(autoCell!=nullptr){
        for(int i =0;i<1;i++)
        autoCell->nextState();
        update();
    }
}



void RenderArea::play()
{
    if(autoCell!=nullptr){
        timer->start(10);
        autoCell->nextState();
        update();
        if(autoCell->getWidth()>1920)
        {
            timer->stop();
            emit pause();
        }
    }
}

void RenderArea::playIsChecked(bool checked)
{
    if(checked)
        play();
    else
        timer->stop();
}


void RenderArea::mousePressEvent(QMouseEvent* ev)
{
    if(autoCell!=nullptr)
    {
        if (ev->button() == Qt::LeftButton) {
            autoCell->changeCellState(QPoint(ev->pos().x()/zoom,ev->pos().y()/zoom));
            update();

        }
    }
}

OneD *RenderArea::getAutoCell() const
{
    return autoCell;
}

void RenderArea::setAutoCell(OneD *value)
{
    autoCell = value;
}
