/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:22:45 by apaget            #+#    #+#             */
/*   Updated: 2016/01/28 19:47:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/includes/libft.h"
# define LL 2
# define L 1
# define H 3
# define HH 4
# define Z 5
# define J 6

typedef struct			s_data
{
	char				*drapeau; // 'rien' '-' '+' ' ' '#'
	int					length; // nombre de char a afficher
	int					nb_len;
	int					comp;
	int					precision; // des nombre
	char				modificateur; //long ou pas
	char				type; // 'd' 'p' 's' 'o' 'i' etc
	void				*data;
}						t_data;

char		*load_conf(char *str, t_data *data);
char		*apply_diezzz(t_data *data, char *str);
void		debug_print_conf(t_data *data);
char		*get_unsigned_integer(long long int number, int base,char sep);
char		*get_char(char c);
char		get_type(char **str);
char		*get_drapeau(t_data *data,char **str);
int			get_str(long long int number, int base, int i);
char		*get_float(t_data *data, float number);
int			get_precision(char **str);
char		get_modificateur(char **str);
char		*get_ptr(void *ptr);
char		*get_integer(long long int number,int base, char sep);
int			get_length(char **str, t_data *data);
char		*ft_itoa_base(long long int number, int base, char sep);
char		*get_var(t_data *data, va_list *list);
int			get_str_len_of_num(unsigned long long int number, int base);
int			power_base(long long int nb, int power,long long int nbsave);
char		*apply_length(t_data *data, char *str);
char		*apply_precision(t_data *data, char *str);
char		*apply_flag(t_data *data, char *str);
void		fill_empty_data(t_data *data);
void		init_data(t_data *data);
int			make_str(t_data *data, va_list *list);
void		psuh_right(t_data *data, char *str, char *new);
void		ft_putwchar_t(wchar_t c);
void		ft_putwstr(wchar_t *str);
wchar_t		*ft_wstr_new(int length);
int			ft_wstrlen(wchar_t *str);
wchar_t		*apply_wprecision(t_data *data, wchar_t *str);
int			make_wwwwwwstr(t_data *data, va_list *list);
int			isintab(char *tab, char c);
void		*les_flics(t_data *data, char *str);
char		*ft_unsigned_itoa_base(unsigned long long int number, int base, char sep);
int			get_unsigned_str(unsigned long long int number, int base, int i);
char		*get_signed_var(t_data *data, va_list *list);
void		addtotab(char *tab, char c);
void		make_wchar(t_data *data, va_list *list);
char		*get_unsigned_var(t_data *data, va_list *list);

#endif
