/* 添加LICENSE和作者信息 */
/* 字符设备驱动最终的模板 */

static int chrtest_open(struct inode *inode, struct file *filp)
{
    /* 打开设备时的操作 */
    return 0;
}

static ssize_t chrtest_read(struct file *filp, char __user *buf, size_t cnt, loff_t *offt)
{
    /* 读取设备时的操作 */
    return 0;
}

static ssize_t chrtest_write(struct file *filp, const char __user *buf, size_t cnt, loff_t *offt)
{
    /* 写入设备时的操作 */
    return 0;
}

static int chrtest_release(struct inode *inode, struct file *filp)
{
    /* 关闭设备时的操作 */
    return 0;
}

static struct file_operations test_fops = {
    .owner = THIS_MODULE,
    .open = chrtest_open,
    .read = chrtest_read,
    .write = chrtest_write,
    .release = chrtest_release
};

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

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DZP");