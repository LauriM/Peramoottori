#include "Sprite.h"
using namespace pm;

Sprite::Sprite() : Rectangle(0, 0, 0, 0)
{
	hasTexture = false;
	draw = true;
}

Sprite::Sprite(Texture texture) : Rectangle(texture.getTexturePosition(), texture.getTextureSize())
{
	this->texture = texture;
	hasTexture = true;
	draw = true;
	setSourceRectPosition(texture.getTexturePosition());
	setSourceRectSize(texture.getTextureSize());
}

Sprite::Sprite(Texture texture, float x, float y, float widht, float heigth) : Rectangle(x, y, widht, heigth)
{
	this->texture = texture;
	hasTexture = true;
	draw = true;
}

Sprite::~Sprite()
{

}

void Sprite::setSourceRectSize(glm::vec2 tempsourceRectSize)
{
	this->sourceRect[2] = tempsourceRectSize[0];
	this->sourceRect[3] = tempsourceRectSize[1];

	vertices[6 + 7 * 2] = (tempsourceRectSize[1] / texture.getTextureSize()[1]);
	vertices[5 + 7 * 3] = (tempsourceRectSize[0] / texture.getTextureSize()[0]);
	vertices[5 + 7 * 4] = (tempsourceRectSize[0] / texture.getTextureSize()[0]);
	vertices[6 + 7 * 4] = (tempsourceRectSize[1] / texture.getTextureSize()[1]);
}

void Sprite::setSourceRectPosition(glm::vec2 tempsourceRectPosition)
{
	this->sourceRect[0] = tempsourceRectPosition[0];
	this->sourceRect[1] = tempsourceRectPosition[1];

	vertices[5] = (tempsourceRectPosition[0] / texture.getTextureSize()[0]);
	vertices[6] = (tempsourceRectPosition[1] / texture.getTextureSize()[1]);
}

void Sprite::setSourceRect(glm::vec4 tempsourceRect)
{
	this->sourceRect = tempsourceRect;

	vertices[5] = (tempsourceRect[0] / texture.getTextureSize()[0]);
	vertices[6] = (tempsourceRect[1] / texture.getTextureSize()[1]);
	vertices[6 + 7 * 2] = (tempsourceRect[3] / texture.getTextureSize()[3]);
	vertices[5 + 7 * 3] = (tempsourceRect[2] / texture.getTextureSize()[2]);
	vertices[5 + 7 * 4] = (tempsourceRect[2] / texture.getTextureSize()[2]);
	vertices[6 + 7 * 4] = (tempsourceRect[3] / texture.getTextureSize()[3]);
}

glm::vec2 Sprite::getSourceRectSize()
{
	return glm::vec2(sourceRect[2], sourceRect[3]);
}

glm::vec2 Sprite::getSourceRectPosition()
{
	return glm::vec2(sourceRect[0], sourceRect[1]);
}

glm::vec4 Sprite::getSourceRect()
{
	return sourceRect;
}
