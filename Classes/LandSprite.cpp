#include "LandSprite.h"
#include "cocos2d.h"
#include "define.h"
USING_NS_CC;


bool LandSprite::init(float n)
{
	this->initWithSpriteFrameName("land.png");
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto contentSize = this->getContentSize();
	this->setPosition(origin.x+contentSize.width*n,origin.y+contentSize.height/2);
	this->getTexture()->setAliasTexParameters();

	auto body = PhysicsBody::create();
	auto shape = PhysicsShapeBox::create(contentSize);
	body->addShape(shape);
	body->setDynamic(false);
	body->setGravityEnable(false);

	body->setCategoryBitmask(LAND);
	body->setCollisionBitmask(BIRD);
	body->setContactTestBitmask(0);

	body->setLinearDamping(0.7f);
	this->setPhysicsBody(body);
	return true;
}

LandSprite* LandSprite::create(float n)
{
	LandSprite* landSprite = new LandSprite();
	if(landSprite && landSprite->init(n))
	{
		landSprite->autorelease();
		return landSprite;
	}
	else
	{
		delete landSprite;
		landSprite = NULL;
		return NULL;
	}
}