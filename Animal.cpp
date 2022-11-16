#include "Animal.hpp"

void Animal::crecer_hambre() {
    int perso = this->personalidad->get_dormilon_jugueton();
    if (hambre + 10 + perso > 100)
        hambre = 100;
    else
        hambre = hambre + 10 + perso;
}

void Animal::mostrar_animal() {
    cout << endl << "Nombre: " << nombre << endl
    << "Especie: " << especie << endl
    << "Edad: " << edad << endl
    << "Tamaño: " << tamano << endl
    << "Personalidad: " << personalidad->get_nombre() << endl
    << "Hambre: " << hambre << endl
    << "Higiene: " << higiene << endl;
}

Animal::~Animal() {
  delete this->personalidad;
}
