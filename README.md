# RoboSumo

RoboSumo is a simple sumo robot built using an Arduino. It uses ultrasonic and infrared sensors to detect opponents and the edges of the sumo ring, respectively, and controls its movements with an L298N motor driver.

## Features

- **Ultrasonic Sensor**: Detects the distance to the opponent.
- **Infrared Sensors**: Detects the edges of the sumo ring to prevent falling out.
- **Motor Control**: Controls the robot's movement using an L298N motor driver.

## Components

- Arduino
- L298N Motor Driver
- Ultrasonic Sensor (HC-SR04)
- Infrared Sensors
- DC Motors
- Wheels
- Power Supply

## Circuit Diagram

![Circuit Diagram](circuit_diagram.png)  // to be add yet

## Code Explanation

The code is divided into the following sections:

1. **Libraries and Pin Definitions**: Includes necessary libraries and defines pins for sensors and motors.
2. **Motor and Sensor Setup**: Initializes the motor driver and sensors.
3. **Main Loop**: Contains the logic for robot movement based on sensor readings.

### Libraries

- `Ultrasonic.h`: For ultrasonic distance measurement.
- `L298NX2.h`: For controlling the L298N motor driver.

### Pin Definitions

```cpp
#define ENA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENB 5

#define trigPin 12
#define echoPin 13

#define IR_frente 3
#define IR_traseiro 2
```

### Initialization

```cpp
L298NX2 motores(ENA, IN1, IN2, ENB, IN3, IN4);
Ultrasonic ultrasonic(trigPin, echoPin, 40000UL);

void setup(){
  Serial.begin(9600);
  pinMode(IR_frente, INPUT);
  pinMode(IR_traseiro, INPUT);
  motores.setSpeed(velocidade_padrao);
}
```

### Main Logic

The main loop reads sensor values and controls the motors accordingly:

- **Normal Operation**: Moves forward or backward based on the infrared sensor readings.
- **Attack Mode**: If the opponent is detected within a specified distance, it moves towards the opponent at full speed.
- **Edge Detection**: If an edge is detected by the IR sensors, it changes direction to avoid falling out of the ring.

```cpp
void loop(){
  int distancia = ultrasonic.read(CM);
  sensor_frente = digitalRead(IR_frente);
  sensor_traseiro = digitalRead(IR_traseiro);
  Serial.println(distancia); //print distancia no terminal

  if(sensor_frente == 0 && sensor_traseiro == 0){
      motores.setSpeed(velocidade_ataque);
      motores.backward();
      delay(2000);
  } else if(distancia > distancia_ataque){
      if(random(1,3) == 1){
        motores.setSpeed(velocidade_padrao);
        motores.backwardB();
        motores.forwardA();
        delay(300);  
      } else {
        motores.setSpeed(velocidade_padrao);
        motores.forwardB();
        motores.backwardA();
        delay(300);
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
```

## How to Run

1. **Assemble the Circuit**: Connect the components according to the circuit diagram.
2. **Upload the Code**: Use the Arduino IDE to upload the provided code to your Arduino.
3. **Power the Robot**: Provide power to the robot and place it in the sumo ring.
4. **Observe the Behavior**: The robot will start moving and reacting based on the sensor inputs.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contributing

Feel free to open issues or submit pull requests for any improvements or bug fixes.

## Acknowledgements

- [Arduino](https://www.arduino.cc/)
- [HC-SR04 Ultrasonic Sensor](https://www.electronicwings.com/sensors-modules/hc-sr04-ultrasonic-sensor)
- [L298N Motor Driver](https://www.electronicwings.com/arduino/l298n-motor-driver-module)
