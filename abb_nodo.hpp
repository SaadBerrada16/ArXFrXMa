#ifndef ABB_ABBNODO_HPP
#define ABB_ABBNODO_HPP

#include "animal.hpp"

class ABBNodo
{
//atributos
private:
    Animal* dato;
    ABBNodo* izquierda; //sucesor de izquierda 
    ABBNodo* derecha; //sucesor de derecha 
    ABBNodo* antecesor;

//métodos
public:
    // Constructor
    // Crea un nodo que contiene los datos del animal.
    ABBNodo(Animal* dato);

    // pre: -
    // pos: vuelve los datos del animal.
    Animal* conseguir_dato();
    
    // pre: -
    // pos: llena los atributos derecha y antecesor del ABBNodo.
    void setear_derecha(ABBNodo* derecha, ABBNodo* antecesor);
    
    // pre: -
    // pos: llena el atributo derecha del ABBNodo.
    void setear_derecha(ABBNodo* derecha);

    // pre: -
    // pos: llena los atributos izquierda y antecesor del ABBNodo.
    void setear_izquierda(ABBNodo* izquierda, ABBNodo* antecesor);
    
    // pre: -
    // pos: llena el atributo izquierda del ABBNodo.
    void setear_izquierda(ABBNodo* izquierda);
     
    // pre: -
    // pos: vuelve el atributo derecha del ABBNodo.
    ABBNodo* conseguir_derecha();

    // pre: -
    // pos: llena el atributo izquierda del ABBNodo.
    ABBNodo* conseguir_izquierda();
};

#endif //ABB_ABBNODO_HPP