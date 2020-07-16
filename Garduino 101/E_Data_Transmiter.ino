/*
  int pin = 10;
  int data = 0;
  char userInput;
  void setup()
  {
  Serial.begin(9600);
  }

  void loop()
  {
  if(Serial.available() > 0)
  {
    userInput = Serial.read();
    if (userInput == 'R')
    {
      data = analogRead(pin);
      Serial.println(data);
    }
  }
  }

*/
/*
  int i = 0;
  void Data_Transmiter()
  {
  if (Serial.available() > 0)
  {
    InputComms = Serial.read();
    while(InputComms == 'c' && i < 3);
      {
        Thermistor();
        Luminosity();
        TempKelvin = data[1];
        PhotoLumTension = data[2];
        Serial.println(data[i]);
        i = i + 1;
      }
     delay(2000);
     Serial.println("Fora do while");
     if (i == 2)
     {
      i = 0;
     }
  }
  }

*/
void Data_Transmiter()
{
  Thermistor();
  Luminosity();
}
