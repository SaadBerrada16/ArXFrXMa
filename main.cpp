#include <iostream>
#include "menu.hpp"
#include "Reserva.hpp"



using namespace std;

int main() {

    Reserva* reserva = new Reserva;
    Mapa* mapa = new Mapa();
    int opcion = 0;

    reserva->cargar_animales();
    reserva->generar_mapa(mapa);

    mostrar_menu();
    opcion = pedir_opcion();
    validar_opcion_elegida(opcion);

    while(opcion != SALIR){
        procesar_opcion(reserva, opcion, mapa);

        mostrar_menu();
        opcion = pedir_opcion();
        validar_opcion_elegida(opcion);
    }

    reserva->guardar_animales();

    delete mapa;
    delete reserva;

    return 0;
}
