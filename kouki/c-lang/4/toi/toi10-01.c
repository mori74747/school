#include <stdio.h>

main()
{
	int hourFirst, minFirst;  // 開始時刻
	int hourLast,  minLast;   // 終了時刻
	int totalMin;             // 経過時間(分)
	int totalSec;             // 経過時間(秒)

	// 入力
	printf("時刻 = ");
	scanf("%d:%d %d:%d", &hourFirst, &minFirst, &hourLast, &minLast);

	printf("%d:%dから%d:%dまでは、", hourFirst, minFirst, hourLast, minLast);
	printf("%d分または%d秒経過しています。\n", totalMin, totalSec);

	return (0);
}