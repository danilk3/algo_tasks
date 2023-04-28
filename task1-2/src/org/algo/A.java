package org.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) {
        FastReader scanner = new FastReader();
        int n = scanner.nextInt();

        int[] prefix = new int[n + 1];

        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            prefix[i + 1] = prefix[i] + a;
        }

        int q = scanner.nextInt();

        for (int i = 0; i < q; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            System.out.println(prefix[end + 1] - prefix[start]);
        }
    }
}
