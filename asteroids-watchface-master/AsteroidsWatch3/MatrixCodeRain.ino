int number = 0;
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{
  B00000000, B00000000,
  B00000011, B11000000,
  B00001111, B11110000,
  B00011100, B00111000,
  B00110000, B00001100,
  B01100000, B00001110,
  B01100000, B00000110,
  B01100000, B00000110,
  B01100000, B00000110,
  B01100000, B00000110,
  B01100000, B00000110,
  B01110000, B00001100,
  B00111000, B00011100,
  B00011111, B11111000,
  B00001111, B11110000,
  B00000001, B10000000,

  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00111111, B11111100,
  B01111111, B11111110,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00111111, B11111100,
  B00011111, B11111000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B01111111, B11111110,
  B01111111, B11111110,
  B00000000, B00000000,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000000, B00000000,
  B00111111, B11111100,
  B00111111, B11111100,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00011111, B11111000,
  B00011111, B11111000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B00000000, B00000000,
  B01111111, B11111110,
  B01111111, B11111110,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000000, B00000000,
  B00111111, B11111100,
  B01111111, B11111110,
  B01100110, B11000110,
  B01100110, B11000110,
  B01100110, B11000110,
  B01100110, B11000110,
  B01101100, B11011110,
  B01111100, B11111110,
  B01111000, B01110110,
  B01100000, B00000110,
  B01111111, B11111110,
  B01111111, B11111110,
  B01100000, B00000110,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000000, B00000000,
  B00111111, B11111100,
  B00111111, B11111100,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000110, B00000000,
  B00111111, B11110000,
  B00111111, B11111000,
  B00000110, B00111000,
  B00000110, B00111000,
  B00001100, B00111000,
  B00001100, B00111000,
  B01111111, B11111110,
  B01111111, B11111110,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000001, B00000000,
  B00000001, B10000000,
  B00000001, B10000000,
  B01111111, B11111110,
  B01111111, B11111110,
  B00000000, B00000000,
  B00000000, B00000000,
  B00001110, B01100000,
  B00001100, B00110000,
  B00011100, B00111000,
  B00011000, B00011000,
  B00110000, B00011100,
  B01110000, B00001110,
  B01100000, B00000110,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000110, B00000000,
  B00000110, B00000000,
  B00000110, B00000000,
  B00000110, B00000000,
  B00000110, B11111110,
  B01111111, B11111110,
  B01111111, B00000000,
  B00000110, B00000000,
  B00000110, B00000000,
  B00000110, B00000000,
  B00000110, B00000000,
  B00000110, B00001100,
  B00000111, B11111100,
  B00000111, B11111100,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000000, B00000000,
  B00000111, B11110000,
  B00000111, B11110000,
  B00000100, B01110000,
  B00001110, B00110000,
  B00001100, B00110000,
  B00001100, B00110000,
  B00011100, B00110000,
  B00011000, B00111000,
  B00011000, B00011000,
  B00110000, B00011100,
  B01110000, B00001110,
  B01100000, B00000110,
  B01000000, B00000010,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000111, B00000000,
  B00000111, B00000000,
  B00000111, B00000000,
  B00000111, B00000000,
  B01111111, B11110000,
  B00000111, B00110000,
  B00000110, B00110000,
  B00000110, B00110000,
  B00000110, B00110000,
  B00001110, B00110000,
  B00011100, B00110000,
  B00111000, B00110011,
  B01110000, B00111111,
  B01100000, B00111110,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000011, B00000000,
  B01111111, B11111110,
  B01111111, B11111110,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000000, B00110000,
  B01111100, B00110000,
  B01111111, B11111110,
  B01101101, B11111100,
  B01101100, B00110000,
  B01111111, B11111110,
  B01111111, B11111110,
  B01101100, B00001100,
  B01101111, B11111110,
  B01101111, B11111110,
  B01111101, B10001100,
  B01111100, B11001100,
  B01100000, B00011100,
  B00000000, B00111000,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000110, B00100000,
  B00000110, B01100000,
  B00001100, B00110000,
  B00011100, B00011000,
  B00111000, B00011100,
  B01110000, B00001110,
  B01111111, B11111110,
  B00011111, B11111000,
  B00000110, B00011000,
  B00000110, B00011000,
  B00000110, B00011000,
  B00001110, B00111000,
  B00011100, B00110000,
  B00111000, B11110000,
  B00000000, B01000000,

  B00000000, B00000000,
  B00011000, B00000000,
  B00011000, B00000000,
  B00111111, B11111110,
  B00110000, B11000000,
  B01100000, B11000000,
  B01111111, B11111100,
  B00011111, B11111100,
  B00011000, B11000000,
  B00011000, B11000000,
  B01111111, B11111110,
  B01111111, B11111110,
  B00000000, B11000000,
  B00000000, B11000000,
  B00000000, B11000000,
  B00000000, B11000000,

  B00000000, B00000000,
  B00000000, B00000000,
  B00001111, B11111000,
  B00001100, B00011000,
  B00001100, B00011000,
  B00001111, B11111000,
  B00001111, B11111000,
  B00001100, B00011000,
  B00011100, B00011000,
  B00011111, B11111000,
  B00011111, B11111000,
  B00011000, B00011000,
  B00111000, B00011000,
  B00110000, B00111000,
  B00110000, B01111000,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000000, B00000000,
  B00011111, B11111000,
  B00011111, B11111000,
  B00011000, B00011000,
  B00011000, B00011000,
  B00011000, B00011000,
  B00011111, B11111000,
  B00011111, B11111000,
  B00011000, B00011000,
  B00011000, B00011000,
  B00011000, B00011000,
  B00011111, B11111000,
  B00011111, B11111000,
  B00011000, B00011000,
  B00000000, B00000000,

  B00000000, B00000000,
  B00000001, B10000000,
  B01111111, B11111100,
  B01111111, B11111100,
  B00000011, B00000000,
  B00000011, B00000000,
  B00000110, B00001100,
  B00001111, B11111100,
  B00011111, B11111100,
  B00000110, B11000000,
  B00000110, B11000000,
  B00000110, B11000000,
  B00001100, B11000110,
  B00011000, B11111110,
  B01100000, B11111100,
  B00000000, B00000000,

  B00111111, B11111100,
  B00000001, B10000000,
  B01111111, B11111110,
  B11000001, B10000011,
  B11011101, B10111011,
  B00000001, B10000000,
  B00011101, B10111000,
  B00000001, B10000000,
  B01111111, B11111110,
  B01100001, B10000110,
  B01111111, B11111110,
  B01100001, B10000110,
  B01111111, B11111110,
  B00100001, B10000100,
  B00000001, B10000110,
  B00000001, B11111100,
  B00000000, B1111100,

  B00000000, B00000000,
  B00000000, B00000000,
  B00111000, B00000000,
  B01111100, B00011000,
  B01100110, B00110000,
  B01100110, B01100000,
  B01111100, B11000000,
  B00111001, B10000000,
  B00000011, B00000000,
  B00000110, B11110000,
  B00001101, B10110000,
  B00011001, B10011000,
  B00110001, B10010000,
  B01100001, B11110000,
  B00000000, B11100000,
  B00000000, B00000000,
};

int columnpos[] = {30, 50, -20, 0, 30, 20, 40 };
int columnpos2[] = {-30, -50, -20, 0, -30, -20, -40 };
int offset = 0;

void drawNum(int d, int col, int fin, int c) {
  int dones = d % 10;
  int dtens = (d / 10) % 10;
  if (d > 99) {
    dtens = 9;
    dones = 9;
  }
  if (dtens == 0) {
    display.drawBitmap(col, offset+columnpos[c]+0,  &logo16_glcd_bmp[16 * 2 * dones + 2], 16, 16, 1);
    display.drawBitmap(col, offset+columnpos[c]+16,  &logo16_glcd_bmp[16 * 2 * fin + 2], 16, 16, 1);
  } else {
    if (dtens == 1) {
      if (dones == 0){
      display.drawBitmap(col, offset+columnpos[c]+0,  &logo16_glcd_bmp[16 * 2 * 10 + 2], 16, 16, 1);
      display.drawBitmap(col, offset+columnpos[c]+16,  &logo16_glcd_bmp[16 * 2 * fin + 2], 16, 16, 1);       
      }else{
      display.drawBitmap(col, offset+columnpos[c]+0,  &logo16_glcd_bmp[16 * 2 * 10 + 2], 16, 16, 1);
      display.drawBitmap(col, offset+columnpos[c]+16,  &logo16_glcd_bmp[16 * 2 * dones + 2], 16, 16, 1);
      display.drawBitmap(col, offset+columnpos[c]+32,  &logo16_glcd_bmp[16 * 2 * fin + 2], 16, 16, 1);
      }
    } else {
      if (dones == 0){
      display.drawBitmap(col, offset+columnpos[c]+0,  &logo16_glcd_bmp[16 * 2 * dtens + 2], 16, 16, 1);
      display.drawBitmap(col, offset+columnpos[c]+16,  &logo16_glcd_bmp[16 * 2 * 10 + 2], 16, 16, 1);
      display.drawBitmap(col, offset+columnpos[c]+32,  &logo16_glcd_bmp[16 * 2 * fin + 2], 16, 16, 1);
       }else{
      display.drawBitmap(col, offset+columnpos[c]+0,  &logo16_glcd_bmp[16 * 2 * dtens + 2], 16, 16, 1);
      display.drawBitmap(col, offset+columnpos[c]+16,  &logo16_glcd_bmp[16 * 2 * 10 + 2], 16, 16, 1);
      display.drawBitmap(col, offset+columnpos[c]+32,  &logo16_glcd_bmp[16 * 2 * dones + 2], 16, 16, 1);
      display.drawBitmap(col, offset+columnpos[c]+48,  &logo16_glcd_bmp[16 * 2 * fin + 2], 16, 16, 1);
       }
    }
  }
  if (offset == 0){
    offset=-64;
    drawNum(d, col, fin, c);
     offset=0;
  }
}


void showBatteryJapanese() {
  batteryLevel = getBatteryPercent();
  display.drawBitmap(18, columnpos[1]+ 0,  &logo16_glcd_bmp[16*2*16+2  ], 16, 16, 1);
  display.drawBitmap(18, columnpos[1]+16,  &logo16_glcd_bmp[16*2*17+2], 16, 16, 1);
  drawNum(batteryLevel*100,0, 18, 0);

  display.drawBitmap(18, -64+columnpos[1]+ 0,  &logo16_glcd_bmp[16*2*16+2  ], 16, 16, 1);
  display.drawBitmap(18, -64+columnpos[1]+16,  &logo16_glcd_bmp[16*2*17+2], 16, 16, 1);
}


void showTimeJapanese() {
  display.setCursor(0, 0);
  now  = rtc.now();
  drawNum(now.year(),108, 13, 6);
  drawNum(now.month(),90, 14, 5);
  drawNum(now.day(),72, 15, 4);

  drawNum(now.hour(),54, 11, 3);
  drawNum(now.minute(),36, 12, 2);
}

void drawJapanese(){
  for (int i=0;i<7;i++){
    columnpos[i]=columnpos[i]+random(0,4);
    if (columnpos[i] > 64){
      columnpos[i]=0;
    }
  }
  showTimeJapanese();
  showBatteryJapanese();
}
