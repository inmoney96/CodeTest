function solution(a, b) {
    var answer = 0;
    if (a===b){
        answer = a;
    }else if(a > b){
        while ( b <= a){
            answer =answer + b;
            b++;}
        }else if(a < b){
        while ( a <= b){
            answer = answer + a;
            a++;}
    };
    return answer;
}