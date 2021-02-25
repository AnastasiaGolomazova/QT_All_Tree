#ifndef RANDTREE_H
#define RANDTREE_H

#include "abstracttree.h"

class RandTree : public AbstractTree
{

private:
    virtual void DelTree(Node *&); // рекурсивная функция удаления дерева
    virtual bool DelNode(Node *&, int item); // рекурсивная функция удаления узла
    virtual void AddNode(Node *&, Node *); // рекурсивная функция добавления узла
    virtual bool FindNode(Node *, int); // рекурсивная функция поиска узла
    virtual int HeightNode(Node *R); // рекурсивная функция для вычисления высоты
protected:
    virtual Node *Parents(int, Node *);         // возвращает РОДИТЕЛЯ

public:
	RandTree() {
		Root = nullptr;
	}
	RandTree(RandTree &);                   // конструктор копирования
    virtual int HeightNode();               // функция вычисления высоты
    RandTree operator= (RandTree &);       // оператор присвоения, полностью наследуется
    ~RandTree() {
		DelTree(Root);
	}
    virtual void CopyTree(Node *ctr_v, Node *ctr_c);
	virtual bool Add(int);  //Метод добавления ключа в дерево
	virtual bool Del(int);  //Метод удаления ключа из дерева
	virtual bool Find(int); //Метод поиска ключа в дереве

};

#endif // RANDTREE_H
