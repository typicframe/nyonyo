#ifndef WASHCARD_H
#define WASHCARD_H

#include<string>
using namespace std;

class washCard
{
private:
	static const int size = 5;
	int card1[size], card2[size];//card1:數字  card2:花色
	string card3[size];//card3:花色
	int finallyCard[size][2];//前面:花色   後面:數字
public:
	washCard();//洗牌，未排列大小

	int getFinallyCard(int);
	void sequenceCard();//牌從小排到大
	void printWashCard();//給玩家看的牌
};

#endif