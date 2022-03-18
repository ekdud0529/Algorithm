#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a < b;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    for(int i=0; i<phone_book.size() - 1; i++)
    {
        int cur_len = phone_book[i].size();
        int next_len = phone_book[i+1].size();
        int size = (cur_len < next_len)? cur_len : next_len;
        int check = true;
        
        for(int j=0; j<size; j++)
        {
            if(phone_book[i][j] != phone_book[i+1][j])
            {
                check = false;
                break;
            }
        }
        if(check) return false;
    }
    return answer;
}
