#define N 100
int count = 0 ;

void producer(void){
	int item;
	while(TRUE){
		iterm = produce_item();
		if(count==N) sleep();
		insert_iterm(item);
		count ++;     /*将缓冲区的数据项计数器增1*/
		if(count==1)
			wakeup(consumer);
	}
}


void consumer(void){
	int item;

	while(TRUE)
	{
		if(count==0) sleep(); /*如果缓冲区为空，则进入休眠状态*/
		item = remove_item();
		count--;
		if(count==N-1) 
			wakeup(producer); /*缓冲区满吗*/
		consume_item(item);
	}
}
