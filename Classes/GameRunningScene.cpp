#include "GameRunningScene.h"
#include "define.h"
#include "GamePlatform.h"
#include "BackgroundLayer.h"

#include "GuiderLayer.h"
#include "PipeLayer.h"
USING_NS_CC;
Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(GRAVITY);
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer ::init() )
    {
        return false;
    }
    
	//yn
    
    auto bg = BackgroundLayer::create();
    bg->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	bg->setPosition(Point::ZERO);
    this->addChild(bg);
    
    auto pipe = PipeLayer::create();
    pipe->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	pipe->setPosition(Point::ZERO);
    this->addChild(pipe);
    
	auto land = GamePlatform::create();
	land->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	land->setPosition(Point::ZERO);
	this->addChild(land);

    
    
    
    return true;
}

