#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

string bfs(int start, vector<vector<int>> keypad, int L, int R) {
    bool isVisited[12] = {false};
    bool closeL = false;
    bool closeR = false;
    int sstep=start;
    queue<int> q;
    q.push(start);
    isVisited[start] = true;

    if (start == L) {
        return "L";
    }
    if (start == R) {
        return "R";
    }

    while (!q.empty()) {
        int x = q.front();
        for (int i = 0; i < keypad[x].size(); i++) {
            int y = keypad[x][i];
            if (isVisited[y] == false) {
                if (y == L) {
                    closeL = true;
                }
                if (y == R) {
                    closeR = true;
                }
                q.push(y);
                isVisited[y] = true;
            }
            
        }
        if (q.front() == sstep) {
            if (closeL && closeR) {
                return "X";
            }
            else if (closeL) {
                return "L";
            }
            else if (closeR) {
                return "R";
            }
            sstep = q.back();
        }
        q.pop();
    }

}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    //make keypad
    vector<vector<int>> keypad(12);
    keypad[0].push_back(8);
    keypad[0].push_back(11); //#
    keypad[0].push_back(10); //*

    keypad[1].push_back(2);
    keypad[1].push_back(4);

    keypad[2].push_back(1);
    keypad[2].push_back(3);
    keypad[2].push_back(5);

    keypad[3].push_back(2);
    keypad[3].push_back(6);

    keypad[4].push_back(1);
    keypad[4].push_back(5);
    keypad[4].push_back(7);

    keypad[5].push_back(2);
    keypad[5].push_back(6);
    keypad[5].push_back(8);
    keypad[5].push_back(4);

    keypad[6].push_back(3);
    keypad[6].push_back(5);
    keypad[6].push_back(9);

    keypad[7].push_back(4);
    keypad[7].push_back(8);
    keypad[7].push_back(10);

    keypad[8].push_back(5);
    keypad[8].push_back(9);
    keypad[8].push_back(0);
    keypad[8].push_back(7);

    keypad[9].push_back(6);
    keypad[9].push_back(11); 
    keypad[9].push_back(8);

    keypad[10].push_back(7);
    keypad[10].push_back(0);

    keypad[11].push_back(0);
    keypad[11].push_back(9);


    string c="";
    int lFinger=10;
    int rFinger=11;
    for (int i = 0; i < numbers.size(); i++) {
        switch (numbers[i])
        {
        case 1:
        case 4:
        case 7:
            answer.append("L");
            lFinger = numbers[i];
            break;
        case 3:
        case 6:
        case 9:
            answer.append("R");
            rFinger = numbers[i];
            break;
        case 2:
        case 5:
        case 8:
        case 0:
            c = bfs(numbers[i], keypad, lFinger, rFinger);
            if (c == "X" && hand == "left") {
                answer.append("L");
                lFinger = numbers[i];
            }
            else if (c == "X" && hand == "right") {
                answer.append("R");
                rFinger = numbers[i];
            }
            else {
                answer.append(c);
                if (c == "L") {
                    lFinger = numbers[i];
                }
                else {
                    rFinger = numbers[i];
                }
            }
        default:
            break;
        }
    }

    return answer;
}
