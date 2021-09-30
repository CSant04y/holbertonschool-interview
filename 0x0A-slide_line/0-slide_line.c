#include "slide_line.h"

/**
 * slide_line - Merges either left or right based on if numbers are
 * identical, contigious, or seperated by zeros.
 * @line: pointer to array of integers
 * @size: size of the array of integers
 * @direction: boolean 0 for it going left and 1 for it going right
 * Return: return 1 on success and 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t tmp, bool = 0, pos1 = 0, pos2 = 1, itr, itr2;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	pos1 = (direction == SLIDE_RIGHT) ? size - 1 : pos1;
	pos2 = (direction == SLIDE_RIGHT) ? size - 2 : pos2;

	for (itr = 0; itr < size; itr++)
	{       tmp = pos2;
		bool = 0;
		for (itr2 = itr + 1; itr2 < size; itr2++)
		{
			if (line[pos1] != 0 && line[pos2] == line[pos1])
			{	line[pos1] = line[pos1] * 2;
				line[pos2] = 0;
				break; }

			if (line[pos1] == 0 && line[pos2] != 0)
			{	line[pos1] = line[pos2];
				line[pos2] = 0;
				bool = 1;
				pos2 = tmp;
				itr--;
				break; }

			if (line[pos2] != 0)
				break;
			direction == SLIDE_LEFT ? pos2++ : pos2--;
		}
		if (line[pos1] == 0)
			break;
		if (bool == 0)
		{	pos1 = (direction == SLIDE_LEFT) ? pos1 + 1 : pos1;
			pos1 = (direction == SLIDE_RIGHT) ? pos1 - 1 : pos1;
			pos2 = (direction == SLIDE_LEFT) ? pos1 + 1 : pos2;
			pos2 = (direction == SLIDE_RIGHT) ? pos1 - 1 : pos2; }
	}
	return (1);
}
