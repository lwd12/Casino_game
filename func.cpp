#include "data.h"

extern int player, buy[], key;
extern Datas dt[5];

int min_val = 30, max_val = 150;

void Rand_Graph()// �ֽ� ���� �Լ�
{
	srand(time(NULL)); // ����

	int temp1 = dt[0].getprice();
	int temp2;
	
	if ((rand() % 100) + 1 >= dt[0].getper()) //����
	{
		temp2 = dt[0].getprice() - (rand() % 40 + 1);
		if (temp2 < min_val)
			dt[0].setprice(min_val);
		else
			dt[0].setprice(temp2);
	}	
	else //����
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

void color_check(int main_col, int color_set[])
{
	if (main_col % 2 == 0)
	{
		if (color_set[(main_col / 2) - 1] == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (color_set[(main_col / 2) - 1] == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		}
		if (color_set[(main_col / 2) - 1] == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		}
	}
}

void draw_in(int a_graph)
{
	if (a_graph == 1)
		cout << "-";
	else if (a_graph == 2)
		cout << "|";
	else if (a_graph == 3)
		cout << "  ";
	else if (a_graph == 4)
		cout << "��";
}

void ui() //ȭ�� ǥ�� �Լ�
{
	int drawgraph[17][25] = {0,};
	int drawbox[47];
	int checkprice[11];
	int graph_col = 2;
	int color_set[11] = { 0, };
	dt->setgetprice(checkprice);

	for (int set = 0; set < 10; set++)
	{
		if (checkprice[set] < checkprice[set + 1])
			color_set[set + 1] = 1;
		else if(checkprice[set] > checkprice[set + 1])
			color_set[set + 1] = 2;
		else if (checkprice[set] = checkprice[set + 1])
			color_set[set + 1] = 0;
	}
	
	for (int bloc = 0; bloc < 11; bloc++)
	{
		int block2;
		int block = checkprice[bloc] / 10;
		if (checkprice[bloc] % 10 >= 0 && checkprice[bloc] % 10 <= 4)
			block2 = 1;
		else
			block2 = 2;
		if (block != 0)
		{
			for (int graph_rows = 15; graph_rows > (16 - (block + block2)); graph_rows--)
			{
				drawgraph[graph_rows][graph_col] = 4;
			}
		}
		graph_col += 2;
	}

	for (int main_rows = 0; main_rows < 17; main_rows++)
	{
		if (main_rows == 0 || main_rows == 16)
		{
			for (int box_col = 0; box_col < 47; box_col++)
			{
				drawbox[box_col] = 1;
				draw_in(drawbox[box_col]);
			}
		}
		else
		{
			for (int main_col = 0; main_col < 25; main_col++)
			{
				if (main_col == 0 || main_col == 24)
				{
					drawgraph[main_rows][main_col] = 2;
					draw_in(drawgraph[main_rows][main_col]);
				}
				else
				{
					if (drawgraph[main_rows][main_col] == 4)
					{
						color_check(main_col, color_set);
						draw_in(drawgraph[main_rows][main_col]);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					}
					else
					{
						drawgraph[main_rows][main_col] = 3;
						draw_in(drawgraph[main_rows][main_col]);
					}
				}
			}
		}
		cout << endl;
	}
}

void consol_move()
{
	if (player == 1)
	{
		cout << "��";
	}
	else if (player == 2)
	{
		cout << setw(22) << "��";
	}
	else if (player == 3)
	{
		cout << setw(42) <<"��";
	}
	else if (player == 4)
	{
		cout << setw(62) << "��";
	}
	cout << endl;
}

void player_data()
{
	cout << "�ں� : " << right << setw(3) << dt[1].getmoney();
	cout << right << setw(16) << "�ں� : " << dt[2].getmoney();
	cout << right << setw(16) << "�ں� : " << dt[3].getmoney();
	cout << right << setw(16) << "�ں� : " << dt[4].getmoney() << endl;

	cout << "�ҽ� �� : " << right << setw(3) << dt[1].getstock();
	cout << right << setw(17) << "�ҽ� �� : " << dt[2].getstock();
	cout << right << setw(19) << "�ҽ� �� : " << dt[3].getstock();
	cout << right << setw(19) << "�ҽ� �� : " << dt[4].getstock() << endl;

	cout << "��� : " << right << setw(3) << dt[1].gettotal();
	cout << right << setw(16) << "��� : " << dt[2].gettotal();
	cout << right << setw(16) << "��� : " << dt[3].gettotal();
	cout << right << setw(16) << "��� : " << dt[4].gettotal() << endl;

	cout << "�Ÿ� : " << right << setw(3) << buy[1];
	cout << right << setw(17) << "�Ÿ� : " << buy[2];
	cout << right << setw(19) << "�Ÿ� : " << buy[3];
	cout << right << setw(19) << "�Ÿ� : " << buy[4] << endl;
	consol_move();
}

void ui_sec()
{
	int ui_day = dt[0].getday() + 1;
	int day_price = dt->getprice();
	int upper = dt->getper();
	int downper = 100 - upper;

	cout << ui_day << "����" << "      �ְ� : " << day_price << "   ��� : " << upper << "%" << "   ����  : " << downper << "%" << endl;
	cout << endl;
	cout << "P1" << setw(20) << "P2" << setw(20) << "P3" << setw(20) << "P4";
	cout << endl;
	player_data();
}

void typing() 
{
	while (1) // ������Ʈ
	{
		key = _getch();
		if (key == 0 || key == 224) //���ڱ� �Էƾȵȴ� �ϸ� �̰� 0�̳� 224�� ����;;;
		{
			key = _getch();
			switch (key)
			{
			case 72: //��
				buy[player]++;
				if (buy[player] * dt[0].getprice() > dt[player].getmoney())
					buy[player]--;
				break;
			case 80: //��
				buy[player]--;
				if (dt[player].getstock()<-buy[player])
					buy[player]++;
				break;
			case 77: //��
				player++;
				if (player > 4)
					player = 1;
				break;
			case 75: //��
				player--;
				if (player < 1)
					player = 4;
				break;
			}
		}
		else if (key == 'z' || key == 'Z')
		{
			player = 1;
			break;
		}
		system("cls");
		ui();
		ui_sec();
	}
}

void playerdata() //���� ���� ����
{
	for (int i = 1; i <= 4; i++)
	{
		dt[i].setstock(dt[i].getstock() + buy[i]);
		dt[i].setmoney(dt[i].getmoney() - dt[0].getprice() * buy[i]); //�ڱ� ����
		buy[i] = 0;
		//dt[i].settotal(dt[i].getmoney() + dt[i].getstock() * dt[0].getprice()); //�� ��� ����
	}
}

int final() //������� ��� �Լ�
{
	int i=1, temp;
	int winner; //����� ��ȣ�� ����� �������ּ��� 1~4
	
	for (temp=i; i < 5; i++)
	{
		if (dt[temp].gettotal() < dt[i].gettotal())
			temp = i;
	}
	winner = temp;
	return winner;
}

void gameover(int winner)
{
	_getch();
	system("cls");
	if (winner == 1)
	{
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
	}
	if (winner == 2)
	{
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
	}
	if (winner == 3)
	{
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
	}
	if (winner == 4)
	{
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
		cout << "                    " << "�����������" << "�����������" << endl;
	}
	cout << "�����������" << "�����������" << "�����������" << "�����������" << endl;
	cout << "�����������" << "�����������" << "�����������" << "�����������" << endl;
	cout << "�����������" << "�����������" << "�����������" << "�����������" << endl;
	cout << "�����������" << "�����������" << "�����������" << "�����������" << endl;
	cout << "�����������" << "�����������" << "�����������" << "�����������" << endl;
	cout << "�����������" << "�����������" << "�����������" << "�����������" << endl;
	cout << "�����������" << "�����������" << "�����������" << "�����������" << endl;
	cout << "�����������" << "�����������" << "�����������" << "�����������" << endl;
	cout << "�����������" << "�����������" << "�����������" << "�����������" << endl;
}