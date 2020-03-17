//Happy Birthday to You

const unsigned char SPPIN = A0;
const unsigned char tempo = 1200;
float Piano[10];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Piano[0] = 0; //C4
  Piano[1] = 261.626; //C4
  Piano[2] = 293.665; //D4
  Piano[3] = 329.628; //E4
  Piano[4] = 349.228; //F4
  Piano[5] = 391.995; //G4
  Piano[6] = 440.000; //A4
  Piano[7] = 493.883; //B5
  Piano[8] = 523.251; //C5
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char xx[] = {1, 5, 5, 2, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 1, 5, 5, 2, 5};
  for (unsigned char i = 0; i < sizeof(xx); i++) {
    PianoS(xx[i]);
    Serial.print(xx[i]);
  }
  while (1) {

  }
}

void PianoS(unsigned char x) {
  tone(A0, Piano[x], tempo);
  delay(tempo);
}
