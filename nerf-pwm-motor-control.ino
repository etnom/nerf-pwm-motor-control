#include <Button.h>			//library for dealing with buttons

#define POT_IN_PIN 0		//pin for poteniometer as input
#define PWM_OUT_PIN 5		//pin for pwm, using pin 5 for 980 Hz PWM
#define TRIGGER_PIN 4		//pin for trigger

Button triggerBtn (TRIGGER_PIN, true, true, 25);		//button class, invert and internal pullups with 20 ms debounce time

void setup() {
	
}

void loop () {
	if (triggerBtn.isPressed()) {
		analogWrite(PWM_OUT_PIN, analogRead(POT_IN_PIN)/4);		//write PWM depending on pot value
	}
}
