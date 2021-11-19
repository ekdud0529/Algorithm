#include <string>

using namespace std;

int score[3];

int solution(string dartResult) {
    int answer = 0;
    int turn = 0;
    
    for(int i=0; i<dartResult.size(); i++)
    {
        if('0' <= dartResult[i] && dartResult[i] <= '9')
        {
            int num = 0;
            for(int k=i; ('0' <= dartResult[k] && dartResult[k] <= '9'); k++)
            {
                num = num*10 + dartResult[k]-'0';
            }
            if(num > 9) i++;
            score[turn] = num;
        }
        else
        {
            switch(dartResult[i])
            {
                case 'S':
                    if('0' <= dartResult[i+1] && dartResult[i+1] <= '9')
                        turn++;
                    continue;
                case 'D':
                    score[turn] *= score[turn];
                    break;
                case 'T':
                    score[turn] *= (score[turn] * score[turn]);
                    break;
                case '*':
                    score[turn] *= 2;
                    if(turn > 0) score[turn - 1] *= 2;
                    break;
                case '#':
                    score[turn] *= -1;
                    break;
            }
            if('0' <= dartResult[i+1] && dartResult[i+1] <= '9')
            {
                turn++;
            }
        }
    }
    answer = score[0] + score[1] + score[2];
    return answer;
}
