#include "abstracttree.h"
#include <cstdlib>

class BinTree : public AbstractTree
{
    virtual bool DelNode(Node *&, int item);            // рекурсивная функция удаления узла
    virtual void DelTree(Node *&);               // рекурсивная функция удаления дерева
    virtual void AddNode(Node *, Node *);// рекурсивная функция добавления узла
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


    ~BinTree()
    {
    }
};
