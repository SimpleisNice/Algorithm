#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char game_map[10][10];
bool ball_move[10][10][2];
int move_index = -1;

int move_x[] = { 0, 0, -1, 1 };
int move_y[] = { -1, 1, 0, 0 };
void move_ball(pair<int, int> red, pair<int, int> blue, int move_count)
{
	if (move_count > 10)
		return;

	for (int i = 0; i < 4; ++i)
	{
		pair<int, int> temp_red = red;
		pair<int, int> temp_blue = blue;
		int red_index = 0;
		int blue_index = 0;

		bool red_pass = false, red_end = false;
		bool blue_pass = false, blue_end = false;

		while (true)
		{
			int x = temp_red.first + move_x[i] * red_index;
			int y = temp_red.second + move_y[i] * red_index;

			if (x <= 0 || x >= n - 1 || y <= 0 || y >= m - 1)
				break;
			if (game_map[x][y] == '#')
				break;
			if (x == blue.first && y == blue.second)
				red_pass = true;
			if (game_map[x][y] == 'O')
				red_end = true;

			++red_index;
		}
		--red_index;

		temp_red.first = red.first +  move_x[i] * red_index;
		temp_red.second = red.second + move_y[i] * red_index;

		if (red_pass)
		{
			temp_blue.first = temp_red.first;
			temp_blue.second = temp_red.second;
			temp_red.first = red.first + move_x[i] * (red_index - 1);
			temp_red.second = red.second + move_y[i] * (red_index - 1);
		}
		else
		{	// blue move
			while (true)
			{
				int x = temp_blue.first + move_x[i] * blue_index;
				int y = temp_blue.second + move_y[i] * blue_index;

				if (x <= 0 || x >= n - 1 || y <= 0 || y >= m - 1)
					break;
				if (game_map[x][y] == '#')
					break;
				if (x == red.first && y == red.second)
					blue_pass = true;
				if (game_map[x][y] == 'O')
				{
					blue_end = true;
					break;
				}
				++blue_index;
			}
			--blue_index;

			temp_blue.first = blue.first + move_x[i] * blue_index;
			temp_blue.second = blue.second + move_y[i] * blue_index;
			if (blue_pass)
			{
				temp_blue.first = blue.first + move_x[i] * (blue_index - 1);
				temp_blue.second = blue.second + move_y[i] * (blue_index - 1);
			}
		}

		if (red_end && !blue_end)
		{
			if (move_index == -1 || move_index > move_count)
				move_index = move_count;
			continue;
		}
		else if (blue_end)
			continue;

		if (ball_move[temp_red.first][temp_red.second][0] && ball_move[temp_blue.first][temp_blue.second][1])
			continue;
		if (ball_move[temp_red.first][temp_red.second][0])
		{
			ball_move[temp_blue.first][temp_blue.second][1] = true;
			move_ball(make_pair(temp_red.first, temp_red.second), make_pair(temp_blue.first, temp_blue.second), move_count + 1);
			ball_move[temp_blue.first][temp_blue.second][1] = false;
		}
		else
		{
			if (ball_move[temp_blue.first][temp_blue.second][1])
			{
				ball_move[temp_red.first][temp_red.second][0] = true;
				move_ball(make_pair(temp_red.first, temp_red.second), make_pair(temp_blue.first, temp_blue.second), move_count + 1);
				ball_move[temp_red.first][temp_red.second][0] = false;
			}
			else
			{
				ball_move[temp_red.first][temp_red.second][0] = true;
				ball_move[temp_blue.first][temp_blue.second][1] = true;
				move_ball(make_pair(temp_red.first, temp_red.second), make_pair(temp_blue.first, temp_blue.second), move_count + 1);
				ball_move[temp_red.first][temp_red.second][0] = false;
				ball_move[temp_blue.first][temp_blue.second][1] = false;
			}
		}
	}
}
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	pair<int, int> red, blue;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> game_map[i];
		for (int j = 0; j < m; ++j)
		{
			if (game_map[i][j] == 'R')
			{
				red = make_pair(i, j);
				ball_move[i][j][0] = true;
			}
			else if (game_map[i][j] == 'B')
			{
				blue = make_pair(i, j);
				ball_move[i][j][1] = true;
			}
		}
	}

	move_ball(red, blue, 1);

	cout << move_index << '\n';

	return 0;
}