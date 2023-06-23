class Solution {
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        
        for(int i=0; i<5; i++)
        {
            if(checkCovid(places[i]))
                answer[i] = 1;
            else
                answer[i] = 0;
        }
        return answer;
    }
    
    boolean checkCovid(String[] place)
    {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        boolean[][] visited = new boolean[5][5];
        
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(place[i].charAt(j) != 'P') continue;
                for(int k=0; k<4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                        
                    if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                        continue;
                    if(visited[nx][ny] || (place[nx].charAt(ny) == 'P'))
                        return (false);
                    if(place[nx].charAt(ny) == 'O')
                        visited[nx][ny] = true;
                }
            }
        }
        return (true);
    }
}
