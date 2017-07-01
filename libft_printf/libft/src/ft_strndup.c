#include "libft.h"

char	*ft_strndup(const char *s1, char c)
{
	char	*str;
	int		len;

	len = 0;
	while (s1[len] != c && s1[len])
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str = ft_strncpy(str, s1, len);
	return (str);
}
