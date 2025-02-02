# PC To E3V2 Screen
This project can help with using the **TJC screen** from the **Ender 3 V2** 3D printer, with the help of an **Arduino**.

<img width="480" height="460" src="https://github.com/user-attachments/assets/188c030d-6571-4167-9d65-a6a3ec662871">

## Requirements
* A **TJC screen**.
* **Arduino** (I'm using the Uno).
* Jumper **wires**.
* **Open Hardware Monitor** (download [here](https://openhardwaremonitor.org/downloads/))
* **Pyserial** (`pip uninstall serial` and then `pip install pyserial`)
* (Optionnal) **Usart HMI** (if you want to edit the screen's text position, or the background image. [Here](http://wiki.tjc1688.com/download/usart_hmi.html))

## Wiring
For the code to work, you need to plug the pins in a specific order :
| Screen | Arduino |
| :---         |          ---: |
| `VCC`   | `5V`    |
| `GND`     | `GND`      |
| `TX`     | `PIN 11`      |

## Installation
First, you need to install **Open Hardware Monitor**, it's required to have it **launched at all time** for the screen to work. So consider putting it in the **Startup folder** of Windows.
Then, simply download the repo, upload the `display.ino` file located in `display/` to the Arduino, and launch the python file. It should come live in about 5 seconds.
