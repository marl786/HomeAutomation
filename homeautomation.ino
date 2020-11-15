#include<LiquidCrystal.h>
#include <IRremote.h>
const int RECV_PIN=14;
IRrecv irrecv(RECV_PIN);
decode_results results;
#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define Fan 3
#define Light 4
#define TV 6

int i=1,j=1,k=1,n=1;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(Fan, OUTPUT);
  pinMode(Light, OUTPUT);
  pinMode(TV, OUTPUT);

  digitalWrite(Fan, 1);
  digitalWrite(Light, 1);
  digitalWrite(TV, 1);


  
  lcd.print("Home Automation");
  lcd.setCursor(0,1);
  lcd.print("Project by...");
  delay(3000);
  lcd.clear();
  lcd.print("  ALI RAZA");
  delay(3000);
  
  
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fan   Light  TV ");
  lcd.setCursor(0,1);
  lcd.print("OFF    OFF   OFF");
}

void loop() 
{
  if (irrecv.decode(&results) || Serial.available()>0) 
   {
     int data = Serial.read();
     Serial.println(data);
     
     Serial.println(results.value);
     delay(100);
     lcd.setCursor(0,0);
     lcd.print("Fan   Light  TV"); 
     
     
     
     
     
     if (data==49)
     {
      i++;
        int x=i%2;
        digitalWrite(Fan, x);
        lcd.setCursor(0,1);
        if(x)
        lcd.print("OFF ");
        else
        lcd.print("ON  ");
       // delay(200);
      }
     else if(results.value==16728765)
     {
        i++;
        int x=i%2;
        digitalWrite(Fan, x);
        lcd.setCursor(0,1);
        if(x)
        lcd.print("OFF ");
        else
        lcd.print("ON  ");
       // delay(200);
     }
     
     
     
     
     
     
     
     else if (data==50)
     {
      j++;
        int x=j%2;
        digitalWrite(Light, x);
        lcd.setCursor(6,1);
        if(x)
        lcd.print("OFF  ");
        else
        lcd.print("ON   ");
       // delay(200);
      }
    
     else if(results.value==16730805)    //  key 1 

     {
        j++;
        int x=j%2;
        digitalWrite(Light, x);
        lcd.setCursor(6,1);
        if(x)
        lcd.print("OFF  ");
        else
        lcd.print("ON   ");
       // delay(200);
     }

     
   
     
     
     
     
     
     else if (data==51)
     {
      k++;
        int x=k%2;
        digitalWrite(TV, x);
        lcd.setCursor(13,1);
        if(x)
        lcd.print("OFF");
        else
        lcd.print("ON ");
       // delay(200);
      }
     else if(results.value==16732845)
     {
        k++;
        int x=k%2;
        digitalWrite(TV, x);
        lcd.setCursor(13,1);
        if(x)
        lcd.print("OFF");
        else
        lcd.print("ON ");
       // delay(200);
       }
       
        
       else if (data==52)
    {
      n++;
        int x=n%2;
        digitalWrite(TV, x);
        digitalWrite(Fan,x);
        digitalWrite(Light,x);
        lcd.setCursor(0,1);
        if(x)
        lcd.print("OFF    OFF   OFF");
        else
        lcd.print("ON     ON    ON ");
        //delay(200);
      
    } 
        else if(results.value==16753245)
       {
        n++;
        int x=n%2;
        digitalWrite(TV, x);
        digitalWrite(Fan,x);
        digitalWrite(Light,x);
        lcd.setCursor(0,1);
        if(x)
        lcd.print("OFF    OFF   OFF");
        else
        lcd.print("ON     ON    ON ");
        //delay(200);
       }
     irrecv.resume(); // Receive the next value
     //delay(100);
   }
}
