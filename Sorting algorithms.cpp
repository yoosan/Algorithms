// The simple implement of Sorting algorithms

// Including 5 sorting algorithms, which are Select-sort, Insertion-sort, Bubble-sort, Merge-sort and Quick-sort

#include <iostream>

// Display the array
void display(int *arr, int n)
{
    
    for (int i = 0; i < n - 1; i++){
        std::cout << * (arr + i ) << " ";
    }
    std::cout << arr[n-1] << std::endl;
    
}

// The swap function
inline void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

// Select sorting, the main idea is that to find the min(max) element from the unsorted array, then swap the current element and the min(max) element

bool selectSort(int *arr, int n)
{
    if (arr == NULL || n == 0) return false;
    
    for (int i = 0; i < n; i++){
        
        int flag = i;
        int min = arr[i];
        
        for (int j = i;j < n; j++){
            
            if (arr[j] < min){
                flag = j;
                min = arr[j];
            }
        }
        
        swap(arr[i], arr[flag]);
    }
    
    return true;
}
// ..

// Insertion sorting, the every step is choosing a element and then inserting to a sorted array.

bool insertionSort(int *arr, int n)
{
    if (arr == NULL || n == 0) return false;
    
    for (int i = 1; i < n; i++){
        
        int cur = arr[i];
        int j = i;
        
        for (j = i - 1; j >= 0 && cur < arr[j]; j--){
            arr[j+1] = arr[j];
        }
        
        arr[j+1] = cur;
        
    }
    
    return true;
}
//..

//Merge sorting,

void merge(int *arr, int start, int gap, int end)
{
    int n1 = gap - start + 1;
    int n2 = end - gap;
    
    int *left = new int[n1];
    int *right = new int[n2];
    
    int k = start, i = 0, j = 0;
    
    while (i < n1)  left[i++] = arr[k++];
    while (j < n2)  right[j++] = arr[k++];
    
    i = j = 0;
    k = start;
    
    while(i < n1 && j < n2) {
        
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
        
    }
    
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
    
}

void mergearray(int *arr, int start, int end)
{
    
    if (start < end){
        
        int mid = start + (end - start) / 2;

        mergearray(arr, start, mid);
        mergearray(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

bool mergeSort(int *arr, int n)
{
    if (arr == NULL || n == 0)
        return false;
    
    mergearray(arr, 0, n -1 );
    return true;
}

//...


//Bubble sort.

bool bubbleSort(int *arr, int n)
{
    if (arr == NULL || n == 0) return false;
    
    for (int i = 0; i < n; i ++)
        for (int j = n - 1; j > i; j--){
            if ( arr[j-1] > arr[j])
                swap(arr[j-1], arr[j]);
        }
    
    return true;
}
//..


//Quick sort .

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int p = start - 1;
    
    for (int i = start; i < end; i++ ){
        if (arr[i] < pivot)
            swap(arr[++p], arr[i]);
    }
    
    swap(arr[p + 1], arr[end]);
    
    return p + 1;
}

void sort(int *arr, int start, int end)
{
    if (start < end){
        
        int part = partition(arr, start, end);
        sort(arr, start, part - 1);
        sort(arr, part + 1, end);
    }
}

bool quickSort(int *arr, int n)
{
    if (arr == NULL || n == 0) return false;
    
    sort(arr, 0, n - 1);
    return true;
}

//...
int main()
{
    int a[] = {21, 3, 23, 5, 77, 421, 1, 32311, 21, 2};
    
    int n = sizeof(a) / sizeof(a[0]);
    
    display(a, n);
    
    quickSort(a, n);
    display(a, n);
    
}