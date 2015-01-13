/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 10:13:15 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/27 10:35:23 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "ft_printf.h"
#include "libft.h"

/* int		ft_vsprintf(char *str, const char *format, va_list args)  */
/* { */
/* 	//attention à pas segfault sur les types que je vais pas gerer */
/* 	int		len; */
/* 	char	**ret; */

/* 	ret = malloc(sizeof(char*)); */
/* 	if (!ret) */
/* 	{ */
/* 		str = NULL; */
/* 		return (-1); */
/* 	} */
/* 	len = ft_getprintf(ret, format, &args); */
/* 	ft_memcpy(str, *ret, len + 1); */
/* 	free(ret); */
/* 	return (len); */
/* } */

/* int		ft_sprintf(char *str, const char *format, ...) */
/* { */
/* 	va_list		ap; */
/* 	int			ret; */

/* 	va_start(ap, format); */
/* 	ret = ft_vsprintf(str, format, ap); */
/* 	va_end(ap); */
/* 	return (ret); */
/* } */


/* int		ft_vprintf(const char *format, va_list arg) */
/* { */
/* 	int		len; */
/* 	char	**ret; */

/* 	ret = malloc(sizeof(char*)); */
/* 	if (!ret) */
/* 		return (-1); */
/* 	len = ft_getprintf(ret, format, &arg); */
/* 	ft_putstr(*ret); */
/* 	free(ret); */
/* 	return (len); */
/* } */

/* int		ft_printf(const char *format, ...) */
/* { */
/* 	va_list		ap; */
/* 	int			ret; */

/* 	va_start(ap, format); */
/* 	ret = ft_vprintf(format, ap); */
/* 	va_end(ap); */
/* 	return (ret); */
/* } */


// void showbits(byte_pointer x, int bytes, int real_bytes)
// {
    // int i;
    // for(i=8 * bytes - 1; i>=0; i--)
    // {
		// if (i / 8 < real_bytes)
			// printf("\033[35m"); fflush(stdout);
        // (x[i/8] & (1 << i%8)) ? putchar('1') : putchar('0');
		// !(i%8)? putchar(' ') : (int)i;
		// printf("\033[39m"); fflush(stdout);
    // }
	// printf("\n");
// }


void showbits(t_byte *x, int bits, int highlightmin, int highlightmax)
{
    int i;
    for(i= bits - 1; i >= 0; i--)
    {
		if (i <= highlightmax && i >= highlightmin)
			printf("\033[35m"); fflush(stdout);
        (x[i/8] & (1 << i%8)) ? putchar('1') : putchar('0');
		!(i%8)? putchar(' ') : (int)i;
		printf("\033[39m"); fflush(stdout);
    }
	printf("\n");
}


void	do_my_tests(void);


//main.c
int	main(void)
{
	
	do_my_tests();
	return (0);
}


size_t strlen_doublezero(char *str)
{
	size_t	len = 0;

	gotola:
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str++;
	if (*str != '\0')
	{
		len++;
		goto gotola;
	}
	return (len);
}


#define NEW_SPECIFIERS ((char*)ft_strjoin(LENG, SPEC))
// // "jztLhl"
#define LENG ""
/* #define LENG "j" */
/* #define LENG "z" */
/* #define LENG "t" */
/* #define LENG "L" */
/* #define LENG "h" */
/* #define LENG "l" */
/* #define LENG "hh" */
/* #define LENG "ll" */


// // // // // //dDioOuUxX
/* #define SPEC "i"  // 100% */
/* #define SPEC "d"  // 100% */
/* #define SPEC "D"  // 100% */
/* #define SPEC "u"  // 100% */
/* #define SPEC "U"  // 100% */
/* #define SPEC "o"  // 100% */
/* #define SPEC "O"  // 100% */
/* #define SPEC "x"  // 100% */
/* #define SPEC "X"  // 100% */

// // // // // //d%
/* #define SPEC "p"  // 100% */
/* #define SPEC "%"  // 100% */


// // // // // //sScC
/* #define SPEC "s"  // %ls +faire meilleurs tests */
/* #define SPEC "S"  // */
/* #define SPEC "c"  // %lc +faire meilleurs tests */
/* #define SPEC "C"  // */


/* #define SPEC "a"  // %LA +approfondir tests */
/* #define SPEC "A"  // %LA +approfondir tests */

#define SPEC "f"  // undone
// #define SPEC "F"  // undone
// #define SPEC "e"  // undone
// #define SPEC "E"  // undone
// #define SPEC "g"  // undone
// #define SPEC "G"  // undone

// #define SPEC "n"  // undone


#define BONUS_TESTS 0
#define MALLOC_SIZE 50000

#if BONUS_TESTS == 0// DONT TOUCH

#define FLOAT_NUMBERS 1
#define FLOAT_TO_TEST 1 //1->6	1:(250 norm randoms)  2:(250 unnorm randoms)  3:(fixes et 30 random nan)  
//								4:(nan bornes et delta 33)  5:(norm bornes et delta 33)  6:(unnorm bornes et delta 33)
//								7:(norm randoms via %f)	8:(norm randoms via %a)  9:(norm randoms via %e) 
//								10: un peu de tout, efficace


#define HIDE_ALL_RESULTS 0
#define MAX_BAD_TO_WRITE 200

#define HIDE_GOOD_RESULTS 0
#define MAX_GOOD_TO_WRITE 50

#define NEW_STRLEN 50

#define MAX_CHARS_PER_LINE 135
#define BONUS_CHARS_PER_LINE 5000
# define CHARS_FLAGS_BIS "-+ #0"

#define DELIMITER (USHRT_MAX / 3)
#define NULLIFIER (USHRT_MAX / 5)

#if FLOAT_NUMBERS == 1 //DONT TOUCH BORDEL
#define NUM_TYPE double
#define READER_FMT "%a|"
#else
#define NUM_TYPE uint64_t
#define READER_FMT "%llX|"
#endif



NUM_TYPE	*numbers;
int			*widths;
int			*precisions;
char		**flags;

int		line_status;
char	*line1;
char	*line2;
char	*line3;
unsigned int failed;
unsigned int passed;
unsigned int	*nbrs_results;
unsigned int	*width_results;
unsigned int	*preci_results;
unsigned int	*flags_results;
unsigned int	*singleflags_results;
int		wid;
int		pre;
int		nbr;
int		fla;
int		writing_status;


void	flush_lines(int status)
{
	if ((int)ft_strlen(line1) == 0)
		return ;
	else if (writing_status != 0)
		ft_putstr("\n");
	ft_putstr(line1); ft_putstr("\n");
	ft_putstr(line2); ft_putstr("\n");
	ft_putstr(line3); ft_putstr("\n");

	ft_memset(line1, 0, MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1);
	ft_memset(line2, 0, MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1);
	ft_memset(line3, 0, MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1);
	
	if (status == 1) // au milieu des tests
	{
		// #define LINE_INITIER1 "      "
		ft_strcpy(line1, "FMT ");
		ft_strcpy(line2, "REF ");
		ft_strcpy(line3, "CUS ");
		
		line_status = (int)ft_strlen(line1);
	}
	writing_status = 0;
}


char *starter = " [";
char *ender = "] ";
char *filler = "__________________________________________________________________________________________________________________________________________________________________________________________________________________";

void	write_in_lines(char* l1, char* l2, char* l3, int type, int deltal3)
{
	char	*temp = malloc(MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1);
	
	int l1len = (int)ft_strlen(l1);
	int l2len = (int)ft_strlen(l2);
	int l3len = (int)ft_strlen(l3);
	
	int totlen = l1len >= l2len ? l1len : l2len;
	totlen = totlen >= l3len ? totlen : l3len;
	
	// if (type == 1 && ft_strcmp(l2, l3))
		// ft_strcat(line3, "\033[31m");
	// else
		// ft_strcat(line3, "\033[32m");
	if (ft_strcmp(l3, l2)) //true
	{
		l3 = (char*)ft_strjoin("\033[31m", l3);
		l3 = (char*)ft_strjoin(l3, "\033[39m");
	}
	else
	{
		l3 = (char*)ft_strjoin("\033[32m", l3);
		l3 = (char*)ft_strjoin(l3, "\033[39m");
	}
	if (type == 1)
	{
		ft_strcat(line1, starter);
		ft_strcat(line2, starter);
		ft_strcat(line3, starter);
	}

	ft_strcat(line1, l1);
	ft_strcat(line2, l2);
	ft_strcat(line3, l3);
	
	if (totlen > l1len) {ft_memset(temp, 0, MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1); ft_memset(temp, '_', totlen - l1len); ft_strcat(line1, temp);}
	if (totlen > l2len) {ft_memset(temp, 0, MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1); ft_memset(temp, '_', totlen - l2len); ft_strcat(line2, temp);}
	if (totlen > l3len) {ft_memset(temp, 0, MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1); ft_memset(temp, '_', totlen - l3len); ft_strcat(line3, temp);}

	
	if (type == 1)
	{
		ft_strcat(line1, ender);
		ft_strcat(line2, ender);
		ft_strcat(line3, ender);
	}
	
	// ft_strcat(line2, "\033[39m");
	// ft_strcat(line3, "\033[39m");
	free(temp);
}


int		nbr_len(int nbr)
{
	if (nbr < 0)
		return (1 + nbr_len(-nbr));
	else if (nbr >= 10)
		return (1 + nbr_len(nbr / 10));
	else
		return (1);
}

int		ftnbr_stars(char *str)
{
	int count = 0;
	int temp = 0;
	while (*str)
	{
		if (*str == '*' && !temp)
			count = 1;
		else if (*str == '*' && temp)
		{
			count = count + 2;
			return (count);
		}
		else if (*str == '.')
			temp = 1;
		str++;
	}
	return (count);
}


char	*create_format(char* format, int width, int precision)
{
	int len = (int)ft_strlen(format);
	int nbr_stars = ftnbr_stars(format);
	
	if (nbr_stars == 1 || nbr_stars == 3)
		len += nbr_len(width) - 1;
	if (nbr_stars == 2 || nbr_stars == 3)
		len += nbr_len(precision) - 1;
		
	char *str = malloc(len + 1);
	ft_memset(str, 0, len + 1);
	int i = 0;
	char *temp;

	while(*format)
	{
		if (*format == '*')
		{
			if (nbr_stars == 1 || nbr_stars == 3)
			{
				temp = malloc(25);
				sprintf(temp, "%d", width);
				ft_strcat(str, temp);
				free(temp);
				nbr_stars--;
			}
			else if (nbr_stars == 2)
			{
				temp = malloc(25);
				sprintf(temp, "%d", precision);
				ft_strcat(str, temp);
				free(temp);
			}
		}
		else
			str[(int)ft_strlen(str)] = *format;
		format++;
	}
	return (str);
}


char	*make_readable(char* str, int len)
{
	char *ret = malloc(len * 3 + 1);
	ft_memset(ret, 0, len * 3 + 1);
	char *save;
	save = ret;
	char *temp;
	
	while(len)
	{
		if (ft_isprint(*str))
			*(ret++) = *(str++);
		else
		{
			*(ret++) = '\\';
			temp = malloc(25);
			sprintf(temp, "%hhd", *str);
			ft_strcpy(ret, temp);
			ret += (int)ft_strlen(temp);
			str += (int)ft_strlen(temp);
			free(temp);
		}
		len--;
	}
	*ret = '\0';
	return (save);
}

void	save_results(char* format, char* refstr, char* cusstr, int reflen, int cuslen, int width, int precision)
{
	static unsigned int countbad = 0;
	static unsigned int countgood = 0;
	if (!memcmp(refstr, cusstr, reflen))
	{
		passed++;
		if (HIDE_GOOD_RESULTS || HIDE_ALL_RESULTS || (countgood) > MAX_GOOD_TO_WRITE)
			return ;
		countgood++;
	}
	else
	{
		
		nbrs_results[nbr]++;
		width_results[wid]++;
		preci_results[pre]++;
		flags_results[fla]++;
		failed++;
			//"-+ #0"
		if (ft_strcharlen(flags[fla], '-') < ft_strlen(flags[fla]))
			singleflags_results[0]++;
		if (ft_strcharlen(flags[fla], '+') < ft_strlen(flags[fla]))
			singleflags_results[1]++;
		if (ft_strcharlen(flags[fla], ' ') < ft_strlen(flags[fla]))
			singleflags_results[2]++;
		if (ft_strcharlen(flags[fla], '#') < ft_strlen(flags[fla]))
			singleflags_results[3]++;
		if (ft_strcharlen(flags[fla], '0') < ft_strlen(flags[fla]))
			singleflags_results[4]++;
		if (HIDE_ALL_RESULTS || (countbad) > MAX_BAD_TO_WRITE)
			return ;
		countbad++;
	}
		//mettre format au propre avec width et precision, si besoin
		format = create_format(format, width, precision);
		//rendre readable les 2 autre strings
		refstr = make_readable(refstr, reflen);
		cusstr = make_readable(cusstr, cuslen);
		//call l'ecriture, et fflush avant si besoin
		int totlen;
		totlen = (int)ft_strlen(format) >= (int)ft_strlen(refstr) ? (int)ft_strlen(format) : (int)ft_strlen(refstr);
		totlen = totlen >= (int)ft_strlen(cusstr) ? totlen : (int)ft_strlen(cusstr);
		totlen += 4;
		if ((int)ft_strlen(line1) + totlen > MAX_CHARS_PER_LINE)
			flush_lines(1);
		// printf("(%d) ", !ft_strcmp(refstr, cusstr));

		
		write_in_lines(format, refstr, cusstr, 1, 1);
		free(format);
		free(refstr);
		free(cusstr);
}

double	generate_float(int negative, int exposant, uint64_t mantissa)
{
	printf("neg(%d)exp(%d)man(%llu/%llx)     ", negative, exposant, mantissa, mantissa);
	double *ptr2;
	ptr2 = malloc(8);
	char *ptr;
	ptr = (char*)ptr2;
	int i;
	int last_bit;
	char *test;
	test = (unsigned char*)&mantissa;
	for (i = 0; i < 64; i++)
	{
		if (test[i/8] & (1 << i % 8))
			last_bit = i;
	}
	i = 0;
	for (i = last_bit - 1; i >= 0; i--)
	{
		if (test[(last_bit - 1 - i) / 8] & (1 << ((last_bit - 1 - i) % 8)))
			ptr[(51 - i) / 8] = ptr[(51 - i) / 8] | (1 << ((51 - i) % 8));
		
	}
	// showbits(ptr, 8, 8); printf("\n");
	
	//ecriture exposant
	exposant += 1023;
	
	// showbits((unsigned char*)&exposant, 4, 4); printf("\n");
	
	for (i = 0; i < 11; i++)
	{
		if (((char*)&exposant)[i/8] & (1 << (i % 8)))
			ptr[(i+52)/8] = ptr[(i+52)/8] | (1 << ((i+52)%8));
	}
	// showbits(ptr, 8, 8); printf("\n");
	
	if (negative)
		// test[64/8 - 1] = test[64/8  - 1] | (1 << 7);
		ptr[7] = ptr[7] | (1 << 7);
	// showbits(ptr, 8, 8); printf("\n");
	// showbits((unsigned char*)ptr2, 8, 8); printf("\n");
	// return((double)*ptr);
	// printf("(%f) (%e) (%d)\n", *ptr, *ptr, *ptr);
	printf(" a(%a)     f(%f) e(%e) g(%g) llu(%llu)\n", *ptr2, *ptr2, *ptr2, *ptr2, *ptr2);
	return(*ptr2);
}

double	do_double(uint64_t nbr)
{
	double ret;
	double *ptr2;
	// ptr2 = malloc(8);
	// ret = +0.0;
	ptr2 = &ret;
	ft_memset(ptr2, 0, 8);
	unsigned char *ptr;
	ptr = (unsigned char*)ptr2;
	
	unsigned char *srcptr;

	srcptr = (unsigned char*)&nbr;
	
	int i;
	// for (i = 0; i < 8; i++)
	// {
		// ptr[i] = srcptr[i];
	// }
	for (i = 0; i < 64; i++)
	{
		if (srcptr[i/8] & (1 << (i%8)))
			ptr[i/8] = ptr[i/8] | (1 << (i%8));
		// if (i == 51)
		// {
			// if (srcptr[i/8] & (1 << (i%8)))
				// printf("(1)");
			// else
				// printf("(0)");
			// if (ptr[i/8] & (1 << (i%8)))
				// printf("(1)");
			// else
				// printf("(0)");
		// }
	}
	// printf("[0x%016llX]", nbr); showbits((unsigned char*)&nbr, 8, 8);
	// printf("[0x%016llX]", *ptr2); showbits((unsigned char*)ptr2, 8, 8);
	// 
	// ;
	return (ret);
}

char	*build_cur_format(char *flags, int has_wid, int has_pre, char *specifiers)
{
	char *ret;
	ret = "%";
	
	ret = (char*)ft_strjoin(ret, flags);
	if (has_wid)
		ret = (char*)ft_strjoin(ret, "*");
	if (has_pre)
		ret = (char*)ft_strjoin(ret, ".*");
	ret = (char*)ft_strjoin(ret, specifiers);
	
	return (ret);
}

void	do_my_tests(void)
{

// double dbl = generate_float(0, 11, 0b1100010001011);
// double dbl = generate_float(0, 0, 0b10 0010 0010 0011);
// printf("(%f) (%e) (%a)\n", dbl, dbl, dbl);
// showbits((unsigned char*)&dbl, 8, 8); printf("\n");


// exit(0);
numbers = malloc(sizeof(NUM_TYPE) * MALLOC_SIZE);
widths = malloc(sizeof(int) * MALLOC_SIZE);
precisions = malloc(sizeof(int) * MALLOC_SIZE);
flags = malloc(32 * sizeof(char*));


nbrs_results = malloc(sizeof(unsigned int) * MALLOC_SIZE);
width_results = malloc(sizeof(unsigned int) * MALLOC_SIZE);
preci_results = malloc(sizeof(unsigned int) * MALLOC_SIZE);
flags_results = malloc(sizeof(unsigned int) * MALLOC_SIZE);
singleflags_results = malloc(sizeof(unsigned int) * 5);

int 	i;
do
{
	for (i = 0; i < MALLOC_SIZE ; i++)
	{
		precisions[i] = DELIMITER;
		widths[i] = DELIMITER;
		numbers[i] = DELIMITER;
		nbrs_results[i] = 0;
		width_results[i] = 0;
		preci_results[i] = 0;
		flags_results[i] = 0;
		singleflags_results[i] = 0;
	}
	
#if FLOAT_NUMBERS == 1

	i = 0;
#define ADD_NBR_BITS(NBR) numbers[i] = do_double(NBR);\
printf("%-3d", i);\
printf("(%d)", ft_dbltype(numbers[i]));\
printf("[0x%016llX|", numbers[i]);\
printf("0x%016llX]", NBR);\
printf("[%+25a|", numbers[i]);\
printf("%-+25a]", NBR);\
showbits((unsigned char*)&numbers[i], 64, 52, 62);\
i++;\
fflush(stdout)


#define ADD_NBR_DECI(NBR) numbers[i] = NBR;\
printf("%-3d", i);\
printf("(%d)", ft_dbltype(numbers[i]));\
printf("[%016llF|", numbers[i]);\
printf("%016llF]", NBR);\
printf("[%+25a|", numbers[i]);\
printf("%-+25a]", NBR);\
showbits((unsigned char*)&numbers[i], 64, 52, 62);\
i++;\
fflush(stdout)




#if FLOAT_TO_TEST == 1
// 200 normalises  random
ADD_NBR_BITS(0XF16B737306B4856E);
ADD_NBR_BITS(0X44932B2520A25A33);
ADD_NBR_BITS(0X1E49D252F1C3FD35);
ADD_NBR_BITS(0X94DB7D70B140B162);
ADD_NBR_BITS(0X5ABC87B9189A13AC);
ADD_NBR_BITS(0X6E6B91D58E77242D);
ADD_NBR_BITS(0X25CD86564041D039);
ADD_NBR_BITS(0X81D4C4E48B931124);
ADD_NBR_BITS(0XED31C28E158D1918);
ADD_NBR_BITS(0X3C9ACB87A2EADDF9);
ADD_NBR_BITS(0X9ADCDF802B17CBED);
ADD_NBR_BITS(0XF39308E9C8A2EB00);
ADD_NBR_BITS(0X4FB0FA8B6C256E2B);
ADD_NBR_BITS(0X8B30071AF3FA387F);
ADD_NBR_BITS(0X526A77BC6B5EBBC0);
ADD_NBR_BITS(0X63E7C429A548A4C4);
ADD_NBR_BITS(0X274A2896EF4F171C);
ADD_NBR_BITS(0XD88F62951A47C219);
ADD_NBR_BITS(0X8DAB305462A8E28C);
ADD_NBR_BITS(0X3057A426BC8312A5);
ADD_NBR_BITS(0X4C3796045E5843B1);
ADD_NBR_BITS(0X6594E9D905F95866);
ADD_NBR_BITS(0XA4D735DF4957D9E7);
ADD_NBR_BITS(0X38E08F3F181B8C4B);
ADD_NBR_BITS(0X4D3A2EB78BA23F46);
ADD_NBR_BITS(0X5BDEA1322243EC91);
ADD_NBR_BITS(0X9753E175E24FC9AD);
ADD_NBR_BITS(0X1059F181CFDBBF2C);
ADD_NBR_BITS(0XA61FB7E9BC5C2721);
ADD_NBR_BITS(0XF128EA470E0E5D85);
ADD_NBR_BITS(0X3F919B64700BA955);
ADD_NBR_BITS(0X089C7E565A90A0AB);
ADD_NBR_BITS(0XA8CE67F3D1BC5129);
ADD_NBR_BITS(0XD137D39D8E227580);
ADD_NBR_BITS(0X2F95A6F1115F672F);
ADD_NBR_BITS(0XC8AE181BE857EC01);
ADD_NBR_BITS(0XA3C58A093F93E921);
ADD_NBR_BITS(0XF15CE7461C460264);
ADD_NBR_BITS(0XB8BA2C3C97DFF656);
ADD_NBR_BITS(0XD3694BC359B8AB30);
ADD_NBR_BITS(0XAAA577A717FF755F);
ADD_NBR_BITS(0X319DE62567789C02);
ADD_NBR_BITS(0X82AAE2D1C5D4199B);
ADD_NBR_BITS(0X5B57BC0DBBCE4D50);
ADD_NBR_BITS(0X99D00896F31AF6C8);
ADD_NBR_BITS(0X08561BD591726611);
ADD_NBR_BITS(0X2F78E810229DC446);
ADD_NBR_BITS(0X93BC78DE82BAE924);
ADD_NBR_BITS(0X6A8CEA8EFE63A127);
ADD_NBR_BITS(0XE5338767D7F889BF);
ADD_NBR_BITS(0X3226EC396ED82B4E);
/* ADD_NBR_BITS(0X652122AE975C0B7F); */
/* ADD_NBR_BITS(0XDB49D79654253B7C); */
/* ADD_NBR_BITS(0X972993A7744AF27E); */
/* ADD_NBR_BITS(0XC27DD8928B7B98EE); */
/* ADD_NBR_BITS(0XCDCD8BE98A39F76B); */
/* ADD_NBR_BITS(0XA447BAB01A0D40AF); */
/* ADD_NBR_BITS(0X5763AC6ADF55140B); */
/* ADD_NBR_BITS(0X3FEF8025DB7AD4F9); */
/* ADD_NBR_BITS(0XD51A651C6DE80C04); */
/* ADD_NBR_BITS(0XFF76C6253A5C92D0); */
/* ADD_NBR_BITS(0X33951E3D3AA699FA); */
/* ADD_NBR_BITS(0X05283AF80EE00FD3); */
/* ADD_NBR_BITS(0XD44C05771F4A3AF5); */
/* ADD_NBR_BITS(0XD030436D0063C4D0); */
/* ADD_NBR_BITS(0XD8E4D964B3FA3A4F); */
/* ADD_NBR_BITS(0X7BEF47CA85A096A0); */
/* ADD_NBR_BITS(0XB1177C9F4CC72D96); */
/* ADD_NBR_BITS(0XFA2B706A55BE0BBD); */
/* ADD_NBR_BITS(0X7F6D7F14F7CCC3DF); */
/* ADD_NBR_BITS(0XE2B8FFB756B6B8D0); */
/* ADD_NBR_BITS(0XAA8CAF09521F7AE8); */
/* ADD_NBR_BITS(0XF386A25DEB1D9FE2); */
/* ADD_NBR_BITS(0XCBC6CCD37837CD4F); */
/* ADD_NBR_BITS(0X6B8DD0E89031B9FC); */
/* ADD_NBR_BITS(0X33182630E8851343); */
/* ADD_NBR_BITS(0X07D9126D418F9FC6); */
/* ADD_NBR_BITS(0X5E36D936C7A2A1BC); */
/* ADD_NBR_BITS(0XCBA303DD345A347B); */
/* ADD_NBR_BITS(0X74B0468F27B7BA1A); */
/* ADD_NBR_BITS(0X282D0D2C98C891B9); */
/* ADD_NBR_BITS(0X6C9C921ABD15BAD3); */
/* ADD_NBR_BITS(0X9C4BCB110478BFE2); */
/* ADD_NBR_BITS(0X1AEB835B0422CC87); */
/* ADD_NBR_BITS(0X2383ADDC4AE7204D); */
/* ADD_NBR_BITS(0X1A5FAE45DBBF6EC4); */
/* ADD_NBR_BITS(0X15B717D12189CAA4); */
/* ADD_NBR_BITS(0XA57F9EADB30640FC); */
/* ADD_NBR_BITS(0X4D38DED09F4BAE7A); */
/* ADD_NBR_BITS(0XF7E0983C9A5C93C7); */
/* ADD_NBR_BITS(0XD6DBD22001789227); */
/* ADD_NBR_BITS(0X954995C1987098D0); */
/* ADD_NBR_BITS(0XDF321134DB4E749C); */
/* ADD_NBR_BITS(0XBA1BF428FD1AED77); */
/* ADD_NBR_BITS(0X91EF161248DEEF1B); */
/* ADD_NBR_BITS(0X5F6665E6C683FC6A); */
/* ADD_NBR_BITS(0XE62B584E615E9ECE); */
/* ADD_NBR_BITS(0X0B201750A9BFF087); */
/* ADD_NBR_BITS(0X0E7B9DCB2F95362C); */
/* ADD_NBR_BITS(0X6A379C5999FC4B80); */
/* ADD_NBR_BITS(0XF892F79A1D291362); */
/* ADD_NBR_BITS(0X0688A0AF32CF5483); */
/* ADD_NBR_BITS(0X8AA83F6DFDA92F8B); */
/* ADD_NBR_BITS(0XC09EEC6CAC636571); */
/* ADD_NBR_BITS(0X69BCB251104429D3); */
/* ADD_NBR_BITS(0XF65949FE481243A6); */
/* ADD_NBR_BITS(0X4F3E7600BD32739E); */
/* ADD_NBR_BITS(0XB031B5F5E64C5FE0); */
/* ADD_NBR_BITS(0X48374CC967B05AD7); */
/* ADD_NBR_BITS(0XE575FED330734FCE); */
/* ADD_NBR_BITS(0X89EF765A4E3EA346); */
/* ADD_NBR_BITS(0X6E480CA4BFAF227D); */
/* ADD_NBR_BITS(0XE0E3F62F0AE22880); */
/* ADD_NBR_BITS(0X6A4B59E5A1CF3491); */
/* ADD_NBR_BITS(0X4D4C8C3CDD869E80); */
/* ADD_NBR_BITS(0X30A5C3CC50391C9C); */
/* ADD_NBR_BITS(0XC15432F500874448); */
/* ADD_NBR_BITS(0X665A4B23EF4B1C1F); */
/* ADD_NBR_BITS(0XDFB3C5AF319D2367); */
/* ADD_NBR_BITS(0X5E366839CFF5C9D1); */
/* ADD_NBR_BITS(0XBD83821A40F07C8A); */
/* ADD_NBR_BITS(0X905DA67CC3D6B215); */
/* ADD_NBR_BITS(0X8387938F0C8708D6); */
/* ADD_NBR_BITS(0X2968E5A39AD4B866); */
/* ADD_NBR_BITS(0X201A2433B9B508DE); */
/* ADD_NBR_BITS(0X6B396F41F78D427F); */
/* ADD_NBR_BITS(0XA421E4E7B73DB96B); */
/* ADD_NBR_BITS(0X7A8EC1C978F4F99B); */
/* ADD_NBR_BITS(0XFFA9C064E085B30A); */
/* ADD_NBR_BITS(0X0737C19A55FE9CDC); */
/* ADD_NBR_BITS(0X0D1C48E9472BAD33); */
/* ADD_NBR_BITS(0X251A213E5ABEC0A9); */
/* ADD_NBR_BITS(0X7B5E75FC7B14BD89); */
/* ADD_NBR_BITS(0X5CDE38F9D1FB559B); */
/* ADD_NBR_BITS(0XECCBE57CB92FE49B); */
/* ADD_NBR_BITS(0XC232E85FBA993DDB); */
/* ADD_NBR_BITS(0X8AED19771CD443F1); */
/* ADD_NBR_BITS(0XF31DE2802BAA3514); */
/* ADD_NBR_BITS(0X03EDA4DCBF71B760); */
/* ADD_NBR_BITS(0XA9B4061BBB1DA7B7); */
/* ADD_NBR_BITS(0XE74B00BFA5BBD5DA); */
/* ADD_NBR_BITS(0X50912B2A892A1858); */
/* ADD_NBR_BITS(0X3B3927CDC668BC92); */
/* ADD_NBR_BITS(0XA6E91BA892E32864); */
/* ADD_NBR_BITS(0X90344E839F89D2F4); */
/* ADD_NBR_BITS(0XBE91DC27474D137D); */
/* ADD_NBR_BITS(0X809A9DBEA42B1C48); */
/* ADD_NBR_BITS(0X6E44A94F2B99626B); */
/* ADD_NBR_BITS(0X642696B4582A0FB0); */
/* ADD_NBR_BITS(0XC2115487048EAC98); */
/* ADD_NBR_BITS(0X1F85AA76CFB5E2C9); */
/* ADD_NBR_BITS(0X3187C90CD4CF1E67); */
/* ADD_NBR_BITS(0X3DC8BE1520D4C96E); */
/* ADD_NBR_BITS(0XDB8A5BD302E64B1A); */
/* ADD_NBR_BITS(0XA8693A46C136A971); */
/* ADD_NBR_BITS(0X945402AD2CD9F10E); */
/* ADD_NBR_BITS(0XE724898650FBA920); */
/* ADD_NBR_BITS(0X3FCD4D099D2333F4); */
/* ADD_NBR_BITS(0X17446E46AA9AB349); */
/* ADD_NBR_BITS(0XDD261E3D79065FDD); */
/* ADD_NBR_BITS(0XDCC290EC459EAB92); */
/* ADD_NBR_BITS(0XAE4BE2ABAA027312); */
/* ADD_NBR_BITS(0XC6A5CA06D1BA5112); */
/* ADD_NBR_BITS(0X90A77CEFF530A557); */
/* ADD_NBR_BITS(0XAADD912176A75F6B); */
/* ADD_NBR_BITS(0X3AB6DA6F830B4473); */
/* ADD_NBR_BITS(0XB1A16751CC64B57A); */
/* ADD_NBR_BITS(0X26D1A565DFC2DDAF); */
/* ADD_NBR_BITS(0X6419E82BA9EA425E); */
/* ADD_NBR_BITS(0X6843BDE556B12DC6); */
/* ADD_NBR_BITS(0X48477D8FCD380FA1); */
/* ADD_NBR_BITS(0XFEC274EA9669FF24); */
/* ADD_NBR_BITS(0X5E6092E4FE7F4EB5); */
/* ADD_NBR_BITS(0XFB2F03A3B0332E58); */
/* ADD_NBR_BITS(0XDE2FDDF90BDC6477); */
/* ADD_NBR_BITS(0XC848A0C3EB3AF9F3); */
/* ADD_NBR_BITS(0X1851C0ACF1ED9F67); */
/* ADD_NBR_BITS(0X92E68B65ED927EDE); */
/* ADD_NBR_BITS(0X8321398EE6A073EF); */
/* ADD_NBR_BITS(0XC33441BC021CB8EB); */
/* ADD_NBR_BITS(0X09AA993C459ACA0F); */
/* ADD_NBR_BITS(0XB9C5C2DBF6E89E93); */
/* ADD_NBR_BITS(0X04556FFD6FAA6F1F); */
/* ADD_NBR_BITS(0XA8E7C0E803B614AB); */
/* ADD_NBR_BITS(0X1BA5D72AE10E2EF7); */
/* ADD_NBR_BITS(0XF0ED15930E8BF28C); */
/* ADD_NBR_BITS(0X1989EE2A53FF5D5F); */
/* ADD_NBR_BITS(0X8E4F69F3E043386C); */
/* ADD_NBR_BITS(0X209D57DE5CBCC978); */
/* ADD_NBR_BITS(0X7FBD87E9E165133D); */
/* ADD_NBR_BITS(0XA41A0D09A64053A4); */
/* ADD_NBR_BITS(0XADA69ACA83DB9C35); */
/* ADD_NBR_BITS(0X27837AF5A3FCDF4B); */
/* ADD_NBR_BITS(0X7AA91379A05AF838); */
/* ADD_NBR_BITS(0X672846667992B118); */
/* ADD_NBR_BITS(0XDC2393FB52F0D23A); */
/* ADD_NBR_BITS(0X258270A345F62F86); */
/* ADD_NBR_BITS(0X5C2DE96B9CA4DB4A); */
/* ADD_NBR_BITS(0XE943E5B1C4B443BB); */
/* ADD_NBR_BITS(0X41BA744A318FE2B4); */
#elif FLOAT_TO_TEST == 2
// 200 denormalises  random
// ADD_NBR_BITS(0X80034721B99413DF);
// ADD_NBR_BITS(0X0007E8E58FBC89D5);
// ADD_NBR_BITS(0X80046C80BF0F0B43);
// ADD_NBR_BITS(0X8008447D49431174);
// ADD_NBR_BITS(0X800B826E9DA7B33B);
// ADD_NBR_BITS(0X800E8460A8E02E7B);
// ADD_NBR_BITS(0X800529B3CE6BB0D4);
// ADD_NBR_BITS(0X0003E441DABA7C49);
// ADD_NBR_BITS(0X0002695D1DB7CB96);
// ADD_NBR_BITS(0X800268BBFFE0A5EB);
// ADD_NBR_BITS(0X00075151F3B8020A);
// ADD_NBR_BITS(0X80044107DAA43441);
// ADD_NBR_BITS(0X0003096DFD4AA41E);
// ADD_NBR_BITS(0X000702BCE90878F3);
// ADD_NBR_BITS(0X8001AD6E07D81185);
// ADD_NBR_BITS(0X800B3CA62432816B);
// ADD_NBR_BITS(0X800314911D2896E8);
// ADD_NBR_BITS(0X8007B0E93EA84FE6);
// ADD_NBR_BITS(0X00071790EAD8CBF4);
// ADD_NBR_BITS(0X000DEFF15FC60CB9);
// ADD_NBR_BITS(0X80039F8947AB771D);
// ADD_NBR_BITS(0X00086F246D1DA462);
// ADD_NBR_BITS(0X800979682AECB99A);
// ADD_NBR_BITS(0X8006D877282BEB3C);
// ADD_NBR_BITS(0X00050A0ACF69CB13);
// ADD_NBR_BITS(0X000E747E76510C7D);
// ADD_NBR_BITS(0X8005D0AA39045608);
// ADD_NBR_BITS(0X000B0FBE5092E6F6);
// ADD_NBR_BITS(0X000F615D624EEB68);
// ADD_NBR_BITS(0X800CD30B4FA86616);
// ADD_NBR_BITS(0X00065EBCEB4D8AF9);
// ADD_NBR_BITS(0X8007B0C0845B1526);
// ADD_NBR_BITS(0X00006FBD60045603);
// ADD_NBR_BITS(0X8001A4607085F3B1);
// ADD_NBR_BITS(0X8009DA29A8E1D769);
// ADD_NBR_BITS(0X000D205569EDF83C);
// ADD_NBR_BITS(0X80003AD0B930B54C);
// ADD_NBR_BITS(0X8001E89B794B5D83);
// ADD_NBR_BITS(0X000346A68595B969);
// ADD_NBR_BITS(0X00067DB72BFC33E8);
// ADD_NBR_BITS(0X000D727379B2ADB1);
// ADD_NBR_BITS(0X800F282FFFA94E09);
// ADD_NBR_BITS(0X80077741ABB1265A);
// ADD_NBR_BITS(0X000892834DDBBA52);
// ADD_NBR_BITS(0X00074663FF9B989A);
// ADD_NBR_BITS(0X00059951E5BD9119);
// ADD_NBR_BITS(0X8004B4E95F2CA418);
// ADD_NBR_BITS(0X8005C975E6132B2A);
// ADD_NBR_BITS(0X800E9A4C3B687272);
// ADD_NBR_BITS(0X8006F43301244B14);
// ADD_NBR_BITS(0X800BEF7504988BD1);
// ADD_NBR_BITS(0X00028C73E90854D5);
// ADD_NBR_BITS(0X800FA0EC6BA0B8A3);
// ADD_NBR_BITS(0X800B88458FA468A5);
// ADD_NBR_BITS(0X000AFB427AD96C19);
// ADD_NBR_BITS(0X00054BE69ACFB718);
// ADD_NBR_BITS(0X000F72699820AA27);
// ADD_NBR_BITS(0X80087A8EC65024B9);
// ADD_NBR_BITS(0X80000333EE06AC9D);
// ADD_NBR_BITS(0X800D09D992721CB3);
// ADD_NBR_BITS(0X8000652EDF6FDA87);
// ADD_NBR_BITS(0X80091C93E8F81B0A);
// ADD_NBR_BITS(0X0005CEC8C6872DA9);
// ADD_NBR_BITS(0X8008E3191E1BB8AB);
// ADD_NBR_BITS(0X8003E0259B4BB572);
// ADD_NBR_BITS(0X800D818D5EBB8C07);
// ADD_NBR_BITS(0X0008352E675AF883);
// ADD_NBR_BITS(0X0001EE73EFE7D3AD);
// ADD_NBR_BITS(0X80023E8EF39C3B68);
// ADD_NBR_BITS(0X000257C5C8DD00E4);
// ADD_NBR_BITS(0X800F9906E5556D2E);
// ADD_NBR_BITS(0X0009FD0CC3FA9EB7);
// ADD_NBR_BITS(0X800388A988FA313E);
// ADD_NBR_BITS(0X0002C295B113C0F3);
// ADD_NBR_BITS(0X800D0251A5615829);
// ADD_NBR_BITS(0X800A876ED5BA5986);
// ADD_NBR_BITS(0X800DBD7162CC8B5E);
// ADD_NBR_BITS(0X800FB04356876817);
// ADD_NBR_BITS(0X0002D5D38419B26D);
// ADD_NBR_BITS(0X00052416572AAD6C);
// ADD_NBR_BITS(0X000087A3F780E07E);
// ADD_NBR_BITS(0X00071A968AECA4B1);
// ADD_NBR_BITS(0X00021BC78155CEB9);
// ADD_NBR_BITS(0X000675C9187A0B2D);
// ADD_NBR_BITS(0X80024B3B74D3F687);
// ADD_NBR_BITS(0X8007B4CF822597B8);
// ADD_NBR_BITS(0X000D21BFA24E45AA);
// ADD_NBR_BITS(0X800DC65C102922DA);
// ADD_NBR_BITS(0X0001F44DF82738AE);
// ADD_NBR_BITS(0X80083E7AA153F80A);
// ADD_NBR_BITS(0X8005E7A8FE62C5CB);
// ADD_NBR_BITS(0X000DB687B2C960F3);
// ADD_NBR_BITS(0X800CFFCF62C2EDC4);
// ADD_NBR_BITS(0X000B50BB8020DE2C);
// ADD_NBR_BITS(0X00019B39D22D9105);
// ADD_NBR_BITS(0X8008B538C21BBDC2);
// ADD_NBR_BITS(0X00072647A2A1D0BE);
// ADD_NBR_BITS(0X00074FC157D7F4E1);
// ADD_NBR_BITS(0X80097E89396FAA12);
// ADD_NBR_BITS(0X8006DE104411088A);
// ADD_NBR_BITS(0X8003BB51996D803A);
// ADD_NBR_BITS(0X000E5481BB281C5E);
// ADD_NBR_BITS(0X000850130185BD72);
// ADD_NBR_BITS(0X0005F8C55C52E282);
// ADD_NBR_BITS(0X800423E064B659C9);
// ADD_NBR_BITS(0X00005E9888504242);
// ADD_NBR_BITS(0X800142370F27C464);
// ADD_NBR_BITS(0X0005DEEF868FBEF3);
// ADD_NBR_BITS(0X000414C3887A4F3C);
// ADD_NBR_BITS(0X000E0D5671D940BA);
// ADD_NBR_BITS(0X0007D65CC42E8AB3);
// ADD_NBR_BITS(0X8006D1619753F124);
// ADD_NBR_BITS(0X8000F7D38F509EB2);
// ADD_NBR_BITS(0X800FCF1DA654D053);
// ADD_NBR_BITS(0X000BA2F8ECB641CF);
// ADD_NBR_BITS(0X000625FC428907AA);
// ADD_NBR_BITS(0X8009745BA27F91E2);
// ADD_NBR_BITS(0X00089C9F37C5D781);
// ADD_NBR_BITS(0X800B69AD4388219F);
// ADD_NBR_BITS(0X0007F5312E082598);
// ADD_NBR_BITS(0X8001AC973D66755D);
// ADD_NBR_BITS(0X000EEAFF15EE9FC8);
// ADD_NBR_BITS(0X000A5AC813A81B75);
// ADD_NBR_BITS(0X000FF98A8B873BB6);
// ADD_NBR_BITS(0X00008396D9AF742D);
// ADD_NBR_BITS(0X800E39053D7D30BF);
// ADD_NBR_BITS(0X80001833ECD565FD);
// ADD_NBR_BITS(0X0005AF11D6B5226F);
// ADD_NBR_BITS(0X80071F7D3AE92196);
// ADD_NBR_BITS(0X800A3945880211BE);
// ADD_NBR_BITS(0X800DEE00C8CA8462);
// ADD_NBR_BITS(0X800A04A97DF66C1B);
// ADD_NBR_BITS(0X8004415E53592236);
// ADD_NBR_BITS(0X80064839583E2428);
// ADD_NBR_BITS(0X8000455C6EF30D5F);
// ADD_NBR_BITS(0X8003EE0439ED7094);
// ADD_NBR_BITS(0X000E1E568D22EF0B);
// ADD_NBR_BITS(0X800143937F4539A5);
// ADD_NBR_BITS(0X0008DF827F480A83);
// ADD_NBR_BITS(0X0005DB61B36B8581);
// ADD_NBR_BITS(0X800B716D0EB7FBDD);
// ADD_NBR_BITS(0X0002E2EF98B1D7EE);
// ADD_NBR_BITS(0X800DCED1ECD33C5C);
// ADD_NBR_BITS(0X0008DD0A5772E6C9);
// ADD_NBR_BITS(0X000FAA92A6B28DC1);
// ADD_NBR_BITS(0X8003A09A050792E5);
// ADD_NBR_BITS(0X00013855B102B196);
// ADD_NBR_BITS(0X8008B7A86003D803);
// ADD_NBR_BITS(0X8000D6AAA8549825);
// ADD_NBR_BITS(0X8009727513DC059D);
// ADD_NBR_BITS(0X0001C47A3B090E08);
// ADD_NBR_BITS(0X0001D68BC20C16D8);
// ADD_NBR_BITS(0X8008B43320948C9D);
// ADD_NBR_BITS(0X000873CD95D178AC);
// ADD_NBR_BITS(0X800A61143CDB54D1);
// ADD_NBR_BITS(0X800B0406181226B4);
// ADD_NBR_BITS(0X0001E48B96638328);
// ADD_NBR_BITS(0X800A19A514983E11);
// ADD_NBR_BITS(0X000643D10055ADDF);
// ADD_NBR_BITS(0X80071D29821618DD);
// ADD_NBR_BITS(0X000B29A1CC233BA9);
// ADD_NBR_BITS(0X800083D551F24D7C);
// ADD_NBR_BITS(0X000233BEC8E0EDF6);
// ADD_NBR_BITS(0X0008A3A149C5DB14);
// ADD_NBR_BITS(0X8009A2A942753C4C);
// ADD_NBR_BITS(0X000BB7D0A414C18D);
// ADD_NBR_BITS(0X000A986005A5DCF8);
// ADD_NBR_BITS(0X0004755B07ED5BD3);
// ADD_NBR_BITS(0X000D140CB14142FF);
// ADD_NBR_BITS(0X000A7460BEE27AA5);
// ADD_NBR_BITS(0X0000F82F614F7201);
// ADD_NBR_BITS(0X800CB894EF1C74A9);
// ADD_NBR_BITS(0X800E79BE6745729E);
// ADD_NBR_BITS(0X800BEE23B9F639F6);
// ADD_NBR_BITS(0X8006E5E3B4201E1E);
// ADD_NBR_BITS(0X80034A1D3724C733);
// ADD_NBR_BITS(0X8006018BC0AFC8DD);
// ADD_NBR_BITS(0X0009CA34F4A49213);
// ADD_NBR_BITS(0X800AAB48579F2AED);
// ADD_NBR_BITS(0X80050D704A991318);
// ADD_NBR_BITS(0X800AFC8F7CA7BDAE);
// ADD_NBR_BITS(0X80021D909CB64D4A);
// ADD_NBR_BITS(0X80040F5DB235EAB1);
// ADD_NBR_BITS(0X800267E690AA2E46);
// ADD_NBR_BITS(0X8008B726908F6856);
// ADD_NBR_BITS(0X80061A10A578E457);
// ADD_NBR_BITS(0X800B061A258DBAE8);
// ADD_NBR_BITS(0X80071DC478FAC156);
// ADD_NBR_BITS(0X800CA526D797C9BD);
// ADD_NBR_BITS(0X000F402C6C611EC5);
// ADD_NBR_BITS(0X000BD6E2F2925B88);
// ADD_NBR_BITS(0X80006312BC728938);
// ADD_NBR_BITS(0X800173820C74E7E2);
// ADD_NBR_BITS(0X800F956AB0EB1A72);
// ADD_NBR_BITS(0X8008CF675C60F0D3);
// ADD_NBR_BITS(0X80018654F9A3E63B);
// ADD_NBR_BITS(0X000084603C8EDFC6);
// ADD_NBR_BITS(0X8006883D904EEC7B);
// ADD_NBR_BITS(0X800398F98941D684);
// ADD_NBR_BITS(0X0003C5D06F43D10F);



ADD_NBR_BITS(0X0000000000000003);
ADD_NBR_BITS(0X00000000DC291997);
ADD_NBR_BITS(0X8000000000000D8F);
ADD_NBR_BITS(0X0000000000EA20C2);
ADD_NBR_BITS(0X0000000000000301);
ADD_NBR_BITS(0X800E1A6B652D06FE);
ADD_NBR_BITS(0X0000000000006B16);
ADD_NBR_BITS(0X8000001D75EA45F8);
ADD_NBR_BITS(0X000000009CD4E6DB);
ADD_NBR_BITS(0X800002DB2C81FE06);
ADD_NBR_BITS(0X000000000CB248A5);
ADD_NBR_BITS(0X000000001D34C05E);
ADD_NBR_BITS(0X00000FEEE04A5A2B);
ADD_NBR_BITS(0X000000000000006F);
ADD_NBR_BITS(0X8000000183C67E16);
ADD_NBR_BITS(0X800F432300F3B1A7);
ADD_NBR_BITS(0X0000020EE3C8C86B);
ADD_NBR_BITS(0X8000000008A2FE0A);
ADD_NBR_BITS(0X0003D19580C65B74);
ADD_NBR_BITS(0X0000000000000007);
ADD_NBR_BITS(0X8000000002AAD428);
ADD_NBR_BITS(0X000BDF425D31DC7B);
ADD_NBR_BITS(0X800D84DC56E2BA6B);
ADD_NBR_BITS(0X000000FDD3A7A85C);
ADD_NBR_BITS(0X8000000000000D11);
ADD_NBR_BITS(0X000001A14EB51AE1);
ADD_NBR_BITS(0X80000000ADA1D61B);
ADD_NBR_BITS(0X000000000006B7B4);
ADD_NBR_BITS(0X800000000C8BE14D);
ADD_NBR_BITS(0X800000000298ACBD);
ADD_NBR_BITS(0X8000D2BCF0C068D7);
ADD_NBR_BITS(0X8000228254396C79);
ADD_NBR_BITS(0X8000000000000882);
ADD_NBR_BITS(0X0000000000000103);
ADD_NBR_BITS(0X0000000030B26BF5);
ADD_NBR_BITS(0X8000670E4C3D62E5);
ADD_NBR_BITS(0X0000000000203626);
ADD_NBR_BITS(0X0000000000000C9D);
ADD_NBR_BITS(0X000000073CF3803C);
ADD_NBR_BITS(0X0000000000000002);
ADD_NBR_BITS(0X800000000000D912);
ADD_NBR_BITS(0X8000000000000006);
ADD_NBR_BITS(0X00002B3B6D8A3CAB);
ADD_NBR_BITS(0X0000000013032775);
ADD_NBR_BITS(0X0000000869458A9B);
ADD_NBR_BITS(0X8000000000000872);
ADD_NBR_BITS(0X8000A0E1FE6180D6);
ADD_NBR_BITS(0X000000079338E372);
ADD_NBR_BITS(0X80000000000000C7);
ADD_NBR_BITS(0X80000000000073EF);
ADD_NBR_BITS(0X0000D88737D227B6);
ADD_NBR_BITS(0X80000000007AB438);
ADD_NBR_BITS(0X0000000D0B457B9C);
ADD_NBR_BITS(0X800000000D180D86);
ADD_NBR_BITS(0X800000000000199F);
ADD_NBR_BITS(0X80000000000078BD);
ADD_NBR_BITS(0X0000000002BA07F4);
ADD_NBR_BITS(0X8000000000F1B4BD);
ADD_NBR_BITS(0X00000000B6FE8C76);
ADD_NBR_BITS(0X800FA4E09B24DD29);
ADD_NBR_BITS(0X80000000000000E7);
ADD_NBR_BITS(0X800000000000097D);
ADD_NBR_BITS(0X80033FCB087CB4DB);
ADD_NBR_BITS(0X00062E0E345F12EC);
ADD_NBR_BITS(0X800000534C8EF2AE);
ADD_NBR_BITS(0X800000000000000C);
ADD_NBR_BITS(0X0000000000221B6F);
ADD_NBR_BITS(0X8000001F39A81292);
ADD_NBR_BITS(0X000000A02826DAB9);
ADD_NBR_BITS(0X0000000D6B007E25);
ADD_NBR_BITS(0X800005B02D32F9D2);
ADD_NBR_BITS(0X000008457DF4D64B);
ADD_NBR_BITS(0X8000000000C40867);
ADD_NBR_BITS(0X00008D9DF1B956F6);
ADD_NBR_BITS(0X800000000BBD86D4);
ADD_NBR_BITS(0X8000004280CBE625);
ADD_NBR_BITS(0X000000000000008C);
ADD_NBR_BITS(0X800017AEFD21AF25);
ADD_NBR_BITS(0X8000000000000053);
ADD_NBR_BITS(0X0006185BFA050757);
ADD_NBR_BITS(0X00000000D42E06F3);
ADD_NBR_BITS(0X00000000000FDBDD);
ADD_NBR_BITS(0X800000B9F0FCF304);
ADD_NBR_BITS(0X80000000000000B1);
ADD_NBR_BITS(0X0000001B7385EC8F);
ADD_NBR_BITS(0X0000B10A409455E9);
ADD_NBR_BITS(0X0000000000006849);
ADD_NBR_BITS(0X0000000737E52A71);
ADD_NBR_BITS(0X00000005B7AD9499);
ADD_NBR_BITS(0X0000000009036856);
ADD_NBR_BITS(0X0000000000065EB4);
ADD_NBR_BITS(0X800000000000E6C3);
ADD_NBR_BITS(0X8004134AA5CFACDD);
ADD_NBR_BITS(0X800000000000072B);
ADD_NBR_BITS(0X800000000000007C);
ADD_NBR_BITS(0X000000005FF8EBA5);
ADD_NBR_BITS(0X8000000F327F650A);
ADD_NBR_BITS(0X000000000075C406);
ADD_NBR_BITS(0X0000000000000008);
ADD_NBR_BITS(0X000AF0D6232551DD);
ADD_NBR_BITS(0X8000000E6CDB98A3);
ADD_NBR_BITS(0X800000000000B1FD);
ADD_NBR_BITS(0X00000000000000E1);
ADD_NBR_BITS(0X00000000024406BE);
ADD_NBR_BITS(0X800000000F17367B);
ADD_NBR_BITS(0X8000000000BDDECD);
ADD_NBR_BITS(0X000000000000E12B);
ADD_NBR_BITS(0X000596A87D39C7F9);
ADD_NBR_BITS(0X000000000000EC52);
ADD_NBR_BITS(0X80000000000009EB);
ADD_NBR_BITS(0X00000000BF336AFE);
ADD_NBR_BITS(0X8000000000000E5C);
ADD_NBR_BITS(0X0000000000000A85);
ADD_NBR_BITS(0X8000000009D5BF6F);
ADD_NBR_BITS(0X0000000000B4572E);
ADD_NBR_BITS(0X00000000000B698E);
ADD_NBR_BITS(0X80000000B8EB299F);
ADD_NBR_BITS(0X80000000F12219EE);
ADD_NBR_BITS(0X0000000538B3FEFD);
ADD_NBR_BITS(0X00000000000006C1);
ADD_NBR_BITS(0X00000005000D2BB5);
ADD_NBR_BITS(0X80000000F8975E3B);
ADD_NBR_BITS(0X8000000000000004);
ADD_NBR_BITS(0X0000000CBE9964B7);
ADD_NBR_BITS(0X80000000DCE96E37);
ADD_NBR_BITS(0X0000000000000004);
ADD_NBR_BITS(0X8000000000052EF5);
ADD_NBR_BITS(0X80000000000B4489);
ADD_NBR_BITS(0X00000000060124A5);
ADD_NBR_BITS(0X000000000000FDC6);
ADD_NBR_BITS(0X0000000000BA056A);
ADD_NBR_BITS(0X000000B55C6F57E7);
ADD_NBR_BITS(0X0000334DF00A3889);
ADD_NBR_BITS(0X000A065FD5C0EBBF);
ADD_NBR_BITS(0X000000003CBAB78E);
ADD_NBR_BITS(0X00000000000515CB);
ADD_NBR_BITS(0X0000000000000A5F);
ADD_NBR_BITS(0X800000059A8AD1A8);
ADD_NBR_BITS(0X8000000000000004);
ADD_NBR_BITS(0X0000000000004C6F);
ADD_NBR_BITS(0X00000000000271AA);
ADD_NBR_BITS(0X0000000000000B96);
ADD_NBR_BITS(0X800000000002299A);
ADD_NBR_BITS(0X0007EFC31FB2D311);
ADD_NBR_BITS(0X0000000000000C31);
ADD_NBR_BITS(0X00000000B3D25C01);
ADD_NBR_BITS(0X0000000000000AD9);
ADD_NBR_BITS(0X8000000000000009);
ADD_NBR_BITS(0X00000001784D0616);
ADD_NBR_BITS(0X800000000007B0E8);
ADD_NBR_BITS(0X00000000000071B2);
ADD_NBR_BITS(0X800371E3516B1524);
ADD_NBR_BITS(0X8000000000008CD9);
ADD_NBR_BITS(0X80000000000000DE);
ADD_NBR_BITS(0X0000000000B093C9);
ADD_NBR_BITS(0X80000000343AAC07);
ADD_NBR_BITS(0X800003470D1197AC);
ADD_NBR_BITS(0X80005E7BA47E1E8A);
ADD_NBR_BITS(0X80000000000000A4);
ADD_NBR_BITS(0X8000000000000ACE);
ADD_NBR_BITS(0X0000000C60FE8333);
ADD_NBR_BITS(0X000053C71011DEE4);
ADD_NBR_BITS(0X800000026191BA35);
ADD_NBR_BITS(0X0000000000778347);
ADD_NBR_BITS(0X8000000E09FED0D9);
ADD_NBR_BITS(0X800000009D43416F);
ADD_NBR_BITS(0X00000000000B25CB);
ADD_NBR_BITS(0X000000000000A484);
ADD_NBR_BITS(0X000000000000000B);
ADD_NBR_BITS(0X000000000045428F);
ADD_NBR_BITS(0X000000000000089A);
ADD_NBR_BITS(0X00000000000048CD);
ADD_NBR_BITS(0X80000000000000A7);
ADD_NBR_BITS(0X000000000C7124AB);
ADD_NBR_BITS(0X000000000000007A);
ADD_NBR_BITS(0X800000A9B4B4D069);
ADD_NBR_BITS(0X800095447B343A34);
ADD_NBR_BITS(0X0000000000000844);
ADD_NBR_BITS(0X80000001313DC71C);
ADD_NBR_BITS(0X80000000000AF0C7);
ADD_NBR_BITS(0X8002FF0CE2AC3737);
ADD_NBR_BITS(0X000000000000435C);
ADD_NBR_BITS(0X00000924F5CB1739);
ADD_NBR_BITS(0X000000000000AAAC);
ADD_NBR_BITS(0X00000CA05E287A22);
ADD_NBR_BITS(0X00003BF195953A29);
ADD_NBR_BITS(0X0000000009CCCC38);
ADD_NBR_BITS(0X00000000AC4BEE94);
ADD_NBR_BITS(0X0000000000000001);
ADD_NBR_BITS(0X00000000C902E093);
ADD_NBR_BITS(0X000000832B002BAE);
ADD_NBR_BITS(0X0000000000000001);
ADD_NBR_BITS(0X80000000DDC98AC5);
ADD_NBR_BITS(0X0000000000EDF1C3);
ADD_NBR_BITS(0X8000000000000014);
ADD_NBR_BITS(0X80086EF641126047);
ADD_NBR_BITS(0X00000000000000DB);
ADD_NBR_BITS(0X000000000000003D);
ADD_NBR_BITS(0X00000000000000AD);
ADD_NBR_BITS(0X000000BF0A5FECF6);

#elif FLOAT_TO_TEST == 3
// 30 nan random
ADD_NBR_BITS(0X7FFACBC37AC774BC);
ADD_NBR_BITS(0X7FFFC111775486B5);
ADD_NBR_BITS(0XFFF08D0D08C97863);
ADD_NBR_BITS(0XFFFB01FF90CA523F);
ADD_NBR_BITS(0X7FFF11721DFFB9DD);
ADD_NBR_BITS(0XFFF20B886092291D);
ADD_NBR_BITS(0XFFFE0F8C54BE3134);
ADD_NBR_BITS(0X7FF32FEB4722FF5F);
ADD_NBR_BITS(0X7FF03807DB864468);
ADD_NBR_BITS(0X7FF90273B113BE17);
ADD_NBR_BITS(0XFFF5DAE0399D4189);
ADD_NBR_BITS(0XFFF1A058BD70DF69);
ADD_NBR_BITS(0X7FF0CE7F6C082AE8);
ADD_NBR_BITS(0X7FF0A70DE17579B3);
ADD_NBR_BITS(0XFFF5917913C8ED1C);
ADD_NBR_BITS(0XFFF75A0DE8A0DCA7);
ADD_NBR_BITS(0X7FFC03C6A9DB8C6C);
ADD_NBR_BITS(0X7FF69A59AC6402E3);
ADD_NBR_BITS(0XFFF528B678AF3697);
ADD_NBR_BITS(0X7FF91DFBB30D2F16);
ADD_NBR_BITS(0X7FF2419A46A70859);
ADD_NBR_BITS(0X7FFBE6D3403BCB68);
ADD_NBR_BITS(0XFFFC7648844EEF6E);
ADD_NBR_BITS(0XFFF0711654EF5C57);
ADD_NBR_BITS(0XFFF96E3690D18075);
ADD_NBR_BITS(0X7FF95AEE7FF6FE36);
ADD_NBR_BITS(0X7FF842EAE3ABAC93);
ADD_NBR_BITS(0XFFFF34780874BC1F);
ADD_NBR_BITS(0XFFFE88AF64DF4EE6);
ADD_NBR_BITS(0XFFF6A90573E65A5F);

// les fixes
ADD_NBR_BITS(0X0000000000000000);
ADD_NBR_BITS(0X8000000000000000);
ADD_NBR_BITS(0X7FF0000000000000);
ADD_NBR_BITS(0XFFF0000000000000);
#elif FLOAT_TO_TEST == 4
// NAN bornes et leur delta sur 33
ADD_NBR_BITS(0x7FF0000000000001);
ADD_NBR_BITS(0x7FF0000000000002);
ADD_NBR_BITS(0x7FF0000000000003);
ADD_NBR_BITS(0x7FF0000000000004);
ADD_NBR_BITS(0x7FF0000000000005);
ADD_NBR_BITS(0x7FF0000000000006);
ADD_NBR_BITS(0x7FF0000000000007);
ADD_NBR_BITS(0x7FF0000000000008);
ADD_NBR_BITS(0x7FF0000000000009);
ADD_NBR_BITS(0x7FF000000000000A);
ADD_NBR_BITS(0x7FF000000000000B);
ADD_NBR_BITS(0x7FF000000000000C);
ADD_NBR_BITS(0x7FF000000000000D);
ADD_NBR_BITS(0x7FF000000000000E);
ADD_NBR_BITS(0x7FF000000000000F);
ADD_NBR_BITS(0x7FF0000000000010);
ADD_NBR_BITS(0x7FF0000000000011);
ADD_NBR_BITS(0x7FF0000000000012);
ADD_NBR_BITS(0x7FF0000000000013);
ADD_NBR_BITS(0x7FF0000000000014);
ADD_NBR_BITS(0x7FF0000000000015);
ADD_NBR_BITS(0x7FF0000000000016);
ADD_NBR_BITS(0x7FF0000000000017);
ADD_NBR_BITS(0x7FF0000000000018);
ADD_NBR_BITS(0x7FF0000000000019);
ADD_NBR_BITS(0x7FF000000000001A);
ADD_NBR_BITS(0x7FF000000000001B);
ADD_NBR_BITS(0x7FF000000000001C);
ADD_NBR_BITS(0x7FF000000000001D);
ADD_NBR_BITS(0x7FF000000000001E);
ADD_NBR_BITS(0x7FF000000000001F);
ADD_NBR_BITS(0x7FF0000000000020);
ADD_NBR_BITS(0x7FF0000000000021);
ADD_NBR_BITS(0x7FF0000000000022);

ADD_NBR_BITS(0xFFF0000000000001);
ADD_NBR_BITS(0xFFF0000000000002);
ADD_NBR_BITS(0xFFF0000000000003);
ADD_NBR_BITS(0xFFF0000000000004);
ADD_NBR_BITS(0xFFF0000000000005);
ADD_NBR_BITS(0xFFF0000000000006);
ADD_NBR_BITS(0xFFF0000000000007);
ADD_NBR_BITS(0xFFF0000000000008);
ADD_NBR_BITS(0xFFF0000000000009);
ADD_NBR_BITS(0xFFF000000000000A);
ADD_NBR_BITS(0xFFF000000000000B);
ADD_NBR_BITS(0xFFF000000000000C);
ADD_NBR_BITS(0xFFF000000000000D);
ADD_NBR_BITS(0xFFF000000000000E);
ADD_NBR_BITS(0xFFF000000000000F);
ADD_NBR_BITS(0xFFF0000000000010);
ADD_NBR_BITS(0xFFF0000000000011);
ADD_NBR_BITS(0xFFF0000000000012);
ADD_NBR_BITS(0xFFF0000000000013);
ADD_NBR_BITS(0xFFF0000000000014);
ADD_NBR_BITS(0xFFF0000000000015);
ADD_NBR_BITS(0xFFF0000000000016);
ADD_NBR_BITS(0xFFF0000000000017);
ADD_NBR_BITS(0xFFF0000000000018);
ADD_NBR_BITS(0xFFF0000000000019);
ADD_NBR_BITS(0xFFF000000000001A);
ADD_NBR_BITS(0xFFF000000000001B);
ADD_NBR_BITS(0xFFF000000000001C);
ADD_NBR_BITS(0xFFF000000000001D);
ADD_NBR_BITS(0xFFF000000000001E);
ADD_NBR_BITS(0xFFF000000000001F);
ADD_NBR_BITS(0xFFF0000000000020);
ADD_NBR_BITS(0xFFF0000000000021);
ADD_NBR_BITS(0xFFF0000000000022);

ADD_NBR_BITS(0x7FFFFFFFFFFFFFFF);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFFE);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFFD);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFFC);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFFB);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFFA);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFF9);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFF8);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFF7);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFF6);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFF5);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFF4);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFF3);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFF2);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFF1);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFF0);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFEF);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFEE);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFED);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFEC);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFEB);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFEA);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFE9);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFE8);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFE7);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFE6);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFE5);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFE4);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFE3);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFE2);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFE1);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFE0);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFDF);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFDE);

ADD_NBR_BITS(0xFFFFFFFFFFFFFFFF);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFFE);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFFD);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFFC);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFFB);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFFA);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFF9);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFF8);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFF7);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFF6);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFF5);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFF4);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFF3);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFF2);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFF1);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFF0);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFEF);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFEE);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFED);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFEC);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFEB);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFEA);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFE9);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFE8);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFE7);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFE6);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFE5);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFE4);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFE3);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFE2);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFE1);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFE0);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFDF);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFDE);



#elif FLOAT_TO_TEST == 5

// Normal bornes et leur delta sur 33
ADD_NBR_BITS(0x0010000000000000);
ADD_NBR_BITS(0x0010000000000001);
ADD_NBR_BITS(0x0010000000000002);
ADD_NBR_BITS(0x0010000000000003);
ADD_NBR_BITS(0x0010000000000004);
ADD_NBR_BITS(0x0010000000000005);
ADD_NBR_BITS(0x0010000000000006);
ADD_NBR_BITS(0x0010000000000007);
ADD_NBR_BITS(0x0010000000000008);
ADD_NBR_BITS(0x0010000000000009);
ADD_NBR_BITS(0x001000000000000A);
ADD_NBR_BITS(0x001000000000000B);
ADD_NBR_BITS(0x001000000000000C);
ADD_NBR_BITS(0x001000000000000D);
ADD_NBR_BITS(0x001000000000000E);
ADD_NBR_BITS(0x001000000000000F);
ADD_NBR_BITS(0x0010000000000010);
ADD_NBR_BITS(0x0010000000000011);
ADD_NBR_BITS(0x0010000000000012);
ADD_NBR_BITS(0x0010000000000013);
ADD_NBR_BITS(0x0010000000000014);
ADD_NBR_BITS(0x0010000000000015);
ADD_NBR_BITS(0x0010000000000016);
ADD_NBR_BITS(0x0010000000000017);
ADD_NBR_BITS(0x0010000000000018);
ADD_NBR_BITS(0x0010000000000019);
ADD_NBR_BITS(0x001000000000001A);
ADD_NBR_BITS(0x001000000000001B);
ADD_NBR_BITS(0x001000000000001C);
ADD_NBR_BITS(0x001000000000001D);
ADD_NBR_BITS(0x001000000000001E);
ADD_NBR_BITS(0x001000000000001F);
ADD_NBR_BITS(0x0010000000000020);
ADD_NBR_BITS(0x0010000000000021);

ADD_NBR_BITS(0x8010000000000000);
ADD_NBR_BITS(0x8010000000000001);
ADD_NBR_BITS(0x8010000000000002);
ADD_NBR_BITS(0x8010000000000003);
ADD_NBR_BITS(0x8010000000000004);
ADD_NBR_BITS(0x8010000000000005);
ADD_NBR_BITS(0x8010000000000006);
ADD_NBR_BITS(0x8010000000000007);
ADD_NBR_BITS(0x8010000000000008);
ADD_NBR_BITS(0x8010000000000009);
ADD_NBR_BITS(0x801000000000000A);
ADD_NBR_BITS(0x801000000000000B);
ADD_NBR_BITS(0x801000000000000C);
ADD_NBR_BITS(0x801000000000000D);
ADD_NBR_BITS(0x801000000000000E);
ADD_NBR_BITS(0x801000000000000F);
ADD_NBR_BITS(0x8010000000000010);
ADD_NBR_BITS(0x8010000000000011);
ADD_NBR_BITS(0x8010000000000012);
ADD_NBR_BITS(0x8010000000000013);
ADD_NBR_BITS(0x8010000000000014);
ADD_NBR_BITS(0x8010000000000015);
ADD_NBR_BITS(0x8010000000000016);
ADD_NBR_BITS(0x8010000000000017);
ADD_NBR_BITS(0x8010000000000018);
ADD_NBR_BITS(0x8010000000000019);
ADD_NBR_BITS(0x801000000000001A);
ADD_NBR_BITS(0x801000000000001B);
ADD_NBR_BITS(0x801000000000001C);
ADD_NBR_BITS(0x801000000000001D);
ADD_NBR_BITS(0x801000000000001E);
ADD_NBR_BITS(0x801000000000001F);
ADD_NBR_BITS(0x8010000000000020);
ADD_NBR_BITS(0x8010000000000021);

ADD_NBR_BITS(0x7FEFFFFFFFFFFFFF);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFFE);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFFD);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFFC);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFFB);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFFA);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFF9);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFF8);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFF7);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFF6);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFF5);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFF4);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFF3);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFF2);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFF1);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFF0);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFEF);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFEE);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFED);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFEC);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFEB);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFEA);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFE9);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFE8);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFE7);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFE6);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFE5);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFE4);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFE3);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFE2);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFE1);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFE0);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFDF);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFDE);

ADD_NBR_BITS(0xFFEFFFFFFFFFFFFF);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFFE);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFFD);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFFC);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFFB);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFFA);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFF9);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFF8);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFF7);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFF6);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFF5);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFF4);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFF3);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFF2);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFF1);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFF0);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFEF);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFEE);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFED);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFEC);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFEB);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFEA);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFE9);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFE8);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFE7);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFE6);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFE5);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFE4);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFE3);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFE2);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFE1);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFE0);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFDF);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFDE);



#elif FLOAT_TO_TEST == 6

// Denormal bornes et leur delta sur 33
ADD_NBR_BITS(0x0000000000000001);
ADD_NBR_BITS(0x0000000000000002);
ADD_NBR_BITS(0x0000000000000003);
ADD_NBR_BITS(0x0000000000000004);
ADD_NBR_BITS(0x0000000000000005);
ADD_NBR_BITS(0x0000000000000006);
ADD_NBR_BITS(0x0000000000000007);
ADD_NBR_BITS(0x0000000000000008);
ADD_NBR_BITS(0x0000000000000009);
ADD_NBR_BITS(0x000000000000000A);
ADD_NBR_BITS(0x000000000000000B);
ADD_NBR_BITS(0x000000000000000C);
ADD_NBR_BITS(0x000000000000000D);
ADD_NBR_BITS(0x000000000000000E);
ADD_NBR_BITS(0x000000000000000F);
ADD_NBR_BITS(0x0000000000000010);
ADD_NBR_BITS(0x0000000000000011);
ADD_NBR_BITS(0x0000000000000012);
ADD_NBR_BITS(0x0000000000000013);
ADD_NBR_BITS(0x0000000000000014);
ADD_NBR_BITS(0x0000000000000015);
ADD_NBR_BITS(0x0000000000000016);
ADD_NBR_BITS(0x0000000000000017);
ADD_NBR_BITS(0x0000000000000018);
ADD_NBR_BITS(0x0000000000000019);
ADD_NBR_BITS(0x000000000000001A);
ADD_NBR_BITS(0x000000000000001B);
ADD_NBR_BITS(0x000000000000001C);
ADD_NBR_BITS(0x000000000000001D);
ADD_NBR_BITS(0x000000000000001E);
ADD_NBR_BITS(0x000000000000001F);
ADD_NBR_BITS(0x0000000000000020);
ADD_NBR_BITS(0x0000000000000021);
ADD_NBR_BITS(0x0000000000000022);

ADD_NBR_BITS(0x8000000000000001);
ADD_NBR_BITS(0x8000000000000002);
ADD_NBR_BITS(0x8000000000000003);
ADD_NBR_BITS(0x8000000000000004);
ADD_NBR_BITS(0x8000000000000005);
ADD_NBR_BITS(0x8000000000000006);
ADD_NBR_BITS(0x8000000000000007);
ADD_NBR_BITS(0x8000000000000008);
ADD_NBR_BITS(0x8000000000000009);
ADD_NBR_BITS(0x800000000000000A);
ADD_NBR_BITS(0x800000000000000B);
ADD_NBR_BITS(0x800000000000000C);
ADD_NBR_BITS(0x800000000000000D);
ADD_NBR_BITS(0x800000000000000E);
ADD_NBR_BITS(0x800000000000000F);
ADD_NBR_BITS(0x8000000000000010);
ADD_NBR_BITS(0x8000000000000011);
ADD_NBR_BITS(0x8000000000000012);
ADD_NBR_BITS(0x8000000000000013);
ADD_NBR_BITS(0x8000000000000014);
ADD_NBR_BITS(0x8000000000000015);
ADD_NBR_BITS(0x8000000000000016);
ADD_NBR_BITS(0x8000000000000017);
ADD_NBR_BITS(0x8000000000000018);
ADD_NBR_BITS(0x8000000000000019);
ADD_NBR_BITS(0x800000000000001A);
ADD_NBR_BITS(0x800000000000001B);
ADD_NBR_BITS(0x800000000000001C);
ADD_NBR_BITS(0x800000000000001D);
ADD_NBR_BITS(0x800000000000001E);
ADD_NBR_BITS(0x800000000000001F);
ADD_NBR_BITS(0x8000000000000020);
ADD_NBR_BITS(0x8000000000000021);
ADD_NBR_BITS(0x8000000000000022);

ADD_NBR_BITS(0x000FFFFFFFFFFFFF);
ADD_NBR_BITS(0x000FFFFFFFFFFFFE);
ADD_NBR_BITS(0x000FFFFFFFFFFFFD);
ADD_NBR_BITS(0x000FFFFFFFFFFFFC);
ADD_NBR_BITS(0x000FFFFFFFFFFFFB);
ADD_NBR_BITS(0x000FFFFFFFFFFFFA);
ADD_NBR_BITS(0x000FFFFFFFFFFFF9);
ADD_NBR_BITS(0x000FFFFFFFFFFFF8);
ADD_NBR_BITS(0x000FFFFFFFFFFFF7);
ADD_NBR_BITS(0x000FFFFFFFFFFFF6);
ADD_NBR_BITS(0x000FFFFFFFFFFFF5);
ADD_NBR_BITS(0x000FFFFFFFFFFFF4);
ADD_NBR_BITS(0x000FFFFFFFFFFFF3);
ADD_NBR_BITS(0x000FFFFFFFFFFFF2);
ADD_NBR_BITS(0x000FFFFFFFFFFFF1);
ADD_NBR_BITS(0x000FFFFFFFFFFFF0);
ADD_NBR_BITS(0x000FFFFFFFFFFFEF);
ADD_NBR_BITS(0x000FFFFFFFFFFFEE);
ADD_NBR_BITS(0x000FFFFFFFFFFFED);
ADD_NBR_BITS(0x000FFFFFFFFFFFEC);
ADD_NBR_BITS(0x000FFFFFFFFFFFEB);
ADD_NBR_BITS(0x000FFFFFFFFFFFEA);
ADD_NBR_BITS(0x000FFFFFFFFFFFE9);
ADD_NBR_BITS(0x000FFFFFFFFFFFE8);
ADD_NBR_BITS(0x000FFFFFFFFFFFE7);
ADD_NBR_BITS(0x000FFFFFFFFFFFE6);
ADD_NBR_BITS(0x000FFFFFFFFFFFE5);
ADD_NBR_BITS(0x000FFFFFFFFFFFE4);
ADD_NBR_BITS(0x000FFFFFFFFFFFE3);
ADD_NBR_BITS(0x000FFFFFFFFFFFE2);
ADD_NBR_BITS(0x000FFFFFFFFFFFE1);
ADD_NBR_BITS(0x000FFFFFFFFFFFE0);
ADD_NBR_BITS(0x000FFFFFFFFFFFDF);
ADD_NBR_BITS(0x000FFFFFFFFFFFDE);

ADD_NBR_BITS(0x800FFFFFFFFFFFFF);
ADD_NBR_BITS(0x800FFFFFFFFFFFFE);
ADD_NBR_BITS(0x800FFFFFFFFFFFFD);
ADD_NBR_BITS(0x800FFFFFFFFFFFFC);
ADD_NBR_BITS(0x800FFFFFFFFFFFFB);
ADD_NBR_BITS(0x800FFFFFFFFFFFFA);
ADD_NBR_BITS(0x800FFFFFFFFFFFF9);
ADD_NBR_BITS(0x800FFFFFFFFFFFF8);
ADD_NBR_BITS(0x800FFFFFFFFFFFF7);
ADD_NBR_BITS(0x800FFFFFFFFFFFF6);
ADD_NBR_BITS(0x800FFFFFFFFFFFF5);
ADD_NBR_BITS(0x800FFFFFFFFFFFF4);
ADD_NBR_BITS(0x800FFFFFFFFFFFF3);
ADD_NBR_BITS(0x800FFFFFFFFFFFF2);
ADD_NBR_BITS(0x800FFFFFFFFFFFF1);
ADD_NBR_BITS(0x800FFFFFFFFFFFF0);
ADD_NBR_BITS(0x800FFFFFFFFFFFEF);
ADD_NBR_BITS(0x800FFFFFFFFFFFEE);
ADD_NBR_BITS(0x800FFFFFFFFFFFED);
ADD_NBR_BITS(0x800FFFFFFFFFFFEC);
ADD_NBR_BITS(0x800FFFFFFFFFFFEB);
ADD_NBR_BITS(0x800FFFFFFFFFFFEA);
ADD_NBR_BITS(0x800FFFFFFFFFFFE9);
ADD_NBR_BITS(0x800FFFFFFFFFFFE8);
ADD_NBR_BITS(0x800FFFFFFFFFFFE7);
ADD_NBR_BITS(0x800FFFFFFFFFFFE6);
ADD_NBR_BITS(0x800FFFFFFFFFFFE5);
ADD_NBR_BITS(0x800FFFFFFFFFFFE4);
ADD_NBR_BITS(0x800FFFFFFFFFFFE3);
ADD_NBR_BITS(0x800FFFFFFFFFFFE2);
ADD_NBR_BITS(0x800FFFFFFFFFFFE1);
ADD_NBR_BITS(0x800FFFFFFFFFFFE0);
ADD_NBR_BITS(0x800FFFFFFFFFFFDF);
ADD_NBR_BITS(0x800FFFFFFFFFFFDE);

#elif FLOAT_TO_TEST == 7

ADD_NBR_DECI(0.1);
ADD_NBR_DECI(0.01);
ADD_NBR_DECI(0.001);
ADD_NBR_DECI(0.0001);
ADD_NBR_DECI(0.000123456789);
ADD_NBR_DECI(0.000123456789);
ADD_NBR_DECI(0.00123456789);
ADD_NBR_DECI(0.0123456789);
ADD_NBR_DECI(0.123456789);
ADD_NBR_DECI(1.23456789);
ADD_NBR_DECI(12.3456789);
ADD_NBR_DECI(123.456789);
ADD_NBR_DECI(1234.56789);
ADD_NBR_DECI(12345.6789);
ADD_NBR_DECI(123456.789);
ADD_NBR_DECI(1234567.89);
ADD_NBR_DECI(12345678.9);
ADD_NBR_DECI(123456789.0);
ADD_NBR_DECI(0.120003456789);
ADD_NBR_DECI(1.23400056789);
ADD_NBR_DECI(12.3450006789);
ADD_NBR_DECI(123.450006789);
ADD_NBR_DECI(1234.56000789);
ADD_NBR_DECI(12345.6700089);
ADD_NBR_DECI(123456.780009);
ADD_NBR_DECI(1234567.80009);
ADD_NBR_DECI(12345678.0009);
ADD_NBR_DECI(123456789.0);
ADD_NBR_DECI(123456789);
ADD_NBR_DECI(12345678);
ADD_NBR_DECI(1234567);
ADD_NBR_DECI(123456);
ADD_NBR_DECI(12345);
ADD_NBR_DECI(1234);
ADD_NBR_DECI(123);
ADD_NBR_DECI(12);
ADD_NBR_DECI(1);
ADD_NBR_DECI(123450006789);
ADD_NBR_DECI(12340005678);
ADD_NBR_DECI(1234000567);
ADD_NBR_DECI(123000456);
ADD_NBR_DECI(12300045);
ADD_NBR_DECI(1200034);
ADD_NBR_DECI(120003);
ADD_NBR_DECI(10002);
ADD_NBR_DECI(1000);


#elif FLOAT_TO_TEST == 10

ADD_NBR_DECI(0x1.1118p+25);

ADD_NBR_DECI(123456.789);
ADD_NBR_DECI(123456789.0);
ADD_NBR_DECI(0.120003456789);
ADD_NBR_DECI(1.23400056789);
ADD_NBR_DECI(12.3450006789);
ADD_NBR_DECI(1234567.80009);
ADD_NBR_DECI(12345678.0009);
ADD_NBR_DECI(123456789.0);
ADD_NBR_DECI(123456789);
ADD_NBR_DECI(12345678);
ADD_NBR_DECI(12);
ADD_NBR_DECI(1);

ADD_NBR_DECI(123450006789);
ADD_NBR_BITS(0x800FFFFFFFFFFFFF);
ADD_NBR_BITS(0x800FFFFFFFFFFFFE);
ADD_NBR_BITS(0x000FFFFFFFFFFFFF);
ADD_NBR_BITS(0x000FFFFFFFFFFFFE);
ADD_NBR_BITS(0x8000000000000001);
ADD_NBR_BITS(0x8000000000000002);
ADD_NBR_BITS(0x0000000000000001);
ADD_NBR_BITS(0x0000000000000002);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFFF);
ADD_NBR_BITS(0xFFEFFFFFFFFFFFFE);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFFF);
ADD_NBR_BITS(0x7FEFFFFFFFFFFFFE);
ADD_NBR_BITS(0x8010000000000000);
ADD_NBR_BITS(0x8010000000000001);
ADD_NBR_BITS(0x0010000000000000);
ADD_NBR_BITS(0x0010000000000001);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFFF);
ADD_NBR_BITS(0xFFFFFFFFFFFFFFFE);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFFF);
ADD_NBR_BITS(0x7FFFFFFFFFFFFFFE);
ADD_NBR_BITS(0xFFF0000000000001);
ADD_NBR_BITS(0xFFF0000000000002);
ADD_NBR_BITS(0x7FF0000000000001);
ADD_NBR_BITS(0x7FF0000000000002);

ADD_NBR_BITS(0X0000000000000000);
ADD_NBR_BITS(0X8000000000000000);
ADD_NBR_BITS(0X7FF0000000000000);
ADD_NBR_BITS(0XFFF0000000000000);

ADD_NBR_BITS(0XFFFE0F8C54BE3134);
ADD_NBR_BITS(0X7FF32FEB4722FF5F);


ADD_NBR_BITS(0XF16B737306B4856E);
ADD_NBR_BITS(0X44932B2520A25A33);
ADD_NBR_BITS(0X1E49D252F1C3FD35);
ADD_NBR_BITS(0X94DB7D70B140B162);
ADD_NBR_BITS(0X5ABC87B9189A13AC);
ADD_NBR_BITS(0X6E6B91D58E77242D);
ADD_NBR_BITS(0X25CD86564041D039);
ADD_NBR_BITS(0X81D4C4E48B931124);
ADD_NBR_BITS(0XED31C28E158D1918);
ADD_NBR_BITS(0X3C9ACB87A2EADDF9);
ADD_NBR_BITS(0X9ADCDF802B17CBED);
ADD_NBR_BITS(0XF39308E9C8A2EB00);
ADD_NBR_BITS(0X4FB0FA8B6C256E2B);
ADD_NBR_BITS(0X8B30071AF3FA387F);
ADD_NBR_BITS(0X526A77BC6B5EBBC0);
ADD_NBR_BITS(0X63E7C429A548A4C4);
ADD_NBR_BITS(0X274A2896EF4F171C);
ADD_NBR_BITS(0XD88F62951A47C219);
ADD_NBR_BITS(0X8DAB305462A8E28C);
ADD_NBR_BITS(0X3057A426BC8312A5);
ADD_NBR_BITS(0X4C3796045E5843B1);
ADD_NBR_BITS(0X6594E9D905F95866);
ADD_NBR_BITS(0XA4D735DF4957D9E7);
ADD_NBR_BITS(0X38E08F3F181B8C4B);
ADD_NBR_BITS(0X4D3A2EB78BA23F46);
ADD_NBR_BITS(0X5BDEA1322243EC91);
ADD_NBR_BITS(0X9753E175E24FC9AD);
ADD_NBR_BITS(0X1059F181CFDBBF2C);
ADD_NBR_BITS(0XA61FB7E9BC5C2721);

ADD_NBR_BITS(0X0000000000000003);
ADD_NBR_BITS(0X00000000DC291997);
ADD_NBR_BITS(0X8000000000000D8F);
ADD_NBR_BITS(0X0000000000EA20C2);
ADD_NBR_BITS(0X0000000000000301);
ADD_NBR_BITS(0X800E1A6B652D06FE);
ADD_NBR_BITS(0X0000000000006B16);
ADD_NBR_BITS(0X8000001D75EA45F8);
ADD_NBR_BITS(0X000000009CD4E6DB);
ADD_NBR_BITS(0X800002DB2C81FE06);
ADD_NBR_BITS(0X000000000CB248A5);
ADD_NBR_BITS(0X000000001D34C05E);
ADD_NBR_BITS(0X00000FEEE04A5A2B);
ADD_NBR_BITS(0X000000000000006F);
ADD_NBR_BITS(0X8000000183C67E16);
ADD_NBR_BITS(0X800F432300F3B1A7);
ADD_NBR_BITS(0X0000020EE3C8C86B);
ADD_NBR_BITS(0X8000000008A2FE0A);
ADD_NBR_BITS(0X0003D19580C65B74);
ADD_NBR_BITS(0X0000000000000007);
ADD_NBR_BITS(0X8000000002AAD428);
ADD_NBR_BITS(0X000BDF425D31DC7B);
ADD_NBR_BITS(0X800D84DC56E2BA6B);
ADD_NBR_BITS(0X000000FDD3A7A85C);
ADD_NBR_BITS(0X8000000000000D11);
ADD_NBR_BITS(0X000001A14EB51AE1);
ADD_NBR_BITS(0X80000000ADA1D61B);
ADD_NBR_BITS(0X000000000006B7B4);
ADD_NBR_BITS(0X800000000C8BE14D);
#endif
	
#else
	numbers[0] = 0;
	numbers[1] = 1;
	numbers[2] = 2;
	numbers[3] = 3;
	numbers[4] = 4;
	numbers[5] = 5;
	numbers[6] = 6;
	numbers[7] = 7;
	numbers[8] = SCHAR_MAX + 1;
	numbers[9] = SCHAR_MAX - 0;
	numbers[10] = SCHAR_MAX - 1;
	numbers[11] = SCHAR_MAX - 2;
	numbers[12] = SCHAR_MAX - 3;
	numbers[13] = SCHAR_MAX - 4;
	numbers[14] = SCHAR_MAX - 5;
	numbers[15] = SCHAR_MAX - 6;
	numbers[16] = SCHAR_MAX - 7;
	numbers[17] = (NUM_TYPE)SHRT_MAX + 1;
	numbers[18] = SHRT_MAX - 0;
	numbers[19] = SHRT_MAX - 1;
	numbers[20] = SHRT_MAX - 2;
	numbers[21] = SHRT_MAX - 3;
	numbers[22] = SHRT_MAX - 4;
	numbers[23] = SHRT_MAX - 5;
	numbers[24] = SHRT_MAX - 6;
	numbers[25] = SHRT_MAX - 7;
	numbers[26] = (NUM_TYPE)LONG_MAX + 1;
	numbers[27] = LONG_MAX - 0;
	numbers[28] = LONG_MAX - 1;
	numbers[29] = LONG_MAX - 2;
	numbers[30] = LONG_MAX - 3;
	numbers[31] = LONG_MAX - 4;
	numbers[32] = LONG_MAX - 5;
	numbers[33] = LONG_MAX - 6;
	numbers[34] = LONG_MAX - 7;
	numbers[35] = (NUM_TYPE)LLONG_MAX + 1;
	numbers[36] = LLONG_MAX - 0;
	numbers[37] = LLONG_MAX - 1;
	numbers[38] = LLONG_MAX - 2;
	numbers[39] = LLONG_MAX - 3;
	numbers[40] = LLONG_MAX - 4;
	numbers[41] = LLONG_MAX - 5;
	numbers[42] = LLONG_MAX - 6;
	numbers[43] = LLONG_MAX - 7;
	numbers[44] = ULLONG_MAX - 0;
	numbers[45] = ULLONG_MAX - 1;
	numbers[46] = ULLONG_MAX - 2;
	numbers[47] = ULLONG_MAX - 3;
	numbers[48] = ULLONG_MAX - 4;
	numbers[49] = ULLONG_MAX - 5;
	numbers[50] = ULLONG_MAX - 6;
	numbers[51] = ULLONG_MAX - 7;
#endif
	precisions[0] = -5;
	precisions[1] = -4;
	precisions[2] = -3;
	precisions[3] = -2;
	precisions[4] = -1;
	precisions[5] = 0;
	precisions[6] = 1;
	precisions[7] = 2;
	precisions[8] = 3;
	precisions[9] = 4;
	precisions[10] = 5;
	precisions[11] = 6;
	precisions[12] = 7;
	precisions[13] = 8;
	precisions[14] = 9;
	precisions[15] = 10;
	precisions[16] = 11;
	precisions[17] = 12;
	precisions[18] = 13;
	precisions[19] = 14;
	precisions[20] = 15;
	precisions[21] = 16;
	precisions[22] = 17;
	precisions[23] = 18;
	precisions[24] = 19;
	precisions[25] = 20;
	precisions[26] = 21;
	precisions[27] = 22;
	precisions[28] = NULLIFIER;

	widths[0] = -22;
	widths[1] = -21;
	widths[2] = -20;
	widths[3] = -19;
	widths[4] = -18;
	widths[5] = -17;
	widths[6] = -16;
	widths[7] = -15;
	widths[8] = -14;
	widths[9] = -13;
	widths[10] = -12;
	widths[11] = -11;
	widths[12] = -10;
	widths[13] = -9;
	widths[14] = -8;
	widths[15] = -7;
	widths[16] = -6;
	widths[17] = -5;
	widths[18] = -4;
	widths[19] = -3;
	widths[20] = -2;
	widths[21] = -1;
	widths[22] = 0;
	widths[23] = 1;
	widths[24] = 2;
	widths[25] = 3;
	widths[26] = 4;
	widths[27] = 5;
	widths[28] = 6;
	widths[29] = 7;
	widths[30] = 8;
	widths[31] = 9;
	widths[32] = 10;
	widths[33] = 11;
	widths[34] = 12;
	widths[35] = 13;
	widths[36] = 14;
	widths[37] = 15;
	widths[38] = 16;
	widths[39] = 17;
	widths[40] = 18;
	widths[41] = 19;
	widths[42] = 20;
	widths[43] = 21;
	widths[44] = 22;
	widths[45] = NULLIFIER;

	flags[0] = "";
	flags[1] = " ";
	flags[2] = "0";
	flags[3] = "+";
	flags[4] = "-";
	flags[5] = "#";
	flags[6] = " 0";
	flags[7] = " +";
	flags[8] = "0+";
	flags[9] = " -";
	flags[10] = "0-";
	flags[11] = "+-";
	flags[12] = " #";
	flags[13] = "0#";
	flags[14] = "+#";
	flags[15] = "-#";
	flags[16] = "+-#";
	flags[17] = "0-#";
	flags[18] = " -#";
	flags[19] = "0+#";
	flags[20] = " +#";
	flags[21] = " 0#";
	flags[22] = "0+-";
	flags[23] = " +-";
	flags[24] = " 0-";
	flags[25] = " 0+";
	flags[26] = "0+-#";
	flags[27] = " +-#";
	flags[28] = " 0-#";
	flags[29] = " 0+#";
	flags[30] = " 0+-";
	flags[31] = " 0+-#";


	
} while (0);



writing_status = 0;
line_status = 0;
line1 = malloc(MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1); ft_memset(line1, 0, MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1);
line2 = malloc(MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1); ft_memset(line2, 0, MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1);
line3 = malloc(MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1); ft_memset(line3, 0, MAX_CHARS_PER_LINE + BONUS_CHARS_PER_LINE + 1);




char *curformat;
char *cusstr = malloc(NEW_STRLEN);
char *refstr = malloc(NEW_STRLEN);
int		cusret;
int		refret;
int		specifier_isstring;
char *forstrings = malloc(sizeof(NUM_TYPE) + 1);
forstrings[sizeof(NUM_TYPE)] = '\0';

failed = 0;
passed = 0;

ft_strcpy(line1, "FMT ");
ft_strcpy(line2, "REF ");
ft_strcpy(line3, "CUS ");

fla = 0;
while (fla <= 31)
{
	writing_status += printf("%5.1f%%", (double)(((double)fla) * 100 / 32)); fflush(stdout);
	wid = 0;
	while (widths[wid] != DELIMITER)
	{
		pre = 0;
		while (precisions[pre] != DELIMITER)
		{
			nbr = 0;
			while (numbers[nbr] != DELIMITER)
			{
				ft_memset(cusstr, 0, NEW_STRLEN);
				ft_memset(refstr, 0, NEW_STRLEN);
				
				if (specifier_isstring = (NEW_SPECIFIERS[(int)ft_strlen(NEW_SPECIFIERS) - 1] == 's'))
					ft_memcpy(forstrings, &numbers[nbr], sizeof(NUM_TYPE));
				
				
				#define CALL_FUNCTIONS(ARG1, ARG2, ARG3) { cusret = ft_sprintf(cusstr, curformat, ARG1, ARG2, ARG3); \
				refret = sprintf(refstr, curformat, ARG1, ARG2, ARG3); }

/* 				qprintf("===>%.1e\n", numbers[nbr]); */
/* 				qprintf("===>%.1f\n", numbers[nbr]); */
/* 				qprintf("===>%.1e SALUT\n", numbers[nbr]); */
				
				if (widths[wid] == NULLIFIER && precisions[pre] == NULLIFIER)
				{
					curformat = build_cur_format(flags[fla], 0, 0, NEW_SPECIFIERS);
					if (specifier_isstring)
						CALL_FUNCTIONS(forstrings, 0, 0)
					else
						CALL_FUNCTIONS(numbers[nbr], 0, 0)
				}
				else if (widths[wid] == NULLIFIER)
				{
					curformat = build_cur_format(flags[fla], 0, 1, NEW_SPECIFIERS);
					if (specifier_isstring)
						CALL_FUNCTIONS(precisions[pre], forstrings, 0)
					else
						CALL_FUNCTIONS(precisions[pre], numbers[nbr], 0)
				}
				else if (precisions[pre] == NULLIFIER)
				{
					curformat = build_cur_format(flags[fla], 1, 0, NEW_SPECIFIERS);
					if (specifier_isstring)
						CALL_FUNCTIONS(widths[wid], forstrings, 0)
					else
						CALL_FUNCTIONS(widths[wid], numbers[nbr], 0)
				}
				else
				{
					curformat = build_cur_format(flags[fla], 1, 1, NEW_SPECIFIERS);
					if (specifier_isstring)
						CALL_FUNCTIONS(widths[wid], precisions[pre], forstrings)
					else
						CALL_FUNCTIONS(widths[wid], precisions[pre], numbers[nbr])
				}
				

/* 				qprintf("===>%.1e OUT\n", numbers[nbr]); */
					// cusret = ft_sprintf(cusstr, curformat, widths[wid], precisions[pre], forstrings);
					// refret = sprintf(refstr, curformat, widths[wid], precisions[pre], forstrings);

					// cusret = ft_sprintf(cusstr, curformat, widths[wid], precisions[pre], numbers[nbr]);
					// refret = sprintf(refstr, curformat, widths[wid], precisions[pre], numbers[nbr]);

				
				save_results(curformat, refstr, cusstr, refret, cusret, widths[wid], precisions[pre]);
				nbr++;
			}
			
			pre++;
			// break;
			// goto stopall;
		}
			
		wid++;
		// break;
	}
	
	fla++;
	// break;
}

// stopall:
flush_lines(0);
printf("\n");
printf("Results for: [%%%s]", NEW_SPECIFIERS);
printf("\n");

#define MALLOC_SIZE_BIS 200000
write_in_lines("TOTAL_: ", "PASSED: ", "FAILED: ", 0, 0);
char* temp1;
char* temp2;
char* temp3;
temp1 = malloc(MALLOC_SIZE_BIS);
temp2 = malloc(MALLOC_SIZE_BIS);
temp3 = malloc(MALLOC_SIZE_BIS);

char* temp10;
char* temp20;
char* temp30;
temp10 = malloc(MALLOC_SIZE_BIS);
temp20 = malloc(MALLOC_SIZE_BIS);
temp30 = malloc(MALLOC_SIZE_BIS);

sprintf(temp1, "%07u", passed + failed);
sprintf(temp2, "%07u", passed);
sprintf(temp3, "%07u", failed);
ft_strcat(line1, temp1);
ft_strcat(line2, temp2);
ft_strcat(line3, temp3);
flush_lines(0);

printf("\n");
if (failed == 0)
	return ;
int perc;
int tempret;
int sum;
i = 0;
write_in_lines("prec: ", "fail: ", "%%%%: ", 0, 0);
while (precisions[i] != DELIMITER)
{
	perc = preci_results[i] * 100 / failed;

	sum = sprintf(temp10, "%d|", precisions[i]);
	tempret = sprintf(temp20, "%u|", preci_results[i]);
	sum = sum >= tempret ? sum : tempret;
	tempret = sprintf(temp30, "%.1u%%|", perc);
	sum = sum >= tempret ? sum : tempret;
	sum++;
	sprintf(temp1, "%*s", sum, temp10);
	sprintf(temp2, "%*s", sum, temp20);
	sprintf(temp3, "%*s", sum, temp30);

	if ((int)ft_strlen(line1) + (int)ft_strlen(temp1) > MAX_CHARS_PER_LINE)
	{
		flush_lines(0);
		write_in_lines("prec: ", "fail: ", "%%%%: ", 0, 0);
	}
	if (perc > 50)
		ft_strcat(line3, "\033[35m");
	else if (perc > 10)
		ft_strcat(line3, "\033[35m");
	else if (perc > 0)
		ft_strcat(line3, "\033[36m");
	else
		ft_strcat(line3, "\033[34m");
		
	ft_strcat(line1, temp1);
	ft_strcat(line2, temp2);
	ft_strcat(line3, temp3);
	ft_strcat(line3, "\033[39m");
	
	i++;
}
flush_lines(0);
printf("\n");

i = 0;
write_in_lines("widt: ", "fail: ", "%%%%: ", 0, 0);
while (widths[i] != DELIMITER)
{
	perc = width_results[i] * 100 / failed;

	sum = sprintf(temp10, "%d|", widths[i]);
	tempret = sprintf(temp20, "%u|", width_results[i]);
	sum = sum >= tempret ? sum : tempret;
	tempret = sprintf(temp30, "%.1u%%|", perc);
	sum = sum >= tempret ? sum : tempret;
	sum++;
	sprintf(temp1, "%*s", sum, temp10);
	sprintf(temp2, "%*s", sum, temp20);
	sprintf(temp3, "%*s", sum, temp30);

	if ((int)ft_strlen(line1) + (int)ft_strlen(temp1) > MAX_CHARS_PER_LINE)
	{
		flush_lines(0);
		write_in_lines("widt: ", "fail: ", "%%%%: ", 0, 0);
	}
	
	if (perc > 50)
		ft_strcat(line3, "\033[35m");
	else if (perc > 10)
		ft_strcat(line3, "\033[35m");
	else if (perc > 0)
		ft_strcat(line3, "\033[36m");
	else
		ft_strcat(line3, "\033[34m");
		
	ft_strcat(line1, temp1);
	ft_strcat(line2, temp2);
	ft_strcat(line3, temp3);
	ft_strcat(line3, "\033[39m");
	
	i++;
}
flush_lines(0);
printf("\n");

i = 0;
write_in_lines("numb: ", "fail: ", "%%%%: ", 0, 0);
while (numbers[i] != DELIMITER)
{
	perc = nbrs_results[i] * 100 / failed;

	// sum = sprintf(temp10, (char*)ft_strjoin(READER_FMT, "|"), numbers[i]);
	sum = sprintf(temp10, READER_FMT, numbers[i]);
	tempret = sprintf(temp20, "%u|", nbrs_results[i]);
	sum = sum >= tempret ? sum : tempret;
	tempret = sprintf(temp30, "(%d)%.1u%%|", i, perc);
	sum = sum >= tempret ? sum : tempret;
	sum++;
	sprintf(temp1, "%*s", sum, temp10);
	sprintf(temp2, "%*s", sum, temp20);
	sprintf(temp3, "%*s", sum, temp30);

	if ((int)ft_strlen(line1) + (int)ft_strlen(temp1) > MAX_CHARS_PER_LINE)
	{
		flush_lines(0);
		write_in_lines("numb: ", "fail: ", "%%%%: ", 0, 0);
	}
	
	if (perc > 50)
		ft_strcat(line3, "\033[35m");
	else if (perc > 10)
		ft_strcat(line3, "\033[35m");
	else if (perc > 0)
		ft_strcat(line3, "\033[36m");
	else
		ft_strcat(line3, "\033[34m");
		
	ft_strcat(line1, temp1);
	ft_strcat(line2, temp2);
	ft_strcat(line3, temp3);
	ft_strcat(line3, "\033[39m");
	
	i++;
}
flush_lines(0);
printf("\n");


i = 0;
write_in_lines("flag: ", "fail: ", "%%%%: ", 0, 0);
while (i < 32)
{
	perc = flags_results[i] * 100 / failed;

	sum = sprintf(temp10, "%s|", flags[i]);
	tempret = sprintf(temp20, "%u|", flags_results[i]);
	sum = sum >= tempret ? sum : tempret;
	tempret = sprintf(temp30, "%.1u%%|", perc);
	sum = sum >= tempret ? sum : tempret;
	sum++;
	sprintf(temp1, "%*s", sum, temp10);
	sprintf(temp2, "%*s", sum, temp20);
	sprintf(temp3, "%*s", sum, temp30);

	if ((int)ft_strlen(line1) + (int)ft_strlen(temp1) > MAX_CHARS_PER_LINE)
	{
		flush_lines(0);
		write_in_lines("numb: ", "fail: ", "%%%%: ", 0, 0);
	}
	
	if (perc > 50)
		ft_strcat(line3, "\033[35m");
	else if (perc > 10)
		ft_strcat(line3, "\033[35m");
	else if (perc > 0)
		ft_strcat(line3, "\033[36m");
	else
		ft_strcat(line3, "\033[34m");
		
	ft_strcat(line1, temp1);
	ft_strcat(line2, temp2);
	ft_strcat(line3, temp3);
	ft_strcat(line3, "\033[39m");
	
	i++;
}
flush_lines(0);
printf("\n");

i = 0;
write_in_lines("flag: ", "fail: ", "%%%%: ", 0, 0);
while (i < 5)
{
	perc = singleflags_results[i] * 100 / failed;

	sum = sprintf(temp10, "[%c|", CHARS_FLAGS_BIS[i]);
	tempret = sprintf(temp20, "%u|", singleflags_results[i]);
	sum = sum >= tempret ? sum : tempret;
	tempret = sprintf(temp30, "%.1u%%|", perc);
	sum = sum >= tempret ? sum : tempret;
	sum++;
	sprintf(temp1, "%*s", sum, temp10);
	sprintf(temp2, "%*s", sum, temp20);
	sprintf(temp3, "%*s", sum, temp30);

	if ((int)ft_strlen(line1) + (int)ft_strlen(temp1) > MAX_CHARS_PER_LINE)
	{
		flush_lines(0);
		write_in_lines("numb: ", "fail: ", "%%%%: ", 0, 0);
	}
	
	if (perc > 50)
		ft_strcat(line3, "\033[35m");
	else if (perc > 10)
		ft_strcat(line3, "\033[33m");
	else if (perc > 0)
		ft_strcat(line3, "\033[36m");
	else
		ft_strcat(line3, "\033[34m");
		
	ft_strcat(line1, temp1);
	ft_strcat(line2, temp2);
	ft_strcat(line3, temp3);
	ft_strcat(line3, "\033[39m");
	
	i++;
}
flush_lines(0);
printf("\n");


printf("love");
printf("love");
printf("love");
printf("love");
printf("love");




free(temp1);
free(temp2);
free(temp3);

flush_lines(0);

// free(cusstr);
// free(refstr);
}


#endif


#if BONUS_TESTS == 1


void	do_my_tests(void)
{
	char	*refstr, *cusstr;
	
	char	*save_malloc_1, *save_malloc_2;
	int		refret, cusret, i;
	unsigned int u;
// [d%-18d][j%-18jd][z%-18zd][t%-18td][L%-18Ld]\n[h%-18hd][l%-18ld][hh%-18hhd][ll%-18lld]\n\
// [d%-18u][j%-18ju][z%-18zu][t%-18tu][L%-18Lu]\n[h%-18hu][l%-18lu][hh%-18hhu][ll%-18llu]\n\


	cusstr = save_malloc_1 = (char*)malloc(sizeof(char) * MALLOC_SIZE * 100);
	refstr = save_malloc_2 = (char*)malloc(sizeof(char) * MALLOC_SIZE * 100);
	

	

/*
!
$
' '
#
0

!$
!' '
!#
!0

$' '
$#
$0

' '#
' '0

!$' '
!$#
!$0

!' '#
!' '0
!#0

$' '#
$' '0
' '#0
*/

// 0	turn '\letter' into code
// !	don't use colors
// $	turn "$\n" into '\\n'
// SPACE	turn "\t" into '\\t'
// #	hide prexixes such as '\\d' and '\\x'

// %zS	Code control et meta + couleur si besoin
// %S	Code hexa + couleur si besoin
// %lS	Code decimal + couleur si besoin

// printf("%u\n", COLORS_FLAGS_FIELD2);
// printf("%u\n", COLORS_FLAGS_FIELD);

#define FT_REF sprintf
#define FT_CUS ft_sprintf
	
#define FORMAT__ \
"%sLigne1: :red:SALUT:yel:CON:cya:DE:whi:TOI:lig:TOI:eoc:c'est:eoc:presque:eoc:fini:eoc:lol?:eol:FIN:eof:\n\
%s:bla::lig:Ligne2: :GRE:SALUT:YEL:CON:CYA:DE:WHI:TOI:LIG:TOI:eob:c'est:eob:presque:eob:fini:eob:lol?:eoc::eol::eoL:FIN\n\
%sLigne3: :cya: salut \e[35m les :eoc: amis. :eoc: FIN\n\
%sLigne4: :CYA: salut \e[45m les :eob: amis. :eob: FIN\n\
%sLigne5: :gre:>:RED:%$.27r:eob:<:eob::eoc: FIN\n\
%sLigne6: :und: salut \e[46m les :eob: amis. :eou: FIN\n\
%sLigne7: :und: %d %lld %hhd :RED:%-+0# 9d:eob: :RED:%-+0# 9d:eob: :RED:%0# 9d:eob::eou: FIN\n\
%sLigne8: %UMs, %Rd, %MNOPQRr, %UPc FIN\n\
\
%sLine99: tests \\0: (%.21r)(%c)  (%5c)  (%-5c)  (%-.5c) %s FIN\n\
"

// #define TRUCS "\
// \n\t[%s]test:(%c)reussi?\
// "


// #define TRUCS2 \
// "salope _\a_\b_\f_\v_\r_\e_\x7F_\x8F_\xDF_\t_\n_c'est la fin", \
// '\0'~

#define ARGUMENTS__ \
":BLU:    :eob:", ":RED:        :eob:", ":GRE:    :eob:", ":CYA:    :eob:", ":WHI:    :eob:", "Sa \v lu \t co \x9F me \0 nt \n CA",\
":CYA:    :eob:", \
":CYA::LIG:    :eob::eoL:", 18, 18LL, 18, 12584, -12584, 12584,\
":RED::LIG:    :eob::eoL:", "salut", -1258455, "lol \v \1 minifin", 'a', \
\
":RED:    :eob:", "\e[46m \v \t \x9F \0 minifin", '\0', '\0', '\0', '\0', "fin"


#define PT(CODE) "\e["#CODE"m"


#define TESTLOL(CODE) printf("%02sTEST:"PT(CODE)"TEST1"PT(28)"TEST2"PT(0)"_RETOUR?\n", #CODE)


// printf("Salut %s. T'as %d ans\n%X %hhu %o %23a %c %s %10% \n", "Nicolas", 10, 800, (char)200, 800, 18.958416, 'Q', "saj");


// fflush(stdout);

// exit(0);

// 
// printf("%08s  |  ne garde (en 0) que les doubles 0\n", ft_itoa_a(i | j, 2));
// printf("%08s  ^  ne garde (en 0) que les doubles 1 et les doubles 0\n", ft_itoa_a(i ^ j, 2));


// printf("test"PT(0)"test"PT(1)"test"PT(2)"test"PT(3)"test"PT(4)"test"PT(5)"test"PT(6)"test"PT(7)"test"PT(8)"test"PT(9)"test"PT(10)"test"PT(11)"test"PT(0)"test\n");

// exit(0);
// for (u = 0; u < 257; u++)
	// printf("%3hhd:'%c'\n", u, u);
	
	
	char	*strREPRINT = (char*)malloc(sizeof(char) * MALLOC_SIZE * 100);
	int		retREPRINT;
	// printf("%p\n", strREPRINT);
	// printf("%s\n", strREPRINT);
	// retREPRINT = ft_sprintf(strREPRINT, "lol");
	// printf("%p\n", strREPRINT);
	// printf("%s\n", strREPRINT);
	// exit(0);
	
	ft_putstr("\n\nCUSTOM:");
	cusret = FT_CUS(cusstr, FORMAT__, ARGUMENTS__);
	printf("\n-_-_-_-_-_-_-_-_putnchar:CUSTOM-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_[%d]\n", cusret); fflush(stdout);
	ft_myputnchar(cusstr, cusret); 
	printf("\n-_-_-_-_-_-_-_-_  printf:CUSTOM-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n%s", cusstr); fflush(stdout);
	cusret++;
	retREPRINT = FT_CUS(strREPRINT, "% *r", cusret, cusstr);
	printf("\n-_-_-_-_-_-_-_-_  REPRINT AVEC ft_sprintf(\"%% *r\"): CUSTOM-_-_-_-_-_-_-_-_-[%d]\n%s\n", retREPRINT, strREPRINT); fflush(stdout);
	printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	
	ft_putstr("\n\n");
	
	ft_putstr("REFERENCE:");
	refret = FT_REF(refstr, FORMAT__, ARGUMENTS__);
	printf("[%d]\n-_-_-_-_-_-_-_-_putnchar:REFERENCE-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n", refret); fflush(stdout);
	ft_myputnchar(refstr, refret); 
	printf("\n-_-_-_-_-_-_-_-_  printf:REFERENCE-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n%s\n", refstr); fflush(stdout);
	printf("\e[0m\e[21m\e[22m\e[24m\e[25m\e[27m\e[28m\e[39m\e[49m"); fflush(stdout);
	printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");

	
	ft_myassert(refret == cusret);
	
	
	ft_myassert(!memcmp(refstr, cusstr, (cusret > refret ? cusret : refret) + 1));
	ft_putendl("");	
	
	int k = 1;
	printf("%2d  \e[%d;%dmtest\e[0m c%d b%d\n", k++, 36, 41, 36, 41);
	printf("%2d  \e[%d;%dmtest\e[0m c%d b%d\n", k++, 30, 42, 30, 42);
	printf("%2d  \e[%d;%dmtest\e[0m c%d b%d\n", k++, 31, 43, 31, 43);
	printf("%2d  \e[%d;%dmtest\e[0m c%d b%d\n", k++, 37, 44, 37, 44);
	printf("%2d  \e[%d;%dmtest\e[0m c%d b%d\n", k++, 34, 45, 34, 45);
	printf("%2d  \e[%d;%dmtest\e[0m c%d b%d\n", k++, 35, 46, 35, 46);
	
	printf("test,%c,%c,\',%s,", '\'', 39, "\'");
}

#endif




















