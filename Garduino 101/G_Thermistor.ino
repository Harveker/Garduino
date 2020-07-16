void Thermistor()
{
  TempKelvin = (Beta / (log((Rout / Rinf)))); //Temperature equation re-arranged from the Steinhart-Hart equation.
  TempCelsius = ((TempKelvin) - (273.15));
  Serial.print("The temperature of the system is: ");
  Serial.print(TempKelvin);
  Serial.println(" K");
  Serial.print("The temperature in Celsius of the system is: ");
  Serial.print(TempCelsius);
  Serial.println(" ºC");
}
