import java.util.*;

class Solution {
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};
    int index = 1;
    
    public int solution(int[][] land) {
        int answer = 0;
        int[] oil = new int[125001];
        
        for (int j=0; j<land[0].length; j++) 
        {
            int sum = 0;
            boolean[] visited = new boolean[125001];
            
            for (int i=0; i<land.length; i++) 
            {
                if (land[i][j] == 0)
                    continue;
                else if (land[i][j] < 0)
                {
                    if (visited[-land[i][j]] == false) 
                    {
                        sum += oil[-land[i][j]];
                        visited[-land[i][j]] = true;
                    }
                }
                else 
                {
                    int l = bfs(i, j, land);
                    oil[index] = l;
                    sum += l;
                    visited[index] = true;
                    index++;
                }
            }
            if (answer < sum) answer = sum;
        }
        return answer;
    }
    
    public int bfs(int x, int y, int[][] land) {
        Queue<int[]> q = new LinkedList<>();
        int[] now = {x, y};
        int sum = 0;
        
        q.add(now);
        land[x][y] = -index;
        while (!q.isEmpty())
        {
            int[] next = q.poll();
            
            sum++;
            for (int i=0; i<4; i++)
            {
                int nx = next[0] + dx[i];
                int ny = next[1] + dy[i];
                
                if (0 > nx || nx >= land.length || 0 > ny || ny >= land[0].length)
                    continue;
                if (land[nx][ny] != 1) continue;
                land[nx][ny] = -index;
                int[] input = {nx, ny};
                q.add(input);
            }
        }
        return (sum);
    }
}
