#include <iostream>
#include <cctype>

namespace zhuravleva{
  void removeLatinLetters(const char* input, char* result)
  {
    size_t i = 0, j = 0;
    while (input[i] != '\0')
    {
      if (isalpha(input[i]))
      {
        i++;
        continue;
      }
      result[j] = input[i];
      j++;
      i++;
    }
    result[j] = '\0';
  }

  void excludeCommonSymbols(const char* str1, const char* str2, char* result)
  {
    size_t i = 0, j = 0;
    while (str1[i] != '\0')
    {
      int found = 0;
      for (size_t k = 0; str2[k] != '\0'; k++)
      {
        if (str1[i] == str2[k])
        {
          found = 1;
          break;
        }
      }
      if (!found)
      {
        result[j] = str1[i];
        j++;
      }
      i++;
    }
    result[j] = '\0';
  }
}

int main()
{
  return 0;
}
