
#include "U8glib.h"

U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);

int a;
String valore;

void setup() {
  Serial.begin(9600);    
    // flip screen, if required
  // u8g.setRot180();
  
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
 }

void loop() {
 if(Serial.available()){
  valore=" ";
  do{
    a = Serial.read();
    valore+=a;
  }while(a != '\n');
  u8g.firstPage(); 
 do {
  
u8g.setFont(u8g_font_gdr25r);
//u8g.drawStr(8, 30, "Eeee");

char buf[9];
sprintf (buf, "%d", a);
u8g.drawStr(0, 30, buf);

  } while( u8g.nextPage() );
  delay(200); 
  
 }
}
