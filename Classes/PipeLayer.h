#ifndef __PIPELAYER_H__
#define __PIPELAYER_H__

#include "cocos2d.h"
class PipeSprite :
	public cocos2d::Sprite
{
public:
   //tag = 1 up pipe, tag = 2 down pipe
	bool init(int tag);
    
   //tag = 1 up pipe, tag = 2 down pipe
	static PipeSprite* create(int tag);
   
};

//in fact , those are a pair of pipes, which including a upward pipe and a downward pipe
class Pipes: public cocos2d::Node
{
public:
   
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(bool isOffsetX);
    
    // a selector callback
    static Pipes* create(bool isOffsetX);
	//void LoadingFinshed();
    void MovePipes();
    void stopMovePipes();
    void MoveOver(Ref* f);
	void update(float) override;
private:
    float _positionX;
    float _destinationX;
    float _timeX;
    bool _isScored;//用来标记当前管道是否已被记分,防止重复记分
    
};

class PipeLayer: public cocos2d::Layer
{
public:
    virtual bool init();
	void stopMovePipes();
    CREATE_FUNC(PipeLayer);
private:
	cocos2d::Node* _pipes1;
	cocos2d::Node* _pipes2;
};
#endif // __PIPELAYER_H__
