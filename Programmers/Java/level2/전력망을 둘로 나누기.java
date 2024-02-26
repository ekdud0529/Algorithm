import java.util.*;

class Solution {
    int[] parent = new int[100];
    
    public int solution(int n, int[][] wires) {
        int answer = 100;
        
        for (int i=0; i<wires.length; i++)
        {
            int cnt = 0;
            for(int j=0; j<n; j++)
            {
                parent[j] = j;
            }
            for (int j=0; j<wires.length; j++)
            {
                if (j == i) continue;
                union(wires[j][0]-1, wires[j][1]-1);
            }
            for (int j=0; j<n; j++)
            {
                parent[j] = find(j);
                if (parent[j] == 0) cnt++;
            }
            cnt = Math.abs(n - (cnt * 2));
            if (cnt < answer) answer = cnt;
        }
        return answer;
    }
    
    public int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    public void union(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x < y)
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
        }
    }
}
