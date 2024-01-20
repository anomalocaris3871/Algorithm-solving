import java.util.Scanner;


class Test {

    static int[] dp = new int[1001];
    static int[] sequence = new int[1001];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        for (int i = 1; i <= n; ++i) {
            sequence[i] = scanner.nextInt();

        }


        int max = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = 1;
            for (int j = 1; j < i; ++j) {
                if (sequence[i] > sequence[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    if(dp[i] > max) {
                        max = dp[i];
                    }
                }
            }
        }

        System.out.println(max);
        scanner.close();
    }
}
