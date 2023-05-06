import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


public class E {
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
        int t = scanner.nextInt();


        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();

            Set<Integer> set = new HashSet<>();

            int val = 1;
            while (val * val <= n) {
                set.add(val * val);
                ++val;
            }

            val = 1;
            while (val * val * val <= n) {
                set.add(val * val * val);
                ++val;
            }

            System.out.println(set.size());
        }
    }
}
