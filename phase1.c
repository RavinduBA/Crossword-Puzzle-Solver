#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define coordinate 2
#define MX_rows 100
#define MX_wlen 100
#define MX_cols 100
#define coordinate 2
#define MX_words 100

char save_words[MX_words][MX_wlen];
int rows,cols;
int word_available[MX_words];
char Grid[MX_rows][MX_cols];
int w_count;
int location[coordinate];
int Check_valid_row(int index, int a, int b);
int Check_valid_column(int index, int a, int b);
int check_letter(char Char);
int find_();
int find2();
void Grid_print();
int Valid_grid();
int clarify();
