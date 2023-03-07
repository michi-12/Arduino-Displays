int digitos[16][7] = { // definición de los segmentos para cada dígito del 0 al 15
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
  {1, 1, 1, 0, 1, 1, 1}, // A
  {0, 0, 1, 1, 1, 1, 1}, // B
  {1, 0, 0, 1, 1, 1, 0}, // C
  {0, 1, 1, 1, 1, 0, 1}, // D
  {1, 0, 0, 1, 1, 1, 1}, // E
  {1, 0, 0, 0, 1, 1, 1}  // F
};

void setup() {
  // Configurar el monitor serial y el display de 7 segmentos
  Serial.begin(9600);
  for (int i = 0; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Esperar a que el usuario ingrese un número por el monitor serial
  while (Serial.available() == 0) {}
  int numero = Serial.parseInt();

  // Validar que el número esté entre 0 y 15
  if (numero >= 0 && numero <= 15) {
    // Mostrar el número en el display de 7 segmentos
    for (int i = 0; i < 7; i++) {
      digitalWrite(i+2, digitos[numero][i]);
    }
  } else {
    Serial.println("Número inválido");
  }
}