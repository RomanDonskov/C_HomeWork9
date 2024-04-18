// В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые
// числа и иные символы. Требуется все числа, которые встречаются в строке,
// поместить в отдельный целочисленный массив. Например, если дана строка
// "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
// массив по возрастанию в файл .txt.

#include <stdio.h>
#include <string.h>

int find_nums(char *str, int nums[])
    {
         int i = 0;
        int j = 0;
        int n;
        while(str[i] != '\0')
        {
            if (str[i]>='0' && str[i] <='9')
            {
                n = 0;
                while(str[i]>='0' && str[i]<='9')
                {
                    n = n*10 + (str[i]-'0');
                    i++;
                }
                nums[j++] = n;
            
            }
            i++;
        }
        return j;
    }
int main()
{
    char file_in[] = "in.txt";
    char file_out[] = "out.txt";

    char str[1000];
    int k,tmp;
    int nums[1000];
    FILE *f_in = fopen(file_in, "r");
    fscanf(f_in, "%[^\n]", str);
    fclose(f_in);

    k = find_nums(str, nums);
    for (int i = 0; i<k-1; i++)
        for (int j = i+1; j<k; j++)
        {
            if (nums[i]>nums[j])
            {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    //for(int i = 0; i<k; i++) printf("%4d", nums[i]);
    
    FILE *f_out = fopen(file_out, "w");
    for (int i = 0; i<k; i++)
    fprintf(f_out, "%4d", nums[i]);
    fclose(f_out);

    return 0;
}
