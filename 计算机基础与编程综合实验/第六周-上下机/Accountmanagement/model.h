#ifndef MODEL_H
#define MODEL_H

// ���忨��Ϣ�ṹ��
typedef struct Card
{
	char aName[18];         // ����
	char aPwd[8];           // ����
	int  nStatus;           // ��״̬(0-δ�ϻ���1-�����ϻ���2-��ע����3-ʧЧ)
	time_t tStart;          // ����ʱ��
	time_t tEnd;            // ���Ľ�ֹʱ�� 
	float fTotalUse;        // �ۼƽ��
	time_t tLast;           // ���ʹ��ʱ��
	int nUseCount;          // ʹ�ô���
	float fBalance;         // ���
	int nDel;               // ɾ����ʶ 0-δɾ��,1-ɾ��
}Card;

// ���忨��Ϣ����������
typedef struct CardNode
{
	Card data;              // �������
	struct CardNode* next;  // ָ���¸�����ָ��
}CardNode, *lpCardNode;

// �Ʒ���Ϣ�ṹ��
typedef struct Billing
{
	char aCardName[18];    // ����
	time_t tStart;         // �ϻ�ʱ��
	time_t tEnd;           // �»�ʱ��
	float fAmount;         // ���ѽ��
	int nStatus;           // ����״̬��0-δ���㣬1-�Ѿ�����
	int nDel;              // ɾ����ʶ��0-δɾ��,1-ɾ��
}Billing;

// �Ʒ���Ϣ���
typedef struct BillingNode
{
	Billing data;
	struct BillingNode *next;
}BillingNode, *lpBillingNode;

// �ϻ���Ϣ�ṹ��
typedef struct LogonInfo
{
	char aCardName[18];    // �ϻ�����
	time_t tLogon;         // �ϻ�ʱ��
	float fBalance;        // �ϻ�ʱ�Ŀ����
}LogonInfo;

// �»���Ϣ�ṹ��
typedef struct SettleInfo
{
	char aCardName[18];   // ����
	time_t tStart;        // �ϻ�ʱ��
	time_t tEnd;          // �»�ʱ��
	float fAmount;        // ���ѽ��
	float fBalance;       // ���
}SettleInfo;

// ��ֵ�˷ѽṹ��
typedef struct Money
{
	char aCardName[18];  // ����
	time_t tTime;		 // ��ֵ�˷ѵ�ʱ��
	int nStatus;		 // ״̬��0-��ʾ��ֵ��1-��ʾ�˷�
	float fMoney;		 // ��ֵ�˷ѽ��
	int nDel;			 // ɾ����ʶ��0-δɾ��,1-ɾ��
}Money;

// ��ֵ�˷���Ϣ�ṹ��
typedef struct MoneyInfo
{
	char aCardName[18];  // ����
	float foney;        // ��ֵ�˷ѽ��
	float fBalance;      // ���
}MoneyInfo;

#endif