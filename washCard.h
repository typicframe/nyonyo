#ifndef WASHCARD_H
#define WASHCARD_H

#include<string>
using namespace std;

class washCard
{
private:
	static const int size = 5;
	int card1[size], card2[size];//card1:�Ʀr  card2:���
	string card3[size];//card3:���
	int finallyCard[size][2];//�e��:���   �᭱:�Ʀr
public:
	washCard();//�~�P�A���ƦC�j�p

	int getFinallyCard(int);
	void sequenceCard();//�P�q�p�ƨ�j
	void printWashCard();//�����a�ݪ��P
};

#endif