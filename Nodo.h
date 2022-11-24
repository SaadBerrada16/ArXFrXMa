#ifndef GRAFOS_Nodo_Grafo_H
#define GRAFOS_Nodo_Grafo_H
#include <string>

using namespace std;

template < typename Tipo >
class Nodo_Grafo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo_Grafo<Tipo>* siguiente;

/*MÉTODOS*/
public:
    Nodo_Grafo(string nombre);

    //post: devuelve el Nodo_Grafo siguiente.
    Nodo_Grafo<Tipo>* obtenerSiguiente();

    //post: devuelve el nombre del Nodo_Grafo
    string obtenerNombre();

    //post: le asigna como siguiente el Nodo_Grafo recibido
    void asignarSiguiente(Nodo_Grafo<Tipo>* siguiente);

    ~Nodo_Grafo();
};

template<typename Tipo>
Nodo_Grafo<Tipo>::Nodo_Grafo(string nombre) {
    elemento = new Tipo(nombre);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo_Grafo<Tipo> *Nodo_Grafo<Tipo>::obtenerSiguiente() {
    return siguiente;
}

template<typename Tipo>
string Nodo_Grafo<Tipo>::obtenerNombre() {
    return elemento -> obtenerNombre();
}

template<typename Tipo>
void Nodo_Grafo<Tipo>::asignarSiguiente(Nodo_Grafo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo_Grafo<Tipo>::~Nodo_Grafo() {
    delete elemento;
}


#endif //GRAFOS_Nodo_Grafo_H
