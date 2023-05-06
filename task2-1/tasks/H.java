import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class H {

    static class Pair {

        public Pair(Character character, Integer value) {
            this.character = character;
            this.value = value;
        }

        public Character character;
        public Integer value;
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
        String str = scanner.next();

        Stack<Pair> stack = new Stack<>();
        stack.push(new Pair(')', 0));

        int numberOfSeq = 0;
        int maxSeq = 0;

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(') {
                stack.push(new Pair('(', 0));
            } else {
                if (stack.peek().character == '(') {
                    int val = stack.pop().value;
                    stack.peek().value += 1 + val;
                } else {
                    stack.push(new Pair(')', 0));
                }

                int topVal = stack.peek().value;
                if (topVal > maxSeq) {
                    numberOfSeq = 1;
                    maxSeq = topVal;
                } else if (topVal == maxSeq) {
                    ++numberOfSeq;
                }
            }
        }

        if (maxSeq == 0) {
            System.out.println("0 1");
        } else {
            System.out.println(maxSeq * 2 + " " + numberOfSeq);
        }
    }
}
