

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	size_t s_len;
	size_t new_len;
	size_t i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len< len)
		len = new_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
		substr[i++] = s[start++];
	return (substr);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *new_str;
	size_t s1_len;
	size_t s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (s1 ? ft_strdup(s1) : ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcpy(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *new_str;
	size_t start;
	size_t end;

	start = 0;
	while (s1[start] && s1[start] == *set)
		start++;
	end = ft_strlen(s1);
	while (end && s1[end] == *set)
		end--;
	if (start >= end)
		return (ft_strdup(""));
	new_str = ft_substr(s1, start, end - start);
	return (new_str);
}
