#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
using namespace sf;
class Player
{
public:
	Player(Texture* texture, Vector2u totalImages, float switchingTime, float playerSpeed);
	void update(float deltaTime);
	void draw(RenderWindow& window);
	RectangleShape srpit();
private:
	RectangleShape playerBody;
	Animation animation;
	unsigned int rowNumber;
	float playerSpeed;
	bool playerFacingRight;
};
