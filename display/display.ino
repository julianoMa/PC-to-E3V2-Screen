#include <SoftwareSerial.h>

SoftwareSerial tjcSerial(10, 11); // RX, TX

String Gpu;
String CpuUsage;
String CpuTemp;
String GpuUsage;
String RamUsage;

void setup() {
  Serial.begin(115200);      
  tjcSerial.begin(9600);     
  Serial.println("Starting...");

  delay(100);
  tjcSerial.print("clearscreen");
  tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n'); 

    int firstComma = data.indexOf(',');
    int secondComma = data.indexOf(',', firstComma + 1);
    int thirdComma = data.indexOf(',', secondComma + 1);
    int fourthComma = data.indexOf(',', thirdComma + 1);

    CpuUsage = data.substring(0, firstComma);
    CpuTemp = data.substring(firstComma + 1, secondComma);
    GpuUsage = data.substring(secondComma + 1, thirdComma);
    Gpu = data.substring(thirdComma + 1, fourthComma);
    RamUsage = data.substring(fourthComma + 1);

    Serial.println("Sending data to TJC...");

    tjcSerial.print("cpuusage.txt=\"" + CpuUsage + "\"");
    tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);

    tjcSerial.print("cputemp.txt=\"" + CpuTemp + "\"");
    tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);

    tjcSerial.print("gpuusage.txt=\"" + GpuUsage + "\"");
    tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);

    tjcSerial.print("gputemp.txt=\"" + Gpu + "\"");
    tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);

    tjcSerial.print("ramusage.txt=\"" + RamUsage + "\"");
    tjcSerial.write(0xFF); tjcSerial.write(0xFF); tjcSerial.write(0xFF);
  }

  delay(1500); 
}
