#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

map<pair<int, int>, int> point_pos;

char room_map[20][20];
int move_check[20][20];
int move_count[12][12];

int move_x[] = {0, 0, -1, 1};
int move_y[] = {-1, 1, 0, 0};

int w, h;

int BFS()
{
    queue<pair<int, int>> temp_q;
    memset(move_count, -1, sizeof(move_count));
    for (auto it = point_pos.begin(); it != point_pos.end(); ++it)
    {
        int index = it->second;
        temp_q.push(make_pair(it->first.first, it->first.second));

        memset(move_check, -1, sizeof(move_check));
        move_check[it->first.first][it->first.second] = 0;
        move_count[index][index] = 0;

        while (!temp_q.empty())
        {
            int x = temp_q.front().first;
            int y = temp_q.front().second;
            temp_q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int pos_x = move_x[i] + x;
                int pos_y = move_y[i] + y;

                if (pos_x >= 0 && pos_x < h && pos_y >= 0 && pos_y < w)
                {
                    if (room_map[pos_x][pos_y] == 'x')
                        continue;
                    if (move_check[pos_x][pos_y] == -1)
                    {
                        move_check[pos_x][pos_y] = move_check[x][y] + 1;
                        if (room_map[pos_x][pos_y] == 'o' || room_map[pos_x][pos_y] == '*')
                        {
                            move_count[index][point_pos[make_pair(pos_x, pos_y)]] = move_check[pos_x][pos_y];
                        }
                        temp_q.push(make_pair(pos_x, pos_y));
                    }
                }
            }
        }
        for (int i = 0; i < point_pos.size(); ++i)
        {
            if (move_count[index][i] == -1)
                return -1;
        }
    }
    return 0;
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (true)
    {
        int index = 0;
        vector<int> temp_vector(1);
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        for (int i = 0; i < h; ++i)
        {
            cin >> room_map[i];

            for (int j = 0; j < w; ++j)
            {
                if (room_map[i][j] == '.' || room_map[i][j] == 'x')
                    continue;
                if(room_map[i][j] == 'o')
                    temp_vector[0] = index;
                else
                    temp_vector.push_back(index);
                point_pos.insert(make_pair(make_pair(i, j), index++));
            }
        }
        if (BFS() == -1)
            cout << -1 << '\n';
        else
        {
            int min_value = -1;
            int item_size = temp_vector.size();
            do
            {
                int value = 0;
                for (int i = 0; i < item_size - 1; ++i)
                {
                    value += move_count[temp_vector[i]][temp_vector[i + 1]];
                }
                if (min_value == -1 || min_value > value)
                    min_value = value;
            } while (next_permutation(temp_vector.begin() + 1, temp_vector.end()));
            cout << min_value << '\n';
        }
        point_pos.clear();
    }
    return 0;
}