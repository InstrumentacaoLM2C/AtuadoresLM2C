#include <Arduino.h>
#include "functions.h"
#include "macros.h"
#include <AccelStepper.h>

//Declaração de variáveis para motores
AccelStepper* motor1 = nullptr;
AccelStepper* motor2 = nullptr;

//Declaração de variáveis para paramêtros do motor
int velocidadeMaxima, aceleracaoMaxima, velocidade;

void setup() {
  // Configura os pinos de ENABLE como saída
  pinMode(PIN_ENABLE_1, OUTPUT);
  pinMode(PIN_ENABLE_2, OUTPUT);

  // Desabilita os motores inicialmente (ENABLE em HIGH)
  digitalWrite(PIN_ENABLE_1, HIGH);
  digitalWrite(PIN_ENABLE_2, HIGH);

  //Configuração de velocidade e aceleração
  velocidadeMaxima = 8000;
  aceleracaoMaxima = 200;
  velocidade = 1000;

   // Configurações iniciais para o Motor 1
  motor1 = CriarMotor(PIN_PASSO_1, PIN_DIR_1, PIN_ENABLE_1, velocidadeMaxima, aceleracaoMaxima, velocidade);
  motor2 = CriarMotor(PIN_PASSO_2, PIN_DIR_2, PIN_ENABLE_2, velocidadeMaxima, aceleracaoMaxima, velocidade);
}

void loop() {

  //Chamada de funções
  VerificarSerial();

  /* // Habilita os motores (ENABLE em LOW)
  digitalWrite(PIN_ENABLE_1, LOW);
  digitalWrite(PIN_ENABLE_2, LOW);

  // Move motor
  int MoverMotor (char numeroMotor);
  
  MoverMotor (motor, distancia){
    if (!motor){  
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
*/
}