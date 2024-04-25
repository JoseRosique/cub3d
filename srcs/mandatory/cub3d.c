/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:15:57 by joslopez          #+#    #+#             */
/*   Updated: 2023/12/30 17:29:36 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arguments(int argc, char **argv)
{
	if (argc > 3)
	{
		ft_putstr("Error\nToo many arguments");
		return (1);
	}
	if (argc < 2)
	{
		ft_putstr("Error\nNot enough arguments");
		return (1);
	}
	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		{
			ft_putstr("Error\nFirst argument is not a .cub file");
			return (1);
		}
	}
	return (0);
}

int	launch_environment(t_arg variables)
{
	t_env	environment;

	if (variables.fcounter == 0 || variables.ccounter == 0)
	{
		ft_putstr("Error\nProblem with Floor or Ceil");
		return (0);
	}
	if (extra_map_check(variables.map) != 0)
		return (1);
	if (check_map(variables.map) != 0)
		return (1);
	else
	{
		environment = start_environment(variables);
		events(environment);
	}
	return (0);
}

int	check_not_empty(char *buffer, t_arg *variables, int tmp)
{
	if ((ft_strchr("NSWE1FC", buffer[0]) && !ft_strchr(" ", buffer[0])) \
		|| tmp == 2)
	{
		if (!ft_strlen(buffer))
			return (2);
		if (tmp == 2)
		{
			ft_putstr("Error\nEmpty line in map");
			return (1);
		}
		variables->linecounter++;
	}
	if (ft_strlen(&buffer[0]) <= 0 && variables->linecounter >= 7)
		return (2);
	if (buffer && ft_strlen(&buffer[0]))
	{
		if (check_identifier(variables, buffer) != 0)
		{
			free(buffer);
			return (1);
		}
	}
	free(buffer);
	return (0);
}

int	read_and_process_file(int ret, int fd, t_arg *variables)
{
	char	*buffer;
	int		tmp;

	tmp = 0;
	while (1)
	{
		buffer = NULL;
		ret = get_next_line(fd, &buffer);
		tmp = check_not_empty(buffer, variables, tmp);
		if (tmp != 0 && tmp != 2)
		{
			return (1);
			break ;
		}
		if (ret <= 0)
			break ;
	}
	if (ret == -1)
	{
		ft_putstr("Error\nCould not complete file reading");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_arg	variables;

	ft_bzero(&variables, sizeof(variables));
	if (check_arguments(argc, argv) != 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\nCould not open the file");
		return (0);
	}
	if (read_and_process_file(0, fd, &variables) != 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (launch_environment(variables) != 0)
		return (0);
	return (0);
}
