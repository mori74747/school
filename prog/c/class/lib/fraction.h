typedef struct {
    int numerator;   // 分子
    int denominator; // 分母
} Fraction;

Fraction getFraction(void);
Fraction frcCreate(int numerator, int denominator);
Fraction frcAdd(Fraction x, Fraction y);
Fraction frcSub(Fraction x, Fraction y);
Fraction frcMul(Fraction x, Fraction y);
Fraction frcDiv(Fraction x, Fraction y);
Fraction frcReduction(Fraction x);
int frcGetNumerator(Fraction x);
int frcGetDenominator(Fraction x);
void frcPrint(Fraction x);