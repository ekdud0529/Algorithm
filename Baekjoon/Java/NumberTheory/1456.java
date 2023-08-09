import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static boolean[] isprime = new boolean[10000001];
    static ArrayList<Long> prime = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int answer = 0;
        Long a = Long.parseLong(st.nextToken());
        Long b = Long.parseLong(st.nextToken());
        Set<Long> set = new HashSet<>();

        getPrime();

        for (Long p : prime) {
            Long num = p;

            while (num <= b / p) {
                num *= p;
                if (a <= num && num <= b && !set.contains(num)) {
                    answer++;
                    set.add(num);
                }
            }
        }
        System.out.println(answer);
    }

    static void getPrime() {
        for (int i=2; i * i <= 10000000; i++) {
            if (!isprime[i]) {
                for (int j = i + i; j <= 10000000; j+=i) {
                    isprime[j] = true;
                }
            }
        }

        for (int i=2; i <= 10000000; i++) {
            if (!isprime[i])
                prime.add(Long.valueOf(i));
        }
    }
}
