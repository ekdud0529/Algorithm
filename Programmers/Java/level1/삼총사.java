class Solution {
    int ans = 0;
    boolean[] visited = new boolean[14];

    public int solution(int[] number) {
        int answer = 0;
        
        dfs(0, 0, 0, number);
        answer = ans;
        return answer;
    }
    
    void dfs(int cnt, int sum, int index, int[] number)
    {
        if(cnt == 3)
        {
            if(sum == 0)
                ans++;
            return ;
        }
        for(int i=index; i<number.length; i++)
        {
            if(visited[i]) continue;
            visited[i] = true;
            dfs(cnt+1, sum+number[i], i+1, number);
            visited[i] = false;
        }
    }
}
