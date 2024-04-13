#include "libft.h"

//dstとsrcがかぶっていてもちゃんと移動しているように見える　memcpyより有能
// 一度どこかのbufferに保存したあとにコピーしていく
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	//lenが大きい場合はエラー処理　とりあえずnullを返すが、正解はどうしたらいいのかわかんない
	//destがlenに足りない場合はエラー
	//srcが足りない場合は気にしなくていい

	//方針
	//destの長さをft_strlenで数え、足りない場合はエラー
	//足りる場合はlenの大きさのbufferを作り、そこにmemcpyしていく
	//そのあとbufferからdstにmemcpyしていく

	unsigned char	tmp[len];

	if (len > ft_strlen(dst))
		return (NULL);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	return (dst);
}
