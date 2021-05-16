

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "minor-project-ad4e3.firebaseio.com"
#define FIREBASE_AUTH "TCWhfiKPcnsr0ZjVKKHITOEpYqkc4Vy3ERC8YSya"
#define WIFI_SSID "roop"
#define WIFI_PASSWORD "roop@1234"
//#define LED 2
int touchPin = 5;
int relayPin = 16;
int val = 0;
int lightON = 0;
int touched = 0;
String old_stat = "off";
int count=0;
void setup() {
pinMode(touchPin, INPUT); 
//pinMode(LED,OUTPUT);
pinMode(relayPin, OUTPUT);
//digitalWrite(LED,0);
Serial.begin(9600);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);

}

Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
//Firebase.setInt("LEDStatus",0);

}

void loop() {
//val = digitalRead(touchPin);
String x = Firebase.getString("mystatus");
Serial.println(x);
/*digitalWrite(relayPin, HIGH);   //Turn off relay 
delay(1000); 
digitalWrite(relayPin, LOW);    //Turn on relay */
         
/*if(val == 1)
{
count++;
}
if(val==1)
{
 if(count%2 ==0)
 {
  digitalWrite(relayPin,HIGH); 
  Serial.println("off");
  old_stat = "off";
 }
 else
 {
  
  digitalWrite(relayPin,LOW); 
  Serial.println("on");
  old_stat = "on";
 }
}*/

/*if(x!=old_stat)
{
  if(x=="off")
  {
    digitalWrite(relayPin,HIGH); 
    Serial.println("off");
    old_stat = "off";
  }
  else if(x=="on")
  {
    digitalWrite(relayPin,LOW); 
    Serial.println("on");
    old_stat = "on";
    
  }

}*/
/*if((val == HIGH or x == "off")  && lightON == LOW){

    touched = 1-touched;
    delay(100);
  } 
  lightON = val;

      if(touched == HIGH){
        Serial.println("Light ON");
        digitalWrite(relayPin, LOW); 
        Serial.println(x);
       
       
      }
      else{
        Serial.println("Light OFF");
        digitalWrite(relayPin, HIGH);
        Serial.println(x);
   
      }*/ 

if( x == "on")
{
  digitalWrite(relayPin, LOW);
}
else
{
  digitalWrite(relayPin, HIGH);
}
if (Firebase.failed()) // Check for errors 
Serial.print("setting /number failed:");
Serial.println(Firebase.error());
return;
delay(1000);

}
