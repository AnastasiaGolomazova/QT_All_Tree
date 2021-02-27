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


    QPushButton *createBtn = new QPushButton(tr("Create"), this);
    connect(createBtn, &QPushButton::clicked, this,  &MainWindow::ButtonCreateOnClick);



	QGroupBox *groupBoxS = new QGroupBox(this);
	QVBoxLayout *layStart = new QVBoxLayout(this);
    this->countEdit = new QLineEdit(this);
    this->countEdit->setText("0");

	//countEdit->setMaximumWidth(150);

	QLabel *countLabel = new QLabel("&Count:", this);
    countLabel->setBuddy(this->countEdit);

	layStart->addWidget(countLabel, 1, Qt::AlignLeft);
    layStart->addWidget(this->countEdit);//, 0, Qt::AlignRight);
    layStart->addWidget(createBtn);
	layStart->addStretch(10);
	groupBoxS->setLayout(layStart);



	QGroupBox *groupBoxA = new QGroupBox(tr(""));

	QGroupBox *groupBoxB = new QGroupBox(tr("Options"));

	QGroupBox *groupBoxC = new QGroupBox(tr("Processing"));
	QGroupBox *groupBoxD = new QGroupBox(tr("Visualization"));

	this->setGeometry(100, 100, 1000, 600);
	this->setStatusBar(new QStatusBar(this));
    this->statusBar()->showMessage("Status bar");
	QSplitter *splitter = new QSplitter(parent);

	QVBoxLayout *layOptions = new QVBoxLayout(this);

    QRadioButton *radio1 = new QRadioButton(tr("Random Tree"), this);
    QRadioButton *radio2 = new QRadioButton(tr("Binary tree"), this);
    //QRadioButton *radio3 = new QRadioButton(tr("Balanced Tree"), this);
    radio2->setChecked(true);

	layOptions->addWidget(radio1, 1, Qt::AlignLeft);
	layOptions->addWidget(radio2, 1, Qt::AlignLeft);
    //layOptions->addWidget(radio3, 1, Qt::AlignLeft);
	layOptions->addStretch(1);
	groupBoxB->setLayout(layOptions);

	QVBoxLayout *layProcessing = new QVBoxLayout(this);
    this->valueEdit = new QLineEdit(this);
	QLabel *valueLabel = new QLabel("Value Of Node:", this);
    this->valueEdit->setText("0");
    valueLabel->setBuddy(this->valueEdit);

	QPushButton *addBtn = new QPushButton(tr("Add"), this);
	QPushButton *delBtn = new QPushButton(tr("Remove"), this);
	QPushButton *fndBtn = new QPushButton(tr("Find"), this);
	QPushButton *clrBtn = new QPushButton(tr("Clear"), this);

	layProcessing->addWidget(valueLabel, 1, Qt::AlignLeft);
    layProcessing->addWidget(this->valueEdit);//, 0, Qt::AlignRight);
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

    tree = new BinTree();

    area = new Area(this, tree);

//	//Инициализируем карандаш
//	area->myPen.setWidth(2);
//	area->myPen.setColor(Qt::red);

    //btn = new QPushButton(codec->toUnicode("Close"), this);
	QVBoxLayout *layoutPicture = new QVBoxLayout(this);
    layoutPicture->addWidget(area);
    //layoutPicture->addWidget(btn);
    //connect(btn, SIGNAL(clicked(bool)), this, SLOT(this->close()));

    //connect(btn, &QPushButton::clicked, qApp, &QApplication::quit);
	groupBoxD->setLayout(layoutPicture);


	///---------------------------
	groupBoxA->setMinimumWidth(80);
	groupBoxA->setMaximumWidth(150);
	splitter->addWidget(groupBoxD);
	splitter->addWidget(groupBoxA);

	setCentralWidget(splitter);
    connect(radio1, &QRadioButton::toggled, this, &MainWindow::RandomTreeButtonClick);
    connect(radio2, &QRadioButton::toggled, this, &MainWindow::BinTreeButtonClick);
    connect(addBtn, &QPushButton::clicked, this,  &MainWindow::ButtonAddOnClick);
    connect(delBtn, &QPushButton::clicked, this,  &MainWindow::ButtonDelOnClick);
    connect(fndBtn, &QPushButton::clicked, this,  &MainWindow::ButtonFndOnClick);
    connect(clrBtn, &QPushButton::clicked, this,  &MainWindow::ButtonClrOnClick);


}

MainWindow::~MainWindow()
{

}

void MainWindow::RandomTreeButtonClick(bool checked)
{
	if (checked) {
        this->statusBar()->showMessage("Choosen Tree: Random tree");
        delete tree;
        tree = new RandTree();
        area->setTree(tree);
        updateTree();
	}

}

void MainWindow::BinTreeButtonClick(bool checked)
{
    if (checked) {
        this->statusBar()->showMessage("Choosen Tree: Binary tree");
        delete tree;
        tree = new BinTree();
        area->setTree(tree);
        updateTree();
    }

}
void MainWindow::RadioButtonOnClick()
{
	this->statusBar()->showMessage("Choosen Tree: JustClik");
}

void MainWindow::updateTree(){
    QPen tmpPen;
    tmpPen.setWidth(4);
    tmpPen.setColor(Qt::white);
    area->DrawTree(tmpPen);
    //Обновляем виджет что бы дерево перерисовалось.
    area->update();
}

void MainWindow::ButtonCreateOnClick()
{
    this->statusBar()->showMessage("Values added");

    int value = this->countEdit->text().toInt();

    for(int i = 0; i < value; i++){
        tree->Add(rand()%100);
    }

    updateTree();

}

void MainWindow::ButtonAddOnClick()
{


    int value = this->valueEdit->text().toInt();

    if(tree->Add(value)){
        this->statusBar()->showMessage("Value added");
    }else{
        this->statusBar()->showMessage("Value already exists");
    }

    updateTree();

}

void MainWindow::ButtonDelOnClick()
{



    int value = this->valueEdit->text().toInt();

    if(tree->Del(value)){
        this->statusBar()->showMessage("Value deleted");
    }else{
        this->statusBar()->showMessage("Value to delete NOT found");
    }

    updateTree();

}

void MainWindow::ButtonFndOnClick()
{
    int value = this->valueEdit->text().toInt();

    if(tree->Find(value)){
        this->statusBar()->showMessage(this->valueEdit->text() + " has found");
    }else{
        this->statusBar()->showMessage(this->valueEdit->text() + " NOT found");
    }

}

void MainWindow::ButtonClrOnClick()
{
    this->statusBar()->showMessage("All elements cleared");

    tree->ClearTree();

    updateTree();

}
