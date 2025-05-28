#include "../includes/cub3d.h"

static bool is_dir(char *arg)
{
	int fd;
	bool is_dir;
	is_dir = false;
	fd = open(arg, O_DIRECTORY);
	if (fd != -1)
	{
		is_dir = true;
		close(fd);
	}
	else
	{
		close(fd);
	}
	return (is_dir);
}

static bool is_cub_file(char *arg)
{
	int i;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '.')
		{
			if (ft_strncmp(arg + i, ".cub", 4) == 0)
				return (true);
		}
		i++;
	}
	return (false);
}

int check_map_file(char *arg, bool cub)
{
	int fd;

    if (is_dir(arg))
    {
        printf("Error\n%s: Is a directory\n", arg);
        return (1);
    }
	fd = open(arg, O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n%s: No such file or directory\n", arg);
        return (1);
    }
    if(cub && !is_cub_file(arg))
    {
        printf("Error\n%s: Invalid file extension\n", arg);
        close(fd);
        return (1);
    }
    return (SUCCESS);
}
