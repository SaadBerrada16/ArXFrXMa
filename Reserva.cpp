#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Reserva.hpp"
#include "Animal.hpp"

//constructor
Reserva::Reserva() {
    animales = new Diccionario<Animal*>;
    coche = new Auto;
    animales_escapados = 0;
}

void Reserva::iniciar() {
	animales -> iniciar();
}

bool Reserva::hay_siguiente() {
	return animales -> hay_siguiente();
}

Animal* Reserva::siguiente() {
	return animales -> siguiente();
}

int Reserva::obtener_cantidad_de_animales(){
	return animales -> obtener_cantidad();
}

void Reserva::listar_animales() {
	Animal* animal_actual;
	animales -> iniciar();
	while (animales -> hay_siguiente()) {
		animal_actual = animales -> siguiente();
    	animal_actual -> mostrar_animal();
  	}
}

Animal* Reserva::buscar_animal(string nombre) {
	string nombre_actual;
	Animal* animal;
	animales -> iniciar();
	while (animales -> hay_siguiente()) {
		animal = animales -> siguiente();
		nombre_actual = animal->nombre;
		if (nombre_actual == nombre)
		return animal;
	}
	return 0;
}

void Reserva::agregar_animal(Animal* animal) {
	animales -> insertar(animal->nombre, animal);
}

void Reserva::banar_animales(){
	Animal* animal_actual;
	animales -> iniciar();
	while(animales -> hay_siguiente()){
		animal_actual = animales -> siguiente();
		animal_actual -> duchar();
		}
}

void Reserva::alimentar_animales(){
	Animal* animal_actual;
	animales -> iniciar();
	while(animales -> hay_siguiente()){
		animal_actual = animales -> siguiente();
		animal_actual -> comer();
	}
}

void mostrar_adoptar(int &cant, Animal* a){
	a -> mostrar_animal();
	cant++;
	cout << "\n\n" << endl;
}

void Reserva::adoptar_animal(int espacio) {
  	string nombre_animal = "nombre_animal";
    
    int posicion = 0;
    Animal** vector = new Animal*[animales -> obtener_cantidad()];
    TreeSort* arbol = new TreeSort();
    
    
    animales -> iniciar();
  	if(espacio == 0){
    	cout << "No se puede adoptar un animal, espacio no suficiente" << endl;
  	} 
    else {
        while (animales -> hay_siguiente()) {
            Animal* a = animales -> siguiente();

      	    if(a -> tamano == "diminuto") {
                vector[posicion] = a;
                posicion += 1;
            }

      	    if(espacio > 2){
        	    if(a -> tamano == "pequeño") {
                    vector[posicion] = a;
                    posicion += 1;
                }

        	    if(espacio > 10){
          		    if(a -> tamano == "mediano") {
                        vector[posicion] = a;
                        posicion += 1;
                    }

          		    if(espacio > 20){
            		    if(a -> tamano == "grande") {
                            vector[posicion] = a;
                            posicion += 1;
                        }

            		    if(espacio > 50){
              			    if(a -> tamano == "gigante") {
                                vector[posicion] = a;
                                posicion += 1;
                            }
            		    }   
          		    }
        	    }
      	    }
        }

        arbol -> sort(vector, posicion);
        for (int i = posicion - 1; i >= 0; i --) {
            vector[i] -> mostrar_animal();
        }

    	if(posicion != 0){
      		bool existe_nombre = false;
      		while(!existe_nombre){
      		cout << "Ingrese el nombre del Animal que quéres adoptar o 'CANCELAR' si quéres cancelar la adopcion: ";
      		cin >> nombre_animal;
        		if(nombre_animal == "CANCELAR"){
          			existe_nombre = true;
          			cout << "\nAdopcion cancelada." << endl;
        		}

            animales->iniciar();
        		for(int i = 0; i < animales -> obtener_cantidad(); i++){
          			Animal* a = animales -> siguiente();
          			if(nombre_animal == a->nombre){
            			delete a;
            			animales -> eliminar(nombre_animal);
            			cout << "Felicitaciones " << nombre_animal << " forma ahora parte de tu familia !" << endl;
            			existe_nombre = true;
          			}
        		}
      		}
    	} 
        else {
      		cout << "No tenemos ningun animal que pueden entrar en su espacio disponible." << endl;
    	}
  	}

    delete [] vector;
}

void Reserva::guardar_animales() {
    remove(PATH_ANIMALES.c_str());
    string nombre_archivo = "animales.csv";
    fstream archivo;
    archivo.open(nombre_archivo, ios::out | ios::app);
    animales -> iniciar();
    while (animales -> hay_siguiente()) {
        Animal* a = animales -> siguiente();
        archivo <<  a->nombre << "," << a->edad << "," << a->tamano << "," << a -> especie.substr(0, 1) << "," << a -> personalidad -> get_nombre();
        if (animales -> hay_siguiente())
            archivo << endl;
    }
}

void Reserva::cargar_animales() {
    fstream archivo;
    archivo.open(PATH_ANIMALES.c_str(), fstream::in);

    string nombre;
    string edad;
    string tamano;
    string especie;
    string personalidad;

    string linea;
    while (getline(archivo, linea,'\n')) {
        stringstream sanimal(linea);
        getline(sanimal, nombre, ',');
        getline(sanimal, edad, ',');
        getline(sanimal, tamano, ',');
        getline(sanimal, especie, ',');
        getline(sanimal, personalidad, ',');
        animales->insertar(nombre, crear_animal(nombre, edad, tamano, especie, personalidad));
    }

    archivo.close();
}

void Reserva::bajar_higiene_y_crecer_hambre(){
	Animal* animal_actual;
	animales -> iniciar();
	while (animales -> hay_siguiente()){
		animal_actual = animales -> siguiente();
		animal_actual -> ensuciar();
		animal_actual -> crecer_hambre();
	}
}


void Reserva::generar_mapa(Mapa* mapa){
    srand((unsigned)time(NULL));

    int n_animales = 5;
    mapa -> animales = new Animal*[n_animales];
    char* esp = new char[n_animales];
    mapa -> pos = generar_posiciones();

    for(int i = 0; i < n_animales; i++){
        mapa -> animales[i] = generar_animal();
        esp[i] = mapa -> animales[i] -> especie[0];
    }


    mapa -> colocar_animales(esp, n_animales);
    delete [] esp;
}

void Reserva::aumentar_combustible(){
    coche -> aumentar_combustible();
}

void buscar_camino_minimo_animales(Mapa* mapa, Auto* coche, int* costo, int n_animales, int &numero_animales_rescatables){
    for (int i = 0; i < n_animales; i++){
        if (mapa -> pos[i] != 0){
            char* mapa_camino_minimo = new char[mapa -> n * mapa -> n];
            string destino = to_string(mapa -> pos[i]);
            
            mapa -> grafo -> camino_minimo("1" , destino);
            
            costo[i] = mapa -> grafo -> recuperar_costo((mapa -> pos[i]-1));
            
            int * recorrido = mapa -> grafo -> recuperar_recorrido();
            
            mapa -> imprimir_mapa_recorrido("1", destino, recorrido, mapa -> mapa[stoi(destino) - 1] , mapa_camino_minimo);
            
            if (coche -> combustible_suficiente(costo[i])){
              cout << "Con el combustible que tienes puedes rescatar el animal que está en la posición " << mapa -> pos[i] << " y se gastaria " << costo[i] << " de combustible" << endl << endl;
              numero_animales_rescatables++;
            } else {
                cout << "No puedes rescatar al animal en la posicion " << mapa -> pos[i] << " con el combustible actual" << endl;
            }
            
            delete [] mapa_camino_minimo;
        }
    }
}

int pedir_posicion_mapa(){
    int posicion;
    cout << "Ingrese la posicion de cual animal quéres rescatar o '0' si no quéres rescatar a un animal: " << endl;
    while(!(cin >> posicion)){
        cout << "Error: Ingrese un numero" << endl;
        cin.clear();
        cin.ignore();
    }
    return posicion;
}

void Reserva::rescatar_un_animal(Mapa* mapa, int n_animales, int* costo){
    int posicion_animal_a_rescatar = 0;
    posicion_animal_a_rescatar = pedir_posicion_mapa();

    if (posicion_animal_a_rescatar == 0 ){
        cout <<  "Salvaje cancelado." << endl;
        return;
    }

    // recorrido de la tabla de posicion
    for (int i = 0; i < n_animales; i++){
        string nombre;
        if(mapa -> pos[i] == posicion_animal_a_rescatar){
            cout << endl << "Ingrese un nombre para otorgarle al animal rescatado: ";
            cin >> nombre;
            while(buscar_animal(nombre) != 0 ){
                cout << "Ingrese otro nombre que no exista en la reserva: " << endl;
                cin.clear();
                cin.ignore();
                cin >> nombre;
            }
            mapa -> animales[i] -> nombre = nombre;
            agregar_animal(mapa -> animales[i]);
            coche -> bajar_combustible(costo[i]);
            mapa -> mapa[mapa -> pos[i] - 1] = '.';
            mapa -> pos[i] = 0;
            cout << "\n\n Rescataste a: " << endl;
            mapa -> animales[i] -> mostrar_animal();
            mapa -> animales[i] = nullptr;
            mapa -> cantidad_animales_mapa--;
            return;
        }
    }
    
    //Si ingresan una posicion del mapa en la que no hay un animal
    cout << "No hay ningun animal en esa posicion" << endl;
    rescatar_un_animal(mapa, n_animales, costo);
}


void Reserva::rescatar_animales(Mapa* mapa){

    if(mapa->cantidad_animales_mapa == 0){
        cout << "No hay mas animales para rescatar" << endl;
        return;
    }

    int n_animales = 5;
    int* costo = new int[n_animales];
    int numero_animales_rescatables = 0;

    mapa -> imprimir_mapa();
    mapa -> grafo -> crear_dijkstra();

    buscar_camino_minimo_animales(mapa, coche, costo, n_animales , numero_animales_rescatables);
    if(numero_animales_rescatables == 0) {
        cout << "No hay animales que puedas rescatar con el combustible actual" << endl;
        return;
    }
    rescatar_un_animal(mapa, n_animales, costo);

    delete [] costo;
}


void Reserva::se_escapan(){
    Animal* animal_actual;
	animales->iniciar();
	while (animales->hay_siguiente()){
		animal_actual = animales->siguiente();
		if (animal_actual->higiene == 0){
            animales->eliminar(animal_actual->nombre);
            cout << endl << "Soy " << animal_actual->nombre << " el " << animal_actual->especie << ", me escapo porque huelo re mal" << endl;
            animales_escapados++;
        }
        else if (animal_actual->hambre == 100){
            animales->eliminar(animal_actual->nombre);
            cout << endl << "Soy " << animal_actual->nombre << " el " << animal_actual->especie << ", me escapo porque tengo re hambre" << endl;
            animales_escapados++;
        }
	}
}

bool Reserva::partida_terminada(){
    if (animales_escapados >= 3){
        cout << endl << "Más de 3 animales se escapan, entonces la reserva es clausurada y la partida terminada" << endl;
        return true;
    }
    return false;
}

// Destructor
Reserva::~Reserva() {
  	Animal * animal_actual;
  	animales->iniciar();
  	while (animales->hay_siguiente()){
    	animal_actual = animales->siguiente();
    	delete animal_actual;
  	}
  	delete animales;
    delete coche;
}

Animal* generar_animal(){
    string especies[7] = {"P", "G", "C", "R", "O", "E", "L"};
    string personalidades[4] = {"dormilon", "travieso", "jugueton", "sociable"};
    string tamanos[5] = {"diminuto", "pequeño", "mediano", "grande", "gigante"};
    string nombres[1] = {"Nombre Temporal"};

    string especie = especies[random_num(7)];
    string personalidad = personalidades[random_num(4)];
    string tamano = tamanos[random_num(5)];
    string nombre = nombres[random_num(1)];
    int edad = 1 + random_num(20); // pq no puede ser un animal de 0 ano de edad

    Personalidad* p = convertir_personalidad(personalidad);

    if (especie == "P")
        return new Perro(nombre, edad, tamano, p);
    else if (especie == "G")
        return new Gato(nombre, edad, tamano, p);
    else if (especie == "C")
        return new Caballo(nombre, edad, tamano, p);
    else if (especie == "R")
        return new Roedor(nombre, edad, tamano, p);
    else if (especie == "O")
        return new Conejo(nombre, edad, tamano, p);
    else if (especie == "E")
        return new Erizo(nombre, edad, tamano, p);
    else
        return new Lagartija(nombre, edad, tamano, p);

}

int* generar_posiciones() {
  int n = 5;
  srand((unsigned)time(NULL));
  int* posiciones = new int[n];
  for (int i = 0; i < n; i++) {
      bool unico = false;
      while(!unico){
          int rd = 2 + random_num(63);
          posiciones[i] = rd;
          unico = true;
          for (int k = 0; k < i; k++){
              if(posiciones[i] == posiciones[k]) unico = false;
          }

      }

  }
    return posiciones;
}

Personalidad* convertir_personalidad(string p) {
    if (p == "dormilon") {
        Dormilon* d = new Dormilon();
        return d;
    } else if (p == "travieso") {
        Travieso* t = new Travieso();
        return t;
    } else if (p == "jugueton") {
        Jugueton* j = new Jugueton();
        return j;
    } else if (p == "sociable") {
        Sociable* s = new Sociable();
        return s;
    } else {
        return 0;
    }
}

Animal* crear_animal(string nombre, string edad, string tamano, string especie, string personalidad) {
    int e = stoi(edad);
    Personalidad* p = convertir_personalidad(personalidad);
    if (especie == "perro" || especie == "P")
        return new Perro(nombre, e, tamano, p);
    else if (especie == "gato" || especie == "G")
        return new Gato(nombre, e, tamano, p);
    else if (especie == "caballo" || especie == "C")
        return new Caballo(nombre, e, tamano, p);
    else if (especie == "roedor" || especie == "R")
        return new Roedor(nombre, e, tamano, p);
    else if (especie == "conejo" || especie == "O")
        return new Conejo(nombre, e, tamano, p);
    else if (especie == "erizo" || especie == "E")
        return new Erizo(nombre, e, tamano, p);
    else
        return new Lagartija(nombre, e, tamano, p);
}

int random_num(int rango){
    // srand((unsigned)time(NULL));
    int random = rand() % rango;
    return random;
}

void Reserva::imprimir_combustible(){
    cout << "El nivel de combustible actual es: " << coche -> combustible << "/100" << endl;
}

void Reserva::cargar_combustible(int combustible){
    coche -> cargar_combustible(combustible);
}