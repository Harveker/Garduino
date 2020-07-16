void Beta_Rinf()
{
  Beta = ((log(RT1/RT2))/((1/T1)-(1/T2))); //Beta computing out of the Steinhart-Hart equation.
  Rinf = R0*exp(-Beta/T0); //The infinite resistance based on Beta.
}
