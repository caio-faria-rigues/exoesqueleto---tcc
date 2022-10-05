int speed2_pin = 3;

int finger2_output1 = 2;
int finger2_output2 = 4;

int sensor2 = A1;

int sensor2pos1 = 0;

int sensor2pos2 = 0;

int move2 = 0;

int steps = 1000;

//definir a potência do movimento:
int force = 30;
//definir a sensibilidade mínima do movimento:
int sense = 10;

void setup()
{
//pinos dos motores
pinMode(speed2_pin, OUTPUT);
  
pinMode(finger2_output1, OUTPUT);
pinMode(finger2_output2, OUTPUT);
  
Serial.begin(9600);

//pinos dos sensores
pinMode(sensor2, INPUT);
}

void loop()
{
analogWrite(speed2_pin, 300);  

sensor2pos1 = map(analogRead(sensor2), 0, 1023, 0, 100);
delay(1000);
sensor2pos2 = map(analogRead(sensor2), 0, 1023, 0, 100);

//move2 é a diferença de posição 
move2 = sensor2pos1 - sensor2pos2;
Serial.println(move2);

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
}
