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
    for(int i = 0; i < var; i++)
    {
        int x, y;
        fscanf(file, "%d %d", &x, &y);
        printf("%d %d\n", x, y);
    }
    fclose(file);
    return 0;
}