/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:45 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/07/18 10:58:57 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void	ft_bzero(void *s, size_t n)
{
	char	*buf;

	buf = (char *)s;
	while (n)
	{
		*buf++ = 0;
		n--;
	}
}