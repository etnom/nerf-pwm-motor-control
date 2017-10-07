#include <Button.h>			//library for dealing with buttons

#define POT_IN_PIN 0			//pin for poteniometer as input
#define PWM_OUT_PIN 5			//pin for pwm, using pin 5 for 980 Hz PWM
#define TRIGGER_PIN 4			//pin for trigger
#define MOTOR_ACCEL_TIME 200	//time to allow motor to reach full speed, in ms. May need to be adjusted depending on motor torque

Button triggerBtn (TRIGGER_PIN, true, true, 25);		//button class, invert and internal pullups with 20 ms debounce time

boolean hasAccelerated = false;		//boolean to check if motor spinning at full speed

void setup() {

}

void loop () {
	triggerBtn.read();

	if(triggerBtn.isPressed() && !hasAccelerated) {				//when trigger first pressed
		digitalWrite(PWM_OUT_PIN, HIGH);						//motor at full power
		delay(MOTOR_ACCEL_TIME);								//allow motor to reach full speed
		hasAccelerated = true;									//allow pwm
	} else if (triggerBtn.isPressed() && hasAccelerated) {		//if trigger pressed
		analogWrite(PWM_OUT_PIN, analogRead(POT_IN_PIN)/4);		//write PWM depending on pot value
	} else if (triggerBtn.wasReleased()) {						//when trigger released
		digitalWrite(PWM_OUT_PIN, LOW);							//turn motor off
		hasAccelerated = false;									//reset flag to check for acceleration
	}
}
