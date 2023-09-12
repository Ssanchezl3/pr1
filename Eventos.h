#include <iostream>
#include <string>
#include "nodo.h"
class Eventos {
public:
    int total;
    bool Pasados;
    int contador;
    // Constructor and other members...
    Node* EventA;
    Node* EventB;
    Node* EventC;
    // Method declarations
    Node* addEvent(int data);
    void modifyEvent(int time);
    bool isPrime(int);
    // Special methods for the scenario
    void initializeScenario(); // Initialize with Evento A
    void travelP(Node*); // Create an observation event and travel to the past
    // Other members and methods...
    bool coprime(int a, int b);
    int gcd(int a, int b);
};