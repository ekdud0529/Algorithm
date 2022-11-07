#include <string>
#include <vector>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int         answer = 0;
    long long   sum1 = 0;
    long long   sum2 = 0;
    int         size = (queue1.size() + queue2.size()) * 2;
    int         pt1 = 0;
    int         pt2 = 0;
    
    for(int n : queue1) sum1 += n;
    for(int n : queue2) sum2 += n;
    while(size--)
    {
        if(sum1 == sum2) break;
        else if(sum1 > sum2)
        {
            sum1 -= queue1[pt1];
            sum2 += queue1[pt1];
            queue2.push_back(queue1[pt1]);
            pt1++;
        }
        else
        {
            sum1 += queue2[pt2];
            sum2 -= queue2[pt2];
            queue1.push_back(queue2[pt2]);
            pt2++;
        }
        answer++;
    }
    if(sum1 != sum2) return (-1);
    return answer;
}
