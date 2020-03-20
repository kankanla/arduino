//Happy Birthday to You

const unsigned char SPPIN = A5;
int Piano[20];

unsigned char xx[] = {50, 50, 6, 5, 11, 7, 0,
                      50, 50, 6, 5, 12, 11, 0,
                      50, 50, 15, 13, 11, 7, 6,
                      14, 140, 13, 11, 12, 11, 0
                     };

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
  Piano[11] = 523.251; //C5
  Piano[12] = 587.330; //D5
  Piano[13] = 659.255; //E5
  Piano[14] = 698.456; //F5
  Piano[15] = 783.991; //G5
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("a");
  music();
  music();
  Serial.println("b");
  while (1) {
    noTone(A0);
  }
}

void music() {
  for (unsigned char i = 0; i < sizeof(xx); i++) {
    if (xx[i] == 50 || xx[i] == 40 || xx[i] == 140) {
      PianoS((xx[i] / 10), 300);
    } else {
      PianoS(xx[i], 600);
    }
  }
}

void PianoS(unsigned char x, int tempo) {
  tone(SPPIN, Piano[x]);
  delay(tempo);
  noTone(SPPIN);
  delay(0);
  return;
}
