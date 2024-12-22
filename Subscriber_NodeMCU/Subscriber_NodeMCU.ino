//AIO_KEY is hidden and commented in this code

float o=99.0;
float b=80.0;

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// the on off button feed turns this LED on/off
#define LED 2  
// the slider feed sets the PWM output of this pin
#define PWMOUT 12

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "Redmi Note 13 5G"
#define WLAN_PASS       "diptadeepray"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "*********"
//#define AIO_KEY         "********************************"
                       

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Subscribe ox = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/oxy");
Adafruit_MQTT_Subscribe bp = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/bpm");

/*************************** Sketch Code ************************************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();

void setup() {

  pinMode(D3, OUTPUT);

  Serial.begin(9600);
  delay(10);

  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  // Setup MQTT subscription for onoff & slider feed.
  mqtt.subscribe(&ox);
  mqtt.subscribe(&bp);
}

uint32_t x=0;

void loop() {
  // Ensure the connection to the MQTT server is alive (this will make the first
  // connection and automatically reconnect when disconnected).  See the MQTT_connect
  // function definition further below.
  MQTT_connect();

  // this is our 'wait for incoming subscription packets' busy subloop
  // try to spend your time here

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {

    
    /**if (subscription == &ox) {
      Serial.print(F("Blood Oxygen Saturation Level: "));
      Serial.println((char *)ox.lastread);
      
      if (strcmp((char *)onoffbutton.lastread, "ON") == 0) {
        digitalWrite(D1, HIGH); 
      }
      if (strcmp((char *)onoffbutton.lastread, "OFF") == 0) {
        digitalWrite(D1, LOW); 
      }
    }**/

    
    // check if its the slider feed
    if (subscription == &bp) {
      Serial.print(F("BPM:"));
      Serial.println((char *)bp.lastread);
      uint16_t bpval = atoi((char *)bp.lastread);  // convert to a number

      if (bpval<60||bpval>100)
        {
          digitalWrite(D3, HIGH);
        }
       else
       {
        digitalWrite(D3, LOW);
       }
      
      //analogWrite(PWMOUT, sliderval);
    }
        if (subscription == &ox) {
      Serial.print(F("SpO2:"));
      Serial.println((char *)ox.lastread);
      uint16_t oxval = atoi((char *)ox.lastread);  // convert to a number

      if (oxval<95)
        {
          digitalWrite(D3, HIGH);
        }
       else
       {
        digitalWrite(D3, LOW);
       }
      
      //analogWrite(PWMOUT, sliderval);
    }
  }

  // ping the server to keep the mqtt connection alive
  if(! mqtt.ping()) {
    mqtt.disconnect();
  }

}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
