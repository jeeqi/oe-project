float num1;
float num2;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);
  num2=(sensorValue*(5/1024.0));//Must deal with float type
  num1=((num2*1000)/5108.0);  
  Serial.println(num1, 3);//Print to serial and Display three digits after the decimal point
  delay(2000); //Delay of 2000 milliseconds
}

