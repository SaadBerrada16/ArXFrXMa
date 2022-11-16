#include <iostream>
#include <fstream>
#include <sstream>
//#include <cstring>
#include "Reserva.hpp"
#include "Animal.hpp"

//constructor
Reserva::Reserva() {
  animales = new Lista;
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
        Jugueton* j = new Jugueton();
        return j;
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
