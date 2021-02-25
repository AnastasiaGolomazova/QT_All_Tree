#include <iostream>
#include "bintree.h"

using namespace std;

int main()
{

	BinTree tree;

	tree.Add(57);
	

	tree.print2D();

	tree.Del(57);

	cout << "--------------------------" << endl;

	tree.print2D();

	return 0;
}
