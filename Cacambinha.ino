#include <robo_hardware2.h> 
#include <Servo.h>

//-----PINOS PARA LIGAR MOTORES-----//
//Motor1:
//pino1 PWM_RODA_DIREITA 	6
//pino2 SENTIDO_RODA_DIREITA 	7
//
//Motor2:
//pino1 PWM_RODA_ESQUERDA 	5
//pino2 SENTIDO_RODA_ESQUERDA	4
//-----PINOS PARA LIGAR MOTORES-----//

//-----PINOS PARA SENSORES REFLETANCIA-----//
//SENSOR_LINHA_MAIS_ESQUERDO	    A3
//SENSOR_LINHA_ESQUERDO			    A2
//SENSOR_LINHA_DIREITO			    A1	
//SENSOR_LINHA_MAIS_DIREITO			A0	
//-----PINOS PARA SENSORES REFLETANCIA-----//

#define DIVISOR_BRANCO_PRETO_MAIS_ESQ 25
#define DIVISOR_BRANCO_PRETO_MAIS_DIR 75
#define DIVISOR_BRANCO_PRETO_DIR 20
#define DIVISOR_BRANCO_PRETO_ESQ 75

float valorSensorDir;
float valorSensorEsq;
float valorSensorMaisDir;
float valorSensorMaisEsq;

void setup(){
	robo.configurar();
}

void loop(){

	valorSensorEsq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
	valorSensorDir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();

	//Identifica se os dois sensores viram branco
	if(valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR){
		robo.acionarMotores(0,0);	//Aciona os dois motores com a mesma velocidade
	} else if(valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(30, 30);//DIREITA BRANCO, ESQUERDA BRANCO, MAIS ESQUERDA BRANCO, MAIS DIREITA BRANCO
  } else if (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(30, 30);//DIREITA PRETO, ESQUERDA PRETO, MAIS ESQUERDA BRANCO, MAIS DIREITA BRANCO
  } else if (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(-40, 70);//DIREITA PRETO, ESQUERDA PRETO, MAIS ESQUERDA PRETO, MAIS DIREITA BRANCO
  } else if (valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(-30, 35);//DIREITA BRANCO, ESQUERDA BRANCO, MAIS ESQUERDA PRETO, MAIS DIREITA BRANCO
  } else if (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(70, -40);//DIREITA PRETO, ESQUERDA PRETO, MAIS ESQUERDA BRANCO, MAIS DIREITA PRETO
  } else if (valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(-25 , 35);//DIREITA BRANCO, ESQUERDA PRETO, MAIS ESQUERDA BRANCO, MAIS DIREITA BRANCO
  } else if(valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR) {
    robo.acionarMotores(-30, 70);//DIREITA BRANCO, ESQUERDA PRETO, MAIS ESQUERDA PRETO, MAIS DIREITA BRANCO
  }else if(valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR) {
    robo.acionarMotores(70, -30);//DIREITA PRETO, ESQUERDA BRANCO, MAIS ESQUERDA BRANCO, MAIS DIREITA PRETO
  }else if(valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR) {
    robo.acionarMotores(25, -30);//DIREITA PRETO, ESQUERDA BRANCO, MAIS ESQUERDA BRANCO, MAIS DIREITA BRANCO
  }else if(valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR) {
    robo.acionarMotores(35, -30);//DIREITA BRANCO, ESQUERDA BRANCO, MAIS ESQUERDA BRANCO, MAIS DIREITA PRETO
  }

}
