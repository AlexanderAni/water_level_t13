#include <avr/io.h>
#define SENSOR PB0
#define LED PB3

void setup(){
	CLKPR &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)); // Clock Prescale Register to 0b0000 > divide by 1
	// DDRB &= ~(1<<SENSOR);		// set SENSOR as input
	// pinMode(SENSOR, INPUT);		// set SENSOR as input
	// DDRB |= (1<<LED);			// set LED as output
	pinMode(LED, OUTPUT);		// set LED as output
	// PORTB |= (1<<LED);		// set LED HIGH
	digitalWrite(LED, HIGH);	// set LED HIGH (off)
	// PORTB &= ~(1<<LED);		// set LED LOW

	// Start
	blink();

	// Charge-discharge preparation
	// Charge
	pinMode(SENSOR, INPUT);
	while (digitalRead(SENSOR) == 0) {
	}

	// Discharge
	pinMode(SENSOR, OUTPUT);
	digitalWrite(SENSOR, LOW);
	while (digitalRead(SENSOR)) {}

	// Check
	// Charge
	uint8_t count = 0;
	pinMode(SENSOR, INPUT);
	while (digitalRead(SENSOR) == 0) {
		count ++;
	}

	// Stop
	blink();

	// Pause
	delay(250); // 2 seconds

	// Result
	for (uint8_t i=0; i<count; i+=1){
		blink();
	}

	// On if water
	if (count > 5) {
		digitalWrite(LED, LOW);	// off
	}
}

void loop() {
}

void blink() {
	digitalWrite(LED, LOW);		// on
	delay(50); // 400 ms
	digitalWrite(LED, HIGH);	// off
	delay(50); // 400 ms
	// delay(125); // 1 second
}
