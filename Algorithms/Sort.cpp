#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int n = 10;
int a[n];

void khoi_tao()
{
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
}

void in_ds(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

/**
 * Ý tưởng thuật toán là thực hiện n-1 lượt việc đưa phần tử nhỏ nhất trong
 * dãy hiện hành về vị trí đúng ở đầu dãy
 * https://youtu.be/xWBP4lzkoyM
*/
void selection_sort(int a[], int n)
{
    // Từng bước một di chuyển ranh giới của mảng con chưa sắp xếp
    for (int i = 0; i < n - 1; i++)
    {
        // Tìm chỉ số của phần tử nhỏ nhất trong mảng chưa được sắp xếp
        int vt_min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[vt_min])
                vt_min = j;

        // Hoán đổi phần tử nhỏ nhất được tìm thấy với phần tử đầu tiên
        if (vt_min != i)
        {
            int tam = a[i];
            a[i] = a[vt_min];
            a[vt_min] = tam;
        }

        // printf("\nBuoc thu %d: ", i + 1);
        // in_ds(a, n);
    }
}

/**
 * Sắp xếp chèn là một thuật toán sắp xếp bắt chước cách sắp xếp quân bài của
 * những người chơi bài. Muốn sắp một bộ bài theo trật tự người chơi bài rút lần
 * lượt từ quân thứ 2, so với các quân đứng trước nó để chèn vào vị trí thích hợp.
 * Nếu danh sách đã gần đúng thứ tự, Insertion Sort sẽ chạy rất nhanh.
 * https://youtu.be/OGzPmgsI-pQ
*/
void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int j = i - 1;
        while ((a[j] > x) && (j >= 0))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = x;
        // printf("\nBuoc thu %d: ", i);
        // in_ds(a, n);
    }
}

void buble_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1])
            {
                int tam = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tam;
            }
    }
}

void interchange_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[i])
            {
                int tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
}

int main()
{
    khoi_tao();
    printf("Day so ban dau: ");
    in_ds(a, n);

    selection_sort(a, n);

    printf("\nDay so sau khi sap xep: ");
    in_ds(a, n);
    return 0;
}
