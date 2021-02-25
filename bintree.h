#ifndef BINTREE_H
#define BINTREE_H

#include "abstracttree.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class BinTree : public AbstractTree
{
	virtual Node* FindMin(Node*);
    Node* DelNode(Node *&, int item);            // рекурсивная функция удаления узла
    virtual void DelTree(Node *&);               // рекурсивная функция удаления дерева
    virtual void AddNode(Node *&, Node *);// рекурсивная функция добавления узла
    virtual bool FindNode(Node *, int);  // рекурсивная функция поиска узла
    virtual int HeightNode(Node *R); // функция для вычисления высоты
protected:
    virtual Node *Parents(int, Node *);   // возвращает РОДИТЕЛЯ

public:
    BinTree();

    virtual bool Find(int item)
    {
        return FindNode(this->Root, item);
    }
    virtual bool Add(int item);

    virtual int HeightNode(){
        return HeightNode(this->Root);
    }
    virtual bool DelNode(int item){ //Метод удаления ключа из дерева
        return DelNode(this->Root, item);
    }
	virtual bool Del(int);
	virtual void CopyTree(Node* ctr_v, Node* ctr_c);

    ~BinTree()
    {
    }

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


#endif
