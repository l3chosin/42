/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:39:39 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/21 12:54:03 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int a);
char	ft_strchr(char *str, int c);
int		ft_strlcat(char *dst, char *src, int size);
int		ft_strlcpy(char *dst, char *src, int size);
int		ft_strlen(char *tab);
int		ft_strncmp(char *s1, char *s2, int n);
char	ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);

#endif
