#include <iostream>
#include "menu.hpp"
#include "Animal.hpp"


using namespace std;

void mostrar_menu(){
    cout << endl << endl << endl;
    cout << "MENU" << endl
    << '\t' << "1. Listar animales" << endl
    << '\t' << "2. Rescatar animal" << endl
    << '\t' << "3. Buscar animal" << endl
    << '\t' << "4. Cuidar animales" << endl
    << '\t' << "5. Adoptar animal" << endl
    << '\t' << "6. Guardar y salir" << endl;
}

void mostrar_menu_rescatar(){
    cout << endl << endl << endl;
    cout << "Ese nombre ya existe" << endl
    << '\t' << "1. Ingresar otro nombre" << endl
    << '\t' << "2. Volver al menú" << endl;
}

void mostrar_menu_cuidar(){
    cout << endl << endl << endl;
    cout << "MENU" << endl
    << '\t' << "1. Elegir individualmente" << endl
    << '\t' << "2. Alimentar a todos" << endl
    << '\t' << "3. Bañar a todos" << endl
    << '\t' << "4. Regresar al inicio" << endl;
}

void mostrar_menu_cuidar_individualmente(){
    cout << endl << endl << endl;
    cout << '\t' << "1. Bañar" << endl
    << '\t' << "2. Alimentar" << endl
    << '\t' << "3. Saltear" << endl
    << '\t' << "4. Regresar al inicio" << endl;
}

int pedir_opcion(){
    int opcion_elegida;
    cout << endl << "Ingrese el número de su acción elegida : ";
    while(!(cin >> opcion_elegida)){
        cout << "Error: Ingrese un numero: " << endl;
        cin.clear();
        cin.ignore();
    }
    return opcion_elegida - 1;
}

void validar_opcion_elegida(int &opcion_elegida){
    bool es_opcion_valida = opcion_elegida >= 0 && opcion_elegida < CANTIDAD_DE_OPCIONES;
    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> opcion_elegida;
        es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= CANTIDAD_DE_OPCIONES;
    }
}

void validar_opcion_rescatar(int &opcion_elegida){
    bool es_opcion_valida = opcion_elegida >= 0 && opcion_elegida < CANTIDAD_DE_OPCIONES_RESCATAR;
    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> opcion_elegida;
        es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= CANTIDAD_DE_OPCIONES_RESCATAR;
    }
}

void validar_opcion_cuidar(int &opcion_elegida){
    bool es_opcion_valida = opcion_elegida >= 0 && opcion_elegida < CANTIDAD_DE_OPCIONES_CUIDAR;
    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> opcion_elegida;
        es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= CANTIDAD_DE_OPCIONES_CUIDAR;
    }
}

void validar_opcion_cuidar_individualmente(int &opcion_elegida){
    bool es_opcion_valida = opcion_elegida >= 0 && opcion_elegida < CANTIDAD_DE_OPCIONES_CUIDAR_INDIVIDUALMENTE;
    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> opcion_elegida;
        es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= CANTIDAD_DE_OPCIONES_CUIDAR_INDIVIDUALMENTE;
    }
}

int cargar_y_validar_opcion_menu_individual(){
    mostrar_menu_cuidar_individualmente();
    int opcion = pedir_opcion();
    validar_opcion_cuidar_individualmente(opcion);
    return opcion;
}

void procesar_menu_individual(Reserva* reserva, int posicion_del_animal){
    int opcion;
    Animal* animal_actual = reserva->elegir_animal(posicion_del_animal);

    if(animal_actual == 0) return;

    animal_actual->mostrar_animal();

    opcion = cargar_y_validar_opcion_menu_individual();

    while(opcion != VOLVER){
        switch(opcion){
            case BANAR:
                animal_actual->duchar();
                animal_actual->mostrar_animal();
                opcion = cargar_y_validar_opcion_menu_individual();
                break;
            case ALIMENTAR:
                animal_actual->comer();
                animal_actual->mostrar_animal();
                opcion = cargar_y_validar_opcion_menu_individual();
                break;
            case SALTEAR:
                procesar_menu_individual(reserva, posicion_del_animal + 1);
                return;
        }
    }
}

void procesar_opcion(Reserva* reserva, int opcion, Mapa* mapa){
    Animal* animal = nullptr;
    string nombre = "";
    string edad = "";
    string tamano = "";
    string especie = "";
    string personalidad = "";
    string hambre = "";
    string higiene = "";

    int posicion_del_animal = POSICION_INVALIDA;
    // int opcion_rescatar = 0;
    int opcion_cuidar;
    reserva->bajar_higiene_y_crecer_hambre();

    switch (opcion) {
        case LISTAR_ANIMALES:
            reserva->listar_animales();
            break;

        case RESCATAR_ANIMAL:
            reserva->rescatar_animales(mapa);


          cout<<"OK"<<endl;
            // animal = reserva->generar_animal();
            // nombre = animal->nombre;
            // while(reserva->buscar_animal(nombre) != 0 && opcion_rescatar == INGRESAR_NOMBRE) {
            //     mostrar_menu_rescatar();
            //     opcion_rescatar = pedir_opcion();
            //     validar_opcion_rescatar(opcion_rescatar);
            //     if (opcion_rescatar == INGRESAR_NOMBRE) {
            //         nombre = pedir_nombre();
            //     }
            // }
            // if (opcion_rescatar == INGRESAR_NOMBRE) {
            //     animal->nombre = nombre;
            //     reserva->agregar_animal(animal);
            //     cout << endl << "Animal guardado correctamente" << endl << endl;
            // }
            break;

        case BUSCAR_ANIMAL:
            nombre = pedir_nombre();
            animal = reserva->buscar_animal(nombre);
            if(animal == 0){
                cout << "No existe el animal" << endl;
                break;
            }
            animal->mostrar_animal();
            break;

        case CUIDAR_ANIMAL:
            if(reserva->obtener_cantidad_de_animales() == 0){
                cout << "No hay animales para cuidar" << endl;
            }
            mostrar_menu_cuidar();
            opcion_cuidar = pedir_opcion();
            validar_opcion_cuidar(opcion_cuidar);
            switch (opcion_cuidar) {
            case ELEGIR_INDIVIDUALMENTE:
                posicion_del_animal = 1;
                procesar_menu_individual(reserva, posicion_del_animal);
                break;
            case ALIMENTAR_TODOS:
                reserva->alimentar_animales();
                break;
            case BANAR_TODOS:
                reserva->banar_animales();
                break;
            case REGRESAR_INICIO:
                break;
          }
          break;

        case ADOPTAR_ANIMAL:
            int espacio = pedir_espacio_disponible();
            reserva->adoptar_animal(espacio);
            break;
    }
}

string pedir_nombre(){
    string nombre;
    cout << "Ingrese el nombre de su animal: ";
    cin >> nombre;

    return nombre;
}

string pedir_edad(){
    int edad;
    cout << "Ingrese un edad por el animal: ";
    while(!(cin >> edad)){
        cout << "Error: Ingrese un numero: " << endl;
        cin.clear();
        cin.ignore();
    }

    while(!es_edad_valido(edad)){
        cout << "El edad ingresado no tiene un formato valido, por favor ingrese otro edad: ";
        cin >> edad;
    }
    return to_string(edad);
}

string pedir_tamano(){
    string tamano;
    cout << "Ingrese un tamano por el animal: ";
    cin >> tamano;

    while(!es_tamano_valido(tamano)){
        cout << "El tamano ingresado no tiene un formato valido, por favor ingrese otro tamano: ";
        cin >> tamano;
    }
    return tamano;
}

string pedir_especie(){
    string especie;
    cout << "Ingrese una especie por el animal: ";
    cin >> especie;

    while(!es_especie_valido(especie)){
        cout << "La especie ingresado no tiene un formato valido, por favor ingrese otra especie: ";
        cin >> especie;
    }
    return especie;
}

string pedir_personalidad(){
    string personalidad;
    cout << "Ingrese una personalidad por el animal (dormilon, jugueton, travieso, sociable): ";
    cin >> personalidad;

    while(!es_personalidad_valido(personalidad)){
        cout << "La personalidad ingresado no tiene un formato valido, por favor ingrese otra personalidad: ";
        cin >> personalidad;
    }
    return personalidad;
}

int pedir_espacio_disponible(){
    int espacio;
    cout << "Ingrese el espacio disponible para el animal (en metros cuadrados): ";
    while(!(cin >> espacio)){
        cout << "Error: Ingrese un numero: " << endl;
        cin.clear();
        cin.ignore();
    }
    return espacio;
}

bool es_edad_valido(int edad){
    if((0 <= edad) && (edad <= 100)){
        return true;
    }
    return false;
}

bool es_tamano_valido(string tamano){
    if (tamano == "diminuto" || tamano == "pequeño" || tamano == "mediano"
     || tamano == "grande" || tamano == "gigante"){
       return true;
    }
    return false;
}

bool es_especie_valido(string especie){
    if (especie == "P" || especie == "G" || especie == "C" || especie == "R"
     || especie == "O" || especie == "E" || especie == "L"
     || especie == "perro" || especie == "gato" || especie == "caballo"
     || especie == "roedor" || especie == "conejo" || especie == "erizo"
     || especie == "lagartija"){
       return true;
    }
    return false;
}

bool es_personalidad_valido(string personalidad){
    if (personalidad == "dormilon" || personalidad == "jugueton"
     || personalidad == "sociable" || personalidad == "travieso"){
       return true;
    }
    return false;
}
