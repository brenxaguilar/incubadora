const int pinDHT11 = 28;
const int pinRele = 18;
const int LED = 15;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Pines de conexión de la pantalla LCD

#include <DHT.h>
#include <LiquidCrystal.h>

DHT dht(pinDHT11, DHT11);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(pinRele, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16, 2); // Inicializar pantalla LCD (16 columnas, 2 filas)
  dht.begin();
}

void loop() {
  // Leer valores de temperatura y humedad
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  // Imprimir valores en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C");
  Serial.print(" Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  // Controlar el relé en función de la temperatura
  if (temperatura >= 0 && temperatura <= 37) {
    digitalWrite(pinRele, HIGH); // Encender el relé (prender el foco)
    digitalWrite(LED, HIGH); // Indicar estado (opcional)
  } else {
    digitalWrite(pinRele, LOW); // Apagar el relé (apagar el foco)
    digitalWrite(LED, LOW); // Indicar estado (opcional)
  }

  // Mostrar valores en la pantalla LCD
  lcd.setCursor(0, 0); // Posicionar cursor en la primera fila, primera columna
  lcd.print("Temperatura:"); // Mostrar texto "Temperatura:"
  lcd.print(temperatura); // Mostrar valor de temperatura
  lcd.print(" °C"); // Mostrar símbolo de grados Celsius

  lcd.setCursor(0, 1); // Posicionar cursor en la segunda fila, primera columna
  lcd.print("Humedad:"); // Mostrar texto "Humedad:"
  lcd.print(humedad); // Mostrar valor de humedad
  lcd.print("%"); // Mostrar símbolo de porcentaje

  delay(2000); // Retardo entre lecturas
}