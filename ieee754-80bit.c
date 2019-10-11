#include <stdio.h>
#include <math.h>

// In size phần tử của mảng arr bắt đầu từ start
void printArray(int arr[], int start, int size)
{
    for (int i = start; i < start + size; i++)
        printf("%d", arr[i]);
}

// Tìm b
int findB(int arr[], int size, int indexCurent)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
            return abs(indexCurent - i - 1);
    }
    return 0;
}

// Tìm E và chuyển vào mảng kết quả
void handleE(int result[], int E)
{
    int tmp[15] = {0}, i = 0, index = 1;
    while (E != 0)
    {
        tmp[i++] = E % 2;
        E /= 2;
    }

    for (int j = 14; j >= 0; j--)
        result[index++] = tmp[j];
}

// Tìm M và chuyển M vào mảng kết quả
void handleM(int result[], int binFloat[], int indexDauPhay)
{
    int index = 0;
    for (int i = indexDauPhay + 1; i < 65 - indexDauPhay - 1; i++)
        result[16 + index++] = binFloat[i];

    // Bổ sung số 0 cho đủ 64 bit (nếu thiếu)
    while (index == 64)
        result[index++] = 0;
}

// Chuyển từ bin qua hex
void toHex(char hex[], int result[])
{
    int index = 0;
    char dataBaseHex[15] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < 80; i += 4)
    {
        int value = result[i] * 8 + result[i + 1] * 4 + result[i + 2] * 2 + result[i + 3];
        hex[index++] = dataBaseHex[value];
    }
}

void solution(double question)
{
    if (question == 0)
    {
        printf("X = 00000000000000000000H");
        return;
    }

    long long n;
    double f;
    if (question < 0)
    {
        n = floor(-question);
        f = -question - n;
    }
    else
    {
        n = floor(question);
        f = question - n;
    }

    int binFloat[65] = {0};

    // Chuyển phần nguyên sang nhị phân
    int tmp1[65], size1 = 0;

    while (n != 0)
    {
        tmp1[size1++] = n % 2;
        n /= 2;
    }
    // Đưa dữ liệu vào vừa chuyển được vào tạm array binFloat
    for (int i = 0; i < size1; i++)
        binFloat[i] = tmp1[size1 - 1 - i];

    // Chuyển phần thập phân sang nhị phân
    int maxSize = 65 - size1;
    int tmp2[maxSize] = {0}, size2 = 0;
    while (f != 1.0 && size2 < maxSize && f != 0.0)
    {
        f *= 2;
        if (f >= 1)
        {
            tmp2[size2++] = 1;
            if (f == 1.0)
                break;
            f -= 1;
        }
        else
        {
            tmp2[size2++] = 0;
        }
    }
    // Đưa dữ liệu vào vừa chuyển được vào tạm array binFloat
    for (int i = 0; i < size2; i++)
        binFloat[size1 + i] = tmp2[i];

    // Bước 1
    printf("Buoc 1: X = ");
    if (question < 0)
        printf("-");
    printArray(binFloat, 0, size1);
    printf(",");
    printArray(tmp2, 0, size2);

    // Bước 2
    printf("\nBuoc 2: X = ");
    if (question < 0)
        printf("-");
    int b = findB(binFloat, 65, size1);
    int indexDauPhay = -1;
    for (int i = 0; i < size1 + size2; i++)
    {
        printf("%d", binFloat[i]);
        if (binFloat[i] == 1 && indexDauPhay == -1)
            printf(","), indexDauPhay = i;
    }
    printf(" * 2^%d\n", b);

    // Bước 3
    // Tìm S
    int result[80] = {0};
    printf("Buoc 3: Ta co:\n");
    if (question >= 0)
    {
        result[0] = 0;
        printf("\tS = 0, vi X > 0\n");
    }
    else
    {
        result[0] = 1;
        printf("\tS = 1, vi X < 0\n");
    }
    // Tìm E
    int E = b + 16383;
    printf("\tE - 16383 = %d => E = %d = ", b, E);
    handleE(result, E);
    printArray(result, 1, 15);
    // Tìm M
    printf("\n\tM = ");
    handleM(result, binFloat, indexDauPhay);
    printArray(result, 16, 64);

    // Bước 4
    printf("\n => X = ");
    for (int i = 0; i < 80; i += 4)
        printf("%d%d%d%d ", result[i], result[i + 1], result[i + 2], result[i + 3]);

    printf("\n      = ");
    char hex[20];
    toHex(hex, result);
    for (int i = 0; i < 20; i++)
        printf("%c", hex[i]);
    printf("H");
}

int main()
{
    double question;
    printf("Nhap X = ");
    scanf("%lf", &question);

    solution(question);

    return 0;
}
