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

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    vector<int> reported(id_list.size(),0);
    vector<vector<int>> isReport(id_list.size(), (vector<int>(id_list.size(), 0)));
    map<string, int> m;
    for (int i = 0; i < id_list.size(); i++) {
        m.insert(make_pair(id_list[i], i));
    }

    string q, w;
    for (int i = 0; i < report.size(); i++) {
        vector<string> temp;
        temp = split(report[i], ' ');
        q = temp[0];
        w = temp[1];

        if (isReport[m[q]][m[w]] == 0) {
            isReport[m[q]][m[w]]++;
            reported[m[w]]++;
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        for (int j = 0; j < id_list.size(); j++) {
            if (isReport[i][j] > 0&&reported[j]>=k) {
                answer[i]++;
            }
        }
    }

    return answer;
}