using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharp
{
    class Program
    {
        public delegate void SayHello();

        public void Invoker()
        {
            DllOperator.ProxyDLD dld = new DllOperator.ProxyDLD();
            if (!dld.Load("../../dllstdcall/libhello.dll")) {
                Console.WriteLine("Dll Load Fail, errorcode=" + dld.LastError);
                return;
            }

            SayHello func = (SayHello)dld.GetApi("sayHello", typeof(SayHello));
            if (null == func) {
                Console.WriteLine("Func Not Found, errorcode=" + dld.LastError);
                return;
            }

            func();

            if (!dld.Unload()) {
                Console.WriteLine("Dll Free Fail, errorcode=" + dld.LastError);
                return;
            }

            Console.WriteLine("Hello World");
        }

        static void Main(string[] args)
        {
            new Program().Invoker();
            Console.ReadKey();
        }
    }
}
