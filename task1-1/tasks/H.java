import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class H {

    static class Pair {
        public int index;
        public int value;
    }

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

        Pair[] arr = new Pair[n];

        for (int i = 0; i < n; i++) {
            arr[i] = new Pair();
            arr[i].value = scanner.nextInt();
            arr[i].index = i + 1;
        }

        Arrays.sort(arr, (o1, o2) -> {
            if (o1.value > o2.value) {
                return 1;
            } else if (o1.value < o2.value) {
                return -1;
            }
            return 0;
        });

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (r != l) {
                int sum = arr[r].value + arr[i].value + arr[l].value;
                if (sum == x) {
                    System.out.println(String.format("%d %d %d", arr[l].index, arr[r].index, arr[i].index));
                    return;
                } else if (sum > x) {
                    --r;
                } else {
                    ++l;
                }
            }
        }

        System.out.println("IMPOSSIBLE");
    }
}
