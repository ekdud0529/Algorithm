import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main{

    public static void main(String []args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[1000001];

        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;
        for (int i=4; i<=n; i++) {
            dp[i] = i;
            if (i%3 == 0) dp[i] = Math.min(dp[i], dp[i/3]);
            if (i%2 == 0) dp[i] = Math.min(dp[i], dp[i/2]);
            dp[i] = 1 + Math.min(dp[i], dp[i-1]);
        }
        System.out.println(dp[n]);
    }
}
