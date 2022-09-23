#include <vector>
#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return (a);
    return (GCD(b, a % b));
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    if(arr.size() == 1) 
        return (arr[0]);
    for(int i=1; i<arr.size(); i++)
    {
        answer = (answer * arr[i]) / GCD(answer, arr[i]);
    }
    return answer;
}
