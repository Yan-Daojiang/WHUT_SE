#include<stdio.h>


#include "model.h"
#include "global.h"
//将计费信息保存到billing.ams文件中
int saveBilling(const Billing* pBilling, const char* pPath)
{
	FILE* fp = NULL;   // 文件结构体指针

	// 以追加方式打开一个二进制文件
	if((fp = fopen(pPath, "ab")) == NULL)
	{
		// 如果以追加方式失败，则以只写方式创建一个文件并打开
		if((fp = fopen(pPath, "wb")) == NULL)
		{
			return FALSE;
		}
	}

	// 将计费信息保存到文件中
	fwrite(pBilling, sizeof(Billing), 1, fp);

	// 关闭文件
	fclose(fp);

	return TRUE;
}