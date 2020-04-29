#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int main()
{
    // __stdcall ���ù�Լ
    typedef void (__stdcall *pfunc)(void);

    // ���ض�̬��
    HMODULE hModule = LoadLibrary(_T("../../dllstdcall/libhello.dll"));
    if (NULL == hModule)
    {
        printf("Dll Load Fail, errorcode=%ld.", GetLastError());
        return -1;
    }

    // ��ȡ������������ڵ�ַ
    pfunc pf = (pfunc)GetProcAddress(hModule, "sayHello");
    if (NULL == pf)
    {
        printf("Func Not Found, errorcode=%ld.", GetLastError());
        return -2;
    }

    // ����
    pf();

    // ж�ض�̬��
    BOOL ret = FreeLibrary(hModule);
    if (FALSE == ret)
    {
        printf("Dll Free Fail, errorcode=%ld.", GetLastError());
        return -3;
    }

    system("pause");
    return 0;
}