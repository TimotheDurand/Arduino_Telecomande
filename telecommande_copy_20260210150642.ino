#include <IRremote.hpp>

#define IR_RECEIVE_PIN 11
#define LED_PIN 13

bool ledState = false; // état de la LED

// flag pour le ON/OFF
bool flag  = false;
bool flag1 = false;
bool flag2 = false;
bool flag3 = false;
bool flag4 = false;
bool flag5 = false;

// Led PIN
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;

// Codes IR
unsigned long ON_CODE       =   0xBA45FF00;
unsigned long B1_CODE       =   0xF30CFF00;
unsigned long B2_CODE       =   0xE718FF00;
unsigned long B3_CODE       =   0xA15EFF00;
unsigned long B4_CODE       =   0xF708FF00;
unsigned long B5_CODE       =   0xE31CFF00;
unsigned long BOFF_CODE     =   0x00000000;

// Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);   Pour avoir le code d'une commande

// #####----- ----- ----- BOUTON ON ----- ----- -----##### //
void mode_bouton_on () {
  flag = !flag;
  if (flag) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  Serial.println("ON CODE");
}

// #####----- ----- ----- BOUTON 01 ----- ----- -----##### //
void mode_bouton_1 () {
  flag1 = !flag1;
  if (flag1) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }
  Serial.println("BOUTON CODE 1");
}

// #####----- ----- ----- BOUTON 02 ----- ----- -----##### //
void mode_bouton_2 () {
  flag2 = !flag2;
  if (flag2) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
  Serial.println("BOUTON CODE 2");
}

// #####----- ----- ----- BOUTON 03 ----- ----- -----##### //
void mode_bouton_3 () {
  flag3 = !flag3;
  if (flag3) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }
  Serial.println("BOUTON CODE 3");
}

// #####----- ----- ----- BOUTON 04 ----- ----- -----##### //
void mode_bouton_4 () {
  flag4 = !flag4;
  if (flag4) {
    digitalWrite(LED4, HIGH);
  } else {
    digitalWrite(LED4, LOW);
  }
  Serial.println("BOUTON CODE 4");
}

// #####----- ----- -----  BOUTON 05 ----- ----- -----##### //
void mode_bouton_5 () {
  flag5 = !flag5;
  Serial.println("BOUTON CODE 5");
}


// #####----- ----- ------ MODE BOUTON 5 ----- ----- -----##### //
void mode__bouton_5 (bool f1,bool f2,bool f3,bool f4) {
  if (flag5) {
    if (f1 == false) {
      digitalWrite(LED1, HIGH);
    }
    if (f2 == false) {
      digitalWrite(LED2, HIGH);
    }
    if (f3 == false) {
      digitalWrite(LED3, HIGH);
    }
    if (f4 == false) {
      digitalWrite(LED4, HIGH);
    }
    delay(100);
    if (f1 == false) {
      digitalWrite(LED1, LOW);
    }
    if (f2 == false) {
      digitalWrite(LED2, LOW);
    }
    if (f3 == false) {
      digitalWrite(LED3, LOW);
    }
    if (f4 == false) {
      digitalWrite(LED4, LOW);
    }
    delay(100);
  }
}


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Pret - utilise ta télécommande");

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
}

void loop() {
  // Detecter bouton
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;

    if (code == ON_CODE) {
      mode_bouton_on();
    }
    else if (code == B1_CODE) {
      mode_bouton_1 ();
    }
    else if (code == B2_CODE) {
      mode_bouton_2 ();
    }
    else if (code == B3_CODE) {
      mode_bouton_3 ();
    }
    else if (code == B4_CODE) {
      mode_bouton_4 ();
    } 
    else if (code == B5_CODE) {
      mode_bouton_5 ();
    } 

    else if (code == BOFF_CODE) {
      Serial.println("OFF CODE");
    }

    else {
      Serial.println("Bouton inconnu");
    }

    IrReceiver.resume(); // prêt pour le prochain signal
  }

  // Different Mode
  mode__bouton_5 (flag1,flag2,flag3,flag4);
}


//ON : 0xBA45FF00 
// 1 : 0xF30CFF00
// 2 : 0xE718FF00
// 3 : 0xA15EFF00
// 4 : 0xF708FF00