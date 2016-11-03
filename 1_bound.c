//a
while(TRUE){
	while(turn!=0)
		critical_region();
		turn = 1;
		noncritical_region();
}
//b
while(TRUE){
	while(turn!=1)
		critical_region();
		turn = 1;
		noncritical_region();
}
//Peterson Algrithm
//一种互斥算法
#define FALSE 0
#define TRUE 1
#define N   2  /*进程数量*/

int turn /*现在轮到谁*/
int interested[N]

void enter_region(int process);
{
	int other;

	other = 1-process;
	interested[process]=TRUE;
	turn = process;
	while(turn==process && interested[other]==TRUE);
}

Void leave_region(int process){
	interested[process]=FALSE
}


//use TSL command enter region and leave Region

enter_region:
		TSL REGISTER,LOCK
		CMP REGISTER, #0
		JNE enter_region
		RET |返回调用者，进入了临界区

leave_region:
		MOVE LOCK,#0
		RET

