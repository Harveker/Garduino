void Alerts()
{
  int RangeLum = map(PhotoLumTension, MaxLuminosity, MinLuminosity, 0, 3); 
  switch (RangeLum)
    {
      case 0:
        {
          if ((LowerLimit) <= (TempCelsius) && (TempCelsius) <= (HigherLimit))
          {
            Serial.println("Very bright and warm"); //if conditions nominal then green light will turn on.
            digitalWrite(GreenLED, HIGH);
            digitalWrite(YellowLED, LOW);
            digitalWrite(RedLED, LOW);
          }
          else if ((TempCelsius) <= 15.0) //case 0x2. fix it by rising the temperature of the system. (bugcode: T1x0x0).
          {
            Serial.println("Very bright and cold");
            digitalWrite(GreenLED, LOW);
            for (yld = 0; yld < 5; yld++)
            {
              tone(Dbuzzer, 1500);
              digitalWrite(YellowLED, HIGH); //for case 0x2 the yellow light will blink 4 times. (bugcode: T2x0x0).
              delay(400);
              noTone(Dbuzzer);
              digitalWrite(YellowLED, LOW);
              delay(400);
            }
            digitalWrite(RedLED, LOW);
          }
          else
          {
            Serial.println("Very bright but not warm"); //case 0x1. fix it by rising lightly the temperature. (bugcode: T1x0x0).
            digitalWrite(GreenLED, LOW);
            for (yld = 0; yld < 11; yld++)
            {
              tone(Dbuzzer, 1500);
              digitalWrite(YellowLED, HIGH); //for case 0x1 the yellow light will blink 10 times. (bugcode: T1x0x0).
              delay(250);
              noTone(Dbuzzer);
              digitalWrite(YellowLED, LOW);
              delay(250);
            }
            digitalWrite(RedLED, LOW);
          }
          break;
        }
      case 1:
        {
          if ((LowerLimit) <= (TempCelsius) && (TempCelsius) <= (HigherLimit))
          {
            Serial.println("Bright and warm"); //if conditions nominal then green light will turn on.
            digitalWrite(GreenLED, HIGH);
            digitalWrite(YellowLED, LOW);
            digitalWrite(RedLED, LOW);
          }
          else if (TempCelsius <= 15.0) //case 1x2. fix it by rising the temperature of the system. (bugcode: T2x0x0).
          {
            Serial.println("Bright and cold");
            digitalWrite(GreenLED, LOW);
            for (yld = 0; yld < 5; yld++)
            {
              tone(Dbuzzer, 1500);
              digitalWrite(YellowLED, HIGH); //for case 1x2 the yellow light will blink 4 times. (bugcode: T2x0x0).
              delay(400);
              noTone(Dbuzzer);
              digitalWrite(YellowLED, LOW);
              delay(400);
            }
            digitalWrite(RedLED, LOW);
          }
          else
          {
            Serial.println("Bright but not warm"); //case 1x1. fix it by rising lightly the temperature. (bugcode: T1x0x0).
            digitalWrite(GreenLED, LOW);
            for (yld = 0; yld < 11; yld++)
            {
              tone(Dbuzzer, 1500);
              digitalWrite(YellowLED, HIGH); //for case 1x1 the yellow light will blink 10 times over 1 second. (bugcode: T1x0x0).
              delay(250);
              noTone(Dbuzzer);
              digitalWrite(YellowLED, LOW);
              delay(250);
            }
            digitalWrite(RedLED, LOW);
          }
          break;
        }
      case 2:
        {
          if ((LowerLimit) <= (TempCelsius) && (TempCelsius) <= (HigherLimit))
          {
            Serial.println("Dim and warm"); //if conditions of the light are not nominal then yellow light will turn on.
            digitalWrite(GreenLED, LOW);
            digitalWrite(YellowLED, HIGH); //case 2x0. fix it by rising the luminosity in the system. (bugcode: L0x1x0).
            digitalWrite(RedLED, LOW);
          }
          else if (TempCelsius <= 15.0) //case 2x2. fix it by rising the temperature of the system and the luminosity. (bugcode: TL2x1x0).
          {
            Serial.println("Dim and cold");
            digitalWrite(GreenLED, LOW);
            for (rld = 0; rld < 5; rld++)
            {
              tone(Dbuzzer, 1500);
              digitalWrite(YellowLED, HIGH); //for case 2x2 the yellow light will turn on.
              digitalWrite(RedLED, HIGH); //for case 2x2 the red light will blink 4 times. (bugcode: TL2x1x0).
              delay(400);
              noTone(Dbuzzer);
              digitalWrite(RedLED, LOW);
              delay(400);
            }
            digitalWrite(YellowLED, LOW);
          }
          else
          {
            Serial.println("Dim but not warm"); //case 2x1. fix it by rising lightly the temperature and increasing the luminosity. (bugcode: TL1x1x0).
            digitalWrite(GreenLED, LOW);
            for (rld = 0; rld < 11; rld++)
            {
              tone(Dbuzzer, 1500);
              digitalWrite(YellowLED, HIGH); //for case 2x1 the yellow light will turn on.
              digitalWrite(RedLED, HIGH); //for case 2x1 the red light will blink 10 times. (bugcode: TL1x1x0).
              delay(250);
              noTone(Dbuzzer);
              digitalWrite(RedLED, LOW);
              delay(250);
            }
            digitalWrite(YellowLED, LOW);
          }
          break;
        }
      case 3:
        {
          if ((LowerLimit) <= (TempCelsius) && (TempCelsius) <= (HigherLimit))
          {
            Serial.println("Dark and warm"); //if conditions of the light are not nominal then red light will turn on. (bugcode: L0x2x0).
            digitalWrite(GreenLED, LOW);
            digitalWrite(YellowLED, LOW);
            digitalWrite(RedLED, HIGH); //case 3x0. fix it by rising the luminosity in the system. (bugcode: L0x2x0).
          }
          else if (TempCelsius <= 15.0) //case 3x2. fix it by rising the temperature of the system and the luminosity. (bugcode: TL2x2x0).
          {
            Serial.println("Dark and cold");
            digitalWrite(GreenLED, LOW);
            for (yld = 0; yld < 5; yld++)
            {
              tone(Dbuzzer, 1500);
              digitalWrite(RedLED, HIGH); //for case 3x2 the red light will turn on.
              digitalWrite(YellowLED, HIGH); //for case 3x2 the yellow light will blink 4 times. (bugcode: TL2x2x0).
              delay(400);
              noTone(Dbuzzer);
              digitalWrite(YellowLED, LOW);
              delay(400);
            }
            digitalWrite(RedLED, LOW);
          }
          else
          {
            Serial.println("Dark but not warm"); //case 3x1. fix it by rising lightly the temperature and increasing the luminosity. (bugcode: TL1x2x0).
            digitalWrite(GreenLED, LOW);
            for (yld = 0; yld < 11; yld++)
            {
              tone(Dbuzzer, 1500);
              digitalWrite(RedLED, HIGH); //for case 3x1 the red light will turn on.
              digitalWrite(YellowLED, HIGH); //for case 3x1 the yellow light will blink 10 times. (bugcode: TL1x2x0).
              delay(250);
              noTone(Dbuzzer);
              digitalWrite(YellowLED, LOW);
              delay(250);
            }
            digitalWrite(RedLED, LOW);
          }
          break;
        }
    }
}  
