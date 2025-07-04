#include <string>
#include <vector>
using namespace std;

int Gcd(int a, int b)
{
	int M = max(a, b);
	int m = min(a, b);

	while ( M%m !=0 )
	{
		int t = M % m;
		M = m;
		m = t;
	}

	return m;
}

int solution(vector<int> arr) {
	int answer = arr[0];

	for (int i = 1;i < arr.size();i++)
	{
		int GCD = Gcd(answer, arr[i]);
		int LCM = answer * arr[i] / GCD;
		answer = LCM;
	}

	return answer;
}