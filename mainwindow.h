#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include<QTextCodec>
#include "area.h"
#include "randtree.h"

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
private slots:
	void RadioButtonClick(bool checked);
	void RadioButtonOnClick();
	void ButtonAddOnClick(bool checked);
private:
	RandTree *baseTree_;
};
#endif // MAINWINDOW_H
