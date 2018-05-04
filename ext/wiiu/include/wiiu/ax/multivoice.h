#pragma once
#include <wiiu/types.h>
#include "voice.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	bool running;
	uint32_t channels;
	AXVoice *v[];
} AXMVoice;
typedef struct
{
	u16 unknown0_[0x25];
	u16 count;
	u16 unknown1_[0xA];
} AXMVoiceParams;
static_assert(sizeof(AXMVoiceParams) == sizeof(u16) * 0x30, "");

void AXAcquireMultiVoice(u32 prio, void *cb, u32 cbarg, void *setup, AXMVoice **mvoice);
void AXSetMultiVoiceDeviceMix(AXMVoice *mvoice, AXDeviceType type, u32 id, u32 bus, u16 vol, s16 delta);
void AXSetMultiVoiceOffsets(AXMVoice *mvoice, AXVoiceOffsets *offsets);
void AXSetMultiVoiceCurrentOffset(AXMVoice *mvoice, uint32_t offset);
void AXSetMultiVoiceState(AXMVoice *mvoice, AXVoiceState state);
void AXSetMultiVoiceVe(AXMVoice *mvoice, AXVoiceVeData *veData);
void AXSetMultiVoiceSrcType(AXMVoice *mvoice, AXVoiceSrcType type);
void AXSetMultiVoiceSrcRatio(AXMVoice *mvoice, float ratio);
bool AXIsMultiVoiceRunning(AXMVoice *mvoice);
void AXFreeMultiVoice(AXMVoice *mvoice);

#ifdef __cplusplus
}
#endif
