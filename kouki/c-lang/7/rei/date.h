//  日付データを格納する構造体の定義                                            
typedef struct {                                                           
  int year;                                                            
  int month;                                                            
  int day;                                                             
} Date;

Date getDate(void);
void printDate(Date date);
Date laterDate(Date date1, Date date2);
