/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:42:40 by razaha            #+#    #+#             */
/*   Updated: 2020/11/26 18:24:58 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

unsigned char g_header[54] = { 0 };

void	ft_bitmap_create(unsigned char *buf, uint32_t imagesize)
{
	int				fd;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
	if (fd == -1)
		return ;
	write(fd, g_header, 54);
	write(fd, buf, imagesize);
	close(fd);
	free(buf);
}

void	ft_bitmap_calc(uint32_t imagesize, int32_t width, int32_t height,
int width_in_bytes)
{
	char			*add;
	unsigned char	*buf;
	int				row;
	int				col;
	int				i;
	int				sl;

	add = mlx_get_data_addr(g_threed_img, &row, &sl, &i);
	row = height - 1;
	buf = malloc(imagesize);
	while (row >= 0)
	{
		col = 0;
		while (col < width)
		{
			i = col * 4 + sl * (height - 1 - row);
			buf[row * width_in_bytes + col * 3 + 0] = add[i];
			buf[row * width_in_bytes + col * 3 + 1] = add[i + 1];
			buf[row * width_in_bytes + col * 3 + 2] = add[i + 2];
			col++;
		}
		row--;
	}
	ft_bitmap_create(buf, imagesize);
}

void	ft_screenshot(int32_t width, int32_t height, uint16_t bitcount,
int width_in_bytes)
{
	uint32_t			imagesize;
	const uint32_t		bisize = 40;
	const uint32_t		bfoffbits = 54;
	uint32_t			filesize;
	const uint16_t		biplanes = 1;

	width = g_window_width;
	height = g_window_height;
	bitcount = 24;
	width_in_bytes = ((width * bitcount + 31) / 32) * 4;
	imagesize = width_in_bytes * height;
	filesize = 54 + imagesize;
	ft_memcpy(g_header, "BM", 2);
	ft_memcpy(g_header + 2, &filesize, 4);
	ft_memcpy(g_header + 10, &bfoffbits, 4);
	ft_memcpy(g_header + 14, &bisize, 4);
	ft_memcpy(g_header + 18, &width, 4);
	ft_memcpy(g_header + 22, &height, 4);
	ft_memcpy(g_header + 26, &biplanes, 2);
	ft_memcpy(g_header + 28, &bitcount, 2);
	ft_memcpy(g_header + 34, &imagesize, 4);
	ft_bitmap_calc(imagesize, width, height, width_in_bytes);
	exit(EXIT_SUCCESS);
}
