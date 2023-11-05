//sensors
#define LSP2 6
#define LSP 5
#define MSP 4
#define RSP 2
#define RSP2 3
//motor
#define LD 12
#define RD 10
#define LS 11
#define RS 9
//other
#define SPD 150               //FOWARD
#define SPD2 250              //MAIN WHEEL SPEED
 #define SPD3 92              //SECONDARY WHEEL SPEED
#define SPD4 200              //main wheel for while loops
#define SPD5 50               //secondary wheel for while loops
#define MOTOR_DIRECTION HIGH  //SECONDARY WHEEL DIRECTION
#define MOTOR_DIRECTION2 LOW  //SECONDRY wheel dircetion for while loops
//variables
int LL, L, M, R, RR;

void setup() {
  pinMode(LSP2,INPUT);
  pinMode(LSP, INPUT);
  pinMode(MSP, INPUT);
  pinMode(RSP, INPUT);
  pinMode(RSP2, INPUT);
  pinMode(LD, OUTPUT);
  pinMode(RD, OUTPUT);
  pinMode(LS, OUTPUT);
  pinMode(RS, OUTPUT);
  // Serial.begin(9600);
}

void loop() {
  LL = digitalRead(LSP2);
  L = digitalRead(LSP);
  M = digitalRead(MSP);
  R = digitalRead(RSP);
  RR = digitalRead(RSP2);
  // Serial.print(LL);
  // Serial.print("\t");
  // Serial.print(L);
  // Serial.print("\t");
  // Serial.print(M);
  // Serial.print("\t");
  // Serial.print(R);
  // Serial.print("\t");
  // Serial.println(RR);

  //conditions
  if (LL == 1 && RR == 0) {
    if (M == 1 && L == 1 && R == 1) {
      digitalWrite(LD, MOTOR_DIRECTION2);
      digitalWrite(RD, HIGH);
      analogWrite(LS, SPD5);
      analogWrite(RS, SPD4);
      //Serial.print(LL);
      // Serial.print("\t");
      // Serial.print(L);
      // Serial.print("\t");
      // Serial.print(M);
      // Serial.print("\t");
      // Serial.print(R);
      // Serial.print("\t");
      // Serial.println(RR);
    } else {
      whileleft();
    }
  }

  else if (LL == 0 && RR == 1) {
    if (M == 1 && L == 1 && R == 1) {
      digitalWrite(LD, HIGH);
      digitalWrite(RD, MOTOR_DIRECTION2);
      analogWrite(LS, SPD4);
      analogWrite(RS, SPD5);
      Serial.print(LL);
      // Serial.print("\t");
      // Serial.print(L);
      // Serial.print("\t");
      // Serial.print(M);
      // Serial.print("\t");
      // Serial.print(R);
      // Serial.print("\t");
      // Serial.println(RR);
    } else {
      whileright();
    }
  }

  //right
  else if (R == 1 && L == 0) {
    while (M == 0 && LL == 0 && RR==0) {
      digitalWrite(LD, HIGH);
      digitalWrite(RD, MOTOR_DIRECTION);
      analogWrite(LS, SPD2);
      analogWrite(RS, SPD3);
      LL = digitalRead(LSP2);
      M = digitalRead(MSP);
      RR = digitalRead(RSP2);
    }
  }

  //left
  else if (R == 0 && L == 1) {
    while(M==0 && RR==0 && LL==0){
    digitalWrite(LD, MOTOR_DIRECTION);
    digitalWrite(RD, HIGH);
    analogWrite(LS, SPD3);
    analogWrite(RS, SPD2);
    M = digitalRead(MSP);
    LL = digitalRead(LSP2);
    RR = digitalRead(RSP2);}

  }
  //forward
  else {
    //previous_time=millis();
    //if(min2<set_speed<max2){set_speed=set_speed + 15}
    digitalWrite(LD, HIGH);
    digitalWrite(RD, HIGH);
    analogWrite(LS, SPD);
    analogWrite(RS, SPD);
  }
}
void whileright() {
  while (M == 0 && L == 0 && R==0) {
    digitalWrite(LD, HIGH);
    digitalWrite(RD, MOTOR_DIRECTION2);
    analogWrite(LS, SPD4);
    analogWrite(RS, SPD5);
    M = digitalRead(MSP);
    R = digitalRead(RSP);
    L = digitalRead(LSP);
    LL = digitalRead(LSP2);
    if (LL == 1) {
      whileleft();
      return;
    }
  }
}
void whileleft() {
  while (M == 0 && R == 0 && L==0) {
    digitalWrite(LD, MOTOR_DIRECTION2);
    digitalWrite(RD, HIGH);
    analogWrite(LS, SPD5);
    analogWrite(RS, SPD4);
    M = digitalRead(MSP);
    L = digitalRead(LSP);
    R = digitalRead(RSP);
    RR = digitalRead(RSP2);
    if (RR == 1) {
      whileright();
      return;
    }
  }
}
