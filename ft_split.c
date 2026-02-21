#include "push_swap.h"

static int	word_count(char const *str, char c)
{
	int	i;
	int	counter;
	int	in_word;

	i = 0;
	counter = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
			in_word = 0;
		else if (str[i] != c && in_word == 0)
		{
			in_word = 1;
			counter++;
		}
		i++;
	}
	return (counter);
}

static char	*add_word(char const *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static	void	*ft_free(char **arr, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**spliting(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			arr[j] = add_word(s, start, i);
			if (!arr[j])
				return (ft_free(arr, j));
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	return (spliting(arr, s, c));
}