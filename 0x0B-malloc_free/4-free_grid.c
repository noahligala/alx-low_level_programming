#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2D grid created by alloc_grid.
 * @grid: pointer to the 2D array of integers.
 * @height: height of the grid of integers.
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
