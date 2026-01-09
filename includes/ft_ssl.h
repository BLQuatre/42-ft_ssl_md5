#ifndef FT_SSL_H
# define FT_SSL_H

# include <unistd.h>
# include <stdlib.h>
# include <libgen.h>

size_t ft_strlen(const char *msg);
void *ft_memcpy(void *dest, const void *src, size_t n);
void ft_write(int fd, char *msg);
int ft_strncmp(const char *s1, const char *s2, size_t n);

// TEMP DEV
# include <stdio.h>
void print_hex_dump(const unsigned char *data, size_t len, int bytes_per_line);

#endif
