/* 字符设备驱动模块加载和卸载函数模板 */

/* 驱动入口函数 */
static int __init xxx_init(void)
{
    /* 入口函数具体内容 */
    return 0;
}

/* 驱动出口函数 */
static void __exit xxx_exit(void)
{
    /* 出口函数具体内容 */
}

// 将上面两个函数指定为驱动的入口和出口函数
module_init(xxx_init);
module_exit(xxx_exit);