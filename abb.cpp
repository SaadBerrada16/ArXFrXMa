#include "abb.hpp"

ABB::ABB() {
    this->raiz = NULL;
}

// INSERTAR, COMPLEJIDAD PEOR CASO: O(h) = O(log2(n))
// h: height, n: #nodos
ABBNodo* ABB::insertar(ABBNodo* nodo, Animal* dato) {

    if (nodo == NULL) {
        nodo = new ABBNodo(dato);
    }

    else if (dato->edad > nodo->conseguir_dato()->edad) {
        nodo->setear_derecha(insertar(nodo->conseguir_derecha(), dato), nodo);
    }

    else {
        nodo->setear_izquierda(insertar(nodo->conseguir_izquierda(), dato), nodo);
    }
    return nodo;
}

void ABB::insertar(Animal* dato)
{
    this->raiz = insertar(this->raiz, dato);
}

// IMPRIMIR EN ORDEN, COMPLEJIDAD PEOR CASO: O(n)
// n: #nodos
void ABB::imprimir_en_orden(ABBNodo* nodo)
{
    if (nodo != NULL)
    {
        imprimir_en_orden(nodo->conseguir_izquierda());
        std::cout << nodo->conseguir_dato() << ' ';
        imprimir_en_orden(nodo->conseguir_derecha());
    }
}

void ABB::imprimir_en_orden()
{
    this->imprimir_en_orden(this->raiz);
}

void ABB::guardar_en_orden(ABBNodo* nodo, Animal** vector, int& i)
{
    if (nodo != NULL)
    {
        guardar_en_orden(nodo->conseguir_izquierda(), vector, i);
        vector[i] = nodo->conseguir_dato();
        i++;
        guardar_en_orden(nodo->conseguir_derecha(), vector, i);
    }
}

void ABB::guardar_en_orden(Animal** vector)
{
    int i = 0;
    this->guardar_en_orden(this->raiz, vector, i);
}

bool ABB::vacio()
{
    return this->raiz == NULL;
}


void ABB::eliminar_todos(ABBNodo* nodo)
{
    if(nodo == NULL)
        return;
    this->eliminar_todos(nodo->conseguir_izquierda());
    this->eliminar_todos(nodo->conseguir_derecha());
    delete nodo;
}

void ABB::eliminar_todos()
{
    this->eliminar_todos(this->raiz);
}

ABB::~ABB()
{
    this->eliminar_todos();
}
