public class Main {

    public static void printArray(int[] a, int n) {
        for (int i = 0; i < n; i++){
            System.out.println(a[i]);
        }
    }


    public static void swap(int[] arr, int a, int b) {
        int t = arr[a];
        arr[a] = arr[b];
        arr[b] = t;
    }

    public static boolean seleciontSort(int[] a, int n) {
        if (a == null) return false;
        for (int i = 0; i < n ; i++){
            int flag = i;
            for (int j = i; j < n; j++){
                if (a[j] < a[flag]){
                    flag = j;
                }
                else continue;
            }
            swap(a, i, flag);
        }
        return true;
    }

    public static boolean insertionSort(int[] a, int n) {
        if (a == null) return false;
        for (int i = 1; i < n; i ++) {
            int cur = a[i];
            int j = i - 1 ;
            for (; j >=0 && cur < a[j]; j--){
                a[j+1] = a[j];
            }
            a[j+1] = cur;
        }
        return true;
    }

    public static boolean bubbleSort(int[] a, int n) {
        if (a == null) return false;

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (a[j] < a[j - 1]) {
                    swap(a, j, j-1);
                }
            }
        }
        return true;
    }

    public static void merge(int[] a,int start,int gap, int end) {
        int n1 = gap - start + 1;
        int n2 = end - gap;
        int i = 0, j = 0, k = start;
        int[] left = new int[n1], right = new int[n2];

        while (i < n1) {
            left[i++] = a[k++];
        }
        while (j < n2) {
            right[j++] = a[k++];
        }

        i = j = 0;
        k = start;

        while (i < n1 && j < n2){
            if (left[i] < right[j]){
                a[k++] = left[i++];
            }
            else
                a[k++] = right[j++];
        }

        while (i < n1) a[k++] = left[i++];
        while (j < n2) a[k++] = right[j++];

    }


    public static void mergearray(int[] a, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            mergearray(a, start, mid);
            mergearray(a, mid + 1, end);
            merge(a, start, mid, end);
        }
    }

    public static boolean mergeSort(int[] a, int n) {
        if (a == null) return false;

        mergearray(a, 0, n - 1);
        return true;
    }

    public static int partition(int[] a, int start, int end) {
        int pivot = a[end];
        int p = start - 1, q = start;

        for (;q < end; q++) {
            if (a[q] < pivot) {
                swap(a, ++p, q);
            }
        }
        swap(a, p+1, end);
        return p + 1;
    }

    public static void quick(int[] a, int start, int end) {
        if (start < end) {
            int part = partition(a, start, end);
            quick(a, start, part - 1);
            quick(a, part + 1, end);
        }
    }

    public static boolean quickSort(int[] a, int n) {
        if (a == null) return false;

        quick(a, 0, n - 1);
        return true;
    }

    public static void main(String[] args) {
        System.out.println("Hello World!");

        int a[] = {21,11,3,14,5,26,7};
        int n = a.length;
        System.out.println("The size of array is " + n);

        printArray(a, n);
        System.out.println("--------------------");
        //seleciontSort(a, n);
        //insertionSort(a, n);
        //bubbleSort(a, n);
        //mergeSort(a, n);
        quickSort(a, n);
        printArray(a, n);

    }
}
