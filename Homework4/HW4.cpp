int sumDigits(int x)
{
    if (x == 0)
    {
        return 0;
    }   
    return x % 10 + sumDigits(x - x % 10)/10);
}