#ifndef __MT_SM2__
#define __MT_SM2__

//#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/stat.h>
//#include <sys/types.h>
#include <time.h>
//#include <unistd.h>
#include "hexdump.h"
#include "sm2.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MT_SM2_OK 1                   //验签OK
#define MT_SM2_ERROR_PUBLICLEN -1     //公钥长度错误
#define MT_SM2_ERROR_COMPRESSCODE -2  //公钥长压缩码错误，只能是0x02,0x03
#define MT_SM2_ERROR_SIGNLEN -3       //签名长度错误，签名长度只能是64字节
#define MT_SM2_ERROR_SM3HASH -4       //计算sm3hash错误
#define MT_SM2_ERROR_GETPUBLICY -5    //计算公钥Y错误
#define MT_SM2_ERROR_VERIFY -6        //验签错误
#define MT_SM2_ERROR_PARAM -7         //参数错误

/*
pubkeyx:压缩公钥X，17字节，0x02/0x03开头
pubkeylen:缩公钥X长度
sign:签名字符串
signlen:签名字符串长
data:数据字符串
datalen：数据字符串长度
*/
int mt_sm2_verify_compress(
        unsigned char* pubkeyX, int pubkeylen, unsigned char* sign, int signlen, unsigned char* data, int datalen);

/*
功能：非压缩方式SM验签
pubkeyx:压缩公钥X，17字节，0x02/0x03开头
pubkeylen:缩公钥X长度
sign:签名字符串
signlen:签名字符串长
data:数据字符串
datalen：数据字符串长度
*/
int mt_sm2_verify(void* pubkey, int pubkeylen, void* sign, int signlen, void* data, int datalen);

#ifdef __cplusplus
}
#endif

#endif
