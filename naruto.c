// drawing NARUTO
// Usage: 
//  $ echo "*  30 15" | ./naruto
//         * ************        
//         * *          *        
//         * * ******** *        
//         * * *      * *        
//         * * * **** * *        
//         * * * *  * * *        
//         * * * ** * * *        
//         * * * ** * * *        
//         * * * ** * * *        
//         * * *    * * *        
//         * * ****** * *        
//         * *        * *        
//         * ********** *        
//         *            *        
//         **************        

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w, h,  wh, hh,  x, y;
    int w_even=0, h_even=0, side=0;
    char s, t;
    char c;

    scanf("%c%c %d %d", &s, &t, &w, &h);

/*
    + stragegy for NARUTO + 

      *^*********
      * ^       *
      * *^***** *
      * * ^   * *
      * * *^* * *
      * * * * * *
      * * *** * *
      * *     * *
      * ******* *
      *         *
      ***********

    (1) draw squares
    (2) xor '^' (NARUTO point)
*/

    if ((w & 1) == 0) w_even = 1; // Is width even?
    if ((h & 1) == 0) h_even = 1; // Is height even?
    if ((w & 2) != 0)   side = 1; // Is width 4n + a(a=0,1)?
                                  //// (it is needed to adjust
                                  ////  left edge of NARUTO.)

    wh = w/2;  hh = h/2;          // center point

    for (y = 0; y< h; y++) {
        for (x = 0; x< w; x++) {
            int x2 = x-wh, y2 = y - hh;      // set center to origin

            if (x2 >= 0) { x2 += w_even; }   // if width or height is even
            if (y2 >= 0) { y2 += h_even; }   //  trancate x/y axis by 1.

            if (x2 < -hh || y2 < -wh || 
                    x2 > hh || y2 > wh) {    // out of canvas
                c = t;
            } else if (labs(x2) < labs(y2)) {// RULE for horizontal line of square
                if ((labs(y2) % 2) == side)
                    c = s;
                else
                    c = t;
            } else {                         // RULE for vertical line of square
                if ((labs(x2) % 2) == side) 
                    c = s;
                else
                    c = t;
            }

            if (x2 <= 0 && y2 <= 0 &&
                    (x2 - 1) == y2) {        // xor NARUTO point
                c = (s+t) - c;
            }
                    
            putchar(c);
        }
        putchar('\n');
    }
    return 0;
}
