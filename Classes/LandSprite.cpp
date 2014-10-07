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
	body->setContactTestBitmask(BIRD);

	//body->setLinearDamping(0.7f);
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


//------------LandLayer-------
bool Land::init()
{
	_spriteland1 = LandSprite::create(0.5);
    _spriteland2 = LandSprite::create(1.5);
   
    this->addChild(_spriteland1);
    this->addChild(_spriteland2);
    
    this->schedule(schedule_selector(Land::moveLand ), LAND_VELOCITY);
	return true;
}
void Land::moveLand(float)
{
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto contentSize = _spriteland1->getContentSize();
    
	_spriteland1->setPositionX(_spriteland1->getPositionX()-2);
	_spriteland2->setPositionX(origin.x+_spriteland1->getPositionX()+contentSize.width);
	if(_spriteland2->getPositionX() == origin.x+contentSize.width/2)
	{
		_spriteland1->setPositionX(origin.x+contentSize.width/2);
	}
}
void Land::stopLandMove()
{
	this->unschedule(schedule_selector(Land::moveLand));
}
