#include "perro.hpp"

Perro::Perro(string n, int e, string t, Personalidad* p) {
    nombre = n;
    edad = e;
    tamano = t;
    personalidad = p;
    especie = "Perro";
    hambre = 0;
    higiene = 100;
}

void Perro::comer() {
    hambre = 0;
    cout << "Soy " << nombre << " el perro, comi huesos" << endl;
}