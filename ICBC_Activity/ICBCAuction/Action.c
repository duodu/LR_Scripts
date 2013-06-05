Action()
{



	//unsigned int tagStatus = 0;


// 	lr_log_message("%d",tag_over_Status);
// 	lr_log_message("%d",tag_top_Status);
	lr_think_time(5);

 	if (!tag_top_Status  ) {
//	if (!tag_top_Status) {
 	if (tag_over_Status && tag_exit_Status<3) {
	lr_save_string(lr_paramarr_idx("addPrice_arr",1),"param_addPrice");
	tag_exit_Status ++;
	}else{
	lr_save_string(lr_paramarr_random("addPrice_arr"),"param_addPrice");
	}
	lr_save_string(lr_paramarr_random("addPrice_arr"),"param_addPrice");

	web_reg_find("Text=branchActMdseAuction","SaveCount=Auction_ct",LAST);
	//加价确认
	lr_start_transaction("toBranchAction");

	web_url("toBranchAction.do",
		"URL=http://icbc.99wuxian.com/wap/toBranchAction.do?ac={appCode}&bc={BC}&s={Stage}&c={campainCode}&gc={GC}&mc={MC}&ma={minAmount}&oa={param_addPrice}&mdurl=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?ac={appCode}$||$@mc={MC}$||$@gc={GC}$||$@s={Stage}$||$@c={campainCode}$||$@bc={BC}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}",
		"Snapshot=t65.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/ActivityPat/ActivityPat_all.css", ENDITEM,
		//"URL=http://www.google-analytics.com/ga.js", "Referer=http://icbc.99wuxian.com/wap/toBranchAction.do?ac=icbcAuction&bc=ICBCCategory_HN&s=s2&c=45&gc=G1initial&mc=E999900014942&ma=5000&oa=5&mdurl=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?ac=icbcAuction$||$@mc=E999900014942$||$@gc=G1initial$||$@s=s2$||$@c=45$||$@bc=ICBCCategory_HN", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/img/xhtml/mybg.jpg", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", ENDITEM,
		//"URL=http://www.google-analytics.com/__utm.gif?utmwv=5.4.2&utms=111&utmn=1624760941&utmhn=icbc.99wuxian.com&utmcs=UTF-8&utmsr=1440x900&utmvp=1440x723&utmsc=24-bit&utmul=zh-cn&utmje=1&utmfl=11.7%20r700&utmdt=99%E6%97%A0%E9%99%90&utmhid=1720735535&utmr=0&utmp=%2Fwap%2FtoBranchAction.do%3Fac%3DicbcAuction%26bc%3DICBCCategory_HN%26s%3Ds2%26c%3D45%26gc%3DG1initial%26mc%3DE999900014942%26ma%3D5000%26oa%3D5%26mdurl%3Dhttp%3A%2F%2Ficbc.99wuxian.com%2Fwap%2FbranchActMdseDetail.do%3Fac%3DicbcAuction%24%257C%257C%24%40mc%3DE999900014942%24%257C%257C%24%40gc%3DG1initial%24%257C%257C%24%40s%3Ds2%24%257C%257C%24%40c%3D45%24%257C%257C%24%40bc%3DICBCCategory_HN&utmht=1369797431223&utmac=UA-29240412-2&utmcc=__utma%3D127319493.1618945018.1363572430.1369729183.1369794315.32%3B%2B__utmz%3D127319493.1363845158.6.2.utmcsr%3D10.48.196.232%3A8780%7Cutmccn%3D(referral)%7Cutmcmd%3Dreferral%7Cutmcct%3D%2Fwap%2Fmyaccount%2FsaveAddress.do%3B&utmu=qB~", "Referer=http://icbc.99wuxian.com/wap/toBranchAction.do?ac=icbcAuction&bc=ICBCCategory_HN&s=s2&c=45&gc=G1initial&mc=E999900014942&ma=5000&oa=5&mdurl=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?ac=icbcAuction$||$@mc=E999900014942$||$@gc=G1initial$||$@s=s2$||$@c=45$||$@bc=ICBCCategory_HN", ENDITEM,
		LAST);
	if (atoi(lr_eval_string("{Auction_ct}")) > 0) {
	lr_end_transaction("toBranchAction", LR_PASS);
	}else{
	lr_end_transaction("toBranchAction", LR_FAIL);
	}

	lr_think_time(1);

	web_reg_find("Text=领先","SaveCount=top_ct",LAST);
	web_reg_find("Text=您的当前出价已超过商品销售价","SaveCount=over_ct",LAST);
	web_reg_find("Text=恭喜您抢拍成功","SaveCount=success_ct",LAST);
	web_reg_save_param("minAmount","LB=\"minAmount\":","RB=,\"mdseCode","Notfound=warning",LAST);
	//web_reg_save_param("branchActMdseDetail_url","LB=branchActMdseDetail.do?","RB=\"","Notfound=warning",LAST);

	web_reg_find("Text=branchActMdseDetail","SaveCount=Detail_count",LAST);
	//加价
	lr_start_transaction("branchActMdseAuction");
	web_submit_data("branchActMdseAuction.do",
		"Action=http://icbc.99wuxian.com/wap/branchActMdseAuction.do",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://icbc.99wuxian.com/wap/toBranchAction.do?ac={appCode}&bc={BC}&s={Stage}&c={campainCode}&gc={GC}&mc={MC}&ma={minAmount}&oa={param_addPrice}&mdurl=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?ac={appCode}$||$@mc={MC}$||$@gc={GC}$||$@s={Stage}$||$@c={campainCode}$||$@bc={BC}",
		"Snapshot=t66.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=ac", "Value={appCode}", ENDITEM,
		"Name=bc", "Value={BC}", ENDITEM,
		"Name=s", "Value={Stage}", ENDITEM,
		"Name=c", "Value={campainCode}", ENDITEM,
		"Name=gc", "Value={GC}", ENDITEM,
		"Name=mc", "Value={MC}", ENDITEM,
		"Name=ma", "Value={minAmount}", ENDITEM,
		"Name=oa", "Value={param_addPrice}", ENDITEM,
		"Name=mdurl", "Value=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?ac={appCode}$||$@mc={MC}$||$@gc={GC}$||$@s={Stage}$||$@c={campainCode}$||$@bc={BC}", ENDITEM,
		"Name=auction_submit", "Value=确定", ENDITEM,
		EXTRARES,
		"URL=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/ActivityPat/ActivityPat_all.css", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/config.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		//"URL=http://www.google-analytics.com/ga.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/img/xhtml/mybg.jpg", "Referer=http://pic.99wuxian.com/mall/wap/css/min/xhtml/Common/Common.css", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/plugs/sea/plugin-shim.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/countdown.js?v=2324424.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/detail.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		//"URL=http://www.google-analytics.com/__utm.gif?utmwv=5.4.2&utms=112&utmn=1593433989&utmhn=icbc.99wuxian.com&utmcs=UTF-8&utmsr=1440x900&utmvp=1440x723&utmsc=24-bit&utmul=zh-cn&utmje=1&utmfl=11.7%20r700&utmdt=99%E6%97%A0%E9%99%90&utmhid=1738395412&utmr=0&utmp=%2Fwap%2FbranchActMdseDetail.do%3Fac%3DicbcAuction%26mc%3DE999900014942%26gc%3DG1initial%26s%3Ds2%26c%3D45%26bc%3DICBCCategory_HN&utmht=1369797434640&utmac=UA-29240412-2&utmcc=__utma%3D127319493.1618945018.1363572430.1369729183.1369794315.32%3B%2B__utmz%3D127319493.1363845158.6.2.utmcsr%3D10.48.196.232%3A8780%7Cutmccn%3D(referral)%7Cutmcmd%3Dreferral%7Cutmcct%3D%2Fwap%2Fmyaccount%2FsaveAddress.do%3B&utmu=qB~", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/common/utils.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/xhtml/ActivityPat/list.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/plugs/lib/jquery-1.8.3.min.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		LAST);
	if (atoi(lr_eval_string("{Detail_ct}")) > 0) {
	lr_end_transaction("branchActMdseAuction", LR_PASS);
	}else{
	lr_end_transaction("branchActMdseAuction", LR_FAIL);
	}
	if (atoi(lr_eval_string("{over_ct}")) > 0) {
		tag_over_Status = 1;
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_PASS );
	}else{
		tag_over_Status = 0;
	}

	if (atoi(lr_eval_string("{success_ct}")) > 0) {
		lr_start_transaction("Buy_Success");
		lr_end_transaction("Buy_Success",LR_PASS);
		lr_exit(LR_EXIT_VUSER,LR_PASS);
	}
	}
	
	lr_think_time(10);
	
	web_reg_find("Text=领先","SaveCount=top_ct",LAST);
	web_reg_save_param("minAmount","LB=\"minAmount\":","RB=,\"mdseCode","Notfound=warning",LAST);
	web_url("刷新",
		"URL=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?ac={branchActMdseDetail_url}",
		"Snapshot=t67.inf",
		"Mode=HTML",
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
		//"URL=http://www.google-analytics.com/__utm.gif?utmwv=5.4.2&utms=113&utmn=1360599580&utmhn=icbc.99wuxian.com&utmcs=UTF-8&utmsr=1440x900&utmvp=1440x723&utmsc=24-bit&utmul=zh-cn&utmje=1&utmfl=11.7%20r700&utmdt=99%E6%97%A0%E9%99%90&utmhid=801544643&utmr=0&utmp=%2Fwap%2FbranchActMdseDetail.do%3Fac%3DicbcAuction%26mc%3DE999900014942%26gc%3DG1initial%26s%3Ds2%26c%3D45%26bc%3DICBCCategory_HN&utmht=1369797447616&utmac=UA-29240412-2&utmcc=__utma%3D127319493.1618945018.1363572430.1369729183.1369794315.32%3B%2B__utmz%3D127319493.1363845158.6.2.utmcsr%3D10.48.196.232%3A8780%7Cutmccn%3D(referral)%7Cutmcmd%3Dreferral%7Cutmcct%3D%2Fwap%2Fmyaccount%2FsaveAddress.do%3B&utmu=qB~", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		"URL=http://pic.99wuxian.com/mall/wap/js/min/plugs/lib/jquery-1.8.3.min.js", "Referer=http://icbc.99wuxian.com/wap/branchActMdseDetail.do?{branchActMdseDetail_url}", ENDITEM,
		LAST);

	tag_top_Status = (unsigned int )atoi(lr_eval_string("{top_ct}"));

return 0;
}
