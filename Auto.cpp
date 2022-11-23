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

void Auto::bajar_combustible(int litros) {
    combustible = combustible - litros;
    if (combustible<=0){
        combustible = 0;
    }
}

void Auto::bajar_combustible() {
    combustible = combustible - 5;
    if (combustible<=0){
        combustible = 0;
    }
}
