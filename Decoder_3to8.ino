/* Exemple d'ús d'un decodificador 3to8 74HC238 
   Autor: Albert Segura Salvador
   Data: 22/01/12
   Arduino UNO R2 - Arduino v1.0
 */
int valor = 0;

void setup()  { 
  pinMode(13, OUTPUT); // A0
  pinMode(12, OUTPUT); // A1
  pinMode(11, OUTPUT); // A2
  pinMode(10, OUTPUT); // E3
  
  digitalWrite(10,HIGH);
  Serial.begin(9600); // delay on linux fix
} 

void escriu() {  // Cutre
  if (valor == 8) digitalWrite(10,LOW);
  else digitalWrite(10,HIGH);
  int lectura = valor%2;
  if (lectura == 1) digitalWrite(13,HIGH);
  else digitalWrite(13,LOW);
  int aux = valor/2;
  lectura = aux%2;
  if (lectura == 1) digitalWrite(12,HIGH);
  else digitalWrite(12,LOW);
  aux = aux/2;
  lectura = aux%2;
  if (lectura == 1) digitalWrite(11,HIGH);
  else digitalWrite(11,LOW);
}

void loop()  { 
  if (valor == 9) valor = 0;
  
  escriu();
  ++valor;
  delay(80);
}
