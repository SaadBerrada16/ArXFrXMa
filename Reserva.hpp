#ifndef RESERVA_H
#define RESERVA_H


#include <iostream>
#include "Animal.hpp"
#include "lista.hpp"
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
#include "lista.hpp"
#include "nodo.hpp"
#include "Perro.hpp"
#include "Personalidad.hpp"
#include "Roedor.hpp"
#include "Sociable.hpp"
#include "Travieso.hpp"

using namespace std;

const string PATH_ANIMALES = "animales.csv";

class Reserva {
    //atributos
    private:
        Lista* animales;

    public:
        //Constructor
        //crea una reserva con una puntero a una lista
        Reserva();

        //pre: existe la reserva
        //post: devuelve la cantidad de elementos que contiene la lista
        int obtener_cantidad_de_animales();

        //pre: existe la reserva y si contiene elementos son del tipo Animal*
        //post: imprime en el terminal todos los atributos del animal
        void listar_animales();

        //pre: existe la reserva y recibe un nombre para buscar
        //post: si existe el animal devuelve un puntero a este animal, sino devuelve 0
        Animal* buscar_animal(string nombre);
        //pre: existe la reserva y recibe una Animal*
        //post: añade un Animal* a la lista
        void agregar_animal(Animal* animal);

        //pre: existe la reserva y recibe el numero de la list a buscar
        //post: devuelve el Animal* en la posicion elegida si es que existe, sino devuelve 0
        Animal* elegir_animal(int posicion_actual);
        //pre: existe la reserva
        //post: baña todos los animales en la lista
        void banar_animales();
        //pre: existe la reserva
        //post: alimenta todos los animales en la lista
        void alimentar_animales();
        //pre: existe la reserva y recibe el espacio que posee el usuario para saber que tipo de animal puede adoptar
        //post: se remueve de la lista el Animal* que corresponde al animal adoptado
        void adoptar_animal(int espacio);

        //pre: existe la reserva y un archivo en la misma carpeta que se llama animales.csv
        //post: guarda en el archivo animales.csv los animales contenidos en la lista
        void guardar_animales();
        //pre: existe la reserva
        //post: añade a la lista punteros a los animales guardados en el archivo animales.csv
        void cargar_animales();

        //pre: existe la reserva
        //post: se le baja la higiene y se le aumenta el hambre a los animales de la lista
        void bajar_higiene_y_crecer_hambre();

        ~Reserva();
};

//pre: recibe un string
//post: si ese string corresponde a una personalidad devuelve un puntero a ese tipo de personalidad, sino devuelve 0
Personalidad* convertir_personalidad(string p);
//pre: recibe el nombre, edad, tamaño, especie y personalidad del animal a crear
//post devuelve un Animal* que corresponde al animal deseado determinado por la especie
Animal* crear_animal(string nombre, string edad, string tamano, string especie, string personalidad);

#endif
