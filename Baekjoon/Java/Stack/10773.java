package dataStructure;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        int answer = 0;
        Stack<Integer> st = new Stack<>();
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();

        while (k-- > 0)
        {
            int num = sc.nextInt();
            if(num == 0)
            {
                answer -= st.peek();
                st.pop();
            }
            else
            {
                st.push(num);
                answer += num;
            }
        }
        System.out.print(answer);
    }
}
