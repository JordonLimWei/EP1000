#define LED1 15
#define LED2 14
#define LED3 16

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop()
{
  digitalWrite(LED1, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(LED1, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(LED2, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(LED2, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(LED3, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(LED3, LOW);
  delay(500); // Wait for 1000 millisecond(s)
}