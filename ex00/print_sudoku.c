/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddvorove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:37:48 by ddvorove          #+#    #+#             */
/*   Updated: 2020/01/19 20:38:13 by ddvorove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_sudoku(char **matrix)
{
	int row;
	int col;

	row = -1;
	while (++row < 9)
	{
		col = -1;
		while (++col < 9)
		{
			write(1, &((matrix[row][col])), 1);
			if (col != 8)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}
