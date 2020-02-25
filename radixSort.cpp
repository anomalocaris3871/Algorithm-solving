#include <bits/stdc++.h>

#define DIGITS 4
#define BUCKETS 10

using namespace std;

void initRandom(int *list, int n, int max=10000)
{
    for(int i = 0; i < n ; ++ i)
        list[i] = rand() % max;
}

void printArray(int *arr, int n, char *str = "Array")
{
    printf("%s = ", str);
    for(int i=0; i < n; ++i )
        printf("%6d", arr[i]);
    printf("\n");
}

void radixSort(int *arr, int n)
{
    queue<int> queues[BUCKETS];
    int factor = 1;
    for(int d=0; d<DIGITS ; ++d) {
        for( int i=0; i<n; ++i)
            queues[(arr[i]/factor)%10].push(arr[i]);


        for(int b=0, i=0; b<BUCKETS ; ++b)
            while(!queues[b].empty()) {
                arr[i++] = queues[b].front();
                queues[b].pop();
            }

        factor *= 10;

        printArray(arr, n, "RadixSort ");
    }
}
int main(void)
{
    int arr[11];
    int len = sizeof(arr) / sizeof(*arr);
    initRandom(arr, len);
    printArray(arr, len, "Original ");

    radixSort(arr, len);


    return 0;
}
