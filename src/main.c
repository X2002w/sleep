#define WIN32_LEAN_AND_MEAN
#include "windows.h"

int parse_int(const char* str)
{
  int number = 0;
  // str -> 14 '\0'
  while(*str != '\0')
  {
    if (*str < '0' || *str > '9')
      return number;

    number = number * 10 + (*str - '0');
    str++;
  }
  return number;
}
static void write_str(const char* s)
{
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  if (h == NULL || h == INVALID_HANDLE_VALUE) return;

  // strlen (自己算，避免 CRT)
  const char* p = s;
  while (*p) p++;

  DWORD written = 0;
  WriteFile(h, s, (DWORD)(p - s), &written, NULL);
}



// 跳过cmd开头空白部分
static const char* skip_spaces(const char* cmd)
{
  while (*cmd == ' ' || *cmd == '\t')
    cmd++;
  return cmd;
}

static const char* skip_token(const char* cmd)
{
  while(*cmd && *cmd != ' ')
  {
    cmd++;
  }
  return cmd;
}

static int get_arg1(char* out, int out_cap)
{
  // 获取命令行string指针
  const char* cmd = GetCommandLineA();
  if (!cmd) 
    return 0;
  
  const char* p = skip_spaces(cmd);
  p = skip_token(p);
  p = skip_spaces(p);

  if (*p == '\0')
    return 0;

  int n = 0;
  while(*p && *p != ' ' && *p != '\t' && n < out_cap -1)
    out[n++] = *p++;

  out[n] = '\0';
  return n > 0;
}

void _start(void)
{
  char arg1[64];
  
  if(!get_arg1(arg1, (int)sizeof(arg1)))
  {
    write_str("usage: sleep <seocnds> ...\n");

    ExitProcess(0);
  }
  
  int seconds = parse_int(arg1);
  if (seconds < 0)
    seconds = 0;

  Sleep(seconds * 1000);
  ExitProcess(0);
}