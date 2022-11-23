#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "Animal.hpp"
using namespace std;

#define M 3
#define medio (M-1)/2

template <typename Tipo>
class Nodo {
    private:
        bool eliminado[M];
        string claves[M];
        Tipo datos[M];
        bool esHoja;
        Nodo* antecesor;
        Nodo* vias[M+1];
        void dividirNodo();
    public:
        void insertar(string clave, Tipo dato);

        bool contieneClave(string clave);

        Tipo obtenerDato(string clave);

        Tipo eliminar(string clave);     
};

template <typename Tipo>
void Nodo<Tipo>::dividirNodo() {
    clave = claves[medio];
    dato = datos[medio];
    
}

template <typename Tipo>
void Nodo<Tipo>::insertar(string clave, Tipo dato) {
    int  i = 0;
    while (claves[i] != NULL && clave > claves[i] && i < M)
       i++;
    if (esHoja) {
        for (int j = M-1; j > i; j--) {
            claves[j] = claves[j-1];
            datos[j] = datos[j-1];
        }
        claves[i] = clave;
        datos[i] = dato;
        if (claves[M-1] != NULL) 
            dividirNodo();
    }
    else {
        vias[i]->insertar(clave, dato);
    }
}

template <typename Tipo>
bool Nodo<Tipo>::contieneClave(string clave) {
    int  i = 0;
    while (clave >= claves[i] && i < M) {
        if (clave == claves[i])
            return true;
        i++;
    }
    vias[i]->contieneClave(clave);
}

template <typename Tipo>
Tipo Nodo<Tipo>::obtenerDato(string clave) {
    int  i = 0;
    while (clave >= claves[i] && i < M) {
        if (clave == claves[i])
            return datos[i];
        i++;
    }
    vias[i]->obtenerDato(clave);
}

template <typename Tipo>
Tipo Nodo<Tipo>::eliminar(string clave) {

}

#endif // NODO_H_INCLUDED
