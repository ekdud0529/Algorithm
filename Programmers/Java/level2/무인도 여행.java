import java.util.*;

class Solution {
    int[][] map = new int[100][100];
    int lenX = 0;
    int lenY = 0;
    
    class Pos{
        int x;
        int y;
        
        Pos(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }
    
    public int[] solution(String[] maps) {
        int[] answer = {};
        ArrayList<Integer> ans = new ArrayList<>();
        
        lenX = maps.length;
        lenY = maps[0].length();
        splitMaps(maps);
        for(int i=0; i<maps.length; i++)
        {
            for(int j=0; j<maps[i].length(); j++)
            {
                if(map[i][j] == 0)
                    continue;
                ans.add(bfs(i, j));
            }
        }
        if (ans.size() == 0)
        {
            answer = new int[1];
            answer[0] = -1;
        }    
        else
        {
            answer = ans.stream().mapToInt(i->i).toArray();
            Arrays.sort(answer);
        }
        return answer;
    }
    
    void splitMaps(String[] maps)
    {
        for(int i=0; i<lenX; i++)
        {
            for(int j=0; j<lenY; j++)
            {
                if (maps[i].charAt(j) == 'X')
                    map[i][j] = 0;
                else
                    map[i][j] = maps[i].charAt(j) - '0';
            }
        }
    }
    
    int bfs(int x, int y)
    {
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        int sum = 0;
        Queue<Pos> q = new LinkedList<>();
        
        q.add(new Pos(x, y));
        sum += map[x][y];
        map[x][y] = 0;
        while(!q.isEmpty())
        {
            Pos now = q.poll();
            for(int i=0; i<4; i++)
            {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                if(0 > nx || nx >= lenX || 0 > ny || ny >= lenY)
                    continue;
                if(map[nx][ny] == 0)
                    continue;
                q.add(new Pos(nx, ny));
                sum += map[nx][ny];
                map[nx][ny] = 0;
            }
        }
        return (sum);
    }
}
