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
#define MAX_PWM 2010
#define MIN_PWM 990


Servo feed;
Servo launch;

int POT_Val = 0;       //est la valeurs du potentiomètre
int INVERSE_POT_Val = 0;       //est la valeurs du potentiomètre

void setup () {
    Serial.begin(115200);
    pinMode(BUTTON_PIN_1, INPUT);
    pinMode(BUTTON_PIN_2, INPUT);
    feed.attach(PWM_PIN_1,MIN_PWM, MAX_PWM);
    launch.attach(PWM_PIN_2,MIN_PWM, MAX_PWM);
    
}

void loop () {
    POT_Val = analogRead(POT_PIN_1);
    POT_Val = map(POT_Val , Val_Min_POT, Val_Max_POT, New_Min_POT, New_Max_POT); 
    INVERSE_POT_Val = map(POT_Val , Val_Min_POT, Val_Max_POT, New_Max_POT , New_Min_POT);     //va convertir la valeur du potentiomètre en valeurs numériques

    if(digitalRead(BUTTON_PIN_2)== LOW)   //lis si le bouton est appuyer
    {
        Serial.println ("Avance roue avant");    //envoie vroom vroom
        
        launch.write(POT_Val );      //change la vitesse
    }
    else 
    {
        Serial.println ("rien du tout");    //envoie un message temporaire
        launch.write(90);
    }

    if(digitalRead(BUTTON_PIN_1)== LOW)   //lis si le bouton est appuyer
    {
        Serial.println ("Avance roue arrière");    //envoie vroom vroom
        feed.write(INVERSE_POT_Val );     //change la vitesse
    }
    else 
    {
        Serial.println ("rien du tout");    //envoie un message temporaire
        feed.write(90);
    }


}