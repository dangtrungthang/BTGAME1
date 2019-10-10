#include "Ball.h"
void Ball::Update(DWORD dt,int w,int h) {
	float speed = 0.3;
	if (x < 0 || x > w)
		dx = -dx;
	if (y < 0 || y  > h)
		dy = -dy;
	x += dx * speed*dt;
	y += dy * speed*dt;
	rect.left = x;
	rect.top = y;
	rect.right = 40;
	rect.bottom = 40;
	
}