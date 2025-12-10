// #include <header.h>
#include <time.h>
#include <stdlib.h>

/*needs: Some way to store the initial time value (in header.h)
 also: way to compare current and initial time to get elapsed time
*/

double initial_time = 0;
double thymekeep()
{
  if (initial_time == 0)
  {
    initial_time = time(NULL);
    return 0;
  }
  else
  {
    double currytime = time(NULL) - initial_time;
    return currytime;
  }
}

int main()
{
  double thzm = thymekeep();
  printf("Initial time: %f\n", thzm);
  int igitt = 0;
  while (igitt < 2000)
  {

    int r[2800 + 1];
    int i, k;
    int b, d;
    int c = 0;

    for (i = 0; i < 2800; i++)
    {
      r[i] = 2000;
    }
    r[i] = 0;

    for (k = 2800; k > 0; k -= 14)
    {
      d = 0;

      i = k;
      for (;;)
      {
        d += r[i] * 10000;
        b = 2 * i - 1;

        r[i] = d % b;
        d /= b;
        i--;
        if (i == 0)
          break;
        d *= i;
      }
      printf("%.4d", c + d / 10000);
      c = d % 10000;
    }
    igitt++;
  }
  printf("\nnon-initial time: %f\n", thymekeep());
  return 0;
}
