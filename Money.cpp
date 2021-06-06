#include"Money.h"
#include"Niuniu.h"
#include<iostream>
using namespace std;

BetMoney::BetMoney(int newPlayerMoney)
{
	newPlayerMoney = 0;
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

int BetMoney::WOrLMoney()
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
		return money * 1;
}
void BetMoney::MoneyLessThanZero()
{
	if (money <= 0)
		cout << "Game Over"<<endl;
	cout << "You Don't have enough Money to Play";
}
bool BetMoney::MoneyMoreThanZero()
{
	if (money <= 0)
		return 0;
	else
		return 1;
}