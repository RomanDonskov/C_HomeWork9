#include <stdio.h>
#include <string.h>

int main()
{
    char file_in[] = "in.txt";
    char file_out[] = "out.txt";

    char wrd1[100], wrd2[100];
    int alf1[26] = {0}, alf2[26] = {0};

    FILE *f_in = fopen(file_in, "r");
    fscanf(f_in, "%s%s", wrd1, wrd2);
    fclose(f_in);

    int i = 0;
    while(i < (int)strlen(wrd1))
    {
        alf1[wrd1[i]-'a']++;
        i++;
    }

    i = 0;
    while(i < (int)strlen(wrd2))
    {
        alf2[wrd2[i]-'a']++;
        i++;
    }

    FILE *f_out = fopen(file_out, "w");
    for (int j = 0; j < 26; j++)
    {
        if (alf1[j] == 1 && alf2[j] == 1)
            fprintf(f_out, "%c", j+'a');
    }
    fclose(f_out);

    return 0;
}