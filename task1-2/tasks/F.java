import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class F {

    static class Pair {
        public Character symbol;
        public Integer index;

        public Pair(Character symbol, Integer index) {
            this.symbol = symbol;
            this.index = index;
        }
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

        List<Pair> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            list.add(new Pair('+', start));
            list.add(new Pair('-', end));
        }

        list.sort((o1, o2) -> {
            if (o1.index > o2.index) {
                return 1;
            }

            if (o1.index < o2.index) {
                return -1;
            }

            if (o1.symbol == '-' && o2.symbol == '+') {
                return 1;
            }
            return -1;
        });

        int counter = 0;
        int numberOfSegments = 0;
        int startOfSegment = 0;
        List<int[]> segments = new ArrayList<>();

        for (Pair pair : list) {
            if (counter == 0) {
                startOfSegment = pair.index;
            }

            if (pair.symbol == '+') {
                ++counter;
            } else {
                --counter;

                if (counter == 0) {
                    ++numberOfSegments;
                    segments.add(new int[]{startOfSegment, pair.index});
                }
            }
        }

        System.out.println(numberOfSegments);
        segments.forEach(seg -> System.out.println(seg[0] + " " + seg[1]));
    }
}
