#ifndef _PRINT_CONTROL_HPP_
#define _PRINT_CONTROL_HPP_

/**
 *
 *@file
 *
 *@author
 *
 *@data
 *
 *@version
 *
 *@brief
 *
 *@copyright
 *
 */

#include <cstdio>
#include <cstdlib>

/** 调试输出级别 */
#define NONE 0
#define ERROR 1
#define WARN 2
#define INFO 3
#define ENTRY 4
#define DEBUG 5

/** 需要定义PRINT_LEVEL */
#define PRINT_LEVEL DEBUG


#define PRINT_PURE(level, ...)                                                      \
  do {                                                                         \
    if (level <= PRINT_LEVEL) {                                                \
      printf("[" #level "]>>" __VA_ARGS__);                                    \
    }                                                                          \
  } while (0);

#define PRINT(level, ...)                                                      \
  do {                                                                         \
    if (level <= PRINT_LEVEL) {                                                \
      printf("<<File:%s  Line:%d  Function:%s>> \n", __FILE__, __LINE__,       \
             __FUNCTION__);                                                    \
      printf("[" #level "]>>" __VA_ARGS__);                                    \
    }                                                                          \
  } while (0);

#define PRINT_ERROR(...)                                                       \
  do {                                                                         \
    PRINT(ERROR, ##__VA_ARGS__);                                                 \
    printf("\n");                                                              \
  } while (0);

#define PRINT_WARN(...)                                                        \
  do {                                                                         \
    PRINT(WARN, ##__VA_ARGS__);                                                  \
    printf("\n");                                                              \
  } while (0);

#define PRINT_INFO(...)                                                        \
  do {                                                                         \
    PRINT(INFO, ##__VA_ARGS__);                                                  \
    printf("\n")                                                               \
  } while (0);

#define PRINT_ENTRY(...)                                                       \
  do {                                                                         \
    PRINT(ENTRY, ##__VA_ARGS__);                                                 \
    printf("\n");                                                              \
  } while (0);

#define PRINT_DEBUG(...)                                                       \
  do {                                                                         \
    PRINT(DEBUG, ##__VA_ARGS__);                                                 \
    printf("\n");                                                              \
  } while (0);

#endif //头文件
