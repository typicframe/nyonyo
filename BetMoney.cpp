#include"BetMoney.h"
#include"Niuniu.h"
#include<iostream>
using namespace std;

BetMoney::BetMoney(int newPlayerMoney)
{
	money = newPlayerMoney;
}

void BetMoney::setMoney(int money)
{
	this->money = money;
}
int BetMoney::getMoney()
{
	return money;
}

int BetMoney::winOrLostMoney()
{
	if (isGreatNiuniu())
		return money * 6;
	else if (isCommonNiuniu())
		return money * 4;
	else if (isNiuniu7ToNiuniu9())
		return money * 3;
	else if (isNiuniu1ToNiuniu6())
		return money * 2;
	else if (isMaleOolong())
		return money * 1;
	else
		return -money * 1;
}
void BetMoney::isMoneyBigThanZero()
{
	if (money <= 0)
		cout << "請不要亂來!!!\n";
}
bool BetMoney::IsMoneyBigThanZero()
{
	if (money <= 0)
		return 0;
	else
		return 1;
}