#include "Lagartija.hpp"

Lagartija::Lagartija(string n, int e, string t, Personalidad* p) {
    nombre = n;
    edad = e;
    tamano = t;
    personalidad = p;
    especie = "Lagartija";
    hambre = 0;
    higiene = 100;
}

void Lagartija::comer() {
    hambre = 0;
    cout << "Soy " << nombre << " el lagartija, comi insectos" << endl;
}