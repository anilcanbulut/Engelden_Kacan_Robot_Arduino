//ultrasonik sensör trigger ve echo pinleri
const int trig = 3;
const int echo = 9;

//L298N motor sürücüsü dijital pin girisleri
const int in1 = 4;
const int in2 = 5;
const int in3 = 7;
const int in4 = 6;


void setup() {
//giris ve cikis pinleri tanımlandı
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

//serial port kullanimi aktiflestirildi
Serial.begin(9600);
}

void loop() {
//ultrasonik sensörün trigger pini aktif. Dalga üretimi baslar...
digitalWrite(trig,HIGH);
delay(500);
digitalWrite(trig,LOW);

//mesafe olcumu icin gerekli formuller yapıldı. PulseIn() komutuyla arada gecen sure olculdu.
int duration = pulseIn(echo,HIGH);
int distance = (duration/2)/29.1;

//serial port ile mesafe display edildi.
Serial.print(distance);
Serial.println(" cm");

//Bu komutla motorlar baslangıcta ileri doğru hareket eder.
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);

//engel ile aradaki mesafe 20 cm'den dusukse motorlar geriye dogru calisir ve saga donus gerceklesir
if(distance < 20){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(150);

  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
  delay(250); 

//Engel 20 cm'den uzaktaysa sorun olmadan motorlar ileri dogru donmeye devam eder.
}else{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
  
}
