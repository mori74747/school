#include <stdio.h>
#include <string.h>
#include <hamakou.h>

#define STUDENT_LIMIT   100  // 生徒数上限
#define GRADE           7    // 度数分布の段階数
#define MAX_NAME_SIZE   20   // 姓と名それぞれの文字数上限
#define PERFECT_SCORE   100  // １教科あたりの上限スコア
#define SUBJECT_SIZE    3    // 試験の教科数

#define BUFF_SIZE       1024 // 入力バッファサイズ

typedef struct {
    char   Name[MAX_NAME_SIZE*2+2];   // 名前を格納する文字配列
    int    TestData[SUBJECT_SIZE+2];  // テストデータを格納する配列 [0]:国語 [1]:数学 [2]:英語 [3]:合計 [4]:順位
}Exam;

void  setName(Exam *student, char name1[], char name2[]);
char *getName(Exam *student, char name[]);
void  setSubjectScore(Exam *student, int sbj, int score);
int   getSubjectScore(Exam *student, int sbj);
int   getScoreSum(Exam *student);
void  setRank(Exam *student, int rank);
int   getRank(Exam *student);

int  readStudentsData(Exam students[]);
void calcRanking(Exam students[], int n);
void countTimes(Exam students[], int histogram[], int n);
void printSeiseki(Exam students[], int n);
void printHistogram(int histogram[]);

void calcSum(Exam students[], int n);

main()
{
    int n, histogram[GRADE] = {};     // 度数分布の段階はGRADE個
    Exam students[STUDENT_LIMIT];     // 全生徒のデータ

    // 全生徒のデータを読み込み、生徒数を取得する
    n = readStudentsData(students);
    // 順位を求める
    calcRanking(students, n);
    // 度数分布を集計する
    countTimes(students, histogram, n);
    // 成績一覧を生徒番号順に表示
    printSeiseki(students, n);
    // 度数分布を表示する
    printHistogram(histogram);

    return(0);
}

/*-------------------------------------------------------------*/
/*                            アクセサー                        */
/*-------------------------------------------------------------*/

/*---------------------------------------------------------------
[機　能] name1とname2からなる氏名を指定した生徒に格納する
[引　数] student      : 氏名を格納する生徒一人分のデータを指すポインタ
[　　　] name1, name2 : 姓、名　または　FirstName, LastName
[戻り値] なし
---------------------------------------------------------------*/
void setName(Exam *student, char name1[], char name2[]){

    // 文字列nameを用意
    char name[MAX_NAME_SIZE*2+2];

    // A.1 姓をコピー
    strcpy(name, name1);
    // A.2 空白追加
    strcat(name, " ");
    // A.3 名を追加
    strcat(name, name2);

    // A.4 student.Nameへ格納
    strcpy(student->Name, name);

    return;
}

/*---------------------------------------------------------------
[機　能] 指定した生徒のデータから、氏名をnameに取り出す
[引　数] student      : 氏名を取り出す生徒一人分のデータを指すポインタ
[　　　] name         : 取り出した氏名を格納する文字配列
[戻り値] 取り出した氏名を指す文字列へのポインタ（すなわちnameそのもの）
---------------------------------------------------------------*/
char *getName(Exam *student, char name[]){

    // nameへstudent.Nameを格納
    strcpy(name, student->Name);
    return(name);
}

/*---------------------------------------------------------------
[機　能] 指定した生徒に、科目番号sbjの科目の得点scoreを格納する
[引　数] student      : 得点を格納する生徒一人分のデータを指すポインタ
[　　　] sbj          : 対象科目の科目番号（0:国語, 1:数学, 2:英語）
[　　　] score        : 科目番号sbjの科目の得点
[戻り値] なし
---------------------------------------------------------------*/
void  setSubjectScore(Exam *student, int sbj, int score){

    // student.TestData[科目番号]にscoreを格納
    student->TestData[sbj] = score;

    return;
}

/*---------------------------------------------------------------
[機　能] 指定した生徒のデータから科目番号sbjの科目の得点scoreを取得する
[引　数] student      : 得点を取り出す生徒一人分のデータを指すポインタ
[　　　] sbj          : 対象科目の科目番号（0:国語, 1:数学, 2:英語）
[戻り値] 生徒studentの科目番号sbjの科目の得点
---------------------------------------------------------------*/
int getSubjectScore(Exam *student, int sbj){
    return(student->TestData[sbj]);
}

/*---------------------------------------------------------------
[機　能] 指定した生徒のデータから、全科目の合計得点を取得する
[引　数] student      : 得点を取り出す生徒一人分のデータを指すポインタ
[戻り値] 全科目の合計得点
---------------------------------------------------------------*/
int getScoreSum(Exam *student){
    return(student->TestData[SUBJECT_SIZE]);
}

/*---------------------------------------------------------------
[機　能] 指定した生徒に、合計得点に基づく順位rankを格納する
[引　数] student      : 順位を格納する生徒一人分のデータを指すポインタ
[　　　] rank         : 合計得点に基づく順位
[戻り値] なし
---------------------------------------------------------------*/
void setRank(Exam *student, int rank){
    student->TestData[SUBJECT_SIZE+1] = rank;
}

/*---------------------------------------------------------------
[機　能] 指定した生徒のデータから、合計得点に基づく順位を取得する
[引　数] student      : 順位を取り出す生徒一人分のデータを指すポインタ
[戻り値] 合計得点に基づく生徒studentの順位
---------------------------------------------------------------*/
int getRank(Exam *student){
    return(student->TestData[SUBJECT_SIZE+1]);
}

/*-------------------------------------------------------------*/
/*                            操作関数                          */
/*-------------------------------------------------------------*/

/*---------------------------------------------------------------
[機　能] 全生徒のデータを読み込み、生徒数を取得する
[引　数] students      : 全生徒のデータを格納する配列 
[戻り値] n             : 格納した生徒の数
---------------------------------------------------------------*/
int readStudentsData(Exam students[]){

    int size = getint("試験の生徒人数: ");
    int n = size;
    // 入力個数の規制
    if(n > STUDENT_LIMIT){
        n = STUDENT_LIMIT;

        printf("データ数が上限を超えました。\n入力できたデータのみ使用します。\n");
    }

    // 入力
    printf("NO , 姓 , 名 , テストの点数 を 空白区切りで入力\n");
    for(int i = 0; i < size; i++){

        int pos = 0, ct;
        char buff[BUFF_SIZE] = {};
        fgets(buff, sizeof(buff), stdin);

        // A.番号を入力
        int No;
        sscanf(buff, "%d%n", &No, &ct);
        pos += ct;
        No--;

        // 無効データの排除
        if(No < STUDENT_LIMIT){

            // B.名前の入力
            char FirstName[MAX_NAME_SIZE+1];
            char LastName[MAX_NAME_SIZE+1];

            sscanf(buff + pos, "%s %s%n", FirstName, LastName, &ct);
            pos += ct;
            
            setName(&students[No], FirstName, LastName);

            // C.テストデータの入力
            int j, testData;
            for(j = 0; j < SUBJECT_SIZE; j++){
                sscanf(buff + pos, "%d%n", &testData, &ct);
                pos += ct;

                setSubjectScore(&students[No], j, testData);
            }
        }
    }
    return(n);
}

/*---------------------------------------------------------------
[機　能] 全生徒の順位を求める
[引　数] students      : 全生徒のデータが格納されている配列　(各生徒のテストデータ　　[0]:国語 [1]:数学 [2]:英語 [3]:合計 [4]:順位)
[戻り値] n             : 全生徒の数
---------------------------------------------------------------*/
void calcRanking(Exam students[], int n){

    // A 合計計算
    calcSum(students, n);

    // B 順位計算
    for(int i = 0; i < n; i++){

        // A.1 i+1番目の人の順位を1位で初期化する
        int rank = 1;

        // A.2 i+1番目の人より大きい人が何人いるか加算する
        for(int j = 0; j < n; j++){

            // A.2-1 自身より大きい人がいるか確認
            if(getScoreSum(&students[j]) > getScoreSum(&students[i])){
                // 順位を1つ加算する（順位を１つ下げる）
                rank++;
            }
        }
        setRank(&students[i], rank);
    }
    return;
}

/*---------------------------------------------------------------
[機　能] 配列に格納されている生徒データの度数分布表を作成する
[引　数] students      : 全生徒のデータが格納されている配列　(各生徒のテストデータ　　[0]:国語 [1]:数学 [2]:英語 [3]:合計 [4]:順位)
[　　　] histogram     : 度数分布を格納する配列
[　　　] n             : 全生徒の数
[戻り値] なし
---------------------------------------------------------------*/
void countTimes(Exam students[], int histogram[], int n){

    // A. 度数分布表の計算
    for(int i = 0; i < n; i++){
        // A.1 合計点を50点ごとの階級に分離
        histogram[getScoreSum(&students[i])/50]++;
    }
    return;
}

/*---------------------------------------------------------------
[機　能] 全生徒のデータを表示する
[引　数] students      : 全生徒のデータが格納されている配列　(各生徒のテストデータ　　[0]:国語 [1]:数学 [2]:英語 [3]:合計 [4]:順位)
[　　　] n             : 全生徒の数
[戻り値] なし
---------------------------------------------------------------*/
void printSeiseki(Exam students[], int n){

    // 統計用テストデータ配列([0]:国語 [1]:数学 [2]:英語 [3]:合計)
    int data[SUBJECT_SIZE+1] = {};

    // A. 見出しの表示
    printf("\n");
    printf("試験成績一覧表\n\n");

    printf("%-3s %-32s %7s %9s %9s %9s %9s %10s\n",
        "NO  ",
        "氏名",
        "国語",
        "数学",
        "英語",
        "合計",
        "順位",
        "平均\n");

    // B. 生徒のデータを表示
    for(int i = 0; i < n; i++){

        // B.1 出席番号の表示
        printf("%3d  ", i + 1);

        // B.2 名前の表示
        char name[MAX_NAME_SIZE*2+2];
        getName(&students[i], name);
        printf("%-28s", name);

        // B.3 各教科のテストデータの表示
        int j;
        for(j = 0; j < SUBJECT_SIZE; j++){
            int testData = getSubjectScore(&students[i], j);
            printf("%8d", testData);

            // 統計用データへ加算
            data[j] += testData; 
        }

        // B.4 生徒の合計点数の表示
        int sum = getScoreSum(&students[i]);
        printf("%8d", sum);

        // B.5 生徒順位の表示
        printf("%8d", getRank(&students[i]));

        // B.6 生徒の平均点数の表示
        printf("%8.2f", (double)sum / SUBJECT_SIZE);

        printf("\n");
    }

    printf("\n");

    // C 統計の表示
    // C.1 各教科合計の表示
    printf("%35s","合計  ");
    for(int i = 0; i < SUBJECT_SIZE; i++){
        printf("%8d", data[i]);

        // 統計用データの加算
        data[SUBJECT_SIZE] += data[i];
    }
    // C.2 すべての合計点数の表示
    printf("%8d\n", data[SUBJECT_SIZE]);

    // C.3 各教科平均の表示
    printf("%35s","平均  ");
    for(int i = 0; i < SUBJECT_SIZE; i++){
        printf("%8.2f", (double)data[i] / n);
    }

    // C.4 全生徒の平均の表示
    printf("%8.2f\n", (double)data[SUBJECT_SIZE] / n);

    return;
}

/*---------------------------------------------------------------
[機　能] 全生徒のデータから作成した度数分布を表示する
[引　数] histogram     : 度数分布が格納されている配列
[戻り値] なし
---------------------------------------------------------------*/
void printHistogram(int histogram[]){

    printf("\n\n");
    int i, j;
    for(i = 0; i < 7; i++){

        // 階級の幅計算用
        int min = i * 50;
        int max = min + 49;

        // A.1 見出しの表示
        if(i == 6){
            printf("%-10s","300");
        }
        else{
            printf("%3d - %3d ", min, max);
        }

        // A.2 階級の度数の表示
        printf("[%2d] ", histogram[i]);

        // A.3 ヒストグラムの表示
        for(j = 0; j < histogram[i]; j++){
            printf("*");
        }

        printf("\n");
    }
    return;
}

/*-------------------------------------------------------------*/
/*                    追加した操作関数                          */
/*-------------------------------------------------------------*/

/*---------------------------------------------------------------
[機　能] 全生徒のデータの合計を計算する studentsの[3]:合計に格納
[引　数] students      : 全生徒のデータが格納されている配列　(各生徒のテストデータ　　[0]:国語 [1]:数学 [2]:英語 [3]:合計 [4]:順位)
[　　　] n             : 全生徒の数
[戻り値] なし
---------------------------------------------------------------*/
void calcSum(Exam students[], int n){

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < SUBJECT_SIZE; j++){
            // 各生徒ごとの合計の計算
            sum += getSubjectScore(&students[i], j);
        }
        // 合計の格納
        setSubjectScore(&students[i], SUBJECT_SIZE, sum);
    }
    return;
}