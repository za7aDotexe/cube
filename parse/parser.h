/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:20:18 by razaha            #+#    #+#             */
/*   Updated: 2020/11/24 20:12:40 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H_
# define PARSER_H_

# include "../libft.h"

char	**g_map;
int		num_sp;
int		get_next_line(int fd, char **line);
void    ft_fill_map(char *ptr, int g_rows, int g_cols);
void    ft_check_map(int g_rows, int g_cols);
void	ft_fill_floorciel_color(char *line);
void    ft_fill_resolution(char *line);
void	ft_textu(char c, char c2, char *line);
void     ft_check();
void    ft_check_elements();
int	    ft_puterror(char *error);

#endif

