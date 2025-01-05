int sensor;
int vetPins [] {
  12,11,10,9,8,7,6,5,4,3
} ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 3; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  sensor = analogRead(A0);
  Serial.println(sensor);

  sensor = map(sensor, 0, 1023, 0, 10);

  Serial.println(sensor);

  for (int i = 0; i < sensor; i++) {
    digitalWrite(vetPins[i], HIGH);
  }
  for (int i = 10; i > sensor-1; i--) {
    digitalWrite(vetPins[i], LOW);
  }
  // put your main code here, to run repeatedly:
}
