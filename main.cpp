#include <bits/stdc++.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

const long long N = 1000000;

float arr[N];

// Quick Sort

void quickSort(float a[], int l, int r)
{
    float p = a[(l + r)/2];
    int i = l, j = r;
    while (i < j)
    {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (i < r) quickSort(a, i, r);
    if (j > l) quickSort(a, l, j);
}

// Heap Sort

void heapify(float arr[], int i, int n)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void heapSort(float arr[], int n)
{
    for (int i = n/2-1; i >= 0; i--) heapify(arr, i, n);
    for (int i = n-1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

// Merge Sort
float L[N/2], R[N/2];

void merge(float arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(float arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        if (arr[m] > arr[m + 1]) merge(arr, l, m, r);
    }
}

int main() {
    cout << "Type a number to choose the algorithm you want to test.\n1. Sort (C++)\n2. Quicksort\n3. Heapsort\n4. Mergesort\n";
    int choice;
    cin >> choice;
    //long result[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int testcase = 1; testcase <= 10; testcase++)
    {
        string input = "test" + to_string(testcase) + ".inp";
        ifstream inputFile(input);
        if (!inputFile.is_open())
        {
            cerr << "Unable to open the file for reading." << endl;
            return 1;
        }
        float value;
        for (int i = 0; i < N; i++) {
            inputFile >> value;
            arr[i] = value;
        }
        inputFile.close();



        auto clock_wait = high_resolution_clock :: now();

        switch(choice)
        {
            case 1:
                sort(arr, arr + N);
                break;
            case 2:
                quickSort(arr, 0, N-1);
                break;
            case 3:
                heapSort(arr, N);
                break;
            case 4:
                mergeSort(arr, 0, N-1);
                break;
        }
        auto clock_end = high_resolution_clock :: now();
        auto duration = duration_cast<milliseconds>(clock_end - clock_wait);
        cout << "test" << testcase << ": " << duration.count() << "ms" << endl;

    }
    return 0;
}
