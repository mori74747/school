#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hamakou.h"

int getint(char *msg)
{
    char buf[256];
    int val;

    printf("%s", msg);
    fgets(buf, sizeof(buf), stdin);
    val = atoi(buf);

    return val;
}

// ダミー実装（使わない関数のエラー回避用）
int GetString(char *msg, char *str, int size)
{
    printf("%s", msg);
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
    return strlen(str);
}

int getcharacter(char *msg)
{
    char buf[256];
    printf("%s", msg);
    fgets(buf, sizeof(buf), stdin);
    return buf[0];
}

double getfloat(char *msg)
{
    char buf[256];
    printf("%s", msg);
    fgets(buf, sizeof(buf), stdin);
    return atof(buf);
}

void timer(int t) {}
char *itoa(int x) { static char b[64]; sprintf(b,"%d",x); return b; }
char *ftoa(float x){ static char b[64]; sprintf(b,"%f",x); return b; }
char *dtoa(double x){ static char b[64]; sprintf(b,"%lf",x); return b; }
int bit_check(char *s){ return 1; }
unsigned int bit2int(char *s){ return strtoul(s,NULL,2); }
char *int2bit(unsigned int d){ static char b[64]; memset(b,'0',63); b[63]='\0'; return b; }
void echo(char *s){}
void keybuff(char *s){}
double timecount(char *s){ return 0.0; }
