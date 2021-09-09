#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int size = commands.size();
    for(int i=0; i<size; i++){
        int sizeArr = commands[i][1]-commands[i][0]+1;
        
        int arr[sizeArr];
        for(int j=0; j<sizeArr; j++){
            arr[j] = array[commands[i][0]-1+j];
        }
        
        for(int k=0; k<sizeArr-1; k++){
            for(int j=k+1; j<sizeArr; j++){
                if(arr[k] > arr[j]){
                    int temp = arr[j];
                    arr[j] = arr[k];
                    arr[k] = temp;
                }
            }
        }
        answer.push_back(arr[commands[i][2]-1]);
    }
    
    return answer;
}
