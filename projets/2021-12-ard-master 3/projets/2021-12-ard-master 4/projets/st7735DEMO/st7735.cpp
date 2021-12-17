#include "st7735.h"
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
void showTime(char*);
void showPressure(char*);
void initFrame();
void initST() {
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  tft.fillScreen(ST77XX_BLACK);
  initFrame();
}

void loopST(S_Datas datas) {
  char buff[15]="";
  sprintf(buff,"%02d:%02d",datas.tm.Hour,datas.tm.Minute);
  showTime(buff);
}
void initFrame(){

}
void showTime(char* str)
{
  tft.fillRect(POS_TIME_X-2,POS_TIME_Y-2,44,12, ST77XX_BLUE);
  tft.setCursor(POS_TIME_X,POS_TIME_Y);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(str);
}

void showPressure(char* str)
{
  tft.fillRect(POS_PRESS_X-10,POS_PRESS_Y-2,44,12, ST77XX_BLUE);
  tft.setCursor(POS_PRESS_X,POS_PRESS_Y);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(str);
}
