#include "bintree.h"


void BinTree::DelTree(Node *&){
    return;
}
bool BinTree::DelNode(Node *&, int item){
    return false;
}
void BinTree::AddNode(Node *node, Node *item){
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
bool BinTree::FindNode(Node *, int){
    return true;
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
