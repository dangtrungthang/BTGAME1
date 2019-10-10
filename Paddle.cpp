#include "Paddle.h"

void Paddle::Update(DWORD dt) {
	switch (state)
			{
			case MOVE_UP_KEYBOARD:
				y -= 0.2f * dt; break;
			case MOVE_DOWN_KEYBOARD:
				y += 0.2f * dt; break;
			case IDLE:
				break;
			default:
				break;
			}
}
void Paddle::UpdateR(DWORD dt,int xs,int ys) {
	if (y < 0) { y = 0; };
		if (y > SCREEN_HEIGHT - infoSquare.Height) y = SCREEN_HEIGHT - infoSquare.Height;
		y = y + ys; 
		rect.left = x;
		rect.top = y;
		rect.right =  infoSquare.Width;
		rect.bottom = infoSquare.Height;
}