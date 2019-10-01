# string

## 1. split(string, char)

```cpp
vector<string> split(string s, char separator)
{
    vector<string> res;
    s += separator;
    for (int i = 0, j = 0; i < s.size(); i++)
        if (s[i] == separator)
        {
            res.push_back(s.substr(j, i - j));
            j = i + 1;
        }
    return res;
}
```

Ví dụ:

```cpp
string "1,2,3,4,5";
split(s, ','); // [1, 2, 3, 4, 5]
```
