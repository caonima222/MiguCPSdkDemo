#pragma once
#ifdef MIGUCPSDK_EXPORTS
#define MIGUCPSDK_API __declspec(dllexport)
#else
#define MIGUCPSDK_API __declspec(dllimport)
#endif


typedef void(*REQUEST_CALLBACK)(const char*);

typedef struct TagMiguPayInfo
{
	char* gameName;     //游戏名称
	char* contentCode;  //云游戏内容管理平台的内容代码
	char* gameAccount;  //CP的游戏账户ID
	char* orderId;      //订单号
	char* propName;     //道具名称
	int orderAmount;	//订单金额（单位：分）
}MiguPayInfo;

extern "C" {
	//初始化
	MIGUCPSDK_API int CreateInstance_MsgSDK(void);

	//释放
	MIGUCPSDK_API void ReleaseInstance(void);

	//登陆 
	MIGUCPSDK_API void Login(const char* contentCode, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//登陆
	MIGUCPSDK_API void GetLoginInfo(const char* contentCode, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//获取一级Token
	MIGUCPSDK_API void GetToken(REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//获取通用信息
	MIGUCPSDK_API void GetGeneralInfo(REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//查询用户所有平台设置过的成就
	MIGUCPSDK_API void QueryAllAchievement(REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//批量设置用户成就
	MIGUCPSDK_API void SetAchievementBatch(const char* data, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//查询用户单个成就状态
	MIGUCPSDK_API void QueryAchievement(const char* achievementId, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//设置用户单个成就
	MIGUCPSDK_API void SetAchievement(const char* achievementId, int achievementType, double reachValue, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//查询用户单个成就完成进度
	MIGUCPSDK_API void QueryAchievementPercentage(const char* achievementId, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//通用接口
	MIGUCPSDK_API void CommonBusiness(const char* bussinessUrl, const char* data, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//通用接口初始化
	MIGUCPSDK_API int CommonBusinessInit(const char* appId, const char* appSecret);

	//支付
	MIGUCPSDK_API void CloudPay(const MiguPayInfo payInfo, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//拉起CP支付Url
	//payUrl：游戏生成的H5支付链接，需游戏提供传入
	MIGUCPSDK_API void CloudPayToCP(const char* payUrl, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//通用接口-MsgSDK
	MIGUCPSDK_API void CommonInterfaceByMsgSDK(const int type, const char* data, REQUEST_CALLBACK callback, int timeoutSeconds = 10);
}


class MIGUCPSDK_API IMiguCpSdk {
public:
	enum QUERY_RESULT {
		RESULT_OK = 0,								//成功
		RESULT_TIMEOUT = -1,						//超时
		RESULT_INVALID_PARAMETER = -2,				//参数错误，比如指针为NULL
		RESULT_EXCEPTION = -3,						//异常，比如数据Json格式不对
		RESULT_GENERAL_FILE_NOT_EXIST = -4,         //共享文件不存在
		RESULT_SERVER_NULL = -5,                    //请求中台服务端数据为空
		RESULT_USERID_NULL = -6,                    //获取userid等信息为空
		RESULT_LIBCURL_ERROR = -7,                  //http请求报错
		RESULT_MSGSDK_ERROR = -8,                   //消息sdk错误
		RESULT_REQUEST_FAIL = -9,                   //请求返回失败
	};
	
	//登陆 
	virtual void Login(const char* contentCode, REQUEST_CALLBACK callback,int timeoutSeconds = 10) = 0;

	//登陆
	virtual void GetLoginInfo(const char* contentCode, REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//获取通用信息
	virtual void GetGeneralInfo(REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//查询用户所有平台设置过的成就
	virtual void QueryAllAchievement(REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//批量设置用户成就
	virtual void SetAchievementBatch(const char* data, REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//查询用户单个成就状态
	virtual void QueryAchievement(const char* achievementId, REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//设置用户单个成就
	virtual void SetAchievement(const char* achievementId, int achievementType, double reachValue, REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//查询用户单个成就完成进度
	virtual void QueryAchievementPercentage(const char* achievementId, REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//通用接口
	virtual void CommonBusiness(const char* bussinessUrl, const char* data,REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	virtual int CommonBusinessInit(const char* appId, const char* appSecret) = 0;
};