int inpin1 = A0;
int inpin2 = A1;
int inpin3 = A2;
int inpin4 = A3;
int inpin5 = A4;

int ledPin1 = 7;
int ledPin2 = 6;
int ledPin3 = 5;
int ledPin4 = 4;
int ledPin5 = 3;

int switch1 = 0;
int switch2 = 0;
int switch3 = 0;
int switch4 = 0;
int switch5 = 0;

int threshold = 900;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inpin1, INPUT);
  pinMode(inpin2, INPUT);
  pinMode(inpin3, INPUT);
  pinMode(inpin4, INPUT);
  pinMode(inpin5, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if (analogRead(inpin1) > threshold) {
    digitalWrite(ledPin1, HIGH);
    if (switch1==0){ switch1=1;};
  }
  
  if (analogRead(inpin2) > threshold) {
    digitalWrite(ledPin2, HIGH);
    if (switch2==0){ switch2=1;};    
  }
  
  if (analogRead(inpin3) > threshold) {
    digitalWrite(ledPin3, HIGH);
    if (switch3==0){ switch3=1;};

  }

  if (analogRead(inpin4) > threshold) {
    digitalWrite(ledPin4, HIGH);
    if (switch4==0){ switch4=1;};
  }

  if (analogRead(inpin5) > threshold) {
    digitalWrite(ledPin5, HIGH);
    if (switch5==0){ switch5=1;};
  }
  if (switch1+switch2+switch3>=3) {
    int i = 0;
    while (i<5) {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      digitalWrite(ledPin5, HIGH);
      delay(100);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
      delay(100);
      ++i;
    }
    switch1 = 0;
    switch2 = 0;
    switch3 = 0;
    switch4 = 0;
    switch5 = 0;
    delay(250);
  }
  delay(10);
}

