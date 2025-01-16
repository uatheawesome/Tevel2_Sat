/*
 * isismepsv2_ivid5_pdu_types.h
 *
 * AUTOGENERATED CODE
 * Please do not perform manual edits
 * Generated using autogen v1.0.3
 *
 * Generated from:
 *  - imepsv2_structs.yaml
 *  - imepsv2_pdu.yaml
 */

#ifndef ISISMEPSV2_IVID5_PDU_TYPES_H_
#define ISISMEPSV2_IVID5_PDU_TYPES_H_

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* DEFINES */

#define ISISMEPSV2_IVID5_PDU_NOP_ID {0x11, 0x05, 0x02, 0x00}
#define ISISMEPSV2_IVID5_PDU_CANCEL_ID {0x11, 0x05, 0x04, 0x00}
#define ISISMEPSV2_IVID5_PDU_RESETWATCHDOG_ID {0x11, 0x05, 0x06, 0x00}
#define ISISMEPSV2_IVID5_PDU_OUTPUTBUSGROUPON_ID {0x11, 0x05, 0x10, 0x00}
#define ISISMEPSV2_IVID5_PDU_OUTPUTBUSGROUPOFF_ID {0x11, 0x05, 0x12, 0x00}
#define ISISMEPSV2_IVID5_PDU_OUTPUTBUSGROUPSTATE_ID {0x11, 0x05, 0x14, 0x00}
#define ISISMEPSV2_IVID5_PDU_OUTPUTBUSCHANNELON_ID {0x11, 0x05, 0x16, 0x00}
#define ISISMEPSV2_IVID5_PDU_OUTPUTBUSCHANNELOFF_ID {0x11, 0x05, 0x18, 0x00}
#define ISISMEPSV2_IVID5_PDU_SWITCHTONOMINAL_ID {0x11, 0x05, 0x30, 0x00}
#define ISISMEPSV2_IVID5_PDU_SWITCHTOSAFETY_ID {0x11, 0x05, 0x32, 0x00}
#define ISISMEPSV2_IVID5_PDU_GETSYSTEMSTATUS_ID {0x11, 0x05, 0x40, 0x00}
#define ISISMEPSV2_IVID5_PDU_GETOVERCURRENTFAULTSTATE_ID {0x11, 0x05, 0x42, 0x00}
#define ISISMEPSV2_IVID5_PDU_GETHOUSEKEEPINGDATARAW_ID {0x11, 0x05, 0x50, 0x00}
#define ISISMEPSV2_IVID5_PDU_GETHOUSEKEEPINGDATARAWWITHCONVERSION_ID {0x11, 0x05, 0x50, 0x00}
#define ISISMEPSV2_IVID5_PDU_GETHOUSEKEEPINGDATAENG_ID {0x11, 0x05, 0x52, 0x00}
#define ISISMEPSV2_IVID5_PDU_GETHOUSEKEEPINGDATARUNNINGAVG_ID {0x11, 0x05, 0x54, 0x00}
#define ISISMEPSV2_IVID5_PDU_GETCONFIGURATIONPARAMETER_ID {0x11, 0x05, 0x82, 0x00}
#define ISISMEPSV2_IVID5_PDU_SETCONFIGURATIONPARAMETER_ID {0x11, 0x05, 0x84, 0x00}
#define ISISMEPSV2_IVID5_PDU_RESETCONFIGURATIONPARAMETER_ID {0x11, 0x05, 0x86, 0x00}
#define ISISMEPSV2_IVID5_PDU_RESETCONFIGURATION_ID {0x11, 0x05, 0x90, 0x00}
#define ISISMEPSV2_IVID5_PDU_LOADCONFIGURATION_ID {0x11, 0x05, 0x92, 0x00}
#define ISISMEPSV2_IVID5_PDU_SAVECONFIGURATION_ID {0x11, 0x05, 0x94, 0x00}
#define ISISMEPSV2_IVID5_PDU_RESET_ID {0x11, 0x05, 0xAA, 0x00}


/* ENUMS */

/*!
 * Enumeration of all ISISPACE modular EPS channels
 */
typedef enum __attribute__ ((__packed__)) isismepsv2_ivid5_pdu__eps_channel_t
{
    isismepsv2_ivid5_pdu__eps_channel__channel_16v_perm = 0u,
    isismepsv2_ivid5_pdu__eps_channel__channel_16v_sw1 = 1u,
    isismepsv2_ivid5_pdu__eps_channel__channel_16v_sw2 = 2u,
    isismepsv2_ivid5_pdu__eps_channel__channel_16v_sw3 = 3u,
    isismepsv2_ivid5_pdu__eps_channel__channel_5v_perm = 4u,
    isismepsv2_ivid5_pdu__eps_channel__channel_5v_sw1 = 5u,
    isismepsv2_ivid5_pdu__eps_channel__channel_5v_sw2 = 6u,
    isismepsv2_ivid5_pdu__eps_channel__channel_5v_sw3 = 7u,
    isismepsv2_ivid5_pdu__eps_channel__channel_3v3_perm = 8u,
    isismepsv2_ivid5_pdu__eps_channel__channel_3v3_sw1 = 9u,
    isismepsv2_ivid5_pdu__eps_channel__channel_3v3_sw2 = 10u,
    isismepsv2_ivid5_pdu__eps_channel__channel_3v3_sw3 = 11u,
} isismepsv2_ivid5_pdu__eps_channel_t;

/* STRUCTS */

/*!
 *  ISISMEPSV2_IVID5_PDU instance structure
 */
typedef struct
{
    uint8_t i2cAddr; /*!< I2C address used for this instance */
} ISISMEPSV2_IVID5_PDU_t;

/*!
 * Union for storing the parameters for struct ReplyHeader.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__replyheader_t
{
    unsigned char raw[5];
    struct __attribute__ ((__packed__))
    {
        uint8_t stid; /*!< See "System Type Identifier (STID)" (page 22) */
        uint8_t ivid; /*!< See "Interface Version Identifier (IVID)" (page 23) */
        uint8_t rc; /*!< See "Board Identifier (BID)" (page 24) */
        uint8_t bid; /*!< Response code as stated in the header (inside parenthesis). */
        uint8_t cmderr : 4; /*!< See "Response Status Information (STAT)" (page 25) */
        uint8_t reserved : 3; /*!< See "Response Status Information (STAT)" (page 25) */
        uint8_t new_flag : 1; /*!< See "Response Status Information (STAT)" (page 25) */
    } fields;
} isismepsv2_ivid5_pdu__replyheader_t;

/*!
 * Union for storing the parameters for struct VIPDraw.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__vipdraw_t
{
    unsigned char raw[6];
    struct __attribute__ ((__packed__))
    {
        int16_t volt; /*!<  \note conversion: eng. value [in mV] = 0.9765625 * raw + 0*/
        int16_t current; /*!<  \note conversion: eng. value [in mA] = 0.305175781 * raw + 0*/
        int16_t power; /*!<  \note conversion: eng. value [in mW] = 9.765625 * raw + 0*/
    } fields;
} isismepsv2_ivid5_pdu__vipdraw_t;

/*!
 * Union for storing the parameters for struct VIPDch.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__vipdch_t
{
    unsigned char raw[6];
    struct __attribute__ ((__packed__))
    {
        int16_t volt; /*!<  \note conversion: eng. value [in mV] = 0.9765625 * raw + 0*/
        int16_t current; /*!<  \note conversion: eng. value [in mA] = 0.1525879 * raw + 0*/
        int16_t power; /*!<  \note conversion: eng. value [in mW] = 4.8828125 * raw + 0*/
    } fields;
} isismepsv2_ivid5_pdu__vipdch_t;

/*!
 * Union for storing the parameters for struct VIPDvd.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__vipdvd_t
{
    unsigned char raw[6];
    struct __attribute__ ((__packed__))
    {
        int16_t volt; /*!<  \note conversion: eng. value [in mV] = 0.9765625 * raw + 0*/
        int16_t current; /*!<  \note conversion: eng. value [in mA] = 0.30517578 * raw + 0*/
        int16_t power; /*!<  \note conversion: eng. value [in mW] = 9.765625 * raw + 0*/
    } fields;
} isismepsv2_ivid5_pdu__vipdvd_t;

/*!
 * Union for storing the parameters for struct VIPDeng.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__vipdeng_t
{
    unsigned char raw[6];
    struct __attribute__ ((__packed__))
    {
        int16_t volt; /*!<  */
        int16_t current; /*!<  */
        int16_t power; /*!<  \note conversion: eng. value [in mW] = 10 * raw */
    } fields;
} isismepsv2_ivid5_pdu__vipdeng_t;

/*!
 * Union for storing the parameters received by getconfigurationparameter.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__getconfigurationparameter__from_t
{
    unsigned char raw[16];
    struct __attribute__ ((__packed__))
    {
        isismepsv2_ivid5_pdu__replyheader_t reply_header; /*!<  */
        uint8_t reserved; /*!<  */
        uint16_t par_id; /*!< parameter id of the parameter to get */
        uint8_t par_val[8]; /*!< parameter value encompassing n bytes. The length depends on the parameter type. */
    } fields;
} isismepsv2_ivid5_pdu__getconfigurationparameter__from_t;

/*!
 * Union for storing the parameters received by gethousekeepingdataeng.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__gethousekeepingdataeng__from_t
{
    unsigned char raw[158];
    struct __attribute__ ((__packed__))
    {
        isismepsv2_ivid5_pdu__replyheader_t reply_header; /*!< "See \""System Type Identifier (STID)\"" (page 22)" */
        uint8_t reserved; /*!< (reserved) */
        int16_t volt_brdsup; /*!< Voltage level of internal board supply */
        int16_t temp; /*!< Measured temperature provided by a sensor internal to the MCU \note conversion: eng. value [in °C] = 0.01 * raw */
        isismepsv2_ivid5_pdu__vipdeng_t vip_input; /*!< Input V, I and P data for the unit in raw form. */
        uint16_t stat_ob_on; /*!< Bitflag field indicating channel-on status for the output bus channels. */
        uint16_t stat_ob_ocf; /*!< Bitflag field indicating overcurrent latch-off fault status for the output bus channels. */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd0; /*!< Output V, I and P of voltage domain 0 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd1; /*!< Output V, I and P of voltage domain 1 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd2; /*!< Output V, I and P of voltage domain 2 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd3; /*!< Output V, I and P of voltage domain 3 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd4; /*!< Output V, I and P of voltage domain 4 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd5; /*!< Output V, I and P of voltage domain 5 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd6; /*!< Output V, I and P of voltage domain 6 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc00; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc01; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc02; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc03; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc04; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc05; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc06; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc07; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc08; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc09; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc10; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc11; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc12; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc13; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc14; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc15; /*!< Output V, I and P of output bus channel */
    } fields;
} isismepsv2_ivid5_pdu__gethousekeepingdataeng__from_t;

/*!
 * Union for storing the parameters received by gethousekeepingdataraw.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__gethousekeepingdataraw__from_t
{
    unsigned char raw[158];
    struct __attribute__ ((__packed__))
    {
        isismepsv2_ivid5_pdu__replyheader_t reply_header; /*!< "See \""System Type Identifier (STID)\"" (page 22)" */
        uint8_t reserved; /*!< (reserved) */
        uint16_t volt_brdsup; /*!< Voltage level of internal board supply in raw form. */
        uint16_t temp; /*!< Measured temperature provided by a sensor internal to the MCU in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_input; /*!< Input V, I and P data for the unit in raw form. */
        uint16_t stat_ob_on; /*!< Bitflag field indicating channel-on status for the output bus channels. */
        uint16_t stat_ob_ocf; /*!< Bitflag field indicating overcurrent latch-off fault status for the output bus channels. */
        isismepsv2_ivid5_pdu__vipdraw_t vip_vd0; /*!< Output V, I and P of voltage domain 0 in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_vd1; /*!< Output V, I and P of voltage domain 1 in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_vd2; /*!< Output V, I and P of voltage domain 2 in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_vd3; /*!< Output V, I and P of voltage domain 3 in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_vd4; /*!< Output V, I and P of voltage domain 4 in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_vd5; /*!< Output V, I and P of voltage domain 5 in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_vd6; /*!< Output V, I and P of voltage domain 6 in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc00; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc01; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc02; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc03; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc04; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc05; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc06; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc07; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc08; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc09; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc10; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc11; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc12; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc13; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc14; /*!< Output V, I and P of output bus channel in raw form */
        isismepsv2_ivid5_pdu__vipdraw_t vip_obc15; /*!< Output V, I and P of output bus channel in raw form */
    } fields;
} isismepsv2_ivid5_pdu__gethousekeepingdataraw__from_t;

/*!
 * Union for storing the parameters received by gethousekeepingdatarawwithconversion.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__gethousekeepingdatarawwithconversion__from_t
{
    unsigned char raw[158];
    struct __attribute__ ((__packed__))
    {
        isismepsv2_ivid5_pdu__replyheader_t reply_header; /*!< "See \""System Type Identifier (STID)\"" (page 22)" */
        uint8_t reserved; /*!< (reserved) */
        int16_t volt_brdsup; /*!< Voltage level of internal board supply \note conversion: eng. value [in V] = 0.001221 * raw */
        int16_t temp; /*!< Measured temperature provided by a sensor internal to the MCU \note conversion: eng. value [in °C] = 0.24444444 * raw + -285.511111*/
        isismepsv2_ivid5_pdu__vipdraw_t vip_input; /*!< Input V, I and P data for the unit in raw form. */
        uint16_t stat_ob_on; /*!< Bitflag field indicating channel-on status for the output bus channels. */
        uint16_t stat_ob_ocf; /*!< Bitflag field indicating overcurrent latch-off fault status for the output bus channels. */
        isismepsv2_ivid5_pdu__vipdvd_t vip_vd0; /*!< Output V, I and P of voltage domain 0 */
        isismepsv2_ivid5_pdu__vipdvd_t vip_vd1; /*!< Output V, I and P of voltage domain 1 */
        isismepsv2_ivid5_pdu__vipdvd_t vip_vd2; /*!< Output V, I and P of voltage domain 2 */
        isismepsv2_ivid5_pdu__vipdvd_t vip_vd3; /*!< Output V, I and P of voltage domain 3 */
        isismepsv2_ivid5_pdu__vipdvd_t vip_vd4; /*!< Output V, I and P of voltage domain 4 */
        isismepsv2_ivid5_pdu__vipdvd_t vip_vd5; /*!< Output V, I and P of voltage domain 5 */
        isismepsv2_ivid5_pdu__vipdvd_t vip_vd6; /*!< Output V, I and P of voltage domain 6 */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc00; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc01; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc02; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc03; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc04; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc05; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc06; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc07; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc08; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc09; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc10; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc11; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc12; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc13; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc14; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdch_t vip_obc15; /*!< Output V, I and P of output bus channel */
    } fields;
} isismepsv2_ivid5_pdu__gethousekeepingdatarawwithconversion__from_t;

/*!
 * Union for storing the parameters received by gethousekeepingdatarunningavg.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__gethousekeepingdatarunningavg__from_t
{
    unsigned char raw[158];
    struct __attribute__ ((__packed__))
    {
        isismepsv2_ivid5_pdu__replyheader_t reply_header; /*!< "See \""System Type Identifier (STID)\"" (page 22)" */
        uint8_t reserved; /*!< (reserved) */
        int16_t volt_brdsup; /*!< Voltage level of internal board supply */
        int16_t temp; /*!< Measured temperature provided by a sensor internal to the MCU \note conversion: eng. value [in °C] = 0.01 * raw */
        isismepsv2_ivid5_pdu__vipdeng_t vip_input; /*!< Input V, I and P data for the unit in raw form. */
        uint16_t stat_ob_on; /*!< Bitflag field indicating channel-on status for the output bus channels. */
        uint16_t stat_ob_ocf; /*!< Bitflag field indicating overcurrent latch-off fault status for the output bus channels. */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd0; /*!< Output V, I and P of voltage domain 0 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd1; /*!< Output V, I and P of voltage domain 1 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd2; /*!< Output V, I and P of voltage domain 2 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd3; /*!< Output V, I and P of voltage domain 3 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd4; /*!< Output V, I and P of voltage domain 4 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd5; /*!< Output V, I and P of voltage domain 5 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_vd6; /*!< Output V, I and P of voltage domain 6 */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc00; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc01; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc02; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc03; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc04; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc05; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc06; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc07; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc08; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc09; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc10; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc11; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc12; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc13; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc14; /*!< Output V, I and P of output bus channel */
        isismepsv2_ivid5_pdu__vipdeng_t vip_obc15; /*!< Output V, I and P of output bus channel */
    } fields;
} isismepsv2_ivid5_pdu__gethousekeepingdatarunningavg__from_t;

/*!
 * Union for storing the parameters received by getovercurrentfaultstate.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__getovercurrentfaultstate__from_t
{
    unsigned char raw[42];
    struct __attribute__ ((__packed__))
    {
        isismepsv2_ivid5_pdu__replyheader_t reply_header; /*!<  */
        uint8_t reserved; /*!<  */
        uint16_t stat_ob_on; /*!<  */
        uint16_t stat_ob_ocf; /*!<  */
        uint16_t ocf_cnt_obc00; /*!<  */
        uint16_t ocf_cnt_obc01; /*!<  */
        uint16_t ocf_cnt_obc02; /*!<  */
        uint16_t ocf_cnt_obc03; /*!<  */
        uint16_t ocf_cnt_obc04; /*!<  */
        uint16_t ocf_cnt_obc05; /*!<  */
        uint16_t ocf_cnt_obc06; /*!<  */
        uint16_t ocf_cnt_obc07; /*!<  */
        uint16_t ocf_cnt_obc08; /*!<  */
        uint16_t ocf_cnt_obc09; /*!<  */
        uint16_t ocf_cnt_obc10; /*!<  */
        uint16_t ocf_cnt_obc11; /*!<  */
        uint16_t ocf_cnt_obc12; /*!<  */
        uint16_t ocf_cnt_obc13; /*!<  */
        uint16_t ocf_cnt_obc14; /*!<  */
        uint16_t ocf_cnt_obc15; /*!<  */
    } fields;
} isismepsv2_ivid5_pdu__getovercurrentfaultstate__from_t;

/*!
 * Union for storing the parameters received by getsystemstatus.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__getsystemstatus__from_t
{
    unsigned char raw[26];
    struct __attribute__ ((__packed__))
    {
        isismepsv2_ivid5_pdu__replyheader_t reply_header; /*!<  */
        uint8_t mode; /*!< Indicates the current mode of the system. */
        uint8_t conf; /*!< Read/write configuration parameters have been changed by the EPS master since the last parameters load/save operation */
        uint8_t reset_cause; /*!< Cause of last reset. */
        uint32_t uptime; /*!<  */
        uint16_t error; /*!<  */
        uint16_t rc_cnt_pwron; /*!<  */
        uint16_t rc_cnt_wdg; /*!<  */
        uint16_t rc_cnt_cmd; /*!<  */
        uint16_t rc_cnt_pweron_mcu; /*!<  */
        uint16_t rc_cnt_emlopo; /*!<  */
        uint16_t prevcmd_elapsed; /*!<  */
    } fields;
} isismepsv2_ivid5_pdu__getsystemstatus__from_t;

/*!
 * Union for storing the parameters received by resetconfigurationparameter.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__resetconfigurationparameter__from_t
{
    unsigned char raw[16];
    struct __attribute__ ((__packed__))
    {
        isismepsv2_ivid5_pdu__replyheader_t reply_header; /*!<  */
        uint8_t reserved; /*!<  */
        uint16_t par_id; /*!< parameter id of the parameter to get */
        uint8_t par_val[8]; /*!< parameter value encompassing n bytes. The length depends on the parameter type. */
    } fields;
} isismepsv2_ivid5_pdu__resetconfigurationparameter__from_t;

/*!
 * Union for storing the parameters sent by setconfigurationparameter.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__setconfigurationparameter__to_t
{
    unsigned char raw[10];
    struct __attribute__ ((__packed__))
    {
        uint16_t par_id; /*!< parameter id of the parameter to get */
        uint8_t par_val[8]; /*!< new parameter value encompassing n bytes. The length depends on the parameter type. */
    } fields;
} isismepsv2_ivid5_pdu__setconfigurationparameter__to_t;

/*!
 * Union for storing the parameters received by setconfigurationparameter.
 */
typedef union __attribute__((__packed__)) _isismepsv2_ivid5_pdu__setconfigurationparameter__from_t
{
    unsigned char raw[16];
    struct __attribute__ ((__packed__))
    {
        isismepsv2_ivid5_pdu__replyheader_t reply_header; /*!<  */
        uint8_t reserved; /*!<  */
        uint16_t par_id; /*!< parameter id of the parameter to get */
        uint8_t par_val[8]; /*!< parameter value encompassing n bytes. The length depends on the parameter type. */
    } fields;
} isismepsv2_ivid5_pdu__setconfigurationparameter__from_t;

#ifdef __cplusplus
}
#endif

#endif /* ISISMEPSV2_IVID5_PDU_TYPES_H_ */

