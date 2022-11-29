#include "Mapa.hpp"

Mapa::Mapa() {
    n = 8;
    grafo = new Grafo();
    mapa = new char[n * n];
    mapa[0] = 'A';
    pos = new int[5];
    costo = 0;

    //mapa de char
    for(int i = 1; i < n * n; i++){
        mapa[i] = '.';
    }

    //crear matriz de adyacencia
    for(int i = 1; i <= (n * n); i++){
        grafo -> agregarVertice(to_string(i));
    }
    for (int i = 1; i <= (n * n); i++)
    {
        if(i % n != 0)grafo -> agregarCamino(to_string(i), to_string(i+1), conseguir_peso(i+1));

        if(i % n != 1) grafo -> agregarCamino(to_string(i), to_string(i-1), conseguir_peso(i-1));

        if(i < ( (n * n) - n )) grafo -> agregarCamino(to_string(i), to_string(i+n), conseguir_peso(i+n));

        if(i > n) grafo -> agregarCamino(to_string(i), to_string(i-n), conseguir_peso(i-n));
    }
}

int Mapa::conseguir_peso(int i){
    return tipos[i-1];
}

void Mapa::imprimir_mapa(){
  cout << "\n###  MAPA DE LA RESERVA  ###\n" << endl;
  for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "| "<< mapa[i*8+j] << " ";
        }
        cout << "|" <<endl;
    }

    cout << "\n\n" << endl;
}

void Mapa::colocar_animales(char* animales, int n_animales){
    for(int i = 0; i < n_animales; i++){
        mapa[pos[i]-1] = animales[i];
    }
}


void Mapa::actualizar_posiciones(){
    int j = 0;
    for(int i = 1; i < n * n; i++){
        if(mapa[i] != '.'){
            pos[j] = i+1;
            j++;
        }
    }
}
