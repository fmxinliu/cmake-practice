|    调用规约    | C 风格 | def模块 |       导出函数名        |
| :--------: | :--: | :---: | :----------------: |
|  `cdecl`   |  ✘   |   ✘   | *?sayHello@@YAXXZ* |
| `fastcall` |  ✘   |   ✘   | *?sayHello@@YIXXZ* |
| `stdcall`  |  ✘   |   ✘   | *?sayHello@@YGXXZ* |
|  `cdecl`   |  ✔   |   ✘   |     *sayHello*     |
| `fastcall` |  ✔   |   ✘   |   *@sayHello@0*    |
| `stdcall`  |  ✔   |   ✘   |   *_sayHello@0*    |
|  `cdecl`   |  ✘   |   ✔   |     *sayHello*     |
| `fastcall` |  ✘   |   ✔   |     *sayHello*     |
| `stdcall`  |  ✘   |   ✔   |     *sayHello*     |
|  `cdecl`   |  ✔   |   ✔   |     *sayHello*     |
| `fastcall` |  ✔   |   ✔   |     *sayHello*     |
| `stdcall`  |  ✔   |   ✔   |     *sayHello*     |
