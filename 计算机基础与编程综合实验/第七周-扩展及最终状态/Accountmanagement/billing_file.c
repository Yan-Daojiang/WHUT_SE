#include<stdio.h>


#include "model.h"
#include "global.h"
//���Ʒ���Ϣ���浽billing.ams�ļ���
int saveBilling(const Billing* pBilling, const char* pPath)
{
	FILE* fp = NULL;   // �ļ��ṹ��ָ��

	// ��׷�ӷ�ʽ��һ���������ļ�
	if((fp = fopen(pPath, "ab")) == NULL)
	{
		// �����׷�ӷ�ʽʧ�ܣ�����ֻд��ʽ����һ���ļ�����
		if((fp = fopen(pPath, "wb")) == NULL)
		{
			return FALSE;
		}
	}

	// ���Ʒ���Ϣ���浽�ļ���
	fwrite(pBilling, sizeof(Billing), 1, fp);

	// �ر��ļ�
	fclose(fp);

	return TRUE;
}