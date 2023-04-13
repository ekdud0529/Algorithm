class Solution {
    int[][] grid = new int[1001][1001];
    
    public int[] solution(int n) {
        int[] answer = new int[(n * (n+1)) / 2];
        int index = 0;
        
        SetNum(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<grid[i][0]; j++)
            {
                answer[index++] = grid[i][j];
            }
        }
        return answer;
    }
    
    public void SetNum(int n)
    {
        int num = 1;
        int x = 0;
        int y = 0;
        int[] dx = {1, 0, -1};
        int[] dy = {0, 1, -1};
        
        for(int k=0; k<n; k++)
        {
            switch (k % 3){
                case 0 -> {
                    for(int i=0; i<n; i++)
                    {
                        if(grid[x][y] != 0) break;
                        grid[x][y] = num;
                        x += dx[0];
                        y += dy[0];
                        num++;
                    }
                    x--;
                    y++;
                }
                case 1 -> {
                    for(int i=0; i<n; i++)
                    {
                        if(grid[x][y] != 0) break;
                        if(y >= grid[x][0]) break;
                        grid[x][y] = num;
                        x += dx[1];
                        y += dy[1];
                        num++;
                    }
                    x--;
                    y -= 2;
                }
                case 2 -> {
                    for(int i=0; i<n; i++)
                    {
                        if(grid[x][y] != 0) break;
                        grid[x][y] = num;
                        x += dx[2];
                        y += dy[2];
                        num++;
                    }
                    x += 2;
                    y++;
                }
            }
                
        }
    }
}
