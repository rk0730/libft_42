#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	// haystackにnull文字が来たらそこで打ち切る
	// haystackのlen文字目以降は見ない
	//方針
	// len以内かつnull文字でない　というループ
	//ループ内でまずフラグを立て、最後まで一致していなかったらフラグを折る（memcmp使う）
	//フラグが立っていたら結果をreturn 最後までいったらnullをreturn (size_t i = 0);
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen((char *)needle);
	while (haystack[i] && i + needle_len <= len)
	{
		if (ft_memcmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
