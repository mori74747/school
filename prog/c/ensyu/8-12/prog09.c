#include <stdio.h>
#include <hamakou.h>

double sCombResistance(double r1, double r2);
/*-----sCombResistance()-----
２つの抵抗値から、直列合成抵抗を返す
[引　数] r1, r2は抵抗値
[戻り値] r1, r2の直列合成抵抗: r0
-----------------------------*/
double pCombResistance(double r1, double r2);
/*-----pCombResistance()-----
２つの抵抗値から、並列合成抵抗を返す
[引　数] r1, r2は抵抗値
[戻り値] r1, r2の並列合成抵抗: r0
-----------------------------*/

main(){

	// 抵抗値を設定
	double R1 = 15;
	double R2 = 20;
	double R3 = 35;

	// 合成抵抗の演算・出力(有効桁数:3桁)
	double R0 = sCombResistance(R1, pCombResistance(R2, R3));
	printf("%.3g\n",R0);

	return(0);
}

double sCombResistance(double r1, double r2){

	double r0 = r1 + r2;
	return (r0);
}

double pCombResistance(double r1, double r2){

	double r0 = (r1 * r2) / (r1 + r2);
	return (r0);
}