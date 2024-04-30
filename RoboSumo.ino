#include <L298NX2.h>
#include <Ultrasonic.h>


#define ENA 10
#define IN1 9
#define IN2 8
#define IN3 5
#define IN4 6
#define ENB 5
L298NX2 motores(ENA, IN1, IN2, ENB, IN3, IN4);



#define trigPin 12
#define echoPin 11
Ultrasonic ultrasonic(trigPin, echoPin);

#define IR_frente 3
#define IR_traseiro 2
int distancia_ataque = 20;
int sensor_frente, sensor_traseiro;


int velocidade_padrao = 180, velocidade_ataque = 255;


void setup(){
  
  pinMode(sensor_frente, INPUT);
  pinMode(sensor_traseiro, INPUT);
  motores.setSpeed(velocidade_padrao);
 


}

void loop(){
  int distancia = ultrasonic.read(CM);
  sensor_frente = digitalRead(IR_frente);
  sensor_traseiro = digitalRead(IR_traseiro);

  if(sensor_frente == 0 && sensor_traseiro == 0){
    while(distancia>distancia_ataque){
      if(random(1,3) == 1){
        motores.setSpeed(velocidade_padrao);
        motores.backwardA();
        motores.forwardB();
        delay(300);
      }else{
        motores.setSpeed(velocidade_padrao);
        motores.forwardA();
        motores.backwardB();
        delay(300);
      }

    }
    motores.setSpeed(velocidade_ataque);
    motores.forward();
    delay(500);
  }

  if(sensor_frente == 1 && sensor_traseiro == 0){
    motores.setSpeed(velocidade_ataque);
    motores.backward();
    delay(400);
  }
  
  if(sensor_frente == 0 && sensor_traseiro == 1){
    motores.setSpeed(velocidade_ataque);
    motores.forward();
    delay(400);
  }

}