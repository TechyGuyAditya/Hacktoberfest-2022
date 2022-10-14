class MyCalendarThree
{
public:
    map<int, int> m;
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {
        int mx = 0, sum = 0;
        m[start]++;
        m[end]--;
        for (const auto it : m)
        {
            sum += it.second;
            mx = max(mx, sum);
        }
        return mx;
    }
};