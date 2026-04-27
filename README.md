#  Displaify - Spotify Desktop Controller

A custom IoT desktop device powered by an ESP32-C3 to control and display Spotify metadata. This project features a 1.8" TFT screen and 6 mechanical switches for tactile control, housed in a custom-designed 3D printed enclosure.

##  Features
- **Real-time Display:** Shows song title and artist.
- **6 Tactile Controls:** Play/Pause, Next Track, Previous Track, Volume Up, Volume Down, and Mute (Unlike the standard 3-button design).
- **Custom Enclosure:** Ergonomic design for desk use with an updated layout for 6 switches.
- **IoT Connection:** Connects via WiFi to the Spotify API.

##  Components & Bill of Materials (BOM)
| Component | Purpose | Link |
| --- | --- | --- |
| ESP32-C3 SuperMini | Brain, WiFi & connectivity | [Aliexpress](https://es.aliexpress.com/item/1005007446721319.html) |
| 1.8" TFT ST7735 SPI | Visual display for track info | [Aliexpress](https://es.aliexpress.com/item/1005010626780549.html) |
| Outemu Mechanical Switches | 6 Tactile input controls | [Aliexpress](https://es.aliexpress.com/item/1005006396423418.html) |
| 24 AWG Silicone Wire | Internal connections | [Aliexpress](https://es.aliexpress.com/item/1005009017260144.html) |

##  Wiring Diagram & Pinout
The following pin configuration will be used for the final assembly.

### Screen (ST7735 SPI)
- **VCC:** 3.3V
- **GND:** GND
- **SDA/MOSI:** GPIO 10
- **SCK/SCL:** GPIO 8
- **RES:** GPIO 3
- **D/C:** GPIO 2
- **CS:** GPIO 7

### Buttons (Mechanical Switches)
- **Play/Pause:** GPIO 0
- **Next Track:** GPIO 1
- **Previous:** GPIO 4
- **Volume Up:** GPIO 5
- **Volume Down:** GPIO 6
- **Mute:** GPIO 20
*(One pin of each switch to the listed GPIO, and the other pin common to GND)*

##  Project Files
- `/cad`: Includes `.step` and `.f3z` files for the 6-button enclosure.
- `/firmware`: Project source code (work in progress).
- `bom.csv`: Detailed parts list.
