/*
 * A simple programme that will change the intensity of
 * an LED based  * on the amount of light incident on 
 * the photo resistor.
 * 
 */

//PhotoResistor Pin
int lightPin = A0; //the analog pin the photoresistor is 
                  //connected to
                  //the photoresistor is not calibrated to any units so
                  //this is simply a raw sensor value (relative light)
//LED Pin
int ledPinRed = 9;   //the pin the LED is connected to
                  //we are controlling brightness so 
                  //we use one of the PWM (pulse width
                  // modulation pins)
int ledPinGreen = 10;

int readBack;
                  
void setup()
{
  Serial.begin(9600);
  pinMode(ledPinRed, OUTPUT); //sets the led pin to output
  pinMode(ledPinGreen, OUTPUT); //sets the led pin to output
  pinMode(lightPin, INPUT); //sets the led pin to output
}
 /*
 * loop() - this function will start after setup 
 * finishes and then repeat
 */
void loop()
{
 int lightLevel = analogRead(lightPin); //Read the lightlevel
 
 
 lightLevel = map(lightLevel, 0, 900, 0, 255); 
         //adjust the value 0 to 900 to
         //span 0 to 255



// lightLevel = constrain(lightLevel, 0, 255);//make sure the 
                                           //value is betwween 
                                           //0 and 255   
                                           
// analogWrite(ledPin, lightLevel);  //write the value
  if(lightLevel > 170)
  { 
     playPause();
  } 

  

}

void playPause()
{
  Serial.print('A');
  analogWrite(ledPinRed, 255);
  
  delay(1000);
  int readBack = Serial.read();
  analogWrite(ledPinRed, 0);
//  readData();
};

void readData()
{
  if (readBack == 1)
  {
     analogWrite(ledPinGreen, 255);
  delay(1000);
  analogWrite(ledPinGreen, 0);
  }
};
