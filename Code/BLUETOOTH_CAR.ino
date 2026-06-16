#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); // RX, TX

char t;

void setup() {

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Bluetooth Ready");
}

void loop() {

  if (BT.available()) {

    t = BT.read();

    Serial.println(t);

    // Stop all motors first
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);

    if (t == 'F') {

      digitalWrite(13, HIGH);
      digitalWrite(11, HIGH);

    }

    else if (t == 'B') {

      digitalWrite(12, HIGH);
      digitalWrite(10, HIGH);

    }

    else if (t == 'R') {

      digitalWrite(13, HIGH);

    }

    else if (t == 'L') {

      digitalWrite(11, HIGH);

    }

    else if (t == 'S') {

      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);

    }

    else if (t == 'W') {

      digitalWrite(9, HIGH);

    }

    else if (t == 'w') {

      digitalWrite(9, LOW);

    }
  }
}