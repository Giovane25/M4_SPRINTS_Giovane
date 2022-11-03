#define sensorLuz 2
#define led1 48
#define led2 0
#define led3 36
#define led4 38
#define botao1 8
#define botao2 15
#define buzzer 40 //define as portas

void setup() {//define os pinos
  Serial.begin(9600);
  pinMode(botao1,INPUT);
  pinMode(botao2,INPUT);
  pinMode(sensorLuz,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(buzzer,OUTPUT);
};

int bt1;//define as variáveis que usei
int bt2;
int vetor[4] = {0,0,0,0};
int pos = 0;//posição do vetor na hora que for armazenar/ler
int valorConvertido;//valor do sensor convertido de 1 a 15
int valorSensor;//valor do sensor de 0 a 4095
int som; //som que toca no buzzer

void loop() {
  bt1 = digitalRead(botao1);//verifica se o botao 1 foi apertado
  bt2 = digitalRead(botao2);
  valorSensor = analogRead(sensorLuz);
  if(bt1==0){
    converter(valorSensor);
    apagarLeds();
  }
  if(bt2==0){
    lerVetor();
    apagarLeds();
    zerarVetor();
  }
  delay(500);
};

void converter(int valorSensor){//converte o valor do sensor para 1 a 15, acende o led correspondente ao binário e toca o buzzer.
  if(valorSensor<=273){ 
    valorConvertido = 1;
    acenderLed(1,0,0,0);
    tocarBuzzer(1);
    salvarNoVetor(1);
  }
  else if(valorSensor>273 && valorSensor<=546){
    valorConvertido = 2;
    acenderLed(0,1,0,0);
    tocarBuzzer(2);
    salvarNoVetor(2);
  }
  else if(valorSensor>546 && valorSensor<=819){
    valorConvertido = 3;
    acenderLed(1,1,0,0);
    tocarBuzzer(3);
    salvarNoVetor(3);
  }
  else if(valorSensor>819 && valorSensor<=1092){
    valorConvertido = 4;
    acenderLed(0,0,1,0);
    tocarBuzzer(4);
    salvarNoVetor(4);
  }
  else if(valorSensor>1092 && valorSensor<=1365){
    valorConvertido = 5;
    acenderLed(1,0,1,0);
    tocarBuzzer(5);
    salvarNoVetor(5);
  }
  else if(valorSensor>1365 && valorSensor<=1638){
    valorConvertido = 6;
    acenderLed(0,1,1,0);
    tocarBuzzer(6);
    salvarNoVetor(6);
  }
  else if(valorSensor>1638 && valorSensor<=1911){
    valorConvertido = 7;
    acenderLed(1,1,1,0);
    tocarBuzzer(7);
    salvarNoVetor(7);
  }
  else if(valorSensor>1911 && valorSensor<=2184){
    valorConvertido = 8;
    acenderLed(0,0,0,1);
    tocarBuzzer(8);
    salvarNoVetor(8);
  }
  else if(valorSensor>2184 && valorSensor<=2457){
    valorConvertido = 9;
    acenderLed(1,0,0,1);
    tocarBuzzer(9);
    salvarNoVetor(9);
  }
  else if(valorSensor>2457 && valorSensor<=2730){
    valorConvertido = 10;
    acenderLed(0,1,0,1);
    tocarBuzzer(10);
    salvarNoVetor(10);
  }
  else if(valorSensor>2730 && valorSensor<=3003){
    valorConvertido = 11;
    acenderLed(1,1,0,1);
    tocarBuzzer(11);
    salvarNoVetor(11);
  }
  else if(valorSensor>3003 && valorSensor<=3276){
    valorConvertido = 12;
    acenderLed(0,0,1,1);
    tocarBuzzer(12);
    salvarNoVetor(12);
  }
  else if(valorSensor>3276 && valorSensor<=3549){
    valorConvertido = 13;
    acenderLed(1,0,1,1);
    tocarBuzzer(13);
    salvarNoVetor(13);
  }
  else if(valorSensor>3549 && valorSensor<=3822){
    valorConvertido = 14;
    acenderLed(0,1,1,1);
    tocarBuzzer(14);
    salvarNoVetor(14);
  }
  else if(valorSensor>3822 && valorSensor<=4095){
    valorConvertido = 15;
    acenderLed(1,1,1,1);
    tocarBuzzer(15);
    salvarNoVetor(15);
  }
  delay(3000);
};

void acenderLed(int valor1,int valor2,int valor3,int valor4){//acende os LEDS do numero binário
  digitalWrite(led1,valor1);
  digitalWrite(led2,valor2);
  digitalWrite(led3,valor3);
  digitalWrite(led4,valor4);
};


void tocarBuzzer(int valorConvertido){//toca o buzzer
  som = valorConvertido*50;
  tone(buzzer,som,3000);
};

void salvarNoVetor(int valorConvertido){//salva no vetor o valor decimal
  if(pos==4){
    pos=0;
  }
  vetor[pos] = valorConvertido;
  pos = pos+1;
};

void lerVetor(){//le o vetor no segundo botao
  int valorSalvo;
  for(int i=0;i<4;i++){
    valorSalvo = vetor[i];
    if(valorSalvo==1){
      acenderLed(1,0,0,0);
      tocarBuzzer(1);
    } 
    else if(valorSalvo==2){
      acenderLed(0,1,0,0);
      tocarBuzzer(2);
    }
    else if(valorSalvo==3){
      acenderLed(1,1,0,0);
      tocarBuzzer(3);
    }
    else if(valorSalvo==4){
      acenderLed(0,0,1,0);
      tocarBuzzer(4);
    }
    else if(valorSalvo==5){
      acenderLed(1,0,1,0);
      tocarBuzzer(5);
    }
    else if(valorSalvo==6){
      acenderLed(0,1,1,0);
      tocarBuzzer(6);
    }
    else if(valorSalvo==7){
      acenderLed(1,1,1,0);
      tocarBuzzer(7);
    }
    else if(valorSalvo==8){
      acenderLed(0,0,0,1);
      tocarBuzzer(8);
    }
    else if(valorSalvo==9){
      acenderLed(1,0,0,1);
      tocarBuzzer(9);
    }
    else if(valorSalvo==10){
      acenderLed(0,1,0,1);
      tocarBuzzer(10);
    }
    else if(valorSalvo==11){
      acenderLed(1,1,0,1);
      tocarBuzzer(11);
    }
    else if(valorSalvo==12){
      acenderLed(0,0,1,1);
      tocarBuzzer(12);
    }
    else if(valorSalvo==13){
      acenderLed(1,0,1,1);
      tocarBuzzer(13);
    }
    else if(valorSalvo==14){
      acenderLed(0,1,1,1);
      tocarBuzzer(14);
    }
    else if(valorSalvo==15){
      acenderLed(1,1,1,1);
      tocarBuzzer(15);
    }
    delay(3000);
  }
};

void zerarVetor(){//zera o vetor no segundo botao
  for(int i=0;i<4;i++){
    vetor[i]=0;
  }
}

void apagarLeds(){//apaga os leds
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  digitalWrite(led4,0);
}
