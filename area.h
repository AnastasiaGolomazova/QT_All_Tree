#ifndef AREA_H
#define AREA_H
#include <QWidget>
#include <QPainter>
#include "figura.h"
#include "abstracttree.h"

//Область для рисования дерева, представляем виджетом
class Area : public QWidget
{
	//int myTimer; // идентификатор таймера
	//float alpha; // угол поворота
    AbstractTree *baseTree;
public:
	//Это просто для примера
	QPen myPen;

    Area(QWidget *parent = nullptr, AbstractTree *root = nullptr);
	~Area();
    void setTree(AbstractTree *);
	void DrawTree(QPen &tmpPen);

protected:
	void drawTreeRecursively(QPainter *, Node *, int, int, int);

	// обработчики событий
	void paintEvent(QPaintEvent *event);
	void timerEvent(QTimerEvent *event);
	void showEvent(QShowEvent *event);
	void hideEvent(QHideEvent *event);
};

#endif // AREA_H
