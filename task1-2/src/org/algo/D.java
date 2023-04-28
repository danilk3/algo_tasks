package org.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class D {
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
        int x = scanner.nextInt();

        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        int res = 0;
        int pref = 0;

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            pref += num;

            Integer rep = map.get(pref - x);

            if (rep != null) {
                res += rep;
            }
            map.put(pref, map.getOrDefault(num, 1));
        }

        System.out.println(res);
    }
}
