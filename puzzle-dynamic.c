#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

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


int main(){
  int *i = (int*)malloc(sizeof(int));
  int *j = (int*)malloc(sizeof(int));
  int *is_Possible = (int*)malloc(sizeof(int));
  int *empty_lines = (int*)malloc(sizeof(int));
  int *MX_Length = (int*)malloc(sizeof(int));
  int *MN_Length = (int*)malloc(sizeof(int));

  *i = 1;           //The puzzle's loop variable
  *is_Possible = 1;
  *MX_Length = -1;
  *MN_Length = -1;


  *j = 0;           //Loop variable for words list
  *empty_lines = 0; //No of empty lines

    for(;;){
        if (*empty_lines >= 2){
            break;
        }

        else if (*empty_lines ==0){
            gets( Grid[*i] );                  //Add the input to the puzzle array after taking it.
            int Row_length = strlen(Grid[*i]);

            if ( Row_length !=0){
                if ( (*MX_Length ==-1) || ( *MX_Length< Row_length ))
                    { *MX_Length= Row_length; }
                if ( (*MN_Length ==-1) || ( *MN_Length> Row_length ))
                    { *MN_Length = Row_length; }
                if ( *MX_Length!= *MN_Length)
                     { *is_Possible=0; }           // Check to see if the grid has the same number of columns.

                for(int y=0;y<Row_length;y++){
                    int e = Grid[*i][y];
                    if ( !((e==35) || (e==42) || ( (65<=e) && (e<=90) ) || ( (97<=e) && (e<=122) )) ){
                        *is_Possible = 0;
                    }
                }
                *i = *i+1;
           }
            else{
                *empty_lines = *empty_lines + 1;
            }
        }
          // word list input
        else if(*empty_lines==1){
            gets(save_words[*j]);
            int Word_length = strlen(save_words[*j]);

            if (Word_length!=0){
                for(int y=0;y<Word_length;y++){
                    int e = save_words[*j][y];
                    if (!(((97<=e)&&(e<=122) )|| ((65<=e) && (e<=90)))){
                        is_Possible = 0;
                    }                      //Only letters make up words. Otherwise, error
                }
                *j = *j + 1;
            }
            else{
                *empty_lines = *empty_lines + 1;
            }
        }
    }

     if(Valid_grid()){
        printf("INVALID INPUT\n");
        return 0;
     }

    cols = *MX_Length;
    rows = *i+1;
    w_count = *j;
    word_available[0] = 1;
    word_available[1] = 1;

    free(i);
    free(j);
    free(empty_lines);
    free(MX_Length);
    free(MN_Length);

  clarify();

    for(int i=0; i<w_count; i++){
        if(word_available[i]){
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
 Grid_print();

    return 0;

}

void Grid_print(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%c", Grid[i][j]);
        }
        putchar('\n');
    }
}

//Function to check whether crossword pattern is valid
int Valid_grid(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(Grid[i][j] != '#' && Grid[i][j] != '\n' && Grid[i][j] != '*' && !check_letter(Grid[i][j])){
                return 1;
            }
        }
    }
    return 0;
}


//Function to check whether input character is a letter
int check_letter(char Char){
    if((Char>=65 && Char<=90) || (Char>=97 && Char<=122)){ //A-Z or a-z or #
        return 1;
    }
    else{
        return 0;
    }
}

//Return the position of place in grid that can insert a word
int find2(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
                if(Grid[i][j]=='#'){
                    location[0] = j;
                    location[1] = i;
                    return 0;
                }
          }
    }
    return 1;
}

int find_()
{
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            for(int k=0; k<w_count; k++){

                if(!word_available[k]){
                    continue;
                }
                if(check_letter(Grid[i][j])){
                    if(save_words[k][0]==Grid[i][j]){
                        location[0] = j;
                        location[1] = i;
                        return 0;
                    }
                }
                if(Grid[i][j]==35){
                    location[0] = j;
                    location[1] = i;
                    return 0;
                }
            }
        }
    }
    return 1;
}

//Check validity of word that can be inserted
int Check_valid_row(int index, int a, int b){
    int Hash=0;
    for(int i=a; i<cols; i++){
        if(check_letter(Grid[b][i])){
            for(int j=0; j<w_count; j++){
                if(!word_available[j]){
                    continue;
                }

                if(Grid[b][i] == save_words[j][i]){
                    Hash++;
                    break;
                }
                else{
                    return 0;
                }
            }
        }
        else if(Grid[b][i]==35){
            Hash++;
        }
        else{
            break;
        }
    }

    if(Hash==strlen(save_words[index])){
        return 1;
    }
    else{
        return 0;
    }
}

//Check validity of word that can be inserted
int Valid_col(int index, int a, int b){
    int Hash=0;
    for(int i=b; i<rows; i++){

        if(check_letter(Grid[i][a])){

            for(int j=0; j<w_count; j++){
                    if(!word_available[j]){
                        continue;
                    }
                    if(Grid[i][a] == save_words[j][i]){
                        Hash++;
                        break;
                    }
                    else{
                        return 0;
                    }
                }
        }
        else if(Grid[i][a]==35){
            Hash++;
        }
        else{
            break;
        }
    }

    if(Hash==strlen(save_words[index])){
        return 1;
    }
    else{
        return 0;
    }
}

int clarify(){

    find_();
    int a=location[0];
    int b=location[1];
    int count=0;

    for(int i=0; i<w_count; i++){

        if(!word_available[i]){
            count++;;
        }
        if(count==w_count){
            return 1;
        }
    }

    for(int i=0; i<w_count; i++){
        if(!word_available[i]){
            continue;
        }
       if(Check_valid_row(i, a, b)){

           for(int j=0; j<strlen(save_words[i]); j++){
                Grid[b][a+j]=save_words[i][j];
            }
            word_available[i]=0;

             if(clarify()){
                return 1;
            }

            word_available[i]=1;

             for(int j=0; j<strlen(save_words[i]); j++){
                Grid[b][a+j]='#';
            }
         }
        if(Valid_col(i, a, b)){
            for(int j=0; j<strlen(save_words[i]); j++){
                Grid[b+j][a]=save_words[i][j];
            }
            word_available[i]=0;

            if(clarify()){
                return 1;
            }
            word_available[i]=1;

           for(int j=0; j<strlen(save_words[i]); j++){
               Grid[b+j][a]='#';
            }
        }
    }
    return 0;
}
