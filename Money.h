#ifndef Money_H
#define Money_H

#include"Niuniu.h"

class BetMoney : public Niuniu
{
public:
	BetMoney(int);
	void setMoney(int);
	int getMoney();
	int WOrLMoney();
	void MoneyLessThanZero();
	bool MoneyMoreThanZero();
private:
	int money;
};

#endif
