#include <iostream>
#include  "nodo.h"
// Node class constructor
Node::Node(int value) {
	this->data = value;
	this->next = nullptr;
	this->prev = nullptr;
}
void Node::nodo(Node* next2)
{
	next=next2;
}
void Node::prvnodo(Node* prv) {
	prev = prv;
}