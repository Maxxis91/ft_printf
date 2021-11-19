/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:36:29 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/18 23:54:29 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
//	t_seq	*seq;
//	t_seq	*tmp;
	int				c;
	unsigned int	h;
	char			*r = "N";
	char			*f;
	char			*fmt;
   
	fmt = "";
		//"'%c'\n'%6c'\n'%-6c'\n";
	c = 97;
	h = 0;
    r = "Fuck";
	f = "'%6.3-4s'\n";
	printf("|%d\n", printf("%-10c %-10.4s %-+10.6d %-10.7x %10.7u %10.p", 0, NULL, 0, 0, 0, NULL));
	printf("\n");
	ft_printf("|%d\n", ft_printf("%-10c %-10.4s %-+10.6d %-10.7x %10.7u %10.p", 0, NULL, 0, 0, 0, NULL));
	printf("\n");
	printf("|%d\n", printf("%-10.c %-10.s %-+10.d %-10.x %10.u %10.p", 0, NULL, 0, 0, 0, NULL));
	printf("\n");
	ft_printf("|%d\n", ft_printf("%-10.c %-10.s %-+10.d %-10.x %10.u %10.p", 0, NULL, 0, 0, 0, NULL));
	printf("\n");
/*	ft_printf("x  : '%d'\n",h);
	ft_printf("6x : '%6d'\n",h);
	ft_printf("-6 : '%-6d'\n",h);
	ft_printf("06 : '%06d'\n",h);
	ft_printf(".x : '%.4d'\n",h);
	ft_printf("6. : '%6.d'\n",h);
	ft_printf("-6.: '%-6.d'\n",h);
	ft_printf("06.: '%06.d'\n",h);
	ft_printf(" x  : '% d'\n",h);
	ft_printf(" 6x : '% 6d'\n",h);
	ft_printf(" -6 : '% -6d'\n",h);
	ft_printf(" 06 : '% 06d'\n",h);
	ft_printf(" .x : '% .4d'\n",h);
	ft_printf(" 6. : '% 6.d'\n",h);
	ft_printf(" -6.: '% -6.d'\n",h);
	ft_printf(" 06.: '% 06.d'\n",h);
*/

	c = printf("%-5%%05%%-05%");
	printf("\n%d\n", c);
	c = ft_printf("%-5%%05%%-05%");
	printf("\n%d\n", c);
	printf("-->|%-16.p|<-- ", NULL);
	printf("\n");
	ft_printf("-->|%-16.p|<-- ", NULL);
/*	ft_printf("x  : '%X'\n",h);
	ft_printf("6x : '%5X'\n",h);
	ft_printf("-6 : '%-5X'\n",h);
	ft_printf("06 : '%05X'\n",h);
	ft_printf(".x : '%.3X'\n",h);
	ft_printf("6. : '%6.3X'\n",h);
	ft_printf("-6.: '%-6.3X'\n",h);
	ft_printf("06.: '%06.3X'\n",h);
	ft_printf("#x  : '%#X'\n",h);
	ft_printf("#6x : '%#6X'\n",h);
	ft_printf("#-6 : '%#-6X'\n",h);
	ft_printf("#06 : '%#06X'\n",h);
	ft_printf("#.x : '%#.3X'\n",h);
	ft_printf("#6. : '%#6.3X'\n",h);
	ft_printf("#-6.: '%#-6.3X'\n",h);
	ft_printf("#06.: '%#06.3X'\n",h);
	ft_printf("#.x : '%#.5X'\n",h);
	ft_printf("#6. : '%#6.5X'\n",h);
	ft_printf("#-6.: '%#-6.5X'\n",h);
	ft_printf("#06.: '%#06.5X'\n",h);
	int c1 = printf("% .d",h);
//	printf("\ncount: %d\n", c1);
//	printf(" : '%.x'\n",h);
//	printf("+: '%+x'\n",h);
//	printf("p: '%#010x'\n",h);


	seq = ft_q_set("%%%5%%-5%%05%%-05%");
	tmp = seq;
	while (tmp)
	{
		printf("Flags: '#': '%c'; ", tmp->flags->x);
		printf("'0': '%c'; ' ': '%c'; ", tmp->flags->zpad, tmp->flags->bpos);
		printf("'-': '%c'; '+': '%c';\n", tmp->flags->ladj, tmp->flags->sign);
		printf("Width: %zu; Precision: %ld; ", tmp->width, tmp->prcsn);
		printf("Conversion: '%c'; Data: '%s'\n", tmp->tconv, tmp->data);
		tmp = tmp->next;
	}	
	printf("----------------------------\n\n");
	size_t c2 = ft_q_print(seq);
	printf("count: %zu\n", c2);
	ft_seq_clear(&seq);
printf("\n\n");
ft_printf("%%%5%%-5%%05%%-05%");
printf("\n\n");
*/

//	while (1)
		;
	return (0);
}
