const int trigger_pin = 12;
const int echo_pin = 13;
const int buzzer = 2;

const int yled = 4;
const int sled = 5;
const int kled = 6;

int sure;
int mesafe;

void setup() {
  pinMode(kled, OUTPUT);
  pinMode(sled, OUTPUT);
  pinMode(yled, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger_pin, LOW);
  sure = pulseIn(echo_pin, HIGH);
  mesafe = (sure / 2) / 28.5;
  Serial.print("Mesafe= ");
Serial.println(mesafe);
  if (mesafe <= 18)
  {
    digitalWrite(kled, HIGH);
  digitalWrite(sled, HIGH);
    digitalWrite(yled, HIGH);
    
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(kled, LOW);
    digitalWrite(sled, LOW);
    digitalWrite(yled, LOW);
    
    digitalWrite(buzzer, LOW);
    delay(250);
  }

  else if (mesafe <= 45)
  {
    digitalWrite(sled, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(sled, LOW);
    digitalWrite(buzzer, LOW);
    delay(500);
  }

  else if (mesafe <= 60)
  {
     digitalWrite(yled, HIGH);
    digitalWrite(buzzer, HIGH);

    
    delay(50);
    digitalWrite(yled, LOW);
    digitalWrite(buzzer, LOW);
    delay(750);
  }


}
