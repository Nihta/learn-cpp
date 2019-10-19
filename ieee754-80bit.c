#include <stdio.h>
#include <math.h>

// In size phần tử của mảng arr bắt đầu từ start
void printArray(int arr[], int start, int size)
{
    for (int i = start; i < start + size; i++)
        printf("%d", arr[i]);
}

// Tìm b ( ... 2^b)
int findB(int arr[], int size, int indexCommaCurent)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == 1)
            return indexCommaCurent - (i + 1);
    return 0;
}

// Tìm vị trí đấu phẩy (ở bước 2)
int findIndexComma(int binFloat[], int arrSize)
{
    int i;
    for (i = 0; i < arrSize; i++)
        if (binFloat[i] == 1)
            break;
    return i + 1;
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
void handleM(int result[], int binFloat[], int indexComma)
{
    int index = 0;
    for (int i = indexComma + 1; i < 65 - indexComma - 1; i++)
        result[16 + index++] = binFloat[i];

    // Bổ sung số 0 cho đủ 64 bit (nếu thiếu)
    while (index == 64)
        result[index++] = 0;
}

// In mã bin ra mà hình
void printBin(int result[])
{
    for (int i = 0; i < 80; i += 4)
        printf("%d%d%d%d ", result[i], result[i + 1], result[i + 2], result[i + 3]);
}

// Chuyển từ bin qua hex và in ra màn hình
void printBinToHex(int result[])
{
    char dataBaseHex[15] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < 80; i += 4)
    {
        int value = result[i] * 8 + result[i + 1] * 4 + result[i + 2] * 2 + result[i + 3];
        printf("%c", dataBaseHex[value]);
    }
    printf("H");
}

void solution(double X)
{
    if (X == 0)
    {
        printf("X = 00000000000000000000H");
        return;
    }

    // Tách phần nguyên và phần thập phân
    long long n;
    double f;
    if (X < 0)
    {
        n = floor(-X);
        f = -X - n;
    }
    else
    {
        n = floor(X);
        f = X - n;
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
    int tmp2[65] = {0}, size2 = 0;
    while (size2 < 65 - size1 && f != 0.0)
    {
        f *= 2;
        if (f >= 1)
        {
            tmp2[size2++] = 1;
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
    printf("Buoc 1: X = %c", X < 0 ? '-' : ' ');
    // In dữ liệu
    if (size1 == 0)
        printf("0");
    printArray(binFloat, 0, size1);
    if (size2 != 0)
        printf(",");
    printArray(tmp2, 0, size2);

    // Bước 2
    printf("\nBuoc 2: X = %c", X < 0 ? '-' : ' ');
    // Tìm b
    int b = findB(binFloat, 65, size1);
    // Tìm vị trí dấu phẩy
    int indexComma = findIndexComma(binFloat, size1 + size2);
    // In dữ liệu
    printf("1,");
    for (int i = indexComma; i < size1 + size2; i++)
        printf("%d", binFloat[i]);
    if (indexComma == size1 + size2)
        printf("0");
    printf(" * 2^(%d)", b);

    // Bước 3
    int result[80] = {0};
    printf("\nBuoc 3: Ta co:\n");

    // Tìm S
    if (X >= 0)
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
    handleM(result, binFloat, indexComma);
    printArray(result, 16, 64);

    // Bước 4
    // In mã bin
    printf("\n => X = ");
    printBin(result);

    // In mã hex
    printf("\n      = ");
    printBinToHex(result);
}

int main()
{
    double X;
    printf("Nhap X = ");
    scanf("%lf", &X);

    system("cls");

    printf("%lf -> IEEE 754/85 (80bit)\n", X);
    solution(X);

    printf("\n===============================================================");
    printf("============================================");

    return 0;
}
