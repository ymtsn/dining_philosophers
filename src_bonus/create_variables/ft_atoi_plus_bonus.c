/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_plus_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:26:25 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/02 20:44:18 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

static int	ft_isspace(char c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi_plus(const char *str)
{
	size_t	buf;

	buf = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (0);
		str++;
	}
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
	{
		buf = buf * 10 + (*str++ - '0');
		if (buf > INT_MAX)
			return (INT_MAX);
	}
	if (*str)
		return (0);
	return ((int)buf);
}
