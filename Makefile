.PHONY: all clean

CIFRA = cifraRSA.o
FACTORIZAR = factorizarPrimos.o

CC = g++
LIBS = gmp

all: encriptarRSA desencriptarRSA geraChavesRSA quebrarRSA testaPrimo

geraChavesRSA: geraChavesRSA.cpp $(CIFRA)
	$(CC) -o $@ $@.cpp  $(CIFRA) -l$(LIBS)

encriptarRSA: encriptarRSA.cpp $(CIFRA)
	$(CC) -o $@ $@.cpp $(CIFRA) -l$(LIBS)

desencriptarRSA: desencriptarRSA.cpp $(CIFRA)
	$(CC) -o $@ $@.cpp $(CIFRA) -l$(LIBS)

quebrarRSA: quebrarRSA.cpp $(FACTORIZAR)
	$(CC) -o $@ $@.cpp  $(FACTORIZAR) -l$(LIBS)

testaPrimo: testaPrimo.cpp $(FACTORIZAR)
	$(CC) -o $@ $@.cpp  $(FACTORIZAR) -l$(LIBS)

clean:
	rm -f  encriptarRSA desencriptarRSA geraChavesRSA chavePublica chavePrivada *.o
