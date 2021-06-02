#include "../minirt.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_new_strchr(const char *s, int c)
{
	char	*dst;
	size_t	i;

	if (c == 0 && *s == 0)
		return ((char *)s);
	i = 0;
	while (s[i] != c)
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			dst[i] = s[i];
			i++;
		}
		if (s[i] == c)
			break ;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_mod_strchr(const char *s, int c)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
			i++;
		if (s[i] == c)
			break ;
	}
	if (s[i] != c)
		return (NULL);
	i++;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!tmp)
		return (NULL);
	while (s[i])
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	if (c == 0 && *s == 0)
		return ((char *)s);
	return (tmp);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
