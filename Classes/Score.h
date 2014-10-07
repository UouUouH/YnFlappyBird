#ifndef _SCORE_
#define _SCORE_
#include "cocos2d.h"

class Score:public cocos2d::Node
{
public:
	bool virtual init();
	static Score* getInstance();
	void addScore();
	int getScore();
	void initScore();
private:
	int _score;
	cocos2d::Label* _scoreLabel;
	
};

class TopScore
{
public:
	static TopScore* getInstance();
	int getTopScore();
	void SaveTopScore(int topScore);
private:
	void initTopScoreFile();
};
#endif