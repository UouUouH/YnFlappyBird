#include "GamePlatform.h"
#include "cocos2d.h"
#include "define.h"
#include "LandSprite.h"
#include "BirdSprite.h"
USING_NS_CC;
GamePlatform* instance = NULL;
GamePlatform* GamePlatform::getInstance()
{
    if (instance == NULL) {
        instance = GamePlatform::create();
        instance->init();
    }
    return instance;
}
bool GamePlatform::init( )
{
	if (!Layer::init()) {
        return false;
    }
    
    _spriteland1 = LandSprite::create(0.5);
    _spriteland2 = LandSprite::create(1.5);
    auto zorder = this->getLocalZOrder();
    this->addChild(_spriteland1);
    this->addChild(_spriteland2);
    
    this->schedule(schedule_selector(GamePlatform::move ), LAND_VELOCITY);
    
    //2 bird
    auto birdSprite = BirdSprite::create();
    this->addChild(birdSprite, zorder, BIRD_TAG);
    birdSprite->PrepareToFly();
    
   
    
	return true;
}

void GamePlatform::onEnter()
{
    Layer::onEnter();
    _touchOneByOneListenr = EventListenerTouchOneByOne::create();
    _touchOneByOneListenr->setSwallowTouches(false);
    auto bird = this->getChildByTag(BIRD_TAG);
    _touchOneByOneListenr->onTouchBegan =[=] (Touch *t, Event *e)
    {
        log("touch begin");
        return true;
    };
    _touchOneByOneListenr->onTouchEnded =[=] (Touch *t, Event *e)
    {
        
        ((BirdSprite*)bird)->FlyUpward();
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchOneByOneListenr, this);
}
void GamePlatform::move(float)
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
void GamePlatform::stop()
{
	this->unschedule(schedule_selector(GamePlatform::move));
}