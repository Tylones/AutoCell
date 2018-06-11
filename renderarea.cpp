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
		QVector < Etat > etats=autoCell->getEtats();
		for(int i = 0; i < etats.size(); i++){
			for(int j =0; j < etats[i].getMatrice().size(); j++){
				for(int k = 0; k < etats[i].getMatrice()[j].size(); k++){
					switch(etats[i].getMatrice()[j][k]){
					case 0:
						painter.setBrush(Qt::black);
						painter.setPen(Qt::black);
						break;
					case 2:
						painter.setBrush(Qt::black);
						painter.setPen(Qt::white);
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
					painter.setBrush(Qt::white);
					painter.setPen(Qt::black);
					}

					painter.drawRect((k)*10,(j)*10,10,10);
				}

			}
		}
		/*QVector <Etat> ::iterator row;
		QVector <int>::iterator col;
		for (row = etats.begin(); row != etats.end(); row++) {
			QVector <int > line = row->getMatrice()[0];

			for (col = line.begin(); col != line.end(); col++) {
				//painter.drawRect((row-matrice.begin())*10,(col-row->begin())*10,10,10);
				if(*col==1)
					painter.fillRect((row-etats.begin())*10,(col-line.begin())*10,10,10,Qt::SolidPattern);
			}
		}*/

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
		if(autoCell->getCurrentState() * autoCell->getCellHeight()*zoom > height())
			zoom=(double)autoCell->getCurrentState()/(double)(autoCell->getCurrentState()*autoCell->getCellHeight());

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
			qDebug() << ev->pos().x()/zoom << "//" << ev->pos().y()/zoom << "//" << zoom;
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
