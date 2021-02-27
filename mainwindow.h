#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include<QTextCodec>
#include <QLineEdit>
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
    QLineEdit *countEdit;
    QLineEdit *valueEdit;
    void updateTree();
private slots:
    void RandomTreeButtonClick(bool checked);
    void BinTreeButtonClick(bool checked);
	void RadioButtonOnClick();
    void ButtonAddOnClick();
    void ButtonDelOnClick();
    void ButtonFndOnClick();
    void ButtonClrOnClick();
    void ButtonCreateOnClick();
};
#endif // MAINWINDOW_H
