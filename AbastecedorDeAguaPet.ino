#define pinBomba 21
#define pinRecipNoEmpty 32
#define pinPoteNoEmpty 33
#define pinPoteFull 25

void setup() {

  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(pinBomba, OUTPUT);
  pinMode(pinRecipNoEmpty, INPUT);
  pinMode(pinPoteNoEmpty, INPUT);
  pinMode(pinPoteFull, INPUT);
}

int count = 1;

void loop() {
  condicaoBombaLigar();
  condicaoBombaDesligar();
  pt("--");print(count++);ptln("--");
  delaySec(1);
  pt("isRecipOk: ");println(analogRead(pinRecipNoEmpty));
  pt("isPoteOk: ");println(analogRead(pinPoteNoEmpty));
  pt("isPoteFull: ");println(analogRead(pinPoteFull));
}


bool condicaoBombaLigar() {
  if (!digitalRead(pinBomba)) {
    if (isRecipOk() && !isPoteOk() && !isPoteFull()) {
      digitalWrite(pinBomba, 1);
      Serial.println("ligado");
    }
  }
}

bool condicaoBombaDesligar() {
  if (digitalRead(pinBomba)) {
    if (isRecipOk()) {
      if (isPoteFull()) {
        digitalWrite(pinBomba, 0);
        Serial.println("desligado");
      }
    } else {
      digitalWrite(pinBomba, 0);
      Serial.println("desligado");
    }
  }
}

bool isRecipOk() {
  //pt("isRecipOk: ");println(analogRead(pinRecipNoEmpty));
  return analogRead(pinRecipNoEmpty) < 1000;
}
bool isPoteOk() {
  // pt("isPoteOk: ");println(analogRead(pinPoteNoEmpty));
  return analogRead(pinPoteNoEmpty) < 1000;
}
bool isPoteFull() {
  // pt("isPoteFull: ");println(analogRead(pinPoteFull));
  return analogRead(pinPoteFull) < 1000;
}

void ptln(String valor) {
  Serial.println(valor);
}

void pt(String valor) {
  Serial.print(valor);
}

void print(int valor) {
  Serial.print(valor);
}
void println(int valor) {
  Serial.println(valor);
}

void delaySec(int sec) {
  delay(sec * 1000);
}