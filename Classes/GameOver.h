#ifndef _GAMEOVER_
#define _GAMEOVER_

#include "cocos2d.h"
USING_NS_CC;
class Scoreboard: public cocos2d::Node
{
public:
	virtual bool init();
	CREATE_FUNC(Scoreboard);
	int getScore();
	int getTopScore();
private:
	int _tempScore;
	Label* _scoreLabel;
	void addScoreAnimation(float);
	void SaveTopScore(int n);
};
class GameOver:
	public cocos2d::Node
{
public:
	
	virtual bool init();
	CREATE_FUNC(GameOver);
	void createMenu();
	void playAgain();
	void GetRank();
};


#endif //_GAMEOVER_