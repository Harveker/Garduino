void Rout_Vout()
{
  Vout =((float)(analogRead(ThermoButton))*(5.0/1024)); //Tension value, out of the tension diviser.
  Rout = (Rt*Vout)/(Vin-Vout); //Resistance of the thermoresistor behaving as a resistor.
}
