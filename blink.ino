void setup() {
  // put your setup code here, to run once:
  
  // designate pin 13 as an OUTPUT pin for the LED
  pinMode (13, OUTPUT);

  // designate pin A0 as an Analog INPUT for the potentiometer
  pinMode (A0, INPUT);

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println  (A0);

  int potValue = analogRead (A0);

  digitalWrite (13, HIGH);

  delay (potValue);

  digitalWrite (13, LOW);

  delay (potValue);
}
