/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:12:15 by minjacho          #+#    #+#             */
/*   Updated: 2023/08/06 15:24:22 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include <unistd.h>

int		ft_is_printable(char *str);
int		ft_char_in_str(char c, char *charset);
char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int size);
char	*ft_strncat(char *dest, char *src, unsigned int size);
char	*ft_strdup(char *src);
int		get_char_idx_str(char c, char *str);
char	*ft_strip(char *str);
char	*ft_strip_i(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
int		check_numeric(char c);

#endif
