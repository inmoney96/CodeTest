#include <string>
#include <vector>

using namespace std;

string tobi(int n) {
    string bi = "";
    while (n != 1)
    {
        int tmp = n % 2;
        bi = to_string(tmp) + bi;
        n /= 2;
    }
    return bi;
}

int solution(int n) {
   
    string get = tobi(n);
    int Ori_OneC = 0;
    for (int i = 0;i < get.size();i++)
    {
        if (get[i] == '1')
        {
            Ori_OneC++;
        }
    }

    while (true)
    {
        n++;
        string tmp = tobi(n);
        int tmp_OneC = 0;
        for (int i = 0;i < tmp.size();i++)
        {
            if (tmp[i] == '1')
            {
                tmp_OneC++;
            }
        }
        if (Ori_OneC == tmp_OneC)
            break;
    }
    return n;
}