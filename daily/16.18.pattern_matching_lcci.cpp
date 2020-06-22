#include <iostream>
#include <string>

using namespace std;

class Solution
{
    bool check(string &value, int n)
    {
        int length = value.length();
        if (length % n != 0)
            return false;
        string label = value.substr(0, length / n);
        for (int i = 1; i < length / n; i++)
        {
            if (value.substr(i * length / n, length / n) != label)
                return false;
        }
        return true;
    }

public:
    bool patternMatching(string pattern, string value)
    {
        // 讨论空字符串情形
        if (pattern == "" && value == "")
            return true;
        if (value == "")
        {
            if (pattern.find("a") != string::npos && pattern.find("b") != string::npos)
                return false;
            else
                return true;
        }
        if (pattern == "")
            return false;

        int n = value.size();
        int cnt_a = 0, cnt_b = 0;
        for (char x : pattern)
        {
            if (x == 'a')
                cnt_a++;
            else
                cnt_b++;
        }

        // 用一个字符表示 value
        if (cnt_a == 1 || cnt_b == 1)
            return true;
        // 用一种字符表示 value
        if (!cnt_a || !cnt_b)
        {
            return check(value, max(cnt_a, cnt_b));
        }

        // 改变字符 a 的长度，判断是否可以匹配 value
        for (int l_a = 0; l_a <= n / cnt_a; ++l_a)
        {
            // 用一种字符表示 value
            if (l_a == 0)
            {
                if (n % cnt_b == 0 && check(value, cnt_b))
                    return true;
            }
            else if (l_a == n / cnt_a)
            {
                if (n % cnt_a == 0 && check(value, cnt_a))
                    return true;
            }
            else
            {
                if ((n - l_a * cnt_a) % cnt_b != 0)
                    continue;
                int l_b = (n - l_a * cnt_a) / cnt_b;
                string label_a = "";
                string label_b = "";
                int cur_index = 0;
                for (char x : pattern)
                {
                    if (x == 'a')
                    {
                        if (label_a.empty())
                        {
                            label_a = value.substr(cur_index, l_a);
                            cur_index += l_a;
                        }
                        else
                        {
                            if (value.substr(cur_index, l_a) != label_a)
                                break;
                            cur_index += l_a;
                        }
                    }
                    else
                    {
                        if (label_b.empty())
                        {
                            label_b = value.substr(cur_index, l_b);
                            cur_index += l_b;
                        }
                        else
                        {
                            if (value.substr(cur_index, l_b) != label_b)
                                break;
                            cur_index += l_b;
                        }
                    }
                }
                if (cur_index == n && label_a != label_b)
                    return true;
            }
        }
        return false;
    }
};

// 官方题解
class Solution
{
public:
    bool patternMatching(string pattern, string value)
    {
        int count_a = 0, count_b = 0;
        for (char ch : pattern)
        {
            if (ch == 'a')
            {
                ++count_a;
            }
            else
            {
                ++count_b;
            }
        }
        if (count_a < count_b)
        {
            swap(count_a, count_b);
            for (char &ch : pattern)
            {
                ch = (ch == 'a' ? 'b' : 'a');
            }
        }
        if (value.empty())
        {
            return count_b == 0;
        }
        if (pattern.empty())
        {
            return false;
        }
        string_view v_value(value);
        for (int len_a = 0; count_a * len_a <= value.size(); ++len_a)
        {
            int rest = value.size() - count_a * len_a;
            if ((count_b == 0 && rest == 0) || (count_b != 0 && rest % count_b == 0))
            {
                int len_b = (count_b == 0 ? 0 : rest / count_b);
                int pos = 0;
                bool correct = true;
                string_view value_a, value_b;
                for (char ch : pattern)
                {
                    if (ch == 'a')
                    {
                        string_view sub = v_value.substr(pos, len_a);
                        if (!value_a.size())
                        {
                            value_a = sub;
                        }
                        else if (value_a != sub)
                        {
                            correct = false;
                            break;
                        }
                        pos += len_a;
                    }
                    else
                    {
                        string_view sub = v_value.substr(pos, len_b);
                        if (!value_b.size())
                        {
                            value_b = sub;
                        }
                        else if (value_b != sub)
                        {
                            correct = false;
                            break;
                        }
                        pos += len_b;
                    }
                }
                if (correct && value_a != value_b)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    string pattern, value;
    cin >> pattern >> value;

    Solution solver;
    bool res = solver.patternMatching(pattern, value);
    cout << res << endl;
}