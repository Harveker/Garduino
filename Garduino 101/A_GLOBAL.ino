/* This program is made by: Franco Endrigo.
    If you wish to colaborate, ask questions or sugestions you can do so, in github.com/Harveker/arduino.
    This is public for everyone. I only ask that if you improve this program that you let me know which improvments you did, so i can improve this project too.
    I'm still a beginner both in programming and eletronic. Therefore, i'll definetly apreciate any help.
    There are no credits to anyone yet, since i only use the www.arduino.cc 's references for this project, any help that i get along the way will be credit here.
*/

// Analogic and Digital pins named:
#define ThermoButton A0 //Pin of the Thermistor
#define PhotoButton  A1 //Pin of the Photoresistor
#define Dbuzzer 8 //Digital pin of the Piezoeletric buzzer
#define GreenLED 9 //Digital pin of the green LED
#define YellowLED 10 //Digital pin of the yellow LED
#define RedLED 11 //Digital pin of the red LED

// Constants to thermistor (out of datasheet):
#define Vin 5.0 //Tension of input [volts].
#define RT1 35563 //resistance in [ohm].
#define RT2 549.4 //resistance in [ohm].
#define R0 10000 //resistance in [ohm].
#define Rt 10000 //resistance in [ohm]. Resistance of the voltage diviser.
#define T1 273.15 // temperature in [K].
#define T0 298.15 // temperature in [K].
#define T2 373.15 // temperature in [K].

//Constants for mapping the photoresistor:
const int MaxLuminosity = 0.94; //experimental reading
const int MinLuminosity = 4.99; //experimental reading

// initial variables:
float PhotoLumTension = 0.0;
float ThermistorTension = 0.0;
int LumValue = 0;
float data[2] = {};

//str Commands: 

//Char Variables:
char InputComms;
char InputAlert;
char InputData;

//Thermistor's variables:
float Rinf = 0.0;
float Beta = 0.0;
float TempKelvin = 0.0;
float TempCelsius = 0.0;
float Rout = 0.0;
float Vout = 0.0;
float LowerLimit = 30.00;
float HigherLimit = 45.00;

//LED blinking variables:
int gld = 0;
int yld = 0;
int rld = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(Dbuzzer, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  Beta_Rinf();
}

void loop()
{
  Rout_Vout();
  Data_Transmiter();
  if (InputAlert == 'a')
  {
    Alerts();
  }
  delay(2000);
}
