#include <string>
#include <vector>

using namespace std;

int discountPay[7];
int discount[4] = {10, 20, 30, 40};
int ans_plus = 0;
int ans_pay = 0;

void checkEmoUser(vector<vector<int>> users, vector<int> emoticons)
{
    int sum_plus = 0;
    int sum_pay = 0;

    for(int i=0; i<users.size(); i++)
    {
        int sum = 0;
        for(int j=0; j<emoticons.size(); j++)
        {
            if(users[i][0] <= discountPay[j])
            {
                sum += ((emoticons[j] * (100 - discountPay[j])) / 100);
            }
        }
        if(users[i][1] <= sum)
        {
            sum_plus += 1;
        }
        else
        {
            sum_pay += sum;
        }
    }
    if(sum_plus > ans_plus)
    {
        ans_plus = sum_plus;
        ans_pay = sum_pay;
    }
    else if(sum_plus == ans_plus)
    {
        if(sum_pay > ans_pay)
        {
            ans_pay = sum_pay;
        }
    }
}

void dfs(int index, int cnt, vector<vector<int>> users, vector<int> emoticons)
{
    if(cnt == index)
    {
        checkEmoUser(users, emoticons);
        return ;
    }
    for(int i=0; i<4; i++)
    {
        discountPay[index] = discount[i];
        dfs(index + 1, cnt, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    dfs(0, emoticons.size(), users, emoticons);
    answer.push_back(ans_plus);
    answer.push_back(ans_pay);
    return answer;
}
