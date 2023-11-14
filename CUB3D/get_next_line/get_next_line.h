/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:25:01 by otelliq           #+#    #+#             */
/*   Updated: 2023/10/04 19:59:35 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

char	*get_next_line(int fd);
char	*get_first_line(char *s);
char	*get_rest_line(char *s);
char	*ft_read_line(int fd, char *s);
int		ft_strlenn(char *s);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_strchrr(char *str, char c);
#endif
