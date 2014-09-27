#include "BackgroundLayer.h"
#include "define.h"
USING_NS_CC;

// on "init" you need to initialize your instance
bool BackgroundLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	//yn
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto bg = Sprite::createWithSpriteFrameName("bg_day.png");
	bg->setPosition(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2);
	this->addChild(bg);
    
    return true;
}


//void Bird::LoadingFinshed()
//{
//}
