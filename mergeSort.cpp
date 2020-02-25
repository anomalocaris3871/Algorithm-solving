#include <bits/stdc++.h>

#define MAX_SIZE 1024

using namespace std;

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

void merge(int *arr, int left, int mid, int right)
{
    int i, j, k = left, l;
    static int sorted[MAX_SIZE];

    for(i=left, j=mid+1; i<=mid && j<=right ; )
        sorted[k++] = (arr[i] <= arr[j] ? arr[i++] : arr[j++]);

    if (i > mid)
        for(l=j; l<=right; l++, k++)
            sorted[k++] = arr[l];
    else
        for(l=i; l<=mid; l++, k++)
            sorted[k] = arr[l];

    for(l = left ; l<=right; l++)
        arr[l] = sorted[l];



void mergeSort(int *arr, int left, int right)
{
    if(left < right) {
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(void)
{
    int arr[16];
    int len = sizeof(arr) / sizeof(*arr);
    initRandom(arr, len);
    printArray(arr, len, "Original ");

    mergeSort(arr, 0, len-1);
    printArray(arr, len, "MergeSort ");

    return 0;

}
