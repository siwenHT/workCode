#ifndef _YVIM_CMDDEF_H__
#define _YVIM_CMDDEF_H__
#define  CLOUDMSG_SYSTEM          "SYSTEM"
#define  CLOUDMSG_PUSH            "PUSH"
#define  CLOUDMSG_FRIEND          "P2P"
#define  CLOUDMSG_GROUP           "GROUP"
#define 	  CLOUDMSG_ID				110			
#define 	  CLOUDMSG_SOURCE			111			
#define IM_LOGIN_REQ                    0x11000
namespace x11000{
	enum{
			 userid				= 1, 
			 pwd				= 2, 
			 pgameServiceID		= 3, 
		 wildCard			= 4, 
		    readstatus         = 5, 
	};
}
#define IM_LOGIN_RESP	                 0x11001
namespace x11001 {
	enum {
		 result		= 1, 
		 msg			= 2, 
		 nickname		= 4, 
		 userId		= 5, 
		 iconurl		= 6, 
	};
}
#define IM_THIRD_LOGIN_REQ				  0x11002
namespace x11002{
	enum{
			 tt					= 1, 
			 pgameServiceID		= 2, 
		 wildCard			= 3, 
		    readstatus         = 4, 
	};
}
#define IM_THIRD_LOGIN_RESP				   0x11003
namespace x11003 {
	enum {
		 result			= 1, 
		 msg				= 2, 
		 userid			= 3, 
		 nickName			= 4, 
		 iconUrl			= 5, 
		 thirdUserId		= 6, 
		 thirdUserName	= 7, 
		 level			= 8, 
		 vip				= 9, 
		 ext				= 10, 
		 sex				= 11, 
	};
}
#define IM_LOGOUT_REQ	                   0x11004
namespace x11004
{
}
#define IM_DEVICE_SETINFO                   0x11012
namespace x11012 {
	enum {
		 imsi        = 1,
		 imei        = 2,
		 mac         = 3,
		 appVersion  = 4,
		 networkType = 5,
	};
}
#define IM_RECONNECTION_NOTIFY               0x11013
namespace x11013 {
	enum {
		 userid        = 1,
	};
}
#define IM_SETUSERINFO_REQ      0x11019
namespace x11019 {
	enum{
		  nickname  = 1,      
		  iconUrl   = 2,      
		  level	  = 3,      
		  vip		  = 4,      
		  ext       = 5,      
		   sex       = 6,      
	};
}
#define IM_SETUSERINFO_RESP     0x11020
namespace x11020 {
	enum{
				result   = 1, 
				msg		 = 2,
	};
}
#define IM_GET_THIRDBINDINFO_REQ             0x11014
namespace x11014 {
	enum {
		 appid        = 1,   
		 uid          = 2, 
	};
}
#define IM_GET_THIRDBINDINFO_RESP            0x11015
namespace x11015 {
	enum {
		 result		= 1, 
		 msg			= 2, 
		 yunvaid      = 3,   
		 nickname     = 4,
		 iconUrl      = 5,
		 level        = 6,
		 vip          = 7,
		 ext          = 8,
		 sex          = 9, 
		 uid          = 10,
	};
}
enum yv_net
{
	yv_net_disconnect = 0,
	yv_net_connect = 1,
};
#define IM_NET_STATE_NOTIFY                  0x11016
namespace x11016 {
	enum {
		 state        = 1,     
	};
}
#define IM_GET_SDKINFO_REQ                    0x11017
namespace x11017 {
}
#define IM_GET_SDKINFO_RESP                   0x11018
namespace x11018 {
	enum {
		 versions        = 1,     
		  netstate        = 2,     
	};
}
namespace  xUserInfo {
	enum{
		 nickname  = 1, 
		 userid    = 2, 
		 iconurl   = 3, 
		  online    = 4, 
		 userlevel = 5, 
		 viplevel  = 6, 
		 ext       = 7, 
		  shieldmsg = 8, 
		  sex       = 9, 
		 group     = 10, 
		 remark    = 11, 
		 uid		 = 12,
	};
}
namespace xSearchInfo{
	enum{
		 yunvaId  = 1,
		 userId   = 2, 
		 nickName = 3, 
		 iconUrl  = 4, 
		 level    = 5, 
		 vip      = 6, 
		 Ext      = 7, 
		 sex      = 8, 
	};
}
#define IM_FRIEND_ADD_REQ        0x12000
namespace x12000 {
	enum  {
		    userid = 1, 
		    greet  = 2, 
	};
}
#define IM_FRIEND_ADD_RESPOND    0x12025
namespace x12025 {
	enum  {
				result   = 1, 
				msg		 = 2,
		      userid   = 3,
	};
}
#define IM_FRIEND_ADD_NOTIFY    0x12002
namespace x12002 {
	enum {
		 userid = 1,  
		 name   = 3,  
		 greet  = 2,  
		 sign   = 4,
		 url    = 5,  
		 uid    = 6,
	};
}
#define IM_FRIEND_ADD_ACCEPT   0x12003 
namespace x12003 {
	enum {
		  userid = 1, 
			affirm = 2,
			greet  = 3,
	};
}
#define IM_FRIEND_ACCEPT_RESP   0x12004
namespace x12004 {
	enum {
		 result = 4,    
		 msg	  = 5,     
		 userid = 1, 
		  affirm = 2, 
		 greet  = 3, 
	};
}
enum e_addfriend_affirm{
	af_refuse    = 0, 
	af_agree     = 1, 
	af_agree_add = 2, 
};
#define IM_FRIEND_ADD_RESP      0x12001
namespace x12001 {
	enum {
		 affirm = 1, 
		 userid = 2, 
		 name   = 3, 
		 url    = 4, 
		 greet  = 5, 
		 uid	  = 6, 
	};
}
enum e_delfriend{
	df_exit_in_list     = 0, 
	df_remove_from_list = 1, 
};
#define IM_FRIEND_DEL_REQ   0x12005
namespace x12005 {
	enum {
			del_friend	= 1,  
		   act         = 2,  
	}; 
}
#define IM_FRIEND_DEL_RESP  0x12006  
namespace x12006 {
	enum {
				result			= 1,    
				msg				= 2,     
			    del_friend		= 3,  
		       act				= 4,  
	};
}
#define IM_FRIEND_DEL_NOTIFY   0x12007
namespace x12007 {
	enum {
		 del_friend	 = 1, 
		  del_fromlist  = 2, 
	};
}
#define IM_FRIEND_SEARCH_REQ   0x12018  
namespace x12018 {
	enum {
		 keyworld = 1, 
		 start    = 2, 
		 count    = 3, 
	};
}
#define IM_FRIEND_SEARCH_RESP  0x12019  
namespace x12019 {
	enum {
				result   = 1, 
				msg		 = 2, 
		 userinfo = 3, 
	};
}
#define IM_FRIEND_RECOMMAND_REQ     0x12008  
namespace x12008 {
	enum {
		 start = 1, 
		 count = 2, 
	};
}
#define IM_FRIEND_RECOMMAND_RESP   0x12009
namespace x12009 {
	enum {
				result   = 1, 
				msg		 = 2, 
		 userinfo = 3, 
	};
}
enum e_oper_friend_act
{
	oper_add_blacklist = 3, 
	oper_del_blacklist = 4, 
};
#define IM_FRIEND_OPER_REQ		   0x12010
namespace x12010 {
	enum {
			userId = 1,
			operId = 2,
			act	   = 3,
	};
}
#define IM_FRIEND_OPER_RESP	    	 0x12011
namespace x12011 {
	enum {
			result		= 5,
			msg			= 6, 
			userId 		= 1, 
			operId		= 2, 
			act			= 3, 
			oper_state	= 4, 
	};
}
#define IM_FRIEND_LIST_REQ		     0x12028
namespace x12028{
	enum {
		 group        = 1, 
	};
}
#define IM_FRIEND_LIST_RESP		     0x12029
namespace x12029{
	enum {
				result	 = 2,
				msg		 = 3,
		 userinfo = 1, 
	};
}
#define IM_FRIEND_LIST_NOTIFY		  0x12012  
namespace x12012{
	enum {
		 userinfo = 1, 
	};
}
#define IM_FRIEND_BLACKLIST_REQ		     0x12030
namespace x12030{
	enum {
	
	};
}
#define IM_FRIEND_BLACKLIST_RESP		 0x12031
namespace x12031{
	enum {
				result	 = 2,
				msg		 = 3,
		 userinfo = 1, 
	};
}
#define IM_FRIEND_BLACKLIST_NOTIFY       0x12013
namespace x12013 {
	enum {
		 userinfo = 1, 
	};
}
namespace xNearChatInfo
{
	enum
	{
		 nickname  = 1, 
		 userid    = 2, 
		 iconurl   = 3, 
		  online    = 4, 
		 userlevel = 5, 
		 viplevel  = 6, 
		 ext       = 7, 
		  shieldmsg = 8, 
		  sex       = 9, 
		 group     = 10, 
		 remark    = 11, 
		 times     = 12, 
		 uid		 = 13,
	};
}
namespace xRecentConactList {
	enum e_recent_user {
		        endId    = 1, 
		        unread   = 2, 
		   msg      = 3, 
		 user     = 4,
	};
}
#define IM_FRIEND_NEARLIST_REQ		0x12032
namespace x12032{
	enum {
	
	};
}
#define IM_FRIEND_NEARLIST_RESP		0x12033
namespace x12033{
	enum {
				result	 = 2,
				msg		 = 3,
		 recent = 1, 
	};
}
#define IM_FRIEND_NEARLIST_NOTIFY    0x12014
namespace x12014 {
	enum {
		   recent = 1, 
	};
}
#define IM_FRIEND_QUERY_ONLINE_REQ		0x12034
namespace x12034{
	enum {
			userid		= 1,	
	};
}
#define IM_FRIEND_QUERY_ONLINE_RESP		0x12035
namespace x12035{
	enum {
		  result    = 1, 
			msg       = 2,
			userid	  = 3,		
	};
}
enum e_friend_status{
	fs_offline = 0, 
	fs_online  = 1, 
};
#define IM_FRIEND_STATUS_NOTIFY    0x12015
namespace x12015 {
	enum {
		 userid = 1, 
		  status = 2, 
	};
}
#define IM_FRIEND_INFOSET_REQ	0x12016
namespace x12016 {
	enum {
			friendId = 1, 
			group	 = 2, 
			note	 = 3, 
	};
}
#define IM_FRIEND_INFOSET_RESP	0x12017
namespace x12017 {
	enum {
			result		= 4, 
			msg			= 5, 
			friendId	= 1, 
			group		= 2, 
			note		= 3, 
	};
}
#define IM_USER_GETINFO_REQ       0x12020
namespace x12020 {
	enum {
		 userid = 1, 
	};
}
#define IM_USER_GETINFO_RESP      0x12021
namespace x12021 {
	enum {
		  result    = 8,
		  msg		  = 9,     
		  userid    = 1,
		   sex      = 2,     
		  nickname  = 3,     
		  headicon  = 4,     
		  userlevel = 5,     
		  viplevel  = 6,     
		  ext       = 7,     
		  uid       = 10,     
	};
}
#define IM_USER_SETINFO_NOTIFY      0x12024
namespace x12024 {
	enum{
		  userid    = 1, 
		  nickname  = 2, 
		  iconurl   = 3, 
		  userlevel = 4, 
		  viplevel  = 5, 
		  ext       = 6, 
		  sex       = 7, 
	};
}
#define IM_REMOVE_CONTACTES_REQ      0x12026
namespace x12026 {
	enum{
		  userid    = 1,      
	};
}
#define IM_REMOVE_CONTACTES_RESP      0x12027
namespace x12027 {
	enum{
				  result    = 1, 
				  msg       = 2,
		        userid    = 3,  
	};
}
namespace xGroupUser {
	enum {
			userId			= 1, 
		  nickname        = 2, 
		  iconurl         = 3, 
		   sex             = 4, 
			alias			= 5, 
			role			= 6, 
			level			= 7, 
			grade			= 8, 
			lately_online	= 9, 
			online			= 10, 
		  uid				= 11, 
	};
}
#define IM_GROUP_USERLIST_NOTIFY  0x13000
namespace x13000 {
	enum {
		     groupid     = 1, 
		   xGroupUser  = 2,
	};
}
#define IM_GROUP_USERMDY_NOTIFY	   0x13001
namespace x13001 {
	enum {
		  groupid         = 1, 
			userId			= 2, 
			name			= 3, 
			icon			= 4, 
			announcement	= 5, 
			verify			= 6, 
			alias			= 8, 
	};
}
enum e_groupverify {
	gv_allow	  =	1,
	gv_audit	  =	3,
	gv_not_allow  =	4,
};
#define IM_GROUP_CREATE_REQ     0x13002   
namespace x13002 {
	enum {
		 verify     = 1, 
		 name       = 2, 
		 iconUrl    = 3, 
	};
}
#define IM_GROUP_CREATE_RESP      0x13003
namespace x13003 {
	enum {
		 result  = 1, 
		 msg     = 2, 
		 groupid = 3, 
	};
}
#define IM_GROUP_SEARCH_REQ     0x13004   
namespace x13004 {
	enum {
		 groupid = 1, 
	};
}
#define IM_GROUP_SEARCH_RESP      0x13005
namespace x13005 {
	enum {
		 result       = 1, 
		 msg          = 2, 
		 groupid      = 3, 
		 verify       = 4, 
		 name         = 5, 
		 iconurl      = 6, 
		 numbercount  = 7, 
		 currentnum   = 8, 
		 ownerid      = 9, 
		 announcement = 10,
	};
}
#define IM_GROUP_JOIN_REQ        0x13006 
namespace x13006  {
	enum {
		 groupid = 1, 
		 greet   = 2, 
	};
}
#define IM_GROUP_JOIN_RESPON        0x13036 
namespace x13036  {
	enum {
		 result = 1, 
		 msg    = 2, 
		 groupid = 3, 
	};
}
enum e_joingroup {
	jg_refuse = 0, 
	jg_agree  = 1, 
};
#define IM_GROUP_JOIN_RESP      0x13009
namespace x13009 {
	enum {
		 groupid   = 3, 
		 userid    = 4, 
		  agree     = 5, 
		 groupname = 6, 
		 greet     = 7, 
		 iconurl   = 8, 
	};
}
#define IM_GROUP_JOIN_NOTIFY    0x13007   
namespace x13007 {
	enum {
		 groupid   = 1, 
		 userid    = 2, 
		 username  = 3, 
		 groupname = 4, 
		 greet     = 5, 
		 iconurl   = 6, 
	};
}
#define IM_GROUP_JOIN_ACCEPT    0x13008
namespace x13008 {
	enum {
		 groupid = 1, 
		 userid  = 2, 
		  agree   = 3, 
		 greet   = 4, 
	};
}
#define IM_GROUP_JOIN_ACCEPT_RESP    0x13040
namespace x13040 {
	enum {
		 result	= 1,
		 msg		= 2,
		 groupid  = 3,
		 userid   = 4,
		 reason	= 5,
	};
}
#define IM_GROUP_EXIT_REQ     0x13010
namespace x13010 {
	enum {
		 groupid = 1, 
	};
}
#define IM_GROUP_EXIT_RESP   0x13011
namespace x13011 {
	enum {
		 result  = 1, 
		 msg     = 2, 
		 groupid = 3, 
		 userid  = 4, 
	};
}
#define IM_GROUP_EXIT_NOTIFY   0x13012
namespace x13012 {
	enum {
		 groupid = 1, 
		 userid  = 2, 
	};
}
#define IM_GROUP_MODIFY_REQ  0x13013   
namespace x13013 {
	enum {
		 groupid      = 1, 
		 name         = 2, 
		 icon         = 3, 
		 announcement = 4, 
		  verify       = 5, 
		  msg_set      = 6, 
		 alias        = 8, 
	};
}
#define IM_GROUP_MODIFY_RESP  0x13014  
namespace x13014 {
	enum {
		 result       = 1, 
		 msg          = 2, 
		 groupid      = 3, 
		 name         = 4, 
		 icon         = 5, 
		 announcement = 6, 
		  verify       = 7, 
		  msg_set      = 8, 
		 alias        = 10,
	};
}
#define IM_GROUP_SHIFTOWNER_REQ   0x13015
namespace x13015 {
	enum {
		 groupid = 1, 
		 userid  = 2, 
	};
}
#define IM_GROUP_SHIFTOWNER_NOTIFY   0x13016
namespace x13016 {
	enum {
		 groupid = 1, 
		 userid  = 2, 
		 shiftid = 3, 
	};
}
#define IM_GROUP_SHIFTOWNER_RESP   0x13017
namespace x13017 {
	enum {
		 result  = 1, 
		 msg     = 2, 
		 groupid = 3, 
		 userid  = 4, 
		 shiftid = 5,  
	};
}
#define IM_GROUP_KICK_REQ    0x13018
namespace x13018 {
	enum {
		 groupid = 1, 
		 userid  = 2, 
	};
}
#define IM_KGROUP_KICK_NOTIFY   0x13019
namespace x13019 {
	enum {
		 groupid   = 1, 
		 userid    = 2, 
		 kickid    = 3, 
		 groupname = 4, 
	};
}
#define IM_GROUP_KICK_RESP   0x13020
namespace x13020 {
	enum {
		 result  = 1, 
		 msg     = 2, 
		 groupid = 3, 
	};
}
#define IM_GROUP_INVITE_REQ   0x13021
namespace x13021 {
	enum {
		 groupid = 1, 
		 userid  = 2, 
		 greet   = 3, 
	};
}
#define IM_GROUP_INVITE_RESPON   0x13041
namespace x13041 {
	enum {
		 result  = 1, 
		 msg     = 2, 
		 groupid = 3, 
		 invitedid  = 4, 
	};
}
#define IM_GROUP_INVITE_NOTIFY   0x13022
namespace x13022 {
	enum {
		 groupid    = 1, 
		 inviteid   = 2, 
		 invitename = 3, 
		 greet      = 4, 
		 groupname  = 5, 
		 groupicon  = 6, 
	};
}
enum e_group_invite {
	gi_refuse = 0, 
	gi_agree  = 1, 
};
#define IM_GROUP_INVITE_ACCEPT   0x13023
namespace x13023 {
	enum {
		 groupid	 = 4, 
		 invitename = 5, 
		 inviteid  = 1, 
		 agree     = 2, 
		 greet     = 3, 
	};
}
#define IM_GROUP_INVITE_ACCEPT_RESP   0x13042
namespace x13042 {
	enum {
		 result    = 1, 
		 msg       = 2, 
		 groupid   = 3, 
		 inviteid  = 4, 
	};
}
#define IM_GROUP_INVITE_RESP   0x13024
namespace x13024 {
	enum {
		 groupid   = 3, 
		 inviteid  = 4, 
		 groupname = 5, 
		  agree     = 6, 
		 greet	 = 7, 
	};
}
enum e_group_role{
	gr_owners	= 2, 
	gr_admin	= 3, 
	gr_number	= 4, 
	gr_visitor	= 10,
};
#define IM_GROUP_SETROLE_REQ   0x13025
namespace x13025 {
	enum {
		 groupid = 1, 
		 userid  = 2, 
		  role    = 3, 
	};
}
#define IM_GROUP_SETROLE_RESP    0x13026
namespace x13026 {
	enum {
		 result  = 1, 
		 msg     = 2, 
		 groupid = 3, 
	};
}
#define IM_GROUP_SETROLE_NOTIFY    0x13027
namespace x13027 {
	enum {
		 groupid  = 1, 
		 operid   = 2, 
		 byuserid = 3, 
		 role     = 4, 
	};
}
#define IM_GROUP_DISSOLVE_REQ  0x13028
namespace x13028 {
	enum {
		 grouid = 1, 
	};
}
#define IM_GROUP_DISSOLVE_RESP  0x13029
namespace x13029 {
	enum {
		 result = 1, 
		 msg    = 2, 
		 grouid = 3, 
	};
}
#define IM_GROUP_SETOTHER_REQ   0x13030
namespace x13030 {
	enum {
		 groupid = 1, 
		 userid  = 2, 
		 alias   = 3, 
	};
}
#define IM_GROUP_SETOTHER_NOTIFY   0x13031
namespace x13031 {
	enum {
		 groupid = 1, 
		 userid  = 2, 
		 alias   = 3, 
	};
}
#define IM_GROUP_SETOTHER_RESP   0x13032
namespace x13032 {
	enum {
		 result  = 1, 
		 msg     = 2, 
		 groupid = 3, 
	};
}
#define IM_GROUP_PROPERTY_NOTIFY   0x13033
namespace x13033 {
	enum {
		  groupid         = 1, 
			name			= 2, 
			icon			= 3, 
			announcement	= 4, 
			level			= 5, 
			verify			= 6, 
			number_limit	= 7, 
			owner			= 8, 
			msg_set			= 9, 
		  user_count      = 11,
		   role            = 12,
	};
}
enum group_member_online {
	gm_status_online = 1,    
};
#define IM_GROUP_MEMBER_ONLINE   0x13034
namespace x13034 {
	enum {
		 groupid = 1, 
		 userid  = 2, 
		  online  = 3, 
	};
}
#define IM_GROUP_USERJOIN_NOTIFY  0x13035
namespace x13035 {
	enum {
		     groupid = 1, 
		 xUser   = 2, 
	};
}
#define IM_CHAT_FRIEND_TEXT_REQ  0x14000
namespace x14000 {
	enum {
		 userid = 1, 
		 data   = 2, 
		 ext    = 3, 
		 flag   = 4, 
	};
}
#define IM_CHAT_FRIEND_IMAGE_REQ  0x14001
namespace x14001 {
	enum {
		 userid = 1, 
		 image  = 2, 
		 ext    = 3, 
		 flag   = 4, 
	};
}
#define IM_CHATI_FRIEND_AUDIO_REQ  0x14002
namespace x14002 {
	enum {
		 userid = 1, 
		 file   = 2, 
		 time   = 3, 
		 txt    = 4, 
		 ext    = 5, 
		 flag   = 6, 
	};
}
enum e_chat_msgtype {
	chat_msgtype_image = 0, 
	chat_msgtype_audio = 1, 
	chat_msgtype_text  = 2, 
};
#define IM_CHAT_FRIEND_NOTIFY 0x14003
namespace x14003 {
	enum {
		 userid    = 1,  
		 name      = 2,  
		 signature = 3,  
		 headurl   = 4,  
		 sendtime  = 5,  
		  type      = 6,  
		 data      = 7,  
		 imageurl  = 8,  
		 audiotime = 9,  
		 attach    = 10, 
		 ext1      = 11, 
		 uid       = 12,
		 indexid   = 14,
	};
}
#define IM_CHATT_FRIEND_RESP  0x14004
namespace x14004 {
	enum {
		 result       = 1,  
		 msg          = 2, 
		  type         = 3,
		 userid       = 4,   
		 flag         = 5,
		 indexid      = 6,   
		 text         = 7,   
		 audiourl     = 8,   
		 audiotime    = 9,   
		 imageurl1    = 10,  
		 imageurl2    = 11,  
		 ext1         = 13,  
	};
}
#define IM_CHAT_GROUP_TEXT_REQ    0x14006
namespace x14006 {
	enum {
		 groupid = 1, 
		 text    = 2, 
		 ext     = 3, 
		 flag	   = 4, 
	};
}
#define IM_CHAT_GROUP_IMAGE_REQ    0x14007
namespace x14007 {
	enum {
		 groupid  = 1, 
		 image    = 2, 
		 ext      = 3, 
		 flag		= 4, 
	};
}
#define IM_CHATA_GROUP_AUDIO_REQ    0x14008
namespace x14008 {
	enum {
		 groupid = 1, 
		 file    = 2, 
		 time    = 3, 
		 txt     = 4, 
		 ext     = 5, 
		 flag	   = 6, 
	};
}
#define IM_CHAT_GROUP_NOTIFY    0x14009
namespace x14009 {
	enum {
		 groupid   = 1, 
		 sendid    = 2, 
		 sendnickname = 12, 
		 sendheadurl  = 13, 
		 time      = 3, 
		 groupicon = 4, 
		 groupname = 5, 
		  type      = 6, 
		 data      = 7, 
		 imageurl  = 8, 
		 audiotime = 9, 
		 attach    = 10, 
		 ext1      = 11, 
		 indexid   = 14,
	};
}
#define IM_CHAT_GROUPMSG_RESP  0x14010
namespace x14010 {
	enum {
		 result       = 1,  
		 msg          = 2, 
		 groupid      = 3, 
		 index        = 4, 
		 flag			= 5, 
	};
}
#define IM_CHAT_MSG_SEND_PERCENT_NOTIFY 0x14011
namespace x14011{
	enum{
		 flag			= 1, 
		 percent      = 2, 
	};
}
#define IM_CHAT_CANCEL_SEND_REQ 0x14012
namespace x14012{
	enum{
		 id			= 1, 
		 flag			= 2, 
	};
}
namespace xP2PChatMsg
{
	enum
	{
		 userid    = 1,  
		 name      = 2,  
		 signature = 3,  
		 headurl   = 4,  
		 sendtime  = 5,  
		  type      = 6,  
		 data      = 7,  
		 imageurl  = 8,  
		 audiotime = 9,  
		 attach    = 10, 
		 ext1      = 11, 
		 uid       = 12,
	};
}
namespace xGroupChatMsg
{
	enum {
		 groupid   = 1, 
		 sendid    = 2, 
		 sendnickname = 12, 
		 sendheadurl  = 13, 
		 time      = 3, 
		 groupicon = 4, 
		 groupname = 5, 
		  type      = 6, 
		 data      = 7, 
		 imageurl  = 8, 
		 audiotime = 9, 
		 attach    = 10, 
		 ext1      = 11, 
	};
}
#define IM_CLOUDMSG_NOTIFY           0x15002
namespace x15002 {
	enum {
		 source  = 1, 
		 id      = 2, 
		 beginid = 3, 
		 endid   = 4, 
		 time    = 5, 
		   packet  = 6, 
		 unread  = 7,
	};
}
#define IM_CLOUDMSG_LIMIT_REQ         0x15003
namespace x15003 {
	enum {
		 source = 1, 
		 id     = 2, 
		 index  = 3, 
		  limit  = 4, 
	};
}
#define IM_CLOUDMSG_LIMIT_RESP        0x15004
namespace x15004 {
	enum {
		 result  = 1, 
		 msg     = 2, 
		 source  = 3, 
		 id      = 4, 
		 index   = 5, 
		 limit   = 6, 
	};
}
#define IM_CLOUDMSG_LIMIT_NOTIFY       0x15005
namespace x15005 {
	enum {
				source	= 1, 
		      id      = 2, 
				count	= 3, 
				indexId	= 4, 
				ptime	= 5, 
				packet	= 6, 
	};
}
#define IM_MSG_PUSH                   0x15006
namespace x15006 {
	enum {
		 data  = 2, 
	};
}
#define IM_CLOUDMSG_READ_STATUS       0x15007
namespace x15007 {
	enum {
		      id      = 1,  
				source	= 2,  
	};
}
#define IM_CLOUDMSG_READ_RESP         0x15009
namespace x15009 {
	enum {
		      result  = 1, 
		      msg     = 2, 
		      id      = 3,  
				source	= 4, 
	};
}
#define IM_CLOUDMSG_IGNORE_REQ        0x15008
namespace x15008 {
	enum
	{
				source    = 1,  
		      id        = 2,  
		      index     = 3,  
	};
}
#define IM_CLOUDMSG_IGNORE_RESP       0x15010
namespace x15010 {
	enum
	{
		      result    = 1, 
		      msg       = 2, 
				source    = 3,  
		      id        = 4,  
		      index     = 5,  
	};
}
#define IM_CHANNEL_LOGIN_REQ            0x16007
namespace x16007{
	enum {
			 pgameServiceID		= 1, 
		 wildCard			= 2, 
	};
}
#define IM_CHANNEL_LOGIN_RESP           0x16008
namespace x16008{
	enum {
		    result               = 1, 
		    msg                  = 2, 
		  wildCard			   = 3, 
			  announcement		   = 4, 
	};
}
#define IM_CHANNEL_LOGOUT_REQ            0x16009
namespace x16009{
}
#define IM_CHANNEL_LOGOUT_RESP            0x16019
namespace x16019{
	enum {
				result			= 1, 
				msg				= 2, 
				room_id 		= 3,
				user_id			= 4,
	};
}
#define IM_CHANNEL_MODIFY_REQ            0x16011
namespace x16011{
	enum {
		    operate            = 1,     
		    channel            = 2,     
		   wildCard			= 3,     
	};
}
#define IM_CHANNEL_MODIFY_RESP           0x16012
namespace x16012{
	enum {
		   result               = 1, 
		   msg                  = 2, 
		 wildCard			  = 3, 
	};
}
#define IM_CHANNEL_GETINFO_REQ			0x16000
#define IM_CHANNEL_GETINFO_RESP			0x16001
namespace x16001{
	enum{
		 result	= 2,
		 msg		= 3,
			xGame_channel = 1, 
	};
}
#define IM_CHANNEL_TEXTMSG_REQ	    	0x16002    
namespace x16002{
	enum{
			textMsg	 = 1, 
			wildCard = 2, 
			expand	 = 3, 
		  flag     = 4, 
	};
}
#define IM_CHANNEL_VOICEMSG_REQ	         0x16003
namespace x16003{
	enum{
			voiceFilePath	   = 1, 
			voiceDurationTime  = 2, 
			wildCard		   = 3, 
		  txt                = 4, 
			expand			   = 5, 
		  flag               = 6, 
	};
}
#define IM_CHANNEL_SENDMSG_RESP          0x16010
namespace x16010{
	enum
	{
		  result             = 1, 
		  msg                = 2, 
		   type               = 3,   
			wildCard		   = 4,   
		  textMsg            = 5,   
		  url                = 6,   
			voiceDurationTime  = 7,   
			expand			   = 8,   
		   shield             = 9,   
			channel			   = 10,  
		  flag               = 11,  
	};
}
#define IM_CHANNEL_MESSAGE_NOTIFY	     0x16004
namespace x16004 {
	enum {
			user_id			= 1,  
			message_body	= 2,  
			nickname		= 3,  
			ext1			= 4,  
			ext2			= 5,  
			channel			= 6,  
			wildcard		= 7,  
			message_type	= 8,  
		  voiceDuration	= 9,  
		  attach          = 10, 
		   shield          = 11, 
			uid				= 12,
	};
}
#define IM_CHANNEL_HISTORY_MSG_REQ       0x16005
namespace x16005{
	enum {
			index    = 1,			
			count    = 2,			
			wildcard = 3,			
	};
}
namespace xHistoryMsgInfo
{
	enum {
			index			= 1,		
			ctime			= 2,		
			user_id			= 3,		
			message_body	= 4,		
			nickname		= 5,		
			ext1			= 6,		
			ext2			= 7,		
			channel			= 8,		
			wildcard		= 9,		
			message_type	= 10,		
		  voiceDuration	= 11,		
		  attach          = 12,		
		   shield          = 13,           
			uid				= 14,
	};
}
#define IM_CHANNEL_HISTORY_MSG_RESP       0x16006
namespace x16006{
	enum {
			result				 = 2,
		  msg					 = 3,
		 xHistoryMsg = 1,		
	};
}
#define IM_CHANNEL_PUSH_MSG_NOTIFY        0x16013
namespace x16013{
    enum {
         type = 1,            
         data = 2,		
    };
}
#define IM_CHANNEL_GET_PARAM_REQ								0x16014
namespace x16014 {
	enum {
	};
}
#define IM_CHANNEL_GET_PARAM_RESP								0x16015
namespace x16015 {
	enum {
		  result              = 1, 
		  msg                 = 2,
			announcement		= 3,
	};
}
#define IM_CHANNEL_SET_SENDTIME_REQ							0x16016
namespace x16016 {
	enum {
		  time              = 1,
	};
}
#define	IM_RECORD_STRART_REQ	             0x19000
namespace x19000{
	enum{
				strfilepath	   = 1,  
		      ext            = 2,  
		       speech         = 3,  
	};
}
#define	IM_RECORD_STOP_REQ		             0x19001
#define	IM_RECORD_STOP_RESP		             0x19002
namespace x19002{
	enum{
		      result           = 4,  
		      msg              = 5, 
				time		     = 1, 
				strfilepath      = 2, 
		      ext              = 3,  
	};
}
#define	IM_RECORD_STARTPLAY_REQ		         0x19003
namespace x19003{
	enum{
				strUrl		= 1, 
				strfilepath	= 2, 
		      ext         = 3,  
	};
}
#define	IM_RECORD_FINISHPLAY_RESP	         0x19004
namespace x19004{
	enum{
		     result      = 1, 
		     describe	   = 2, 
		     ext         = 3, 
	};
}
#define	IM_RECORD_PLAY_PERCENT_NOTIFY	     0x19016
namespace x19016{
	enum{
		      percent     = 1, 
		     ext         = 2, 
	};
}
#define	IM_RECORD_STOPPLAY_REQ		         0x19005
namespace x190005
{
}
enum yvspeech
{
	speech_file = 0,              
	speech_file_and_url = 1,      
	speech_url = 2,               
	speech_live = 3,              
};
#define IM_SPEECH_STOP_RESP				    0x19009
namespace x19009{
	enum{
				err_id     = 1,  
				err_msg    = 2,  
				result	   = 3,  
		      ext        = 4,  
		      url        = 5,  
	};
}
#define IM_SPEECH_SETLANGUAGE_REQ	        0x19008
namespace x19008{
	enum{
			inlanguage     = 1,     
		   outlanguage    = 2,    
	};
}
enum yvimspeech_language
{
	im_speech_zn = 1, 
	im_speech_ct = 2, 
	im_speech_en = 3, 
};
enum yvimspeech_outlanguage
{
	im_speechout_simplified       = 0,  
	im_speechout_traditional      = 1,  
};
#define IM_UPLOAD_FILE_REQ				  0x19010
namespace x19010{
	enum{
				filename   = 1,   
		      fileid     = 2,   
	};
}
#define IM_UPLOAD_FILE_RESP		          0x19011
namespace x19011{
	enum{
				result	    = 1,   
		      msg         = 2,   
		      fileid      = 3,   
		      fileurl     = 4,   
		      percent     = 5,   
	};
}
#define IM_DOWNLOAD_FILE_REQ              0x19012
namespace x19012 {
	enum {
		      url         = 1,   
		      filename    = 2,   
		      fileid      = 3,   
	};
}
#define IM_DOWNLOAD_FILE_RESP             0x19013
namespace x19013 {
	enum {
				result	     = 1,   
		      msg          = 2,   
		      filename     = 3,   
		      fileid       = 4,   
		      percent      = 5,   
	};
}
#define	IM_RECORD_SETINFO_REQ	          0x19014
namespace x19014{
	enum{
				times	      = 1,   
		       volume        = 2,   
				rate		  = 3,	 
	};
}
#define	IM_RECORD_VOLUME_NOTIFY	          0x19015
namespace x19015{
    enum{
		      ext           = 1,  
		       volume        = 2,  
	};
}
#define IM_TOOL_HAS_CACHE_FILE            0x19017
namespace x19017{
	enum
	{
		      url             = 1, 
	};
}
#define IM_GET_CACHE_FILE_REQ             0x19018  
namespace x19018{
	enum
	{
		      url             = 1, 
	};
}
#define IM_GET_CACHE_FILE_RESP            0x19019 
namespace x19019{
	enum
	{
				result			= 1,   
		      msg				= 2,   
		      url             = 3, 
		      filepath        = 4,   
	};
}
#define IM_CACHE_CLEAR                     0x19020
namespace x19020{
}
#define IM_TOOL_FLOW_REQ                     0x19021
namespace x19021{
    
    
}
#define IM_TOOL_FLOW_RESP                    0x19022
namespace x19022{
    enum
    {
    		result			= 1,   
          msg				= 2,   
          upflow          = 3,   
          downflow        = 4,   
          allflow         = 5,    
    };
}
#define IM_TEXT_TO_VOICE_REQ             0x19023  
namespace x19023{
	enum
	{
		      text            = 1,
				targetType		= 2,
				ext				= 3,    
	};
}
#define IM_TEXT_TO_VOICE_RESP             0x19024  
namespace x19024{
	enum
	{
				result			= 1,
		      msg			    = 2,
		      content         = 3,
				ext				= 4,    
	};
}
#define IM_CHAT_ROBOT_OPEN_REQ            0x19025      
namespace x19025{
    enum{
                targetType        = 1,    
    };
}
#endif
