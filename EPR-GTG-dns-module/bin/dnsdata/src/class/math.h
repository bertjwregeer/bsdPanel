namespace bsdPanel {
    namespace Math {
        int pow(int x, int y);
    }
}

int bsdPanel::Math::pow(int x, int y)
{
    int ans = 1;
    for (int i = 0; i < y; i++)
    {
        ans = ans * x;
    }
    return ans;
}