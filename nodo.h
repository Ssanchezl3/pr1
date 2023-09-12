#include <iostream>
#include <string>
class Node {
public:

    int data;
    std::string scientifico;
    Node* next;
    Node* prev;
    Node(int value);
    void nodo(Node* stay);
    void prvnodo(Node* say);

};