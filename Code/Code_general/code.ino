// capteur distance
const int Trig = 2; // borche trigger
const int Echo = 7; // broche echo
const long TIMEOUT = 25000UL; // definition TIMEOUT 25ms = ~8m à 340m/s
float son = 340.0 / 1000; // vitesse du son dans l'air (mm/µs)
// moteur
int motor1Pin1 = 3;    // reculé gauche
int motor1Pin2 = 4;    // avancer gauche 
int motor2Pin4 = 5;    //avancez droite
int motor2Pin3 = 6;     //reculer droite
int enablePin = 9;     // pin 1 (Enable 1) du L293D
int enablePin2 = 10;
// joystick+servomoteur
#include <Servo.h>
Servo hori;
Servo verti;
 //int joyX = 1;
 //int joyY = 0;
int joyValX;
int joyValY;

void setup() {
// première partie : capteur distance
  pinMode(Trig, OUTPUT); // Configuration des broches d’entrée
  digitalWrite(Trig, LOW); // La broche trigger doit être à LOW au repos
  pinMode(Echo, INPUT); // Configuration des broches de sortie
  Serial.begin(9600);
// deuxième partie : moteur
  // set all the other pins you're using as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin3, OUTPUT);
  pinMode(motor2Pin4, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // Mettre la broche Enable a high comme ca le moteur tourne
  digitalWrite(enablePin, HIGH);
  digitalWrite(enablePin2, HIGH);
// troisième partie : joystick+servomoteur
  hori.attach(10); // broche horizontale
  verti.attach(11); // broche verticale
  Serial.begin(9600);


// capteur distance
void loop(){
  distance();
}
void distance() {
  digitalWrite(Trig, HIGH);  // lance une mesure de distance en envoyant 
  delayMicroseconds(10); //une impulsion HIGH de 10ms sur la broche trigger
  digitalWrite(Trig, LOW);
  int mesure = pulseIn(Echo, HIGH, TIMEOUT); // mesure temps envoi ultrason et reception
  float distance_mm = mesure / 2.0 * son; // calcul de la distance
  if (distance_mm < 100) {
    Serial.print("ATTENTION OBSTACLE À 10CM");
    A completer (polain?)
  }
  
  Serial.print("Distance: "); // affichage des résultats
  Serial.print(distance_mm);
  Serial.println("mm");
  delay(500);
}

// moteur
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

// joystick+servomoteur
void loop(){
  joyValX = analogRead(A1);
  Serial.println(joyValX);
  joyValX = map (joyValX, 0, 1023, 0, 170);
  hori.write(joyValX);
  
  joyValY = analogRead(A0);
  Serial.println(joyValY);
  joyValY = map(joyValY, 0, 1023, 0, 170);
  verti.write(joyValY);
  
  delay(15);
}
