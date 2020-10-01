//Libraries
#include <DHT.h>;

// Which digital I/O pin being used to recieve the data
#define DHTPIN 8        

// Specifying which DHT sensor is being used (Two versions DHT_11 | DHT_22)
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE); 

int chk;

//Stores humidity value
float hum;  

//Stores temperature value
float temp; 

void setup()
{
  Serial.begin(115200);
  dht.begin();

}

void loop()
{
  // Reads both humidity and temperature data from DHT_22
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  // Prints out values to Serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  
  delay(2000); 
