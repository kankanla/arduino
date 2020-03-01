/*
   マイクロ波レーダーセンサーRCWL-0516スイッチモジュールヒューマンインダクションボード検出器 検出距離 5-7m
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
}

void loop() {
  //  digitalWrite(A1, 1);
  // put your main code here, to run repeatedly:
  int i;
  unsigned long  cont = millis();
  while (1) {
    delay(1000);
    i = analogRead(A0);
    if (i > 300) {
      digitalWrite(A1, 1);
      Serial.println("ON");
      cont = millis();
    } else {
      // 一定の時間(5分)以内人体の移動が感知がなければ，OFFにする
      if ((millis() - cont) > (1000l * 300l)) {
        digitalWrite(A1, 0);
        Serial.println("OFF");
        Serial.println("<0");
      }
    }
  }

}
