# RSA

CC	= g++
OPC = -Wall -lm -lgmp

.PHONY: clean all


all: encriptarRSA desencriptarRSA  quebrarRSA

clean:
	-rm *.o encriptarRSA desencriptarRSA  quebrarRSA



#gerarChavesRSA: gerarChavesRSA.cpp cifraRSA.o
#	${CC} -o $@ $@.cpp cifraRSA.o ${OPC}

encriptarRSA: encriptarRSA.cpp cifraRSA.o gerarChavesRSA.o 
	${CC} -o $@ $@.cpp cifraRSA.o gerarChavesRSA.o ${OPC}

desencriptarRSA: desencriptarRSA.cpp cifraRSA.o 
	${CC} -o $@ $@.cpp cifraRSA.o ${OPC}

quebrarRSA: quebrarRSA.cpp cifraRSA.o
	${CC} -o $@ $@.cpp cifraRSA.o ${OPC}
