# win 下的 sleep demo

- 在不依赖CRL的情况下实现sleep调用

## Target

- gcc 只编译
- ld 直接链接
- linker script 可用, 不使用默认的链接脚本(其实是使用的, 但是自定义程序入口)
- 生成PE头正常 且exe 可运行
