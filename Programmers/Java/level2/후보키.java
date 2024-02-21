import java.util.*;

class Solution {
    int ans = 0;
    boolean[] visited = new boolean[8];
    ArrayList<String> subSet = new ArrayList<>();
    ArrayList<Integer> index = new ArrayList<>();
    
    public int solution(String[][] relation) {
        int answer = 0;
        
        for (int i=1; i<=relation[0].length; i++)
        {
            dfs(0, i, relation);
        }
        answer = ans;
        return answer;
    }
    
    public void dfs(int start, int cnt, String[][] relation) {
        if (index.size() == cnt) {
            checkUnique(relation);
            return ;
        }
        
        for (int i=start; i<relation[0].length; i++) {
            if (visited[i] == false) 
            {
                index.add(i);
                visited[i] = true;
                
                dfs(i+1, cnt, relation);
                
                visited[i] = false;
                index.remove(index.size() - 1);
            }
        }
    }
    
    public void checkUnique(String[][] relation) {
        ArrayList<String> key = new ArrayList<>();
        
        for (int i=0; i<relation.length; i++) 
        {
            String s = "";
            for (int j=0; j<index.size(); j++) 
            {
                s += relation[i][index.get(j)];
            }
            if (key.contains(s)) {
                return ;
            }
            key.add(s);
        }
        if (checkMinimum()) return ;
        ans++;
    }
    
    public boolean checkMinimum() {
        String sub = "";
        
        for (int i=0; i<index.size(); i++) 
        {
            sub += index.get(i) + "";
        }
        for (int i=0; i<subSet.size(); i++) 
        {
            String[] str = subSet.get(i).split("");
            int cnt = 0;
            
            for (int j=0; j<str.length; j++) 
            {
                if (sub.contains(str[j]))
                    cnt++;
            }
            if (cnt == str.length)
                return (true);
        }
        subSet.add(sub);
        return (false);
    }
}
