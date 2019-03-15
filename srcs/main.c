/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 23:28:21 by khou              #+#    #+#             */
/*   Updated: 2019/03/15 13:34:41 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		hash_grab_flag(t_hash_flag *flag, char c)
{
	if (c == 'p')
		flag->p = true;
	else if (c == 'q')
		flag->r = true;
	else if (c == 'r')
		flag->r = true;
	else
		return (0);//(-1);
	return (1);
}

int		main(int argc, char **argv)
{
	t_hash	hash;
	int	i;

	hash_init(&hash);
	cmd_flag(&hash.flag, argc, argv);
	i = 2;
	while (i < argc)
	{
		while (i < argc && argv[i][0] == '-')
		{
			if (!argv[i][1])
			{
				while (i < argc)
				{
//					ft_printf("is '%s' a file?\n", argv[i]);
					hash_file(&hash, argv[1], argv[i]);
					i++;
				}
			}
			else
			{
				if (!hash_grab_flag(&hash.flag, *(++argv[i])))//need to + first
					{
						ft_printf("%s: illegal option -- %c\nusage: \
%s [-pqr] [-s string] [files ...]\n", argv[1], *argv[i], argv[1]);
						exit(0);
					}
				ft_printf("flag.s = %d, argv[%i]: %s\n", hash.flag.s, i, argv[i]);
				i++;
			}
			ft_printf("ready to find a file\n");
		}
		if (!argv[i])
			exit (0);
		hash_file(&hash, argv[1], argv[i]);
		i++;
	}
		return (0);
}
/*
int		general_flag(t_hash_flag *flag,int argc, char **argv)
{
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
				flag->s = true;
//				ft_printf("In general flag meets 's' flag\n");
				if (*(argv[i] + 1))
				{
					
					++argv[i];
//					hash_str();
					printf("%s\n", argv[i]);
					i++;
					//does not work with ft_ssl md5 -sfoo felw -sfoo
				}
				else
				{
					i++;
					return (i);
				}
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

*/
	/*
	i = general_flag(&hash.flag, argc, argv);//move the pointer of argv
	ft_printf("flag.s = %d, argv[%i]: %s\n", hash.flag.s, i, argv[i]);
	if (!*argv[i] && hash.flag.s && !hash.flag.p)
	{
		ft_printf("%s: option requires an argument -- s\nusage: \
%s [-pqr] [-s string] [files ...]\n", argv[1], argv[1]);
		exit (0);
	}
	if (!*argv[i])
	{
		ft_printf("ready for reading in from stdin\n");
        exit(0);
	}
	while (i < argc)
	{
		ft_printf("flag.s = %d, argv[%i]: %s\n", hash.flag.s, i, argv[i]);
		if (hash.flag.s)
		{
//			hash_str();
			hash.flag.s = false;
		}
		else
			;//hash_files();//deal with -s 'str' and file
		if (argv[i][0] == '-' && argv[i][1] == 's')
		{
				hash.flag.s = true;
		}
			
		i++;
	}
	*/
