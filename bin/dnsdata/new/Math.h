#ifndef BSDPANEL_MATH_H
#define BSDPANEL_MATH_H

namespace bsdPanel {
    namespace Math {
        int pow(int x, int y)
        {
            int ans = 1;
            for (int i = 0; i < y; i++)
            {
                ans = ans * x;
            }
            return ans;
        }
    }
}
#endif