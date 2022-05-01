#include <Arduino.h>

#include <WiFi.h>
 
const char* ssid     = "Akhil";
const char* password = "akhil20166";
 
WiFiServer server(80);
 
void setup()
{
    Serial.begin(115200);
    pinMode(2, OUTPUT);      // set the LED pin mode
 
    delay(10);
 
    // We start by connecting to a WiFi network
 
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
 
    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
 
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();
 
}
 
int value = 0;
 
void loop(){
 WiFiClient client = server.available();   // listen for incoming clients
 
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
 
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
 
            // the content of the HTTP response follows the header:
            // client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 2 on.<br>");
            // client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 2 off.<br>");
            client.print("A = 0, B = 0, C= 0 | Out = 1 | Click <a href=\"/0\">here</a> <br>");
            client.print("A = 0, B = 0, C= 1 | Out = 0 | Click <a href=\"/1\">here</a> <br>");
            client.print("A = 0, B = 1, C= 0 | Out = 1 | Click <a href=\"/2\">here</a> <br>");
            client.print("A = 0, B = 1, C= 1 | Out = 0 | Click <a href=\"/3\">here</a> <br>");
            client.print("A = 1, B = 0, C= 0 | Out = 1 | Click <a href=\"/4\">here</a> <br>");
            client.print("A = 1, B = 0, C= 1 | Out = 0 | Click <a href=\"/5\">here</a> <br>");
            client.print("A = 1, B = 1, C= 0 | Out = 0 | Click <a href=\"/6\">here</a> <br>");
            client.print("A = 1, B = 1, C= 1 | Out = 1 | Click <a href=\"/7\">here</a> <br>");
 
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
 
        if (currentLine.endsWith("GET /0")) {
          digitalWrite(2, HIGH);               
        }
        if (currentLine.endsWith("GET /1")) {
          digitalWrite(2, LOW);                
        }
        if (currentLine.endsWith("GET /2")) {
          digitalWrite(2, HIGH);                 
        }
        if (currentLine.endsWith("GET /3")) {
          digitalWrite(2, LOW);                
        }
        if (currentLine.endsWith("GET /4")) {
          digitalWrite(2, HIGH);                
        }
        if (currentLine.endsWith("GET /5")) {
          digitalWrite(2, LOW);               
        }
        if (currentLine.endsWith("GET /6")) {
          digitalWrite(2, LOW);               
        }
        if (currentLine.endsWith("GET /7")) {
          digitalWrite(2, HIGH);               
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}