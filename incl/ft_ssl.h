/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 23:26:11 by khou              #+#    #+#             */
/*   Updated: 2019/03/15 13:34:58 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/include/printf.h"
# include "../libft/include/libft.h"

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct	s_hash_flag
{
	bool	md5;
	bool	sha256;
	bool	p;
	bool	q;
	bool	r;
	bool	s;
	
}	t_hash_flag;

typedef	struct	s_hash
{
	t_hash_flag	flag;
	int		len_org;
	char	*content;
	
}t_hash;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
void    hash_init(t_hash *hash);
void    cmd_flag(t_hash_flag *flag, int argc, char **argv);
void	hash_file(t_hash *hash, char *cmd, char *file);

#endif
