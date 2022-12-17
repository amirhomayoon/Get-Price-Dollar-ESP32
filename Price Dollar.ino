#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid     = "wireless";
const char* password = "123456";

void setup()
{
    Serial.begin(115200);
    delay(10);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
  
}

void loop()
{
if(WiFi.status() == WL_CONNECTED)
{
HTTPClient client;
client.begin("https://api.navasan.tech/latest/?api_key=freeIPmh6WH3kEeC7pnrEirZlmT9tp7z");

  String result=client.getString();
   Serial.println("Gheymat Dollar:"+String(result));

}
else{
   Serial.println("Server Lost");
}
  delay(5000);
}

