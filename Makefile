CC=g++

CFLAGS=-Wall -Werror -Wconversion

LDFLAGS=

EXEC=main

SRC=./NodoGrafo.cpp  			\
	./ListaGrafo.cpp  			\
	./BSTNode.cpp				\
	./BST.cpp				\
	./treeSort.cpp				\
	./Mapa.cpp  				\
	./CaminoMinimo.cpp  		\
	./Dijkstra.cpp  			\
	./Grafo.cpp					\
	./Vertice.cpp  				\
	./Personalidad.cpp 			\
	./Dormilon.cpp 				\
	./Jugueton.cpp   			\
	./Sociable.cpp 				\
	./Travieso.cpp    			\
	./Animal.cpp 				\
    ./Perro.cpp   				\
	./Gato.cpp 					\
    ./Caballo.cpp    			\
	./Roedor.cpp 				\
	./Conejo.cpp 				\
	./Erizo.cpp    				\
	./Lagartija.cpp 			\
	./AnimalLimpio.cpp 			\
	./AnimalSucio.cpp 			\
	./Auto.cpp 					\
	./Reserva.cpp				\
    ./menu.cpp    				\
    ./main.cpp

OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) -o ./$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean mrproper

clean:
	find *.o  -exec rm {} \;
	find main -exec rm {} \;

mrproper: clean
	rm $(EXEC)