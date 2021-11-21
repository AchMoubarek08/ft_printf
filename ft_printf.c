
#include "libftprintf.h"

int ft_printf(const char *s, ...)
{
    va_list n;
    va_start(n,s);
    int c;
    c = 0;
    while(*s)
    {
        if(*s == '%')
        {
            s++;
            if (*s == 'd' || *s == 'i')
                ft_putnbr_fd(va_arg(n,int), 1);
            else if (*s == 'c')
                ft_putchar_fd(va_arg(n,char), 1);
            else if (*s == 's')
                ft_putstr_fd(va_arg(n,char *), 1);
            else if (*s == 'u')
                ft_putnbr_fd(va_arg(n, int), 1);
            else
                ft_putchar_fd(*s,1);
            c++;
        }
        else
            ft_putchar_fd(*s,1);
        c++;
        s++;
    }
    return (c);
}
int main()
{
    printf(" %d\n", printf("achraf %%   %u c 88-000 %s\n%c\n%d\n",-10, "hhhhh", 'c', 900));
    printf("%d\n", ft_printf("achraf %%   %u c 88-000 %s\n%c\n%d\n",-10, "hhhhh", 'c', 900));
}