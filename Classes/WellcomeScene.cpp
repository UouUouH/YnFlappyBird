#include "WellcomeScene.h"
#include "define.h"
#include "SimpleAudioEngine.h"
#include "GuiderLayer.h"

USING_NS_CC;

Scene* Wellcome::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Wellcome::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Wellcome::init()
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

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("welcomeBg.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images.plist");

	auto bg = Sprite::createWithSpriteFrameName("welcomeBg.png");
	bg->setPosition(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2);
	this->addChild(bg);

    

	auto animation = Animation::create();
	animation->setDelayPerUnit(LOADING_FRE);
	animation->addSpriteFrame(SpriteFrameCache::getInstance ()->getSpriteFrameByName("zt1.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance ()->getSpriteFrameByName("zt2.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance ()->getSpriteFrameByName("zt3.png"));

	auto animate = Animate::create(animation);

	auto repeat = Repeat::create(animate,LOADING_NUM);
	auto callback = CallFuncN::create(CC_CALLBACK_1(Wellcome::LoadingFinshed,this));
	auto sequence = Sequence::create(repeat, callback, NULL);

	auto loading = Sprite::createWithSpriteFrameName("zt1.png");
	loading->setPosition(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2);
	this->addChild(loading);
	loading->runAction(sequence);



    
	

    auto birdAnimation_0=Animation::create();  
    birdAnimation_0->setDelayPerUnit(BIRD_FLY_FRE);  
    birdAnimation_0->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird0_0.png"));
    birdAnimation_0->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird0_1.png"));
    birdAnimation_0->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird0_2.png"));
    //这里就是把他放到缓存中，然后名字就是 BIRDANIMATION_0 见define.h文件  
    AnimationCache::getInstance()->addAnimation(birdAnimation_0,BIRD_ANIMATION);
    
    /*auto label = LabelTTF::create("FlappyBird by YanngNa", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
	//set background 
	auto sprite = Sprite::createWithSpriteFrameName("wellcome_bg.png");
    // add "HelloWorld" splash screen"
   // auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);*/
   
    return true;
}


void Wellcome::LoadingFinshed(cocos2d::Ref *r)
{
	//auto gameScene = GameScene::createWithPhysics();
	Director::getInstance()->replaceScene(TransitionFade::create(CHANGESCENE_TIME,GuiderLayer::createScene()));
}
