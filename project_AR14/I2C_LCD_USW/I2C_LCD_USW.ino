//초음파센서로 거리 측정하여 I2C LCD로 출력하기
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd; //LCD 객체
int trig = 2;
int echo = 3;

void setup() {
  lcd.begin(16, 2); //LCD 통신 사용
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void loop() {
  float duration, distance;
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); //초음파 발사 후 돌아온 시간
  distance = ((float)(340 * duration) / 10000) / 2; //시간에 따른 cm 단위로 거리 계산

  lcd.clear (); //LCD 출력내용 지우기
  lcd.setCursor (0, 0); //LCD 내용 출력 위치 커서 설정 (첫번째줄, 왼쪽 첫번째 칸)
  lcd.print ("distance:");
  lcd.print (distance);
  lcd.print ("cm");
  lcd.setCursor(1, 1); //LCD 내용 출력 위치 커서 설정 (두번째줄, 왼쪽에서 두번째 칸)
  lcd.print("by CodingPeople");
  delay(200);
}
