#include <string>
#include <vector>
using namespace std;

int matrix[101][101];

void mk_matrix(int row, int col)
{
    int n = 1;
    
    for(int i=1; i<=row; i++)
    {
        for(int k=1; k<=col; k++)
        {
            matrix[i][k] = n;
            n++;
        }
    } 
}

int get_min_num(vector<int> queries)
{
    int min_num = 100000;
    pair<int, int> start = {queries[0], queries[1]};
    pair<int, int> end = {queries[2], queries[3]};
    int tmp = matrix[start.first][end.second];

    if(min_num > tmp) min_num = tmp;
    //right
    for(int i=end.second; i>start.second; i--)
    {
        if(min_num > matrix[start.first][i]) min_num = matrix[start.first][i];
        matrix[start.first][i] = matrix[start.first][i-1];
    }
    //up
    for(int i=start.first; i<end.first; i++)
    {
        if(min_num > matrix[i][start.second]) min_num = matrix[i][start.second];
        matrix[i][start.second] = matrix[i+1][start.second];
    }
    //left
    for(int i=start.second; i<end.second; i++)
    {
        if(min_num > matrix[end.first][i]) min_num = matrix[end.first][i];
        matrix[end.first][i] = matrix[end.first][i+1];
    }
    //down
    for(int i=end.first; i>start.first; i--)
    {
        if(min_num > matrix[i][end.second]) min_num = matrix[i][end.second];
        matrix[i][end.second] = matrix[i-1][end.second];
    }
    matrix[start.first+1][end.second] = tmp;
    return (min_num);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    mk_matrix(rows, columns);
            
    for(int i=0; i<queries.size(); i++)
    {
        int num = get_min_num(queries[i]);
        answer.push_back(num);
    }
    return answer;
}
