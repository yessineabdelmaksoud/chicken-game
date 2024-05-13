#include "Player.h"
Player::Player(Texture* texture, Vector2u totalImages, float switchingTime, float playerSpeed) : animation(texture, totalImages, switchingTime)
{
	this->playerSpeed = playerSpeed;
	rowNumber = 0;
	playerFacingRight = true;
	playerBody.setSize(Vector2f(136.0f, 182));
	playerBody.setPosition(400.0f, 600.0f);
	playerBody.setTexture(texture);
}

void Player::update(float deltaTime)
{
	Vector2f movement(0.0f, 0.0f);
	if (Keyboard::isKeyPressed(Keyboard::Left))
		movement.x -= playerSpeed * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		movement.x += playerSpeed * deltaTime;
	if (movement.x == 0.0f)
		rowNumber = 0;
	else
	{
		rowNumber = 0;
		if (movement.x > 0.0f)
			playerFacingRight = true;
		else
			playerFacingRight = false;
	}

	animation.update(rowNumber, deltaTime, playerFacingRight);
	playerBody.setTextureRect(animation.uvRect);
	playerBody.move(movement);
}
void Player::draw(RenderWindow& window)
{

	window.draw(playerBody);
}

RectangleShape Player::srpit()
{
	return playerBody;
}

