#include <stdio.h>
#define N 6

void bubble_sort(int arr[], int size)
{
    // 传数组不会全部传
    int ret;
    int j, flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 1;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                ret = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = ret;
                flag = 0;
            }
        }
        if (flag == 1)
            break;
    }
}

void bubble_sort1(int arr[])
{
    // 传数组不会全部传
    int ret;
    int j, flag;
    for (int i = 0; i < N - 1; i++)
    {
        flag = 1;
        for (j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                ret = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = ret;
                flag = 0;
            }
        }
        if (flag == 1)
            break;
    }
}

void swap(char *buf1, char *buf2, int width)
{
    char brief;
    int i;
    for (i = 0; i < width; i++)
    {
        brief = *buf1;
        *buf1 = *buf2;
        *buf2 = brief;
        buf1++;
        buf2++;
    }
}

void bubble_sort2(void *base, int size, int width, int (*compare)(const void *element1, const void *element2))
{
    int i, j, k;
    int flag = 0;
    char brief;
    for (i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if ((*compare)((char *)base + j * width, (char *)base + (j + 1) * width) > 0)
            {
                flag = 1;
                for (k = 0; k < width; k++) // 1
                {
                    brief = (*(char *)(base + j * width + k));
                    (*(char *)(base + j * width + k)) = (*(char *)(base + (j + 1) * width + k));
                    (*(char *)(base + (j + 1) * width + k)) = brief;
                } // 1
                // swap((char *)base + j * width, (char *)base + (j + 1) * width, width);//2
            }
        }
        if (flag == 0)
            break;
    }
}

int compare_int(const void *e1, const void *e2)
{
    return *(int *)e1 - *(int *)e2;
}

int main(int argc, char const *argv[])
{
    int a[N];
    int size;
    printf("please input:");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    size = sizeof(a) / sizeof(a[0]);
    // bubble_sort(a,size);//冒泡排序
    bubble_sort2(a, size, sizeof(a[0]), &compare_int);
    for (int i = 0; i < N; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
