#include "erizo.hpp"

Erizo::Erizo(string n, int e, string t, Personalidad* p) {
    nombre = n;
    edad = e;
    tamano = t;
    personalidad = p;
    especie = "Erizo";
    hambre = 0;
    higiene = 100;
}

void Erizo::comer() {
    hambre = 0;
    cout << "Soy " << nombre << " el erizo, comi insectos" << endl;
}