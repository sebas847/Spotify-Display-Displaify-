#  Displaify - Spotify Desktop Controller

A custom IoT desktop device powered by an ESP32-C3 to control and display Spotify metadata. This project features a 1.8" TFT screen and 6 mechanical switches for tactile control, housed in a custom-designed 3D printed enclosure.
<img width="1077" height="619" alt="Captura de pantalla 2026-04-26 201929" src="https://github.com/user-attachments/assets/d3142fad-9d45-464e-80fb-282337f5c7fc" />
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
<img width="1256" height="598" alt="image" src="https://github.com/user-attachments/assets/5bfd940a-9d3c-4e73-8da0-73170a13db9c" />


##  Project Files
- `Displaify.step.zip`: Includes `.step` file for the 6-button enclosure.
- `/firmware`: Project source code 
- `bom.csv`: Detailed parts list.
