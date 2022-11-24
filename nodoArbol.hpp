#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
#include <string.h>
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
        Nodo<Tipo>* antecesor;
        Nodo<Tipo>* vias[M+1];
        Nodo<Tipo>* dividirNodo();
    public:
        Nodo();
        Nodo(bool eh);

        void insertar(string clave, Tipo dato);

        bool contieneClave(string clave);

        Tipo obtenerDato(string clave);

        void mostrarNodo();

        Tipo eliminar(string clave);     

        ~Nodo();
};

template <typename Tipo>
Nodo<Tipo>::Nodo() {
    antecesor = NULL;
    for (int i = 0; i < M; i++) {
        claves[i] = "";
        vias[i] = NULL;
    } 
    vias[M] = NULL;
}

template <typename Tipo>
Nodo<Tipo>::Nodo(bool eh) {
    esHoja = eh;
    antecesor = NULL;
    for (int i = 0; i < M; i++) {
        claves[i] = "";
        vias[i] = NULL;
    } 
    vias[M] = NULL;
}

template <typename Tipo>
Nodo<Tipo>* Nodo<Tipo>::dividirNodo() {
    string clave = claves[medio];
    Tipo dato = datos[medio];
    bool bool_eliminado = eliminado[medio];
    Nodo<Tipo>* nodo_hijo_derecha = new Nodo<Tipo>();
    Nodo<Tipo>* nodo_hijo_izquierda = new Nodo<Tipo>();

    nodo_hijo_izquierda->esHoja = esHoja;
    nodo_hijo_derecha->esHoja = esHoja;

    //Actualizamos los nodos hijos, sus claves, sus datos, sus vias y sus antecesores
    for (int i = 0; i < medio; i++) {
        nodo_hijo_izquierda->claves[i] = claves[i];
        nodo_hijo_izquierda->datos[i] = datos[i];
        nodo_hijo_izquierda->eliminado[i] = eliminado[i];
        nodo_hijo_izquierda->vias[i] = vias[i];
        if (!nodo_hijo_izquierda->esHoja) //si el nodo hijo no es una hoja tenemos que reconectar los hijos con el nuevo nodo creado con el atributo antecesor
            nodo_hijo_izquierda->vias[i]->antecesor = nodo_hijo_izquierda;
    }
    nodo_hijo_izquierda->vias[medio] = vias[medio];
    if (!nodo_hijo_izquierda->esHoja)
        nodo_hijo_izquierda->vias[medio]->antecesor = nodo_hijo_izquierda;

    for (int i = medio + 1; i < M; i++) {
        int j = i - medio - 1;
        nodo_hijo_derecha->claves[j] = claves[i];
        nodo_hijo_derecha->datos[j] = datos[i];
        nodo_hijo_derecha->eliminado[j] = eliminado[i];
        nodo_hijo_derecha->vias[j] = vias[i];
        if (!nodo_hijo_derecha->esHoja)
            nodo_hijo_derecha->vias[j]->antecesor = nodo_hijo_derecha;
    }
    nodo_hijo_derecha->vias[M - 1 - medio - 1 + 1] = vias[M];
    if (!nodo_hijo_derecha->esHoja)
        nodo_hijo_derecha->vias[M - 1 - medio - 1 + 1]->antecesor = nodo_hijo_derecha;

    //Ponemos las vias a NULL porque este nodo lo vamos a borrar y sera reemplazado por el nodo_hijo_izquierda y nodo_hijo_derecha. 
    //Si no ponemos las vias a NULL, cuando lo boremos se va a borrar de manera recursiva hasta sus hojas
    for (int i = 0; i < M; i++) {
        claves[i] = "";
        vias[i] = NULL;
    }
    vias[M] = NULL;
    
    //Subir la clave al antecesor
    if (antecesor != NULL) {//si nuestro nodo tiene padre subimos y ordenamos la clave y cambiamos sus vias
        int i = 0;
        while (antecesor->claves[i] != "" && clave > antecesor->claves[i])
            i++;
        for (int j = M-1; j > i; j--) {
            antecesor->claves[j] = antecesor->claves[j-1];
            antecesor->datos[j] = antecesor->datos[j-1];
            antecesor->eliminado[j] = antecesor->eliminado[j-1];
            antecesor->vias[j+1] = antecesor->vias[j];
        }
        //cout << antecesor->claves[i-1] << endl;
        antecesor->claves[i] = clave;
        antecesor->datos[i] = dato;
        antecesor->eliminado[i] = bool_eliminado;
        antecesor->vias[i] = nodo_hijo_izquierda;
        antecesor->vias[i+1] = nodo_hijo_derecha;

        nodo_hijo_izquierda->antecesor = antecesor;
        nodo_hijo_derecha->antecesor = antecesor;

        if (antecesor->claves[M-1] != "") {
            Nodo* n = antecesor->dividirNodo();
            if (n != NULL) 
                delete n;
        }
        return this;
    }
    else { //si nuestro nodo no tiene padre cambiamos este nodo y no necesitamos borrarlo por eso delvovemos NULL
        claves[0] = clave;
        datos[0] = dato;
        eliminado[0] = bool_eliminado;
        esHoja = false;
        vias[0] = nodo_hijo_izquierda;
        vias[1] = nodo_hijo_derecha;

        nodo_hijo_izquierda->antecesor = this;
        nodo_hijo_derecha->antecesor = this;

        return NULL;
    }
}

template <typename Tipo>
void Nodo<Tipo>::insertar(string clave, Tipo dato) {
    int  i = 0;
    while (claves[i] != "" && clave > claves[i])
       i++;
    if (esHoja) {
        for (int j = M-1; j > i; j--) {
            claves[j] = claves[j-1];
            datos[j] = datos[j-1];
            eliminado[j] = eliminado[j-1];
        }
        claves[i] = clave;
        datos[i] = dato;
        eliminado[i] = false;
        if (claves[M-1] != "") {
            Nodo<Tipo>* n = this->dividirNodo();
            if (n != NULL) 
                delete n;
        }
    }
    else {
        vias[i]->insertar(clave, dato);
    }
}

template <typename Tipo>
bool Nodo<Tipo>::contieneClave(string clave) {
    int  i = 0;
    while (claves[i] != "" && clave >= claves[i]) {
        if (clave == claves[i] && !eliminado[i])
            return true;
        i++;
    }

    if (vias[i] == NULL)
        return false;
    else 
        return vias[i]->contieneClave(clave);
}

template <typename Tipo>
Tipo Nodo<Tipo>::obtenerDato(string clave) {
    int  i = 0;
    while (claves[i] != "" && clave >= claves[i]) {
        if (clave == claves[i])
            return datos[i];
        i++;
    }
    return vias[i]->obtenerDato(clave);
}


template <typename Tipo>
void Nodo<Tipo>::mostrarNodo() {
    for (int i = 0; i < M; i++) {
        cout << claves[i] << ",";
    }
    cout << endl;
    
    for (int i = 0; i < M+1; i++) {
        if (vias[i] != NULL)
            vias[i]->mostrarNodo();
    }
    
}


template <typename Tipo>
Tipo Nodo<Tipo>::eliminar(string clave) {
    int  i = 0;
    while (claves[i] != "" && clave >= claves[i]) {
        if (clave == claves[i]) {
            eliminado[i] = true;
            return datos[i];
        }
        i++;
    }
    return vias[i]->eliminar(clave);
}


template <typename Tipo>
Nodo<Tipo>::~Nodo() {
    for (int i = 0; i < M+1; i++) {
        if (vias[i] != NULL)
            delete vias[i];
    }
}

#endif // NODO_H_INCLUDED