#include <cstdlib>
#include <cstdio>

#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();

  int size = 10;
  srand(2);
  int r = rand() % 10;
  printf ("%d\n", r) ;
  return 0;
}
