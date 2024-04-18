// В файле .txt строка из маленьких и больших английских букв, знаков
// препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
// все пробелы. Результат записать в файл .txt.

#include <stdio.h>
#include <string.h>

int main()
{
    char file_in[] = "in.txt";
    char file_out[] = "out.txt";

    char str[1001];
 
    FILE *f_in = fopen(file_in, "r");
    fscanf(f_in, "%[^\n]", str);
    fclose(f_in);

    for( int i = 0; i<strlen(str)-1; i++)
        if (str[i]!=' ')
            for (int j = i+1; j < strlen(str); j++)
            {
                if (str[i] == str [j])
                {
                    str[j] = ' ';
                }
            }
    
    fputs(str, stdout);
     FILE *f_out = fopen(file_out, "w");
     int i = -1;
     while (str[++i] != '\0')
        if (str[i]!= ' ')
            fprintf(f_out, "%c", str[i]);
    fclose(f_out);
    return 0;
}