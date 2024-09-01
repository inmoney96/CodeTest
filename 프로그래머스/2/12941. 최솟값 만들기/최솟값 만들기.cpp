#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    //최대한 큰 수를 작은 수랑 곱해야 최소값이 나옴
    //A는 오름차순, 
    sort(A.begin(), A.end());
    // B는 내림차순으로 정렬 
    sort(B.rbegin(), B.rend());

    //후 각 인덱스 곱하기

    for (int i = 0; i < A.size(); ++i)
    {
        answer += A[i] * B[i];
    }
    return answer;
    
}