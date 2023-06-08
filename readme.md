Stock_GAME
=============
* A game where the player with the most money at the end wins, based on predicting a graph using stock data.   

<img src="/main.png" width="50%" height="40%" title="px(픽셀) 크기 설정" alt="main"></img></br>

## Function   
> Creating an algorithm that randomly generates changes in the next stock price based on previous stock price data.   
> Drawing a graph based on stock prices and changing the colors.   
> Calculating the final winner based on the sum of stock holdings and cash balance at the end.

## Img  
* Data initialization: Declare variables such as player, buy[], key, including the data.h header file, and initialize the array of structures Datas dt[5].
```C++
#include "data.h"

int player = 1, buy[5], key = 0;
Datas dt[5]; // dt[0] = �ý���, dt[1] = p1, dt[2] = p2, dt[3] = p3, dt[4] = p4
```
* Entry point (main): Initialize player data for dt[1] to dt[4], set the stock price for dt[0], and set the growth rate for dt[0].
```C++
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

```
<img src="/start.png" width="50%" height="40%" title="px(픽셀) 크기 설정" alt="setting"></img></br>


* Update player data: Call the playerdata() function to update the player's funds and stocks, and reset the trading volume.
```C++
void playerdata() //유저 정보 저장
{
	for (int i = 1; i <= 4; i++)
	{
		dt[i].setstock(dt[i].getstock() + buy[i]);
		dt[i].setmoney(dt[i].getmoney() - dt[0].getprice() * buy[i]); //자금 갱신
		buy[i] = 0;
		//dt[i].settotal(dt[i].getmoney() + dt[i].getstock() * dt[0].getprice()); //총 재산 갱신
	}
}
```
<img src="/change.png" width="50%" height="40%" title="px(픽셀) 크기 설정" alt="shadow"></img></br>


* Stock price adjustment: Call the Rand_Graph() function to randomly increase or decrease the stock price.
```C++
void Rand_Graph()// 주식 랜덤 함수
{
	srand(time(NULL)); // 랜덤

	int temp1 = dt[0].getprice();
	int temp2;
	
	if ((rand() % 100) + 1 >= dt[0].getper()) //감소
	{
		temp2 = dt[0].getprice() - (rand() % 40 + 1);
		if (temp2 < min_val)
			dt[0].setprice(min_val);
		else
			dt[0].setprice(temp2);
	}	
	else //증가
	{
		temp2 = dt[0].getprice() + (rand() % 40 + 1);



		if (temp2 > max_val)
			dt[0].setprice(max_val);
		else
			dt[0].setprice(temp2);
	}

	if (temp1 < temp2)
	{
		dt[0].setper(dt[0].getper() - 10);
	}
	else if (temp1 > temp2)
	{
		dt[0].setper(dt[0].getper() + 10);
	}

}
```


* Game end and result output: The game will end after 10 days. Call the final() function to check the final results, and call the gameover() function to print the results.
```C++
int final() //최종경과 계산 함수
{
	int i=1, temp;
	int winner; //우승자 번호를 여기다 저장해주세요 1~4
	
	for (temp=i; i < 5; i++)
	{
		if (dt[temp].gettotal() < dt[i].gettotal())
			temp = i;
	}
	winner = temp;
	return winner;
}
```
<img src="/final.png" width="50%" height="40%" title="px(픽셀) 크기 설정" alt="mouse_event"></img></br>



