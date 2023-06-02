#include "data.h"

int player = 1, buy[5], key = 0;
Datas dt[5]; // dt[0] = �ý���, dt[1] = p1, dt[2] = p2, dt[3] = p3, dt[4] = p4

extern void Rand_Graph();
extern void ui();
extern void typing();
extern void playerdata();
extern int final();
extern void gameover(int);
extern void ui_sec();
;

int main()
{
	for (int i = 1; i <= 4; i++)
	{
		dt[i].setmoney(STARTMONEY);
		dt[i].settotal(5000);
	}
	dt[0].setprice();
	dt[0].setper(PERSTART);
	playerdata();

	while (dt[0].getday() < 10)
	{
		system("cls");
		ui();
		ui_sec();
		typing();
		Rand_Graph();
		playerdata();
		dt[0].setday(dt[0].getday() + 1); // dt[0] 1  dt[10] 11
		for (int i = 1; i <= 4; i++)
			dt[i].settotal(dt[i].getmoney() + dt[i].getstock() * dt[0].getprice());
	}
	system("cls");
	ui();
	ui_sec();
	gameover(final());
}