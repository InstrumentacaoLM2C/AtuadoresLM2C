#include "../include/functions.h"
#include "../include/macros.h"
#include <AccelStepper.h>

AccelStepper* CriarMotor(int stepPin, int dirPin, int enablePin, int velocidadeMaxima, int aceleracao, int velocidade) {
    // Aloca dinamicamente um objeto AccelStepper
    AccelStepper* motor = new AccelStepper(AccelStepper::DRIVER, stepPin, dirPin);

    // Configura os pinos de ENABLE
    pinMode(enablePin, OUTPUT);
    digitalWrite(enablePin, LOW); // Habilita o motor

    // Configura o motor
    motor->setMaxSpeed(velocidadeMaxima);    // Velocidade máxima em passos por segundo
    motor->setAcceleration(aceleracao);      // Aceleração em passos por segundo ao quadrado
    motor->setSpeed(velocidade);             // Velocidade inicial em passos por segundo

    return motor; // Retorna o ponteiro para o motor criado
}

// Função para mover um motor
int moverMotor(AccelStepper* motor, long distancia) {
    if (!motor) { // Verifica se o ponteiro do motor é válido
        return ERROR_MOTOR_NAO_SELECIONADO;
    }
    motor->move(distancia); // Define a posição alvo
    while (motor->distanceToGo() != 0) { // Executa o movimento
        motor->run();
    }
    return OK;
}

// Função para desabilitar um motor
void desabilitarMotor(AccelStepper* motor, int enablePin) {
    if (motor) {
        digitalWrite(enablePin, HIGH); // Desabilita o motor
    }
}

