/**********************************************************************
 *                                版权声明
 *                   Copyright(c) 苏州惠生电子科技有限公司  
 *                                2011~2018                                 
 * ********************************************************************
 * 文 件 名: ProxyDLD.cs   
 *  
 * 作者                    属性                   修改时间
 * 50236193               创建                 2020/04/30 23:11:04
 * 
 * 功能描述: 动态加载非托管 DLL
 * ********************************************************************/
namespace DllOperator
{
    using System;
    using System.Collections.Generic;
    using System.Runtime.InteropServices;
    using System.Text;

    public class ProxyDLD
    {
        /// <summary>
        /// 错误代码
        /// </summary>
        public int LastError { get; private set; }

        /// <summary>  
        /// Loadlibrary 返回的函数库模块的句柄
        /// </summary>  
        private IntPtr hModule = IntPtr.Zero;

        [DllImport("kernel32.dll", SetLastError = true)]
        internal static extern IntPtr LoadLibrary(string lpFileName);

        [DllImport("kernel32.dll", SetLastError = true)]
        internal static extern IntPtr GetProcAddress(IntPtr hModule, string lpProcName);

        [DllImport("kernel32.dll", SetLastError = true)]
        internal static extern bool FreeLibrary(IntPtr hModule);

        /// <summary>  
        /// 装载 dll
        /// </summary>  
        public bool Load(string lpFileName)
        {
            if (this.hModule != null) {
                FreeLibrary(hModule);
            }

            this.hModule = LoadLibrary(lpFileName);
            if (IntPtr.Zero == this.hModule) {
                this.LastError = Marshal.GetLastWin32Error();
                //Console.WriteLine(lpFileName + " Module Load Fail, errorcode=" + this.LastError);
                return false;
            }

            return true;
        }

        /// <summary>  
        /// 卸载 dll  
        /// </summary>  
        public bool Unload()
        {
            bool ret = FreeLibrary(this.hModule);
            if (!ret) {
                this.LastError = Marshal.GetLastWin32Error();
                //Console.WriteLine("Module Unload Fail, errorcode=" + this.LastError);
                return false;
            }

            this.hModule = IntPtr.Zero;
            return ret;
        }

        /// <summary>
        /// 获取函数委托 
        /// </summary>
        public Delegate GetApi(string apiName, Type t)
        {
            if (IntPtr.Zero == this.hModule) {
                //Console.WriteLine("Module Not Loaded, please import *.dll first");
                return null;
            }

            IntPtr api = GetProcAddress(this.hModule, apiName);
            if (IntPtr.Zero == api) {
                this.LastError = Marshal.GetLastWin32Error();
                //Console.WriteLine(apiName + " Not Found, errorcode=" + this.LastError);
                return null;
            }

            return Marshal.GetDelegateForFunctionPointer(api, t);
        }
    }
}
