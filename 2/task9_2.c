// В файле .txt дана символьная строка не более 1000 символов. Необходимо
// заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
// строчные. Результат записать в .txt.

#include <stdio.h>
#include <string.h>

int main()
{
    char file_in[] = "in.txt";
    char file_out[] = "out.txt";

    char str[1000];
    FILE *f_in = fopen(file_in, "r");
    fscanf(f_in, "%[^\n]", str);
    fclose(f_in);

    // int i = 0;
    // char c;
    // while(c = str[i] != '\0')
    for(int i = 0; i < (int)strlen(str); i++)
    {
        if (str[i]=='a' || str[i] == 'A')
            str[i] = str[i]+1;
        else if (str[i] == 'b' || str[i] == 'B')
            str[i] = str[i] - 1;
        
    }

    FILE *f_out = fopen(file_out, "w");
    fprintf(f_out, "%s", str);
    fclose(f_out);

    return 0;
}
