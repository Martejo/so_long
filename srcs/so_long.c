#include "../include/so_long.h"

void	check_args(int argc, char **argv)
{
	int	pos;

	if (argc != 2)
		ft_error("Error\nThis programe take 1 argument '.ber'\n", NULL);
	pos = ft_strlen(argv[1]) - 4;
	if (ft_strcmp(&argv[1][pos], ".ber") != 0)
		ft_error("Error\nWrong file extension.\n", NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int exit = 0;
	int stuff = 0;

	data.map = NULL;
	check_args(argc, argv);
	set_content(&data.content);
	set_map(&data, argv[1]);
	check_map(&data);
	printf("pos player_X = %d et Y = %d\n", data.player.col_player, data.player.line_player);
	bool **visited = malloc(data.height * sizeof(bool *));
	for (int i = 0; i < data.height; i++) {
    	visited[i] = calloc(data.width, sizeof(bool));
}
	if (backtracking(&data, &exit, &stuff, data.player.col_player, data.player.line_player) == true)
		printf("YEEEAHH\n");
	else
		printf("FUCCCK\n");
	for (int i = 0; data.map[i]; i++)
		printf("%s\n", data.map[i]);
	for (int i = 0; data.map[i]; i++)
		free(data.map[i]);
	free(data.map);
	return (0);
}