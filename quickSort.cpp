#include <iostream>

using namespace std;

void swap(int* arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int get_partition(int* arr, int left, int right)
{
    int pivot = arr[right];

    int index = left - 1;
    for (int i = left; i < right; ++i) {
        if (arr[i] < pivot) {
            index++;
            swap(arr, index, i);
        }
    }

    swap(arr, index + 1, right);

    return index;
}


void quick_sort_recursive(int* arr, int left, int right)
{
    if (left >= right) {
        return;
    }

    int pivot_pos = get_partition(arr, left, right);

    quick_sort_recursive(arr, left, pivot_pos - 1);
    quick_sort_recursive(arr, pivot_pos + 1, right);
}


void quick_sort(int* arr)
{
    int len = 10;
    quick_sort_recursive(arr, 0, len - 1);
}



int main(void)
{
    int arr[] = { 2, 5, 1, 3, 4, 6, 7, 7, 9, 8 };
    quick_sort(arr);

    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}