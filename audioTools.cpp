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
#include "audioTools.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

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
		if(!strcmp(argv[1], "showinfo") || !strcmp(argv[1], "-si")){
			if(!strcmp(argv[2], "mode")){
				for(int i=0;i<(int)(sizeof(mode)/sizeof(mode[0]));i++){
					printf("%s%s",mode[i],"\n");
				}
			}
			if(!strcmp(argv[2], "stream")){
				for(int i=0;i<(int)(sizeof(stream)/sizeof(stream[0]));i++){
					printf("%s%s",stream[i],"\n");
				}
			}
			if(!strcmp(argv[2], "device")){
				for(int i=0;i<(int)(sizeof(device)/sizeof(device[0]));i++){
					printf("%s%s",device[i],"\n");
				}
			}
			if(!strcmp(argv[2], "forceuse")){
				for(int i=0;i<(int)(sizeof(forceuse)/sizeof(forceuse[0]));i++){
					printf("%s%s",forceuse[i],"\n");
				}
			}
			if(!strcmp(argv[2], "forcecfg")){
				for(int i=0;i<(int)(sizeof(forcecfg)/sizeof(forcecfg[0]));i++){
					printf("%s%s",forcecfg[i],"\n");
				}
			}
			break;
		}
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

