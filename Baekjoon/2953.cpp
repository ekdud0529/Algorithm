import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		int i=5, k, max=0, cnt, num=0;
		int[][] p = new int[5][4];
		for(i=0;i<5;i++){
			cnt=0;
			for(k=0;k<4;k++) {
				p[i][k] = stdin.nextInt();
				cnt+=p[i][k];
			}
			if(max<cnt) {
				max = cnt;
				num = i+1;
			}
		}
		System.out.print(num+" "+max);
	}
}
