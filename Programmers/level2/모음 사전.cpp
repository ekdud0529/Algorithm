#include <string>
#include <vector>
using namespace std;

char mo[5] = {'A', 'E', 'I', 'O', 'U'};
int cnt = 0;
bool flag = false;

void findWord(string find, string s)
{
    if(flag) return ;
    if(find == s)
    {
        flag = true;
        return ;
    }
    cnt++;
    if(s.size() == 5)
        return ;
    for(int i=0; i<5; i++)
    {
        findWord(find, s+mo[i]);
    }
}

int solution(string word) {
    int answer = 0;
    
    findWord(word, "");
    
    return answer = cnt;
}
