#ifndef RANDTREE_H
#define RANDTREE_H

#include "abstracttree.h"

class RandTree : public AbstractTree
{

private:
    virtual void DelTree(Node *&);               // рекурсивная функция удаления дерева
    virtual void AddNode(Node *, Node *);// рекурсивная функция добавления узла
    virtual bool FindNode(Node *, int);  // рекурсивная функция поиска узла
    virtual int HeightNode(Node *R);             // вспомогательная рекурсивная
	// функция для вычисления высоты
    virtual int Min(Node *, int); //Метод поиска минимального значения в дереве(рекурсия)
    virtual int Max(Node *);  //Метод поиска максимального значения в дереве



protected:
    virtual Node *Parents(int, Node *);         // возвращает РОДИТЕЛЯ
    virtual void CopyRandTree(Node *, Node *);  // функция копирует одно дерево в другое
public:
	RandTree() {
		Root = nullptr;
	}
	RandTree(RandTree &);                   // конструктор копирования
    virtual int HeightNode();                       // функция вычисления высоты
	RandTree operator = (RandTree
						 &);       // оператор присвоения, полностью наследуется
    ~RandTree() {
		DelTree(Root);
	}
	virtual bool Add(int);  //Метод добавления ключа в дерево
	virtual bool Del(int);  //Метод удаления ключа из дерева
	virtual bool Find(int); //Метод поиска ключа в дереве
    virtual int MinValue(); //Метод поиска минимального значения в дереве
    virtual int MaxValue(); //Метод поиска максимального значения в дереве

};

#endif // RANDTREE_H
