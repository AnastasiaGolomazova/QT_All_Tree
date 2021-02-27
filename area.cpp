#include "area.h"
#include <QTimerEvent>

Area::Area(QWidget *parent, AbstractTree *root): QWidget(parent)
{
	//Это для примера. Иницализируем цвет карандаша по умолчанию

    myPen.setWidth(4);
    myPen.setColor(Qt::white);


	//Настравиваем нужные нам компоненты
	// а именно

	baseTree = root;

	//myline = new MyLine(80, 100, 50);
	//myrect = new MyRect(220, 100, 50);
	//alpha = 0;

	//Цвета - https://colorscheme.ru/html-colors.html
	//	this->setStyleSheet("background-color:#FAF0E6;");
	//this->setStyleSheet("background-color:black;");
	//this->setStyleSheet("background-color:#C0C0C0;");
	//this->setStyleSheet("background-color:#2F4F4F;");

	QString myStyle = "background-color:";//+"#F5F5DC;";
	myStyle = myStyle + "black;";
	this->setStyleSheet(myStyle);

}
void Area::showEvent(QShowEvent *)
{
	//myTimer = startTimer(50); // создать таймер


}
void Area::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setPen(myPen);
	QFont font = painter.font();
	font.setPixelSize(20);
	font.setBold(true);
	//font.setFamily("Helvetica");
	font.setFamily("Consolas");
	painter.setFont(font);
	//painter.setFont(QFont("Arial", 20));

	painter.drawText(rect(), Qt::AlignCenter, "Qt");
	drawTreeRecursively(&painter, baseTree->getRoot(), 0, painter.device()->width(), 55);

}
void Area::timerEvent(QTimerEvent *event)
{


	//	if (event->timerId() == myTimer) { // если наш таймер
	//		alpha = alpha + 0.2;
	//		update(); // обновить внешний вид
	//	} else {
	//		QWidget::timerEvent(event);// иначе передать для стандартной
	//	}

	//// обработки
}
void Area::hideEvent(QHideEvent *)
{
	//killTimer(myTimer); // уничтожить таймер
}
Area::~Area()
{

	//Дерево здесь не удалаяем так, как
	//класс Area является классом контейнером,
	//который только содержит адрес дерева, которе будем рисовать.
}
void Area::DrawTree(QPen &tmpPen)
{
	QPainter painter(this);
	myPen = tmpPen;
	painter.setPen(myPen);
	QFont font = painter.font();
	font.setPixelSize(20);
	font.setBold(true);
	//font.setFamily("Helvetica");
	font.setFamily("Consolas");
	painter.setFont(font);
	//painter.setFont(QFont("Arial", 20));

    //painter.drawText(rect(), Qt::AlignCenter, "Qt");
	drawTreeRecursively(&painter, baseTree->getRoot(), 0, painter.device()->width(), 55);


}
void Area:: drawTreeRecursively(QPainter *canva, Node *root, int l, int r, int h)
{
	if (root) {
		int centr_x = (l + r) / 2;
		int rr = 25;
		int x0 = centr_x - rr;
		canva->drawEllipse(x0, h, rr * 2, rr * 2);

        QString str = QString::number(root->key);
		canva->drawText(x0 + rr / 2, h + rr, str);

		if (root->Left) {
			canva->drawLine(centr_x, 2 * rr + h, (l + r) / 2 - (r - l) / 4, h + 60);
			drawTreeRecursively(canva, root->Left, l, centr_x, h + 60);
		}

		if (root ->Right) {
			canva->drawLine((r + centr_x) / 2 - (r - centr_x) / 2, 2 * rr + h, (centr_x + r) / 2, h  + 60);
			drawTreeRecursively(canva, root->Right, centr_x, r, h + 60);
		}

	}
}
