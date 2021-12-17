#include "st7735.h"
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void showTime(char *);
void showPressure(char * pressure);


void loopST7735(struct S_Datas datas) {
  char buff[14]="00:00";
  sprintf(buff,"%2d:%2d",datas.tm.Hour,datas.tm.Minute);
  showTime(buff);
  sprintf(buff,"%6d",datas.meteo.pressure);
  showPressure(buff);
}
void setupST7735() {
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);
}
void makeCadre() {
  tft.fillRect(0, 0, 8, ST_W, ST77XX_RED);
  //cadre heure
  tft.fillRect(32, 0, 12, ST_W - 64, ST77XX_RED);
  //cadre pressur
  tft.drawRect(POS_PRESSURE_X-2, POS_PRESSURE_Y-12,60,40, ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_BLUE);
  tft.setCursor(POS_PRESSURE_X, POS_PRESSURE_Y-10);
  tft.print("Press Pa");

  //cadre temp....
}
void showTime(char *timeStr)
{
  tft.fillRect(32, 0, 12, ST_W - 64, ST77XX_RED);
  tft.setCursor(2, 0);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setTextWrap(true);
  tft.print(timeStr);
}
void showPressure(char * pressure){
  tft.drawRect(POS_PRESSURE_X-1, POS_PRESSURE_Y-6,60,12, ST77XX_YELLOW);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(POS_PRESSURE_X, POS_PRESSURE_Y-10);
  tft.print(pressure);
}
