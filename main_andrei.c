#include <stdlib.h>

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight] = 
{
	//         V
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // <
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};


int main(int argc, char **argv) {
	// what is the diff btw double and float here?
	//Q: why when I put 5,5 - there is hit at 1,0? and no 0,8 but 0,9 ?
	double posX = 7, posY = 7;

	// how to calculate and decide initial values
	// must depend on direction (north, south, east, west)?
	//A: camera vector is perpendicular to direction; so we can hardcode values based on direction
	// 	direction is set in input from map file
	//TODO: try rotation - rotate both dir and plane vectors
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.5; //cyka kamera; 0, 0.66 gives glitches: skips some blocks with dda
	//Q: how other ppl solve it? 0, 0.5 works better with the same pos tests
	double time = 0, oldTime = 0;
	while(1) {
		for (int x = 1; x <= screenWidth; x++) {
			double cameraX = 2 * x / (double)screenWidth - 1; // 
			double rayDirX = dirX + planeX * cameraX; // since perpendicular, X is left 
			double rayDirY = dirY + planeY * cameraX; //y will be from neg to positive
			printf("\nthrowin a ray #%d; cameraX is [%f], ray dir (%f, %f)\n", x, cameraX, rayDirX, rayDirY);
			// what is the diff btw (double) and double(1)?
			int mapX = (int)posX; //TODO: make sure our position is not inside wall
			int mapY = (int)posY;
			double sideDistX, sideDistY;
			// use abs
			//double deltaDistX = (rayDirX == 0) ? 1e30 : abs(1/rayDirX);
			double deltaDistX = (rayDirX == 0) ? 1e30 : 1/rayDirX;
			if (deltaDistX < 0)
				deltaDistX = -deltaDistX;
			//double deltaDistY = (rayDirY == 0) ? 1e30 : abs(1/rayDirY);
			double deltaDistY = (rayDirY == 0) ? 1e30 : 1/rayDirY;
			if (deltaDistY < 0)
				deltaDistY = -deltaDistY;
			printf("delta Dist (%f, %f)\n", deltaDistX, deltaDistY);
			double perpWallDist;
			int stepX, stepY;
			int hit = 0;
			int side;
			if (rayDirX < 0) {
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			} else {
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}
			if (rayDirY < 0) {
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			} else {
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}
			printf("DDA starts; stepX [%d], stepY [%d]; sideDist (%f, %f)\n", stepX, stepY, sideDistX, sideDistY);
			while(hit == 0) {
				if(sideDistX < sideDistY) {
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				} else {
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				printf("DDA: map (%d, %d) sideDist (%f, %f), deltaDist (%f, %f), side (%d)\n", mapX, mapY, sideDistX, sideDistY, deltaDistX, deltaDistY, side);
				if( worldMap[mapX][mapY] > 0)	hit = 1;
			}
			printf("hit at [%d][%d] side[%d]\n", mapX, mapY, side);
		}
		break;
	}
	
	return 0;
}
