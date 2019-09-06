#ifndef __SM2_HEADER_2015_12_28__
#define __SM2_HEADER_2015_12_28__

#include "sm3.h"
#include "miracl.h"

#ifdef __cplusplus
extern "C"{
#endif

void sm2_keygen(unsigned char *wx,int *wxlen, unsigned char *wy,int *wylen,unsigned char *privkey, int *privkeylen);
/*
���ܣ�����SM2��˽Կ��
[���] wx��   ��Կ��X���꣬����32�ֽ���ǰ���0x00
[���] wxlen: wx���ֽ�����32
[���] wy��   ��Կ��Y���꣬����32�ֽ���ǰ���0x00
[���] wylen: wy���ֽ�����32
[���] privkey��˽Կ������32�ֽ���ǰ���0x00
[���] privkeylen�� privkey���ֽ�����32
*/


int  sm2_encrypt(unsigned char *msg,int msglen, unsigned char *wx,int wxlen, unsigned char *wy,int wylen, unsigned char *outmsg);
/*
���ܣ���SM2��Կ�������ݡ����ܽ�����������ݶ�96�ֽڣ�
[����] msg     Ҫ���ܵ�����
[����] msglen��msg���ֽ���
[����] wx��    ��Կ��X����
[����] wxlen:  wx���ֽ�����������32�ֽ�
[����] wy��    ��Կ��Y����
[����] wylen:  wy���ֽ�����������32�ֽ�

[���] outmsg: ���ܽ�������������ݶ�96�ֽڣ���C1��64�ֽڣ���C3��32�ֽڣ�����ǰ��0x00

����ֵ��
		-1��        ����ʧ��
		msglen+96�� ���ܳɹ�
*/

int  sm2_decrypt(unsigned char *msg,int msglen, unsigned char *privkey, int privkeylen, unsigned char *outmsg);
/*
���ܣ���SM2˽Կ�������ݡ����ܽ��������������96�ֽڣ�
[����] msg     Ҫ���ܵ����ݣ���sm2_encrypt()���ܵĽ����������96�ֽڡ�
[����] msglen��msg���ֽ���
[����] privkey�� ˽Կ
[����] privkeylen�� privkeylen���ֽ���

[���] outmsg: ���ܽ����������������96�ֽڣ�

����ֵ��
		-1��        ����ʧ��
		msglen-96�� ���ܳɹ�
*/

#ifdef __cplusplus
}
#endif


#endif
