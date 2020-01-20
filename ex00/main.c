/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myMain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddvorove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:17:47 by ddvorove          #+#    #+#             */
/*   Updated: 2020/01/19 20:39:16 by ddvorove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		solve_sudoku(char **matrix, int row, int col);
char	**copy_sudoku_from_argv(char **argv);
int		check_double_solution(char **matrix, char **argv);
void	print_sudoku(char **matrix);
void	ft_putstr(char *str);

int		main(int argc, char **argv)
{
	char	**matrix;
	int		fst_sol;
	int		sec_sol;

	matrix = copy_sudoku_from_argv(argv);
	fst_sol = solve_sudoku(matrix, argc - argc, 0);
	sec_sol = check_double_solution(matrix, argv);
	if (fst_sol == 1 && fst_sol != sec_sol)
		print_sudoku(matrix);
	else
		ft_putstr("Error\n");
	return (0);
}
