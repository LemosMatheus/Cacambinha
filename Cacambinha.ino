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

#define DIVISOR_BRANCO_PRETO_MAIS_ESQ 75
#define DIVISOR_BRANCO_PRETO_MAIS_DIR 85
#define DIVISOR_BRANCO_PRETO_DIR 60
#define DIVISOR_BRANCO_PRETO_ESQ 75

float valorSensorDir;
float valorSensorEsq;
float valorSensorMaisDir;
float valorSensorMaisEsq;

bool pppp() {
  return (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR);
}
bool bbbb() {
  return (valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);
}
bool bppb() {
  return (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);
}
bool pppb() {
  return (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);
}
bool pbbb() {
  return (valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);
}
bool bppp() {
  return (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR);
}
bool bpbb() {
  return (valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);
}
bool ppbb() {
  return (valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);
}
bool bbpp() {
  return (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR);
}
bool bbpb() {
  return (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR);
}
bool bbbp() {
  return (valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR);
}


void setup(){
	robo.configurar();
}

void loop(){

	valorSensorEsq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
	valorSensorDir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();

	if(pppp()){
		robo.acionarMotores(0,0);
	} else if(bbbb()){
    robo.acionarMotores(35, 30);
  } else if (bppb()){
    robo.acionarMotores(35, 30);
  } else if (pppb()){
    robo.acionarMotores(-80, 60);
  } else if (pbbb()){
    robo.acionarMotores(-35, 30);
  } else if (bppp()){
    robo.acionarMotores(60, -80);
  } else if (bpbb()){
    robo.acionarMotores(-35, 30);
  } else if(ppbb()) {
    robo.acionarMotores(-80, 60);
  }else if(bbpp()) {
    robo.acionarMotores(60, -80);
  }else if(bbpb()) {
    robo.acionarMotores(35, -30);
  }else if(bbbp()) {
    robo.acionarMotores(35, -30);
  }

}
