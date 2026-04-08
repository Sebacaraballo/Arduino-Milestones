// initialize variables for pins
int led1 = 8;
int trig1 = 12;
int echo1 = 13;
int unit = 120;  //delay time for morse code

// initialize variables for calculating distance
float duration = 0;
float distance = 0;

void setup() {
  // to see the data on Serial Monitor
  Serial.begin(9600);
  
  // pinMode for each pin
  pinMode(led1, OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

}

void getDistance(){
  // send ultrasonic wave using trig pin
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig1, LOW);

  // read wave using echo pin
  duration = pulseIn(echo1, HIGH);

  // calculate distance in cm
  distance = duration * 0.034 / 2;
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
  // put your main code here, to run repeatedly:
  getDistance(); //units = cm
  Serial.print("Distance: ");
  Serial.println(distance);
  
 if (distance < 10) {
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

 if (distance > 30) {
  digitalWrite(led1, LOW);
 }

 if (distance < 30 && distance > 10) {
    digitalWrite (led1, HIGH);
    delay(unit * 10);
  }
}
