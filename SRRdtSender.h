#pragma once
#include "RdtSender.h"

class SRRdtSender :public RdtSender {
private:
	int expectSequenceNumberSend;	// ��һ��������� 
	bool waitingState;				// �Ƿ��ڵȴ�Ack��״̬
	Packet *pPacketWaitingAck;		// �ѷ��Ͳ��ȴ�Ack�����ݰ�
	// ���±�������ά���������ڣ�
	// ��������������ʱ��base < nowlMax = rMax;
	// ���������ڲ�����ʱ��base < rMax��0 < nowlMax < base;
	// ������������ ��base��ʼ, base��base+1��... ��0��... ��lMax-1
	int windowN;					// �������ڴ�С
	int base;						// ��ǰ���ڵ���ŵĻ�ַ
	int rMax;						// ��������Ͻ磬��������ΪrMax-1
	int nowlMax;					// ���������ұ߽磬���ΪrMax����СΪ1

public:
	bool getWaitingState();
	bool send(Message &message);
	void receive(Packet &ackPkt);	//����ȷ��Ack������NetworkServiceSimulator����	
	void timeoutHandler(int seqNum);//Timeout handler������NetworkServiceSimulator����

	SRRdtSender(Configuration config);
	virtual ~SRRdtSender();
};