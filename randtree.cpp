#include "randtree.h"
//#include <stdio.h>
#include<stdlib.h>
// рекурсивная функция удаления дерева
void RandTree::DelTree(Node *&Root)
{
	if (Root == nullptr) {
		return;
	}

	if (Root->Left != nullptr) {
		DelTree(Root->Left);
	}

	if (Root->Right != nullptr) {
		DelTree(Root->Right);
	}

	delete Root;
	Root = nullptr;
}
// рекурсивная функция добавления узла
void RandTree::AddNode(Node *R, Node *N)
{
	if (rand() % 2) { //  решаем идти на лево или на право
		if (R->Right) {
			AddNode(R->Right, N);
		} else {
			R->Right = N;
		}
	}


	else {
		if (R->Left) {
			AddNode(R->Left, N);
		} else {
			R->Left = N;
		}
	}
}
// рекурсивная функция поиска узла
bool RandTree::FindNode(Node *R, int key)
{
	if (!R) {
		return false;
	}

	if (R->key == key) {
		return true;
	}

	bool a = false;

	if (R->Right)
		if (FindNode(R->Right, key)) {
			a = true;
		}

	if (R->Left)
		if (FindNode(R->Left, key)) {
			a = true;
		}

	return a;
}
// вспомогательная рекурсивная функция для вычисления высоты
int RandTree::HeightNode(Node *Root)
{
	int LevelLeft = 1;
	int LevelRight = 1;

	if (Root->Right) {
		LevelRight = HeightNode(Root->Right) + 1;
	}

	if (Root->Left) {
		LevelLeft = HeightNode(Root->Left) + 1;
	}

	if (LevelLeft > LevelRight) {
		return LevelLeft;
	} else {
		return LevelRight;
	}
}
int RandTree::Min(Node *R, int m)
{
	if (R->Left == nullptr && R->Right == nullptr) {
		return R->key;
	}

	int l, r;

	if (R->Left) {
		l = Min(R->Left, m);

		if (l < m) {
			m = l;
		}
	}

	if (R->Right) {
		r = Min(R->Right, m);
		return r < m ? r : m;
	}

	return m;
}
int RandTree::Max(Node *R)
{
	if (R == nullptr) {
		return 0;
	}

	int r, m;
	m = Max(R->Left);

	if (m < R->key) {
		m = R->key;
	}

	r = Max(R->Right);
	return r > m ? r : m;
}
// возвращает узел найденный по заданным параметрам
Node *RandTree::Parents(int key, Node *R)
{
	Node *tmp = nullptr;

	if (R->Left && R->Left->key == key) {
		return R;
	}

	if (R->Left) {
		tmp = Parents(key, R->Left);
	}

	if (tmp) {
		return tmp;
	}

	if (R->Right && R->Right->key == key) {
		return R;
	}

	if (R->Right) {
		return (Parents(key, R->Right));
	}

	return tmp;
}
// функция копирует одно дерево в другое
void RandTree::CopyRandTree(Node *ctr_v, Node *ctr_c)
{
	if (ctr_c->Left) {
		Node *q = new Node(ctr_c->Left->key);
		ctr_v->Left = q;
		CopyRandTree(ctr_v->Left, ctr_c->Left);
	}

	if (ctr_c->Right) {
		Node *q = new Node(ctr_c->Right->key);
		ctr_v->Right = q;
		CopyRandTree(ctr_v->Right, ctr_c->Right);
	}
}
// конструктор копирования
RandTree::RandTree(RandTree &Tree)
{
	if (Tree.Root) {
		Node *q = new Node(Tree.Root->key);
		Root = q;
		CopyRandTree(Root, Tree.Root);
	} else {
		Root = nullptr;
	}
}
// функция вычисления высоты
int RandTree::HeightNode()
{
	if (Root == nullptr) {
		return 0;
	} else {
		return HeightNode(Root);
	}
}
// оператор присвоения, полностью наследуется
RandTree RandTree:: operator = (RandTree &Tree)
{
	if (this != &Tree) {
		if (Tree.Root) {
			Node *q = new Node(
				Tree.Root->key); // происходит копирование головы, что бы можно было
			Root = q;       //запустить рекурсивную функцию копирования
			CopyRandTree(Root, Tree.Root);
		} else {
			Root = nullptr;
		}
	}

	return *this;
}
bool RandTree::Add(int key)
{
	if (Find(key)) {
		// ключи не повторяются
		return false;
	} else {
		if (Root != nullptr) {
			Node *q = new Node(key);
			AddNode(Root, q);
		} else {
			Node *q = new Node(key);
			Root = q;
		}
	}

	return true;
}
bool RandTree::Del(int key)
{
	Node *q = nullptr;
	Node *Branch = nullptr;
	Node  *R =
		nullptr;     // R -замещающий узел. Branch - ветка которая осталась от удалённого узла

	if (Find(key)) {        // если есть тот самый узел который мы хотим удалить
		// далее начинаеться ветвление ситуаций, т.е. мы проверяем все варианты
		if (Root->key == key) {
			q = Root;

			if (Root->Left) {
				Branch = Root->Right;
				Root = Root->Left;

			} else {
				Root = Root->Right;
			}
		} else {
			R = Parents(key, Root);

			if (R->Right) {
				if (R->Right->key == key) {
					q = R->Right;
					Branch = R->Right->Right;
					R->Right = R->Right->Left;
				}
			}

			if (R->Left) {
				if (R->Left->key == key) {
					q = R->Left;
					Branch = R->Left->Right;
					R->Left = R->Left->Left;
				}
			}
		}

		delete q;

		if (Branch) {
			AddNode(Root, Branch);
		}

		return true;
	} else {
		return false;
	}
}
bool RandTree::Find(int key)
{
	if (!Root) {
		return false;
	}

	return FindNode(Root, key);
}
int RandTree::MinValue()
{
	int m = 0;
	return Min(this->Root, m);
}
int RandTree::MaxValue()
{
	return Max(Root);
}
