void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRB = B001111;
}

int dly = 5;
int del = 400;
int lspd = 2;
int rspd = 2;
int bast = 20;

void loop() {
  if (Serial.available() > 0) {
    num(Serial.read());
    Serial.print("xxx");
    delay(del );
  }
}

void num(int x) {
  switch (x) {
    case 1:
    case 49:
      step1(bast + 0, lspd);
      delay(del);
      step2(bast + 0, lspd);
      break;
    case 2:
    case 50:
      step1(bast + 6, lspd);
      delay(del);
      step2(bast + 6, rspd);
      break;
    case 3:
    case 51:
      step1(bast + 12, lspd);
      delay(del);
      step2(bast + 12, rspd);
      break;
    case 4:
    case 52:
      step1(bast + 18, lspd);
      delay(del);
      step2(bast + 18, rspd);
      break;
    case 5:
    case 53:
      step1(bast + 24, lspd);
      delay(del);
      step2(bast + 24, rspd);
      break;
    case 6:
    case 54:
      step1(bast + 30, lspd);
      delay(del);
      step2(bast + 30, rspd);
      break;
    case 7:
    case 55:
      step1(bast + 36, lspd);
      delay(del);
      step2(bast + 36, rspd);
      break;
    case 8:
    case 56:
      step1(bast + 42, lspd);
      delay(del);
      step2(bast + 42, rspd);
      break;
    case 9:
    case 57:
      step1(bast + 48, lspd);
      delay(del);
      step2(bast + 48, rspd);
      break;
    case 0:
    case 48:
      step1(bast + 54, lspd);
      delay(del);
      step2(bast + 54, rspd);
      break;
  }
}

void step2(int x, int spd) {
  for (int i = 0; i <= x; ++i) {
    PORTB = B0001;
    delay(spd);
    PORTB = B0010;
    delay(spd);
    PORTB = B0100;
    delay(spd);
    PORTB = B1000;
    delay(spd);
  }
}

void step1(int x, int spd) {
  for (int i = 0; i <= x; ++i) {
    PORTB = B1000;
    delay(spd);
    PORTB = B0100;
    delay(spd);
    PORTB = B0010;
    delay(spd);
    PORTB = B0001;
    delay(spd);
  }
}
