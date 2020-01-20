/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddvorove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:58:14 by ddvorove          #+#    #+#             */
/*   Updated: 2020/01/19 19:52:58 by ddvorove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_horiz(char numb, char **matrix, int row)
{
	int col;

	col = -1;
	while (++col < 9)
	{
		if (matrix[row][col] == numb)
			return (0);
	}
	return (1);
}

int		check_vert(char numb, char **matrix, int col)
{
	int row;

	row = -1;
	while (++row < 9)
	{
		if (matrix[row][col] == numb)
			return (0);
	}
	return (1);
}

int		check_squar(char numb, char **matrix, int row, int col)
{
	int r;
	int c;
	int r2;
	int c2;

	r = 3 * (row / 3) - 1;
	c = 3 * (col / 3) - 1;
	r2 = r + 4;
	c2 = c + 4;
	while (++r < r2)
	{
		c = 3 * (col / 3) - 1;
		while (++c < c2)
		{
			if (matrix[r][c] == numb)
				return (0);
		}
	}
	return (1);
}

int		is_valid(char numb, char **matrix, int row, int col)
{
	int hor;
	int ver;
	int sq;

	hor = check_horiz(numb, matrix, row);
	ver = check_vert(numb, matrix, col);
	sq = check_squar(numb, matrix, row, col);
	return (hor && ver && sq);
}

int		solve_sudoku(char **matrix, int row, int col)
{
	char	numb;

	numb = '0';
	if (row == 9)
		return (1);
	if (matrix[row][col] != '.')
	{
		if (col == 8)
			if (solve_sudoku(matrix, row + 1, 0))
				return (1);
		if (col < 8)
			if (solve_sudoku(matrix, row, col + 1))
				return (1);
		return (0);
	}
	while (++numb <= '9')
	{
		if (is_valid(numb, matrix, row, col))
		{
			matrix[row][col] = numb;
			if (col == 8)
				if (solve_sudoku(matrix, row + 1, 0))
					return (1);
			if (col < 8)
				if (solve_sudoku(matrix, row, col + 1))
					return (1);
		}
		matrix[row][col] = '.';
	}
	return (0);
}
