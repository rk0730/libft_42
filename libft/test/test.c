#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	str[] = "abcdefg";
	memcpy(&(str[2]), str, 3);
	printf("%s\n", str);
	return (0);
}
