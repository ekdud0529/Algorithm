import java.util.*;

class Solution {
    
    class Pos{
        int x;
        int y;
        int cnt;
        
        Pos(int a, int b, int move)
        {
            x = a;
            y = b;
            cnt = move;
        }
    }
    
    public int solution(int[][] maps) {
        int answer = 0;
        int n = maps.length;
        int m = maps[0].length;
        
        answer = Bfs(n-1, m-1, maps);
        if (answer == 1000000)
            return (-1);
        return answer;
    }
    
    public int Bfs(int n, int m, int[][] maps)
    {
        Queue<Pos> q = new LinkedList<Pos>();
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        int answer = 1000000;
        boolean[][] visited = new boolean[n+1][m+1];
        
        q.add(new Pos(0, 0, 1));
        while(!q.isEmpty())
        {
            Pos now = q.poll();
            if((now.x == n) && (now.y == m))
            {
                if(now.cnt < answer)
                    answer = now.cnt;
                continue;
            }
            for(int i=0; i<4; i++)
            {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                if(0 > nx || nx > n || 0 > ny || ny > m)
                    continue;
                if(visited[nx][ny] || (maps[nx][ny] == 0))
                    continue;
                visited[nx][ny] = true;
                q.add(new Pos(nx, ny, now.cnt + 1));
            }
        }
        return (answer);
    }
}
