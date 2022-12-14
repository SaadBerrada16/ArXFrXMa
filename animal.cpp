#include "animal.hpp"

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

// int* Animal::generar_posiciones() {
//   srand((unsigned)time(NULL));
//   int n = 5;
//   int* posiciones = new int[n];
//   for (int i = 0; i < n; i++) {
//       bool unico = false;
//       while(!unico){
//           int random = 2 + rand() % 63;
//           posiciones[i] = random;
//           unico = true;
//           for (int k = 0; k<i; k++){
//               if(posiciones[i]==posiciones[k]) unico = false;
//           }
//
//       }
//
//   }
//     return posiciones;
// }


Animal::~Animal() {
  delete this->personalidad;
}
