打印出1000以内的所有的 "水仙花数 "，所谓 "水仙花数 "是指一个三位数，其各位数字立方和等于该数本身。

例如：153是一个 "水仙花数 "，因为153 = 1的三次方＋5的三次方＋3的三次方。

#include <stdio.h>
main()
{
	int a, b, c, i;
	for (i = 0; i<1000; i++)
	{
		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;
		if (i = a**3 + b**3 + c**3)
			printf("%d", i)
	}
}