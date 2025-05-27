/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:39:39 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/21 16:44:30 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *str, int c);
void	*ft_calloc(size_t num, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int a);
char	*ft_itoa(int n);
void	*ft_memchr(const void *str, int ch, int n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_memset(void *str, int value, int n);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlcat(char *dst, char *src, size_t size);
int		ft_strlcpy(char *dst, char *src, int size);
int		ft_strlen(const char *tab);
int		ft_strncmp(char *s1, char *s2, int n);
char	ft_strnstr(char *haystack, char *needle, int size);
char	*ft_strrchr(char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
