#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
double calculate(double num1, char operator, double num2);
int main() 
{
    char input[100];
    double result = 0;
    int check_first = 1;

    printf("欢迎使用计算器!\n");
    printf("请输入表达式(如: 1+1)，输入exit退出，输入ac清零\n");

    while (1) 
    {
        printf("-> ");
        fgets(input, sizeof(input), stdin);

        // 移除换行符
        input[strcspn(input, "\n")] = 0;

        // 检查退出条件
        if (strcmp(input, "exit") == 0) 
        {
            break;
        }

        // 检查清零条件
        if (strcmp(input, "ac") == 0) 
        {
            result = 0;
            check_first = 1;
            printf("已清零\n");
            continue;
        }

        double num1, num2;
        char operator;

        // 解析输入的表达式
        if (check_first)
        {
            if (scanf(input, "%lf %c %lf", &num1, &operator, &num2) == 3)
            {
                result = calculate(num1, operator, num2);
                printf("= %.2lf\n", result);
                check_first = 0;
            }
            else 
            {
                printf("输入格式错误！请使用正确格式，例如：5 + 3\n");
            }
        }
        else 
        {
            // 使用上一次结果作为第一个数
            if (scanf(input, "%c %lf", &operator, &num2) == 2) 
            {
                result = calculate(result, operator, num2);
                printf("= %.2lf\n", result);
            }
            else
            {
                printf("输入格式错误！请使用正确格式，例如：+ 3\n");
            }
        }
    }

    printf("谢谢使用计算器!\n");
    return 0;
}


double calculate(double num1, char operator, double num2)
{
    switch (operator)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0)
        {
            printf("错误：除数不能为0！\n");
            return num1;
        }
        return num1 / num2;
    case '^':
        return pow(num1, num2);
    default:
        printf("错误：无效的运算符！\n");
        return num1;
    }
}
