# DHT_22 With Dual 1.3 OLED Displays

![IMG_6136](https://user-images.githubusercontent.com/39348633/90320318-cf103d80-df05-11ea-9c90-ea1f69b4785b.jpeg)


## __=== Overall goal of this project ===__
* Display the temperature and humidity readings to both OLED displays
* Provide additional documentation so that others can use two OLED displays at the same time in their own projects

### Please keep in mind

In this repository Visual Studio code and the Platform IO extension was used.

If you do NOT want to go through the hassel of setting both VS Code and Platform IO up 
* Click on the 'SRC' folder to find the source code for this project
* Comment out the '#include <Arduino.h>' header
* Then copy and paste the code to your favorite text editor (To include the Arduino IDE)

---


## __=== Items used ===__
1. Two 1.3 OLED displays
2. A single DHT_22 sensor
3. A handful of jumper wires
4. An Arduino UNO


---


## __=== Information about the OLED Displays ===__

 1. Both OLED displays have the SH1106 driver instead of the more common SH1306 driver that's found on smaller OLED displays
 2. Both communicate with the UNO via I2C to make things easier as far as the wiring goes.
 3. They can also be found on Amazon via [link](https://www.amazon.com/Display-Serial-Arduino-Raspberry-DIYmall/dp/B073VD6W1H/ref=sr_1_2?dchild=1&keywords=OLED+1.3&qid=1597520686&sr=8-2)
 
 
 ---


### __IMPORTANT NOTE__

To ensure that both OLED displays are

1. Connected correctly
2. Have different HEX addresses

The following [.ino/Arduino sketch](https://gist.github.com/tfeldmann/5411375) can be uploaded to the UNO or whatever Arduino board you're using. 

Make sure the baud rate (9600) in the serial monitor matches the one being used in the sketch to avoid getting "garbage" values in the serial monitor


---


## __=== Establishing different HEX addresses with OLED displays ===__

![IMG_6132](https://user-images.githubusercontent.com/39348633/90320991-793e9400-df0b-11ea-9195-6a3c8d232c11.jpeg)

On the back of both displays is a 'section' called ADD_SELECT which dictates if the display has either has 0x3C or 0x3D for their HEX address when using the [I2C Scanner](https://gist.github.com/tfeldmann/5411375)

The next step involves taking a soldering station and de-soldering the SMD resistor that's on the 0x78 side and just solder the 'middle point' to the 0x7A side as shown in the pictures below.

## __================== Before ==================__
![InkedIMG_6134_LI](https://user-images.githubusercontent.com/39348633/90321155-b0617500-df0c-11ea-8626-f8130f7e4b43.jpg)


## __================== After ==================__
![InkedIMG_6133_LI](https://user-images.githubusercontent.com/39348633/90321168-d2f38e00-df0c-11ea-9c56-1d7ebb87514f.jpg)

I'm not entirely if the HEX addresses would change if you were to take a pliers and just physically rip out the SMD resistor, but I'm assuming not.

Once again, to ensure the displays have different HEX addresses, the [I2C Scanner](https://gist.github.com/tfeldmann/5411375) can be used.

---


## __=== Wiring Diagram ===__

Since using a hardware diagram generator like Fritzing is frowned upon, I generated the diagram below with Autodesk EAGLE.

[WHICH IS FREE BTW](https://www.autodesk.com/products/eagle/free-download?plc=F360&term=1-YEAR&support=ADVANCED&quantity=1)

Here's a visual representation of how I wired everything up.

![image](https://user-images.githubusercontent.com/39348633/90321510-13a0d680-df10-11ea-8084-7ee9fb36aa56.png)

If the diagram was confusing to follow, here's an in-depth explantion of what I did.
1. VDD                  --> 5 Volts
2. All GNDs             --> Single ground point on UNO
3. SCL                  --> A5
4. SDA                  --> A4
5. Singal out on DHT_22 --> Digital I/0 Pin 8

---


## __=== IMPORTANT STUFF ===__

* To prevent any text from overlapping, or the OLED displays from flickering, the sendBuffer() adn clearBuffer() function calls must be 'paired' with one another or you're gonna have a bad time yo.
* If you're using either an UNO or Nano board, using two OLED displays __WILL__ eat up most of the on board memory. With this code alone I was using ~96% of the memory
* The U8g2lib.h library (From my understanding...) only deals with Character arrays.
  * The dtostrf() function __MUST__ be used to display the data.
  
# That's it for now!
  
Revisions to this repo will be made later this week if nessessary.
