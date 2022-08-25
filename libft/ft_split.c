/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:45:00 by vjean             #+#    #+#             */
/*   Updated: 2022/05/10 11:34:02 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_count_word(char const *s, char limite)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s == limite)
			s++;
		if (*s != limite && *s)
			words++;
		while (*s != limite && *s)
			s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	words = ft_count_word(s, c);
	tab = ft_calloc(sizeof(char *), (words + 1));
	i = -1;
	if (!tab)
		return (NULL);
	while (++i < words)
	{
		while (*s && *s == c)
			s++;
		if (ft_strchr(s, c))
			len = ft_strchr(s, c) - s;
		else
			len = ft_strlen(s);
		tab[i] = ft_substr(s, 0, len);
		s += len;
	}
	return (tab);
}
