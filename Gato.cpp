#include "Gato.hpp"

Gato::Gato(string n, int e, string t, Personalidad* p) {
    nombre = n;
    edad = e;
    tamano = t;
    personalidad = p;
    especie = "Gato";
    hambre = 0;
    higiene = 100;
}

void Gato::comer() {
    hambre = 0;
    cout << "Soy " << nombre << " el gato, comi atun" << endl;
}