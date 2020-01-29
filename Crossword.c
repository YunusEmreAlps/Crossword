// crossword

#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define row 5 // row number
#define col 5 // column number
#define len 5 // maximum word length

// ----------
// global variables
int rl=0, cl=0; // row location, column location
int leng=0, res=0;
int cnt1=0, cnt2=0;
int i=0, j=0, k=0, z=0; // loop variable

char *spoint; // pointer
char sword[len]; // searched word
char word[row][col]; // crossword
char word2[col][row]; // transpose
char word3[row][col];

// ----------
// signature of functions
void left_right();
void up_down();
void right_left();

// ----------
// main function
int main()
{
    srand(time(NULL)); // random letter

    printf(" ---------------\n"); // left-right part
    for(i=0; i<row; i++)
    {
        printf(" ");
        for(j=0; j<col; j++)
        {
            word[i][j]= 'A' + (rand()%26); // A=65(ASCII value), Z=90(ASCII value)
            printf(" %c ",word[i][j]);
        }
        printf("\n");
    }
    printf(" ---------------\n");

    printf(" - Left-Right \n\n");
    left_right(); // left-right part is end

    printf(" ---------------\n"); // up-down part
    for(i=0; i<col; i++)
    {
        for(j=0; j<row; j++)
        {
            word2[i][j] = word[j][i];
        }
    }

    printf(" - Up-Down \n\n");
    up_down(); // up-down part is end

    printf(" ---------------\n"); // right-left part
    for(i=0; i<row; i++)
    {
        for(j=col-1; j>-1; j--)
        {
            word3[i][k] = word[i][j];
            k++;
        }
        k=0;
    }

    printf(" - Right-Left \n\n");
    right_left() ; // right-left part is end

    printf(" ---------------\n");

    getch();
    return 0;
}

// ----------
void left_right()
{
    printf(" - Enter word : ");
    scanf("%s",&sword);

    spoint=sword;
    leng=strlen(sword); // word length
    res=0; // word number

    if(leng>col)
    {
        printf(" - Error : word length bigger than column size.\n");
        return 0;
    }
    else if(leng<=col)
    {
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                if(*(*(word+i)+j) == spoint[k])
                {
                    cnt1++;
                    if(k==0)
                    {
                        rl = i;
                        cl = j;
                    }
                    if((cnt1 == leng)||(leng == k))
                    {
                        res++;
                        printf(" + Row Number:%d , Column Number : %d \n",rl+1,cl+1);
                        k= -1;
                        z=0;
                        cnt1=0;
                    }
                    k++ ;
                    if((j == row-1)&&(k!=leng))
                    {
                        cnt1 = 0;
                        k = 0;
                    }
                }
                else if ((*(*(word+i)+j) == spoint[z]))
                {
                    cnt2++;
                    if(z==0)
                    {
                        rl=i;
                        cl=j;
                        cnt1 = 0;
                        k=0;
                    }
                    if((cnt2 == leng)||(leng == z))
                    {
                        res++;
                        printf(" + Row Number:%d , Column Number : %d \n",rl+1,cl+1);
                        z=-1;
                        k=0;

                        cnt2=0;
                    }
                    z++;
                }
                else
                {
                    k=0;
                    cnt1=0;
                    z=0;
                    cnt2=0;
                }
            }
        }
    }
    printf("\n - (left-right) result : %d \n",res);
}

// ----------
void up_down()
{
    printf(" - Enter word : ");
    scanf("%s",&sword);

    spoint=sword;
    leng=strlen(sword); // word length
    res=0; // word number

    if(leng>row) // Warning
    {
        printf(" - Error : word length bigger than row size.\n");
        return 0;
    }
    else if(leng<=row)
    {
        rl=0, cl=0; // row location, column location

        for(i=0; i<col; i++)
        {
            for(j=0; j<row; j++)
            {
                if(*(*(word2+i)+j) == spoint[k])
                {
                    cnt1++;
                    if(k==0)
                    {
                        rl=i;
                        cl=j;
                    }

                    if((cnt1 == leng)||(leng == k))
                    {
                        res++;
                        printf(" + Row Number:%d , Column Number: %d \n",cl+1,rl+1);
                        k=-1;
                        z=0;
                        cnt1=0;
                    }
                    k++ ;
                    if((j == row-1)&&(k!=leng))
                    {
                        cnt1=0;
                        k =0;
                    }
                }
                else if ((*(*(word2+i)+j) == spoint[z]))
                {
                    cnt2++;
                    if(z==0)
                    {
                        rl=i;
                        cl=j;
                        cnt1=0;
                        k=0;
                    }

                    if((cnt2 == leng)||(leng == z))
                    {
                        res++;
                        printf(" + RL:%d , CL : %d \n",cl,rl);
                        z=-1;
                        k=0;
                        cnt2=0;
                    }
                    z++;
                }
                else
                {
                    k=0;
                    cnt1=0;
                    z=0;
                    cnt2=0;
                }
            }
        }
    }

    printf("\n - (up-down) result : %d \n",res);
}

// ----------
void right_left()
{
    printf(" - Enter word : ");
    scanf("%s",&sword);

    spoint=sword;
    leng=strlen(sword); // word length
    res=0; // word number

    if(leng>col)
    {
        printf(" - Error : word length bigger than column size.\n");
        return 0;
    }
    else if(leng<=col)
    {
        rl=0, cl=0; // row location, column location

        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                if(*(*(word3+i)+j) == spoint[k])
                {
                    cnt1++;
                    if(k==0)
                    {
                        rl=i;
                        cl=j;
                    }
                    if((cnt1 == leng)||(leng == k))
                    {
                        res++;
                        printf(" + Row Number:%d , Column Number : %d \n",rl+1,col-cl);
                        k=-1;
                        z=0;
                        cnt1=0;
                    }
                    k++;
                    if((j == row-1)&&(k!=leng))
                    {
                        cnt1=0;
                        k=0;
                    }
                }
                else if ((*(*(word3+i)+j) == spoint[z]))
                {
                    cnt2++;
                    if(z==0)
                    {
                        rl=i;
                        cl=j;
                        cnt1=0;
                        k=0;
                    }
                    if((cnt2 == leng)||(leng == z))
                    {
                        res++;
                        printf(" + Row Number:%d , Column Number: %d \n",rl+1,col-cl);
                        z=-1;
                        k=0;
                        cnt2=0;
                    }
                    z++;
                }
                else
                {
                    k=0;
                    cnt1=0;
                    z=0;
                    cnt2=0;
                }
            }
        }
    }
    printf("\n - (right-left) result : %d \n",res);
}
