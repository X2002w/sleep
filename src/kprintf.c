#include <stddef.h>
#define WIN32_LEAN_AND_MEAN
#include "windows.h"

#include "kprintf.h"


typedef int (*kwrite_fn)(void* ctx, const char* data, size_t len);

struct kwrite 
{
  kwrite_fn write;  

  void* ctx;  // 写入目标 HANDLE / buffer / 串口
  int err;
  size_t count; // 写入字节数
};

// 写入data到win 的句柄handle -> stdout/stderr/pip/file
static int kwrite_handle(void* ctx, const char* data, size_t len)
{
  HANDLE h = (HANDLE)ctx;
  if(h == NULL || h == INVALID_HANDLE_VALUE)
    return -1;

  while (len)
  {
    DWORD chunk = (len > 0x7fffffffu) ? 0x7fffffffu : (DWORD)len;
    DWORD written = 0;
    if (!WriteFile(h, data, chunk, &written, NULL))
      return -1;
    
    data += written;
    len -= written;
    if (written == 0)
      return -1;
  }
  return 0;
}

static int kvformat(struct kwrite* w, const char* fmt, va_list ap)
{
  const char* p = fmt;

}
