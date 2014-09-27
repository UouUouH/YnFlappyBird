#include "GuiderLayer.h"
#include "define.h"
#include "BackgroundLayer.h"
#include "GamePlatform.h"
#include "GameRunningScene.h"
USING_NS_CC;

Scene* GuiderLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GuiderLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GuiderLayer::init()
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
    
    auto bg = BackgroundLayer::create();
    bg->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	bg->setPosition(Point::ZERO);
    this->addChild(bg);
    
    auto getReady = cocos2d::Sprite::createWithSpriteFrameName("text_ready.png");
    getReady->setPosition(origin.x+visibleSize.width/2, origin.y+visibleSize.height*4/5);
    this->addChild(getReady);
    
    auto guider = Sprite::createWithSpriteFrameName("tutorial.png");
    guider->setPosition(origin.x+visibleSize.width/2, origin.y+visibleSize.height*2/5);
    this->addChild(guider);
    
    auto birdAndLand = GamePlatform::create();
    this->addChild(birdAndLand);
    
    return true;
}


void GuiderLayer::onEnter()
{
    Layer::onEnter();
    _touchOneByeOne = EventListenerTouchOneByOne::create();
    _touchOneByeOne->setSwallowTouches(false);
    _touchOneByeOne->onTouchBegan =[=] (Touch *t, Event *e)
    {
        log("guider touch begin");
        return true;
    };
    _touchOneByeOne->onTouchEnded =[=] (Touch *t, Event *e)
    {
        
        Director::getInstance()->replaceScene(TransitionFade::create(CHANGESCENE_TIME, GameScene::createScene()));
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchOneByeOne, this);
    
}




































