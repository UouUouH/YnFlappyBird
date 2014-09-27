#ifndef __PIPELAYER_H__
#define __PIPELAYER_H__

#include "cocos2d.h"
//in fact , those are a pair of pipes, which including a upward pipe and a downward pipe
class Pipes: public cocos2d::Sprite
{
public:
   
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(bool isOffsetX);
    
    // a selector callback
    static Pipes* create(bool isOffsetX);
	//void LoadingFinshed();
    void MovePipes();
    
    void MoveOver(Ref* f);
private:
    float _positionX;
    float _destinationX;
    float _timeX;
    
};

class PipeLayer: public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(PipeLayer);
};
#endif // __PIPELAYER_H__
