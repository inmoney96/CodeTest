#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool checkbox[9];

void fun(vector<int> buffer, int N, int M, int depth) {
    
    if (depth == M) {
        for (int k = 0; k < buffer.size(); k++) {
            printf("%d ", buffer[k]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (checkbox[i]) {

            continue;

        }
        vector<int> temp = buffer;
        temp.push_back(i);
        checkbox[i] = true;
        fun(temp, N, M, depth + 1);
        checkbox[i] = false;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> buffer;

    fun(buffer,N,M,0);
    return 0;
}