import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int i, j, max=0;
        int n = sc.nextInt();
        int m = sc.nextInt();
        String[] num = new String[n+1];
        int[][] dp = new int[n+1][m+1];
        for(i=1; i<n+1; i++) {
            num[i] = sc.next();    //num[]에 한 줄씩 넣기
            for (j = 1; j < m+1; j++) {
                dp[i][j] = num[i].charAt(j-1)-'0';    //num[]의 요소를 한 글자씩 dp[][]에 넣기
            }
        }
        for (i=1; i < n+1; i++) {
            for (j = 1; j < m+1; j++) {
                if (dp[i][j] == 1) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
                    max = dp[i][j]<max ?max :dp[i][j];
                }
            }
        }
        System.out.println(max*max);
        sc.close();
    }
    private static int min(int x, int y, int z) {
        x = x<y ?x :y;
        return x<z ?x :z;
    }
}