#include <common.h>

struct unknown233
{
	void* unknown1;
	int unknown2;
	int unknown3;
};

extern struct
{
	char fill_beginning[4];

	char s_spawn[8];
	char s_g_dancer[16];

	char fill_strings[0x290];

	// CS_Podium_FullScene_Init
	char s_podium[8];
	// 0x800abca4
	char s_third[8];
	char s_second[8];
	char s_first[8];
	char s_tawna[8];
	char s_prize[8];
	char s_victorycam[16];

	char fill_strings2[0x3c];

	// CS_LevThread_OnInit
	char s_introguy[12];
	char s_introcam[12];

	// Naughty Dog crate intro thread strings
	char s_box1[8];
	char s_box2[8];
	char s_box2_bottom[16];
	char s_box2_front[16];
	char s_box2_A[8];
	char s_box3[8];
	char s_code[8];
	char s_glow[8];
	char s_lid[4];
	char s_lidb[8];
	char s_lidc[8];
	char s_lidd[8];
	char s_lid2[8];
	char s_kart0[8];
	char s_kart1[8];
	char s_kart2[8];
	char s_kart3[8];
	char s_kart6[8];
	char s_kart7[8];

	// only functions and labels in this gap
	char fill1[0x4DA8];

	// 800b0b7c
	u_short VertSplitLine;
	u_short VertSplit_unknown;
	
	int unknown1;
	int unknown2;
	int unknown3;

	// 800b0b8c
	int CutsceneManipulatesAudio;
	
	// 800b0b90
	// 120 bytes
	struct unknown233 whateverThisMeans[10];

	char fill2[0x864];

	// 800b146c
	struct unknown233* pointerToWhateverThisMeans[10];

	char fill3[0x62CC];

	// 800b7760
	int isCutsceneOver;
	// 800b7764
	int PodiumInitUnk2;
	// 800b7768
	short FXVolumeBackup;
	// 800b776a
	short MusicVolumeBackup;
	// 800b776c
	short VoiceVolumeBackup;

	short volumeunknown;

	// 800b7770
	int PodiumInitUnk3;
	// 800b7774
	int cutsceneState;
} OVR_233;