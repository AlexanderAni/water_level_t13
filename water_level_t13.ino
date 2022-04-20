#include <avr/io.h>
#define SENSOR PB2
#define LED PB3
#define OUT_SIGNAL PB0

void setup() {
	CLKPR &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)); // Clock Prescale Register to 0b0000 > divide by 1
	// DDRB &= ~(1<<SENSOR);		// set SENSOR as input
	// pinMode(SENSOR, INPUT);		// set SENSOR as input
	// DDRB |= (1<<LED);			// set LED as output
	pinMode(LED, OUTPUT);		// set LED as output
	pinMode(OUT_SIGNAL, OUTPUT);		// set LED as output
	digitalWrite(LED, HIGH);	// set LED HIGH (off)
	// PORTB |= (1<<LED);		// set LED HIGH
	// PORTB &= ~(1<<LED);		// set LED LOW

	// Start

	// Charge-discharge preparation
	// Charge
	pinMode(SENSOR, INPUT);
	while (digitalRead(SENSOR) == LOW) {
	}

	// Discharge
	pinMode(SENSOR, OUTPUT);
	digitalWrite(SENSOR, LOW);
	while (digitalRead(SENSOR) == HIGH) {}

	// Check
	// Charge
	uint8_t count = 0;
	pinMode(SENSOR, INPUT);
	while (digitalRead(SENSOR) == LOW) {
		count ++;
	}

	// Stop

	// Result
	if (count > 5) { // Full of Water
		digitalWrite(OUT_SIGNAL, HIGH);	// HIGH output signal
	} else { // Empty, no water
		digitalWrite(OUT_SIGNAL, LOW);		// LOW output signal
	}

	for (uint8_t i=0; i<count; i+=1){
		blink();
	}

	// LED
	if (count > 5) { // Full of Water
		digitalWrite(LED, HIGH);	// OFF
	} else { // Empty, no water
		digitalWrite(LED, LOW);		// ON
	}
}

void loop() {
}

void blink() {
	digitalWrite(LED, LOW);		// on
	delay(20); // 160 ms
	digitalWrite(LED, HIGH);	// off
	delay(20); // 160 ms
	// delay(50); // 400 ms
	// delay(125); // 1 second
}
