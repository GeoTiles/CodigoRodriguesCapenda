.PHONY: all clean

objects = cifraRSA.o 
CC = g++
LIBS = gmp

all: encriptarRSA desencriptarRSA geraChavesRSA

geraChavesRSA: geraChavesRSA.cpp $(objects)
	$(CC) -o $@ $@.cpp  $(objects) -l$(LIBS)

encriptarRSA: encriptarRSA.cpp $(objects)
	$(CC) -o $@ $@.cpp $(objects) -l$(LIBS)

desencriptarRSA: desencriptarRSA.cpp $(objects)
	$(CC) -o $@ $@.cpp $(objects) -l$(LIBS)

clean:
	rm -f  encriptarRSA desencriptarRSA geraChavesRSA chavePublica chavePrivada *.o
