import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {

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

        String s = scanner.next();
        int m = scanner.nextInt();

        int[] prefix = new int[s.length() + 1];
        int counter = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) == s.charAt(i)) {
                ++counter;
            }
            prefix[i] = counter;
        }

        for (int i = 0; i < m; i++) {
            int start = scanner.nextInt() - 1;
            int end = scanner.nextInt() - 1;

            System.out.println(prefix[end] - prefix[start]);
        }
    }
}

