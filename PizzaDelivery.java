import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


class Test {
    static int[][] map;
    static int n;
    static int m;
    static List<Pair> pizzaRestaurant = new ArrayList<>();
    static List<Pair> house = new ArrayList<>();

    static int[] selected;
    static int minCity = Integer.MAX_VALUE;

    static void dfs(int index, int level) {
        if (level == m) {
            int sum = 0;
            for (int j = 0; j < house.size(); ++j) {
                int minDistance = Integer.MAX_VALUE;
                for (int i = 0; i < m; ++i) {
                    int result = (Math.abs(pizzaRestaurant.get(selected[i]).getRow() - house.get(j).getRow())
                            + Math.abs(pizzaRestaurant.get(selected[i]).getColumn() - house.get(j).getColumn()));
                    if (result < minDistance) {
                        minDistance = result;
                    }
                }
                sum += minDistance;
            }

            if (sum < minCity) {
                minCity = sum;
            }
            return;
        }

        for (int i = index; i < pizzaRestaurant.size(); ++i) {
            selected[level] = i;
            dfs(index + 1, level + 1);
        }

    }

    static class Pair {
        int row;
        int column;

        public Pair(int value1, int value2) {
            this.row = value1;
            this.column = value2;
        }

        public int getRow() {
            return row;
        }

        public int getColumn() {
            return column;
        }
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();

        selected = new int[m];
        map = new int[n + 1][n + 1];

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                map[i][j] = scanner.nextInt();
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (map[i][j] == 1) {
                    house.add(new Pair(i, j));
                } else if (map[i][j] == 2) {
                    pizzaRestaurant.add(new Pair(i, j));
                }
            }
        }

        dfs(0, 0);
        System.out.println(minCity);
    }
}
