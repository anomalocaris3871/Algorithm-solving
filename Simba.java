import java.util.PriorityQueue;
import java.util.Scanner;


class Simba {


    static int n;
    static int[][] jungle;
    static boolean[][] checked;
    static int seconds = 0;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    static void bfs(Lion simba) {

        PriorityQueue<Position> queue = new PriorityQueue<>((position1, position2) -> {
            int distance = position1.distance - position2.distance;
            if (distance != 0) {
                return distance;
            }

            int north = position1.y - position2.y;
            if (north != 0) {
                return north;
            }

            return position1.x - position2.x;
        });

        queue.add(simba.pos);
        while (!queue.isEmpty()) {
            Position front = queue.peek();
            queue.remove();

            if (jungle[front.y][front.x] != 0 && jungle[front.y][front.x] < simba.size) {
                simba.pos.x = front.x;
                simba.pos.y = front.y;

                simba.eat++;
                if (simba.eat == simba.size) {
                    simba.sizeUp();
                }
                seconds = front.distance;
                jungle[front.y][front.x] = 0;
                queue.clear();

                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        checked[i][j] = false;
                    }
                }
            }

            for (int i = 0; i < 4; ++i) {
                int nextX = front.x + dx[i];
                int nextY = front.y + dy[i];
                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n || jungle[nextY][nextX] > simba.size || checked[nextY][nextX]) {
                    continue;
                }
                queue.add(new Position(nextX, nextY, front.distance + 1));
                checked[nextY][nextX] = true;
            }
        }

    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        jungle = new int[n][n];
        checked = new boolean[n][n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                jungle[i][j] = scanner.nextInt();
            }
        }

        Lion simba = null;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (jungle[i][j] == 9) {
                    simba = new Lion(new Position(j, i, 0));
                    jungle[i][j] = 0;
                    break;
                }
            }
        }

        bfs(simba);
        System.out.println(seconds);

        scanner.close();
    }

    static class Position {
        int x;
        int y;
        int distance;

        Position(int x, int y, int distance) {
            this.x = x;
            this.y = y;
            this.distance = distance;
        }
    }

    static class Lion {
        Position pos;
        int eat = 0;
        int size = 2;

        Lion(Position pos) {
            this.pos = pos;
        }

        void sizeUp() {
            size += 1;
            eat = 0;
        }
    }
}
