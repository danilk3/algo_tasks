package org.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B {
    static class Node {
        public Node previous;
        public Node next;

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

        int n = scanner.nextInt();
        String s = scanner.next();

        Node previous = new Node();
        previous.value = 0;

        for (int i = 1; i <= n; i++) {
            Node node = new Node();
            node.value = i;

            if (s.charAt(i - 1) == 'L') {
                if (previous.previous != null) {
                    previous.previous.next = node;
                }
                node.previous = previous.previous;
                node.next = previous;
                previous.previous = node;
            } else {
                node.previous = previous;
                previous.next.previous = node;
                node.next = previous.next;
                previous.next = node;
            }
            previous = node;
        }

        while (previous.previous != null) {
            previous = previous.previous;
        }

        while (previous != null) {
            System.out.print(previous.value + " ");
            previous = previous.next;
        }
    }
}
