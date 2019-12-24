/************************************************************************
* @file      WebSocketConnect.h
* @brief     websocketЭ�����
* @author    jiangwang
* @data      2019-12-14
* @version   0.1
************************************************************************/

#pragma once

#include <string>
#include <queue>
#include "TcpServer.h"

class WebSocketEvent;
class WebSocketPacket;
class WebSocketConnect : public TcpSocket
{
public:
	WebSocketConnect(WebSocketEvent * wevent, uint32 buffersize = MESSAGE_BUFFER_SIZE);
	~WebSocketConnect();

	// ���� WebSocket ����������
	bool parseHandshake(const char * pData, int len);

	// �ؿͻ��˵�����Э��
	std::string respondHandshake();

	void sendMsg(WebSocketPacket * pack);
	void sendMsg(void * msg, uint32 len);
protected:

	virtual void on_msgbuffer(MessageBuffer * buffer);
	virtual void on_clsesocket();
	virtual void on_writecomplete();

private:
	WebSocketPacket * createPacket();
	void recyclePacket(WebSocketPacket * pack);
	void send_top_msg();
	bool decodingDatas(WebSocketPacket* pPacket, uint32 msg_mask);
private:
	std::string __m_strKey;
	std::string __m_strHost;

	bool __m_isHandshake;
	WebSocketEvent * __m_webevent;
	WebSocketPacket * __m_readPacket;
	std::queue<WebSocketPacket *> __m_sendPackets;
};
