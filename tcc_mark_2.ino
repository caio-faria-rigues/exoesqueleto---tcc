int speed1_pin = 3;

int finger1_output1 = 2;
int finger1_output2 = 4;

int sensor1 = A0;

int sensor1pos1 = 0;

int sensor1pos2 = 0;

int move1 = 0;

int steps = 1000;

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
  
Serial.begin(9600);

//pinos dos sensores
pinMode(sensor1, INPUT);
}

void loop()
{
analogWrite(speed1_pin, 300);  

sensor1pos1 = map(analogRead(sensor1), 14, 1020, 0, 100);
delay(1000);
sensor1pos2 = map(analogRead(sensor1), 0, 1023, 0, 100);

//move1 é a diferença de posição 
move1 = sensor1pos1 - sensor1pos2;
Serial.println(move1);

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
}
