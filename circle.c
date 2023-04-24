// drawing circle
//
// Usage:
//  % echo "*  20 15" | ./circle
// 
//         *****
//       *********
//      ***********
//      ***********
//     *************
//     *************
//     *************
//     *************
//     *************
//      ***********
//      ***********
//       *********
//         *****

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int w, h,  wh, hh,  x, y;
    char s, t;
    int r_sq;

    scanf("%c%c %d %d", &s, &t, &w, &h);

    wh = w/2; hh = h/2;      // center point

    if (wh > hh) {           // determine radius^2 so that a circle fit in the frame.
        r_sq = hh * hh;
    } else {
        r_sq = wh * wh;
    }
    r_sq *= 0.9;              // make it little smaller

    for (y = -hh; y< hh; y++) {
        for (x = -wh; x< wh; x++) {
            // calc distance^2 from origin.
            int dist_sq;
            dist_sq = x*x + y*y;

            // if distance^2 is less than radius, it means point(x,y)
            //   is inside a circle of radius r.
            if (dist_sq < r_sq) {
                putchar(s);
            } else {
                putchar(t);
            }
        }
        putchar('\n');
    }
    return 0;
}

