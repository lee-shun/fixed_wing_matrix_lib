#include <cstdio>
#include <cstdlib>
#include"print_control.h"

#define LOG(frm, args...)                                                       \
  do {                                                                         \
    {                                                                          \
      printf("\033[0;33m[%s : %s : %d]\033[0m", __FILE__, __func__, __LINE__); \
      printf(frm, ##args);                                                      \
      printf("\n");                                                            \
    }                                                                          \
  } while (0);

int main(int argc, char **argv){
LOG("hello world");
PRINT_ERROR("lee-shun=%d",2);
return 0;
}
