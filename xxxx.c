// drawing X
//
// Usage:
//  % echo "*   15 15" | ./xxxx
// *             *
//  *           *
//   *         *
//    *       *
//     *     *
//      *   *
//       * *
//        *
//       * *
//      *   *
//     *     *
//    *       *
//   *         *
//  *           *
// *             *


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int w, h,  wh, hh,  x, y;
    char s, t;
    int r_2;

    scanf("%c%c %d %d", &s, &t, &w, &h);

    for (y = 0; y< h; y++) {
        for (x = 0; x< w; x++) {
            if (x == y || w-x-1 == y) {
                putchar(s);
            } else {
                putchar(t);
            }
        }
        putchar('\n');
    }
    return 0;
}

