#include "AnimalSucio.hpp"

void AnimalSucio::ensuciar() {
    int perso = this->personalidad->get_sociable_travieso();
    if (higiene - 10 + perso < 0)
        higiene = 0;
    else
        higiene = higiene - 10 + perso;
}

void AnimalSucio::duchar() {
    higiene = 100;
    cout << "Soy " << nombre << " el " << especie << ", me duché" << endl;
}
