#include <bits/stdc++.h>
using namespace std;

int gd[500][500];

int main()
{
    int n, m, b;
    int max=0, min=256, hmax=0;
    long long tmin=1000000000;
    cin >> n >> m >> b;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> gd[i][j];
            if(max < gd[i][j]) max = gd[i][j];
            if(min > gd[i][j]) min = gd[i][j];
        }
    }
    
    for(int i=max; i>=min; i--){
        int rm=0, add=0, t=0;
        int flag=0;
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                int m = abs(i-gd[j][k]);
                if(i < gd[j][k]){
                    rm += m;
                    t += m*2;
                }
                else if(i > gd[j][k]){
                    add += m;
                    t += m;
                }
            }
        }
        if(b+rm>=add && tmin > t){
            tmin = t;
            hmax = i;
        }
    }
    
    cout << tmin << " " << hmax;
    
    return 0;
}
