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

    printf("��ӭʹ�ü�����!\n");
    printf("��������ʽ(��: 1+1)������exit�˳�������ac����\n");

    while (1) 
    {
        printf("-> ");
        fgets(input, sizeof(input), stdin);

        // �Ƴ����з�
        input[strcspn(input, "\n")] = 0;

        // ����˳�����
        if (strcmp(input, "exit") == 0) 
        {
            break;
        }

        // �����������
        if (strcmp(input, "ac") == 0) 
        {
            result = 0;
            check_first = 1;
            printf("������\n");
            continue;
        }

        double num1, num2;
        char operator;

        // ��������ı��ʽ
        if (check_first)
        {
            if (sscanf(input, "%lf %c %lf", &num1, &operator, &num2) == 3)
            {
                result = calculate(num1, operator, num2);
                printf("= %.2lf\n", result);
                check_first = 0;
            }
            else 
            {
                printf("�����ʽ������ʹ����ȷ��ʽ�����磺5 + 3\n");
            }
        }
        else 
        {
            // ʹ����һ�ν����Ϊ��һ����
            if (sscanf(input, "%c %lf", &operator, &num2) == 2) 
            {
                result = calculate(result, operator, num2);
                printf("= %.2lf\n", result);
            }
            else
            {
                printf("�����ʽ������ʹ����ȷ��ʽ�����磺+ 3\n");
            }
        }
    }

    printf("ллʹ�ü�����!\n");
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
            printf("���󣺳�������Ϊ0��\n");
            return num1;
        }
        return num1 / num2;
    case '^':
        return pow(num1, num2);
    default:
        printf("������Ч���������\n");
        return num1;
    }
}