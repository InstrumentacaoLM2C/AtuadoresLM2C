#include "../include/functions.h"
#include "../include/macros.h"
#include "../include/globals.h"
#include <AccelStepper.h>

bool pararMotores = false;

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

// Função para mover um motor (NÃO ESTÁ SENDO UTILIZADA)
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

// Função para mover o motor com aceleraçao
void moverAcelerado(AccelStepper* motor, long distancia, int velocidadeMaxima) {
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


// Função para mover o motor de forma acelerada
void moverUniforme(AccelStepper* motor, long distancia, int velocidadeMaxima){
    if (!motor) { // Verifica se o ponteiro do motor é válido
        return; // Retorna sem fazer nada se o ponteiro for inválido
    }

    //Serial.println("Motor movendo");

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

void moverSimultaneo(AccelStepper* motor1, AccelStepper* motor2, int distancia1, int distancia2, int velocidadeMaxima1, int velocidadeMaxima2, String direcao) {
    //Serial.println("Motores movendo simultaneamente");


    long posicaoDesejada1, posicaoDesejada2;

    // Configura aceleração e velocidade máxima dos motores

    if(direcao == "C"){
        motor1->setMaxSpeed(velocidadeMaxima1);
        motor2->setMaxSpeed(-velocidadeMaxima2);
    } else if(direcao == "B") {
        motor1->setMaxSpeed(-velocidadeMaxima1);
        motor2->setMaxSpeed(velocidadeMaxima2);
    }

    pararMotores = false;

    motor1->setAcceleration(1000000); // Aceleração muito alta para movimento uniforme
    motor2->setAcceleration(1000000); // Aceleração muito alta para movimento uniforme
    posicaoDesejada1 = motor1->currentPosition() + distancia1;
    posicaoDesejada2 = motor2->currentPosition() + distancia2;
    motor1->moveTo(posicaoDesejada1);
    motor2->moveTo(posicaoDesejada2);

    // Loop enquanto pelo menos um motor ainda não atingiu a posição desejada
    while ((motor1->currentPosition() != posicaoDesejada1) || (motor2->currentPosition() != posicaoDesejada2)) {
        // Executa o motor 1 se ainda não atingiu a posição desejada
        if(pararMotores = true){
            break;
        }

        if (motor1->currentPosition() != posicaoDesejada1) {
            motor1->run();
            /*Serial.print("Motor 1 - Posição atual: ");
            Serial.print(motor1->currentPosition());
            Serial.print(" / Posição desejada: ");
            Serial.println(posicaoDesejada1);*/
        }

        // Executa o motor 2 se ainda não atingiu a posição desejada
        if (motor2->currentPosition() != posicaoDesejada2) {
            motor2->run();
            /*Serial.print("Motor 2 - Posição atual: ");
            Serial.print(motor2->currentPosition());
            Serial.print(" / Posição desejada: ");
            Serial.println(posicaoDesejada2);*/
        }
    }

    //Serial.println("Motores pararam");
    Serial.println('y');
}

void paraMotorSimultaneo(AccelStepper* motor1, AccelStepper* motor2){
    if((!motor1) || (!motor2)) {
        return;
    }

    pararMotores = true;

    motor1->stop();
    motor2->stop();
    motor1->disableOutputs(); 
    motor2->disableOutputs();
    motor1->setCurrentPosition(0);
    motor2->setCurrentPosition(0);

    Serial.println('y'); // Imprime "y" no monitor serial para indicar que o motor está parando
}

void paraMotor(AccelStepper* motor){
    if (!motor) { // Verifica se o ponteiro do motor é válido
        return; // Retorna sem fazer nada se o ponteiro for inválido
    }

    motor->stop(); // Para o motor imediatamente
    motor->disableOutputs(); // Desabilita as saídas do motor (desliga a energia)
    motor->setCurrentPosition(0); // Redefine a posição atual do motor para 

    Serial.println('y'); // Imprime "y" no monitor serial para indicar que o motor está parando
    
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

