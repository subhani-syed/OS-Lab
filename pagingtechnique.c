#include <stdio.h>
#include <stdlib.h>
void main()
{
    int ps, np, nf, log;
    int alloc[50], base[50], frame[50], page[50];
    int i, f, n, pa, fs, pno, add, offset;
    int temp;
    int f1;

    printf("\n\t\t PAGING\n");
    printf("\n\t Enter the logical address space:");
    scanf("%d", &log);
    printf("\n\t Enter the page size:");
    scanf("%d", &ps);
    printf("\n\t Enter the physical address space:");
    scanf("%d", &pa);
    fs = ps;
    np = log / ps;
    nf = pa / fs;
    printf("\n\t Number of pages  = %d", np);
    printf("\n\t Number of frames = %d", nf);
    for (i = 0; i < nf; i++)
        alloc[i] = 0;
    for (i = 0; i < np; i++)
    {
        temp = rand() % nf;
        while (alloc[temp] == 1)
            temp = rand() % nf;
        alloc[temp] = 1;
        frame[i] = temp;
    }
    printf("\n Page No \t Frame No \t Base address ");
    for (i = 0; i < np; i++)
    {
        base[i] = frame[i] * ps;
        page[i] = i;
        printf("\n%d\t\t %d\t %d\t\t", i, frame[i], base[i]);
    }
    getch();
}