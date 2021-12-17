#include "s_ds1307.hpp"
void setupDS1307(){
}

void loopDS1307(){
  RTC.read(s.tm);
}
