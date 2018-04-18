#define NUM_SENSORS = 5;

int inPin1 = A0;
int inPin2 = A1;
int inPin3 = A2;

int ledPin1 = 7;
int ledPin2 = 6;
int ledPin3 = 5;


int ledArray[5] = {ledPin1, ledPin2, ledPin3};
int senseArray[5] = {inPin1, inPin2, inPin3};
boolean hitArray[5] = {false, false, false};

int targets[3] = {-1, -1, -1};
int threshhold = 900;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A5));
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  reset();
}

void loop() {
  for(int i = 0; i < 3; i++){
    if(analogRead(senseArray[i]) > threshhold){
      hitArray[i] = true;
      digitalWrite(ledArray[i], LOW);
    }
  }
  
  if(hitArray[targets[0]] && hitArray[targets[1]]){
    
    flash();
    flash();
    flash();
    delay(250);
    reset();
  }
}

void reset(){
  int randNums[2] = {-1, -1};
  for(int i = 0; i < 2; i++){
    
    targets[i] = random() % 3;
    for(int j = 0; j < 2; j++){
      while(randNums[j] == targets[i]){
        targets[i] = random() % 3;
      }
      randNums[j] = targets[i];
    }
    
    digitalWrite(ledArray[targets[i]], HIGH);
  }
  for(int i = 0; i < 3; i++){
    hitArray[i] = false;
  }
  
}

void flash() {
  for(int i = 0; i < 3; i++){
    digitalWrite(ledArray[targets[i]], HIGH);

  }
  delay(100);
for(int i = 0; i < 3; i++){
    digitalWrite(ledArray[targets[i]], LOW);
  }
  delay(100);
}

