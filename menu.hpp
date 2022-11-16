#ifndef MENU_HPP
#define MENU_HPP

#include "Reserva.hpp"
using namespace std;

enum OpcionMenu {
    LISTAR_ANIMALES,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    SALIR,
    CANTIDAD_DE_OPCIONES
};

enum OpcionRescatar {
    INGRESAR_NOMBRE,
    VOLVER_MENU,
    CANTIDAD_DE_OPCIONES_RESCATAR
};

enum OpcionCuidar {
    ELEGIR_INDIVIDUALMENTE,
    ALIMENTAR_TODOS,
    BANAR_TODOS,
    REGRESAR_INICIO,
    CANTIDAD_DE_OPCIONES_CUIDAR
};

enum OpcionCuidarIndividualmente {
    BANAR,
    ALIMENTAR,
    SALTEAR,
    VOLVER,
    CANTIDAD_DE_OPCIONES_CUIDAR_INDIVIDUALMENTE
};

const int POSICION_INVALIDA = -1;

// pre: -
// pos: imprime el menu general
void mostrar_menu();

// pre: -
// pos: imprime un menu si el nombre del animal ya existe
void mostrar_menu_rescatar();

// pre: -
// pos: imprime el menu de la opcion cuidar animales
void mostrar_menu_cuidar();

// pre: -
// pos: devuelve la opcion que usuario ingrese en el terminal
int pedir_opcion();

// pre: que el usuario ingresó una opcion
// pos: chequea si la opcion ingresada esta valida
void validar_opcion_elegida(int &opcion_elegida);

// pre: que una reserva existe y que el usuario ingresó a una opcion
// pos: procesar los métodos de la reserva propuesta por el menu
void procesar_opcion(Reserva* reserva, int opcion);

// pre: -
// pos: devuelve el nombre que el usuario ingrese en el terminal
string pedir_nombre();

// pre: -
// pos: devuelve el edad que usuario el ingrese en el terminal
string pedir_edad();

// pre: -
// pos: devuelve el tamano que el usuario ingrese en el terminal
string pedir_tamano();

// pre: -
// pos: devuelve la especie que el usuario ingrese en el terminal
string pedir_especie();

// pre: -
// pos: devuelve la personalidad que el usuario ingrese en el terminal
string pedir_personalidad();

// pre: -
// pos: devuelve el espacio disponible que el usuario ingrese en el terminal
int pedir_espacio_disponible();

// pre: que el usuario ingresó un edad
// pos: chequea si el edad ingresado esta valido
bool es_edad_valido(int edad);

// pre: que el usuario ingresó un tamano
// pos: chequea si el tamano ingresado esta valido
bool es_tamano_valido(string tamano);

// pre: que el usuario ingresó una opcion
// pos: chequea si la opcion ingresada esta valida
bool es_especie_valido(string especie);

// pre: que el usuario ingresó una personalidad
// pos: chequea si la personalidad ingresada esta valida
bool es_personalidad_valido(string personalidad);


#endif
