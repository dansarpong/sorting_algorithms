#include "sort.h"

/**
 * swap - swap two elements in an array
 * @pos1: first position
 * @pos2: second position
*/
void swap(int *pos1, int *pos2)
{
	int temp = *pos1;
	*pos1 = *pos2;
	*pos2 = temp;
}
