/**
*使用信号量的生产者消费者问题
*/

#define N 100
typedef int demaphore;
semaphore mutex = 1;
semaphore empty = N;
semaphore full = 0;

void produce(void){
    int iterm;
    
    while(TRUE){
        item = produce_item();/*产生放在缓冲区的一些数据*/
        down(&empty);          /*将空槽数目减一*/
        down(&mutex);          /*进入临界区*/
        insert_item(item);     /*将新数据放入到缓冲区*/
        up(*mutex);
        up (&full);            /*将满槽的数目加1*/
    }
}

void consumer(void){
    int item;

    while(TRUE){
        down(&full)           /*将满槽数目减1*/
        down(&mutex)          /*进入临界区*/
        item=remove_item();   /*从缓冲区中取出来数据项*/
        up(&mutex);           /*离开临界区*/
        up(&empty)            /*将空槽数目加1*/
        consume_item(item);   /*处理数据项*/
    }
}