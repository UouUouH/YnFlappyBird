#include "PipeLayer.h"
#include "define.h"
#include "Score.h"
USING_NS_CC;

bool PipeSprite::init(int tag)
{
    auto origin = Director::getInstance()->getVisibleOrigin();
   // auto visibleSize = Director::getInstance()->getVisibleSize();
    
    if (tag == 1)//up pipe
    {
        this->initWithSpriteFrameName("pipe_up.png");
        this->setPosition(origin.x+this->getContentSize().width/2, origin.y+this->getContentSize().height/2);
    }
    else{
        
        this->initWithSpriteFrameName("pipe_down.png");
        this->setPosition(origin.x+this->getContentSize().width/2, origin.y+this->getContentSize().height*3/2+THROUGH_HEIGHT);
    }
    
    auto body = PhysicsBody::create();
    auto shape = PhysicsShapeBox::create(this->getContentSize());
    body->addShape(shape);
    body->setDynamic(false);
    
    body->setGravityEnable(false);
    
    body->setCategoryBitmask(PIPE);
    body->setCollisionBitmask(BIRD);
    body->setContactTestBitmask(BIRD);
    
    this->setPhysicsBody(body);
	
    return true;
}

PipeSprite* PipeSprite::create(int tag)
{
    PipeSprite* pipeSprite = new PipeSprite();
    if(pipeSprite && pipeSprite->init(tag))
    {
        pipeSprite->autorelease();
        return pipeSprite;
    }
    else
    {
        delete pipeSprite;
        pipeSprite = NULL;
        return NULL;
    }
}


//-----------------------------Pipes-----------------------------------

// on "init" you need to initialize your instance
bool Pipes::init(bool isOffsetX)
{
    //////////////////////////////
  /* if (!Layer::init()) {
        return false;
    }*/
	//yn
    _isScored = false;
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();
    
	
    auto upPipe = PipeSprite::create(1);
    auto downPipe = PipeSprite::create(2);
   
    auto pipeSize = upPipe->getContentSize();
	//确保屏幕上永远都有两个管道即大概是这样的
	//   |////|           |////|           |////|
	//   |////|           |////|           |////|
	//   |////|           |////|           |////|<----pipe 
	//   |////| <-offset->|////| <-offset->|////|
	//   |////|           |////|           |////|
	//   |////|           |////|           |////|
	//   |////|           |////|           |////|
	//   -----------------------------------------
	//        |--------scope---------------|
    float offsetX = (visibleSize.width-pipeSize.width)/2+pipeSize.width;
    if (!isOffsetX) {
        offsetX = 0;
    }
    _positionX = origin.x+visibleSize.width+pipeSize.width+offsetX;
    _destinationX = origin.x - pipeSize.width;
  //  _timeX = (PIPE_TIME*offsetX)/(visibleSize.width+pipeSize.width)+PIPE_TIME;
	_timeX = -1*(_destinationX - _positionX)/120;//120是草地移动的速度，管子移动速度要和草地移动速度一致
    
    this->addChild(upPipe, 0, PIPE_UP);
    this->addChild(downPipe, 0, PIPE_DOWN);
    
    this->setPosition(_positionX, origin.y+PIPE_Y);
   
 
    _positionX = _positionX - offsetX;
    this->scheduleUpdate();
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
    _timeX = -1*(_destinationX - _positionX)/120;//120是草地移动的速度，管子移动速度要和草地移动速度一致
    MovePipes();
}
//void Bird::LoadingFinshed()
//{
//}
void Pipes::stopMovePipes()
{
	this->stopAllActions();
    this->unscheduleUpdate();
    //this->removeFromParent();
}
void Pipes::update(float)
{
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto pipe = this->getChildByTag(PIPE_UP);
	int p = pipe->getPhysicsBody()->getPosition().x;
	log("pipe positionx %d",p);
	if((p <= (origin.x+visibleSize.width/2))&&(p > (origin.x+visibleSize.width/2-10)))
    {
        if (_isScored == false) {
            Score::getInstance()->addScore();
            _isScored = true;
        }
        
    }
    else
        _isScored = false;
		
}
//-----------------------------#pragma PipeLayer--------------------

bool PipeLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    _pipes1 = Pipes::create(false);
	_pipes2 = Pipes::create(true);
    this->addChild(_pipes1);
    this->addChild(_pipes2);
    ((Pipes*)_pipes1)->MovePipes();
    ((Pipes*)_pipes2)->MovePipes();
    return true;
}

void PipeLayer::stopMovePipes()
{
	((Pipes*)_pipes1)->stopMovePipes();
    ((Pipes*)_pipes2)->stopMovePipes();
}
























    
