#ifndef LIBFT_H
#define LIBFT_H

//消す
#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);



#endif
