#include <time.h>//包含时间类型头文件
#include <stdio.h>//包含sscanf()函数头文件

/********************************************
[函数名]timeToString
[功能]将time_t类型文件转换为字符串，字符串格式为“年-月-日 时：分”
[参数]time_t t:需要转换的时间，char*pBuf:转换之后的字符串
[返回值]void
***********************************************/
void timeToString(time_t t, char* pBuf)
{
	struct tm * timeinfo;
	timeinfo= localtime(&t);
	strftime(pBuf, 20, "%Y-%m-%d %H:%M", timeinfo);
}
/**********************
[函数名]stringToTime
[功能] 将格式为“年-月-日 时：分”的字符串转换为time_t 类型时间
[参数]char*pTime “年-月-日 时；分 格式的字符串
***********************/
time_t stringToTime(char* pTime)
{
	struct tm tm1;
	time_t time1;
	sscanf_s(pTime, "%d-%d-%d %d:%d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday, &tm1.tm_hour, &tm1.tm_min);
	tm1.tm_year -= 1900;//年份从1900开始
	tm1.tm_mon -= 1;//月份为0~11
	tm1.tm_sec = 0;
	tm1.tm_isdst = -1;

	time1 = mktime(&tm1);

	return time1;





}
