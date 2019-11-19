#include <iostream>
#include <algorithm>
#define MAX_GOAL_MOVE 100000000
using namespace std;

char board_map[10][10];
bool ball_move[10][10][2]; // red : 0, blue : 1


int n, m;
int min_move = MAX_GOAL_MOVE;


void Go(pair<int,int>, pair<int,int>, int);

void ball_move_up(const pair<int, int> red_pos, const pair<int, int> blue_pos, int move)
{
	pair<int, int> temp_red_pos = red_pos;
	pair<int, int> temp_blue_pos = blue_pos;
	bool check_blue_ball = false;
	bool goal_check = false;
	int index = 0;
	
	while (true)
	{
		if (board_map[temp_red_pos.first - 1 - index][temp_red_pos.second] != '#')
		{
			if (board_map[temp_red_pos.first - 1 - index][temp_red_pos.second] != 'B')
				check_blue_ball = true;
			if (board_map[temp_red_pos.first - 1 - index][temp_red_pos.second] == 'O')
			{	
				goal_check = true;
				break;
			}
			++index;
		}
		else
		{
			temp_red_pos.first -= index;
			break;
		}
	}

	if (check_blue_ball && !goal_check)
	{
		temp_blue_pos.first = temp_red_pos.first;
		temp_red_pos.first = temp_blue_pos.first + 1;
	}
	else
	{
		index = 0;
		while (true)
		{
			if (board_map[temp_blue_pos.first - 1 - index][temp_blue_pos.second] != '#')
			{
				if (board_map[temp_blue_pos.first - 1 - index][temp_blue_pos.second] != 'O')
					return;				
				++index;
			}
			else
			{
				temp_blue_pos.first -= index;
				break;
			}
		}
	}
	if(goal_check)
	{
		min_move = min(min_move, move + 1);
		return;
	}
	if (ball_move[temp_red_pos.first][temp_red_pos.second][0] && ball_move[temp_blue_pos.first][temp_blue_pos.second][1])
		return;
	else
	{
		ball_move[temp_red_pos.first][temp_red_pos.second][0] = true;
		ball_move[temp_blue_pos.first][temp_blue_pos.second][1] = true;
		Go(temp_red_pos, temp_blue_pos, move + 1);
		ball_move[temp_red_pos.first][temp_red_pos.second][0] = false;
		ball_move[temp_blue_pos.first][temp_blue_pos.second][1] = false;
	}
}
void ball_move_down(const pair<int, int> red_pos, const pair<int, int> blue_pos, int move)
{
	pair<int, int> temp_red_pos = red_pos;
	pair<int, int> temp_blue_pos = blue_pos;
	bool check_blue_ball = false;
	bool goal_check = false;
	int index = 0;
	
	while (true)
	{
		if (board_map[temp_red_pos.first + 1 + index][temp_red_pos.second] != '#')
		{
			if (board_map[temp_red_pos.first + 1 + index][temp_red_pos.second] != 'B')
				check_blue_ball = true;
			if (board_map[temp_red_pos.first + 1 + index][temp_red_pos.second] == 'O')
			{	
				goal_check = true;
				break;
			}
			++index;
		}
		else
		{
			temp_red_pos.first += index;
			break;
		}
	}

	if (check_blue_ball && !goal_check)
	{
		temp_blue_pos.first = temp_red_pos.first;
		temp_red_pos.first = temp_blue_pos.first - 1;
	}
	else
	{
		index = 0;
		while (true)
		{
			if (board_map[temp_blue_pos.first + 1 + index][temp_blue_pos.second] != '#')
			{
				if (board_map[temp_blue_pos.first + 1 + index][temp_blue_pos.second] != 'O')
					return;				
				++index;
			}
			else
			{
				temp_blue_pos.first += index;
				break;
			}
		}
	}
	if(goal_check)
	{
		min_move = min(min_move, move + 1);
		return;
	}
	if (ball_move[temp_red_pos.first][temp_red_pos.second][0] && ball_move[temp_blue_pos.first][temp_blue_pos.second][1])
		return;
	else
	{
		ball_move[temp_red_pos.first][temp_red_pos.second][0] = true;
		ball_move[temp_blue_pos.first][temp_blue_pos.second][1] = true;
		Go(temp_red_pos, temp_blue_pos, move + 1);
		ball_move[temp_red_pos.first][temp_red_pos.second][0] = false;
		ball_move[temp_blue_pos.first][temp_blue_pos.second][1] = false;
	}
}
void ball_move_left(const pair<int, int> red_pos, const pair<int, int> blue_pos, int move)
{
	pair<int, int> temp_red_pos = red_pos;
	pair<int, int> temp_blue_pos = blue_pos;
	bool check_blue_ball = false;
	bool goal_check = false;
	int index = 0;
	
	while (true)
	{
		if (board_map[temp_red_pos.first][temp_red_pos.second - 1 - index] != '#')
		{
			if (board_map[temp_red_pos.first][temp_red_pos.second - 1 - index] != 'B')
				check_blue_ball = true;
			if (board_map[temp_red_pos.first][temp_red_pos.second - 1 - index] == 'O')
			{	
				goal_check = true;
				break;
			}
			++index;
		}
		else
		{
			temp_red_pos.second -= index;
			break;
		}
	}

	if (check_blue_ball && !goal_check)
	{
		temp_blue_pos.second = temp_red_pos.second;
		temp_red_pos.second = temp_blue_pos.second + 1;
	}
	else
	{
		index = 0;
		while (true)
		{
			if (board_map[temp_blue_pos.first][temp_blue_pos.second - 1 - index] != '#')
			{
				if (board_map[temp_blue_pos.first][temp_blue_pos.second - 1 - index] != 'O')
					return;				
				++index;
			}
			else
			{
				temp_blue_pos.second -= index;
				break;
			}
		}
	}
	if(goal_check)
	{
		min_move = min(min_move, move + 1);
		return;
	}
	if (ball_move[temp_red_pos.first][temp_red_pos.second][0] && ball_move[temp_blue_pos.first][temp_blue_pos.second][1])
		return;
	else
	{
		ball_move[temp_red_pos.first][temp_red_pos.second][0] = true;
		ball_move[temp_blue_pos.first][temp_blue_pos.second][1] = true;
		Go(temp_red_pos, temp_blue_pos, move + 1);
		ball_move[temp_red_pos.first][temp_red_pos.second][0] = false;
		ball_move[temp_blue_pos.first][temp_blue_pos.second][1] = false;
	}
}
void ball_move_right(const pair<int, int> red_pos, const pair<int, int> blue_pos, int move)
{
	pair<int, int> temp_red_pos = red_pos;
	pair<int, int> temp_blue_pos = blue_pos;
	bool check_blue_ball = false;
	bool goal_check = false;
	int index = 0;
	
	while (true)
	{
		if (board_map[temp_red_pos.first][temp_red_pos.second + 1 + index] != '#')
		{
			if (board_map[temp_red_pos.first][temp_red_pos.second + 1 + index] != 'B')
				check_blue_ball = true;
			if (board_map[temp_red_pos.first][temp_red_pos.second + 1 + index] == 'O')
			{	
				goal_check = true;
				break;
			}
			++index;
		}
		else
		{
			temp_red_pos.second += index;
			break;
		}
	}

	if (check_blue_ball && !goal_check)
	{
		temp_blue_pos.second = temp_red_pos.second;
		temp_red_pos.second = temp_blue_pos.second - 1;
	}
	else
	{
		index = 0;
		while (true)
		{
			if (board_map[temp_blue_pos.first][temp_blue_pos.second + 1 + index] != '#')
			{
				if (board_map[temp_blue_pos.first][temp_blue_pos.second + 1 + index] != 'O')
					return;				
				++index;
			}
			else
			{
				temp_blue_pos.second += index;
				break;
			}
		}
	}
	if(goal_check)
	{
		min_move = min(min_move, move + 1);
		return;
	}
	if (ball_move[temp_red_pos.first][temp_red_pos.second][0] && ball_move[temp_blue_pos.first][temp_blue_pos.second][1])
		return;
	else
	{
		ball_move[temp_red_pos.first][temp_red_pos.second][0] = true;
		ball_move[temp_blue_pos.first][temp_blue_pos.second][1] = true;
		Go(temp_red_pos, temp_blue_pos, move + 1);
		ball_move[temp_red_pos.first][temp_red_pos.second][0] = false;
		ball_move[temp_blue_pos.first][temp_blue_pos.second][1] = false;
	}
}

void Go(const pair<int, int> red_pos, const pair<int, int> blue_pos, int move)
{
	ball_move_up(red_pos, blue_pos, move);
	ball_move_down(red_pos, blue_pos, move);
	ball_move_left(red_pos, blue_pos, move);
	ball_move_right(red_pos, blue_pos, move);
}

int main(void)
{

	cin >> n >> m;
	pair<int, int> item_pos[2];
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board_map[i][j];
			if (board_map[i][j] == '.' || board_map[i][j] == '#')
				continue;

			if (board_map[i][j] == 'R')
				item_pos[0] = make_pair(i, j);
			else if (board_map[i][j] == 'B')
				item_pos[1] = make_pair(i, j);
		}
	}

	Go(item_pos[0], item_pos[1], 0);

	cout << min_move << '\n';
	return 0;
}