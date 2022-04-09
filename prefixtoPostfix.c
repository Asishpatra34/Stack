#include<stdio.h>
#include<conio.h>
#include<ctype.h>

char stack[50];
int top = -1;

void push(char);
char pop();
int priority(char);

void main()
{
    char exp[50];
    char *p, x;

    printf("Enter the expression: ");
    scanf("%s",exp);

    p = exp;

    // printf("%c\n\n",p);
    while (*p != '\0')
    {
        if (isalnum(*p))
        {
            printf("%c",*p);
        }

        else if (*p == '('){
            push(*p);
        }

        else if (*p == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
            
        }
        else
        {
            while (priority(stack[top]) >= priority(*p))
            {
                printf("%c",pop());
            }
        push(*p);
            
        }
        p++;    
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
    

}

void push(char x){
    top ++;
    stack[top] = x;
}

char pop(){
    int item;
    item = stack[top];
    stack[top] = '\0';
    top--;
    return item;
}

int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}