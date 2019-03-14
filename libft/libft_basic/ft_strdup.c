/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 22:29:42 by khou              #+#    #+#             */
/*   Updated: 2018/09/22 16:35:22 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(char const *s)
{
	char	*ret;

	ret = (char *)ft_strnew(ft_strlen(s) * sizeof(char));
	return (ret ? ft_strcpy(ret, s) : NULL);
}
