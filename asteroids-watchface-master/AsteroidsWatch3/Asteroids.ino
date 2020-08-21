
int last = 0;
float bulletangle[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -100};
int bullettime[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -100};

int bigasteriodx[] = { -1, -2, -1, 0, 0, 1, 1, 2, 2, 1, -1, -100};
int bigasteriody[] = { -2, -1, 0, 2, 2, 1, 0, -1, -2, -2, -2, -100};
int asteriodmult[] = {3, 3, -1, -1, -1, -1, -1, -1, -1, -1};
int asteriodtime[] = {0, 20, -1, -1, -1, -1, -1, -1, -1, -1};
int asteriodvx[] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int asteriodvy[] = {1, 1, -1, -1, -1, -1, -1, -1, -1, -1};
int asteriodx[] = {30, 120, -1, -1, -1, -1, -1, -1, -1, -1};
int asteriody[] = {30, 30, -1, -1, -1, -1, -1, -1, -1, -1};

int screenx = 128;
int screeny = 64;
int mx = screenx / 2;
int my = screeny / 2;

float lastyy;


float tarangle = 0;
float angle = -3;

float computeChaseAngle() {
  float yy = asteriody[0] + 12 * asteriodvy[0] - my;
  float xx = asteriodx[0] + 12 * asteriodvx[0] - mx;
  tarangle = atan2(yy, xx);
  if (yy >= 0 && lastyy < 0) {
    angle = PI * 2 + angle;
  }
  angle = angle +  0.2 * (tarangle - angle);

  lastyy = yy;
}

void createBullet() {
  if (bulletangle[last] == -100) {
    last = 0;
  }
  bulletangle[last] = angle;
  bullettime[last] = 1;
  last = last + 1;
}



void drawGame() {
  // background(255);
  drawAllAsteroids();
  drawShip(angle, 8, mx, my);
  drawBullets(angle);
  drawBatteryLife();

  if (count % 2 == 0) {
    createBullet();
  }

  computeChaseAngle();
  //     angle = angle + PI/8;
  if (angle > PI * 2) {
    angle = 0;
  }
  // }
}

//int asteroidPoints[] = {-2, };

void drawBatteryLife() {
  drawShip(PI / 2 + PI, 4, 4, 13);
  drawShip(PI / 2 + PI, 4, 12, 13);
  if (progMode>9){
      drawShip(PI / 2 + PI, 4, 20, 13);
  }

  batteryLevel = getBatteryPercent();
  display.setCursor(0, 18);
  display.print((int) batteryLevel);
  // display.drawLine(0, 8, 15*batteryLevel/100, 8 ,1);
}

void drawShip(float dir, int shipsize, int x, int y) {
  float tip = 1.2;
  float back = 1;
  int tx = x + tip * shipsize * cos(dir);
  int ty = y + tip * shipsize * sin(dir);
  int bx1 = x + -back * shipsize * cos(dir + PI / 3);
  int by1 = y + -back * shipsize * sin(dir + PI / 3);
  int bx2 = x + -back * shipsize * cos(dir - PI / 3);
  int by2 = y + -back * shipsize * sin(dir - PI / 3);

  display.drawLine(tx, ty, bx1, by1 , 1);
  display.drawLine(tx, ty, bx2, by2 , 1);
  display.drawLine(bx1, by1, bx2, by2, 1);
}

float dist2(float x, float y, float x1, float y1) {
  float dx = x - x1;
  float dy = y - y1;
  return (dx * dx + dy * dy);
}


void drawAllAsteroids() {
  for (int i = 0; asteriodx[i] != -1; i++) {
    if (asteriodtime[i] <= 0) {
      if (asteriodmult[i]  < -1) {
        drawExplosion(i);
      } else {
        if (asteriodmult[i] > 1) {
          asteriodx[i] = asteriodx[i] + asteriodvx[i];
          asteriody[i] = asteriody[i] + asteriodvy[i];
          drawAsteroid(asteriodx[i], asteriody[i], asteriodmult[i]);

        }
      }
    } else {
      asteriodtime[i] = asteriodtime[i] - 1;
    }
    if (asteriodx[i] < -5 || asteriodx[i] > screenx + 5) {
      //  asteriodx[i]=-1;
      asteriodmult[i] = -1;
      createNewAsteriods(i);
    }
    if (asteriody[i] < -5 || asteriody[i] > screeny + 5) {
      //   asteriodx[i]=-1;
      asteriodmult[i] = -1;
      createNewAsteriods(i);
    }
  }
}


int aststart[] = {1, 0, 3, 2};
int astc = 0;

void createNewAsteriods(int i) {
  astc = (astc + 1) % 4;
  asteriodmult[i] = 3;
  if (aststart[astc] == 0) {
    asteriodvx[i] = -1;
    asteriodvy[i] = -1;
    asteriodx[i] = screenx;
    asteriody[i] = screeny;
    asteriodtime[i] = 0;
  }
  if (aststart[astc] == 1) {
    asteriodvx[i] = 1;
    asteriodvy[i] = -1;
    asteriodx[i] = 0;
    asteriody[i] = screeny;
    asteriodtime[i] = 1;
  }
  if (aststart[astc] == 2) {
    asteriodvx[i] = -1;
    asteriodvy[i] = 1;
    asteriodx[i] = screenx;
    asteriody[i] = 0;
    asteriodtime[i] = 0;
  }
  if (aststart[astc] == 3) {
    asteriodvx[i] = 1;
    asteriodvy[i] = 1;
    asteriodx[i] = 0;
    asteriody[i] = 0;
    asteriodtime[i] = 0;
  }

}


void drawExplosion(int i) {
  int mul = 1;
  display.drawPixel(asteriodx[i], asteriody[i] - asteriodmult[i]*mul, 1);
  display.drawPixel(asteriodx[i], asteriody[i] + asteriodmult[i]*mul, 1);
  display.drawPixel(asteriodx[i] + asteriodmult[i]*mul, asteriody[i] - asteriodmult[i]*mul, 1);
  display.drawPixel(asteriodx[i] + asteriodmult[i]*mul, asteriody[i] + asteriodmult[i]*mul, 1);
  display.drawPixel(asteriodx[i] - asteriodmult[i]*mul, asteriody[i] - asteriodmult[i]*mul, 1);
  display.drawPixel(asteriodx[i] - asteriodmult[i]*mul, asteriody[i] + asteriodmult[i]*mul, 1);
  display.drawPixel(asteriodx[i] - asteriodmult[i]*mul, asteriody[i], 1);
  display.drawPixel(asteriodx[i] + asteriodmult[i]*mul, asteriody[i], 1);
  asteriodmult[i] = asteriodmult[i] - 1; // explosion gets bigger
  if (asteriodmult[i] < -6) {
    createNewAsteriods(i);
  }
}

void drawAsteroid(int cx, int cy, int mult) {
  //    int mult = 3;
  for (int i = 1; bigasteriodx[i] != -100; i++) {
    int x1 = bigasteriodx[i - 1] * mult;
    int y1 = bigasteriody[i - 1] * mult;
    int x2 = bigasteriodx[i] * mult;
    int y2 = bigasteriody[i] * mult;
    display.drawLine(cx + x1, cy + y1, cx + x2, cy + y2, 1);
  }
}

void checkBulletAsteroidCollision(int bx, int by) {
  for (int j = 0; asteriodx[j] != -1; j++) {
    float dist = dist2(bx, by, asteriodx[j], asteriody[j]);
    if (dist < 50) {
      if (dist < 20 && asteriodmult[j] > 0) {
        asteriodmult[j] = -2; // explosion
      }
      if (asteriodmult[j] > 2) {
        asteriodmult[j] = 2; //smaller asteroid
        int xx = asteriodvx[j];
        int yy = asteriodvx[j];
        asteriodvx[j] = yy;
        asteriodvy[j] = xx;
      }
    }
  }
}

void drawBullets(float dir) {
  int cx = 128 / 2;
  int cy = 64 / 2;
  int bulletspeed = 2;

  for (int i = 0; bulletangle[i] > -99; i++) {
    if (bulletangle[i] != -1) {
      bullettime[i] = bullettime[i] + 1;
      float bx = cx + cos(bulletangle[i]) * (8 + bullettime[i] * bulletspeed);
      float by = cy + sin(bulletangle[i]) * (8 + bullettime[i] * bulletspeed);

      display.drawPixel(bx, by, 1);
      checkBulletAsteroidCollision(bx, by);
    }
  }
}
