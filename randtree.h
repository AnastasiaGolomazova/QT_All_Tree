#ifndef RANDTREE_H
#define RANDTREE_H

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
class RandTree
{
	friend class SearchTree;

private:
	void DelTree(Node *&);               // рекурсивная функция удаления дерева
	virtual void AddNode(Node *, Node *);// рекурсивная функция добавления узла
	virtual bool FindNode(Node *, int);  // рекурсивная функция поиска узла
	int HeightNode(Node *R);             // вспомогательная рекурсивная
	// функция для вычисления высоты
	int Min(Node *,
			int); //Метод поиска минимального значения в дереве(рекурсия)
	int Max(Node *);  //Метод поиска максимального значения в дереве



protected:
	Node *Root;
	Node *Parents(int, Node *);         // возвращает РОДИТЕЛЯ
	void CopyRandTree(Node *, Node *);  // функция копирует одно дерево в другое
public:
	RandTree() {
		Root = nullptr;
	}
	RandTree(RandTree &);                   // конструктор копирования
	int HeightNode();                       // функция вычисления высоты
	RandTree operator = (RandTree
						 &);       // оператор присвоения, полностью наследуется
	virtual ~RandTree() {
		DelTree(Root);
	}
	virtual bool Add(int);  //Метод добавления ключа в дерево
	virtual bool Del(int);  //Метод удаления ключа из дерева
	virtual bool Find(int); //Метод поиска ключа в дереве
	int MinValue(); //Метод поиска минимального значения в дереве
	int MaxValue(); //Метод поиска максимального значения в дереве
	Node *getRoot() {
		return Root;
	}
};

#endif // RANDTREE_H
