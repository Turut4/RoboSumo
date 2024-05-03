#include <Ultrasonic.h>
#include <L298NX2.h>



#define ENA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENB 5
L298NX2 motores(ENA, IN1, IN2, ENB, IN3, IN4);


#define trigPin 12
#define echoPin 13
Ultrasonic ultrasonic(trigPin, echoPin, 40000UL);

#define IR_frente 3
#define IR_traseiro 2
int distancia_ataque = 30;
int sensor_frente, sensor_traseiro;



int velocidade_padrao = 180;
int velocidade_ataque = 255;



void setup(){
  Serial.begin(9600);
  pinMode(IR_frente, INPUT);
  pinMode(IR_traseiro, INPUT);
  motores.setSpeed(velocidade_padrao);
 
}

void loop(){
  int distancia = ultrasonic.read(CM);
  sensor_frente = digitalRead(IR_frente);
  sensor_traseiro = digitalRead(IR_traseiro);
  Serial.println(distancia);

  if(sensor_frente == 0 && sensor_traseiro == 0){
      motores.setSpeed(velocidade_ataque);
      motores.backward();
  

<<<<<<< HEAD
      delay(2000);
    }else if(distancia > distancia_ataque){
=======
      delay(500);
    }else{
>>>>>>> 0bd2f9f9986dbdb96d4319fc1a545bb064f38b26
      if(random(1,3) == 1){
        motores.setSpeed(velocidade_padrao);
        motores.backwardB();
        motores.forwardA();

        delay(300);  
      }else{
        motores.setSpeed(velocidade_padrao);
        motores.forwardB();
        motores.backwardA();
        delay(300);
      }

    }
    
  }

  if(sensor_frente == 0 && sensor_traseiro == 1){
    motores.setSpeed(velocidade_padrao);
    motores.backward();
    delay(500);
  }
  
  if(sensor_frente == 1 && sensor_traseiro == 0){
    motores.setSpeed(velocidade_padrao);
    motores.forward();
    delay(500);
  }

}