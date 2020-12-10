/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:20:18 by razaha            #+#    #+#             */
/*   Updated: 2020/12/10 12:12:51 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include "../cube.h"

int		g_window_width;
int		g_window_height;
char	*g_notxt;
char	*g_sotxt;
char	*g_wetxt;
char	*g_eatxt;
char	*g_sprit;
int		g_fcol;
int		g_ccol;
char	**g_map;
size_t	g_cols;
size_t	g_rows;
int		g_num_sp;

void	ft_fill_map(char *ptr);
void	ft_check_map(void);
void	ft_fill_floorciel_color(char *line);
void	ft_fill_resolution(char *line);
void	ft_textu(char c, char c2, char *line);
void	ft_check_elements(void);
int		ft_puterror(char *error);
char	*ft_trim_spaces(char *s);
void	ft_free(char **s);
void	ft_check_comma(char *s);
#endif
