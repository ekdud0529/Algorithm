#include <string>
#include <vector>

using namespace std;

void ch_max(vector<vector<int>> sizes, int *max_width, int *max_height)
{
    int idxW=0, idxH=0;
    *max_width = 0;
    *max_height = 0;
    for(int i=0; i < sizes.size(); i++)
    {
        if(*max_width < sizes[i][0])
        {
            *max_width = sizes[i][0];
            idxW = i;
        }
        if(*max_height < sizes[i][1])
        {
            *max_height = sizes[i][1];
            idxH = i;
        }
    }
    if(max_width > max_height && idxW != idxH)
    {
        if(sizes[idxH][0] < sizes[idxH][1])
        {
            int tmp = sizes[idxH][0];
            sizes[idxH][0] = sizes[idxH][1];
            sizes[idxH][1] = tmp;
            ch_max(sizes, &(*max_width), &(*max_height));
        }
    }
    else if(max_width < max_height && idxW != idxH)
    {
        if(sizes[idxW][0] > sizes[idxW][1])
        {
            int tmp = sizes[idxW][0];
            sizes[idxW][0] = sizes[idxW][1];
            sizes[idxW][1] = tmp;
            ch_max(sizes, &(*max_width), &(*max_height));
        }
    }
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_width=0, max_height=0;
    
    ch_max(sizes, &max_width, &max_height);

    answer = max_width * max_height;
    return answer;
}
