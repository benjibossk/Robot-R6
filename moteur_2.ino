int motor1Pin1 = 3;    // reculé gauche
int motor1Pin2 = 4;    // avancer gauche 
int motor2Pin4 = 5;    //avancez droite
int motor2Pin3 = 6;     //reculer droite
int enablePin = 9;     // pin 1 (Enable 1) du L293D
int enablePin2 = 10;

void setup() {
  // set all the other pins you're using as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin3, OUTPUT);
  pinMode(motor2Pin4, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // Mettre la broche Enable a high comme ca le moteur tourne
  digitalWrite(enablePin, HIGH);
  digitalWrite(enablePin2, HIGH);
}

void loop() {
  reculerdroite();
}
void avancer(){
  // Le moteur tourne dans un sens 
  digitalWrite(motor1Pin1, LOW);   // mettre pin 2 a 293D low
  digitalWrite(motor1Pin2, HIGH);  // mettre pin 7 a L293D high
  digitalWrite(motor2Pin3, LOW);   
  digitalWrite(motor2Pin4, HIGH);
 
  delay( 3000 ); // Attendre 3 secondes 
}
void reculer(){
   //Le moteur tourne dans l'autre sens 
  digitalWrite(motor1Pin1, HIGH);  // Mettre pin 2 a L293D high
  digitalWrite(motor1Pin2, LOW);   // Mettre pin 7 a L293D low
  digitalWrite(motor2Pin3, HIGH);   
  digitalWrite(motor2Pin4, LOW);
  
 // delay( 3000 ); // Attendre 3 secondes 
}
void avancergauche(){
   //Le moteur tourne dans l'autre sens 
  digitalWrite(motor1Pin1, LOW);  // Mettre pin 2 a L293D high
  digitalWrite(motor1Pin2, LOW);   // Mettre pin 7 a L293D low
  digitalWrite(motor2Pin3, LOW);   
  digitalWrite(motor2Pin4, HIGH);
}
void avancerdroite(){
   //Le moteur tourne dans l'autre sens 
  digitalWrite(motor1Pin1, LOW);  // Mettre pin 2 a L293D high
  digitalWrite(motor1Pin2, HIGH);   // Mettre pin 7 a L293D low
  digitalWrite(motor2Pin3, LOW);   
  digitalWrite(motor2Pin4, LOW);
}
void reculerdroite(){
   //Le moteur tourne dans l'autre sens 
  digitalWrite(motor1Pin1, HIGH);  // Mettre pin 2 a L293D high
  digitalWrite(motor1Pin2, LOW);   // Mettre pin 7 a L293D low
  digitalWrite(motor2Pin3, LOW);   
  digitalWrite(motor2Pin4, LOW);
}
void reculergauche(){
   //Le moteur tourne dans l'autre sens 
  digitalWrite(motor1Pin1, LOW);  // Mettre pin 2 a L293D high
  digitalWrite(motor1Pin2, LOW);   // Mettre pin 7 a L293D low
  digitalWrite(motor2Pin3, HIGH);   
  digitalWrite(motor2Pin4, LOW);
}
