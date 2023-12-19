import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;


class Test {

    static int[][] map = new int[7][7];
    static int[][] distance = new int[7][7];

    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static void bfs() {
        Queue<Coordinate> queue = new ArrayDeque<>();
        queue.add(new Coordinate(0, 0));
        map[0][0] = -1;

        while (!queue.isEmpty()) {
            Coordinate peek = queue.peek();
            if (peek.x == 6 && peek.y == 6) {
                break;
            }
            queue.remove();

            for (int i = 0; i < 4; ++i) {
                int nextX = peek.x + dx[i];
                int nextY = peek.y + dy[i];

                if ((nextX > 6 || nextX < 0 || nextY > 6 || nextY < 0) || map[nextY][nextX] != 0) {
                    continue;
                }
                queue.add(new Coordinate(nextX, nextY));
                map[nextY][nextX] = -1;
                distance[nextY][nextX] = distance[peek.y][peek.x] + 1;
            }
        }

        if (map[6][6] != 0) {
            System.out.println(distance[6][6]);
        } else {
            System.out.println(-1);
        }

    }

    static class Coordinate {
        int x;
        int y;

        Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 7; ++j) {
                map[i][j] = scanner.nextInt();
            }
        }

        bfs();
        scanner.close();
    }
}
