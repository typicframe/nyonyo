#ifndef BETMONEY_H
#define BETMONEY_H

#include"Niuniu.h"

class BetMoney : public Niuniu
{
private:
	int money;
public:
	BetMoney(int = 0);

	void setMoney(int);
	int getMoney();

	int winOrLostMoney();
	void isMoneyBigThanZero();
	bool IsMoneyBigThanZero();
};

#endif