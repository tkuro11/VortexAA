// drawing slanted NARUTO
//
// Usage:
//  $ echo "*   30 15" | ./slant
//    *  *  *  *  *  *  *  *  *  *
//   *  *  *  *  * *  *  *  *  *  
//  *  *  *  *  *   *  *  *  *  * 
//    *  *  *  *  *  *  *  *  *  *
//   *  *  *  *  * *  *  *  *  *  
//  *  *  *  *  *   *  *  *  *  * 
//    *  *  *  *  *  *  *  *  *  *
//   *  *  *  *  * *  *  *  *  *  
//  *  *  *  *  *    *  *  *  *  *
//   *  *  *  *  *  *  *  *  *  * 
//    *  *  *  *  **  *  *  *  *  
//  *  *  *  *  *    *  *  *  *  *
//   *  *  *  *  *  *  *  *  *  * 
//    *  *  *  *  **  *  *  *  *  
//  *  *  *  *  *    *  *  *  *  *


#include <stdio.h>
#include <stdlib.h>

main()
{
    int w, h,  wh, hh,  x, y;
    char s, t;
    int max;

    scanf("%c%c %d %d", &s, &t, &w, &h);

    wh = w/2; hh = h/2;             // center point

    for (y = -hh; y< hh; y++) {
        for (x = -wh; x< wh; x++) {
            int r, gap = 0;

            // if the point is on the right half area 
            //   displace holizontally by 1
            if (x > 0) gap = 1;

            // calc Manhattan dist.
            r= labs(x) + labs(y+gap); 

            if (r % 3 == 0)  // period 3
                putchar(s);
            else
                putchar(t);
        }
        putchar('\n');
    }
    return 0;
}

