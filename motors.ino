#define IN1 5
#define IN2 4
#define IN3 3
#define IN4 2




#define IN5 9
#define IN6 10
#define IN7 11
#define IN8 12









void forward(){
  // Front Wheels
 
  // Front Left wheel
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);




  // Front Right wheel
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);




  // Back Wheels

  // Back Left Wheel
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);


  // Back Right Wheel
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}




void backward(){
  // Front Wheels

  // Front Left wheel
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);


  // Front Right wheel
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);



  // Back Wheels

  // Back Left Wheel
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);

  // Back Right Wheel
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
}




void turnLeft(){


  // Front Right wheel forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
 
  // Back Right Wheel Forward
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);


  // Front Left wheel backward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Back Left Wheel backward
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);



}








void turnRight(){
  // Front Left wheel forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Back Left Wheel forward
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);


  // Front Right wheel backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);


  // Back Right Wheel backward
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);



}




void stop(){
  // Front Wheels
 
  // Front Left wheel
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Front Right wheel
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);


  // Back Wheels

  // Back Left Wheel
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);

  // Back Right Wheel
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
}



void control(char cmd){
  switch (cmd) {
    case 'w':
      forward();
      break;
    case 's':
      backward();
      break;
    case 'a':
      turnLeft();
      break;
    case 'd':
      turnRight();
      break;
    case 'q':
      stop();
      break;
    default:
      Serial.println("Incorrect Input. (WASD controls)");
      break;
   
  }
}




void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);




  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);




}




void loop() {
  if (Serial){
    if(Serial.available() > 0){
    Serial.println("Motor System Online");
    char command = Serial.read();
    delay(500);
    control(command);

  }


  }
  else{
    Serial.println("Error Occured: Motor System Offline");
  }


}







