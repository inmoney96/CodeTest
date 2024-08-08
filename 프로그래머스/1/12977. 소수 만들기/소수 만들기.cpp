#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    bool* isPrime = new bool[2998];// prime filter

    for (int i = 0; i < 2998; ++i) {
        isPrime[i] = true;
    }

    for (int i = 2; i < 2998; i++) {
        if (isPrime[i]) 
        {
            for (int j = i * 2; j < 2998; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }

    int tmp = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            for (int k = j + 1; k < nums.size(); ++k)
            {
                sum = nums[i] + nums[j] + nums[k];
                if (isPrime[sum])
                {
                    tmp += 1;
                }


            }
        }
    }
    return tmp;
}