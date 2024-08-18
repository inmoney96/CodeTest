#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    //answer = { 가장 작은 세로, 가장 작은 가로, 가장 큰 세로, 가장 큰 가로}

    //가장 작은 세로 탐색 (가로로 진행)
    for (int h = 0; h < wallpaper.size(); ++h)
    {
        for (int w = 0; w < wallpaper[h].size(); ++w)
        {
            if (wallpaper[h][w] == '#')
            {
                answer.push_back(h);
                h = wallpaper.size();
                break;
            }
        }
    }

    //가장 작은 가로 탐색 (세로로 진행)
    for (int w = 0; w < wallpaper[0].size(); ++w)
    {
        for (int h = 0; h < wallpaper.size(); ++h)
        {
            if (wallpaper[h][w] == '#')
            {
                answer.push_back(w);
                w = wallpaper[0].size();
                break;
            }
        }
    }

    ////가장 큰 세로 탐색 (가로로 진행)
    for (int h = wallpaper.size() - 1; h >= 0; --h)
    {
        for (int w = wallpaper[h].size() - 1; w >= 0; --w)
        {
            if (wallpaper[h][w] == '#')
            {
                answer.push_back(h+1);
                h = -1;
                break;
            }
        }
    }

    //가장 큰 가로 탐색 (세로로 진행)
    for (int w = wallpaper[0].size() - 1; w >= 0; --w)
    {
        for (int h = wallpaper.size() - 1; h >= 0; --h)
        {
            if (wallpaper[h][w] == '#')
            {
                answer.push_back(w+1);
                w = -1;
                break;
            }
        }
    }

    return answer;
}

int main() {
    solution({ ".....", "....#" });
    return 0;
}