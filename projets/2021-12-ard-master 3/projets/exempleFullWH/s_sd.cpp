#include "s_sd.h"
#include <SD.h>
File myFile;
void setupSD() {
  SD.begin(SD_CS);
}
void loopSD() {
  myFile = SD.open(FILENAME, FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    myFile.print(s.tm.Hour);
    myFile.print("");
    myFile.print(s.tm.Minute);
    myFile.print("");
    myFile.print(s.tm.Second);
    myFile.print("");
    myFile.print(s.meteo.pressure);
    myFile.print(";");
    myFile.print(s.meteo.temp);
    myFile.print(";");
    myFile.println("");
    // close the file:
    myFile.close();
  }
}
