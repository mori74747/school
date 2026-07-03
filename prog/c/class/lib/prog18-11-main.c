#include <stdio.h>
#include "fraction.h"


void frcPrintOperation(char op, Fraction x, Fraction y);

main()
{
    Fraction a, b, c;
    int i;
    char op[] = "+-*/";

    // 2つの分数をキーボードより入力する
    printf("a: ");
    a = getFraction();
    printf("b: ");
    b = getFraction();

    if (frcGetDenominator(a) * frcGetDenominator(b) == 0) {
        printf("分母が0です\n");
    } else {
        // 分数a, bに対して、四則演算を実行する
        for (i = 0; op[i] != '\0'; i++) {
            frcPrintOperation(op[i], a, b); // 四則演算の結果表示
        }
        putchar('\n'); // 見やすくするために改行
    }

    return(0);
}

// 分数xと分数yに、2項演算(x op y)を実行した結果を表示する
//   [引　数] op   : 2項演算子（+, -, *, /)
//            x, y : 演算対象となる分数 
//   [表示例] 1/2 + 1/4 = 3/4
void frcPrintOperation(char op, Fraction x, Fraction y)
{
    Fraction a;

    switch (op) {
    case '+':
        a = frcAdd(x, y); break;
    case '-':
        a = frcSub(x, y); break;
    case '*':
        a = frcMul(x, y); break;
    case '/':
        a = frcDiv(x, y); break;
    default:
        printf("%c: 演算子が不正です。\n", op);
        return;
    }
    a = frcReduction(a);
    frcPrint(x); printf(" %c ", op); frcPrint(y); printf(" = "); frcPrint(a);
    putchar('\n');

    return;
}
