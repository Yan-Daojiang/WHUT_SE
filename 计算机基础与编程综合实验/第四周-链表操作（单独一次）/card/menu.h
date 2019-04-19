//定义学生信息结构体
typedef struct Student
{
    long num;
	float score;
	struct Student *next;
};

//相关函数声明
void outmenu();
struct Student *creat(void);
void print(struct Student *p);
void find(struct Student *pt,long num);	//遍历查找