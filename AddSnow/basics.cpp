#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>


#using namespace std
#using namespace cv

struct rainCircle {
	int x;
	int y;
	int r;
	int curR;
	int rainCircleStep;
};

class rain {
	int dtartX;
	int startY;
	int endY;
	int curX;
	int curY;
	int rainLineStep;
	int rainLineLength;
	struct rainCircle water;
public:
	int status;
	void createDrop() {
		startX = rand() % 640;
		startY = rand() % 430 + 130;
		endY = 430 + rand() % 50;
		curX = startX;
		curY = startY;
		rainLineStep = 8;
		rainLineStep = 10;
		status = 0;
		water.x = startX;
		water.y = endY;
		water.r = rand() % 40;
		water.curR = rand() % 2;
		water.rainCircleStep = rand() % 2 + 1;
	}
};

class singleStreak {

};

class hugeRain {

};