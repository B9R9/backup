/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:42:38 by briffard          #+#    #+#             */
/*   Updated: 2022/02/22 14:55:48 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdio.h>

int	main(void)
{
	char	*name;
	char	*lastname;
	int		ret;
	float	pi = 3.14159235358979323846;
	double  pi2 = -3.14;

	name = "Joe";
	lastname = "Dassin";
	ret = ft_printf("My name is %s et mon nom de famille est %s.\nMy age is %d\n", name, lastname, 36);
	ft_printf("Le retour est = %d\n", ret);
	ft_printf("Essayons d impimer un char: %c\n", 'c');
	ft_printf("Display %%\n");
	ft_printf("Pi@ = %f\n", pi);
	printf("Pi = %f\n", pi);
	ft_printf("Pi2@ = %f\n",pi2);
	printf("Pi2 = %f\n",pi2);
	printf("Valeur du pointeur name %p\n", name);
	//ft_printf("@Valeur du pointeur name %p\n", name);
	printf("Valeur en hexadecimal = %x\n", 92);
	ft_printf("Valeur en hexadecimal = %x\n", 92);
	printf("Valeur en hexadecimal = %X\n", 92);
	//ft_printf("Valeur en hexadecimal = %X\n", 78913);


	return (EXIT_SUCCESS);
}

