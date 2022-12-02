#include "Mapa.hpp"

Mapa::Mapa() {
    n = 8;
    grafo = new Grafo();
    mapa = new char[n * n];
    mapa[0] = 'A';
    //pos = new int[5];
    costo = 0;
    cantidad_animales_mapa = 5;

    //mapa de char
    for(int i = 1; i < n * n; i++){
        mapa[i] = '.';
    }

    //crear matriz de adyacencia
    for(int i = 1; i <= (n * n); i++){
        grafo -> agregar_vertice(to_string(i));
    }
    for (int i = 1; i <= (n * n); i++)
    {
        if(i % n != 0)grafo -> agregar_camino(to_string(i), to_string(i + 1), conseguir_peso(i + 1));

        if(i % n != 1) grafo -> agregar_camino(to_string(i), to_string(i - 1), conseguir_peso(i - 1));

        if(i < ( (n * n) - n )) grafo -> agregar_camino(to_string(i), to_string(i + n), conseguir_peso(i + n));

        if(i > n) grafo -> agregar_camino(to_string(i), to_string(i - n), conseguir_peso(i - n));
    }
}

int Mapa::conseguir_peso(int i){
    return tipos[i - 1];
}

void Mapa::imprimir_mapa(){
  cout << "\n###  MAPA DE LA RESERVA  ###\n" << endl;
  for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "| "<< mapa[i * 8 + j] << " ";
        }
        cout << "|" <<endl;
    }

    cout << "\n\n" << endl;
}


void Mapa::imprimir_mapa_recorrido(string inicio, string destino, int* recorrido, char inicial_animal ,char* mapa){
    string aux = destino;

    cout << "--------------------------------------------------------------------" << endl;
    cout << "El camino minimo que une A (posicion " << inicio << ") con " << inicial_animal << " (posicion " << destino << ") es ";
    for(int i = 1; i < n * n; i++) mapa[i] = '.';
    mapa[stoi(inicio) - 1] = 'A';
    cout << aux << " <- ";
    aux = to_string(recorrido[stoi(aux) - 1]);
    while (aux != "0"){
        mapa[stoi(aux)] = 'X';
        cout << stoi(aux) + 1 << " <- "; 
        aux = to_string(recorrido[stoi(aux)]);
    }
    cout << inicio << endl;
    mapa[stoi(destino) - 1] = inicial_animal; 
    cout << "\n###  MAPA DE CAMINO MINIMO  ###\n" << endl;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "| "<< mapa[i * 8 + j] << " ";
        }
        cout << "|" <<endl;
    }
    cout << endl;
}

void Mapa::colocar_animales(char* animales, int n_animales){
    for(int i = 0; i < n_animales; i++){
        mapa[pos[i] - 1] = animales[i];
    }
}


Mapa::~Mapa(){
    delete grafo;

    delete [] pos;
    for (int i = 4; i >= 0; i--){
        delete animales[i];
    }
    delete [] animales;
    delete [] mapa;
}