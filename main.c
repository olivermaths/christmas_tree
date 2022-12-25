#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <time.h>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"


#define line                "═"
#define left_up_conner      "╔"
#define right_up_conner     "╗"
#define left_down_conner    "╚"
#define right_down_conner   "╝"
#define up_line             "║"

#define TREE_TR_WIDTH       18





void print_tree(int cols, int rows);


int main() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int rows = w.ws_row;
  int cols = w.ws_col;
  print_tree(cols-4, rows - 2);

  return 0;
}


void print_tree(int cols, int rows){
  int middle = cols/2;


  printf("\n\n\n\n");
  int correction = 0;
  srand(time(NULL));
  
  for (int row = 0; row < rows ; row++) {
        if(row > 3){
          correction += 3;
        }


      for (int col = 0; col < cols; col++) {
          int yellow_rd = rand() % rows * row;
          int red_rd = rand() % rows * col;


          if((col == 0) && row != 0 && row != rows - 1){
            printf(up_line);
          }
          if(col == 0 && row == 0){
            printf(left_up_conner);
          }
          if(col == 0 && row == rows - 1){
            printf(left_down_conner);
          }
          if((yellow_rd < rows - 10) && (row > 3 && row < rows - 10) && col >= (middle - correction/2) && col <= (middle+ correction/2)){
              printf(YELLOW "@" RESET);
          }
          else if((red_rd < rows - 10) && (row > 3 && row < rows - 10) && col >= (middle - correction/2) && col <= (middle+ correction/2)){
              printf(RED "@" RESET);
          }
          else if((row > 2 && row < rows - 10) && col >= (middle - correction/2) && col <= (middle+ correction/2)){
              printf(GREEN "#" RESET);
          }
          else if((row > rows - 11 && row < rows - 1) && col >= (middle - (TREE_TR_WIDTH/3)) && col <= (middle + (TREE_TR_WIDTH/3) )){
                printf("#");
          }
          else if(row > 0 && row < rows - 1 && col > 0 && col < cols - 1){
            printf(" ");
          }     
          
          if((col == cols - 1) && row != 0 && row != rows - 1){
            printf(up_line);
          }
          if(row == 0 && col == cols - 1){
            printf(right_up_conner);
          }

          if(row == rows - 1 && col == cols - 1){
            printf(right_down_conner);
          }
          if((row == 0 || row == rows - 1) && col > 0 && col < cols - 1 ){
            printf(line);
          }


    }
    putchar('\n');
  }
  printf("\n\n\n\n\n\n");
}