#include <stdio.h>

main()
{
	int   year, month, day;
	float x, y;
	char  buff[256];

	printf("今日の年月日をスペースで区切って入力してください：");

	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d %d %d", &year, &month, &day);
	printf("%d年%d月%d日\n", year, month, day);

	printf("今日の年月日を yyyy-mm-dd のように入力してください：");

	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d-%d-%d", &year, &month, &day);
	printf("%d年%d月%d日\n", year, month, day);

	printf("実数x, yをスペースで区切って入力してください：");

	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%g %g",&x, &y);
	printf("%g + %g = %g\n", x, y, x + y);

	printf("実数x, yを x, y のように入力してください：");

	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%g, %g",&x, &y);
	printf("%g + %g = %g\n", x, y, x + y);

	return(0);
}
