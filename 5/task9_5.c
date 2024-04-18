// В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное
// слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть
// несколько, не обрабатывать.

#include <stdio.h>
#include <string.h>

int main()
{
    char file_in[] = "in.txt";
    char file_out[] = "out.txt";

    char str[1000];
    char long_wrd[1000];
    int max_len = 1;
    char tmp_wrd[1000];
    int count;
    FILE *f_p = fopen(file_in, "r");
    while(fscanf(f_p, "%s", str) == 1)
    {
        if (max_len < strlen(str))
        {
            strcpy(long_wrd, str);
            max_len = strlen(str);
        }
    }
        
    fclose(f_p);
    
    FILE *f_out = fopen(file_out, "w");
    fprintf(f_out, "%s", long_wrd);
    fclose(f_out);

    return 0;
}