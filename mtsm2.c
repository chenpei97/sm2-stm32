#include "mtsm2.h"
#include "sm2.h"
#include <string.h>
/*
功能：使用压缩钥匙XSM2验签
pubkeyx:压缩公钥X，17字节，0x02/0x03开头
pubkeylen:缩公钥X长度
sign:签名字符串
signlen:签名字符串长
data:数据字符串
datalen：数据字符串长度
*/
int mt_sm2_verify_compress(
        unsigned char* pubkeyX, int pubkeylen, unsigned char* sign, int signlen, unsigned char* data, int datalen) {
    //参数校验
    if (pubkeyX == NULL || pubkeylen < 0 || sign == NULL || signlen <= 0 || data == NULL || datalen <= 0) {
        return MT_SM2_ERROR_PARAM;
    }
    int bc = -1;
    unsigned char pubkeyY[32], he[32];
    //签名数据长度
    if (signlen != 64)
        return MT_SM2_ERROR_SIGNLEN;
    //公钥X长度
    if (pubkeylen != 33)
        return MT_SM2_ERROR_PUBLICLEN;
    //公钥X压缩码
    switch (pubkeyX[0]) {
        case 0x02:
            bc = 0;
            break;
        case 0x03:
            bc = 1;
            break;
        default:
            return MT_SM2_ERROR_COMPRESSCODE;
    }
    //获取公钥Y
    if (sm2_key_get_y(&pubkeyX[1], 32, pubkeyY, 32, bc) < 0) {
        return MT_SM2_ERROR_GETPUBLICY;
    }
    //计算sm3 hash
    char userid[] = "1234567812345678";
    if (sm3_e((unsigned char *)userid, strlen(userid), &pubkeyX[1], 32, pubkeyY, 32, data, datalen, he) < 0) {
        return MT_SM2_ERROR_SM3HASH;
    }
    // SM2验签
    if (sm2_verify_mt(he, 32, &sign[0], 32, &sign[32], 32, &pubkeyX[1], 32, pubkeyY, 32) < 0) {
        return MT_SM2_ERROR_VERIFY;
    }

    return MT_SM2_OK;
}

/*
功能：非压缩方式SM验签
pubkeyx:压缩公钥X，17字节，0x02/0x03开头
pubkeylen:缩公钥X长度
sign:签名字符串
signlen:签名字符串长
data:数据字符串
datalen：数据字符串长度
*/
int mt_sm2_verify(void* pubkey, int pubkeylen, void* sign, int signlen, void* data, int datalen) {
    //参数校验
    if (pubkey == NULL || pubkeylen <= 0 || sign == NULL || signlen <= 0 || data == NULL || datalen <= 0) {
        return MT_SM2_ERROR_PARAM;
    }
    unsigned char* pubk = (unsigned char*)pubkey;
    unsigned char* signdata = (unsigned char*)sign;
    unsigned char* data_c = (unsigned char*)data;
    unsigned char he[32];
    //签名数据长度
    if (signlen != 64)
        return MT_SM2_ERROR_SIGNLEN;
    //公钥X长度
    if (pubkeylen != 64)
        return MT_SM2_ERROR_PUBLICLEN;
    //计算sm3 hash
		char tmp[] = "1234567812345678";
    if (sm3_e((unsigned char *)tmp, strlen(tmp), &pubk[0], 32, &pubk[32], 32, data_c, datalen, he) < 0) {
        return MT_SM2_ERROR_SM3HASH;
    }
    // SM2验签
	int sm2_res = sm2_verify_mt(he, 32, &signdata[0], 32, &signdata[32], 32, &pubk[0], 32, &pubk[32], 32);
    if (sm2_res < 0) {
        return MT_SM2_ERROR_VERIFY;
    }

    return MT_SM2_OK;
}
