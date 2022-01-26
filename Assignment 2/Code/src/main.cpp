#include <Arduino.h>

int out = 13, W = 10, V = 9, U =8, result, a, b, c;

void output(int U, int V, int W){
  result = (!(U&&V) && (!W)) || (U&&V&&W);
  digitalWrite(out, result);
}

void setup() {
  pinMode(U, INPUT);
  pinMode(V, INPUT);
  pinMode(W, INPUT);

  pinMode(out, OUTPUT);
}

void loop() {
  a = digitalRead(U);
  b = digitalRead(V);
  c = digitalRead(W);

  output(a, b, c);
}