// configurer le pwm qui se trouve a la patte 6 et 7 en fonction de les pattes 4 et 5
#include <Arduino.h>
#include "ESP32Servo.h"
//configuration des timer

#define BUTTON_PIN_1 4
#define BUTTON_PIN_2 6
#define BUTTON_PIN_3 13
#define PWM_PIN_1 7     //les pwm sont les trucs qui envoies les signals 
#define PWM_PIN_2 15
#define PWM_PIN_3 16

#define POT_PIN_1 5
#define POT_PIN_2 8
#define POT_PIN_3 12

#define Val_Max_POT 4095
#define Val_Min_POT 0
#define New_Max_POT 180
#define New_Min_POT 0
#define MAX_PWM 2010
#define MIN_PWM 990


Servo moteur1;
Servo moteur2;
Servo moteur3;

int POT_Val1 = 0;       //est la valeurs du potentiomètre
int POT_Val2 = 0;
int POT_Val3 = 0;
int INVERSE_POT_Val = 0;       //est la valeurs du potentiomètre

void setup () {
    Serial.begin(115200);
    pinMode(BUTTON_PIN_1, INPUT);
    pinMode(BUTTON_PIN_2, INPUT);
    pinMode(BUTTON_PIN_3, INPUT);
    moteur1.attach(PWM_PIN_1,MIN_PWM, MAX_PWM);
    moteur2.attach(PWM_PIN_2,MIN_PWM, MAX_PWM);
    moteur3.attach(PWM_PIN_3,MIN_PWM, MAX_PWM);
    
}

void loop () {
    POT_Val1 = analogRead(POT_PIN_1 );
    POT_Val1 = map(POT_Val1 , Val_Min_POT, Val_Max_POT, New_Min_POT, New_Max_POT); 
    INVERSE_POT_Val = map(POT_Val1 , Val_Min_POT, Val_Max_POT, New_Max_POT , New_Min_POT);     //va convertir la valeur du potentiomètre en valeurs numériques

    POT_Val2 = analogRead(POT_PIN_2 );
    POT_Val2 = map(POT_Val2 , Val_Min_POT, Val_Max_POT, New_Min_POT, New_Max_POT); 
 
    POT_Val3 = analogRead(POT_PIN_3 );
    POT_Val3 = map(POT_Val3 , Val_Min_POT, Val_Max_POT, New_Min_POT, New_Max_POT); 


    if(digitalRead(BUTTON_PIN_2)== LOW)   //lis si le bouton est appuyer
    {
        Serial.println ("moteur 2 ON     ");    //envoie vroom vroom
        
        moteur2.write(POT_Val2 );      //change la vitesse
    }
    else 
    {
//        Serial.println ("rien du tout");    //envoie un message temporaire
        moteur2.write(90);
    }


    if(digitalRead(BUTTON_PIN_1)== LOW)   //lis si le bouton est appuyer
    {
        Serial.println ("moteur 1 ON    ");    //envoie vroom vroom
//        moteur1.write(POT_Val1 );      //change la vitesse
        moteur1.write(INVERSE_POT_Val );     //change la vitesse
    }
    else 
    {
//        Serial.println ("rien du tout");    //envoie un message temporaire
        moteur1.write(90);
    }


    if(digitalRead(BUTTON_PIN_3)== LOW)   //lis si le bouton est appuyer
    {
        Serial.println ("moteur 3 ON    ");    //envoie vroom vroom
        
        moteur3.write(POT_Val3 );      //change la vitesse
    }
    else 
    {
//        Serial.println ("rien du tout");    //envoie un message temporaire
        moteur3.write(90);
    }


}