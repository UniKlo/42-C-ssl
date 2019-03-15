/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:13:05 by khou              #+#    #+#             */
/*   Updated: 2019/03/15 13:41:43 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	err_obj(char *cmd, char *file)
{
	ft_printf("%s: %s: No such file or directory\n", cmd, file);
}

void	hash_file(t_hash * hash, char *cmd, char *file)
{
	int		fd;
	char	buffer[BUFF_SIZE + 1];
	int		ret = 0;
	char	*tmp;

	ft_printf("BUFF_SIZE: %d\n", BUFF_SIZE);
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		err_obj(cmd, file);
		return ;
	}
	if (read(fd, buffer, 0) < 0)
		return ;

	hash->len_org = 0;	
	hash->content = ft_strnew(0);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		printf("buff: %s", buffer);//file has new line
		tmp = hash->content;
		hash->content = ft_strjoin(hash->content, buffer);
		free(tmp);
		hash->len_org += ret;
	}
	
	ft_printf("len in char: %d\ncontent: \"\n%s\"", hash->len_org, hash->content);
	close(fd);
	


}
