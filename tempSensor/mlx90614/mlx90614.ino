/*************************************************** 
  This is a library example for the MLX90614 Temp Sensor

  Designed specifically to work with the MLX90614 sensors in the
  adafruit shop
  ----> https://www.adafruit.com/products/1747 3V version
  ----> https://www.adafruit.com/products/1748 5V version

  These sensors use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  
  pinMode(4, INPUT);
  pinMode(5, OUTPUT); 
  Serial.println("Adafruit MLX90614 test");  

  mlx.begin(4,5);  
}

double* getTemps(){
  double* result = (double*)malloc(2*sizeof(double));
  
  result[0] = mlx.readAmbientTempC();
  result[1] = mlx.readObjectTempC();
  return result;  
}

void loop() {
  double* temps = getTemps();
  
  Serial.print("Ambient = "); Serial.print(temps[0]); 
  Serial.print("*C\tObject = "); Serial.print(temps[1]); Serial.println("*C");
  delete[] temps;
  Serial.println();
  delay(500);
}
