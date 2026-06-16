
#include <Arduino.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <WiFi.h>
#include <SpotifyEsp32.h>
#include <SPI.h>

char* SSID = "FW Wifi-5.0";
char* PASSWORD = "p0p1921SeWa";

const char* CLIENT_ID = "d91698a862304c12beee5d3650429125";
const char* CLIENT_SECRET = "605fda655e46437bbb42835d4a16de0d";

#define TFT_CS 0
#define TFT_RST 1
#define TFT_DC 2
#define TFT_SCLK 3
#define TFT_MOSI 4

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


void setup() {
 Serial.begin(115200);

    Serial.print("."); 
}
Serial.printf("\nConnected!\n"); 

tft.initR(INITR_BLACKTAB); 
tft.setRotation(1); 
Serial.println("TFT Initialized!");
tft.fillScreen(ST77XX_BLACK); 

//wifi setup

WiFi.begin(SSID, PASSWORD); // Attempt to connect to wifi
Serial.print("Connecting to WiFi..."); 
while(WiFi.status() != WL_CONNECTED) 


tft.setCursor(0,0); 
tft.write(WiFi.localIP().toString().c_str()); 
}

void loop() {
 yttops.begin();
while(yttops.is_auth())
{
    yttops.handle_client();
}
Serial.println("Connected to Spotify!");
delay(1000);

yttops.current_artist_names(); 
yttops.current_track_name();   
yttops.start_resume_playback(); 
yttops.skip();                  
yttops.previous();           
yttops.is_playing(); 
yttops.volume_up();
yttops.volume_down();

tft.write("Music"); 
tft.setCursor(160,128);        /
tft.fillScreen(ST77XX_COLOR); // most of the main colors are here!
tft.drawRect(Cursorx, Cursory, RectWidth, RectHeight, ST77XX_color); // draws a rectangle
tft.fillRect(Cursorx, Cursory, RectWidth, RectHeight, ST77XX_color); // fills in a rectangle
tft.setTextSize(5);  
         
