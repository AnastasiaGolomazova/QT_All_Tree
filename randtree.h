#ifndef RANDTREE_H
#define RANDTREE_H

#include "abstracttree.h"
#include <iostream>

using namespace std;
class RandTree : public AbstractTree
{

private:
    void DelNode(Node *&, int item); // рекурсивная функция удаления узла
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


	void print2DUtil(Node* root, int space)
	{
		// Base case
		if (root == NULL)
			return;

		// Increase distance between levels
		space += 10;

		// Process right child first
		print2DUtil(root->Right, space);

		// Print current node after space
		// count
		cout << endl;
		for (int i = 10; i < space; i++)
			cout << " ";
		cout << root->key << "\n";

		// Process left child
		print2DUtil(root->Left, space);
	}

	// Wrapper over print2DUtil()
	void print2D()
	{
		// Pass initial space count as 0
		print2DUtil(this->Root, 0);
	}

};

#endif // RANDTREE_H
