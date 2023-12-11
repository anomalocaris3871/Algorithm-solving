import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Test {

    static int[] combination = null;
    static int n;
    static int r;

    public static void dfs(int index, int level) {
        if (level == r) {
            for (int i = 0; i < level; ++i) {
                System.out.print(combination[i]);
            }
            System.out.println();
            return;
        }
        for (int i = index; i < n; ++i) {
            combination[level] = i;
            dfs(i + 1, level + 1);
        }

    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        r = scanner.nextInt();

        combination = new int[r];
        dfs(0, 0);


    }
}
