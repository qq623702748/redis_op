#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "redis_op.h"

int main(int argc, char *argv[])
{
    int ret = 0;
    //连接数据库
    redisContext *conn = NULL;

    conn = rop_connectdb_nopwd("127.0.0.1", "6379");

    //set foo  nihao
    ret = rop_set_string(conn, "foo", "nihao");
    if (ret == 0) {
        printf("set succ!\n");
    }
    else {
        printf("set fail\n");
    }

    char value[1024] = {0};
    RVALUES v = &value;
    ret = rop_get_string(conn,"foo",v);
    if (ret == 0)
    {
        printf("get value:%s\n",value);
    }
    else 
    {
        printf("get value error!\n");
    }
    //释放数据库
    rop_disconnect(conn);


	return 0;
}
