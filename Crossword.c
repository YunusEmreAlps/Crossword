// Crossword

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h> // string length
#include <time.h> // random function

#define Row 5  // Row
#define Col 5 //  column
#define Len 10 //  searched word length

char Word[Row][Col]  ; // crossword
char Word2[Col][Row] ; // transpose
char Word3[Row][Col] ;
char SWord[Len] ; // searched word
//char Word[Row][Col] = {{'E','U','E','U'},{'Z','E','U','S'},{'D','E','U','E'},{'U','E','E','T'}} ;

int left_right(char *P_1) ;
int up_down(char *P_2) ;

int right_left(char *P_3) ;

int main()
{
    int i,j ; // loop variable

    srand(time(NULL)) ;

    printf(" Left-Right \n\n") ;

    printf("\n ---------- \n\n") ;

    for( i=0 ; i < Row ; i++ )
    {
        for( j=0 ; j < Col ; j++ )
        {
            Word[i][j] = 'A' + ( rand()%26 ) ; // A = 65 <- ASCII , Z = 90 <- ASCII

            printf(" %c ",Word[i][j]) ;
        }
        printf("\n") ; // new line
    }

    printf("\n ---------- \n\n") ;

    left_right(Word) ;

    printf("\n ---------- \n\n") ;

    printf(" Up-Down \n\n") ;

    for( i=0 ; i<Col ; i++ )
    {
        for( j=0 ; j<Row ; j++ )
        {
            Word2[i][j] = Word[j][i] ;
            printf(" %c ",Word2[i][j]) ;
        }
        printf("\n") ;
    }

    printf("\n ---------- \n\n") ;

    up_down(Word2) ;

    printf("\n ---------- \n\n") ;

    int k = 0 ;

    printf(" Right-Left \n\n") ;

    for( i=0 ; i<Row ; i++ )
    {
        for( j=Col-1 ; j>-1 ; j-- )
        {
            Word3[i][k] = Word[i][j] ;
            k++ ;
        }
        k=0 ;
    }

    for( i= 0 ; i<Row ; i++ )
    {
        for( j=0 ; j<Col ; j++ )
        {
            printf(" %c ",Word3[i][j]) ;
        }
        printf("\n") ;
    }


    printf("\n ---------- \n\n") ;

    right_left(Word3) ;

    printf("\n ---------- \n\n") ;


    getch() ;
    return 0 ;
}

int left_right(char *P_1)
{
    printf(" Please enter a searched word : ") ;
    scanf("%s",&SWord) ;

    char *SP ; // pointer

    SP = SWord ; // assign

    int Length = strlen(SWord) ; // searched word length

    int Result = 0 ; // total searched word number

    if(Length > Col ) // Warning
    {
        printf("\n ---------- \n\n") ;

        printf(" Error : Searched word length bigger than Column size . \n ") ;

        printf("\n ---------- \n\n") ;

        return 0 ;
    }

    else if (Length <= Col )
    {
        int i,j,k=0,z=0 ;   // loop
        int RL = 0,CL = 0 ;  // Row Location , Column Location
        int Counter = 0,Counter2 = 0 ;  // Length == Counter

        for( i=0 ; i<Row ; i++ )
        {
            for( j=0 ; j<Col ; j++ )
            {
                if(*(*(Word+i)+j) == SP[k])
                {
                    Counter++ ;

                    if(k==0)
                    {
                        RL = i ;
                        CL = j ;

                    }

                    if((Counter == Length)||(Length == k))
                    {

                        Result++ ;
                        printf(" + Row Number:%d , Column Number : %d \n",RL+1,CL+1) ;
                        k= -1 ;
                        z=0 ;
                        Counter=0 ;

                    }

                    k++ ;

                    //printf(" + Row:%d , Col:%d , Letter : %c \n",i,j,Word[i][j]) ;

                    if((j == Row-1)&&(k!=Length))
                    {
                        Counter = 0 ;
                        k = 0 ;
                    }

                }

                else if ((*(*(Word+i)+j) == SP[z]))
                {
                    Counter2++ ;

                    if(z==0)
                    {
                        RL = i ;
                        CL = j ;
                        Counter = 0 ;
                        k=0 ;
                    }

                    if((Counter2 == Length)||(Length == z))
                    {
                        Result++ ;
                        printf(" + Row Number:%d , Column Number : %d \n",RL+1,CL+1) ;
                        z= -1 ;
                        k= 0 ;

                        Counter2=0 ;
                    }

                    z++ ;
                }




                else
                {
                    k = 0 ;
                    Counter = 0 ;
                    z = 0 ;
                    Counter2 = 0 ;
                }
            }

        }

    }

    printf(" Left_Right Result : %d \n",Result) ;

}

int up_down(char *P_2)
{
    printf(" Please enter a searched word : ") ;
    scanf("%s",&SWord) ;

    char *SP ; // pointer

    SP = SWord ; // assign

    int Length = strlen(SWord) ; // searched word length

    int Result = 0 ; // total searched word number

    if(Length > Row) // Warning
    {
        printf("\n ---------- \n\n") ;

        printf(" Error : Searched word length bigger than Row size . \n ") ;

        printf("\n ---------- \n\n") ;

        return 0 ;
    }

    else if (Length <= Row)
    {
        int i,j,k=0,z=0 ;   // loop
        int RLo = 0,CLo = 0 ;  // Row Location , Column Location
        int Counter = 0,Counter2 = 0 ;  // Length == Counter

        for( i=0 ; i<Col ; i++ )
        {
            for( j=0 ; j<Row ; j++ )
            {
                if(*(*(Word2+i)+j) == SP[k])
                {
                    Counter++ ;

                    if(k==0)
                    {
                        RLo = i ;
                        CLo = j ;
                    }

                    if((Counter == Length)||(Length == k))
                    {

                        Result++ ;
                        printf(" + Row Number:%d , Column Number: %d \n",CLo+1,RLo+1) ;
                        k= -1 ;
                        z=0 ;
                        Counter=0 ;

                    }
                    k++ ;

                    if((j == Row-1)&&(k!=Length))
                    {
                        Counter = 0 ;
                        k = 0 ;
                    }

                    //printf(" + Row:%d , Col:%d , Letter : %c \n",i,j,Word[i][j]) ;

                }

                else if ((*(*(Word2+i)+j) == SP[z]))
                {
                    Counter2++ ;

                    if(z==0)
                    {
                        RLo = i ;
                        CLo = j ;
                        Counter = 0 ;
                        k=0 ;
                    }

                    if((Counter2 == Length)||(Length == z))
                    {
                        Result++ ;
                        printf(" + RL:%d , CL : %d \n",CLo,RLo) ;
                        z= -1 ;
                        k= 0 ;

                        Counter2=0 ;
                    }

                    z++ ;
                }

                else
                {
                    k = 0 ;
                    Counter = 0 ;
                    z = 0 ;
                    Counter2 = 0 ;
                }
            }

        }
    }

    printf(" Up_Down Result : %d",Result) ;
}

int right_left(char *P_3)
{
    printf(" Please enter a searched word : ") ;
    scanf("%s",&SWord) ;

    char *SP ; // pointer

    SP = SWord ; // assign

    int Length = strlen(SWord) ; // searched word length

    int Result = 0 ; // total searched word number

    if(Length > Col ) // Warning
    {
        printf("\n ---------- \n\n") ;

        printf(" Error : Searched word length bigger than Column size . \n ") ;

        printf("\n ---------- \n\n") ;

        return 0 ;
    }

    else if (Length <= Col )
    {
        int i,j,k=0,z=0 ;   // loop
        int RL = 0,CL = 0 ;  // Row Location , Column Location
        int Counter = 0,Counter2 = 0 ;  // Length == Counter

        for( i=0 ; i<Row ; i++ )
        {
            for( j=0 ; j<Col ; j++ )
            {
                if(*(*(Word3+i)+j) == SP[k])
                {
                    Counter++ ;

                    if(k==0)
                    {
                        RL = i ;
                        CL = j ;

                    }

                    if((Counter == Length)||(Length == k))
                    {

                        Result++ ;
                        printf(" + Row Number:%d , Column Number : %d \n",RL+1,Col-CL) ;
                        k= -1 ;
                        z=0 ;
                        Counter=0 ;

                    }

                    k++ ;

                    //printf(" + Row:%d , Col:%d , Letter : %c \n",i,j,Word[i][j]) ;

                    if((j == Row-1)&&(k!=Length))
                    {
                        Counter = 0 ;
                        k = 0 ;
                    }

                }

                else if ((*(*(Word3+i)+j) == SP[z]))
                {
                    Counter2++ ;

                    if(z==0)
                    {
                        RL = i ;
                        CL = j ;
                        Counter = 0 ;
                        k=0 ;
                    }

                    if((Counter2 == Length)||(Length == z))
                    {
                        Result++ ;
                        printf(" + Row Number:%d , Column Number: %d \n",RL+1,Col-CL) ;
                        z= -1 ;
                        k= 0 ;

                        Counter2=0 ;
                    }

                    z++ ;
                }




                else
                {
                    k = 0 ;
                    Counter = 0 ;
                    z = 0 ;
                    Counter2 = 0 ;
                }
            }

        }

    }

    printf(" Right_Left Result : %d \n",Result) ;

}
