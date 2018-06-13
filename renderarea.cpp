#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
	: QWidget(parent),zoom(1),autoCell(nullptr)
{
	// OneD(int width, int cellWidth, int cellHeight,int cellStates,int r,int nb_neighborhood)test
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
    if(autoCell!=nullptr){
        QVector < Etat > etats=autoCell->getEtats();
        QVector <QVector < int > >    mat;

        if(etats.last().getMatrice().size()==1){

			int cellHeight =(height() / (autoCell->getEtats().size()));
			int cellWidth =(width() / (autoCell->getWidth()));

            for(int j =0; j < etats.size(); j++){
                mat=etats[j].getMatrice();
                for(int k = 0; k < mat[0].size(); k++){
                    switch(mat[0][k]){
                    case 0:
                        painter.setBrush(Qt::white);
                        painter.setPen(Qt::black);
						break;
                    case 2:
                        painter.setBrush(Qt::black);
                        painter.setPen(Qt::black);
                        break;
                    case 3:
                        painter.setBrush(Qt::red);
                        painter.setPen(Qt::white);
                        break;
                    case 4:
                        painter.setBrush(Qt::green);
                        painter.setPen(Qt::white);
                        break;
                    case 5:
                        painter.setBrush(Qt::blue);
                        painter.setPen(Qt::white);
                        break;
                    case 6:
                        painter.setBrush(Qt::yellow);
                        painter.setPen(Qt::white);
                        break;
                    default:
                        painter.setBrush(Qt::black);
                        painter.setPen(Qt::black);
                    }
					if(10* autoCell->getEtats().size() > height())
						painter.drawRect((k) * cellWidth, j*cellHeight,cellWidth ,cellHeight);
					else
						painter.drawRect((k) * cellWidth, j*10, cellWidth,10);
                }

            }
        }
        else{
            mat=etats[autoCell->getCurrentState()%10].getMatrice();
            for(int j =0; j < mat.size(); j++){
                for(int k = 0; k < mat[j].size(); k++){
                    switch(mat[j][k]){
                    case 0:
                        painter.setBrush(Qt::white);
                        painter.setPen(Qt::black);
                        break;
                    case 2:
                        painter.setBrush(Qt::black);
                        painter.setPen(Qt::black);
                        break;
                    case 3:
                        painter.setBrush(Qt::red);
                        painter.setPen(Qt::white);
                        break;
                    case 4:
                        painter.setBrush(Qt::green);
                        painter.setPen(Qt::white);
                        break;
                    case 5:
                        painter.setBrush(Qt::blue);
                        painter.setPen(Qt::white);
                        break;
                    case 6:
                        painter.setBrush(Qt::yellow);
                        painter.setPen(Qt::white);
                        break;
                    default:
                        painter.setBrush(Qt::black);
                        painter.setPen(Qt::white);
                    }
                    int centre =0;
                            //= (((width()-(autoCell->getWidth()*autoCell->getCellWidth()*zoom))/2));

					int cellHeight =(height() / (autoCell->getHeight()));
					int cellWidth =(width() / (autoCell->getWidth()));
					painter.drawRect((k) * cellWidth, j * cellHeight, cellWidth, cellHeight);
                }

            }
        }
    }
}



void RenderArea::paintEvent(QPaintEvent * /* event */)
{

	QPainter painter(this);
	if(autoCell!=nullptr)
	{
        if(autoCell->getWidth()>=autoCell->getHeight())
			zoom=(double)width()/(double)(autoCell->getWidth()*autoCell->getCellWidth());
		if(autoCell->getHeight()*autoCell->getCellHeight()*zoom>height())
			zoom=(double)height()/(double)(autoCell->getHeight()*autoCell->getCellHeight());
        if(autoCell->getHeight() * autoCell->getCellHeight()*zoom > height())
            zoom=(double)height()/(double)(autoCell->getHeight()*autoCell->getCellHeight());

        qDebug() << width() << "//"<< height() << "//" << autoCell->getCellWidth() <<"//" <<autoCell->getWidth() << "//" << autoCell->getCurrentState() << "//" << autoCell->getCellHeight() << "//" << autoCell->getHeight() << zoom;
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
		timer->start(100);
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
			int cellHeight =(height() / (autoCell->getHeight()));
			int cellWidth =(width() / (autoCell->getWidth()));
			autoCell->changeCellState(QPoint(ev->pos().x()/cellWidth,ev->pos().y()/cellHeight));
			qDebug() << ev->pos().x()/cellWidth << "//" << ev->pos().y()/cellHeight << "//" << zoom;
			update();

		}
	}
}

AutoCell *RenderArea::getAutoCell() const
{
	return autoCell;
}

void RenderArea::setAutoCell(AutoCell *value)
{
	autoCell = value;
}
