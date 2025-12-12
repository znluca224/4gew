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
  double thzm = thymekeep(NULL);
  printf("Initial time: %f\n", thzm);

  printf("\nnon-initial time: %f\n", thymekeep());
  return 0;
}
