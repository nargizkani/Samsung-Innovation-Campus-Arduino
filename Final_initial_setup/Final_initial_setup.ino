#include <Servo.h>
Servo myservo1;  // Создание четырех объектов Servo для управления двигателями
Servo myservo2;
Servo myservo3;
Servo myservo4;
int pos1=90, pos2=70, pos3=120, pos4=0, d=10; // исходное положение для двигателей и задержка для управления скоростью

void setup()
{
  // указание номеров портов, к котороым подключены двигатели: A1, A0, 6, 9
  myservo1.attach(A1);  // база
  myservo2.attach(A0);  // рейка смещения по горизонтали
  myservo3.attach(6);   // рейка смещения по вертикали
  myservo4.attach(9);   // клешня
  
  myservo1.write(pos1);  // установка исходных положений для двигателей
  myservo4.write(pos4);
  delay(1000);
  myservo2.write(pos2);
  myservo3.write(pos3);
  delay(1500);
}

void loop() 
{
  // повернуть направо
  for(pos1;pos1>10;pos1--)
  {
    myservo1.write(pos1);
    delay(d);
  }
  delay(1000);
  
  // повернуть налево
  for(pos1;pos1<170;pos1++)
  {
    myservo1.write(pos1);
    delay(d);
  }
  delay(1000);
  
  // установить по центру
  for(pos1;pos1>90;pos1--)
  {
    myservo1.write(pos1);
    delay(d);
  }
  delay(1000);

  // смещения по горизонтали
  for(pos2;pos2<120;pos2++)
  {
    myservo2.write(pos2);
    delay(d);
  }
  delay(1000);
  
  for(pos2;pos2>40;pos2--)
  {
    myservo2.write(pos2);
    delay(d);
  }
  delay(1000);
  for(pos2;pos2<70;pos2++)
  {
    myservo2.write(pos2);
    delay(d);
  }
  delay(1000);
  
  
  
  // смещния по вертикали
  for(pos3;pos3<170;pos3++)
  {
    myservo3.write(pos3);
    delay(d);
  }
  delay(1000);
  
  for(pos3;pos3>100;pos3--)
  {
    myservo3.write(pos3);
    delay(d);
  }
  delay(1000);
  
  for(pos3;pos3<120;pos3++)
  {
    myservo3.write(pos3);
    delay(d);
  }
  delay(1000);
  
  // раскрыть клешню
  for(pos4;pos4<20;pos4++)
  {
    myservo4.write(pos4);
    delay(d);
  }
  delay(1000);
  
  // схватить
  for(pos4;pos4>0;pos4--)
  {
    myservo4.write(pos4);
    delay(d);
  }
  delay(1000);
}
