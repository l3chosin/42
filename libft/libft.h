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

int		ft_atoi(const char *str);
void	ft_bzero(void *str, size_t c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int a);
void	*ft_memchr(const void *str, int ch, int n)
void	ft_memset(void *str, int value, int n);
char	ft_strchr(char *str, int c);
int		ft_strlcat(char *dst, char *src, int size);
int		ft_strlcpy(char *dst, char *src, int size);
int		ft_strlen(char *tab);
int		ft_strncmp(char *s1, char *s2, int n);
char	ft_strnstr(char *haystack, char *needle, int size);
char	*ft_strrchr(char *str, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
