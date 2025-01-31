#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/task.h>

#include <hal/Timing/Time.h>
#include <hal/errors.h>

#include <satellite-subsystems/isis_vu_e.h>
#include <satellite-subsystems/isis_ants.h>
#include <satellite-subsystems/isis_ants_types.h>
#include <satellite-subsystems/isismepsv2_ivid7_piu.h>
#include <satellite-subsystems/isismepsv2_ivid7_piu_types.h>


#include <stdlib.h>
#include <string.h>

#include "GlobalStandards.h"
#include "TRXVU.h"
#include "AckHandler.h"
#include "SubsystemCommands/TRXVU_Commands.h"
#include "SatCommandHandler.h"
#include "TLM_management.h"

#include "SubSystemModules/PowerManagment/EPS.h"
#include "SubSystemModules/Maintenance/Maintenance.h"
#include "SubSystemModules/Housekepping/TelemetryCollector.h"
#ifdef TESTING_TRXVU_FRAME_LENGTH
#include <hal/Utility/util.h>
#endif

#include "HashSecuredCMD.h"

int SetRSSITransponder(short rssiValue)
{
	// put set rssi + rssi in fram together?
}
Boolean CheckTransmitionAllowed();
{
	Boolean  low_voltage_flag = TRUE;
	low_voltage_flag = EpsGetLowVoltageFlag();
	if(low_voltage_flag){return FALSE;}
	//add if tx mute flag is up to return FALSE
	return TRUE;
}
// make dump better (-res?)

/*!
 * @brief	mutes the TRXVU for a specified time frame
 * @param[in] duration for how long will the satellite be in mute state
 * @return	0 in successful
 * 			-1 in failure
 */
int muteTRXVU(time_unix duration);
{
	//from what i understand a flag is put up in the fram to signal the sat will not answer, why????
}

/*!
 * @brief Cancels TRXVU mute - transmission is now enabled
 */
void UnMuteTRXVU();
//unmute can be added to muteTRXVU or can use the func and give a param (0)

void InitTxModule();

//what the diff  InitTxModule() VS InitTrxvu() and can they be combined?

/*!
 * @brief initializes the TRXVU subsystem
 * @return	0 on successful init
 * 			errors according to <hal/errors.h>
 */
int InitTrxvu();

void checkTransponderFinish();

int CMD_SetBeaconInterval(sat_packet_t *cmd);
{
	//memcpy data to var add var to fram
}

/*!
 * @brief The TRXVU logic according to the sub-system flowchart
 * @return	command_succsess on success
 * 			errors according to CMD_ERR enumeration
 * @see "SatCommandHandler.h"
 */
int TRX_Logic();

/**
 * add float chart
 * COMBINE???
 * turn on the transponder
 */
int turnOnTransponder();
/**
 * turn off the transponder
 */
int turnOffTransponder();

Boolean CheckDumpAbort();

/*!
learn
 * @brief 	Transmits a packet according to the SPL protocol
 * @param[in] packet packet to be transmitted
 * @param[out] avalFrames Number of the available slots in the transmission buffer of the VU_TC after the frame has been added. Set NULL to skip available slot count read-back.
 * @return    Error code according to <hal/errors.h>
 */
int TransmitSplPacket(sat_packet_t *packet, int *avalFrames);

/*!
 * @brief sends an abort message via a freeRTOS queue.
 */
void SendDumpAbortRequest();

/*!
 * @brief Closes a dump task if one is executing, using vTaskDelete.
 * @note Can be used to forcibly abort the task
 */
void AbortDump(sat_packet_t *cmd);

void FinishDump(sat_packet_t *cmd,unsigned char *buffer, ack_subtype_t acktype,
		unsigned char *err, unsigned int size) ;

/*!
 * @brief transmits beacon according to beacon logic
 */
int BeaconLogic(Boolean forceTX);

/*
 * @brief set the idle state of the trxvu
 * @param[in] state ON/OFF
 * @param[in] duration for how long will the satellite be in idle state, if state is OFF than this value is ignored
 * @return	0 in successful
 * 			-1 in failure
 */
int SetIdleState(isis_vu_e__onoff_t state, time_unix duration);

/*!
 * @brief checks if the Trxvu mute time has terminated
 * @return	TRUE if the termination time has arrived
 * 			FALSE else
 */
Boolean CheckForMuteEnd();
//checks mute, transponder, idle 
/*!
 * @brief returns number of online frames are in the TRX frame buffer
 * @return	#number number of packets available
 * 			-1 in case of failure
 */
int GetNumberOfFramesInBuffer();

/*!
 * @brief returns an online(immediate) command to be executed if there is one in the command buffer
 * @param[out] cmd pointer to parsed command from online TRXVU frame buffer
 * @note cmd is set
 * @return	errors according to CMD_ERR
 */
int GetOnlineCommand(sat_packet_t *cmd);


/*!
 * @brief transmits data as SPL packet
 * @param[in] cmd the given command.
 * @param[in] data the outout data.
 * @param[in] length number of bytes in 'data' fields.
 * @return errors according to <hal/errors.h>
 */
int TransmitDataAsSPL_Packet(sat_packet_t *cmd, unsigned char *data, unsigned short length);

/*
 * @brief update TX config to its needed values
 * return error
 */
int ChangeTrxvuConfigValues();








///------------------------------------------///
void Hash256(char* text, BYTE* outputHash)
{
    BYTE buf[SHA256_BLOCK_SIZE];
    SHA256_CTX ctx;

    // Initialize SHA256 context
    sha256_init(&ctx);

    // Hash the user input (text)
    sha256_update(&ctx, (BYTE*)text, strlen(text));
    sha256_final(&ctx, buf);

    // Copy the hash into the provided output buffer
    memcpy(outputHash, buf, SHA256_BLOCK_SIZE);
}
char error_hash[8] = {0};
int CMD_Hash256(sat_packet_t *cmd)
{
	unsigned int lastid, currId, code;
    char plsHashMe[50];
    char code_to_str[50];
    char cmpHash[Max_Hash_size], temp[Max_Hash_size];
	
    currId = cmd->ID;

	if (cmd == NULL || cmd->data == NULL) {
		return E_INPUT_POINTER_NULL;
	}

    //get code from FRAM
    FRAM_read((unsigned char*)&code, CMD_PASSWORD_ADDR, CMD_PASSWORD_SIZE);

    //get the last id from FRAM and save it into var lastid then add new id to the FRAM (as new lastid)
    FRAM_read((unsigned char*)&lastid, CMD_ID_ADDR, CMD_ID_SIZE);
    FRAM_write((unsigned char*)&currId, CMD_ID_ADDR, CMD_ID_SIZE);

    //check if curr ID is bigger than lastid
    if(currId <= lastid)
    {
        return E_UNAUTHORIZED;//bc bool FALSE needed?
    }

    //combine lastid(as str) into plshashme
    sprintf(plsHashMe, "%u", currId);

    // turn code into str
    sprintf(code_to_str, "%u", code);

    //add (passcode)
    strcat(plsHashMe, code_to_str);

    // Initialize buffer for hashed output
    BYTE hashed[SHA256_BLOCK_SIZE];

    // Hash the combined string
    Hash256(plsHashMe, hashed);

    //cpy byte by byte to temp (size of otherhashed = 8 bytes *2 (all bytes are saved by twos(bc its in hex))+1 for null)
    char otherhashed[Max_Hash_size * 2 + 1]; // Array to store 8 bytes in hex, plus a null terminator

    /*for (int i = 0; i < Max_Hash_size; i++) {
        sprintf(&otherhashed[i * 2], "%02x", hashed[i]);
    }
    otherhashed[16] = '\0'; // Add Null*/

    //cpy first 8 bytes to temp 
    memcpy(temp, hashed, Max_Hash_size);

	//add temp to globle var 
	memcpy(error_hash, temp, Max_Hash_size);
    //cpy first 8 bytes of the data
    memcpy(cmpHash, cmd -> data, Max_Hash_size);

	if(cmd -> length < Max_Hash_size)
		return E_MEM_ALLOC;

	//fix cmd.data
	cmd -> length = cmd -> length - Max_Hash_size;//8 bytes are removed from the data this must be reflected in the length
	//note: the memove is crucial to the command though can be changed to memcpy this is so the command that comes after can use the cmd. data correctly (taken out bc of error) 
	//memmove(cmd->data, cmd->data + Max_Hash_size,cmd->length - Max_Hash_size);
	
    //cmp hash from command centre to internal hash
    if(memcmp(temp, cmpHash, Max_Hash_size) == 0)
    {   
        printf("success!\n");//for test
		SendAckPacket(ACK_COMD_EXEC,cmd,NULL,0);
        return E_NO_SS_ERR;
    }
    else
	{
		return E_UNAUTHORIZED;
	}
}
