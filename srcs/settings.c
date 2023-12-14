#include "../include/so_long.h"

void	set_content(t_content *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->empty = '0';
	content->collect = 'C';
	content->count_collect = 0;
	content->count_exit = 0;
	content->count_player = 0;
}

