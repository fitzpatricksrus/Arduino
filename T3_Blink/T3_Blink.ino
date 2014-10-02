//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	pinMode(13, OUTPUT);
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	for (int i = 0; i < 10; i++) {
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(100*i);
	}
}
