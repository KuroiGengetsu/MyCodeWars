#include <stdio.h>
#include <stdbool.h>


bool chess_board_cell_color(const char* cell1, const char *cell2)
{
    return (cell1[0]%2) ^ (cell1[1]%2) == (cell2[0]%2) ^ (cell2[1]%2);
}
