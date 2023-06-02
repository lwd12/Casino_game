#include "data.h"

void Datas::setper(int per) { this->per = per; }
void Datas::setupdown(int updown) { this->updown = updown; }
void Datas::setprice() { price[0] = START; }
void Datas::setprice(int price) { this->price[day + 1] = price; }
void Datas::setmoney(int money) { this->money = money; }
void Datas::setstock(int stock) { this->stock = stock; }
void Datas::setday(int day) { this->day = day; }
void Datas::settotal(int total) { this->total = total; }
void Datas::setgetprice(int allprice[]) 
{
        for (int i = 0; i < 11; i++)
                allprice[i] = price[i];
}

int Datas::getper() { return per; }
int Datas::getupdown() { return updown; }
int Datas::getprice() {return price[day];}
int Datas::getmoney() { return money; }
int Datas::getstock() { return stock; }
int Datas::gettotal() { return total; }
int Datas::getday() { return day; }
