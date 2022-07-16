#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdio>

using namespace std;

//sorting algorithms
void bubbleSort(int arr[], int s, int l);
void insertionSort(int arr[], int s, int l);
void selectionSort(int arr[], int s, int l);
void mergeSort(int arr[], int s, int l);
void quickSort(int arr[], int s, int l);

void swap(int *a, int *b);
void printArr(int arr[], int s, int l);
void getArray(int arr[], int s);
void mergeArray(int arr[], int s, int mid, int l);
int Division(int arr[], int s, int l);
void Allocate(int a[], int b[], int s, int l);
typedef void (*f)(int[], int, int);

typedef void (*f)(int[], int, int);
f sort[5] = {&bubbleSort, &insertionSort, &selectionSort, &mergeSort, &quickSort};

int main(void)
{
    FILE *fileText = fopen("lab2_2.txt", "w");
    for(int j = 2500; j <= 60000; j+=2500)
    {
        int sizeIn = j;
        int n[sizeIn];
        getArray(n, sizeIn);

        clock_t start[5];
        clock_t last[5];

        double timeUsed[5];

        int a[5][sizeIn];

        fprintf(fileText, "%d," ,sizeIn);

        for(int i = 0; i < 5;i++)
        {
            Allocate(a[i], n, 0, sizeIn - 1);
            start[i] = clock();
            sort[i](a[i], 0, sizeIn - 1);
            last[i] = clock();
            timeUsed[i] = (double)(last[i] - start[i]) / CLOCKS_PER_SEC;
            if(i!=4)
            {
                fprintf(fileText, "%f," , timeUsed[i]);
            }

            else
            {
                fprintf(fileText, "%f\n", timeUsed[i]);
            }
        }
    }

    return 0;
}

void bubbleSort(int arr[], int s, int l)
{
    int sort = 1;

    while(sort)
    {
        sort = 0;
        for(int i = 0; i < l; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                sort = 1;
            }
        }

        l--;
    }
}

void insertionSort(int arr[], int s, int l)
{
    int n;

    while(s < l)
    {
        n = s + 1;

        while(n > 0 && arr[n] < arr[n - 1])
        {
            swap(&arr[n], &arr[n - 1]);
            n--;
        }

        s++;
    }
}

void selectionSort(int arr[], int s, int l)
{
    while(s <= l)
    {
        int prev = s;
        int current = s;

        for(int i = s; i <= l; i++)
        {
            if(arr[current] < arr[prev])
            {
                prev = current;

            }
            current++;
        }

        swap(&arr[s], &arr[prev]);
        s++;
    }
}

void mergeSort(int arr[], int s, int l)
{
    if(s < l)
    {
        int middle = (s + l) / 2;

        mergeSort(arr, s, middle);
        mergeSort(arr, middle + 1, l);
        mergeArray(arr, s, middle, l);
    }
}

void quickSort(int arr[], int s, int l)
{
    if(s < l)
    {
        int n = Division(arr, s, l);
        quickSort(arr, s, n-1);
        quickSort(arr, n+1, l);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int s, int l)
{
    while(s <= l)
    {
        cout<<arr[s];
        s++;
    }

    cout<<endl;
}

void getArray(int arr[], int s)
{
    srand(time(NULL));

    for(int i = 0; i < s; i++)
    {
        arr[i] = rand() % (s * 3);
    }
}

void Allocate(int a[], int b[], int s, int l)
{
    for(int i = s; i <= l; i++)
    {
        a[i] = b[i];
    }
}

int Division(int arr[], int s, int l)
{
    int p = arr[l];
    int i = s;

    for(int n = s; n <= l-1; n++)
    {
        if(arr[n] <= p)
        {
            swap(&arr[i], &arr[n]);
            i++;
        }
    }

    swap(&arr[i], &arr[l]);
    return i;
}

void mergeArray(int arr[], int s, int mid, int l)
{
    int n[l-s+1];
    int i = s;
    int j = mid + 1;
    int k = 0;

    while(i <= mid&& j<= l)
    {
        if(arr[i] < arr[j])
        {
            n[k] = arr[i];
            k++;
            i++;
        }

        else
        {
            n[k] = arr[j];
            k++;
            j++;
        }

    }

    while(i <= mid)
    {
        n[k] = arr[i];
        k++;
        i++;
    }

    while(j <= l)
    {
        n[k] = arr[j];
        k++;
        j++;
    }

    for(int p = 0; p < k; p++)
    {
        arr[s+p] = n[p];
    }
}

