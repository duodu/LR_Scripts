#ifndef _GLOBALS_H 
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"






//--------------------------------------------------------------------
// Global Variables
struct vuser_info{
	char *bCode;
	char *bName;
	char *verificationCode;
	unsigned int likeability;
	unsigned int category;
};
struct vuser_info p;
unsigned int getCategory();
unsigned int getLikeability();

unsigned int tag_top_Status = 0;
unsigned int tag_over_Status = 0;
unsigned int tag_exit_Status = 0;
// long int T2Second(char *tt){
//
// 	char h[3],m[3],s[3];
//
// 	strncpy(h,tt,2);
// 	strncpy(m,tt+3,2);
// 	strncpy(s,tt+6,2);
//
// 	return atoi(h)*3600+atoi(m)*60+atoi(s);
//
// }


#endif // _GLOBALS_H
