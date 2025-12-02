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

#define DIVISOR_BRANCO_PRETO_MAIS_ESQ 45
#define DIVISOR_BRANCO_PRETO_MAIS_DIR 85
#define DIVISOR_BRANCO_PRETO_DIR 25
#define DIVISOR_BRANCO_PRETO_ESQ 25
#define DIVISOR_DISTANCIA 10

float valorSensorDir;
float valorSensorEsq;
float valorSensorMaisDir;
float valorSensorMaisEsq;
float valorSensorFrontal;

void setup(){
  Serial.begin(9600);
	robo.configurar();
}

void loop(){

	valorSensorEsq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
	valorSensorDir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
  valorSensorFrontal = robo.lerSensorSonarFrontal();

	//Identifica se os dois sensores viram branco

if (valorSensorFrontal > DIVISOR_DISTANCIA) {
  if(valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(0, 0);
	} else if(valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(26,26);
    //}	//DIREITA BRANCO, ESQUERDA BRANCO, MAIS ESQUERDA BRANCO, MAIS DIREITA BRANCO
  } else if (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(26, 26);
;	//DIREITA PRETO, ESQUERDA PRETO, MAIS ESQUERDA BRANCO, MAIS DIREITA BRANCO
  } else if (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(-70, 80);
    //}	//DIREITA PRETO, ESQUERDA PRETO, MAIS ESQUERDA PRETO, MAIS DIREITA BRANCO
  } else if (valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(-40, 40);
  //}	//DIREITA BRANCO, ESQUERDA BRANCO, MAIS ESQUERDA PRETO, MAIS DIREITA BRANCO
  } else if (valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(80, -70);
    //}	//DIREITA PRETO, ESQUERDA PRETO, MAIS ESQUERDA BRANCO, MAIS DIREITA PRETO
  } else if (valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR){
    robo.acionarMotores(-30 , 30);
  //robo.acionarMotores(0, 0);
    //}	//DIREITA BRANCO, ESQUERDA PRETO, MAIS ESQUERDA BRANCO, MAIS DIREITA BRANCO
  } else if(valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR) {
    robo.acionarMotores(-60, 75);
    //}	//DIREITA BRANCO, ESQUERDA PRETO, MAIS ESQUERDA PRETO, MAIS DIREITA BRANCO
  }else if(valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR) {
    robo.acionarMotores(80, -60);
    //}	//DIREITA PRETO, ESQUERDA BRANCO, MAIS ESQUERDA BRANCO, MAIS DIREITA PRETO
  }else if(valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir > DIVISOR_BRANCO_PRETO_MAIS_DIR) {
    robo.acionarMotores(30, -30);
    //}	//DIREITA PRETO, ESQUERDA BRANCO, MAIS ESQUERDA BRANCO, MAIS DIREITA BRANCO
  }else if(valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO_MAIS_ESQ && valorSensorMaisDir < DIVISOR_BRANCO_PRETO_MAIS_DIR) {
    robo.acionarMotores(40, -40);///DIREITA BRANCO, ESQUERDA BRANCO, MAIS ESQUERDA BRANCO, MAIS DIREITA PRETO
  }
} else {
  /*robo.acionarMotores(0, 0);
  delay(1000);
  robo.acionarMotores(57, -57);
  delay(710);*/
  robo.acionarMotores(0,0);
  delay(1000);
  robo.acionarMotores(40, -40);
  delay(210);
  robo.acionarMotores(0,0);
  delay(1000);
  robo.acionarMotores(43, 50);
  delay(500);
  robo.acionarMotores(0, 0);
  delay(1000);
  robo.acionarMotores(-35, 35);
  delay(260);
  robo.acionarMotores(0,0);
  delay(1000);
  robo.acionarMotores(40, 43);
  delay(700);
  robo.acionarMotores(0,0);
  delay(1000);
  robo.acionarMotores(-40, 40);
  delay(300);
  robo.acionarMotores(0, 0);
  delay(1000);
  robo.acionarMotores(35, 35);
  delay(250);
  robo.acionarMotores(50, -40);
  delay(100);


  

};
}