#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string s;
	cin >> s;
	string v1;
	string v2;
	string v3;
	string r1;
	string r2;
	string r3;
	vector<string> vec;
	for (int i = 1; i < s.size()-1; ++i)
	{
		for (int j = 1; j < s.size()-i; ++j)
		{
			v1.append(s, 0, i);
			v2.append(s, i, j);
			v3.append(s, i+j, s.size());


			for (int k = 0 ; k < v1.size(); ++k)
			{
				r1.push_back(v1[v1.size() - 1 - k]);
			}
			for (int k = 0; k < v2.size(); ++k)
			{
				r2.push_back(v2[v2.size() - 1 - k]);
			}
			for (int k = 0; k < v3.size(); ++k)
			{
				r3.push_back(v3[v3.size() - 1 - k]);
			}

			vec.push_back(r1 + r2 + r3);
			v1.clear();
			v2.clear();
			v3.clear();
			r1.clear();
			r2.clear();
			r3.clear();
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec[0];

	return 0;
}
