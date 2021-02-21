#include "mainwindow.h"
#include<QVBoxLayout>
#include <QSplitter>
#include<QGroupBox>
#include<QRadioButton>
#include<QStatusBar>
#include<QLineEdit>
#include<QLabel>
#include<QApplication>
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{


	QPushButton *countBtn = new QPushButton(tr("Create"), this);
	QGroupBox *groupBoxS = new QGroupBox(this);
	QVBoxLayout *layStart = new QVBoxLayout(this);
	QLineEdit *countEdit = new QLineEdit(this);
	countEdit->setText("0");

	//countEdit->setMaximumWidth(150);

	QLabel *countLabel = new QLabel("&Count:", this);
	countLabel->setBuddy(countEdit);

	layStart->addWidget(countLabel, 1, Qt::AlignLeft);
	layStart->addWidget(countEdit);//, 0, Qt::AlignRight);
	layStart->addWidget(countBtn);
	layStart->addStretch(10);
	groupBoxS->setLayout(layStart);



	QGroupBox *groupBoxA = new QGroupBox(tr(""));

	QGroupBox *groupBoxB = new QGroupBox(tr("Options"));

	QGroupBox *groupBoxC = new QGroupBox(tr("Processing"));
	QGroupBox *groupBoxD = new QGroupBox(tr("Visualization"));

	this->setGeometry(100, 100, 1000, 600);
	this->setStatusBar(new QStatusBar(this));
	this->statusBar()->showMessage("Choosen Tree: ");
	QSplitter *splitter = new QSplitter(parent);

	QVBoxLayout *layOptions = new QVBoxLayout(this);

	QRadioButton *radio1 = new QRadioButton(tr("&Random Tree"), this);
	QRadioButton *radio2 = new QRadioButton(tr("Search tree"), this);
	QRadioButton *radio3 = new QRadioButton(tr("Balanced Tree"), this);
	radio1->setChecked(true);

	layOptions->addWidget(radio1, 1, Qt::AlignLeft);
	layOptions->addWidget(radio2, 1, Qt::AlignLeft);
	layOptions->addWidget(radio3, 1, Qt::AlignLeft);
	layOptions->addStretch(1);
	groupBoxB->setLayout(layOptions);

	QVBoxLayout *layProcessing = new QVBoxLayout(this);
	QLineEdit *valueEdit = new QLineEdit(this);
	QLabel *valueLabel = new QLabel("Value Of Node:", this);
	valueEdit->setText("0");
	countLabel->setBuddy(valueEdit);

	QPushButton *addBtn = new QPushButton(tr("Add"), this);
	QPushButton *delBtn = new QPushButton(tr("Remove"), this);
	QPushButton *fndBtn = new QPushButton(tr("Find"), this);
	QPushButton *clrBtn = new QPushButton(tr("Clear"), this);

	layProcessing->addWidget(valueLabel, 1, Qt::AlignLeft);
	layProcessing->addWidget(valueEdit);//, 0, Qt::AlignRight);
	layProcessing->addWidget(addBtn);
	layProcessing->addWidget(delBtn);
	layProcessing->addWidget(fndBtn);
	layProcessing->addWidget(clrBtn);
	layProcessing->addStretch(1);
	groupBoxC->setLayout(layProcessing);

	QSizePolicy qq;
	qq.setHorizontalStretch(2);
	qq.setVerticalStretch(3);
	groupBoxB->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	groupBoxC->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QVBoxLayout *layTree = new QVBoxLayout(this);


	layTree->addWidget(groupBoxS);
	layTree->addWidget(groupBoxB);
	layTree->addWidget(groupBoxC);

	groupBoxA->setLayout(layTree);

	codec = QTextCodec::codecForName("Windows-1251");
	this->setWindowTitle(codec->toUnicode("Event handling"));

    AbstractTree* tree = new BinTree();

    tree->Add(12);
    tree->Add(13);
    tree->Add(4);
    tree->Add(22);
    tree->Add(55);
    tree->Add(32);
    tree->Add(43);
    tree->Add(24);

    area = new Area(this, tree);

//	//Инициализируем карандаш
//	area->myPen.setWidth(2);
//	area->myPen.setColor(Qt::red);

	btn = new QPushButton(codec->toUnicode("Close"), this);
	QVBoxLayout *layoutPicture = new QVBoxLayout(this);
    layoutPicture->addWidget(area);
	layoutPicture->addWidget(btn);
	connect(btn, SIGNAL(clicked(bool)), this, SLOT(this->close()));

	connect(btn, &QPushButton::clicked, qApp, &QApplication::quit);
	groupBoxD->setLayout(layoutPicture);


	///---------------------------
	groupBoxA->setMinimumWidth(80);
	groupBoxA->setMaximumWidth(150);
	splitter->addWidget(groupBoxD);
	splitter->addWidget(groupBoxA);

	setCentralWidget(splitter);
	connect(radio1, &QRadioButton::toggled, this, &MainWindow::RadioButtonClick);
	connect(radio2, &QRadioButton::toggled, this, &MainWindow::RadioButtonClick);
	connect(radio3, &QRadioButton::clicked, this, &MainWindow::RadioButtonOnClick);
	//---------------------------------------------------
	connect(addBtn, &QPushButton::clicked, this,  &MainWindow::ButtonAddOnClick);

}

MainWindow::~MainWindow()
{

}

void MainWindow::RadioButtonClick(bool checked)
{
	if (checked) {
		this->statusBar()->showMessage("Choosen Tree: SomeRadioButton is checkekd");
	} else {
		this->statusBar()->showMessage("Choosen Tree: SomeRadioButton is NOT checkekd");
	}

}
void MainWindow::RadioButtonOnClick()
{
	this->statusBar()->showMessage("Choosen Tree: JustClik");
}

void MainWindow::ButtonAddOnClick(bool checked)
{

	QPen tmpPen;
	tmpPen.setWidth(2);
	tmpPen.setColor(Qt::white);
	area->DrawTree(tmpPen);
	//Обновляем виджет что бы дерево перерисовалось.
	area->update();

}
