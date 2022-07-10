#include <stddef.h>
void	ft_bzero(void *s, size_t n)
{
	char	*buf;

	buf = (char *)s;
	while (n--)
		*buf++ = 0;
}
