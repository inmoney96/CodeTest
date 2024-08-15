#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> out;
    string buffer = "";

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == delimiter) {
            out.push_back(buffer);
            buffer.clear();
            continue;
        }
        buffer.push_back(str[i]);
    }
    out.push_back(buffer);

    return out;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int mans = friends.size();
    vector<string> give, given, buffer;
    vector<vector<int>> giftTable(mans, (vector<int>(mans, 0)));
    vector<int> giftIndex(mans, 0);
    map<string, int> friMap;
    for (int i = 0; i < friends.size(); i++)
    {
        friMap.insert({ friends[i], i });
    }

    for (int i = 0; i < gifts.size(); i++)
    {
        buffer = split(gifts[i], ' ');
        give.push_back(buffer[0]);
        given.push_back(buffer[1]);

        giftTable[friMap[give[i]]][friMap[given[i]]]++;
        giftIndex[friMap[give[i]]]++;
        giftIndex[friMap[given[i]]]--;
    }

    for (int i = 0; i < mans; i++) {
        int getGift = 0;
        for (int k = 0; k < mans; k++) {
            if (giftTable[i][k] > giftTable[k][i]) {
                getGift++;
            }
            else if (giftTable[i][k] == giftTable[k][i]) {
                if (giftIndex[i] > giftIndex[k]) {
                    getGift++;
                }
            }
        }
        if (answer < getGift) {
            answer = getGift;
        }
    }

    return answer;
}