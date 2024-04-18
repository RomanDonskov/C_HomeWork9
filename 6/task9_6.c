// В файле .txt дано предложение. Необходимо определить, сколько слов
// заканчиваются на букву 'а'. Ответ записать в файл .txt.
#include <stdio.h>
#include <string.h>

int main()
{
    char file_in[] = "in.txt";
    char file_out[] = "out.txt";
    char str[1000];
    int i = 0;
    FILE *f_p = fopen(file_in, "r");
    while(fscanf(f_p, "%s", str) == 1)
    {
        if (str[strlen(str)-1] == 'a')
            i++;
    }
        
    fclose(f_p);
    
    f_p = fopen(file_out, "w");
    fprintf(f_p, "%d", i);
    fclose(f_p);

    return 0;
}