#include "GamePlatform.h"
#include "cocos2d.h"
#include "define.h"
#include "LandSprite.h"
#include "BirdSprite.h"
#include "BackgroundLayer.h"
#include "PipeLayer.h"
#include "GameOver.h"
#include "Score.h"
USING_NS_CC;
Scene* GamePlatform::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(GRAVITY);
    
    // 'layer' is an autorelease object
    auto layer = GamePlatform::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool GamePlatform::init( )
{
	if (!Layer::init()) {
        return false;
    }
	 auto zorder = this->getLocalZOrder();
    auto bg = BackgroundLayer::create();
    bg->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	bg->setPosition(Point::ZERO);
    this->addChild(bg);
    
    _pipeLayer = PipeLayer::create();
    _pipeLayer->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	_pipeLayer->setPosition(Point::ZERO);
    this->addChild(_pipeLayer);
	/*
    _spriteland1 = LandSprite::create(0.5);
    _spriteland2 = LandSprite::create(1.5);
   
    this->addChild(_spriteland1);
    this->addChild(_spriteland2);
    
    this->schedule(schedule_selector(GamePlatform::moveLand ), LAND_VELOCITY);*/
	_landLayer = Land::create();
	this->addChild(_landLayer);
    //2 bird
    _spriteBird = BirdSprite::create();
    this->addChild(_spriteBird);
   
    ((BirdSprite*)_spriteBird)->PrepareToFly();
   
    Score::getInstance()->initScore();
	this->addChild(Score::getInstance());
	return true;
}

void GamePlatform::onEnter()
{
    Layer::onEnter();
	// 
    _touchOneByOneListenr = EventListenerTouchOneByOne::create();
    _touchOneByOneListenr->setSwallowTouches(false);
    
    _touchOneByOneListenr->onTouchBegan =[=] (Touch *t, Event *e)
    {
        log("touch begin");
        return true;
    };
    _touchOneByOneListenr->onTouchEnded =[=] (Touch *t, Event *e)
    {
        
        ((BirdSprite*)_spriteBird)->FlyUpward();
    };
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_touchOneByOneListenr, this);

	_contactListener = EventListenerPhysicsContact::create();
	_contactListener->onContactBegin = CC_CALLBACK_1(GamePlatform::onContactBegin,this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_contactListener,this);
	
}/*
void GamePlatform::moveLand(float)
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
void GamePlatform::stopLandMove()
{
	this->unschedule(schedule_selector(GamePlatform::moveLand));
}
*/
bool GamePlatform::onContactBegin(PhysicsContact& contact)
{
	log("onContactBegin begin");
	this->gameOver();
	return true;
}

void GamePlatform::gameOver()
{
    ((PipeLayer*)_pipeLayer)->stopMovePipes();
	((BirdSprite*)_spriteBird)->dying();
	((Land*)_landLayer)->stopLandMove();
	
	//øº¬«“™≤ª“™‘⁄’‚¿Ô…æ≥˝¡Ω∏ˆevent listener
	//this->removeChild(_pipeLayer);
	this->removeChild(Score::getInstance());

	auto gameOver =GameOver::create();
	this->addChild(gameOver);
}
