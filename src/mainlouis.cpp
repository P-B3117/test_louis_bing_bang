// configurer le pwm qui se trouve a la patte 6 et 7 en fonction de les pattes 4 et 5
#include <Arduino.h>
#include "ESP32Servo.h"
#include <math.h>
//configuration des timer

#define BUTTON_PIN_1 4
#define BUTTON_PIN_2 6
#define BUTTON_PIN_3 13
#define PWM_PIN_1 7     //les pwm sont les trucs qui envoies les signals 
#define PWM_PIN_2 15
#define PWM_PIN_3 16

#define POT_PIN_1 5
#define POT_PIN_2 8
#define POT_PIN_3 3 

#define SWITCH_1 10
#define SWITCH_2 46 

#define Val_Max_POT_1 4095
#define Val_Max_POT_2 4095
#define Val_Max_POT_3 4095
#define Val_Min_POT 0
#define New_Max_POT 180
#define New_Min_POT 0
#define MAX_PWM 2010
#define MIN_PWM 990

#define STOP 90


Servo moteur1;
Servo moteur2;
Servo moteur3;

int POT_Val1 = 0;       //est la valeurs du potentiomètre
int POT_Val2 = 0;
int POT_Val3 = 0;

int map_Val1 = 0;       //est la valeurs du potentiomètre mappee
int map_Val2 = 0;
int map_Val3 = 0;

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

    if(digitalRead(SWITCH_1)==HIGH)     //sert à gérer la switch 
    {
        Serial.println ("SWITCH 1 ON");
    }

    if(digitalRead(SWITCH_2)==HIGH)
    {
        Serial.println ("SWITCH 2 ON");
    }
        
 
    if(digitalRead(BUTTON_PIN_1)== LOW)   //lis si le bouton est appuyer
    {
    POT_Val1 = analogRead(POT_PIN_1 );
    map_Val1 = map(POT_Val1 , Val_Min_POT, Val_Max_POT_1, New_Min_POT, New_Max_POT);    //va convertir la valeur du potentiomètre en valeurs numériques

    

    if(digitalRead(SWITCH_1)==LOW)     //sert à gérer la switch 
    {
        Serial.print ("moteur 1 ON     ");    //envoie vroom vroom
        Serial.print ((int)map_Val1);
        Serial.print ("   ");
        Serial.println ((int)POT_Val1);
        
        map_Val1 = ( pow( (map_Val1 / (float)180) , (float)2 ) ) * (float)180;
    }
    else
    {
        Serial.print ("moteur 1 ON     SWITCH 1 ON      ");    //envoie vroom vroom
        Serial.print ((int)map_Val1 /10);
        Serial.print ("   ");
        Serial.println ((int)POT_Val1 /10);

        map_Val1 = ( pow( (map_Val1 / (float)180) , (float)2 ) ) * (float)180;
    }

    moteur1.write(map_Val1);      //change la vitesse

    }
    else 
    {
//        Serial.println ("rien du tout");    //envoie un message temporaire
        moteur1.write(STOP);
    }

    if(digitalRead(BUTTON_PIN_2)== LOW)   //lis si le bouton est appuyer
    {

    POT_Val2 = analogRead(POT_PIN_2 );
    map_Val2 = map(POT_Val2 , Val_Min_POT, Val_Max_POT_2, New_Min_POT, New_Max_POT); 

        Serial.print ("moteur 2 ON     ");    //envoie vroom vroom
        Serial.print ((int)map_Val2);
        Serial.print ("   ");
        Serial.println ((int)POT_Val2);
        
    map_Val2 = ( pow( (map_Val2 / (float)180) , (float)2 ) ) * (float)180;

    moteur2.write(map_Val2);      //change la vitesse
    }
    else 
     {
//        Serial.println ("rien du tout");    //envoie un message temporaire
        moteur2.write(STOP);
    }


    if(digitalRead(BUTTON_PIN_3)== LOW)   //lis si le bouton est appuyer
    {
    POT_Val3 = analogRead(POT_PIN_2);
    map_Val3 = map(POT_Val3 , Val_Min_POT, Val_Max_POT_3, New_Min_POT, New_Max_POT); 

        Serial.print ("moteur 2 ON     ");    //envoie vroom vroom
        Serial.print ((int)map_Val3);
        Serial.print ("   ");
        Serial.println ((int)POT_Val3);

    map_Val3 = ( pow( (map_Val3 / (float)180) , (float)2 ) ) * (float)180;
        
    moteur3.write(map_Val3);      //change la vitesse
    }
    else 
    {
//        Serial.println ("rien du tout");    //envoie un message temporaire
        moteur3.write(STOP);
    }


}