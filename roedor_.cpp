#include "Roedor.hpp"

Roedor::Roedor(string n, int e, string t, Personalidad* p) {
    nombre = n;
    edad = e;
    tamano = t;
    personalidad = p;
    especie = "Roedor";
    hambre = 0;
    higiene = 100;
}

void Roedor::comer() {
    hambre = 0;
    cout << "Soy " << nombre << " el roedor, comi queso" << endl;
}