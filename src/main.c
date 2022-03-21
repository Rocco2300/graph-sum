#include <stdio.h>

int main()
{
    FILE* file;
    file = fopen("ceva.txt", "r");
    if(file == NULL)
    {
        printf("Error opening file!");
        return 0;
    }
    int var;
    fscanf(file, "%d", &var);
    printf("%d", var);
    fclose(file);
    return 0;
}