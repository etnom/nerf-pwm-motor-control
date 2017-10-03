#define POT_IN_PIN 0		//pin for poteniometer as input
#define PWM_OUT_PIN 5		//pin for pwm, using pin 5 for 980 Hz PWM

void setup () {
}

void loop () {
	analogWrite(PWM_OUT_PIN, analogRead(POT_IN_PIN)/4);		//write PWM depending on pot value
}