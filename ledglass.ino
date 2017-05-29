#include <FastLED.h>

#define LED_PIN     13
#define COLOR_ORDER GRB
#define CHIPSET     WS2812

#define MAXBRIGHTNESS   250

char string0[16] = "LUMIN  ";

int brilho = 30;
int velocidade = 40;

#include "effects.h"

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, LAST_VISIBLE_LED + 1);
  FastLED.setBrightness( scale8(brilho, MAXBRIGHTNESS) );
  Serial.begin(9600);
}

int effect = 1;

String leStringSerial(){
  String conteudo = "";
  char caractere;
  boolean effectBool = false;
  boolean effectVelocity = false;
  boolean effectMessage = false;
  boolean effectBrilho = false;
  
  while(Serial.available() > 0) {
    caractere = Serial.read();
    if (caractere == 'e') {
      effectBool = true;
      delay(10);
      continue;
    }
    else if (caractere == 'v') {
      effectVelocity = true;
      delay(10);
      continue;
    }
    else if (caractere == 'b') {
      effectBrilho = true;
      delay(10);
      continue;
    }
    else if (caractere == 'm') {
      effectMessage = true;
      delay(10);
      continue;
    }
    
    if (effectMessage == true) {
      if (caractere != '\n') {
        conteudo.concat(caractere);
      }
      delay(10);
      continue;
    }

    if (effectBrilho == true) {
      String cara;
      cara.concat(caractere);
      brilho = cara.toInt() * 20;
      delay(10);
      effectBrilho = false;
      continue;
    }

    if (effectBool == true) {
      if (caractere == '0') {
        effect = 0;
      }
      else if (caractere == '1'){
        effect = 1;
      }
      else if (caractere == '2'){
        effect = 2;
      }
      delay(10);
      effectBool = false;
      continue;
    }

    if (effectVelocity == true) {
      String cara;
      cara.concat(caractere);
      velocidade = cara.toInt() * 11;
      delay(10);
      effectVelocity = false;
      continue;
    }
    
  }  
  return conteudo;
}

void loop() {
  String recebido;
  if (Serial.available() > 0){
      recebido = leStringSerial();
      recebido.getBytes(string0, 16);
  }
  if (effect == 0)  {
    textEffectOne();
  }
  else if (effect == 1) {
    textEffectTwo();
  }
  else if (effect == 2) {
    textEffectThree();
  }
  FastLED.setBrightness( scale8(brilho, MAXBRIGHTNESS) );
  //confirmBlink();
  FastLED.show();
  delay(velocidade);
}

