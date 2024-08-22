#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";

    //phone_number.size()만큼의 * 문자열 생성
    //그런데 뒤 4자리는 phone_number와 같게
    //if( idx > size() - 4) break;

    for (int i = 0; i < phone_number.size(); ++i)
    {
        if (i < phone_number.size() - 4)
        {
            answer.push_back('*');
        }
        else
        {
            answer.push_back(phone_number[i]);
        }
    }

    return answer;
}