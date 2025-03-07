#ifndef MACROS_H
#define MACROS_H

// Define Erros de Exeecução
#define OK                                  0 // Executado com sucesso
#define ERROR_MOTOR_NAO_SELECIONADO         1

// Defina os pinos de controle do primeiro motor
#define PIN_PASSO_1 PA8  // Pino de passo (STEP) do Motor 1
#define PIN_DIR_1 PA9   // Pino de direção (DIR) do Motor 1
#define PIN_ENABLE_1 PA10  // Pino de ENABLE do Motor 1

// Defina os pinos de controle do segundo motor
#define PIN_PASSO_2 PA11  // Pino de passo (STEP) do Motor 2
#define PIN_DIR_2 PA12   // Pino de direção (DIR) do Motor 2
#define PIN_ENABLE_2 PA13  // Pino de ENABLE do Motor 2

#define LIGAR_MOTOR                         'A'
#define DESLIGAR_MOTOR                      'a'
#define MOVER_MOTOR_BAIXO                   'B'
#define MOVER_MOTOR_CIMA                    'C'
#define INICIAR_CALIBRACAO                  'I'
#define QTD_PULSOS                          'P'
#define ACELERAR_MOTOR                      'G'
#define ATIVAR_MOTOR_VEL_CTE                'H'
#define CONFIGURAR_ZERO_LASER               'J'
#define SUBSIDENCIA                         'K'
#define ALTERAR_PARA_MOTOR_2                'M'
#define PARAR_MOTOR                         'n'
#define PARAR_CALIBRACAO                    'N'
#define POSICAO_MOTOR_1                     'O'
#define POSICAO_MOTOR_2                     'o'
#define ALTERAR_PARA_MOTOR_1                'R'
#define ATIVAR_SENSOR_INDUTIVO              'S'
#define ENVIAR_CONFIG_COMPLETA              'T'
#define INSERIR_CONSTANTES_CALIBRACAO       'U'
#define DEFINIR_VELOCIDADE                  'V'
#define MSG_MOTOR_MOVENDO_COM_ACELERACAO    'X'
#define MSG_MOTOR_MOVENDO_SEM_ACELERACAO    'x'
#define MOTOR_1                              1
#define MOTOR_2                              2
#define DIRECAO_MOTOR_1_BAIXO               "Mover motor 1 para baixo"
#define DIRECAO_MOTOR_2_BAIXO               "Mover motor 2 para baixo"

#endif