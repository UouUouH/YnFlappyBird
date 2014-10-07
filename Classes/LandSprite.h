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


class Land : public cocos2d::Node
{
public:
	virtual bool init();
	void moveLand(float);
	void stopLandMove();
	CREATE_FUNC(Land);
	private:
	cocos2d::Sprite* _spriteland1;
	cocos2d::Sprite* _spriteland2;
};

#endif //_LandSprite_