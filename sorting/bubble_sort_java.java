package sorting;

public class bubble_sort_java {
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }

    public static void main(String[] args) {
        int[] arr = { 64, 34, 25, 29, 30, 23 };
        System.out.println("Original array:");
        for (int value : arr) {
            System.out.println(value + " ");
        }
        bubbleSort(arr);
        System.out.println("\nSorted array:");
        for (int value : arr) {
            System.out.println(value + " ");
        }
    }
}
