int led1 = 8;   //initialize variable for LED pin
int unit = 120;  //delay time for morse code

void setup() {
  pinMode(led1, OUTPUT);  //initialize LED pin for output
}

void dot() {
  digitalWrite(led1, HIGH);
  delay(unit);
  digitalWrite(led1, LOW);
  delay(unit);
}

void dash() {
  digitalWrite(led1, HIGH);
  delay(unit * 3);
  digitalWrite(led1, LOW);
  delay(unit);
}

void loop() {
  dot();
  dot();
  dot();
  delay(unit * 3);  
  dash();
  dash();
  dash();
  delay(unit * 3);  
  dot();
  dot();
  dot();     
  delay(unit * 7);  
}