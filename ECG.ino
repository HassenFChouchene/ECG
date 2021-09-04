#include <SPI.h>
#include <TFT_eSPI.h>
#define SENSOR A0
#include <Arduino.h>
TFT_eSPI tft = TFT_eSPI();
int i,j,k,b;
int c =0;
int x=0;
void setup(void) {
  //
  Serial.begin(9600);
  pinMode(27, INPUT); // Setup for leads off detection LO +
  pinMode(26, INPUT); // Setup for leads off detection LO -
pinMode (5, OUTPUT);




  
  // Initialize color screen
  x= 0;
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  
  tft.drawLine(0, 0, 320,0,TFT_GREEN);
  tft.drawLine(0, 40, 320,40,TFT_GREEN);
  tft.drawLine(0, 80, 320,80,TFT_GREEN);
  tft.drawLine(0, 120, 320,120,TFT_GREEN);
 // tft.drawLine(0, 160, 320,160,TFT_GREEN);
  
  //
  tft.drawLine(0, 0, 0,120,TFT_GREEN);
  tft.drawLine(40, 0, 40,120,TFT_GREEN);
  tft.drawLine(80, 0, 80,120,TFT_GREEN);
  tft.drawLine(120, 0, 120,120,TFT_GREEN);
  tft.drawLine(160, 0, 160,120,TFT_GREEN);
  tft.drawLine(200, 0, 200,120,TFT_GREEN);
  tft.drawLine(240, 0,240 ,120,TFT_GREEN);
  tft.drawLine(280, 0,280 ,120,TFT_GREEN);
  tft.drawLine(319, 0,319 ,120,TFT_GREEN);
  // 
  
  

//  tft.drawPixel(128,151, TFT_WHITE); 
//  tft.drawPixel(129,150, TFT_WHITE);
//  tft.drawPixel(130,149, TFT_WHITE);
//  tft.drawPixel(131,148, TFT_WHITE);
//  tft.drawPixel(132,147, TFT_WHITE);
//  tft.drawPixel(133,146, TFT_WHITE);
//  tft.drawPixel(134,146, TFT_WHITE);
//  tft.drawPixel(135,146, TFT_WHITE);
//  tft.drawPixel(136,147, TFT_WHITE);
//  tft.drawPixel(137,148, TFT_WHITE);
//  tft.drawPixel(138,149, TFT_WHITE);
//  tft.drawPixel(139,150, TFT_WHITE); 
//  tft.drawPixel(140,151, TFT_WHITE);
  
   
   
   
}

void loop() {
   
  if ((digitalRead(27) == 1) || (digitalRead(26) == 1)) {
    Serial.println('!');
    b=0;
  //  c =0;
    tft.drawLine(0+x, 80, 10+x,80,TFT_RED);
    x+=10;
  }
  else {
     
    // send the value of analog input 0:
    Serial.println(analogRead(A0));
    b = analogRead(A0); 
    if (b==0){
      c =0;
      tft.drawLine(0+x, 80, 10+x,80,TFT_RED);
      x+=10;
    }
    else if ((b>0)&&(b<5000)){
      c++ ;
    }

    if (c>50){
       
    delay(50);
  //
  tft.drawLine(0+x, 80, 10+x,80,TFT_RED);
     
    i=0;
    j=0;
    while(i!=7){
    tft.drawPixel(10+i+x,80-i,TFT_RED); 
    i++;
    }
    
    tft.drawPixel(16+x,74, TFT_RED);
    tft.drawPixel(17+x,74, TFT_RED);
    tft.drawPixel(18+x,74, TFT_RED);
    tft.drawPixel(19+x,74, TFT_RED);
    
    while(j!=6){
    tft.drawPixel(20+j+x,75+j, TFT_RED);
    
    j++;
    }
    
    tft.drawLine(26+x, 80,31+x,80,TFT_RED);
    i=0;
    j=0;
    tft.drawLine(31+x,80,40+x,90,TFT_RED);
    tft.drawLine(40+x,90,47+x,17,TFT_RED);
     
    tft.drawLine(47+x,17,53+x,95,TFT_RED);
    tft.drawLine(53+x,95,57+x,80,TFT_RED);
    delay(50); 
    tft.drawLine(57+x,80,62+x,80,TFT_RED);
//
 while(i!=11){
    tft.drawPixel(62+i+x,80-i,TFT_RED); 
    i++;
    }
    
    tft.drawPixel(72+x,70, TFT_RED);
    tft.drawPixel(73+x,70, TFT_RED);
    tft.drawPixel(74+x,70, TFT_RED);
    tft.drawPixel(75+x,70, TFT_RED);
    
    while(j!=10){
    tft.drawPixel(76+j+x,71+j, TFT_RED);
    
    j++;
    }
    //
     delay(50);
    tft.drawLine(85+x, 80, 110+x,80,TFT_RED);
    

  
  // Set text color to white, blacx text bacxground
   
 
  x=x+120;
  digitalWrite (5, HIGH); //turn buzzer on
  delay(100);
  digitalWrite (5, LOW);  //turn buzzer off
  delay(100);
   
  }
    else {
      tft.drawLine(0+x, 80, 10+x,80,TFT_RED);
    }
    

  }

  if(x>=320){
    tft.fillScreen(TFT_BLACK);
    tft.drawLine(0, 0, 320,0,TFT_GREEN);
  tft.drawLine(0, 40, 320,40,TFT_GREEN);
  tft.drawLine(0, 80, 320,80,TFT_GREEN);
  tft.drawLine(0, 120, 320,120,TFT_GREEN);
 // tft.drawLine(0, 160, 320,160,TFT_GREEN);
  
  //
  tft.drawLine(0, 0, 0,120,TFT_GREEN);
  tft.drawLine(40, 0, 40,120,TFT_GREEN);
  tft.drawLine(80, 0, 80,120,TFT_GREEN);
  tft.drawLine(120, 0, 120,120,TFT_GREEN);
  tft.drawLine(160, 0, 160,120,TFT_GREEN);
  tft.drawLine(200, 0, 200,120,TFT_GREEN);
  tft.drawLine(240, 0,240 ,120,TFT_GREEN);
  tft.drawLine(280, 0,280 ,120,TFT_GREEN);
  tft.drawLine(319, 0,319 ,120,TFT_GREEN);
    x=0;
    }
    
  //Wait for a bit to xeep serial data from saturating
  delay(30);
}
