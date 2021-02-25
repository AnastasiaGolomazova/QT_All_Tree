#ifndef ABSTRACTTREE_H
#define ABSTRACTTREE_H

#include <cstdlib>

class Node
{
public:
    int key;
    //информационное поле узла типа Int
    Node *Left;
    //указатель на левое поддерево
    Node *Right;
    //указатель на правое поддерево
    Node() : Node(0){}
    Node(Node &T) {
        key = T.key;
        Left = T.Left;
        Right = T.Right;
    }
    Node(int k) {
        key = k;
        Left = nullptr;
        Right = nullptr;
    }
};


class AbstractTree
{
    virtual Node* DelNode(Node *&, int item) = 0;               // рекурсивная функция удаления узла
    virtual void DelTree(Node *&) = 0;               // рекурсивная функция удаления дерева
    virtual void AddNode(Node *&, Node *) = 0;// рекурсивная функция добавления узла
    virtual bool FindNode(Node *, int) = 0;  // рекурсивная функция поиска узла
    virtual int HeightNode(Node *R) = 0;   // функция для вычисления высоты

protected:
    virtual void Min(Node *R, int& item)
    {
        if(R == nullptr){
            return;
        }
        if(R->key < item){
            item = R->key;
        }

        Min(R->Left, item);
        Min(R->Right, item);
    }
    virtual void Max(Node *R, int& item)
    {
        if(R == nullptr){
            return;
        }
        if(R->key < item){
            item = R->key;
        }

        Max(R->Left, item);
        Max(R->Right, item);
    }
    Node *Root;
    virtual Node *Parents(int, Node *) = 0;         // возвращает РОДИТЕЛЯ

public:
    virtual bool Add(int) = 0;  //Метод добавления ключа в дерево
    virtual bool Del(int) = 0;  //Метод удаления ключа из дерева
    virtual bool Find(int) = 0; //Метод поиска ключа в дереве

    virtual int MinValue()
    {
        int item = INT_MAX;
        Min(this->Root, item);
        return item;
    }
    virtual int MaxValue()
    {
        int item = INT_MIN;
        Max(this->Root, item);
        return item;
    }


    virtual int HeightNode() = 0;   // функция вычисления высоты
    virtual void CopyTree(Node* ctr_v, Node* ctr_c) = 0;
    Node *getRoot() {
        return Root;
    }
};

#endif // ABSTRACTTREE_H
