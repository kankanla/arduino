/*
   shiftOut のテストと赤色7セグメントLED表示器のテスト
*/

uint8_t resetPin  = A0;  //P10 SRCLR/RESET (常にH可)
uint8_t clockPin  = A1;  //P11 SRCLK/SHIFT CLOCK(クロックを出力するピン)
uint8_t latchPin  = A2;  //P12 RCLK/LATCH CLOCK(LOW->HIGH で更新)
uint8_t oePin     = A3;  //P13 OE/OUTPUT ENABLE (出力有効/無効,常にH可)
uint8_t dataPin   = A4;  //P14 SER/A (ビットを出力するピン)

void setup() {
  Serial.begin(9600);
  pinMode(resetPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(oePin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  Number();
  //  led1();
  //  led2();
  //  led3();
  //  led4();
}

void Number() {
  /*
    赤色7セグメントLED表示器LTS-547BJR-01J
     0から9までの数字のバタン
     ピンの配置
        A
       F B
        G
       E C
        D  dp
  */
  byte n2[] = {
    0b00111111,   //0
    0b00000110,   //1
    0b01011011,   //2
    0b01001111,   //3
    0b01100110,   //4
    0b01101101,   //5
    0b01111101,   //6
    0b00100111,   //7
    0b01111111,   //8
    0b01101111    //9
  };

  byte n[] = {
    0b00000001,   //A
    0b00000010,   //B
    0b00000100,   //C
    0b00001000,   //D
    0b00010000,   //E
    0b00100000,   //F
    0b01000000,   //G
    0b10000000,   //dp
  };

  digitalWrite(resetPin, 1);
  for (uint8_t i = 0; i < sizeof(n); i++) {
    Serial.println(n[i], DEC);
    Serial.println(i);
    shiftOut(dataPin, clockPin, MSBFIRST, n[i]);
    digitalWrite(latchPin, 0);
    digitalWrite(latchPin, 1);
    delay(200);
  }
}

int b = 0b00000001;
void led1() {
  /*
     oePin 有効/無効によりLチカ
  */
  shiftOut(dataPin, clockPin, LSBFIRST, b);
  digitalWrite(latchPin, 0);
  digitalWrite(latchPin, 1);
  for (int i = 0; i < 8 ; i++) {
    digitalWrite(oePin, 1);
    delay(200);
    digitalWrite(oePin, 0);
    delay(200);
  }
}

void led2() {
  /*
     8bit 以上の送信テスト
  */
  int randNumber = random(255, 345690);
  Serial.println(randNumber);
  Serial.println(randNumber, BIN);
  digitalWrite(resetPin, 1);
  shiftOut(dataPin, clockPin, MSBFIRST, randNumber);
  digitalWrite(latchPin, 0);
  digitalWrite(latchPin, 1);
  delay(2000);
}

void led3() {
  /*
     8bit 内の送信テスト
  */
  uint8_t randNumber = random(0, 255);
  Serial.println(randNumber);
  Serial.println(randNumber, BIN);
  digitalWrite(resetPin, 1);
  shiftOut(dataPin, clockPin, MSBFIRST, randNumber);
  digitalWrite(latchPin, 0);
  digitalWrite(latchPin, 1);
  delay(2000);
}

void led4() {
  /*
     LEDの順番表示
  */
  byte b = 0;
  digitalWrite(resetPin, 1);
  digitalWrite(oePin, 0);
  for (uint8_t i = 0; i < 255; i++) {
    Serial.println(i, BIN);
    shiftOut(dataPin, clockPin, MSBFIRST, i);
    digitalWrite(latchPin, 0);
    digitalWrite(latchPin, 1);
    digitalWrite(resetPin, 1);
    delay(100);
  }
}
