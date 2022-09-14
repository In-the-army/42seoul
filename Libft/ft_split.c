#include "libft.h"

size_t ft_cntword(char const *s, char c)
{
	size_t cnt;
	size_t flag;

	cnt = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			cnt++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (cnt);
}

size_t ft_wordlen(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char* ft_strndup(char const *s, size_t wordlen)
{
	char *word;
	size_t i;

	word = (char *)malloc(sizeof(char) * (wordlen + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < wordlen)
	{
		word[i++] = *s;
		s++;
	}
	word[i] = '\0';
	return (word);
}

void ft_free_all(char **result, size_t cnt)
{
	size_t i;

	i = 0;
	while (i < cnt)
		free(result[i++]);
	free(result);
}

char **ft_split(char const *s, char c)
{
	char **result;
	size_t cnt;
	size_t wordlen;
	size_t i;

	if (!s)
		return (NULL);
	cnt = ft_cntword(s, c);
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		if (*s && *s == c)
			s++;
		wordlen = ft_wordlen(s, c);
		result[i] = ft_strndup(s, wordlen);
		if (!result[i])
		{
			ft_free_all(result, i);
			return (NULL);
		}
		s += wordlen;
		i++;
	}
	result[i] = NULL;
	return (result);
}
