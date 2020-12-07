#include "print_ctrl_imp.h"
#include <cstdio>
#include <cstdlib>

#define LOG(frm, args...)                                                      \
  do {                                                                         \
    {                                                                          \
      printf("\033[0;33m[%s : %s : %d]\033[0m", __FILE__, __func__, __LINE__); \
      printf(frm, ##args);                                                     \
      printf("\n");                                                            \
    }                                                                          \
  } while (0);

int main(int argc, char **argv) {
    printf("print_level=%d\n",PRINT_LEVEL);
  LOG("hello world = %d", 2);
  PRINT_DEBUG("lee-shun=%d", 2);
  PRINT_WARN("lee-shun=%d", 2);
  PRINT_ERROR("lee-shun=%d", 2);
  PRINT_INFO("lee-shun=%d", 2);
  PRINT_ENTRY("lee-shun=%d", 2);
  return 0;
}
