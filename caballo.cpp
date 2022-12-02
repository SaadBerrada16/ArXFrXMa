#include "Caballo.hpp"

Caballo::Caballo(string n, int e, string t, Personalidad* p) {
    nombre = n;
    edad = e;
    tamano = t;
    personalidad = p;
    especie = "Caballo";
    hambre = 0;
    higiene = 100;
}

void Caballo::comer() {
    hambre = 0;
    cout << "Soy " << nombre << " el caballo, comi manzanas" << endl;
}
