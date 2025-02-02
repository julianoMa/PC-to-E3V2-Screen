# PC to E3V2 Screen
This project is just researching about the Ender 3 V2 Screen, and see if I can use it as a in-case display

> [!NOTE]
> At the start of this project, I know nothing about the possibilities of it and i'm just gonna write my researches here.

# What's the screen ?
## For the E3V2
The screen comes from the Ender 3 V2, it's a 3D printer. On the chip there's wrote **"T7 2142"**, I find nothing on the web for it.
And there's also the pinout wrote directly on the PCB.
| | | 
|:-------------------------:|:-------------------------:|
|<img width="1604" alt="Screen PCB top" src="https://github.com/user-attachments/assets/2ee539ce-92c4-4fd8-a27c-6a2604dc5382"> | <img width="1604" alt="Screen PCB back" src="https://github.com/user-attachments/assets/898ef961-c82d-41bf-a5f2-5d6007024f0c">
|<img width="1604" alt="The chip" src="https://github.com/user-attachments/assets/2ee68df9-7522-492d-bb6b-5a0fe8812c00">  |  <img width="1604" alt="The pins out" src="https://github.com/user-attachments/assets/ca64f09b-0fd2-4b2a-a2e5-00fe368cc39c">

## Original screen
By disconnecting everything, I have access to the "real" screen, an **"0430A006-I1E1100"**, found for between 4$ and 6$ on the web. I also have access to a diagram of the screen.
| | | 
|:-------------------------:|:-------------------------:|
|<img width="1604" alt="Screen with everything disconnect" src="https://github.com/user-attachments/assets/76830256-e32d-4de2-a458-92b55e295241"> | <img width="1604" alt="Screen's diagram" src="https://github.com/user-attachments/assets/9b071a95-2231-4355-af8a-f308b51dc4b1">

# How?
So, while going into the [Mriscoc Ender 3 V2 screen firmware](https://github.com/mriscoc/Ender3V2S1/), I found out that there's multiple "types" of screens, and mine's a **"TJC display"**
Show at the screenshot below :
![image](https://github.com/user-attachments/assets/53269c4e-a588-4d7c-889e-eedb6d0bc553)

## TJC Editor
I found a [Chinese software](http://wiki.tjc1688.com/download/usart_hmi.html) that can be used for modifying screen's firmware. And it works!
<img alt="Screen successfuly modified" src="https://github.com/user-attachments/assets/6fac98b9-dfc2-42c3-8465-9b8d03c8cf8d">


I managed to do something a bit good looking, and displaying static infos using an **Arduino UNO** and some code.
```C
#include <SoftwareSerial.h>
SoftwareSerial tjcSerial(10, 11); // RX, TX

void setup() {
  Serial.begin(115200);
  tjcSerial.begin(9600);
  Serial.println("Starting...");
}

void loop() {
  Serial.println("Sending data to TJC...");

  tjcSerial.print("cpuusage.txt=\"11\"");
  tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);

  tjcSerial.print("cputemp.txt=\"43\"");
  tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);

  tjcSerial.print("gpuusage.txt=\"4\"");
  tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);

  tjcSerial.print("gputemp.txt=\"38\"");
  tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);

  tjcSerial.print("ramusage.txt=\"53\"");
  tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);
  delay(2000);
}
```
| | | 
|:-------------------------:|:-------------------------:|
|<img width="1604" alt="Screen in editor" src="https://github.com/user-attachments/assets/62f98041-e0d8-485c-9eb3-021df946a68b"> | <img width="1604" alt="Static preview" src="https://github.com/user-attachments/assets/ce1253e9-5804-414e-acef-1d3ef407fb90">

