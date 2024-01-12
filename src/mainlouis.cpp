// configurer le pwm qui se trouve a la patte 6 et 7 en fonction de les pattes 4 et 5
#include <Arduino.h>
#include "ESP32Servo.h"
//configuration des timer

#define BUTTON_PIN_1 4    
#define BUTTON_PIN_2 5
#define PWM_PIN_1 6
#define PWM_PIN_2 7
#define POT_PIN_1 11

#define Val_Max_POT 4095
#define Val_Min_POT 0
#define New_Max_POT 180
#define New_Min_POT 0

Servo feed;
Servo launch;

int POT_Val = 0;       //est la valeurs du potentiomètre

void setup () {
    Serial.begin(115200);
    pinMode(BUTTON_PIN_1, INPUT);
    pinMode(BUTTON_PIN_2, INPUT);
    feed.attach(PWM_PIN_1,1000,2000);
    launch.attach(PWM_PIN_2,1000,2000);
    
}

void loop () {
    POT_Val = analogRead(POT_PIN_1);
    POT_Val = map(POT_Val , Val_Min_POT, Val_Max_POT, New_Min_POT, New_Max_POT);     //va convertir la valeur du potentiomètre en valeurs numériques
    Serial.println(POT_Val );    //devrait lire la valeur du potentiomètre

    if(digitalRead(BUTTON_PIN_2)== LOW)   //lis si le bouton est appuyer
    {
        Serial.println ("Avance roue avant");    //envoie vroom vroom
        launch.writeMicroseconds(1000);
        
        launch.write(POT_Val );      //change la vitesse
    }
    else 
    {
        Serial.println ("rien du tout");    //envoie un message temporaire
        launch.writeMicroseconds(1500);
    }

    if(digitalRead(BUTTON_PIN_1)== LOW)   //lis si le bouton est appuyer
    {
        Serial.println ("Avance roue arrière");    //envoie vroom vroom
        feed.writeMicroseconds(1000);
        
        launch.write(POT_Val );      //change la vitesse
    }
    else 
    {
        Serial.println ("rien du tout");    //envoie un message temporaire
        feed.writeMicroseconds(1500);
    }


}