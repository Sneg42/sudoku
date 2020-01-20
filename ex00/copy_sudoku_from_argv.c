/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_sudoku_from_argv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddvorove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:29:06 by ddvorove          #+#    #+#             */
/*   Updated: 2020/01/19 20:30:37 by ddvorove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**copy_sudoku_from_argv(char **argv)
{
	int		col;
	int		i;
	char	**matrix;

	i = -1;
	matrix = (char **)malloc(sizeof(char *) * 9);
	while (++i < 9)
	{
		col = -1;
		matrix[i] = (char *)malloc(sizeof(char) * 10);
		while (++col < 9)
			matrix[i][col] = argv[i + 1][col];
	}
	return (matrix);
}
