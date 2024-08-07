#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x = 0, y = 0;
    int maxX = park[0].size(), maxY = park.size();

    for (int i = 0; i < park.size(); ++i)
    {
        for (int j = 0; j < park[i].size(); ++j)
        {
            if (park[i][j] == 'S')
            {
                x = j;
                y = i;
            }
        }
    }

    // 루트 입력 받기
    for (int i = 0; i < routes.size(); ++i) {
        bool isFail = false;
        int move = routes[i][2]-'0';
        switch (routes[i][0])
        {
        case 'E':
        {
            if (x + move < maxX)
            {
                for (int q = x + 1; q <= x + move; ++q)
                {
                    if (park[y][q] == 'X')
                    {
                        isFail = true;
                        break;
                    }

                }
                if (isFail)
                {
                    break;
                }
                else 
                {
                    x = x + move;
                }
            }

        }

            break;

        case 'W':
        {
            if (x - move >= 0)
            {
                for (int q = x - 1; q >= x - move; --q)
                {
                    if (park[y][q] == 'X')
                    {
                        isFail = true;
                        break;
                    }

                }
                if (isFail)
                {
                    break;
                }
                else
                {
                    x = x - move;
                }
            }

        }
            break;

        case 'N':
        {
            if (y - move >= 0 )
            {
                for (int q = y - 1; q >= y - move; --q)
                {
                    if (park[q][x] == 'X')
                    {
                        isFail = true;
                        break;
                    }

                }
                if (isFail)
                {
                    break;
                }
                else
                {
                    y = y - move;
                }
            }

        }
            break;

        case 'S':
        {
            if (y + move < maxY)
            {
                for (int q = y + 1; q <= y + move; ++q)
                {
                    if (park[q][x] == 'X')
                    {
                        isFail = true;
                        break;
                    }

                }
                if (isFail)
                {
                    break;
                }
                else
                {
                    y = y + move;
                }
            }

        }
            break;
        }

    }

    answer.push_back(y);
    answer.push_back(x);
    return answer;
}