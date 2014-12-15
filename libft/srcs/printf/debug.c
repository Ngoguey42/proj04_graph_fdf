/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:46:52 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/24 08:47:02 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

//debug.c
void	inspect_part(t_printf_part *part) //debug
{
	static int count = 0;
	count++;
	printf("[%02d ", count);

	
	printf("[");
    int i;
    for(i=8 * 1 - 1; i>=0; i--)
    {
		if (i / 8 < 1)
			printf("\033[35m"); fflush(stdout);
        ((part->flags) & (1 << i%8)) ? putchar('1') : putchar('0');
		printf("\033[39m"); fflush(stdout);
    }
	printf("]");
	
	printf("[");
    for(i=8 * 1 - 1; i>=0; i--)
    {
		if (i / 8 < 1)
			printf("\033[35m"); fflush(stdout);
        ((part->info) & (1 << i%8)) ? putchar('1') : putchar('0');
		printf("\033[39m"); fflush(stdout);
    }
	printf("] ");
	
	printf("wi.pr(%02d.%02d) ", part->width, part->precision);
	
	// printf("len:(%hu|", part->length);
	if (part->length > (int)ft_strlen(CHARS_LENGTH))
		printf("%c%c) ", CHARS_LENGTH[part->length - NUM_DBL_CHAR_LEN - 1], CHARS_LENGTH[part->length - NUM_DBL_CHAR_LEN - 1]);
	else if (part->length > 0)
		printf("%c ) ", CHARS_LENGTH[part->length - 1]);
	else 
		printf("  ) ");
		
		
	// printf("spe:(%2hu|", part->specifier);
	printf("%c) ", part->specifier ? CHARS_SPECIFIERS[part->specifier - 1] : ' ');
	
	char *repro;
	char *temp;
	temp = malloc(200);
	sprintf(temp, "%%"); repro = (char *)ft_strjoin("", temp);
	
	#define JOIN_REPRO repro = (char *)ft_strjoin(repro, temp);
//	{ sprintf(temp, ); JOIN_REPRO; }
	for(i = 0; i < 5; i++)
	{
		if (part->flags & (1 << i))
			{ sprintf(temp, "%c", CHARS_FLAGS[i]); JOIN_REPRO; }
	}
	
	if (part->info & WSTA_MASK)
		{ sprintf(temp, "*"); JOIN_REPRO; }
	else if (part->width)
		{ sprintf(temp, "%d", part->width); JOIN_REPRO; }

	if (part->info & PSTA_MASK)
		{ sprintf(temp, ".*"); JOIN_REPRO; }
	else if (part->precision)
		{ sprintf(temp, ".%d", part->precision); JOIN_REPRO; }
	if (part->length > (int)ft_strlen(CHARS_LENGTH))
		{ sprintf(temp, "%c%c", CHARS_LENGTH[part->length - NUM_DBL_CHAR_LEN - 1], CHARS_LENGTH[part->length - NUM_DBL_CHAR_LEN - 1]); JOIN_REPRO; }
	else if (part->length > 0)
		{ sprintf(temp, "%c", CHARS_LENGTH[part->length - 1]); JOIN_REPRO; }
	{ sprintf(temp, "%c", CHARS_SPECIFIERS[part->specifier - 1]); JOIN_REPRO; }
	repro = part->specifier ? repro : "";
	printf("%-15s ", repro); fflush(stdout);
	
	
	// printf("%2zu \033[36m|=>|\033[39m", part->str_size); fflush(stdout); ft_myputnchar((char*)part->str_ptr, part->str_size); printf("\033[36m&\033[39m");


	fflush(stdout); ft_myputnchar(part->nbr_ptr, (int)ft_strlen(part->nbr_ptr));
	
	
	
	printf("\033[36m]\n\033[39m");
	fflush(stdout);
	if (*repro) free(repro);
}

