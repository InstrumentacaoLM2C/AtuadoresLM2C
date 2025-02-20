#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <AccelStepper.h>

// Configurações iniciais para os Motores 
int ConfigurarMotor (AccelStepper* numeroMotor, int velocidadeMaximaMotor, int aceleracaoMotor, int velocidadeMotor); 

// Função para criar um motor
AccelStepper* CriarMotor(int stepPin, int dirPin, int enablePin, int velocidadeMaxima, int aceleracao, int velocidade);

// Função para mover um motor
int MoverMotor(AccelStepper* motor, long distancia);

// Função para desabilitar um motor
void DesabilitarMotor(AccelStepper* motor, int enablePin);

void VerificarSerial();

void moverUniforme();

void moverAcelerado1();

void moverAcelerado2();

void moverUniforme1();

void moverUniforme2();

void paraMotor1();

void paraMotor2();

void calibracao();

void subsidencia();

#endif