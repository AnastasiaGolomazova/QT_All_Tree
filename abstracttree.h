#ifndef ABSTRACTTREE_H
#define ABSTRACTTREE_H

class Node
{
public:
    int key;
    //информационное поле узла типа Int
    Node *Left;
    //указатель на левое поддерево
    Node *Right;
    //указатель на правое поддерево
    Node() {
        key = 0;
        Left = Right = nullptr;
    }
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
    virtual void DelTree(Node *&) = 0;               // рекурсивная функция удаления дерева
    virtual void AddNode(Node *, Node *) = 0;// рекурсивная функция добавления узла
    virtual bool FindNode(Node *, int) = 0;  // рекурсивная функция поиска узла
    virtual int HeightNode(Node *R) = 0;             // вспомогательная рекурсивная
    // функция для вычисления высоты
    virtual int Min(Node *, int) = 0; //Метод поиска минимального значения в дереве(рекурсия)
    virtual int Max(Node *) = 0;  //Метод поиска максимального значения в дереве
public:

protected:
    Node *Root;
    virtual Node *Parents(int, Node *) = 0;         // возвращает РОДИТЕЛЯ
    virtual void CopyRandTree(Node *, Node *) = 0;  // функция копирует одно дерево в другое
public:
    virtual bool Add(int) = 0;  //Метод добавления ключа в дерево
    virtual bool Del(int) = 0;  //Метод удаления ключа из дерева
    virtual bool Find(int) = 0; //Метод поиска ключа в дереве
    virtual int MinValue() = 0; //Метод поиска минимального значения в дереве
    virtual int MaxValue() = 0; //Метод поиска максимального значения в дереве
    Node *getRoot() {
        return Root;
    }
    //AbstractTree();
    //virtual ~AbstractTree() = 0;
};

#endif // ABSTRACTTREE_H
