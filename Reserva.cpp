#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Reserva.hpp"
#include "Animal.hpp"


//constructor
Reserva::Reserva() {
  animales = new Lista;
  coche = new Auto;
}

void Reserva::listar_animales() {
	Animal* animal_actual;
	animales->iniciar();
	while (animales->hay_siguiente()) {
		animal_actual = animales->siguiente();
    	animal_actual->mostrar_animal();
  	}
}

void Reserva::agregar_animal(Animal* animal) {
	animales->alta(animal, 1);
}

Animal* Reserva::buscar_animal(string nombre) {
	string nombre_actual;
	Animal* animal;
	animales->iniciar();
	while (animales->hay_siguiente()) {
		animal = animales->siguiente();
		nombre_actual = animal->nombre;
		if (nombre_actual == nombre)
		return animal;
	}
	return 0;
}

Animal* Reserva::elegir_animal(int posicion_animal_actual){
	Animal* animal_deseado = animales->consulta(posicion_animal_actual);
	if(animal_deseado == 0) return 0;
	return animal_deseado;
}

int Reserva::obtener_cantidad_de_animales(){
	return animales->obtener_cantidad();
}

void Reserva::banar_animales(){
	Dato animal_actual;
	animales->iniciar();
	while(animales->hay_siguiente()){
		animal_actual = animales->siguiente();
		animal_actual->duchar();
		}
}

void Reserva::alimentar_animales(){
	Dato animal_actual;
	animales->iniciar();
	while(animales->hay_siguiente()){
		animal_actual = animales->siguiente();
		animal_actual->comer();
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
        animales->alta(crear_animal(nombre, edad, tamano, especie, personalidad), 1);
    }

    archivo.close();
}

void Reserva::guardar_animales() {
    remove(PATH_ANIMALES.c_str());
    string nombre_archivo = "animales.csv";
    fstream archivo;
    archivo.open(nombre_archivo, ios::out | ios::app);
    animales->iniciar();
    while (animales->hay_siguiente()) {
        Animal* a = animales->siguiente();
        archivo <<  a->nombre << "," << a->edad << "," << a->tamano << "," << a->especie.substr(0, 1) << "," << a->personalidad->get_nombre();
        if (animales->hay_siguiente())
            archivo << endl;
    }
}

void Reserva::bajar_higiene_y_crecer_hambre(){
	Dato animal_actual;
	animales->iniciar();
	while (animales->hay_siguiente()){
		animal_actual = animales->siguiente();
		animal_actual->ensuciar();
		animal_actual->crecer_hambre();
	}
}

void mostrar_adoptar(int &cant, Animal* a){
	a->mostrar_animal();
	cant++;
	cout<<"\n\n"<<endl;
}

void Reserva::adoptar_animal(int espacio) {
  	int cantidad_animal_adoptable = 0;
  	string nombre_animal = "nombre_animal";
  	animales->iniciar();

  	if(espacio == 0){
    	cout << "No se puede adoptar un animal, espacio no suficiente" << endl;
  	} else {
      while (animales->hay_siguiente()) {
        Animal* a = animales->siguiente();

      	if(a->tamano == "diminuto")  mostrar_adoptar(cantidad_animal_adoptable, a);

      	if(espacio > 2){
        	if(a->tamano == "pequeño") mostrar_adoptar(cantidad_animal_adoptable, a);

        	if(espacio > 10){
          		if(a->tamano == "mediano") mostrar_adoptar(cantidad_animal_adoptable, a);

          		if(espacio > 20){
            		if(a->tamano == "grande") mostrar_adoptar(cantidad_animal_adoptable, a);

            		if(espacio > 50){
              			if(a->tamano == "gigante") mostrar_adoptar(cantidad_animal_adoptable, a);
            		}
          		}
        	}
      	}
    }

    	if(cantidad_animal_adoptable!=0){
      		bool existe_nombre = false;
      		while(!existe_nombre){
      		cout << "Ingrese el nombre del Animal que quéres adoptar o 'CANCELAR' si quéres cancelar la adopcion: ";
      		cin >> nombre_animal;
        		if(nombre_animal=="CANCELAR"){
          			existe_nombre=true;
          			cout<<"\nAdopcion cancelada."<<endl;
        		}

            animales->iniciar();
        		for(int i = 0; i < animales->obtener_cantidad(); i++){
          			Animal* a = animales->siguiente();
          			if(nombre_animal == a->nombre){
            			delete a;
            			animales->baja(i+1);
            			cout << "Felicitaciones " << nombre_animal << " forma ahora parte de tu familia !" << endl;
            			existe_nombre=true;
          			}
        		}
      		}
    	} else {
      		cout << "No tenemos ningun animale que pueden entrar en su espacio disponible." << endl;
    	}
  	}
}

void Reserva::generar_mapa(Mapa* mapa){
  srand((unsigned)time(NULL));

  int n_animales = 5;
  Animal** animales = new Animal*[n_animales];
  char* esp = new char[n_animales];
  int* pos = generar_posiciones();

  for(int i = 0; i < n_animales; i++){
    animales[i] = generar_animal();
    esp[i] = animales[i] -> especie[0];
  }

  mapa -> colocar_animales(esp, pos);
}

void Reserva::rescatar_animales(Mapa* mapa){
    mapa -> imprimir_mapa();
    mapa -> actualizar_posiciones();
    mapa -> grafo -> usarDijkstra();
    mapa -> grafo -> caminoMinimo("1" , "10");
    cout << mapa -> pos[0] << endl;

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

Animal* generar_animal(){
    string especies[7] = {"P", "G", "C", "R", "O", "E", "L"};
    string personalidades[4] = {"dormilon", "travieso", "jugueton", "sociable"};
    string tamanos[5] = {"diminuto", "pequeño", "mediano", "grande", "gigante"};
    string nombres[20] = {"Rocky", "Tobi", "Teo", "Max", "Jack", "Bruno", "Coco", "Lucas", "Zeus", "Rei", "Maya", "Lola", "Luna", "Cleo", "Mila", "Michi", "Nina", "Bella", "Kiara", "Reina"};

    string especie = especies[random_num(7)];
    string personalidad = personalidades[random_num(4)];
    string tamano = tamanos[random_num(5)];
    string nombre = nombres[random_num(20)];
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

int random_num(int rango){
    // srand((unsigned)time(NULL));
    int random = rand() % rango;
    return random;
}

// Destructor
Reserva::~Reserva() {
  	Dato animal_actual;
  	animales->iniciar();
  	while (animales->hay_siguiente()){
    	animal_actual = animales->siguiente();
    	delete animal_actual;
  	}
  	delete animales;
}
