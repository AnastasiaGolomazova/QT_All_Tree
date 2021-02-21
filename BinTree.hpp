#include "abstracttree.h"


class BinTree : public AbstractTree
{

    bool InsertRec(const int &item, Node *&node)
    {
        if (node == nullptr)
        {
            node = new Node(item);
            return true;
        }
        else
        {
            if (item == node->key)
            {
                return false;
            }

            if (item > node->key)
            {
                return InsertRec(item, node->Right);
            }
            else
            {
                return InsertRec(item, node->Left);
            }
        }
    }

    virtual void DelTree(Node *&){}              // рекурсивная функция удаления дерева
    virtual void AddNode(Node *, Node *){}// рекурсивная функция добавления узла
    virtual bool FindNode(Node *, int){return true;}  // рекурсивная функция поиска узла
    virtual int HeightNode(Node *R){return 0;}             // вспомогательная рекурсивная
    // функция для вычисления высоты
    virtual int Min(Node *, int){return 0;} //Метод поиска минимального значения в дереве(рекурсия)
    virtual int Max(Node *){return 0;}  //Метод поиска максимального значения в дереве

protected:
    virtual Node *Parents(int, Node *){return nullptr;}         // возвращает РОДИТЕЛЯ
    virtual void CopyRandTree(Node *, Node *){}  // функция копирует одно дерево в другое

public:
    BinTree()
    {
        this->Root = nullptr;
        //this->size = 0;
    }
    // BinTree(Node *nd)
    // {
    // }
    virtual bool Find(int item)
    {
        return 0;
    }
    virtual bool Add(int item)
    {
        return InsertRec(item, this->Root);
    }

    virtual int HeightNode(){return 0;}
    virtual bool Del(int){return true;}  //Метод удаления ключа из дерева
    virtual int MinValue(){return 0;} //Метод поиска минимального значения в дереве
    virtual int MaxValue(){return 0;} //Метод поиска максимального значения в дереве

    ~BinTree()
    {
    }
};
