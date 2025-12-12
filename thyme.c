// #include <header.h>
#include <time.h>
#include <stdlib.h>

/*needs: Some way to store the initial time value (in header.h)
 also: way to compare current and initial time to get elapsed time
*/

time_t initial_time = 0;
time_t temp_time = 0;
int thymekeep(char which)
{
  switch (which) // t = total, d = delta, i = initialize (could be any character, really)
  {
  case 't': // how long has the game been running for
  {
    time_t currytime = time(NULL) - initial_time;
    return currytime;
    break;
  }
  case 'd': // has it been a second since the last time the funtion was called
  {
    time_t timecheck = time(NULL);
    // printf("\ntimecheck: %f, temp_time: %f", timecheck, temp_time);
    time_t currytime = timecheck - temp_time; // time difference between last and current check
    temp_time = timecheck;
    if (currytime >= 1)
    {
      return currytime; // returns the elapsed time if is has been at least a second
    }
    return 0; // returns 0 if less than a second has elapsed
  }
  default: // initialize
  {
    temp_time = time(NULL);
    initial_time = temp_time;
    return 0; // no time has passed since the function was called for the first time (because this is that first time)
  }
  }
}

void timespace(int rec)
{
  int igitt = 0;
  while (igitt < rec)
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
      // printf("%.4d", c + d / 10000);
      c = d % 10000;
    }
    igitt++;
  }
}

int main()
{
  // double dtime = thymekeep('d');

  printf("\nInitial time: %f", thymekeep('i'));
  timespace(1000);

  time_t dtime = thymekeep('d');
  if (dtime == 0)
  {
    printf("\nno time has elapsed");
  }
  else
  {
    printf("\nIt has been %d seconds", dtime);
  }

  printf("\nnon-initial time: %f", thymekeep('t'));
  timespace(1000);

  dtime = thymekeep('d');
  if (dtime == 0)
  {
    printf("\nno time has elapsed");
  }
  else
  {
    printf("\nIt has been %d seconds", dtime);
  }

  printf("\nnon-initial time: %f\n", thymekeep('t'));
  timespace(2000);
  dtime = thymekeep('d');
  if (dtime == 0)
  {
    printf("\nno time has elapsed");
  }
  else
  {
    printf("\nIt has been %ld seconds", (long)dtime);
  }

  return 0;
}
