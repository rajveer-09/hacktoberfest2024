import java.util.Scanner;

public class BookAllocation {

    private static boolean isPossible(int[] arr, int n, int m, int currMin) {
        int studentsRequired = 1;
        int currSum = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > currMin) return false;

            if (currSum + arr[i] > currMin) {
                studentsRequired++;
                currSum = arr[i];

                if (studentsRequired > m) return false;
            } else {
                currSum += arr[i];
            }
        }
        return true;
    }

    private static int findPages(int[] arr, int n, int m) {
        if (n < m) return -1;

        int sum = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (arr[i] > max) max = arr[i];
        }

        int start = max;
        int end = sum;
        int result = Integer.MAX_VALUE;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (isPossible(arr, n, m, mid)) {
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int[] pages = new int[n];
        for (int i = 0; i < n; i++) {
            pages[i] = scanner.nextInt();
        }

        int result = findPages(pages, n, m);
        System.out.println(result);

        scanner.close();
    }
}
