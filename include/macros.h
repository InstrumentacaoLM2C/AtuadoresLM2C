#ifndef MACROS_H
#define MACROS_H

// Define Erros de Exeecução
#define OK                                  0 // Executado com sucesso
#define ERROR_MOTOR_NAO_SELECIONADO         1

// Defina os pinos de controle do primeiro motor
#define STEP_PIN_1 PA8  // Pino de passo (STEP) do Motor 1
#define DIR_PIN_1 PA9   // Pino de direção (DIR) do Motor 1
#define ENABLE_PIN_1 PA10  // Pino de ENABLE do Motor 1

// Defina os pinos de controle do segundo motor
#define STEP_PIN_2 PA11  // Pino de passo (STEP) do Motor 2
#define DIR_PIN_2 PA12   // Pino de direção (DIR) do Motor 2
#define ENABLE_PIN_2 PA13  // Pino de ENABLE do Motor 2

#endif