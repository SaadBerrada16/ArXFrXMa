#include <iostream>
#include "menu.hpp"
#include "Reserva.hpp"

using namespace std;

int main() {

    Reserva* reserva = new Reserva;
    int opcion = 0;

    reserva->cargar_animales();

    mostrar_menu();
    opcion = pedir_opcion();
    validar_opcion_elegida(opcion);

    while(opcion != SALIR){
        procesar_opcion(reserva, opcion);

        mostrar_menu();
        opcion = pedir_opcion();
        validar_opcion_elegida(opcion);
    }

    reserva->guardar_animales();

    delete reserva;

    return 0;
}
