// #include <X11/Xfuncproto.h>

#define getstring(msg, str) GetString((msg), (str), sizeof((str)))
// #define difftime(t1, t2) (double)(((time_t)(t2) - (time_t)(t1)))


//_XFUNCPROTOBEGIN

// extern double difftime(long, long);
extern int GetString(char *, char *, int);	//  文字列入力関数
extern int getcharacter(char *);		//  １文字入力関数
extern double getfloat(char *);			//  浮動小数点数入力関数
extern int getint(char *);			//  整数入力関数
extern void timer(int);				//  ディレイタイマー
extern char *itoa(int);				// 数値を表す文字列への変換（int型） 
extern char *ftoa(float);			// 数値を表す文字列への変換（float型）
extern char *dtoa(double);			// 数値を表す文字列への変換（double型）
extern int bit_check(char *string);		//  ２進数を表す文字列かどうかをチェックする
extern unsigned int bit2int(char *string);	//  与えられた２進数文字列を整数値に変換する
extern char *int2bit(int unsigned int_dat);	//  与えられた整数値を２進数文字列に変換する
extern void echo(char *);			//  エコーバックの制御
extern void keybuff(char *);			//  キーバッファリングの制御
extern double timecount(char *);		//  実行時間の計測

//_XFUNCPROTOEND
