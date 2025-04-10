#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int main()
{
    // __stdcall 调用规约
    typedef void (__stdcall *pfunc)(void);

    // 加载动态库
    HMODULE hModule = LoadLibrary(_T("../../dllstdcall/libhello.dll"));
    if (NULL == hModule)
    {
        printf("Dll Load Fail, errorcode=%ld.", GetLastError());
        return -1;
    }

    // 获取导出函数的入口地址
    pfunc pf = (pfunc)GetProcAddress(hModule, "sayHello");
    if (NULL == pf)
    {
        printf("Func Not Found, errorcode=%ld.", GetLastError());
        return -2;
    }

    // 调用
    pf();

    // 卸载动态库
    BOOL ret = FreeLibrary(hModule);
    if (FALSE == ret)
    {
        printf("Dll Free Fail, errorcode=%ld.", GetLastError());
        return -3;
    }

    system("pause");
    return 0;
}