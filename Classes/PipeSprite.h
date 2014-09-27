#ifndef _PIPESPRITE_
#define _PIPESPRITE_
#include "cocos2d.h"
USING_NS_CC;

class PipeSprite :
	public cocos2d::Sprite
{
public:
   //tag = 1 up pipe, tag = 2 down pipe
	bool init(int tag);
    
   //tag = 1 up pipe, tag = 2 down pipe
	static PipeSprite* create(int tag);
   
};

#endif