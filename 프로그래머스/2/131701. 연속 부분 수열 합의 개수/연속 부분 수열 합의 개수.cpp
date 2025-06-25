#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> sum;
    for (int i = 0;i < elements.size();i++) {
        for (int j = 0;j < elements.size() - 1;j++)
        {
            int tmp = 0;
            for (int k = 0; k <= j;k++)
            {
                int idx = i + k;
                if (idx >= elements.size())
                {
                    idx -= elements.size();
                }
                tmp += elements[idx];
            }
            sum.insert(tmp);
        }
    }
    return sum.size()+1;
}