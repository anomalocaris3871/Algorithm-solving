import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;


class Test {

    static int[][] map;
    static int[] dx = {0, 1, 0, -1, 1, -1, 1, -1};
    static int[] dy = {1, 0, -1, 0, 1, -1, -1, 1};
    static int n;

    static int bfs(int y, int x) {
        int result = 0;

        Queue<Pair> queue = new ArrayDeque<>();

        if (map[y][x] == 1) {
            queue.add(new Pair(x, y));
            map[y][x] = -1;
        }

        while (!queue.isEmpty()) {
            result = 1;
            Pair peek = queue.peek();
            queue.remove();

            for (int i = 0; i < 8; ++i) {
                int nextX = peek.x + dx[i];
                int nextY = peek.y + dy[i];

                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) {
                    continue;
                }

                if (map[nextY][nextX] == 1) {
                    queue.add(new Pair(nextX, nextY));
                    map[nextY][nextX] = -1;
                }
            }
        }

        return result;
    }

    static class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }


    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        map = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                map[i][j] = scanner.nextInt();
            }
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += bfs(i, j);
            }
        }

        System.out.println(sum);
    }
}
