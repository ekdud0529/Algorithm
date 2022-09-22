#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i=1; i<=5000; i++)
    {
        for(int j=i; j<=5000-2; j++)
        {
            if(i + j == (brown + 4) / 2)
                if(i * j == (brown + yellow))
                {
                    answer.push_back(j);
                    answer.push_back(i);
                    return answer;
                }
        }
    }
    return answer;
}
