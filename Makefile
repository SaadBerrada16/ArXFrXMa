CC=g++

CFLAGS=-Wall -Werror -Wconversion

LDFLAGS=

EXEC=main

SRC=./nodo_grafo.cpp  			\
	./lista_grafo.cpp  			\
	./abb_nodo.cpp				\
	./abb.cpp					\
	./arbol_busqueda.cpp			\
	./mapa.cpp  				\
	./dijkstra.cpp  			\
	./grafo.cpp					\
	./vertice.cpp  				\
	./personalidad.cpp 			\
	./dormilon.cpp 				\
	./jugueton.cpp   			\
	./sociable.cpp 				\
	./travieso.cpp    			\
	./animal.cpp 				\
    ./perro.cpp   				\
	./gato.cpp 					\
    ./caballo.cpp    			\
	./roedor.cpp 				\
	./conejo.cpp 				\
	./erizo.cpp    				\
	./lagartija.cpp 			\
	./animal_limpio.cpp 			\
	./animal_sucio.cpp 			\
	./auto.cpp 					\
	./reserva.cpp				\
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