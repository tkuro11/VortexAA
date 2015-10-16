// drawing swirl 
// Usage: 
//  $ echo "*  30 15" | ./swirl
//      **    **    **            
//      **     *   **             
//       *    ***  **   * ***     
//       **    *** **  ********   
//        **    ***** ***     **  
//        ***    *******        **
//  *      ************          *
//  *        *************        
//   *          ************      
//   **        *******    ***     
//     **     *** *****    **     
//      ********  ** ***    **    
//        *** *   **  ***    *    
//                **   *     **   
//               **    **    **   

#include <stdio.h>
#include <stdlib.h>    // for labs
#include <math.h>      // for sin, cos

int main()
{
    int w, h,  wh, hh,  x, y;
    char s, t;
    int max;

    scanf("%c%c %d %d", &s, &t, &w, &h);
    max = (w*w+ h*h)/4;                    // normalization coeff.
    wh = w/2; hh = h/2;                    // center point

    for (y = -hh; y< hh; y++) {
        for (x = -wh; x< wh; x++) {
            int r = x*x + y*y;              // dist. from origin
            int tx, ty;

            double sn = sin((double)r/max), // for the 
                   cs = cos((double)r/max); //  rotation matrix

            tx = (int)(x * cs - y * sn);    // rotate
            ty = (int)(x * sn + y * cs);    // rotate

            // if the transformed point is on the x/y axis or
            //         45/135 degree line(in +-1 because error)
            if (tx == 0 || ty == 0 || 
                    labs(tx - ty) < 2 || labs(tx + ty) < 2)
                putchar(s);
            else
                putchar(t);
        }
        putchar('\n');
    }
    return 0;
}
