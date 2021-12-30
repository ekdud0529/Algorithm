#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int row = arr1.size();
    int col = arr1[0].size();
    
    for(int i=0; i<row; i++)
    {
        vector<int> arr;
        for(int j=0; j<arr2[0].size(); j++)
        {
            int mul = 0;
            for(int k=0; k<col; k++)
            {
                mul += (arr1[i][k]*arr2[k][j]);
            }
            arr.push_back(mul);
        }
        answer.push_back(arr);
    }
    
    return answer;
}
