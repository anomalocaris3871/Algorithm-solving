import javax.swing.text.Position;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;


class Test {

    static int box[][];

    static int dx[] = {0, 1, 0, -1};
    static int dy[] = {1, 0, -1, 0};
    static int n;
    static int m;

    static void bfs() {
        Queue<Position> queue = new ArrayDeque<>();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (box[i][j] >= 1) {
                    queue.add(new Position(j, i));
                }
            }
        }

        while (!queue.isEmpty()) {
            Position front = queue.peek();
            queue.remove();

            for (int i = 0; i < 4; ++i) {
                int nextX = front.x + dx[i];
                int nextY = front.y + dy[i];

                if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0) {
                    continue;
                }

                if (box[nextY][nextX] == 0) {
                    queue.add(new Position(nextX, nextY));
                    box[nextY][nextX] = box[front.y][front.x] + 1;
                }

            }
        }


    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        m = scanner.nextInt();
        n = scanner.nextInt();
        box = new int[n][m];
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                box[i][j] = scanner.nextInt();
            }
        }

        bfs();

        int day = 0;
        boolean isFound = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (box[i][j] == 0) {
                    isFound = true;
                    break;
                }
                if (day < box[i][j]) {
                    day = box[i][j];
                }
            }
        }

        if (isFound) {
            System.out.println(-1);
        } else {
            System.out.println(day - 1);
        }

        scanner.close();
    }

    static class Position {
        int x;
        int y;

        Position(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
