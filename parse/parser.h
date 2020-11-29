/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:20:18 by razaha            #+#    #+#             */
/*   Updated: 2020/11/29 12:15:35 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft.h"

char	**g_map;
int		g_num_sp;

void	ft_fill_map(char *ptr, int g_rows, int g_cols);
void	ft_check_map(int g_rows, int g_cols);
void	ft_fill_floorciel_color(char *line);
void	ft_fill_resolution(char *line);
void	ft_textu(char c, char c2, char *line);
void	ft_check_elements(void);
int		ft_puterror(char *error);
char	*ft_trim_spaces(char *s);
void	ft_free(char **s);
#endif
