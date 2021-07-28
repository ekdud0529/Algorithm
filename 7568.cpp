#include <bits/stdc++.h>
using namespace std;

int rk[50];

int main(){
    int n;
    cin >> n;

    vector <vector<int>> size(n, vector<int>(4,0));

    for(int i=0; i<n; i++){
        cin >> size[i][0] >> size[i][1];
        size[i][2] = 1;
        size[i][3] = i;
    }

    sort(size.begin(), size.end());

    for(int i=0; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(size[i][0]>size[j][0] && size[i][1]>size[j][1]){
                size[j][2]++;
            }
        }
    }

    for(int i=0; i<n; i++){
        rk[size[i][3]] = size[i][2];
    }

    for(int i=0; i<n; i++){
        cout << rk[i] << " ";
    }

    return 0;
}
