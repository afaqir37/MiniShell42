/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:59:59 by agoujdam          #+#    #+#             */
/*   Updated: 2023/10/14 02:42:26 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_returnfetch(t_data **data, char *buffer)
{
	char	*pwd;

	if (buffer)
		free(buffer);
	pwd = ft_strdup((*data)->path);
	return (pwd);
}

char	*ft_returnpwd(t_data **data)
{
	char	*buffer;
	int		i;

	i = pathconf(".", _PC_PATH_MAX);
	if (!i || i == -1)
	{
		perror("Pathconf: ");
		g_exit_status = 1;
		return (NULL);
	}
	buffer = malloc(sizeof(char) * i);
	if (!buffer)
	{
		perror("Malloc: ");
		free(buffer);
		g_exit_status = 1;
		return (NULL);
	}
	if (!getcwd(buffer, i) || !buffer[0])
		buffer = ft_returnfetch(data, buffer);
	return (buffer);
}

void	ft_pwd(t_data **data, int fd)
{
	char	*buffer;
	int		i;

	i = pathconf(".", _PC_PATH_MAX);
	if (!i || i == -1)
	{
		perror("Pathconf: ");
		g_exit_status = 1;
		return ;
	}
	buffer = malloc(sizeof(char) * i);
	if (!buffer)
	{
		perror("Malloc: ");
		free(buffer);
		g_exit_status = 1;
		return ;
	}
	if (!getcwd(buffer, i) || !buffer[0])
		buffer = ft_returnfetch(data, buffer);
	g_exit_status = 0;
	ft_putstr_fd(buffer, fd);
	ft_putchar_fd('\n', fd);
	free(buffer);
}
