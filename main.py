import wmi
import serial 
import time

# Initialising the vars
cpu_temp = 0
cpu_usage = 0
gpu_temp = 0
gpu_usage = 0
ram_usage = 0

arduino = serial.Serial(port='COM3', baudrate=115200, timeout=.1) 

w = wmi.WMI(namespace=r"root\OpenHardwareMonitor")

while True:
    infos = w.Sensor()
    for sensor in infos:
        # Temps
        if sensor.SensorType == "Temperature":
            if sensor.Name == "GPU Core":
                gpu_temp = round(sensor.Value)
            elif sensor.Name == "CPU Package":
                cpu_temp = round(sensor.Value)

        # Loads
        if sensor.SensorType == "Load":
            if sensor.Name == "CPU Total":
                cpu_usage = round(sensor.Value)
            elif sensor.Name == "GPU Core":
                gpu_usage = round(sensor.Value)
            elif sensor.Name == "Memory":
                ram_usage = round(sensor.Value)

    data = f"{cpu_usage},{cpu_temp},{gpu_usage},{gpu_temp},{ram_usage}\n"
    arduino.write(data.encode())
    
    # Delay
    time.sleep(1.5)

arduino.close()
