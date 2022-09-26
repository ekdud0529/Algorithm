#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int start = 0;
    int end = citations.size();
    
    while(start <= end)
    {
        int h = (start + end) / 2;
        int upper = 0;
        int lower = 0;
        
        for(int i=0; i<citations.size(); i++)
        {
            if(citations[i] >= h)
                upper++;
            if(citations[i] <= h)
                lower++;
        }
        if(upper >= h && lower <= h)
        {
            if(answer < h)
                answer = h;
        }
        if(h > upper)
            end = h - 1;
        else
            start = h + 1;
    }
    return answer;
}
