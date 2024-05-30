
//правое заднее   f12    r9
//левое переднее   f4    r7
//левое заднее   f6    r5
#define PIN_IN3 23
#define PIN_IN4 25

#define rff 11
#define rfr 10
#define rrf 12
#define rrr 9
#define lff 7
#define lfr 4
#define lrf 6
#define lrr 5
#include "FlySkyIBus.h"



int x = 0;
int y = 0;
int z =0;
int pith =0;
int c = 0;
int r = 0;
int l = 0;

int manip = 0;
bool flag = false;
bool move_manip = false;


void setup()
{
  Serial.begin(115200);//для обмена данными с малиной
  
  IBus.begin(Serial2);
  for (int i = 4; i < 14; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, 0);
  }
  
  pinMode(22,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);
  digitalWrite(22,0);
  digitalWrite(24,0);
  digitalWrite(26,0);
  digitalWrite(28,0);

  pinMode(PIN_IN3,OUTPUT);
  pinMode(PIN_IN4,OUTPUT);
  
  delay(2000);
}

void loop()
{
  IBus.loop();
  x = IBus.readChannel(0); //возможно надо добавить аргумент HEX как в оригинале
  y = IBus.readChannel(1);
  
  //тут не знаю какой канал будет отвечать, сами посмотрите
  z = IBus.readChannel(2);
  
  //должна еще быть переменная pith но я не помню для чего она
  pith = IBus.readChannel(3); //3 для примера

  
  
  manip = IBus.readChannel(6);
 
   
  x = map(x, 1000, 2000, -255, 255);
  y = map(y, 1000, 2000, -255, 255);
  z = map(y, 1000, 2000, -255, 255);
    pith = map(y, 1000, 2000, -255, 255);

  
  manip = map(manip, 1000, 2000, -1, 1);
  

 //определяем где сейчас тумблер. Если при включении пульта тумблер был вверху, то его все равно надо перевести в центральное положение а затем в верхнее для начала управления манипулятором.
  if (manip == 0){ //тумблер посередине, идет управление машинкой
    

    flag = true;
    move_manip =false;
    
    
  }else if ((manip == -1) && (flag == true)){ //тумблер вверху
    
   flag=false;
    move_manip=true;
  } 



if (move_manip){ //если тумблер вверху по полученные значения координат x y z будем передавать на малину, иначе условие перейдет в блок управления машинкой
 String data = String(x + ":" + y +":" +z + ":" + pith + ":" + 400); //последняя переменная отвечает за вращение конечности, но добавьте ее как оси z x y
  Serial.print(data);

} else{


  if ((x < 50) && (x > -50)) {
    x = 0;
  }
  if (x > 150) {
    x = 255;
  }
  if (x < -150) {
    x = -255;
  }


  if ((y < 50) && (y > -50)) {
    y = 0; 
  }
  if (y > 150) {
    y = 255;
  }
  if (y < -150) {
    y = -255;
  }

  
  l = x + y;
  r = y - x;


  if ((r < 50) && (r > -50)) {
    r = 0;
  }
  if (r > 150) {
    r = 255;
  }
  if (r < -150) {
    r = -255;
  }
  if ((l < 50) && (l > -50)) {
    l = 0;
  }
  if (l > 150) {
    l = 255;
  }
  if (l < -150) {
    l = -255;
  }
  if(l>0){
    digitalWrite(lfr,0);
    digitalWrite(lrr,0);
    analogWrite(lff,l);
    analogWrite(lrf,l);
  } else{
    digitalWrite(lff,0);
    digitalWrite(lrf,0);
    analogWrite(lfr,-l);
    analogWrite(lrr,-l);
  }
  if(l==0){
    digitalWrite(lff,0);
    digitalWrite(lrf,0);
    digitalWrite(lfr,0);
    digitalWrite(lrr,0);
  }

    if(r>0){
    digitalWrite(rfr,0);
    digitalWrite(rrr,0);
    analogWrite(rff,r);
    analogWrite(rrf,r);
  } else{
    digitalWrite(rff,0);
    digitalWrite(rrf,0);
    analogWrite(rfr,-r);
    analogWrite(rrr,-r);
  }
  if(r==0){
    digitalWrite(rff,0);
    digitalWrite(rrf,0);
    digitalWrite(rfr,0);
    digitalWrite(rrr,0);
  }
  
  
//  Serial.print("  x=");
//  Serial.print(x);
//  Serial.print("  y=");
//  Serial.print(y);
//  Serial.print("  b=");
//  Serial.print(b);
//  Serial.println();
//  delay(300);

} }
