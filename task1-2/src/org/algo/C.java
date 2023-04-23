package org.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class C {

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
        String s = scanner.next();
        int[] prefix = new int[n + 1];
        // value: index
        Map<Integer, Integer> pairs = new HashMap<>();
        pairs.put(0, 0);

        int res = 0;

        for (int i = 1; i <= n; i++) {
            if (s.charAt(i - 1) == '1') {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1] - 1;
            }

            if (!pairs.containsKey(prefix[i])) {
                pairs.put(prefix[i], i);
            }
            res = Math.max(res, i - pairs.get(prefix[i]));
        }
        System.out.println(res);
    }
}
