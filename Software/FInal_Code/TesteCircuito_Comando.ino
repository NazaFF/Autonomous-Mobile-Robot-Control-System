// Arduino NEC Protocol IR remote control decoder 

#include <NewPing.h>

char text[5];
boolean nec_ok = 0;
byte  i, nec_state = 0, command, inv_command;
unsigned int address;
unsigned long nec_code;
unsigned long distancia;


int type_mov =0;  //se estado é  detetar obstaculos(2) ou luz(1)
boolean mov = false;  //se esta a andar ou parado

//MOTORES
#include <AFMotor.h> 

AF_DCMotor motor1 (1);
AF_DCMotor motor2 (2); 


//SL
float vL,vR, NormalLight=100;              //Nivel luz ambiente
#define dL  A0
#define dR  A1

//US
#define TRIGGER_PIN  13   // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     13   // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

#define command_front 8    //2  
#define command_back  104  //8
#define command_right 40  //6
#define command_left  72  //4
#define command_menu  4   //TXT
#define command_startstop 64  //vermelho
#define command_searchlight 144   //1
#define command_us 136         //3
#define command_stop  152    //0



NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

//FUNÇÕES-----------
int velocidade=80;                //Velocidade por defeito

//IR EM FRENTE
void Front(int velocidade){ //os dois motores tem que arrancar e entra a velocidade
  Serial.println("Front ..... ");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  
  motor1.setSpeed(velocidade);  
  motor2.setSpeed(velocidade);

}

//ANDAR PARA TRAS
void Back(int velocidade){ //os dois motores tem que arrancar e entra a velocidade
   Serial.print("Back ..... ");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);  

  motor1.setSpeed(velocidade);  
  motor2.setSpeed(velocidade);

}

//TURN RIGHT
void TurnRight(int velocidade){ //RODAR PARA A DIREITA

Serial.println("Turn Right ..... ");

  motor1.run(BACKWARD); // Motor 1 anda no sentido inverso do motor 2
  motor2.run(FORWARD);  // Girar robo para a direita

  motor1.setSpeed(velocidade);
  motor2.setSpeed(velocidade);
}

//TURN LEFT
void TurnLeft(int velocidade){  //RODAR PARA A ESQUERDA 


 Serial.println("Turn Left ..... ");

  motor1.run(FORWARD); // Motor 1 anda no sentido inverso do motor 2
  motor2.run(BACKWARD);  // Girar robo para a esquerda

  motor1.setSpeed(velocidade);
  motor2.setSpeed(velocidade);
  

}

//PARAR
void STOP(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
 Serial.println("STOP ..... ");
}

//PROCURAR LUZ

void SearchLight(int velocidade, int NormalLight){  //se encontrar osbstaculos para, se nao segue em frente ou procura luz
  vL = analogRead(dL);
  vR = analogRead(dR);
  Serial.print("SearchLight ..... ");
  if((vR+vL)>NormalLight &&(vR-vL)<-5){
    if(sonar.ping_cm()< 10 ){
    Back(50);
    }
    else
    TurnLeft(velocidade);
    
  }
  else if((vR+vL)>NormalLight &&(vR-vL)>5){
        
          if(sonar.ping_cm()< 10 ){
            Back(50);
         }
         else
         TurnRight(velocidade);
        
       }
  else if ((vR+vL)>NormalLight && abs(vR-vL)<=5){
          if(sonar.ping_cm()<10){
            Back(50);
         }
         else
          Front(sonar.ping_cm());
          
       }
       else
        Girar();
}

//RODAR SOBRE SI PROPRIO
void Girar(){

    motor1.run(FORWARD);  // Girar motor3 para a esquerda
    motor2.run(BACKWARD);  // Motor 1 anda no sentido inverso do motor 2
    motor1.setSpeed(velocidade);
    motor2.setSpeed(velocidade);
    Serial.println("Girar..... ");
      if(sonar.ping_cm() <10){
      Back(50);
      }
}

//EVITAR OBSTÁCULOS
void DetectObstacles(int min_dist){
  if(sonar.ping_cm() >= min_dist) //se ele se encontrar a menos de 10 cm do obstaculo para 
     Front(sonar.ping_cm());
     else
     Girar();
     Serial.print("Detects Obstacles ..... ");
   
} 

int ReadCommnand(){     // Function Read the remote command 
  if(nec_ok){                                    
    // If the mcu receives NEC message with successful
    nec_ok = 0;                                  // Reset decoding process
    nec_state = 0;
    TCCR1B = 0;                                  // Disable Timer1 module
                                                 // Define: address = nec_code >> 16;
    command = nec_code >> 8;                     // Define: inv_command = nec_code;
    Serial.print("Command: ");
    Serial.println(command);
    attachInterrupt(0, remote_read, CHANGE);     // Enable external interrupt (INT0)
  }
  return command;
}

void selectmenu(){ 

  Serial.println(" ");
  Serial.println(" ");
Serial.println("**SELECT MENU ***");
Serial.println("Arranque/Paragem, Press (start red)");
Serial.println("Front, Press 2 ");
Serial.println("Back, Press 8 ");
Serial.println("Turn Left, Press 4 ");
Serial.println("Turn Right, Press 6 ");
Serial.println("Stop, Press 0)");
Serial.println("For light search,  Press 1 ");
Serial.println("For obstacles deviation,  Press 3 ");
Serial.println("For comand intruction,  Press TXT "); 

}

void setup() {
 
  Serial.begin(9600);
  Serial.println("Acabadinho de entrar...");
  // Timer1 module configuration
  TCCR1A = 0;
  TCCR1B = 0;                                    // Disable Timer1 module
  TCNT1  = 0;                                    // Set Timer1 preload value to 0 (reset)
  TIMSK1 = 1;                                    // enable Timer1 overflow interrupt
  attachInterrupt(digitalPinToInterrupt(2), remote_read, CHANGE);       // Enable external interrupt (INT0)
  
}


void loop() {

  // Read the remote command 
 if(nec_ok){                                    
    // If the mcu receives NEC message with successful
    nec_ok = 0;                                  // Reset decoding process
    nec_state = 0;
    TCCR1B = 0;                                  // Disable Timer1 module
                                                 // Define: address = nec_code >> 16;
    command = nec_code >> 8;                     // Define: inv_command = nec_code;
    Serial.print("Command: ");
    Serial.println(command);
    attachInterrupt(0, remote_read, CHANGE);     // Enable external interrupt (INT0)
  }


   delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm"); //AJUSTAR
  // Serial.println((sonar.ping_cm()-3)*(sonar.ping_cm()-3));

  // Read the light sensor (photodiodes)
  vL = analogRead(dL);
  vR = analogRead(dR);
  Serial.print("Light Left: ");
  Serial.print(vL);
 Serial.print("       Light Right: "); 
 Serial.println(vR);
 
if (command ==command_menu ){  //colocar codigo comando correspondente à tecla menu 
    selectmenu();
    do{
     command= ReadCommnand();
      }while (!nec_ok);
   }
 
if(command == command_front ){
 Front(velocidade);
  
 }

if(command == command_back ){
 Back(velocidade);

 }

if(command == command_right ){
 TurnRight(velocidade);
  
 } 

if(command == command_left ){
 TurnLeft(velocidade);
  
 } 

if(command == command_stop ){
 STOP();
 mov = false;
 
 } 

if (command == command_searchlight ){
 SearchLight(velocidade, NormalLight);
 type_mov=1;
 mov = true;
 
 } 

if (command == command_us ){
DetectObstacles(5);
type_mov =2;
mov=true;

 } 
if(command == command_startstop){
  if( mov){
  STOP();
  
  mov = false;
  command=0;
  }
  else{
    if(type_mov ==1){
    SearchLight(velocidade, NormalLight);
    mov=true;
    command=0;
    
    }
    if(type_mov ==2)
    DetectObstacles(5);
     mov=true;
     command=0;
  }
  
}
delay(1000);

}