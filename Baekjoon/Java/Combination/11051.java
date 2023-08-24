import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    
    static int[][] comb;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        comb = new int[n+1][n+1];
        
        if (m == 0 || n == m) {
            System.out.println(1);
            return ;
        }
        getComb(n);
        System.out.println(comb[n][m] % 10007);
    }
    
    static void getComb(int n) {
        comb[1][0] = 1;
        comb[1][1] = 1;
        for (int i=2; i<=n; i++) {
            comb[i][0] = 1;
            comb[i][i] = 1;
            for (int j=1; j<n; j++) {
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % 10007;
            }
        }
    }
}
