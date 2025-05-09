#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    if (a.size() == b.size())
    {
        return a < b;
    }
    else
    {
        return a.size() < b.size();
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; ++i)
    {
        string tmp;
        cin >> tmp;
        words.push_back(tmp);
    }

    sort(words.begin(), words.end(), compare);

    for (int i = 0; i < n; ++i)
    {
        if (i > 0 && words[i] == words[i - 1])
        {
            continue;
        }
        cout << words[i] << endl;
    }

    return 0;
}
