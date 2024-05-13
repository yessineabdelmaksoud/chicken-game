#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Animation
{
private:
	float elapsedTime;

	float switchingTime;

	Vector2u totalImages;

	Vector2u currentImagePosition;
public:

	IntRect uvRect;

	Animation(Texture* texture, Vector2u totalImages, float switchingTime);

	void update(int rowNumber, float deltaTime, bool playerFacingRight);
};
