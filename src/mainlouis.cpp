// configurer le pwm qui se trouve a la patte 6 et 7 en fonction de les pattes 4 et 5
#include <Arduino.h>
#include "ESP32Servo.h"
//configuration des timer

#define BUTTON_PIN_1 4    
#define BUTTON_PIN_2 5

Servo feed;
Servo launch;

void setup () {
    Serial.begin(115200);
    pinMode(BUTTON_PIN_1, INPUT);
    pinMode(BUTTON_PIN_2, INPUT);
    feed.attach(6,1000,2000);
    launch.attach(7,1000,2000);
}

void loop () {
    //delay(75);
    if(digitalRead(BUTTON_PIN_2)== LOW)   //lis si le bouton est appuyer
    {
        Serial.println ("vroom, vroom");    //envoie vroom vroom
        launch.writeMicroseconds(1000);
        
    }
    else 
    {
        Serial.println ("rien du tout");    //envoie un message temporaire
        launch.writeMicroseconds(1500);
    }

    if(digitalRead(BUTTON_PIN_1)== LOW)   //lis si le bouton est appuyer
    {
        Serial.println ("vroom, vroom");    //envoie vroom vroom
        feed.writeMicroseconds(1000);
        
    }
    else 
    {
        Serial.println ("rien du tout");    //envoie un message temporaire
        feed.writeMicroseconds(1500);
    }

    //configuration PWM
    
//    Serial.println (DUTY_CYCLE); //envoie vroom

}