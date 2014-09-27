#ifndef _LandSprite_
#define _LandSprite_

#include "cocos2d.h"
USING_NS_CC;

class LandSprite :
	public cocos2d::Sprite
{
public:
	//n : 精灵偏离远点的距离是自己content的宽度的几倍
	bool init(float n);
	//n : 精灵偏离远点的距离是自己content的宽度的几倍
	static LandSprite* create(float n);
};

#endif //_LandSprite_