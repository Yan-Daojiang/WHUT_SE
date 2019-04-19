
#include<time.h>
#include"model.h"
#include"global.h"
#include"card_file.h"
#include"tool.h"


int addcard(Card card){							//ÃÌº”ø®

return saveCard(&card,CARDPATH);
}

int querycard(char bname[50],Card *pCard){			//≤È’“ø®
	int i=0;
	int flag=0;
	flag=isExsit(bname,pCard, CARDPATH);

	
		return flag;}
