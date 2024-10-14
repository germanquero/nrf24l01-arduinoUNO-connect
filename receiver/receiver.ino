#include <SPI.h>
#include <RF24.h>

RF24 radio(9,8);

const byte addr[6] = "00001";

void setup() {
	Serial.begin(9600);
	radio.begin();
	

	// Abrir el pipe de lectura
	radio.openReadingPipe(0, addr);

	radio.setPALevel(RF24_PA_HIGH);

	// Comenzar a escuchar (receptor)
	radio.startListening();
}

void loop() {
	if(radio.available()) {
		// RF24.h utiliza un buffer de tamaño fijo de 32 bytes
		char buff[32] = ""; // buffer de lectura

		// Leer el mensaje
		radio.read(&buff, sizeof(buff));

		Serial.println(buff);
	}
}
