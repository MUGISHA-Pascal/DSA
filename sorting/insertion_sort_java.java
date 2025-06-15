package sorting;

public class insertion_sort_java {
    public static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        int[] numbers = { 8, 4, 3, 1, 2, 9,9 };
        System.out.println("Original array:");
        for (int num : numbers) {
            System.out.print(num + " ");
        }
        insertionSort(numbers);
        System.out.println("\n Sorted array:");
        for (int num : numbers) {
            System.out.print(num + " ");
        }
    }
}
