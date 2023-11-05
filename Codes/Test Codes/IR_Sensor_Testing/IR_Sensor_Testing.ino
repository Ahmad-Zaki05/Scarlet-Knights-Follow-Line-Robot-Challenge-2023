// This code was written by Yahia Amr and his coach Ahmad Zaki
// This code is used when calibrating the IR sensors to know what reading they are giving at the moment of calibration
#define leftsII 6
#define lefts 5
#define middles 4
#define rights 2
#define rightsII 3
int L = 0, M = 0 , R = 0 , LL = 0, RR = 0;
void setup() {
  pinMode(lefts , INPUT);
  pinMode(middles,  INPUT);
  pinMode(rights  , INPUT);
  pinMode(rightsII , INPUT);
  pinMode(leftsII , INPUT);
  Serial.begin(9600);

}
void loop() {
  L = digitalRead(lefts);
  M = digitalRead(middles);
  R = digitalRead(rights);
  LL = digitalRead(leftsII);
  RR = digitalRead(rightsII);
  Serial.print(LL);
  Serial.print("\t");
  Serial.print(L);
  Serial.print("\t");
  Serial.print(M);
  Serial.print("\t");
  Serial.print(R);
  Serial.print("\t");
  Serial.println(RR);
}
