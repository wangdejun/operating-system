#define N 100

int count = 0;
/**
 * [producer description]
 * 生产者有义务唤醒消费者进程
 */
void producer(void){
	int item;
	while(TRUE){
		item = produce_item();
		if(count == N)
			sleep();
		insert_item(item);
		count++;
		if(count==1){
			wakeup(consumer)
		}
	}
}

/**
 * [consumer description]
 * 消费者有义务唤醒Producer进程
 */
void consumer(void){
	int item;
	while(TRUE){
		if(count==0)
			sleep();
		item = remove_item();
		count--;
		if(count==N-1)
			wakeup(producer);
		consume_item(item);
	}
}
