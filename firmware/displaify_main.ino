
#include <Arduino.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <WiFi.h>
#include <SpotifyEsp32.h>
#include <SPI.h>

char* SSID = "Wifi";
char* PASSWORD = "Password";
const char* CLIENT_ID = "YOUR_CLIENT_ID_HERE";
const char* CLIENT_SECRET = "YOUR_CLIENT_SECRET_HERE";


#define TFT_CS     1
#define TFT_RST    2
#define TFT_DC     3
#define TFT_SCLK   4
#define TFT_MOSI   5


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
Spotify sp(CLIENT_ID, CLIENT_SECRET);
void setup() {
  Serial.begin(115200);

  
  tft.initR(INITR_BLACKTAB);      
  tft.setRotation(1);             
  tft.fillScreen(ST77XX_BLACK);   
  Serial.println("TFT Initialized!");


  WiFi.begin(SSID, PASSWORD);
  Serial.print("Connecting to WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
   
  }
  
  Serial.printf("\nConnected!\n");

  tft.setCursor(0, 0);            
  tft.setTextColor(ST77XX_WHITE); 
  tft.setTextSize(1);             
  tft.write(WiFi.localIP().toString().c_str()); 


  sp.begin();
  while(!sp.is_auth()) {
    sp.handle_client();
  }
  Serial.println("Connected to Spotify!");
}

void loop() {

  sp.handle_client();


  if (sp.is_playing()) {
  
    String cancion = sp.current_track_name();
    String artista = sp.current_artist_names();

    tft.fillScreen(ST77XX_BLACK); 
    
    tft.setCursor(10, 20);
    tft.setTextSize(2);
    tft.setTextColor(ST77XX_GREEN);
    tft.write(cancion.c_str()); 

    tft.setCursor(10, 60);
    tft.setTextSize(1);
    tft.setTextColor(ST77XX_WHITE);
    tft.write(artista.c_str());

  } else {
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(10, 50);
    tft.write("Spotify en pausa...");
  }

  delay(2000);
}
