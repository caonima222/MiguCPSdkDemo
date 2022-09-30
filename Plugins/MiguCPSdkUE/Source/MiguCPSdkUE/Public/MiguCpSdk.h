#pragma once
#ifdef MIGUCPSDK_EXPORTS
#define MIGUCPSDK_API __declspec(dllexport)
#else
#define MIGUCPSDK_API __declspec(dllimport)
#endif


typedef void(*REQUEST_CALLBACK)(const char*);

typedef struct TagMiguPayInfo
{
	char* gameName;     //��Ϸ����
	char* contentCode;  //����Ϸ���ݹ���ƽ̨�����ݴ���
	char* gameAccount;  //CP����Ϸ�˻�ID
	char* orderId;      //������
	char* propName;     //��������
	int orderAmount;	//��������λ���֣�
}MiguPayInfo;

extern "C" {
	//��ʼ��
	MIGUCPSDK_API int CreateInstance_MsgSDK(void);

	//�ͷ�
	MIGUCPSDK_API void ReleaseInstance(void);

	//��½ 
	MIGUCPSDK_API void Login(const char* contentCode, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//��½
	MIGUCPSDK_API void GetLoginInfo(const char* contentCode, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//��ȡһ��Token
	MIGUCPSDK_API void GetToken(REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//��ȡͨ����Ϣ
	MIGUCPSDK_API void GetGeneralInfo(REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//��ѯ�û�����ƽ̨���ù��ĳɾ�
	MIGUCPSDK_API void QueryAllAchievement(REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//���������û��ɾ�
	MIGUCPSDK_API void SetAchievementBatch(const char* data, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//��ѯ�û������ɾ�״̬
	MIGUCPSDK_API void QueryAchievement(const char* achievementId, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//�����û������ɾ�
	MIGUCPSDK_API void SetAchievement(const char* achievementId, int achievementType, double reachValue, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//��ѯ�û������ɾ���ɽ���
	MIGUCPSDK_API void QueryAchievementPercentage(const char* achievementId, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//ͨ�ýӿ�
	MIGUCPSDK_API void CommonBusiness(const char* bussinessUrl, const char* data, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//ͨ�ýӿڳ�ʼ��
	MIGUCPSDK_API int CommonBusinessInit(const char* appId, const char* appSecret);

	//֧��
	MIGUCPSDK_API void CloudPay(const MiguPayInfo payInfo, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//����CP֧��Url
	//payUrl����Ϸ���ɵ�H5֧�����ӣ�����Ϸ�ṩ����
	MIGUCPSDK_API void CloudPayToCP(const char* payUrl, REQUEST_CALLBACK callback, int timeoutSeconds = 10);

	//ͨ�ýӿ�-MsgSDK
	MIGUCPSDK_API void CommonInterfaceByMsgSDK(const int type, const char* data, REQUEST_CALLBACK callback, int timeoutSeconds = 10);
}


class MIGUCPSDK_API IMiguCpSdk {
public:
	enum QUERY_RESULT {
		RESULT_OK = 0,								//�ɹ�
		RESULT_TIMEOUT = -1,						//��ʱ
		RESULT_INVALID_PARAMETER = -2,				//�������󣬱���ָ��ΪNULL
		RESULT_EXCEPTION = -3,						//�쳣����������Json��ʽ����
		RESULT_GENERAL_FILE_NOT_EXIST = -4,         //�����ļ�������
		RESULT_SERVER_NULL = -5,                    //������̨���������Ϊ��
		RESULT_USERID_NULL = -6,                    //��ȡuserid����ϢΪ��
		RESULT_LIBCURL_ERROR = -7,                  //http���󱨴�
		RESULT_MSGSDK_ERROR = -8,                   //��Ϣsdk����
		RESULT_REQUEST_FAIL = -9,                   //���󷵻�ʧ��
	};
	
	//��½ 
	virtual void Login(const char* contentCode, REQUEST_CALLBACK callback,int timeoutSeconds = 10) = 0;

	//��½
	virtual void GetLoginInfo(const char* contentCode, REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//��ȡͨ����Ϣ
	virtual void GetGeneralInfo(REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//��ѯ�û�����ƽ̨���ù��ĳɾ�
	virtual void QueryAllAchievement(REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//���������û��ɾ�
	virtual void SetAchievementBatch(const char* data, REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//��ѯ�û������ɾ�״̬
	virtual void QueryAchievement(const char* achievementId, REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//�����û������ɾ�
	virtual void SetAchievement(const char* achievementId, int achievementType, double reachValue, REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//��ѯ�û������ɾ���ɽ���
	virtual void QueryAchievementPercentage(const char* achievementId, REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	//ͨ�ýӿ�
	virtual void CommonBusiness(const char* bussinessUrl, const char* data,REQUEST_CALLBACK callback, int timeoutSeconds = 10) = 0;

	virtual int CommonBusinessInit(const char* appId, const char* appSecret) = 0;
};