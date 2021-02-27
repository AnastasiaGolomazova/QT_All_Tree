#include "bintree.h"

BinTree::BinTree() {
    this->Root = nullptr;
}

bool BinTree::Del(int data) {
    if(FindNode(this->Root, data)){
        DelNode(this->Root, data);
        return true;
    }

    return false;

}

void BinTree::CopyTree(Node* ctr_v, Node* ctr_c) {
    if (ctr_c->Left) {
        Node *q = new Node(ctr_c->Left->key);
        ctr_v->Left = q;
        CopyTree(ctr_v->Left, ctr_c->Left);
    }

    if (ctr_c->Right) {
        Node *q = new Node(ctr_c->Right->key);
        ctr_v->Right = q;
        CopyTree(ctr_v->Right, ctr_c->Right);
    }
}

Node* BinTree::DelNode(Node *& root, int data){
    
	if (root == NULL) {
		return NULL;
	}
	if (data < root->key) {  // data is in the left sub tree.
		root->Left = DelNode(root->Left, data);
	}
	else if (data > root->key) { // data is in the right sub tree.
		root->Right = DelNode(root->Right, data);
	}
	else {
		// case 1: no children
		if (root->Left == NULL && root->Right == NULL) {
			delete(root); // wipe out the memory, in C, use free function
			root = NULL;
		}
		// case 2: one child (right)
		else if (root->Left == NULL) {
			struct Node* temp = root; // save current node as a backup
			root = root->Right;
			delete temp;
		}
		// case 3: one child (left)
		else if (root->Right == NULL) {
			struct Node* temp = root; // save current node as a backup
			root = root->Left;
			delete temp;
		}
		// case 4: two children
		else {
			struct Node* temp = FindMin(root->Right); // find minimal value of right sub tree
			root->key = temp->key; // duplicate the node
			root->Right = DelNode(root->Right, temp->key); // delete the duplicate node
		}
	}
	return root; // parent node can update reference

}

Node* BinTree::FindMin(Node* root) {
	if (root->Left) {
		return FindMin(root->Left);
	}
	else {
		return root;
	}
}

void BinTree::AddNode(Node *&node, Node *item){
    if(node == nullptr){
        node = item;
        return;
    }
    if (item->key > node->key)
    {
        AddNode(node->Right, item);
    }
    else
    {
        AddNode(node->Left, item);
    }
}

bool BinTree::FindNode(Node * node, int item){
	if (node == nullptr) {
		return false;
	}
	if(node->key == item){
        return true;
    }else{
        return FindNode(node->Left, item) || FindNode(node->Right, item);
    }
    return false;

}
int BinTree::HeightNode(Node *R){
    return 0;
}

Node* BinTree::Parents(int, Node *){
    return nullptr;
}

bool BinTree::Add(int item){
    if(FindNode(Root, item)){
        return false;
    }

    if(Root){
        AddNode(Root, new Node(item));
    }
    else{
        Root = new Node(item);
    }
    return true;
}
