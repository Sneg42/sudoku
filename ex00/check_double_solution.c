/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_souble_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddvorove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:28:33 by ddvorove          #+#    #+#             */
/*   Updated: 2020/01/19 20:35:45 by ddvorove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		solve_sudoku(char **matrix, int row, int col);
char	**copy_sudoku_from_argv(char **argv);

int		check_double_solution(char **matrix, char **argv)
{
	char	**matrix2;
	int		row;
	int		col;

	row = -1;
	matrix2 = copy_sudoku_from_argv(argv);
	while (++row < 9)
	{
		col = -1;
		while (++col < 9)
		{
			if (matrix2[row][col] == '.')
			{
				matrix2[row][col] = matrix[row][col] + 1;
				row = 9;
				col = 9;
			}
		}
	}
	return (solve_sudoku(matrix2, 0, 0));
}
