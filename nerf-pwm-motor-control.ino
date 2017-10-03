#define POT_IN_PIN 0		
#define PWM_OUT_PIN 3		

void setup () {
	pinMode(PWM_OUT_PIN, OUTPUT);		
}

void loop () {
	analogWrite(PWM_OUT_PIN, analogRead(POT_IN_PIN)/4);		
}