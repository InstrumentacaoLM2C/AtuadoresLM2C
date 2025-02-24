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

void moverAcelerado(AccelStepper* motor, int velocidadeMaxima, long distancia) {
    if (!motor) { // Verifica se o ponteiro do motor é válido
        return; // Retorna sem fazer nada se o ponteiro for inválido
    }

    // Configura a aceleração e a velocidade máxima do motor
    motor->setAcceleration(1000); // Define a aceleração em passos por segundo ao quadrado
    motor->setMaxSpeed(velocidadeMaxima); // Define a velocidade máxima em passos por segundo

    // Define a posição alvo
    motor->move(distancia);

    // Executa o movimento até que o motor alcance a posição desejada
    while (motor->distanceToGo() != 0) {
        motor->run();
    }
}



void moverUniforme(AccelStepper* motor, int velocidadeMaxima, long distancia){
    if (!motor) { // Verifica se o ponteiro do motor é válido
        return; // Retorna sem fazer nada se o ponteiro for inválido
    }

    // Configura a aceleração e a velocidade máxima do motor
    motor->setAcceleration(1000); // Define a aceleração em passos por segundo ao quadrado
    motor->setMaxSpeed(velocidadeMaxima); // Define a velocidade máxima em passos por segundo

    // Define a posição alvo
    motor->move(distancia);

    // Executa o movimento até que o motor alcance a posição desejada
    while (motor->distanceToGo() != 0) {
        motor->run();
    }
}


void paraMotor1(AccelStepper* motor){
    if (!motor) { // Verifica se o ponteiro do motor é válido
        return; // Retorna sem fazer nada se o ponteiro for inválido
    }

    Serial.println("y"); // Imprime "y" no monitor serial para indicar que o motor está parando

    motor->stop(); // Para o motor imediatamente
    motor->setCurrentPosition(0); // Redefine a posição atual do motor para 0
    motor->disableOutputs(); // Desabilita as saídas do motor (desliga a energia)
}



void calibracao(){
    
}

void subsidencia(AccelStepper* motor, int velocidadeMaxima, int aceleracao, long distancia){
    digitalWrite(PIN_ENABLE_1, HIGH);
    motor->setMaxSpeed(velocidadeMaxima);
    motor->setAcceleration(aceleracao);
    motor->move(distancia);
    
    while(motor->distanceToGo() != 0){
        motor->run();
    }

    delay(50);

    motor->move(-distancia);
    while(motor->distanceToGo() != 0){
        motor->run();
    }

    delay(50);
    digitalWrite(PIN_ENABLE_1, LOW);
}

void habilitarMotor(AccelStepper* motor, int enablePin){
    if(motor){
        digitalWrite(enablePin, HIGH); // Habilita o motor
    }
}

// Função para desabilitar um motor
void desabilitarMotor(AccelStepper* motor, int enablePin) {
    if (motor) {
        digitalWrite(enablePin, LOW); // Desabilita o motor
    }
}

