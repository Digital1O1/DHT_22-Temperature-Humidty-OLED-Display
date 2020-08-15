# DHT_22 With Dual 1.3 OLED Displays

Both OLED displays used in this project are using I2C to communicate with the Arduino Uno. 

The main reason(s) why I2C was chosen over SPI was due to :

1) Less wires to deal with 
2) I2C displays were significantly cheaper over the SPI displays

Since both OLED screens were using the name I2C bus they need seperate hex addresses.

To ensure that both OLED displays were connected correctly and they both have different HEX addresses, the following [.ino/Arduino sketch](https://gist.github.com/tfeldmann/5411375) can be used. 

### _MAKE SURE THE SERIAL MONTIOR'S BUAD RATE IS AT 9600 BEFORE UPLOADING THE SKETCH_ ###

