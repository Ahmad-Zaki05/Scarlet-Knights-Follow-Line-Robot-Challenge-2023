// This code was written by Yahia Amr and his coach Ahmad Zaki
// This code is for testing the motion of the robot by testing the directions and the speeds of each motor
#define leftSpeed 11
#define rightSpeed 9
#define leftDirection 12
#define rightDirection 10
int dt = 1750;
int speed1 = 254;
int speed2 = 254 ;
int dt2 = 4000;


void setup() {
  pinMode(leftSpeed, OUTPUT);
  pinMode(leftDirection, OUTPUT);
  pinMode(rightSpeed, OUTPUT);
  pinMode(rightDirection, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // forward
  digitalWrite(leftDirection , HIGH);
  digitalWrite(rightDirection , HIGH);
  analogWrite(leftSpeed , speed1);
  analogWrite(rightSpeed , speed1);
  delay(dt);

  // left wide
  digitalWrite(leftDirection , LOW );
  digitalWrite(rightDirection , HIGH );
  analogWrite(leftSpeed , 0 );
  analogWrite(rightSpeed , speed1);
  delay(dt);

  // left tight
  digitalWrite(leftDirection , LOW );
  digitalWrite(rightDirection , HIGH );
  analogWrite(leftSpeed , speed1);
  analogWrite(rightSpeed , speed2);
  delay(dt);

  // right wide
  digitalWrite(leftDirection , HIGH);
  digitalWrite(rightDirection , LOW);
  analogWrite(leftSpeed , speed1 );
  analogWrite(rightSpeed , 0  );
  delay(dt);

  // right tight
  digitalWrite(leftDirection , HIGH);
  digitalWrite(rightDirection , LOW);
  analogWrite(leftSpeed , speed2);
  analogWrite(rightSpeed , speed1);
  delay(dt);

  //backwards
  digitalWrite(leftDirection , LOW);
  digitalWrite(rightDirection , LOW);
  analogWrite(leftSpeed , speed1);
  analogWrite(rightSpeed , speed1);
  delay(dt);
  
  // stop
  digitalWrite(leftDirection , HIGH);
  digitalWrite(rightDirection , HIGH);
  analogWrite(leftSpeed , 0);
  analogWrite(rightSpeed , 0);

  delay(5000);
}
