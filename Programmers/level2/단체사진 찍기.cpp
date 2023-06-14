#include <string>
#include <vector>

using namespace std;

char position[8];
int ans;
bool visited[8];

int findDistance(char a, char b)
{
    int indexA = 0;
    int indexB = 0;
    
    for(int i=0; i<8; i++)
    {
        if(position[i] == a)
            indexA = i;
        else if(position[i] == b)
            indexB = i;
    }
    indexA -= indexB;
    if(indexA < 0)
        indexA *= -1;
    indexA -= 1;
    return (indexA);
}

bool checkPosition(vector<string> data)
{
    for(string s : data)
    {
        int distance = s[4] - '0';
        char compare  = s[3];
        int dist = findDistance(s[0], s[2]);
        
        if(compare == '<')
        {
            if(dist >= distance)
                return(false);
        }
        else if(compare == '>')
        {
            if(dist <= distance)
                return(false);
        }
        else if(compare == '=')
        {
            if(dist != distance)
                return (false);
        }
    }
    return (true);
}

void dfs(char friends[], int index, vector<string> data)
{
    if(index == 8)
    {
        if(checkPosition(data))
        {
            ans++;
        }
        return ;
    }
    for(int i=0; i<8; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        position[index] = friends[i];
        dfs(friends, index + 1, data);
        visited[i] = false;
         
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    char friends[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    ans = 0;
    for(int i=0; i<8; i++)
    {
        visited[i] = false;
    }
    dfs(friends, 0, data);
    answer = ans;
    return answer;
}
