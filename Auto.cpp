#include "Auto.hpp"

Auto::Auto() {
    combustible = 100;
    posicion = 1;
}

void Auto::cargar_combustible(int litros) {
    combustible = combustible + litros;
    if (combustible>=100){
        combustible = 100;
    }
}

void Auto::cargar_combustible() {
  combustible = combustible + 5;
  if (combustible>=100){
    combustible = 100;
  }
}

void Auto::bajar_combustible(int litros) {
    combustible = combustible - litros;
    if (combustible<=0){
        combustible = 0;
    }
}

bool Auto::combustible_suficiente(int costo){
    bool combustible_suficiente = false;
    if(combustible>=costo)
        combustible_suficiente = true;

    return combustible_suficiente;
}
