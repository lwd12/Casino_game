#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include<ctime>
#include <windows.h>
#include <iomanip>

#define START 90 // ������
#define PERSTART 50
#define DATE 11
#define STARTMONEY 5000

using namespace std;

class Datas {
private:
	int per; //Ȯ��
	int	updown; //�ְ�����
	int	price[DATE]; //�����ְ�

	int money; //�ڱ�
	int stock; //���� ��
	int total; //�� ���

	int day;
public:
	void setper(int per);
	void setupdown(int updown);
	void setprice();
	void setprice(int price);
	void setmoney(int money);
	void setstock(int stock);
	void settotal(int total);
	void setday(int day);
	void setgetprice(int allprice[]);

	int getprice();
	int getper();
	int getupdown();
	int getmoney();
	int getstock();
	int gettotal();
	int getday();
};

