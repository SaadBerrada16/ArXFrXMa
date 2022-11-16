CC=g++

CFLAGS=-Wall -Werror -Wconversion

LDFLAGS=

EXEC=main

SRC=./nodo.cpp  				\
		./lista.cpp  				\
		./Personalidad.cpp  \
		./Dormilon.cpp 			\
		./Jugueton.cpp   		\
		./Sociable.cpp 			\
		./Travieso.cpp    	\
		./Animal.cpp 				\
    ./Perro.cpp   			\
		./Gato.cpp 					\
    ./Caballo.cpp    		\
		./Roedor.cpp 				\
		./Conejo.cpp 				\
		./Erizo.cpp    			\
		./Lagartija.cpp 		\
		./AnimalLimpio.cpp 	\
		./AnimalSucio.cpp 	\
		./Reserva.cpp				\
    ./menu.cpp    			\
    ./main.cpp

OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) -o ./$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean mrproper

clean:
	find main -exec rm {} \;
	find *.o  -exec rm {} \;

mrproper: clean
	rm $(EXEC)
