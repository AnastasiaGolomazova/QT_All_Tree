#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include<QTextCodec>
#include "area.h"
#include "randtree.h"
#include "bintree.h"
#include "abstracttree.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

protected:
	QTextCodec *codec;
	Area *area;  // область отображения рисунка
	QPushButton *btn;
    AbstractTree* tree;

private slots:
	void RadioButtonClick(bool checked);
	void RadioButtonOnClick();
    void ButtonAddOnClick();
};
#endif // MAINWINDOW_H
