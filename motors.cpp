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
 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);




  // Back Wheels

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);

  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}




void backward(){
  // Front Wheels

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);


  // Back Wheels

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);


  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
}




void turnLeft(){

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
 
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);


  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);


  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);

}








void turnRight(){
 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);


  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);


  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);








}




void stop(){
  // Front Wheels

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);




  // Back Wheels

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);

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
    char command = Serial.read();// serial reads whatever your keyboard input is
    delay(500);
    control(command);




  }








  }
  else{
    Serial.println("Error Occured: Motor System Offline");
  }








}







