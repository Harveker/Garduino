void Luminosity()
{
  PhotoLumTension = ((float)(analogRead(PhotoButton)) * (5.0 / 1024));
  Serial.print("Luminosity in tension: ");
  Serial.println(PhotoLumTension, 4);
}
