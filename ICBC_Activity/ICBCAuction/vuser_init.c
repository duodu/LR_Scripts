vuser_init()
{
	char *getVerificationCode(unsigned int category);
	//int currr,now;
	//char ext[10];

	
	p.bCode = lr_eval_string("{bCode}");
	p.bName = lr_eval_string("{bName}");
	//strcpy(ext,p.bCode+13);
	p.likeability = getLikeability();
	p.category = getCategory();
	p.verificationCode = getVerificationCode(p.category);
	//lr_log_message(ext);
	strcat(p.verificationCode,p.bCode+13);
	lr_log_message(p.verificationCode);

	lr_save_string(p.bCode,"BC");
	lr_save_string(p.bName,"BN");
	lr_save_string(lr_eval_string("{BN}"),"str_bName");
	web_convert_param("str_bName", "SourceEncoding=HTML","TargetEncoding=URL", LAST );
	lr_save_string(p.verificationCode,"VC");
	//lr_save_string(itoa(p.category),"GN");
	
	lr_log_message("%s~~~~%s",p.bCode,p.bName);
	lr_log_message("%d~~~%d",p.likeability,p.category);
	lr_log_message("%s",p.verificationCode);

	//业务开始
	web_reg_find("Text=toActivity.do","SaveCount=Act_ct",LAST);
	//工行首页
	lr_start_transaction("icbc_index");

	web_url("icbc.do",
		"URL=http://icbc.99wuxian.com/wap/icbc.do",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t55.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=http://pic.99wuxian.com/mall/wap/sftwap/image/mybg.jpg", ENDITEM,
		//"URL=http://www.google-analytics.com/ga.js", ENDITEM,
		//"URL=http://www.google-analytics.com/__utm.gif?utmwv=5.4.2&utms=105&utmn=1902809008&utmhn=icbc.99wuxian.com&utmcs=UTF-8&utmsr=1440x900&utmvp=1423x723&utmsc=24-bit&utmul=zh-cn&utmje=1&utmfl=11.7%20r700&utmdt=99%E6%97%A0%E9%99%90&utmhid=119597439&utmr=-&utmp=%2Fwap%2Ficbc.do&utmht=1369797374100&utmac=UA-29240412-2&utmcc=__utma%3D127319493.1618945018.1363572430.1369729183.1369794315.32%3B%2B__utmz%3D127319493.1363845158.6.2.utmcsr%3D10.48.196.232%3A8780%7Cutmccn%3D(referral)%7Cutmcmd%3Dreferral%7Cutmcct%3D%2Fwap%2Fmyaccount%2FsaveAddress.do%3B&utmu=qB~", ENDITEM,
		LAST);

	if (atoi(lr_eval_string("{Act_ct}")) > 0) {
	lr_end_transaction("icbc_index", LR_PASS);
	}else{
	lr_end_transaction("icbc_index", LR_FAIL);
	}

	lr_think_time(1);

// 	web_reg_find("Text=branchList","SaveCount=branchList_ct",LAST);
// 	//进入工行活动
// 	lr_start_transaction("toActivity");
// 	web_url("toActivity.do",
// 		"URL=http://icbc.99wuxian.com/wap/toActivity.do?secondConfigId=2",
// 		"TargetFrame=",
// 		"Resource=0",
// 		"RecContentType=text/html",
// 		"Referer=http://icbc.99wuxian.com/wap/icbc.do",
// 		"Snapshot=t56.inf",
// 		"Mode=HTML",
// 		EXTRARES,
// 		"URL=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/ActivityPat/ActivityPat_all.css", ENDITEM,
// 		"URL=http://pic.99wuxian.com/mall/wap/img/xhtml/mybg.jpg", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", ENDITEM,
// 		//"URL=http://www.google-analytics.com/ga.js", "Referer=http://icbc.99wuxian.com/wap/toActivity.do?secondConfigId=2", ENDITEM,
// 		//"URL=http://www.google-analytics.com/__utm.gif?utmwv=5.4.2&utms=106&utmn=746005637&utmhn=icbc.99wuxian.com&utmcs=UTF-8&utmsr=1440x900&utmvp=1440x723&utmsc=24-bit&utmul=zh-cn&utmje=1&utmfl=11.7%20r700&utmdt=99%E6%97%A0%E9%99%90&utmhid=1217125690&utmr=0&utmp=%2Fwap%2FtoActivity.do%3FsecondConfigId%3D2&utmht=1369797376874&utmac=UA-29240412-2&utmcc=__utma%3D127319493.1618945018.1363572430.1369729183.1369794315.32%3B%2B__utmz%3D127319493.1363845158.6.2.utmcsr%3D10.48.196.232%3A8780%7Cutmccn%3D(referral)%7Cutmcmd%3Dreferral%7Cutmcct%3D%2Fwap%2Fmyaccount%2FsaveAddress.do%3B&utmu=qB~", "Referer=http://icbc.99wuxian.com/wap/toActivity.do?secondConfigId=2", ENDITEM,
// 		LAST);
// 	if (atoi(lr_eval_string("{branchList_ct}")) > 0) {
// 	lr_end_transaction("toActivity", LR_PASS);
// 	}else{
// 	lr_end_transaction("toActivity", LR_FAIL);
// 	}
//
	lr_think_time(1);

	web_reg_find("Text=branchActList","SaveCount=branchActList_ct",LAST);
	//分行列表
	lr_start_transaction("branchList");

	web_url("branchList.do",
		"URL=http://icbc.99wuxian.com/wap/branchList.do",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://icbc.99wuxian.com/wap/toActivity.do?secondConfigId=2",
		"Snapshot=t57.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/ActivityPat/ActivityPat_all.css", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/img/xhtml/mybg.jpg", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", ENDITEM,
		//"URL=http://www.google-analytics.com/ga.js", ENDITEM,
		//"URL=http://www.google-analytics.com/__utm.gif?utmwv=5.4.2&utms=107&utmn=1044967314&utmhn=icbc.99wuxian.com&utmcs=UTF-8&utmsr=1440x900&utmvp=1423x723&utmsc=24-bit&utmul=zh-cn&utmje=1&utmfl=11.7%20r700&utmdt=99%E6%97%A0%E9%99%90&utmhid=113083883&utmr=0&utmp=%2Fwap%2FbranchList.do&utmht=1369797378438&utmac=UA-29240412-2&utmcc=__utma%3D127319493.1618945018.1363572430.1369729183.1369794315.32%3B%2B__utmz%3D127319493.1363845158.6.2.utmcsr%3D10.48.196.232%3A8780%7Cutmccn%3D(referral)%7Cutmcmd%3Dreferral%7Cutmcct%3D%2Fwap%2Fmyaccount%2FsaveAddress.do%3B&utmu=qB~", ENDITEM,
		LAST);
	if (atoi(lr_eval_string("{branchActList_ct}")) > 0) {
	lr_end_transaction("branchList", LR_PASS);
	}else{
	lr_end_transaction("branchList", LR_FAIL);
	}
	//lr_save_string(lr_eval_string("{bName}"),"str_bName");

	lr_think_time(2);

	//web_convert_param("str_bName", "SourceEncoding=HTML","TargetEncoding=URL", LAST ); 
	web_reg_find("Text=doubleFan","SaveCount=doubleFan_ct",LAST);
	//分行活动列表
	lr_start_transaction("branchActList");

	web_url("branchActList.do",
		"URL=http://icbc.99wuxian.com/wap/branchActList.do?bCode={BC}&bName={str_bName}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://icbc.99wuxian.com/wap/branchList.do",
		"Snapshot=t58.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/ActivityPat/ActivityPat_all.css", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/img/xhtml/mybg.jpg", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", ENDITEM,
		//"URL=http://www.google-analytics.com/ga.js", "Referer=http://icbc.99wuxian.com/wap/branchActList.do?bCode=ICBCCategory_HN&bName=%E6%B5%B7%E5%8D%97%E5%88%86%E8%A1%8C", ENDITEM,
		//"URL=http://www.google-analytics.com/__utm.gif?utmwv=5.4.2&utms=108&utmn=1439031650&utmhn=icbc.99wuxian.com&utmcs=UTF-8&utmsr=1440x900&utmvp=1440x723&utmsc=24-bit&utmul=zh-cn&utmje=1&utmfl=11.7%20r700&utmdt=99%E6%97%A0%E9%99%90&utmhid=787697464&utmr=0&utmp=%2Fwap%2FbranchActList.do%3FbCode%3DICBCCategory_HN%26bName%3D%2525E6%2525B5%2525B7%2525E5%25258D%252597%2525E5%252588%252586%2525E8%2525A1%25258C&utmht=1369797380541&utmac=UA-29240412-2&utmcc=__utma%3D127319493.1618945018.1363572430.1369729183.1369794315.32%3B%2B__utmz%3D127319493.1363845158.6.2.utmcsr%3D10.48.196.232%3A8780%7Cutmccn%3D(referral)%7Cutmcmd%3Dreferral%7Cutmcct%3D%2Fwap%2Fmyaccount%2FsaveAddress.do%3B&utmu=qB~", "Referer=http://icbc.99wuxian.com/wap/branchActList.do?bCode=ICBCCategory_HN&bName=%E6%B5%B7%E5%8D%97%E5%88%86%E8%A1%8C", ENDITEM,
		LAST);

	if (atoi(lr_eval_string("{doubleFan_ct}")) > 0) {
	lr_end_transaction("branchActList", LR_PASS);
	}else{
	lr_end_transaction("branchActList", LR_FAIL);
	}

	lr_think_time(2);

	do{

	web_reg_find("Text=branchActMdseDetail","SaveCount=Detail_ct",LAST);
	//获取用户选择的分组和商品
	switch(p.category){
	case 1:
		web_reg_save_param("mc_arr","LB=ac=icbcAuction&mc=","RB=&gc=G1initial","Ord=all","Notfound=warning",LAST);
		lr_save_string("G1initial","GC");
		web_reg_save_param("beginTime","LB=sellBeginTimeStemp :\'","RB=\',","SaveOffset=6","Ord=1","Notfound=warning",LAST);
        break;
	case 2:
		web_reg_save_param("mc_arr","LB=ac=icbcAuction&mc=","RB=&gc=G2advance","Ord=all","Notfound=warning",LAST);
		lr_save_string("G2advance","GC");
		web_reg_save_param("beginTime","LB=sellBeginTimeStemp :\'","RB=\',","Ord=2","SaveOffset=6","Notfound=warning",LAST);
        break;
	case 3:
		web_reg_save_param("mc_arr","LB=ac=icbcAuction&mc=","RB=&gc=G3master","Ord=all","Notfound=warning",LAST);
		lr_save_string("G3master","GC");
		web_reg_save_param("beginTime","LB=sellBeginTimeStemp :\'","RB=\',","Ord=3","SaveOffset=6","Notfound=warning",LAST);
        break;
	case 4:
		web_reg_save_param("mc_arr","LB=ac=icbcAuction&mc=","RB=&gc=G4super","Ord=all","Notfound=warning",LAST);
		lr_save_string("G4super","GC");
		web_reg_save_param("beginTime","LB=sellBeginTimeStemp :\'","RB=\',","Ord=4","SaveOffset=6","Notfound=warning",LAST);
        break;
    default:
        lr_error_message("Can not find MDSE group");

	}

	
	//分组商品列表
	lr_start_transaction("branchActMdseList");
	web_url("branchActMdseList.do",
		"URL=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={qCode}&actName=%E6%8A%A2%E6%8B%8D",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://icbc.99wuxian.com/wap/branchActList.do?bCode={BC}&bName={str_bName}",
		"Snapshot=t59.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/ActivityPat/ActivityPat_all.css", ENDITEM,
		//"URL=http://www.google-analytics.com/ga.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={qCode}&actName=%E6%8A%A2%E6%8B%8D", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/config.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={qCode}&actName=%E6%8A%A2%E6%8B%8D", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/img/xhtml/mybg.jpg", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/plugs/sea/plugin-shim.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={qCode}&actName=%E6%8A%A2%E6%8B%8D", ENDITEM,
		//"URL=http://www.google-analytics.com/__utm.gif?utmwv=5.4.2&utms=109&utmn=1471220694&utmhn=icbc.99wuxian.com&utmcs=UTF-8&utmsr=1440x900&utmvp=1440x723&utmsc=24-bit&utmul=zh-cn&utmje=1&utmfl=11.7%20r700&utmdt=99%E6%97%A0%E9%99%90&utmhid=780621054&utmr=0&utmp=%2Fwap%2FbranchActMdseList.do%3Fac%3DicbcAuction%26bCode%3DICBCCategory_HN%26cCode%3D45%26qCode%3Ds2%26actName%3D%2525E6%25258A%2525A2%2525E6%25258B%25258D&utmht=1369797382604&utmac=UA-29240412-2&utmcc=__utma%3D127319493.1618945018.1363572430.1369729183.1369794315.32%3B%2B__utmz%3D127319493.1363845158.6.2.utmcsr%3D10.48.196.232%3A8780%7Cutmccn%3D(referral)%7Cutmcmd%3Dreferral%7Cutmcct%3D%2Fwap%2Fmyaccount%2FsaveAddress.do%3B&utmu=qB~", "Referer=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={qCode}&actName=%E6%8A%A2%E6%8B%8D", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/countdown.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={qCode}&actName=%E6%8A%A2%E6%8B%8D", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/common/utils.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={qCode}&actName=%E6%8A%A2%E6%8B%8D", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/detail.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={qCode}&actName=%E6%8A%A2%E6%8B%8D", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/list.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={qCode}&actName=%E6%8A%A2%E6%8B%8D", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/plugs/lib/jquery-1.8.3.min.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={qCode}&actName=%E6%8A%A2%E6%8B%8D", ENDITEM,
		LAST);

	if (atoi(lr_eval_string("{Detail_ct}")) > 0) {
	lr_end_transaction("branchActMdseList", LR_PASS);
	}else{
	lr_end_transaction("branchActMdseList", LR_FAIL);
	}
	}while (atol(lr_eval_string("{currtime}")) <= atol(lr_eval_string("{beginTime}")));

	if (lr_paramarr_len("mc_arr") == 0) {
		lr_exit(LR_EXIT_VUSER,LR_FAIL);
	}
	lr_think_time(3);

	web_reg_find("Text=userName","SaveCount=userName_ct",LAST);
	if (lr_paramarr_len("mc_arr") < 6 ) {
		lr_save_string(lr_paramarr_random("mc_arr"),"MC");
	}else{
	
	switch (p.likeability) {
	case 1:
		lr_save_string(lr_eval_string("{mc_arr_1}"),"MC");
		break;
	case 2:
		lr_save_string(lr_eval_string("{mc_arr_3}"),"MC");
		break;
	case 3:
		lr_save_string(lr_eval_string("{mc_arr_5}"),"MC");
		break;
	case 4:
		if (lr_paramarr_len("mc_arr")<=6) {
			lr_save_string(lr_eval_string("{mc_arr_5}"),"MC");
		}
		lr_save_string(lr_eval_string("{mc_arr_7}"),"MC");
		break;
	default:
		lr_error_message("Can not find MDSE");
	}
	}
	//商品详情跳转到登录
	lr_start_transaction("branchActMdseDetail");


	web_url("branchActMdseDetail",
		"URL=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?ac={appCode}&mc={MC}&gc={GC}&s={Stage}&c={campainCode}&bc={BC}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://icbc.99wuxian.com/wap/branchActMdseList.do?ac={appCode}&bCode={BC}&cCode={campainCode}&qCode={Stage}&actName=%E6%8A%A2%E6%8B%8D",//ac
		"Snapshot=t60.inf",
		"Mode=HTML",
		LAST);
	if (atoi(lr_eval_string("{userName_ct}")) > 0) {
	lr_end_transaction("branchActMdseDetail", LR_PASS);
	}else{
	lr_end_transaction("branchActMdseDetail", LR_FAIL);
	}
	
	lr_think_time(5);

	web_reg_save_param("minAmount","LB=\"minAmount\":","RB=,\"mdseCode","Notfound=warning",LAST);
	web_reg_save_param("addPrice_arr","LB=data-price=\"","RB=\"","ord=all","Notfound=warning",LAST);
	web_reg_save_param("branchActMdseDetail_url","LB=branchActMdseDetail.do?","RB=\"","Notfound=warning",LAST);

	web_reg_find("Text=branchActMdseDetail","SaveCount=Detail_ct",LAST);
	//登录成功，返回至商品详情
	lr_start_transaction("login");
	web_submit_data("redirectpage.do",
		"Action=https://icbc.99wuxian.com/wap/myaccount/redirectpage.do",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t63.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userName", "Value={userName}", ENDITEM,
		"Name=password", "Value=hp123456", ENDITEM,
		"Name=jcaptcha", "Value=888888", ENDITEM,
		"Name=page", "Value=", ENDITEM,
		"Name=log", "Value=登录", ENDITEM,
		EXTRARES,
		"URL=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/ActivityPat/ActivityPat_all.css", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/config.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		//"URL=http://www.google-analytics.com/ga.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/img/xhtml/mybg.jpg", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/plugs/sea/plugin-shim.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/countdown.js?v=2324424.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/detail.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/common/utils.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/list.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		//"URL=http://www.google-analytics.com/__utm.gif?utmwv=5.4.2&utms=110&utmn=2144376545&utmhn=icbc.99wuxian.com&utmcs=UTF-8&utmsr=1440x900&utmvp=1440x723&utmsc=24-bit&utmul=zh-cn&utmje=1&utmfl=11.7%20r700&utmdt=99%E6%97%A0%E9%99%90&utmhid=1002396924&utmr=-&utmp=%2Fwap%2FbranchActMdseDetail.do%3Fac%3DicbcAuction%26mc%3DE999900014942%26gc%3DG1initial%26s%3Ds2%26c%3D45%26bc%3DICBCCategory_HN&utmht=1369797409901&utmac=UA-29240412-2&utmcc=__utma%3D127319493.1618945018.1363572430.1369729183.1369794315.32%3B%2B__utmz%3D127319493.1363845158.6.2.utmcsr%3D10.48.196.232%3A8780%7Cutmccn%3D(referral)%7Cutmcmd%3Dreferral%7Cutmcct%3D%2Fwap%2Fmyaccount%2FsaveAddress.do%3B&utmu=qB~", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/plugs/lib/jquery-1.8.3.min.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		LAST);
	if (atoi(lr_eval_string("{Detail_ct}")) > 0) {
	lr_end_transaction("login", LR_PASS);
	}else{
	lr_end_transaction("login", LR_FAIL);
	}

	lr_think_time(5);

	web_reg_find("Text=success","SaveCount=success_ct",LAST);
	//获取用户的入场券
	//lr_save_string(p.verificationCode,"VC");
	//输入入场券，验证成功
	lr_start_transaction("branchActQualiValid");

	web_url("branchActQualiValid.do",
		"URL=http://icbc.99wuxian.com/wap/branchActQualiValid.do?jsonpcallback=jQuery18306963747899465423_1369797410130&ac={appCode}&bc={BC}&s={Stage}&c={campainCode}&gc={GC}&mc={MC}&vc={VC}&_=1369797426560",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}",
		"Snapshot=t64.inf",
		"Mode=HTML",
		LAST);
	if (atoi(lr_eval_string("{success_ct}")) > 0) {
	lr_end_transaction("branchActQualiValid", LR_PASS);
	}else{
	lr_end_transaction("branchActQualiValid", LR_FAIL);
	lr_exit(LR_EXIT_VUSER,LR_FAIL);
	}

	return 0;
}

char *getVerificationCode(unsigned int category){
	if (category == 1){
		return lr_eval_string("{started_verification_code}");
	}else if (category == 2){
		return lr_eval_string("{upgrade_verification_code}");
	}else if (category == 3){
		return lr_eval_string("{ace_verification_code}");
	}else if (category == 4){
		return lr_eval_string("{daren_verification_code}");
	}
	
	return "Error";
}
unsigned int getLikeability(){
	int r;
	r = rand()%100;
	if (r <= 10){
		return 4;
	}else if (r > 10 && r <= 30){
		return 3;
	}else if(r > 30 && r <= 60){
		return 2;
	}
		return 1;
}
unsigned int getCategory(){
	int r;
	r = rand()%100;
	if (r < 26){
		return 1;
	}else if (r > 25 && r < 53){
		return 2;
	}else if (r > 52 && r <80 ){
		return 3;
	}
		return 4;
	
}
