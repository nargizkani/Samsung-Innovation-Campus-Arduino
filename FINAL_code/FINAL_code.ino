#include<Wire.h>                //библиотека для работы с I2C 
#include<Servo.h>               //библиотека для работы с сервомоторами
#include "Wire.h"               //библиотека для работы с I2C 
#include "I2Cdev.h"             //библиотека для работы с I2C 
#include "MPU6050.h" 
Servo servo_1;      
Servo servo_2;
Servo servo_3;
Servo servo_4;
MPU6050 mpu; 
int16_t ax, ay, az; 
int16_t gx, gy, gz; 
int gripper;
int flex_Pin = A0;
 
void setup()
{
  Serial.begin(9600);
  Wire.begin(); 
  Serial.println("Initialize MPU"); 
  mpu.initialize(); 
  Serial.println(mpu.testConnection() ? "Connected" : "Connection failed"); 

  
  servo_1.attach(2);   // вперед/назад
  servo_2.attach(3);   // вверх/вниз
  servo_3.attach(4);   // захват руки
  servo_4.attach(5);   // влево/вправо
  pinMode(flex_Pin, INPUT);
  
}
void loop()
{
  int flex_sensorip = analogRead(flex_Pin);      //считываем показания с гибкого датчика
  if(flex_sensorip < 750){
    gripper = 180;
  }
  else{
    gripper = 0;
  }
  servo_3.write(gripper);                    //передаем значение захвата на 3-й сервомотор
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
  Serial.print("\t");
  Serial.print("ax=  ");
  Serial.println(ax);
 
  Serial.print("\t");
  Serial.print("ay=  ");
  Serial.print(ay);

  
  Serial.print("\t");
  Serial.print("az=  ");
  Serial.print(az);


  Serial.print("\t");
  Serial.print("gx=  ");
  Serial.print(gx);
  
  Serial.print("\t");
  Serial.print("gy=  ");
  Serial.print(gy);


  Serial.print("\t");
  Serial.print("gz=  ");
  Serial.print(gz);
  Serial.println();
  servo_1.write(map(ax, -17000, 17000, 0, 179));  
  servo_2.write(map(az, -17000, 17000, 0, 200));  
  servo_4.write(map(ay, -17000, 17000, 0, 179));  
  delay(10);
}
