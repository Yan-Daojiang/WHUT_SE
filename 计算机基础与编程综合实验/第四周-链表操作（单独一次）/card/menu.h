//����ѧ����Ϣ�ṹ��
typedef struct Student
{
    long num;
	float score;
	struct Student *next;
};

//��غ�������
void outmenu();
struct Student *creat(void);
void print(struct Student *p);
void find(struct Student *pt,long num);	//��������