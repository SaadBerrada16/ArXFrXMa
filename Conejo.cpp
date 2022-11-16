#include "Conejo.hpp"

Conejo::Conejo(string n, int e, string t, Personalidad* p) {
    nombre = n;
    edad = e;
    tamano = t;
    personalidad = p;
    especie = "Conejo";
    hambre = 0;
    higiene = 100;
}

void Conejo::comer() {
    hambre = 0;
    cout << "Soy " << nombre << " el conejo, comi lechuga" << endl;
}