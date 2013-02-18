int speakerPin = 9;

void setup() {
   Serial.begin(9600);
   pinMode(speakerPin, OUTPUT);
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void loop(){
  //940 - 1010
  int lowValue = 820;
  int highValue = 995;
  //1915-956
  //70 -> 960
  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);
   //wait one second.
  if (sensorValue>lowValue){
    //digitalWrite(13,HIGH);
    float finalValue = (sensorValue-lowValue);
    float finalValue2 = finalValue / (highValue-lowValue);
    int finalValue3 = finalValue2*highValue;
    int finalValue4 = highValue - finalValue3;
    //Serial.println(finalValue4);
    playTone(finalValue4,5);
  } else {
    digitalWrite(speakerPin, LOW);
    //Serial.println("Idle");
    //digitalWrite(13,LOW);
    //delay(100);
  }
}
