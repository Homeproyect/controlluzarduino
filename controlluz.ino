#include <Adafruit_Sensor.h>

#include <DHT.h>
  
#include <DHT_U.h>

#define Type DHT11

int dhtpin=2;

DHT HT(dhtpin, Type);

int Humedad;

int Temperatura;

#include <Servo.h>




Servo servoMotor;

char R;

String estado;  

  
void setup()

{

    

        pinMode( 13, OUTPUT );
    
        pinMode( 12, OUTPUT );
    
        pinMode( 11, OUTPUT);
    
        pinMode( 10, OUTPUT );
        
        pinMode( 9, OUTPUT );
        
        pinMode( 8, OUTPUT );
        
        pinMode( 7, OUTPUT );

         pinMode( 6, OUTPUT );
       
       
        servoMotor.attach(6);

          servoMotor.write(90);
        
        Serial.begin(9600);
        
         HT.begin();

}
        
 void loop()
 {

  int rango;
 
        if(Serial.available() > 0)
        { 
  R=Serial.read();
        }

     /*    if( R =='Z')
        {
           servo();

           }*/

           //cambio de rango de temperatura

if(R == 'Y' )
{
rango++; 

delay(30);

  }

  if(R == 'V' )
{
rango--;


  }

  
      
        //cuarto1
      if( R =='A')
        {
            digitalWrite( 13, HIGH  );

           }
            
  if( R =='B')
        {
            digitalWrite( 13 ,LOW);



            
     
       
           
        }  
        
    
      //cuarto2  
        
          if( R=='C')
        {
            digitalWrite( 12 , HIGH);

          
        }
        
        if( R=='D')
        {
            digitalWrite(  12 , LOW);

           
        }
        
        //cuarto3
        
          if( R=='E')
        {
            digitalWrite( 11, HIGH);
        }
        
        if( R=='F')
        {
            digitalWrite( 11 , LOW);
        }
        
        //cosina
        
          if( R=='G')
        {
            digitalWrite( 10, HIGH);
        }
        
        if( R=='J')
        {
            digitalWrite( 10, LOW);
        }
        
        //sala
        
          if( R=='K')
        {
            digitalWrite( 9 , HIGH);
        }
        
        if( R=='M')
        {
            digitalWrite( 9 , LOW);
        }
        
        //baño
        
         if( R=='N')
        {
            digitalWrite( 8 , HIGH);
        }
        
        if( R=='L')
        {
            digitalWrite( 8, LOW);
        }
        
         //exterior
         
            if( R=='O')
        {
            digitalWrite( 7 , HIGH);
        }
        
        if( R=='Q')
        {
            digitalWrite( 7 ,LOW);
        }

Temperatura=HT.readTemperature();

Humedad=HT.readHumidity();

 


        Serial.print(rango);
        Serial.print("°C");
        Serial.println("_");
        Serial.print(Temperatura);
        Serial.print("°C");
        Serial.println("_");
        Serial.print(Humedad);
        Serial.print("%");
        Serial.println("_");
        
             delay(1000);
       
   if( Temperatura >= rango )
        {
            digitalWrite( 6, LOW );

           }            
  if( Temperatura <= rango)
        {
            digitalWrite( 6,HIGH);
    }
  
        }       

 /*       void servo()
        {

          day(30);
          while (Serial.available())
          {
            char c = Serial.read();
          estado += c;
          }
          if (estado.length() > 0)
          {
             servoMotor.write(estado.toInt());
             estado="";
        
          } 
          
          
          }*/
        

         
       
        
        
