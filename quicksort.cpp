#include <bits/stdc++.h>

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void initRandom(int *list, int n, int max=100)
{
    for(int i = 0; i < n ; ++ i)
        list[i] = rand() % max;
}

void printArray(int *arr, int n, char *str = "Array")
{
    printf("%s = ", str);
    for(int i=0; i < n; ++i )
        printf("%3d", arr[i]);
    printf("\n");
}

int partition(int *arr, int left, int right)
{
    int low = left;
    int high = right+1;
    int pivot = arr[left];


    do {
        do {
            low++;
        }while(low<=right && arr[low] <pivot);

        do {
            high--;
        } while(high>=left && arr[high] >pivot);

        if( low < high)
            swap(arr[low], arr[high]);
    }while(low < high);

    swap(arr[left], arr[high]);
    //The values of the pivot and arr[left] are the same,
    //but the swap uses reference, so it should be used arr[left].
    return high;
}

void quickSort(int *arr, int left, int right)
{
    if(left < right){
        int q = partition(arr, left, right);
        quickSort(arr, left, q-1);
        quickSort(arr, q+1, right);
    }
}




int main(void)
{
    int arr[16];
    int len = sizeof(arr) / sizeof(*arr);
    initRandom(arr, len);
    printArray(arr, len, "Original ");

    quickSort(arr, 0, len-1);
    printArray(arr, len, "QuickSort ");

    return 0;

}
