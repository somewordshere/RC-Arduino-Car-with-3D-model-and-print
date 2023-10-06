int m1_ENA = 5;        // Enable/speedOfCar motor Front Right
int m1_ENB = 6;        // Enable/speedOfCar motor Back Right
int m2_ENA = 10;       // Enable/speedOfCar motor Front Left
int m2_ENB = 11;       // Enable/speedOfCar motor Back Left

int IN_11 = 2;    		// L298N #1    1 motor Front Right
int IN_12 = 3;    		// L298N #1 in 2 motor Front Right
int IN_13 = 4;    		// L298N #1 in 3 motor Back Right
int IN_14 = 7;    		// L298N #1 in 4 motor Back Right

int IN_21 = 8;    		// L298N #2 in 1 motor Front Left
int IN_22 = 9;    		// L298N #2 in 2 motor Front Left
int IN_23 = 12;   		// L298N #2 in 3 motor Back Left
int IN_24 = 13;  		  // L298N #2 in 4 motor Back Left

int buzzer = 16;      //pin A2
int lightLeft = 15;   //pin A1
int lightRight = 14;  //pin A0

int command; 			    //Int to store app command state.
int speedOfCar = 80;
int coefficient = 4;
boolean light = false;
boolean buzz = false;

void setup() {
  pinMode(m1_ENA, OUTPUT);
  pinMode(m1_ENB, OUTPUT);
  pinMode(m2_ENA, OUTPUT);
  pinMode(m2_ENB, OUTPUT);

  pinMode(IN_11, OUTPUT);
  pinMode(IN_12, OUTPUT);
  pinMode(IN_13, OUTPUT);
  pinMode(IN_14, OUTPUT);

  pinMode(IN_21, OUTPUT);
  pinMode(IN_22, OUTPUT);
  pinMode(IN_23, OUTPUT);
  pinMode(IN_24, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(lightLeft, OUTPUT);
  pinMode(lightRight, OUTPUT);
  Serial.begin(9600);
}

void forward() {
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
  analogWrite(m1_ENA, speedOfCar);

  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, HIGH);
  analogWrite(m1_ENB, speedOfCar);


  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, HIGH);
  analogWrite(m2_ENA, speedOfCar);


  digitalWrite(IN_23, HIGH);
  digitalWrite(IN_24, LOW);
  analogWrite(m2_ENB, speedOfCar);
}

void backward() { 
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);
  analogWrite(m1_ENA, speedOfCar / coefficient);

  digitalWrite(IN_13, HIGH);
  digitalWrite(IN_14, LOW);
  analogWrite(m1_ENB, speedOfCar / coefficient);

  digitalWrite(IN_21, HIGH);
  digitalWrite(IN_22, LOW);
  analogWrite(m2_ENA, speedOfCar / coefficient);

  digitalWrite(IN_23, LOW);
  digitalWrite(IN_24, HIGH);
  analogWrite(m2_ENB, speedOfCar / coefficient);
}

void left() {
  digitalWrite(lightLeft, HIGH);

  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);
  analogWrite(m1_ENA, speedOfCar);

  digitalWrite(IN_13, HIGH);
  digitalWrite(IN_14, LOW);
  analogWrite(m1_ENB, speedOfCar);

  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, HIGH);
  analogWrite(m2_ENA, speedOfCar);

  digitalWrite(IN_23, HIGH);
  digitalWrite(IN_24, LOW);
  analogWrite(m2_ENB, speedOfCar);
}

void right() {
  digitalWrite(lightRight, HIGH);

  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
  analogWrite(m1_ENA, speedOfCar);

  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, HIGH);
  analogWrite(m1_ENB, speedOfCar);

  digitalWrite(IN_21, HIGH);
  digitalWrite(IN_22, LOW);
  analogWrite(m2_ENA, speedOfCar);

  digitalWrite(IN_23, LOW);
  digitalWrite(IN_24, HIGH);
  analogWrite(m2_ENB, speedOfCar);
}

void forwardRight() {
  digitalWrite(lightLeft, HIGH);
  
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
  analogWrite(m1_ENA, speedOfCar / coefficient);

  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, HIGH);
  analogWrite(m1_ENB, speedOfCar / coefficient);

  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, HIGH);
  analogWrite(m2_ENA, speedOfCar);

  digitalWrite(IN_23, HIGH);
  digitalWrite(IN_24, LOW);
  analogWrite(m2_ENB, speedOfCar);
}

void forwardLeft() {
  digitalWrite(lightRight, HIGH);
  digitalWrite(IN_11, HIGH);
  digitalWrite(IN_12, LOW);
  analogWrite(m1_ENA, speedOfCar);

  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, HIGH);
  analogWrite(m1_ENB, speedOfCar);

  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, HIGH);
  analogWrite(m2_ENA, speedOfCar / coefficient);

  digitalWrite(IN_23, HIGH);
  digitalWrite(IN_24, LOW);
  analogWrite(m2_ENB, speedOfCar / coefficient);
}

void backwardRight() {
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);
  analogWrite(m1_ENA, speedOfCar / coefficient);

  digitalWrite(IN_13, HIGH);
  digitalWrite(IN_14, LOW);
  analogWrite(m1_ENB, speedOfCar / coefficient);

  digitalWrite(IN_21, HIGH);
  digitalWrite(IN_22, LOW);
  analogWrite(m2_ENA, speedOfCar);

  digitalWrite(IN_23, LOW);
  digitalWrite(IN_24, HIGH);
  analogWrite(m2_ENB, speedOfCar);
}

void backwardLeft() {
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, HIGH);
  analogWrite(m1_ENA, speedOfCar);

  digitalWrite(IN_13, HIGH);
  digitalWrite(IN_14, LOW);
  analogWrite(m1_ENB, speedOfCar);

  digitalWrite(IN_21, HIGH);
  digitalWrite(IN_22, LOW);
  analogWrite(m2_ENA, speedOfCar / coefficient);

  digitalWrite(IN_23, LOW);
  digitalWrite(IN_24, HIGH);
  analogWrite(m2_ENB, speedOfCar / coefficient);
}

void stopCar() {
  digitalWrite(IN_11, LOW);
  digitalWrite(IN_12, LOW);
  analogWrite(m1_ENA, speedOfCar);

  digitalWrite(IN_13, LOW);
  digitalWrite(IN_14, LOW);
  analogWrite(m1_ENB, speedOfCar);

  digitalWrite(IN_21, LOW);
  digitalWrite(IN_22, LOW);
  analogWrite(m2_ENA, speedOfCar);

  digitalWrite(IN_23, LOW);
  digitalWrite(IN_24, LOW);
  analogWrite(m2_ENB, speedOfCar);
}


void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    if(light){ digitalWrite(lightLeft, HIGH); digitalWrite(lightRight, HIGH);} 
    if(!light){ digitalWrite(lightLeft, LOW); digitalWrite(lightRight, LOW);}
    if(buzz) {digitalWrite(buzzer, HIGH);}
    if(!buzz) {digitalWrite(buzzer, LOW);}

    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'I': forwardLeft(); break;
      case 'G': forwardRight(); break;
      case 'J': backwardLeft(); break;
      case 'H': backwardRight(); break;
      case '0': speedOfCar = 100; break;
      case '1': speedOfCar = 115; break;
      case '2': speedOfCar = 130; break;
      case '3': speedOfCar = 145; break;
      case '4': speedOfCar = 160; break;
      case '5': speedOfCar = 175; break;
      case '6': speedOfCar = 190; break;
      case '7': speedOfCar = 205; break;
      case '8': speedOfCar = 220; break;
      case '9': speedOfCar = 235; break;
      case 'q': speedOfCar = 255; break;
      case 'W': light = true; break;
      case 'w': light = false; break;
      case 'V': buzz = true; break;
      case 'v': buzz = false; break;
      default: stopCar(); break;
    }
  }
}
