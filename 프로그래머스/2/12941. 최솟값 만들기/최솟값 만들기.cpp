#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    int a = 0;
    for (int i = 0;i < A.size();i++)
    {
        a += A[i] * B[i];
    }
    return a;
}