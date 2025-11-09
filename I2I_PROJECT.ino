#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
 #define CROSS 'X'
// #define TRIANGLE 'T'
// #define SQUARE 'S'
// #define START 'A'
// #define PAUSE 'P'


int motor1pin1 = 2;  // IN4 for first motor
int motor1pin2 = 4;  // IN3 for first motor
int motor2pin1 = 7;  // IN2 for second motor
int motor2pin2 = 8; // IN1 for second motor
int motor3pin1 = 12;  // IN2 for third motor
int motor3pin2 = 13;  // IN3 for third motor
int motor4pin1 = 3;  // IN4 for fourth motor
int motor4pin2 = 5;

void setup() {
  Serial.begin(9600);  // Set the baud rate for serial communication
  // Initialize any other necessary setup code here

    pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH); //relay


}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    executeCommand(command);
    
    if (command == CIRCLE){
      digitalWrite(9,LOW);
    }

    else if (command == CROSS){
      digitalWrite(9,HIGH);
    }
  }
  // Continue with other tasks in your main loop
}

void executeCommand(char command) {
  switch (command) {
    case FORWARD:
      // Perform action for moving forward
      forward();
      break;
    case BACKWARD:
      reverse();
      // Perform action for moving backward
      break;
    case LEFT:
       left();
      // Perform action for turning left
      break;
    case RIGHT:
       right();
      // Perform action for turning right
      break;
    // case CIRCLE:
    // digitalWrite(9,LOW);
    
    //   // Perform action for circle
    //   break;
    // case CROSS:

    //   digitalWrite(9,HIGH);
    //   // Perform action for immediate stop or crossing
    //   break;
    // case TRIANGLE:
    //   // Perform action for toggling a state (e.g., LED on/off)
    //   break;
    // case SQUARE:
    //   // Perform action for retrieving and sending status information
    //   break;
    // case START:
    //   // Perform action for starting a process or operation
    //   break;
    // case PAUSE:
    //   // Perform action for pausing a process or operation
    //   break;
    default:
       digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);
  // digitalWrite(9,HIGH);

      // Invalid command received
      break;
  }
}



void forward (){

    digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);

}


void left(){
    digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);

}

void reverse(){
    digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);

}

void right(){
    digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);

}