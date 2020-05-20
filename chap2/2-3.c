#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
  chapter 2: exercise 2-3

  write the function, htoi(s), which converts a string of hexadecimal digits
  (including an optional 0x or 0X) into its equivalent integer value.
  the allowable digits are 0 through 9, a through f, and A through F.
*/

int htoi(char s[])
{
  int i, c;
  int convert = 0;

  for (i = 0; (c = s[i]) != '\0'; i++) {
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
      i++;
      continue;
    }
    if (s[i] >= '0' && s[i] <= '9') {
      convert = 16 * convert + (s[i] - '0');
    }
    else if (s[i] >= 'a' && s[i] <= 'f') {
			convert = 16 * convert + (s[i] - 'a' + 10);
		}
    else if (s[i] >= 'A' && s[i] <= 'F') {
			convert = 16 * convert + (s[i] - 'A' + 10);
		}
    else {
			break;
		}
  }
  return convert;
}

int main()
{

  int newhex = htoi("0x123abc");
  printf("%d\n", newhex);
  return 0;
}
