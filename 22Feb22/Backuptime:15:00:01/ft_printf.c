#include "ftprintf.h"
#define hexa "0123456789abcdef"

char	*inttostr(int n)
{
	return (ft_itoa(n));
}
int		ft_printchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

char	*doubletostr(double n)
{
	char	*str;
	int 	x;
	int		i;
	   	
	i = 0;
	x = (int)n;
	str = ft_strjoin(ft_itoa(x),".");
	if(!str)
	{
		ft_memdel((void**)&str);
		exit(EXIT_FAILURE);
	}
	while (i < 6)
	{
		n = n - (double)x;
		n = n * 10;
		if (x < 0)
			str = ft_strjoin(str,ft_itoa(n * -1));
		else
			str = ft_strjoin(str,ft_itoa(n * 1));
		if(!str)
		{
			ft_memdel((void**)&str);
			exit(EXIT_FAILURE);
		}
		x = (int)n;
		i++;
	}
	return(str);
}

char	*decimaltohex(int c)
{
	//char	str[100];
	int ret;
	int modulo;

	ret = c;
	ret = ret / 16;
	modulo = ret % 16;
	printf ("RET = %d\n", ret);
	printf("MODULO = %d\n", modulo);
	return("In progress\n");
}

int	print_str(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		write(1, &str[index++], 1);
	return (index);
}

int		check_option(va_list ap, const char c)
{
	int	strlength;

	strlength = 0;
	if (c == 's')
		return (strlength += print_str(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (strlength += print_str(inttostr(va_arg(ap, int))));
	else if (c == 'c')
		return(strlength += ft_printchar(va_arg(ap, int)));
	else if (c == 'f')
		return(strlength += print_str(doubletostr(va_arg(ap, double))));
	else if (c == 'x')
		return (strlength += print_str(decimaltohex(va_arg(ap,int))));
	else if (c == '%')
		return (strlength += ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		length;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	length = 0;
	while( format[i] != '\0')
	{
		if (format[i] == '%')
		{
			length += check_option(ap, format[i + 1]);
			i++;
		}
		else
			length += ft_printchar(format[i]);
		i++;
	}
	va_end(ap);
	return (length);
}