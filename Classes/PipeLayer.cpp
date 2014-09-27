#include "PipeLayer.h"
#include "PipeSprite.h"
#include "define.h"
USING_NS_CC;

// on "init" you need to initialize your instance
bool Pipes::init(bool isOffsetX)
{
    //////////////////////////////
    //if (!Layer::init()) {
    //    return false;
    //}
    
	//yn
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();
    
    auto upPipe = PipeSprite::create(1);
    auto downPipe = PipeSprite::create(2);
    
    upPipe->retain();
    downPipe->retain();
    auto pipeSize = upPipe->getContentSize();
    float offsetX = 0.5* visibleSize.width;
    if (!isOffsetX) {
        offsetX = 0;
    }
    _positionX = origin.x+visibleSize.width+pipeSize.width+offsetX;
    _destinationX = origin.x - pipeSize.width/2;
    _timeX = (PIPE_TIME*offsetX)/(visibleSize.width+pipeSize.width)+PIPE_TIME;
    
    this->addChild(upPipe, 0, PIPE_UP);
    this->addChild(downPipe, 0, PIPE_DOWN);
    
    this->setPosition(_positionX, origin.y+PIPE_Y);
   
 
    _positionX = _positionX - offsetX;
    
    return true;
}

Pipes* Pipes::create(bool isOffsetX)
{
    Pipes* pipes = new Pipes();
    if(pipes && pipes->init(isOffsetX))
    {
        pipes->autorelease();
        return pipes;
    }
    else
    {
        delete pipes;
        pipes = NULL;
        return NULL;
    }
}



void Pipes::MovePipes()
{
    auto moveAction = MoveTo::create(_timeX,Point(_destinationX,this->getPositionY()));
    auto callback = CallFuncN::create(CC_CALLBACK_1(Pipes::MoveOver, this));
    auto sequence = Sequence::create(moveAction,callback, NULL);
    this->runAction(sequence);
}

void Pipes::MoveOver(cocos2d::Ref *f)
{
    int yRange = rand()%PIPE_RANG;
    this->setPosition(_positionX, PIPE_Y+yRange);
    _timeX = PIPE_TIME;
    MovePipes();
}
//void Bird::LoadingFinshed()
//{
//}

#pragma PipeLayer

bool PipeLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    auto pipes1 = Pipes::create(false);
    auto pipes2 = Pipes::create(true);
    pipes1->retain();
    pipes2->retain();
    this->addChild(pipes1);
    this->addChild(pipes2);
    pipes1->MovePipes();
    pipes2->MovePipes();
    return true;
}


























    
