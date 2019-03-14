/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 23:28:21 by khou              #+#    #+#             */
/*   Updated: 2019/03/13 19:35:35 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	error_usage()
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	exit(0);
}

void	err_cmd(char *str)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", str);
	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
	ft_printf("Cipher commands:\n\n");
	exit(0);	
}

int		hash_grab_flag(char c, t_hash_flag *flag)
{
	if (c == 'p')
		flag->p = true;
	else if (c == 'q')
		flag->r = true;
	else if (c == 'r')
		flag->r = true;
//	else if (c == 's')
//		flag->s = true;
	else
		return (-1);
	return (1);
}

int		general_flag(t_hash_flag *flag,int argc, char **argv)
{
//----init--------------------
	flag->md5 = false;
	flag->sha256 = false;
	flag->p = false;
	flag->q = false;
	flag->r = false;
	flag->s = false;
//----validate----------------
	argc < 2 ? error_usage() : 0;
	if (!ft_strcmp("md5", argv[1]))
		flag->md5 = true;
	else if (!ft_strcmp("sha256", argv[1]))
		flag->sha256 = true;
	else
		err_cmd(argv[1]);
	int	i = 2;
	if (!argv[i])
	{
		ft_printf("ready for reading in from stdin\n");
		exit(0);
	}
	while (i < argc && argv[i][0] == '-')
	{
		!argv[i][1] ?
			ft_printf("%s: -: No such file or directory\n", argv[1]) : 0;
		while (*(++argv[i]))
		{
			if (*argv[i] == 's')
			{
				ft_printf("In general flag meets s\n");
				++argv[i];
				return (i);
			}
			else if (hash_grab_flag(*argv[i], flag) < 0)
			{
				ft_printf("%s: illegal option -- %c\nusage: \
%s [-pqr] [-s string] [files ...]\n", argv[1], *argv[i], argv[1]);
				exit(0);
			}
		}
		i++;		
	}
	return(--i);
}

//hash_init(t_hash)

int		main(int argc, char **argv)
{
	t_hash	hash;
	int	i;

//	hash_init(&hash);
//-- error management for argv ----
	i = general_flag(&hash.flag, argc, argv);//move the pointer of argv
	if (*argv[i])
		ft_printf("argv[%i]: %s\n", i, argv[i]);
	else
	{
		ft_printf("end of the argv");
		exit (0);
	}
	/*
	while (*argv[i])
	{
//		hash_on();//deal with -s 'str' and file
		i++;
		}*/
	
	return (0);
}
