#include <pthread.h>
#include "atmoic.h"
#include <stdio.h>
#include <unistd.h>
 
// 定义一个原子变量
static atomic_t g_atomic = ATOMIC_INIT(1);
// 定义共享资源
static volatile int g_i = 0;
 
/* 定义线程处理函数 */
// #define atomic_dec_and_test(g_atomic) 1 
void *thr1_handle(void *arg)
{
    while (1) {
        if (atomic_dec_and_test(&g_atomic)) {
            printf("--> thread 1 : g_i = %d\n", ++g_i);
        }
        // ++g_i;
        atomic_inc(&g_atomic);
        sleep(1);
    }
 
    return NULL;   
}
 
void *thr2_handle(void *arg)
{
    while (1) {
        if (atomic_dec_and_test(&g_atomic)) {
            printf("--> thread 2 : g_i = %d\n", ++g_i);
        }
        // ++g_i;
        atomic_inc(&g_atomic);
        sleep(1);
    }
    return NULL;   
}
 
 
/* 主函数 */
int main()
{
    pthread_t tid1, tid2;
    if (pthread_create(&tid1, NULL, thr1_handle, NULL) != 0) {
        fprintf(stderr, "create thread1 failed!\n");
        return 1;
    }
    if (pthread_create(&tid2, NULL, thr2_handle, NULL) != 0) {  
        fprintf(stderr, "create thread2 failed!\n");
        return 2;
    }
    
    pthread_join(tid2, NULL);
    pthread_join(tid1, NULL);

 
    return 0;
}