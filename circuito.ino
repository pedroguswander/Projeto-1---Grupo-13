#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(9,8) ;
int button_pin[4] = {2,3,4,5} ;
bool botao_status[4] ; 
int button_custom = 13 ;
int f = 0 ;
int c = 0 ;
LiquidCrystal_I2C lcd(0x27 , 16,2) ;
String numero ;
String data = "BambuBot" ;
String custom ;
String necessidade0 = "Quer Agua!" ;  //necessidades : modo inicial
String necessidade1 = "Esta incomodado!" ;
String necessidade2 =  "Esta com fome!";
String necessidade3 =  "Banheiro!";

void setup() {
  // put your setup code here, to run once:
  for(int i = 0 ; i < 4 ; i++) {
  pinMode(button_pin[i],INPUT_PULLUP) ;
}
  pinMode(button_custom,INPUT_PULLUP) ;
  Serial.begin(9600) ;
  lcd.init() ;
  lcd.setCursor(0,0) ;
  lcd.backlight();
  lcd.display() ;
  bluetooth.begin(9600) ;
}

void loop() {
  // put your main code here, to run repeatedly:
      for (int i = 0 ; i < 4 ; i++) {
    	botao_status[i] = digitalRead(button_pin[i]) ;  
    }

    if (bluetooth.available() > 0 && f == 0 ) {
   	data = bluetooth.readString() ; // primeiro innput é o nome e só é lido uma vez
    f+=1 ;
    }

    if (bluetooth.available() > 0 && f == 1 && c == 0) {
   	  numero = bluetooth.readString() ; // outro input que lê a opção escolhida pelo usuário
      c+=1 ;
    }
    if (numero == "B" && c == 1) {
      if (bluetooth.available() > 0) {
        necessidade0 = bluetooth.readString() ; // texto da necessidade a ser inserida no botão escolhido
        c = 0 ;
      }
    }
    if (numero == "R" && c == 1) {
        if (bluetooth.available() > 0) {
        necessidade1 = bluetooth.readString() ; // texto da necessidade a ser inserida no botão escolhido
        c = 0 ;
      }
    }
      if (numero == "G" && c == 1) {
        if (bluetooth.available() > 0) {
        necessidade2 = bluetooth.readString() ; // texto da necessidade a ser inserida no botão escolhido
        c = 0 ;
      }
      }
      if (numero == "Y" && c==1) {
        if (bluetooth.available() > 0) {
        necessidade3 = bluetooth.readString() ; // texto da necessidade a ser inserida no botão escolhido
        c = 0 ;
      }
      }

  if (botao_status[0] == LOW) {
      lcd.clear() ;
      lcd.setCursor(2,0) ;
      lcd.print(data) ;
      lcd.setCursor(2,1) ;
      lcd.print(necessidade0) ;
      Serial.println("botao0") ; 
    	delay(500) ;
  }
   if (botao_status[1] == LOW) {
      lcd.clear() ;
      lcd.setCursor(2,0) ;
      lcd.print(data) ;
      lcd.setCursor(0,1) ;
      lcd.print(necessidade1) ;
      Serial.println("botao1") ; 
    	delay(500) ;
  }
     if (botao_status[2] == LOW) {
      lcd.clear() ;
      lcd.setCursor(2,0) ;
      lcd.print(data) ;
      lcd.setCursor(0,1) ;
      lcd.print(necessidade2) ;
      Serial.println("botao2") ;
    	delay(500) ;
  }
     if (botao_status[3] == LOW) {
      lcd.clear() ;
      lcd.setCursor(2,0) ;
      lcd.print(data) ;
      lcd.setCursor(0,1) ;
      lcd.print(necessidade3) ;
      Serial.println("botao3") ;
    	delay(500) ;
  }
  
}
