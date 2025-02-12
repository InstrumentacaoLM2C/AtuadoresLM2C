#include <Arduino.h>

// Defina os pinos de controle do primeiro motor
#define STEP_PIN_1 PA8  // Pino de passo (STEP) do Motor 1
#define DIR_PIN_1 PA9   // Pino de direção (DIR) do Motor 1
#define ENABLE_PIN_1 PA10  // Pino de ENABLE do Motor 1

// Defina os pinos de controle do segundo motor
#define STEP_PIN_2 PA11  // Pino de passo (STEP) do Motor 2
#define DIR_PIN_2 PA12   // Pino de direção (DIR) do Motor 2
#define ENABLE_PIN_2 PA13  // Pino de ENABLE do Motor 2

#define OK                                  0
#define ERROR_MOTOR_NAO_SELECIONADO         1

// Inicialize os motores com a interface "DRIVER" (STEP/DIR)
AccelStepper motor1(AccelStepper::DRIVER, STEP_PIN_1, DIR_PIN_1);
AccelStepper motor2(AccelStepper::DRIVER, STEP_PIN_2, DIR_PIN_2);

void setup() {
  // Configura os pinos de ENABLE como saída
  pinMode(ENABLE_PIN_1, OUTPUT);
  pinMode(ENABLE_PIN_2, OUTPUT);

  // Desabilita os motores inicialmente (ENABLE em HIGH)
  digitalWrite(ENABLE_PIN_1, HIGH);
  digitalWrite(ENABLE_PIN_2, HIGH);

   // Configurações iniciais para o Motor 1
  
  
}

void loop() {
  // Habilita os motores (ENABLE em LOW)
  digitalWrite(ENABLE_PIN_1, LOW);
  digitalWrite(ENABLE_PIN_2, LOW);

  // Move ambos os motores no sentido horário
  int MoverMotor (char numeroMotor);
  
  MoverMotor (numeroMotor){
    if !numeroMotor{  
      return ERROR_MOTOR_NAO_SELECIONADO;
    }
    numeroMotor.move(distanciaMotor);
  }
 
  motor2.move(1000);  // Define a posição alvo para o Motor 2

  // Executa o movimento até que ambos os motores atinjam a posição
  while (motor1.distanceToGo() != 0 || motor2.distanceToGo() != 0) {
    motor1.run();
    motor2.run();
  }

  delay(1000);  // Aguarda 1 segundo

  // Move ambos os motores 1000 passos no sentido anti-horário
  motor1.move(-1000);  // Define a posição alvo para o Motor 1
  motor2.move(-1000);  // Define a posição alvo para o Motor 2

  // Executa o movimento até que ambos os motores atinjam a posição
  while (motor1.distanceToGo() != 0 || motor2.distanceToGo() != 0) {
    motor1.run();
    motor2.run();
  }

  delay(1000);  // Aguarda 1 segundo
  
  // Desabilita os motores (ENABLE em HIGH)
  digitalWrite(ENABLE_PIN_1, HIGH);
  digitalWrite(ENABLE_PIN_2, HIGH);

  delay(1000);  // Aguarda 1 segundo antes de reiniciar o ciclo
}