#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include "diccionarioArbolB.hpp"
#include "Animal.hpp"
#include "AnimalLimpio.hpp"
#include "AnimalSucio.hpp"
#include "Caballo.hpp"
#include "Conejo.hpp"
#include "Dormilon.hpp"
#include "Erizo.hpp"
#include "Gato.hpp"
#include "Jugueton.hpp"
#include "Lagartija.hpp"
#include "Perro.hpp"
#include "Personalidad.hpp"
#include "Roedor.hpp"
#include "Sociable.hpp"
#include "Travieso.hpp"
#include "Mapa.hpp"
#include "Auto.hpp"
#include "treeSort.hpp"

using namespace std;

const string PATH_ANIMALES = "animales.csv";

class Reserva {
    //atributos
    private:
        Diccionario<Animal*>* animales;
        Auto* coche;
        int animales_escapados;

    public:
        //Constructor
        //crea una reserva con una puntero a un diccionario
        Reserva();

        void iniciar();

        bool hay_siguiente();

        Animal* siguiente();
    
        //pre: existe la reserva
        //post: devuelve la cantidad de elementos que contiene el diccionario
        int obtener_cantidad_de_animales();

        //pre: existe la reserva y si contiene elementos son del tipo Animal*
        //post: imprime en el terminal todos los atributos del animal
        void listar_animales();

        //pre: existe la reserva y recibe un nombre para buscar
        //post: si existe el animal devuelve un puntero a este animal, sino devuelve 0
        Animal* buscar_animal(string nombre);

        //pre: existe la reserva y recibe una Animal*
        //post: añade un Animal* al diccionario
        void agregar_animal(Animal* animal);

        //pre: existe la reserva
        //post: baña todos los animales en el diccionario
        void banar_animales();

        //pre: existe la reserva
        //post: alimenta todos los animales en el diccionario
        void alimentar_animales();

        //pre: existe la reserva y recibe el espacio que posee el usuario para saber que tipo de animal puede adoptar
        //post: se remueve del diccionario el Animal* que corresponde al animal adoptado
        void adoptar_animal(int espacio);

        //pre: existe la reserva y recibe el nivel de combustible a cargar
        //pos: añade combustible al auto
        void cargar_combustible(int combustible);

        //pre: existe la reserva y un archivo en la misma carpeta que se llama animales.csv
        //post: guarda en el archivo animales.csv los animales contenidos en el diccionario
        void guardar_animales();
        
        //pre: existe la reserva
        //post: añade al diccionario punteros a los animales guardados en el archivo animales.csv
        void cargar_animales();

        //pre: existe la reserva
        //post: se le baja la higiene y se le aumenta el hambre a los animales del diccionario
        void bajar_higiene_y_crecer_hambre();

        // pre: existe la reserva y recibe el mapa a ser generado
        // post: añade animales en el mapa en distintas posiciones 
        void generar_mapa(Mapa* mapa);

        // pre: existe la reserva y el mapa fue generado
        // pos: si quedan animales en el mapa son rescatados y añadidos a la reserva
        void rescatar_animales(Mapa* mapa);

        // pre: existe la reserva, mapa, cantidad de animales, vector de costo de combustible y la cantidad de animales rescatables es mayor a 0
        // pos: se añade un animal rescatado a la reserva
        void rescatar_un_animal(Mapa* mapa, int n_animales, int* costo);
        
        void se_escapan();

        bool partida_terminada();

        // pre: existe la reserva y el auto
        // pos: imprime la cantidad de combustible actual
        void imprimir_combustible();

        // pre: existe la reserva y el auto
        // pos: aumenta la cantidad de combustible del auto cada vez que se usa una accion del menu
        void aumentar_combustible();

        ~Reserva();
};

//pre: -
//post devuelve un Animal* aleatorio
Animal* generar_animal();

//pre: -
//post: devuelve la posicion del mapa donde el usuario desea desplazarse
int pedir_posicion_mapa();

//pre: recibe un vector posiciones
//post: devuelve un vector con las posiciones donde se van a encontrar los animales en el mapa
int* generar_posiciones();

//pre: recibe un string
//post: si ese string corresponde a una personalidad devuelve un puntero a ese tipo de personalidad, sino devuelve 0
Personalidad* convertir_personalidad(string p);
//pre: recibe el nombre, edad, tamaño, especie y personalidad del animal a crear
//post devuelve un Animal* que corresponde al animal deseado determinado por la especie
Animal* crear_animal(string nombre, string edad, string tamano, string especie, string personalidad);

//pre: existe un mapa, auto, un vector de costo de combustible por animal y la cantidad de animales rescatables
//pos: imprime el recorrido minimo a caada animal, guarda su costo en el vector costo y aumenta la cantidad de animales rescatables si hay suficiente combustible
void buscar_camino_minimo_animales(Mapa* mapa, Auto* coche, int* costo, int n_animales , int &numero_animales_rescatables);

//pre: un rango sea definido
//post: devuelve un entero aleatorio entre 0 y rango
int random_num(int rango);

#endif
