#include <string>
#include <vector>

using namespace std;

vector<vector<int>> array;

bool checkCanCompress(int col, int row, int size)
{
    int num = array[col][row];
    
    for(int i=col; i<col+size; i++)
    {
        for(int j=row; j<row+size; j++)
        {
            if(num != array[i][j])
                return (false);
        }
    }
    return (true);
}


void compression(int col, int row, int size)
{
    int num = array[col][row];
    for(int i=col; i<col+size; i++)
    {
        for(int j=row; j<row+size; j++)
        {
            array[i][j] = -1;
        }
    }
    array[col][row] = num;
}

void dfs(int col, int row, int size)
{
    if(checkCanCompress(col, row, size))
    {
        int num = array[col][row];
        compression(col, row, size);
        return ;
    }
    dfs(col, row, size / 2);
    dfs(col, row + (size / 2), size / 2);
    dfs(col + (size / 2), row, size / 2);
    dfs(col + (size / 2), row + (size / 2), size / 2);
}

vector<int> getAnswer()
{
    int cnt0 = 0;
    int cnt1 = 0;
    vector<int> ans;
    
    for(int i=0; i<array.size(); i++)
    {
        for(int j=0; j<array.size(); j++)
        {
            if(array[i][j] == 0)
                cnt0++;
            if(array[i][j] == 1)
                cnt1++;
        }
    }
    ans.push_back(cnt0);
    ans.push_back(cnt1);
    return (ans);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++)
    {
        vector<int> copy;
        for(int j=0; j<arr.size(); j++)
        {
            copy.push_back(arr[i][j]);
        }
        array.push_back(copy);
    }
    dfs(0, 0, arr.size());
    answer = getAnswer();
    return answer;
}
