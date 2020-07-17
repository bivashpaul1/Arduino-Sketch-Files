int delayTime = 500;
void setup()
    {
    for (int pin = 5; pin <= 7; pin++)
        {pinMode(pin, OUTPUT);}
    
    }
void loop()
    {
    for (int pin = 5; pin <= 7; pin++)
        {digitalWrite(pin, HIGH);
        delay(delayTime);
        digitalWrite(pin, LOW);}
    
    }