//saída analógica para definir a velocidade de rotação do motor
int speed1_pin = 3;

//saídas digitais para controle de direção do motor
int finger1_output1 = 2;
int finger1_output2 = 4;

int finger2_output1 = 5;
int finger2_output2 = 6;

int finger3_output1 = 7;
int finger3_output2 = 8;

int finger4_output1 = 9;
int finger4_output2 = 10;

int finger5_output1 = 11;
int finger5_output2 = 12;

//entrada analógica do sensor flexível
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;

//variável referente a posição inicial do sensor
int sensor1pos1 = 0;
int sensor2pos1 = 0;
int sensor3pos1 = 0;
int sensor4pos1 = 0;
int sensor5pos1 = 0;

//variável referente a posição final do sensor
int sensor1pos2 = 0;
int sensor2pos2 = 0;
int sensor3pos2 = 0;
int sensor4pos2 = 0;
int sensor5pos2 = 0;

//diferença entre a posição final e inicial do sensor
int move1 = 0;
int move2 = 0;
int move3 = 0;
int move4 = 0;
int move5 = 0;

//variável que retorna a diferença entre as posições do sensor
//multiplicada pelo fator de multiplicação int force
int steps = 0;

//definir a potência do movimento:
int force = 45;
//definir a sensibilidade mínima do movimento:
int sense = 10;

void setup()
{
//pinos dos motores
pinMode(speed1_pin, OUTPUT);
  
pinMode(finger1_output1, OUTPUT);
pinMode(finger1_output2, OUTPUT);

pinMode(finger2_output1, OUTPUT);
pinMode(finger2_output2, OUTPUT);
  
pinMode(finger3_output1, OUTPUT);
pinMode(finger3_output2, OUTPUT);
  
pinMode(finger4_output1, OUTPUT);
pinMode(finger4_output2, OUTPUT);
  
pinMode(finger5_output1, OUTPUT);
pinMode(finger5_output2, OUTPUT);
  
Serial.begin(9600);

//pinos dos sensores
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);
pinMode(sensor4, INPUT);
pinMode(sensor5, INPUT);
}

void loop()
{
analogWrite(speed1_pin, 300);  

sensor1pos1 = map(analogRead(sensor1), 14, 1020, 0, 100);
sensor2pos1 = map(analogRead(sensor2), 14, 1020, 0, 100);
sensor3pos1 = map(analogRead(sensor3), 14, 1020, 0, 100);
sensor4pos1 = map(analogRead(sensor4), 14, 1020, 0, 100);
sensor5pos1 = map(analogRead(sensor5), 14, 1020, 0, 100);

delay(1000);
sensor1pos2 = map(analogRead(sensor1), 14, 1020, 0, 100);
sensor2pos2 = map(analogRead(sensor2), 14, 1020, 0, 100);
sensor3pos2 = map(analogRead(sensor3), 14, 1020, 0, 100);
sensor4pos2 = map(analogRead(sensor4), 14, 1020, 0, 100);
sensor5pos2 = map(analogRead(sensor5), 14, 1020, 0, 100);



//move é a diferença de posição 
move1 = sensor1pos1 - sensor1pos2;
move2 = sensor2pos1 - sensor2pos2;
move3 = sensor3pos1 - sensor3pos2;
move4 = sensor4pos1 - sensor4pos2;
move5 = sensor5pos1 - sensor5pos2;
  
Serial.println(move5);

  if (move1 > sense || move1 < -sense){
      if (move1 < 0){
          steps = move1 * -force;
          Serial.println(steps);
          digitalWrite(finger1_output1, HIGH);
          digitalWrite(finger1_output2, LOW);
          delay(steps);
          digitalWrite(finger1_output1, LOW);
          digitalWrite(finger1_output2, LOW);
      }
      if (move1 > 0){
          steps = move1 * force;
          Serial.println(steps);
          digitalWrite(finger1_output1, LOW);
          digitalWrite(finger1_output2, HIGH);
          delay(steps);
          digitalWrite(finger1_output1, LOW);
          digitalWrite(finger1_output2, LOW);
      }
  }
  if (move2 > sense || move2 < -sense){
      if (move2 < 0){
          steps = move2 * -force;
          Serial.println(steps);
          digitalWrite(finger2_output1, HIGH);
          digitalWrite(finger2_output2, LOW);
          delay(steps);
          digitalWrite(finger2_output1, LOW);
          digitalWrite(finger2_output2, LOW);
      }
      if (move2 > 0){
          steps = move2 * force;
          Serial.println(steps);
          digitalWrite(finger2_output1, LOW);
          digitalWrite(finger2_output2, HIGH);
          delay(steps);
          digitalWrite(finger2_output1, LOW);
          digitalWrite(finger2_output2, LOW);
      }
  }
  if (move3 > sense || move3 < -sense){
      if (move3 < 0){
          steps = move3 * -force;
          Serial.println(steps);
          digitalWrite(finger3_output1, HIGH);
          digitalWrite(finger3_output2, LOW);
          delay(steps);
          digitalWrite(finger3_output1, LOW);
          digitalWrite(finger3_output2, LOW);
      }
      if (move3 > 0){
          steps = move3 * force;
          Serial.println(steps);
          digitalWrite(finger3_output1, LOW);
          digitalWrite(finger3_output2, HIGH);
          delay(steps);
          digitalWrite(finger3_output1, LOW);
          digitalWrite(finger3_output2, LOW);
      }
  }
  if (move4 > sense || move4 < -sense){
      if (move4 < 0){
          steps = move4 * -force;
          Serial.println(steps);
          digitalWrite(finger4_output1, HIGH);
          digitalWrite(finger4_output2, LOW);
          delay(steps);
          digitalWrite(finger4_output1, LOW);
          digitalWrite(finger4_output2, LOW);
      }
      if (move4 > 0){
          steps = move4 * force;
          Serial.println(steps);
          digitalWrite(finger4_output1, LOW);
          digitalWrite(finger4_output2, HIGH);
          delay(steps);
          digitalWrite(finger4_output1, LOW);
          digitalWrite(finger4_output2, LOW);
      }
  }
  if (move5 > sense || move5 < -sense){
      if (move5 < 0){
          steps = move5 * -force;
          Serial.println(steps);
          digitalWrite(finger5_output1, HIGH);
          digitalWrite(finger5_output2, LOW);
          delay(steps);
          digitalWrite(finger5_output1, LOW);
          digitalWrite(finger5_output2, LOW);
      }
      if (move5 > 0){
          steps = move5 * force;
          Serial.println(steps);
          digitalWrite(finger5_output1, LOW);
          digitalWrite(finger5_output2, HIGH);
          delay(steps);
          digitalWrite(finger5_output1, LOW);
          digitalWrite(finger5_output2, LOW);
      }
  }
}

