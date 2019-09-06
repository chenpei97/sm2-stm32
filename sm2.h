#ifndef __SM2_HEADER_2015_12_28__
#define __SM2_HEADER_2015_12_28__

#include "sm3.h"
#include "miracl.h"

#ifdef __cplusplus
extern "C"{
#endif

void sm2_keygen(unsigned char *wx,int *wxlen, unsigned char *wy,int *wylen,unsigned char *privkey, int *privkeylen);
/*
功能：生成SM2公私钥对
[输出] wx：   公钥的X坐标，不足32字节在前面加0x00
[输出] wxlen: wx的字节数，32
[输出] wy：   公钥的Y坐标，不足32字节在前面加0x00
[输出] wylen: wy的字节数，32
[输出] privkey：私钥，不足32字节在前面加0x00
[输出] privkeylen： privkey的字节数，32
*/


int  sm2_encrypt(unsigned char *msg,int msglen, unsigned char *wx,int wxlen, unsigned char *wy,int wylen, unsigned char *outmsg);
/*
功能：用SM2公钥加密数据。加密结果比输入数据多96字节！
[输入] msg     要加密的数据
[输入] msglen：msg的字节数
[输入] wx：    公钥的X坐标
[输入] wxlen:  wx的字节数，不超过32字节
[输入] wy：    公钥的Y坐标
[输入] wylen:  wy的字节数，不超过32字节

[输出] outmsg: 加密结果，比输入数据多96字节！，C1（64字节）和C3（32字节）保留前导0x00

返回值：
		-1：        加密失败
		msglen+96： 加密成功
*/

int  sm2_decrypt(unsigned char *msg,int msglen, unsigned char *privkey, int privkeylen, unsigned char *outmsg);
/*
功能：用SM2私钥解密数据。解密结果比输入数据少96字节！
[输入] msg     要解密的数据，是sm2_encrypt()加密的结果，不少于96字节。
[输入] msglen：msg的字节数
[输入] privkey： 私钥
[输入] privkeylen： privkeylen的字节数

[输出] outmsg: 解密结果，比输入数据少96字节！

返回值：
		-1：        解密失败
		msglen-96： 解密成功
*/

#ifdef __cplusplus
}
#endif


#endif
