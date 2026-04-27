// 1. Librerías (Líneas 1-7)
#include <Arduino.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <WiFi.h>
#include <SpotifyEsp32.h>
#include <SPI.h>

// 2. Credenciales
char* SSID = "Familia Arevalo 2.4";
char* PASSWORD = "nelson2024";
const char* CLIENT_ID = "5d0175a9c264474e8aee0cfa8c4e600a";
const char* CLIENT_SECRET = "372dda800c834c0ab075fc2ed0714756";

// 3. Configuración de Pantalla (Poner esto AQUÍ ARRIBA)
#define TFT_CS     1
#define TFT_RST    2
#define TFT_DC     3
#define TFT_SCLK   4
#define TFT_MOSI   5

// 4. Creación de Objetos
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
Spotify sp(CLIENT_ID, CLIENT_SECRET);
void setup() {
  Serial.begin(115200);

  // 1. PRIMERO: Iniciamos la pantalla (Lo nuevo)
  tft.initR(INITR_BLACKTAB);      
  tft.setRotation(1);             
  tft.fillScreen(ST77XX_BLACK);   
  Serial.println("TFT Initialized!");

  // 2. SEGUNDO: Conectamos el Wi-Fi (Lo que ya tenías)
  WiFi.begin(SSID, PASSWORD);
  Serial.print("Connecting to WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    // Opcional: podrías poner tft.print(".") para ver los puntos en la pantalla también
  }
  
  Serial.printf("\nConnected!\n");

  // 3. TERCERO: Mostramos la IP en la pantalla (Lo nuevo de la guía)
  tft.setCursor(0, 0);            
  tft.setTextColor(ST77XX_WHITE); 
  tft.setTextSize(1);             
  tft.write(WiFi.localIP().toString().c_str()); 

  // 4. CUARTO: Conectamos a Spotify (Lo que ya tenías)
  sp.begin();
  while(!sp.is_auth()) {
    sp.handle_client();
  }
  Serial.println("Connected to Spotify!");
}

void loop() {
  // 1. Manejar la conexión de Spotify (mantiene la sesión viva)
  sp.handle_client();

  // 2. Si hay música sonando, actualizamos la pantalla
  if (sp.is_playing()) {
    // Guardamos la info en variables tipo String
    String cancion = sp.current_track_name();
    String artista = sp.current_artist_names();

    tft.fillScreen(ST77XX_BLACK); // Limpiamos pantalla
    
    // --- IMPRIMIR CANCIÓN ---
    tft.setCursor(10, 20);
    tft.setTextSize(2);
    tft.setTextColor(ST77XX_GREEN);
    // Aplicamos lo de la imagen: variable.c_str()
    tft.write(cancion.c_str()); 

    // --- IMPRIMIR ARTISTA ---
    tft.setCursor(10, 60);
    tft.setTextSize(1);
    tft.setTextColor(ST77XX_WHITE);
    // Aplicamos lo de la imagen: variable.c_str()
    tft.write(artista.c_str());

  } else {
    // Si no hay nada sonando
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(10, 50);
    tft.write("Spotify en pausa...");
  }

  // El delay para no saturar la conexión (Rate limit)
  delay(2000);
}
