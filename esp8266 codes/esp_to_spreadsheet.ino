#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#define WIFI_SSID "roop"
#define WIFI_PASSWORD "roop@1234"
ESP8266WiFiMulti wifiMulti;
const char* ssid = "roop";
const char* password = "roop@1234";
const char* host = "script.google.com"; 
const char* fingerprint = "89 ff f4 0f 4d 98 09 ed e3 ef 95 f2 8a af af 22 89 08 ac 03";
const int httpsPort = 443;
String script_id = "AKfycbz27CWC8bz1eHo9bua4FUKBKjgwVBcWXjbuEHV4uzaDI8aAGSw";
String url;
int touch = 5;
int Relay = 16;

void setup() 
{
  pinMode(touch,INPUT);
  pinMode(Relay,OUTPUT);
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
}
int val=0;
int count=0;
String x = "on";
void loop() {
  // put your main code here, to run repeatedly:
  
//String s = "aj";
//data(s);
val = digitalRead(touch);
if(val == 1)
{
count++;  
}
if(val==1)
 {
  if(count%2 == 0)
   { 
    
    digitalWrite(Relay,HIGH);
  
    
     x = "off";
     
     Serial.println(x);
     data(x);
    
   }
   else
   {
    digitalWrite(Relay,LOW);
   
    x = "on";
    
    Serial.println(x);
    data(x);
    //Serial.println("on");
    
   }  
 }
 delay(500);
 
  //delay(2000);
}

void data(String d)
{
Serial.print("connecting to ");
  Serial.println(host);
 
  WiFiClient client;

  const int httpPort = 443;
  if (!client.connect(host, httpPort)) 
  {
    Serial.println("connection failed");
    return;
  }

  int t = 1;
  /*url = "/macros/s/AKfycbwDmzcNDYlI9E1tBQI0KZ0h71Knq42AGNj_jjaALD-37qrbhk3X/exec?func=addData&val="+ String(d);
  url = "/macros/s/AKfycbwvjixzPPVjBqFRxv5DjHzUssWDpf3NSbfmtQH-yPq_PUsJE31A/exec?func=addData&val="+ String(d);
  url = "/macros/s/AKfycbz27CWC8bz1eHo9bua4FUKBKjgwVBcWXjbuEHV4uzaDI8aAGSw/exec?func=addData&val="+ String(d); */

  url = "/macros/s/AKfycbwvjixzPPVjBqFRxv5DjHzUssWDpf3NSbfmtQH-yPq_PUsJE31A/exec?func=addData&val="+ String(d);
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  String section="header";
  while(client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();
  Serial.println("closing connection");
  //delay(6000);

}
