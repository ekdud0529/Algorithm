#include <string>
#include <vector>

using namespace std;

int pwd_map[16][16];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++)
    {
        int k = 0;
        while(arr1[i] !=0 || arr2[i] != 0)
        {
            if((arr1[i] % 2) || (arr2[i] % 2))
            {
                pwd_map[i][n-1 - k] = 1;
            }
            arr1[i] /= 2;
            arr2[i] /= 2;
            k++;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        string str = "";
        for(int k=0; k<n; k++)
        {
            if(pwd_map[i][k])
                str += '#';
            else
                str += ' ';
        }
        answer.push_back(str);
    }
    
    return answer;
}
