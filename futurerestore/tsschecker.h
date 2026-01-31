#ifndef tsschecker_h
#define tsschecker_h

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <plist/plist.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char *version;
    char *build;
    char *url;
} firmwareVersion;

typedef enum {
    kNonceTypeNone = 0,
    kNonceTypeSHA1,
    kNonceTypeSHA384
} nonceType;

// 核心函数声明（用于链接）
firmwareVersion getLatestFirmwareForDevice(uint32_t cpid, uint32_t bdid, bool ota);
uint64_t parseECID(const char *ecid);
const char *getBoardTypeFromProductType(const char *productType);
const char *getProductTypeFromCPIDandBDID(uint32_t cpid, uint32_t bdid);
uint32_t getCPIDForProductType(const char *productType);
uint32_t getBDIDForProductType(const char *productType);
nonceType nonceTypeForCPID(uint32_t cpid);

#ifdef __cplusplus
}
#endif

#endif
