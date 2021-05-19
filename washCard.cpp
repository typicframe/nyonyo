#include"washCard.h"
#include<iostream>
#include<iomanip>
#include<ctime>//srand(time(0));  srand(12321);
#include<cstdlib>
#include<string>
#include<sstream>
using namespace std;

washCard::washCard()
{
	srand(time(0));
	for (int i = 0; i < size; i++)
		card2[i] = rand() % 4 + 1;
	for (int i = 0; i < size; i++)
		card1[i] = rand() % 12 + 1;
	for (int i = 0; i < size; i++)
	{
		finallyCard[i][0] = card2[i];
		finallyCard[i][1] = card1[i];
	}
	sequenceCard();
}

int washCard::getFinallyCard(int index)
{
	return finallyCard[index][1];
}
void washCard::sequenceCard()
{
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size - 1; i++)
			{
				if (finallyCard[i][0] > finallyCard[i + 1][0])
				{
					int a = finallyCard[i][0];
					finallyCard[i][0] = finallyCard[i + 1][0];
					finallyCard[i + 1][0] = a;
					int b = finallyCard[i][1];
					finallyCard[i][1] = finallyCard[i + 1][1];
					finallyCard[i + 1][1] = b;
				}
			}
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (finallyCard[i][0] == finallyCard[i + 1][0])
		{
			if (finallyCard[i][1] > finallyCard[i + 1][1])
			{
				int b = finallyCard[i + 1][1];
				finallyCard[i + 1][1] = finallyCard[i][1];
				finallyCard[i][1] = b;
			}
		}
	}
}
void washCard::printWashCard()
{
/*	for (int i = 0; i < size; i++)
		cout << card3[i] << "(" << card2[i] << ") " << card1[i] << endl;
	sequenceCard();
	for (int i = 0; i < size; i++)
		cout << finallyCard[i][0] << " " << finallyCard[i][1] << endl;*/
	for (int i = 0; i < size; i++)
	{
		if (finallyCard[i][0] == 1)
			cout << "    梅花 " << finallyCard[i][1] << endl;
		else if (finallyCard[i][0] == 2)
			cout << "    方塊 " << finallyCard[i][1] << endl;
		else if (finallyCard[i][0] == 3)
			cout << "    愛心 " << finallyCard[i][1] << endl;
		else
			cout << "    黑桃 " << finallyCard[i][1] << endl;
	}
}