# RSA

CC	= g++
OPC = -Wall -lm -lgmp

.PHONY: clean all


all: encriptarRSA desencriptarRSA gerarChavesRSA

clean:
	-rm *.o encriptarRSA desencriptarRSA gerarChavesRSA



gerarChavesRSA: gerarChavesRSA.cpp cifraRSA.o
	${CC} -o $@ $@.cpp cifraRSA.o ${OPC}

encriptarRSA: encriptarRSA.cpp cifraRSA.o
	${CC} -o $@ $@.cpp cifraRSA.o ${OPC}

desencriptarRSA: desencriptarRSA.cpp cifraRSA.o 
	${CC} -o $@ $@.cpp cifraRSA.o ${OPC}

quebrarRSA: quebrarRSA.cpp cifraRSA.o
	${CC} -o $@ $@.cpp cifraRSA.o ${OPC}
