/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:32:22 by khou              #+#    #+#             */
/*   Updated: 2019/03/14 10:33:46 by khou             ###   ########.fr       */
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

void	hash_init(t_hash *hash)
{
	hash->flag.md5 = false;
	hash->flag.sha256 = false;
	hash->flag.p = false;
	hash->flag.q = false;
	hash->flag.r = false;
	hash->flag.s = false;
}

void	cmd_flag(t_hash_flag *flag, int argc, char **argv)
{
	argc < 2 ? error_usage() : 0;
	if (!ft_strcmp("md5", argv[1]))
		flag->md5 = true;
	else if (!ft_strcmp("sha256", argv[1]))
		flag->sha256 = true;
	else
		err_cmd(argv[1]);
}
