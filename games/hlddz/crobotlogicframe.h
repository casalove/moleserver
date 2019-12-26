#ifndef _C_ROBOT_LOGIC_FRAME_H_INCLUDE_
#define _C_ROBOT_LOGIC_FRAME_H_INCLUDE_

#include "cdefines.h"
#include "GameLogic.h"

class CRobotLogicFrame : public RobotLogicFrame
{
public:
	/// ���캯��
	CRobotLogicFrame();
	/// ��������
	~CRobotLogicFrame();

	/// ���õ�ǰ���
	virtual void SetGamePlayer(Player* pPlayer,Room* pRoom) { m_g_myself = pPlayer; m_g_myselfRoom = pRoom;}

	/// ���ڴ����û�׼�������Ϣ
	virtual void OnProcessPlayerReadyMes(int playerId);
	/// ���ڴ����û���ʼ��Ϸ��ʼ��Ϣ
	virtual void OnProcessPlayerGameStartMes();
	/// ���ڴ����û�������Ϸ��Ϣ
	virtual void OnProcessPlayerGameOverMes(void);
	/// ���ڴ����û�������Ϸ��������Ϣ
	virtual void OnProcessPlayerRoomMes(Json::Value &mes);
	/// �����û����뷿����Ϣ
	virtual void OnProcessEnterRoomMsg(int playerId);
	/// �����û��뿪������Ϣ
	virtual void OnProcessLeaveRoomMsg(int playerId);
	/// �����û�����������Ϣ
	virtual void OnProcessReEnterRoomMes(int playerId);
	/// �����û�������Ϣ
	virtual void OnProcessOfflineRoomMes(int playerId);
	/// �����û���ʱ����Ϣ
	virtual void OnProcessTimerMsg(int timerId,int curTimer);

private:
	Player *m_g_myself;
    Room *m_g_myselfRoom;

	//�������
protected:
	CGameLogic						m_GameLogic;						//��Ϸ�߼�

	//�˿˱���
protected:
	uint16 							m_cbTurnCardCount;					//������Ŀ
	uint8							m_cbTurnCardData[20];				//�����б�
	uint16							m_wOutCardUser;						//�������
	uint16							m_wBankerUser;						//�������

	//�����˿�
protected:
	uint8							m_cbBackCard[3];					//��������
	uint16 							m_cbHandCardCount;					//�˿���Ŀ
	uint8							m_cbHandCardData[20];				//�����˿�
	uint16 							m_cbCurrentLandScore;				//�ѽз���

	//�зֽ׶α���
public:
	int							m_cbCallScorePhase;					//���ƽ׶�
};

#endif