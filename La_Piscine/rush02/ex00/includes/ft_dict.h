/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:49:21 by minjacho          #+#    #+#             */
/*   Updated: 2023/08/06 15:24:41 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H

# include <stdlib.h>

typedef struct s_dict
{
	char	key[11];
	char	*value;
}	t_dict;

void	init_dict(t_dict *dict);
int		is_valid_key(char *key, t_dict *dict);
int		add_val(char *key, char *value, t_dict *dict);
char	*get_value(char *key, t_dict *dict);
void	print_three(long long nbr, t_dict *dict);
void	print_whole(char *num, t_dict *dict);
char	*int_to_char(char *key, int num);

#endif
