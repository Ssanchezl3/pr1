#include "Eventos.h"
#include <iostream>
#include<numeric>
#include<algorithm>
using namespace std;
// Constructor and other member implementations...

// Method implementations
Node* Eventos::addEvent(int data) {
    Node* n = new Node(data);
    return n;
}

void Eventos::modifyEvent(int time) {

}

void Eventos::initializeScenario() {
    cout << "start";
    // create the list
    this->EventA = nullptr;
    this->EventB = nullptr;
    this->EventC = nullptr;
    int randomNumber;
    this->total = 2;
    this->contador = -1;
    this->Pasados=false;
    Node* n = nullptr;
    Node* j= nullptr;
    Node* head = nullptr;
    randomNumber = (rand() % (100))+1;
    n = addEvent(randomNumber);
    head = n;

    randomNumber = (rand() % 2)+1;
    if (randomNumber == 1) {
        n->scientifico = "E";
    }
    else {
        n->scientifico = "R";
    }
    if(this->Pasados){
        this->contador = this->contador + 1;
    }
    travelP(n);
    randomNumber = (rand() % (100)) + 1;
    j = addEvent(randomNumber);
    randomNumber = (rand() % 2) + 1;
    if (randomNumber == 1) {
        j->scientifico = "E";
    }
    else {
        j->scientifico = "R";
    }
    if (this->Pasados) {
        this->contador =this->contador+ 1;
    }
    travelP(j);
    n->nodo(j);

    j->prvnodo(n);

    j = n;
    for (int i = 0; i < 20; i++)
    {
        if (this->Pasados) {
            this->contador = this->contador + 1;
        }
        randomNumber = (rand() % (100)) + 1;
        n = addEvent(randomNumber);
        randomNumber = (rand() % 2) + 1;
        if (randomNumber == 1) {
            n->scientifico = "E";
        }
        else {
            n->scientifico = "R";
        }
        travelP(n);
        j->nodo(n);
        n->prvnodo(j);
        j = n;
        this->total =this->total +1;
    }
    cout << "\nTotal de eventos : "<<this->total<<"\n";
    while (head != nullptr) {
        
        cout << "[" <<head->data<<"|"<<head->scientifico<<"]->";
        head=head->next;
    }

}

// Special method to create an observation event and travel to the past
void Eventos::travelP(Node* A) {
    bool isP = isPrime(A->data);
    if (EventA == nullptr) {
        if ((isP) and (A->scientifico == "E")) {
            this->EventA = A;
            cout << "\nSe ha producido un evento tipo A: "<<this->EventA->data;
            cout << "\n|"<<this->EventA->data<<"|"<<"E|A|";
            this->Pasados = true;
        }
    }
    else if (EventB == nullptr)
    {
        if ((isP)) {
            this->EventB = A;
            cout << "\nSe ha producido un evento tipo B: " << this->EventB->data;
            cout << "\n|" << this->EventA->data << "|" << "E|A|->" << "|" << this->EventB->data << "|" << this->EventB->scientifico <<"|B|";
            
        }
    }
    else
    {
        if ((isP) and (coprime(A->data,this->EventA->data))) {
            this->EventC = A;
            cout << "\nSe ha producido un evento tipo C: " << this->EventB->data;
            cout << "\n|" << this->EventA->data << "|" << "E|A|->" << "|" << this->EventB->data << "|" << this->EventB->scientifico << "|B|->" << "|" << this->EventC->data << "|" << this->EventC->scientifico << "|C|";
            cout << "\nSe ha viajado en el tiempo y se han compartido datos ";
            this->EventA = nullptr;
            this->EventB = nullptr;
            this->EventC = nullptr;
            this->Pasados = false;
            this->contador = -1;
        }
        else if(coprime(A->data, this->EventA->data))
        {
            this->EventC = A;
            cout << "\nSe ha encontrado un evento TA en el nodo : "<<this->contador;
            cout << "\nSe ha producido un evento tipo C: " << this->EventB->data;
            cout << "\n|" << this->EventA->data << "|" << "E|A|->" << "|" << this->EventB->data << "|" << this->EventB->scientifico << "|B|->" << "|" << this->EventC->data << "|" << this->EventC->scientifico << "|C|";
            cout << "\nSe ha viajado en el tiempo y No se han compartido datos";
            this->EventA = nullptr;
            this->EventB = nullptr;
            this->EventC = nullptr;
            this->Pasados = false;
            this->contador = -1;
        }
    }
}
bool Eventos::isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;

    return true;
}
bool Eventos::coprime(int a, int b) {

    if (gcd(a, b) == 1)
        return true;
    else
        return false;
}
int Eventos::gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
