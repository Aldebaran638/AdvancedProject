#pragma once
#ifndef _ARREDERDO_H_
#define _ARREDERDO_H_ 
#include "../DoInclude.h"
class ArredetDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, room, Room);
	CC_SYNTHESIZE(string, ow, Ow);
	CC_SYNTHESIZE(string, owt, Owt);
	CC_SYNTHESIZE(string, area, Area);
	CC_SYNTHESIZE(string, ei, Ei);
	CC_SYNTHESIZE(string, st, St);
	CC_SYNTHESIZE(string, et, Et);
	CC_SYNTHESIZE(string, ad, Ad);
	CC_SYNTHESIZE(string, aa, Aa);


public:
	ArredetDO()
	{
		id = " ";
		room = "";
		ow = "";
		owt = "";
		ei = "";
		st = "";
		et = "";
		ad = "";
		aa = "";
	}
};

#endif 