#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size(), -1));
    for(int i=0; i<arr1.size(); i++)
    {
        for(int k=0; k<arr2[0].size(); k++)
        {
            answer[i][k] = arr1[i][k] + arr2[i][k];
        }
    }
    return answer;
}
