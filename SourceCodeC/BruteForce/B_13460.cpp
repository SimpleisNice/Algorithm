#include <iostream>
#include <algorithm>
#define MAX_MOVE 11

using namespace std;

char ball_map[10][10];
bool ball_move[10][10][2];
int move_x[] = { 0,0,-1,1 };
int move_y[] = { -1,1,0,0 };

int min_move = MAX_MOVE;
int n, m;

bool move_check(int x, int y)
{
	if (x > 0 && x < n - 1 && y > 0 && y < m - 1)
		return true;
	return false;
}
void move(pair<int, int> red, pair<int, int> blue, int move_count, bool end)
{
	if (end)
	{
		min_move = min(min_move, move_count);
		return;
	}
	if (move_count >= MAX_MOVE)
		return;
	for (int i = 0; i < 4; ++i)
	{
		int index_r = 0;

		bool r_pass_check = false;
		bool r_goal_check = false;

		while (true)
		{
			int r_x = red.first + move_x[i] * index_r;
			int r_y = red.second + move_y[i] * index_r;

			if (move_check(r_x, r_y))
			{
				if (ball_map[r_x][r_y] == '#')
				{
					--index_r;
					break;
				}
				if (r_x == blue.first && r_y == blue.second)
					r_pass_check = true;
				if (ball_map[r_x][r_y] == 'O')
				{
					r_goal_check = true;
					break;
				}
				++index_r;
			}
			else
			{
				--index_r;
				break;
			}
		}

		int index_b = 0;
		bool b_pass_check = false;
		bool b_goal_check = false;

		if (r_pass_check)
		{
			if (r_goal_check)
				continue;
			index_b = index_r;
			index_r -= 1;
		}
		else
		{
			while (true)
			{
				int b_x = blue.first + move_x[i] * index_b;
				int b_y = blue.second + move_y[i] * index_b;

				if (move_check(b_x, b_y))
				{
					if (ball_map[b_x][b_y] == '#')
					{
						--index_b;
						break;
					}
					if (b_x == red.first && b_y == red.second)
						b_pass_check = true;
					if (ball_map[b_x][b_y] == 'O')
					{
						b_goal_check = true;
						break;
					}
					++index_b;
				}
				else
				{
					--index_b;
					break;
				}
			}
			if (b_pass_check)
			{
				index_r = index_b;
				index_b -= 1;
			}
		}
		if (b_goal_check)
			continue;
		if (r_goal_check)
		{
			move(red, blue, move_count + 1, true);
		}
		if (ball_move[red.first + move_x[i] * index_r][red.second + move_y[i] * index_r][0] && ball_move[blue.first + move_x[i] * index_b][blue.second + move_y[i] * index_b][1])
			continue;
		else if (!ball_move[red.first + move_x[i] * index_r][red.second + move_y[i] * index_r][0] && ball_move[blue.first + move_x[i] * index_b][blue.second + move_y[i] * index_b][1])
		{
			ball_move[red.first + move_x[i] * index_r][red.second + move_y[i] * index_r][0] = true;
			move(make_pair(red.first + move_x[i] * index_r, red.second + move_y[i] * index_r), make_pair(blue.first + move_x[i] * index_b, blue.second + move_y[i] * index_b), move_count + 1, false);
			ball_move[red.first + move_x[i] * index_r][red.second + move_y[i] * index_r][0] = false;
		}
		else if (ball_move[red.first + move_x[i] * index_r][red.second + move_y[i] * index_r][0] && !ball_move[blue.first + move_x[i] * index_b][blue.second + move_y[i] * index_b][1])
		{
			ball_move[blue.first + move_x[i] * index_b][blue.second + move_y[i] * index_b][1] = true;
			move(make_pair(red.first + move_x[i] * index_r, red.second + move_y[i] * index_r), make_pair(blue.first + move_x[i] * index_b, blue.second + move_y[i] * index_b), move_count + 1, false);
			ball_move[blue.first + move_x[i] * index_b][blue.second + move_y[i] * index_b][1] = false;
		}
		else
		{
			ball_move[red.first + move_x[i] * index_r][red.second + move_y[i] * index_r][0] = true;
			ball_move[blue.first + move_x[i] * index_b][blue.second + move_y[i] * index_b][1] = true;
			move(make_pair(red.first + move_x[i] * index_r, red.second + move_y[i] * index_r), make_pair(blue.first + move_x[i] * index_b, blue.second + move_y[i] * index_b), move_count + 1, false);
			ball_move[red.first + move_x[i] * index_r][red.second + move_y[i] * index_r][0] = false;
			ball_move[blue.first + move_x[i] * index_b][blue.second + move_y[i] * index_b][1] = false;
		}
	}
}
int main(void)
{
	pair<int, int> ball_pos[2];
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> ball_map[i][j];

			if (ball_map[i][j] == '#' || ball_map[i][j] == '.' || ball_map[i][j] == 'O')
				continue;
			if (ball_map[i][j] == 'R')
			{
				ball_pos[0] = make_pair(i, j);
				ball_move[i][j][0] = true;
			}
			if (ball_map[i][j] == 'B')
			{
				ball_pos[1] = make_pair(i, j);
				ball_move[i][j][1] = true;
			}
		}
	}

	move(ball_pos[0], ball_pos[1], 0, false);

	cout << min_move << '\n';
	return 0;
}