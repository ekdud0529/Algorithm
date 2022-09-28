#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    vector<int> arr;
    
    for(int i=(left/n)+1; i<=(right/n)+1; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j < i)
                arr.push_back(i);
            else
                arr.push_back(j);
        }
    }
    for(int i=left - n*(left/n); i<=right-n*(left/n); i++)
    {
        answer.push_back(arr[i]);
    }
    return answer;
}
