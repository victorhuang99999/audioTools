#include <stdint.h>
#include <sys/types.h>
#include <math.h>
#include <fcntl.h>
#include <utils/misc.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <sys/select.h>
#include <stdio.h>

#include <media/AudioSystem.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

/*typedef enum {
    AUDIO_STREAM_DEFAULT = -1, // (-1)
    AUDIO_STREAM_MIN = 0,
    AUDIO_STREAM_VOICE_CALL = 0,
    AUDIO_STREAM_SYSTEM = 1,
    AUDIO_STREAM_RING = 2,
    AUDIO_STREAM_MUSIC = 3,
    AUDIO_STREAM_ALARM = 4,
    AUDIO_STREAM_NOTIFICATION = 5,
    AUDIO_STREAM_BLUETOOTH_SCO = 6,
    AUDIO_STREAM_ENFORCED_AUDIBLE = 7,
    AUDIO_STREAM_DTMF = 8,
    AUDIO_STREAM_TTS = 9,
    AUDIO_STREAM_ACCESSIBILITY = 10,
    AUDIO_STREAM_REROUTING = 11,
    AUDIO_STREAM_PATCH = 12,
    AUDIO_STREAM_PUBLIC_CNT = 11, // (ACCESSIBILITY + 1)
    AUDIO_STREAM_FOR_POLICY_CNT = 12, // PATCH
    AUDIO_STREAM_CNT = 13, // (PATCH + 1)
} audio_stream_type_t;*/

/*typedef enum {
    AUDIO_MODE_INVALID = -2, // (-2)
    AUDIO_MODE_CURRENT = -1, // (-1)
    AUDIO_MODE_NORMAL = 0,
    AUDIO_MODE_RINGTONE = 1,
    AUDIO_MODE_IN_CALL = 2,
    AUDIO_MODE_IN_COMMUNICATION = 3,
    AUDIO_MODE_CNT = 4,
    AUDIO_MODE_MAX = 3, // (CNT - 1)
} audio_mode_t;*/

/*enum {
    AUDIO_DEVICE_NONE = 0u, // 0x0
    AUDIO_DEVICE_BIT_IN = 2147483648u, // 0x80000000
    AUDIO_DEVICE_BIT_DEFAULT = 1073741824u, // 0x40000000
    AUDIO_DEVICE_OUT_EARPIECE = 1u, // 0x1
    AUDIO_DEVICE_OUT_SPEAKER = 2u, // 0x2
    AUDIO_DEVICE_OUT_WIRED_HEADSET = 4u, // 0x4
    AUDIO_DEVICE_OUT_WIRED_HEADPHONE = 8u, // 0x8
    AUDIO_DEVICE_OUT_BLUETOOTH_SCO = 16u, // 0x10
    AUDIO_DEVICE_OUT_BLUETOOTH_SCO_HEADSET = 32u, // 0x20
    AUDIO_DEVICE_OUT_BLUETOOTH_SCO_CARKIT = 64u, // 0x40
    AUDIO_DEVICE_OUT_BLUETOOTH_A2DP = 128u, // 0x80
    AUDIO_DEVICE_OUT_BLUETOOTH_A2DP_HEADPHONES = 256u, // 0x100
    AUDIO_DEVICE_OUT_BLUETOOTH_A2DP_SPEAKER = 512u, // 0x200
    AUDIO_DEVICE_OUT_AUX_DIGITAL = 1024u, // 0x400
    AUDIO_DEVICE_OUT_HDMI = 1024u, // OUT_AUX_DIGITAL
    AUDIO_DEVICE_OUT_ANLG_DOCK_HEADSET = 2048u, // 0x800
    AUDIO_DEVICE_OUT_DGTL_DOCK_HEADSET = 4096u, // 0x1000
    AUDIO_DEVICE_OUT_USB_ACCESSORY = 8192u, // 0x2000
    AUDIO_DEVICE_OUT_USB_DEVICE = 16384u, // 0x4000
    AUDIO_DEVICE_OUT_REMOTE_SUBMIX = 32768u, // 0x8000
    AUDIO_DEVICE_OUT_TELEPHONY_TX = 65536u, // 0x10000
    AUDIO_DEVICE_OUT_LINE = 131072u, // 0x20000
    AUDIO_DEVICE_OUT_HDMI_ARC = 262144u, // 0x40000
    AUDIO_DEVICE_OUT_SPDIF = 524288u, // 0x80000
    AUDIO_DEVICE_OUT_FM = 1048576u, // 0x100000
    AUDIO_DEVICE_OUT_AUX_LINE = 2097152u, // 0x200000
    AUDIO_DEVICE_OUT_SPEAKER_SAFE = 4194304u, // 0x400000
    AUDIO_DEVICE_OUT_IP = 8388608u, // 0x800000
    AUDIO_DEVICE_OUT_BUS = 16777216u, // 0x1000000
    AUDIO_DEVICE_OUT_PROXY = 33554432u, // 0x2000000
    AUDIO_DEVICE_OUT_USB_HEADSET = 67108864u, // 0x4000000
    AUDIO_DEVICE_OUT_DEFAULT = 1073741824u, // BIT_DEFAULT
    AUDIO_DEVICE_OUT_ALL = 1207959551u, // (((((((((((((((((((((((((((OUT_EARPIECE | OUT_SPEAKER) | OUT_WIRED_HEADSET) | OUT_WIRED_HEADPHONE) | OUT_BLUETOOTH_SCO) | OUT_BLUETOOTH_SCO_HEADSET) | OUT_BLUETOOTH_SCO_CARKIT) | OUT_BLUETOOTH_A2DP) | OUT_BLUETOOTH_A2DP_HEADPHONES) | OUT_BLUETOOTH_A2DP_SPEAKER) | OUT_HDMI) | OUT_ANLG_DOCK_HEADSET) | OUT_DGTL_DOCK_HEADSET) | OUT_USB_ACCESSORY) | OUT_USB_DEVICE) | OUT_REMOTE_SUBMIX) | OUT_TELEPHONY_TX) | OUT_LINE) | OUT_HDMI_ARC) | OUT_SPDIF) | OUT_FM) | OUT_AUX_LINE) | OUT_SPEAKER_SAFE) | OUT_IP) | OUT_BUS) | OUT_PROXY) | OUT_USB_HEADSET) | OUT_DEFAULT)
    AUDIO_DEVICE_OUT_ALL_A2DP = 896u, // ((OUT_BLUETOOTH_A2DP | OUT_BLUETOOTH_A2DP_HEADPHONES) | OUT_BLUETOOTH_A2DP_SPEAKER)
    AUDIO_DEVICE_OUT_ALL_SCO = 112u, // ((OUT_BLUETOOTH_SCO | OUT_BLUETOOTH_SCO_HEADSET) | OUT_BLUETOOTH_SCO_CARKIT)
    AUDIO_DEVICE_OUT_ALL_USB = 67133440u, // ((OUT_USB_ACCESSORY | OUT_USB_DEVICE) | OUT_USB_HEADSET)
    AUDIO_DEVICE_IN_COMMUNICATION = 2147483649u, // (BIT_IN | 0x1)
    AUDIO_DEVICE_IN_AMBIENT = 2147483650u, // (BIT_IN | 0x2)
    AUDIO_DEVICE_IN_BUILTIN_MIC = 2147483652u, // (BIT_IN | 0x4)
    AUDIO_DEVICE_IN_BLUETOOTH_SCO_HEADSET = 2147483656u, // (BIT_IN | 0x8)
    AUDIO_DEVICE_IN_WIRED_HEADSET = 2147483664u, // (BIT_IN | 0x10)
    AUDIO_DEVICE_IN_AUX_DIGITAL = 2147483680u, // (BIT_IN | 0x20)
    AUDIO_DEVICE_IN_HDMI = 2147483680u, // IN_AUX_DIGITAL
    AUDIO_DEVICE_IN_VOICE_CALL = 2147483712u, // (BIT_IN | 0x40)
    AUDIO_DEVICE_IN_TELEPHONY_RX = 2147483712u, // IN_VOICE_CALL
    AUDIO_DEVICE_IN_BACK_MIC = 2147483776u, // (BIT_IN | 0x80)
    AUDIO_DEVICE_IN_REMOTE_SUBMIX = 2147483904u, // (BIT_IN | 0x100)
    AUDIO_DEVICE_IN_ANLG_DOCK_HEADSET = 2147484160u, // (BIT_IN | 0x200)
    AUDIO_DEVICE_IN_DGTL_DOCK_HEADSET = 2147484672u, // (BIT_IN | 0x400)
    AUDIO_DEVICE_IN_USB_ACCESSORY = 2147485696u, // (BIT_IN | 0x800)
    AUDIO_DEVICE_IN_USB_DEVICE = 2147487744u, // (BIT_IN | 0x1000)
    AUDIO_DEVICE_IN_FM_TUNER = 2147491840u, // (BIT_IN | 0x2000)
    AUDIO_DEVICE_IN_TV_TUNER = 2147500032u, // (BIT_IN | 0x4000)
    AUDIO_DEVICE_IN_LINE = 2147516416u, // (BIT_IN | 0x8000)
    AUDIO_DEVICE_IN_SPDIF = 2147549184u, // (BIT_IN | 0x10000)
    AUDIO_DEVICE_IN_BLUETOOTH_A2DP = 2147614720u, // (BIT_IN | 0x20000)
    AUDIO_DEVICE_IN_LOOPBACK = 2147745792u, // (BIT_IN | 0x40000)
    AUDIO_DEVICE_IN_IP = 2148007936u, // (BIT_IN | 0x80000)
    AUDIO_DEVICE_IN_BUS = 2148532224u, // (BIT_IN | 0x100000)
    AUDIO_DEVICE_IN_PROXY = 2164260864u, // (BIT_IN | 0x1000000)
    AUDIO_DEVICE_IN_USB_HEADSET = 2181038080u, // (BIT_IN | 0x2000000)
    AUDIO_DEVICE_IN_DEFAULT = 3221225472u, // (BIT_IN | BIT_DEFAULT)
    AUDIO_DEVICE_IN_ALL = 3273654271u, // (((((((((((((((((((((((IN_COMMUNICATION | IN_AMBIENT) | IN_BUILTIN_MIC) | IN_BLUETOOTH_SCO_HEADSET) | IN_WIRED_HEADSET) | IN_HDMI) | IN_TELEPHONY_RX) | IN_BACK_MIC) | IN_REMOTE_SUBMIX) | IN_ANLG_DOCK_HEADSET) | IN_DGTL_DOCK_HEADSET) | IN_USB_ACCESSORY) | IN_USB_DEVICE) | IN_FM_TUNER) | IN_TV_TUNER) | IN_LINE) | IN_SPDIF) | IN_BLUETOOTH_A2DP) | IN_LOOPBACK) | IN_IP) | IN_BUS) | IN_PROXY) | IN_USB_HEADSET) | IN_DEFAULT)
    AUDIO_DEVICE_IN_ALL_SCO = 2147483656u, // IN_BLUETOOTH_SCO_HEADSET
    AUDIO_DEVICE_IN_ALL_USB = 2181044224u, // ((IN_USB_ACCESSORY | IN_USB_DEVICE) | IN_USB_HEADSET)
};*/

#define VERSION "0.1"

const char * const func[] = {
	"setpara",
	"getpara",
	"setforceuse",
	"getforceuse",
	"setstreamvolume",
	"getstreamvolume",
	"setstreammute",
	"getstreammute",
	"setmode",
	"mutemic",
	"ismicmuted",
};

const char * const parameter[] = {
	" [parameter] [value] ",
	" [parameter] ",
	" [usage] [config] ",
	" [usgae] ",
	" [stream][index][devices] ",
	" [stream][devices] ",
	" [stream][mute] ",
	" [stream] ",
	" [mode] ",
	" [mute] ",
	" null ",
};

const char * const abbreviation[] = {
	"-sp",
	"-gp",
	"-sfu",
	"-gfu",
	"-ssv",
	"-gsv",
	"-ssm",
	"-gsm",
	"-sm",
	"-mm",
	"-imm",
};

void printAudioToolsInfo(){
	printf("Usage: \n");
	for(int i=0;i<(int)(sizeof(func)/sizeof(func[0]));i++){
		printf("%s%s%s%s",func[i],parameter[i],abbreviation[i],"\n");
	}
}

using namespace android;

int main(int argc, char *argv[])
{
	switch(argc){
	case 1:
		printAudioToolsInfo();
		break;
	case 2:
		if(!strcmp(argv[1], "version") || !strcmp(argv[1], "-v")){
			printf("%s\n",VERSION);
			break;
		}		
		if(!strcmp(argv[1], "ismicmuted") || !strcmp(argv[1], "-imm")){
			bool mute = false;
			AudioSystem::isMicrophoneMuted(&mute);
			printf("%d\n",mute?1:0);
			break;
		}
		for(int i=0;i<(int)(sizeof(func)/sizeof(func[0]));i++){
			if(!strcmp(argv[1], func[i]) || !strcmp(argv[1], abbreviation[i]) ){
				printf("%s%s%s",func[i],parameter[i],"\n");
				break;
			}
		}		
		break;
	case 3:
		if(!strcmp(argv[1], "getpara") || !strcmp(argv[1], "-gp")){
			printf("%s\n",AudioSystem::getParameters(String8(argv[2])).c_str());
			break;
		}
		if(!strcmp(argv[1], "getforceuse") || !strcmp(argv[1], "-gfu")){
			printf("%d\n",AudioSystem::getForceUse((audio_policy_force_use_t)atoi(argv[2])));
			break;
		}
		if(!strcmp(argv[1], "getstreammute") || !strcmp(argv[1], "-gsm")){
			bool mute = false;
			AudioSystem::getStreamMute((audio_stream_type_t)atoi(argv[2]),&mute);
			printf("%d\n",mute?1:0);
			break;
		}
		if(!strcmp(argv[1], "setmode") || !strcmp(argv[1], "-sm")){
			AudioSystem::setMode((audio_mode_t)atoi(argv[2]));
			break;
		}
		if(!strcmp(argv[1], "mutemic") || !strcmp(argv[1], "-mm")){
			AudioSystem::muteMicrophone((atoi(argv[2])==1)?true:false);
			break;
		}		
		break;
	case 4:
		if(!strcmp(argv[1], "setpara") || !strcmp(argv[1], "-sp")){
			char *buf = new char[100];
			sprintf(buf,"%s=%s",argv[2],argv[3]);
			AudioSystem::setParameters(String8(buf));
			break;
		}
		if(!strcmp(argv[1], "setforceuse") || !strcmp(argv[1], "-sfu")){
			AudioSystem::setForceUse((audio_policy_force_use_t)atoi(argv[2]),(audio_policy_forced_cfg_t)atoi(argv[3]));
			break;
		}
		if(!strcmp(argv[1], "getstreamvolume") || !strcmp(argv[1], "-gsv")){
			int index=0;
			AudioSystem::getStreamVolumeIndex((audio_stream_type_t)atoi(argv[2]),&index,(audio_devices_t)atoi(argv[3]));
			printf("%d\n",index);
			break;
		}
		if(!strcmp(argv[1], "setstreammute") || !strcmp(argv[1], "-ssm")){
			AudioSystem::setStreamMute((audio_stream_type_t)atoi(argv[2]),(atoi(argv[3]) == 1)?true:false);
			break;
		}	
		break;
	case 5:
		if(!strcmp(argv[1], "setstreamvolume") || !strcmp(argv[1], "-ssv")){
			AudioSystem::setStreamVolumeIndex((audio_stream_type_t)atoi(argv[2]),atoi(argv[3]),(audio_devices_t)atoi(argv[4]));
			break;
		}	
		break;
	}
	return 0;
}

