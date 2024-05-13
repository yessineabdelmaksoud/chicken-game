#include "Animation.h"

Animation::Animation(Texture* texture, Vector2u totalImages, float switchingTime)
{
	this->totalImages = totalImages;
	this->switchingTime = switchingTime;
	elapsedTime = 0.0f;
	currentImagePosition.x = 0;
	uvRect.width = texture->getSize().x / float(totalImages.x);
	uvRect.height = texture->getSize().y / float(totalImages.y);
}
void Animation::update(int rowNumber, float deltaTime, bool playerFacingRight)
{
	currentImagePosition.y = rowNumber;

	elapsedTime += deltaTime;
	if (elapsedTime >= switchingTime)
	{
		elapsedTime -= switchingTime;
		currentImagePosition.x++;
		if (currentImagePosition.x >= totalImages.x)
		{
			currentImagePosition.x = 0;
		}
	}

	uvRect.top = currentImagePosition.y * uvRect.height;

	if (playerFacingRight)
	{
		uvRect.left = currentImagePosition.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImagePosition.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}
