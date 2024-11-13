#include <iostream>
#include <string>
#include <vector>
using namespace std;
class stack {
public:
	stack(int size){
		capa = size;
		arr = new int[size];
		topnum = -1;
	};
	~stack() {
		delete arr;
	};

	void push(int x) {
		arr[++topnum] = x;
	}

	int pop() {
		if (topnum >= 0)
		{
			return arr[topnum--];
		}
		return -1;
	}
	
	int size() {
		return topnum + 1;
	}

	int empty() {
		if (topnum >= 0)
		{
			return 0;
		}
		else {
			return 1;
		}
	}

	int top() {
		if (topnum < 0)
		{
			return -1;
		}
		return arr[topnum];
	}

private:
	int topnum;
	int* arr;
	int capa;
};

int main() {
	int n;
	cin >> n;
	string str;
	stack s(n);
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			int x;
			cin >> x;
			s.push(x);
		}
		else if (str == "pop")
		{
			ans.push_back(s.pop());
		}
		else if (str == "size")
		{
			ans.push_back(s.size());
		}
		else if (str == "empty")
		{
			ans.push_back(s.empty());
		}
		else if (str == "top")
		{
			ans.push_back(s.top());
		}

	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] <<endl;
	}

	return 0;
}