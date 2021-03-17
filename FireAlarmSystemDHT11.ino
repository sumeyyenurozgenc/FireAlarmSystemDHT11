#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
const int ledPin = 13;
const int buzzerPin=9;

int Do = 262;
int Re = 294;
int Mi = 330;
int Fa = 349;
int Sol = 392;
int La = 440;
int Si = 494;
int Thin_Do = 523;
int music[] = {Do,Re,Mi,Fa,Sol,La,Si,Thin_Do};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
 int temperature=dht.readTemperature();
 if(temperature>15)
 {
  digitalWrite(ledPin, HIGH);  
  digitalWrite(buzzerPin, HIGH);
  for (int i = 0; i < sizeof(music)/sizeof(int); i++)
  {
    tone(buzzerPin, music[i]);
    delay(500);
    noTone(buzzerPin);
    delay(100);
  }
 }
 noTone(buzzerPin);
}
