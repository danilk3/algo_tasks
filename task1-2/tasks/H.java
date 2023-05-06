import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class H {

    static class Guest {
        public Integer arrival;

        public Integer departure;

        public Integer index;

        public Guest(Integer arrival, Integer departure, Integer index) {
            this.arrival = arrival;
            this.departure = departure;
            this.index = index;
        }
    }

    static class Room {
        public Integer id;

        public Integer departure;

        public Room(Integer id, Integer departure) {
            this.id = id;
            this.departure = departure;
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

        Guest[] guests = new Guest[n];

        for (int i = 0; i < n; i++) {
            guests[i] = new Guest(scanner.nextInt(), scanner.nextInt(), i);
        }

        Arrays.sort(guests, Comparator.comparingInt(g -> g.arrival));

        Queue<Room> rooms = new PriorityQueue<>(Comparator.comparingInt(r -> r.departure));
        rooms.add(new Room(1, guests[0].departure));

        int[] res = new int[n];
        res[guests[0].index] = 1;

        int minRoomAmount = 1;

        for (int i = 1; i < n; i++) {
            Guest guest = guests[i];
            Room lastRoom = rooms.peek();

            if (lastRoom.departure >= guest.arrival) {
                rooms.add(new Room(lastRoom.id + 1, guest.departure));
                res[guest.index] = lastRoom.id + 1;
            } else {
                rooms.remove();
                rooms.add(new Room(lastRoom.id, guest.departure));
                res[guest.index] = lastRoom.id;
            }
            minRoomAmount = Math.max(minRoomAmount, rooms.size());
        }

        System.out.println(minRoomAmount);
        Arrays.stream(res).forEach(r -> System.out.print(r + " "));
    }
}
