/* 加入字符设备注册和注销 */
static struct file_operations test_fops;

/* 驱动入口函数 */
static int __init xxx_init(void)
{
    /* 入口函数具体内容 */
    int retvalue = 0;

    /* 注册字符设备驱动 */
    retvalue = register_chrdev(200, "chrtest", &test_fops); 
    // 200为主设备号, "chrtest"为设备名, &test_fops为文件操作集
    if(retvalue < 0)
    {
        /* 注册失败 */
        return -1;
    }
    return 0;
}

/* 驱动出口函数 */
static void __exit xxx_exit(void)
{
    /* 注销字符设备驱动 */
    unregister_chrdev(200, "chrtest"); 
    // 200为主设备号, "chrtest"为设备名
}

// 将上面两个函数指定为驱动的入口和出口函数
module_init(xxx_init);
module_exit(xxx_exit);