package dataStructure;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Queue<Integer> q = new LinkedList<Integer>();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for(int i=1; i<=n; i++)
        {
            q.add(i);
        }
        while (q.size() > 1)
        {
            q.poll();
            q.add(q.poll());
        }
        System.out.print(q.poll());
    }
}