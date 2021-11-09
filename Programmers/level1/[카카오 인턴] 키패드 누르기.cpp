#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left=10, right=12;
    int distL, distR, subL, subR;
    for(int i=0; i < numbers.size(); i++)
    {
        if(numbers[i] == 0)
            numbers[i] = 11;
        if(numbers[i] % 3 == 1) 
            answer += "L";
        else if(numbers[i] % 3 == 0) 
            answer += "R";
        else
        {
            subL = abs(numbers[i] - left);
            subR = abs(numbers[i] - right);
            distL = (subL / 3) + (subL % 3);
            distR = (subR / 3) + (subR % 3);
            
            if(distL == distR)
            {
                if(hand == "right")
                    answer += "R";
                else
                    answer += "L";
            }
            else if(distL > distR)
                answer += "R";
            else
                answer += "L";
        }
        if(answer[answer.size()-1] == 'L')
            left = numbers[i];
        else
            right = numbers[i];
    }
    return answer;
}
