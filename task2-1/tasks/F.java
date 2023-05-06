import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class F {
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

        for (int i = 0; i < n; i++) {
            int t = scanner.nextInt();
            Stack<Integer> stack = new Stack<>();
            int[] arr = new int[t];

            for (int j = 0; j < t; j++) {
                int s = scanner.nextInt();
                arr[j] = s;

                while (!stack.isEmpty() && arr[stack.peek()] <= arr[j]) {
                    stack.pop();
                }

                if (stack.isEmpty()) {
                    System.out.print(j + 1 + " ");
                } else {
                    System.out.print(j - stack.peek() + " ");
                }

                stack.push(j);
            }
            System.out.println();
        }
    }
}
