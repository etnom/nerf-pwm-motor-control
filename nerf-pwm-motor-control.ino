#define POT_IN_PIN 0		//pin for poteniometer as input
#define PWM_OUT_PIN 3		//pin for pwm

void setup () {
	pinMode(PWM_OUT_PIN, OUTPUT);		//set pwm pin to output
}

void loop () {
	analogWrite(PWM_OUT_PIN, analogRead(POT_IN_PIN)/4);		//write PWM depending on pot value
}