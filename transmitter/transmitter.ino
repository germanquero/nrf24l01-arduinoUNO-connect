#include "SPI.h"
#include "RF24.h"

// PINES CS y CSN
RF24 radio(9,8);

// Direccion del canal de comunicacion
const byte addr[6] = "00001";

void setup() {
	Serial.begin(9600);

	// Inicializar el modulo
	radio.begin();

	// Abrir el pipe de escritura
	radio.openWritingPipe(addr);

	// Establecer nivel de potencia
	radio.setPALevel(RF24_PA_HIGH);

	// No escuchar (transmisor)
	radio.stopListening();
}


void loop() {
	// Definir el mensaje
	const char msg[] = "Hola desde el transmisor!";

	// Enviar el mensaje
	bool res = radio.write(&msg, sizeof(msg));

	// Comprobar si llego y hubo respuesta
	if(res) {
		Serial.println("El mensaje llego!");
	} else {
		Serial.println("Hubo un error...");
	}

	// Esperar 1 segundo entre mensajes
	delay(1000);
}
