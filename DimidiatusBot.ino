//Motor 1
//D0 16 enable
//D1 05 in 1
//D2 04 in 2
//Motor 2
//D5 14 enable
//D3 00 in 1
//D4 02 in 2
//Esta libreria maneja puerto bluetooth
#include <SoftwareSerial.h>
//Inicializo conexion bluetooth
SoftwareSerial ss(13,15);//RX, Tx
char dato = 'x';

int motor1Enable = 16;
int motor1pin1 = 5;
int motor1pin2 = 4;

int motor2Enable = 14;
//Este 0 tal vez ponga problema pues es un puerto flash
int motor2pin1 = 0;
int motor2pin2 = 2;

void setup()  
{
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor1Enable,OUTPUT);

  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor2Enable,OUTPUT);
  //Inicializando velocidad del puerto usb
  Serial.begin(115200);
  //Inicializando velocidad del puerto bluetoth
  ss.begin(9600);
}

void loop() 
{
  smartdelay(100);
  accion(dato);
  ss.println(dato);
  ss.println("hola");
  Serial.println("Hola pc");
  Serial.println(dato);
  delay(1000);
}
//Depende de como conectes los cables de los motores
static void accion (char opcion)
{
    if(opcion == 'a')
    {
        
      Serial.println("avanzar");
      digitalWrite(motor1Enable, HIGH);
      digitalWrite(motor2Enable, HIGH);
      
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    
    }
    else if(opcion =='r')
    {
    
        
      Serial.println("retroceder");
      digitalWrite(motor1Enable, HIGH);
      digitalWrite(motor2Enable, HIGH);
      
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);  
      
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);  
    }
    else if(opcion =='i')
    { //Suponiendo que el motor1 es el de la derecha
     
        
      Serial.println("izquierda");
      digitalWrite(motor1Enable, HIGH);
      digitalWrite(motor2Enable, HIGH);
      
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);

      
      
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
    }
    else if(opcion =='d')
    {
      
      Serial.println("derecha");
      digitalWrite(motor1Enable, HIGH);
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
        
      digitalWrite(motor2Enable, HIGH);
      
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    }
    else if(opcion =='s')
    {
      Serial.println("stop");
      digitalWrite(motor1Enable, LOW);
      digitalWrite(motor2Enable, LOW);
    }
}
static void smartdelay(unsigned long ms)
{
//start = hora actual
  unsigned long start = millis();
    do{
      while(ss.available())
        dato = ss.read();
      }while(millis() - start < ms);
}
