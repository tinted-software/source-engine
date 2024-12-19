/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    ksmedia.h

Abstract:

    WDM-CSA Multimedia Definitions.

--*/

#if !defined(_KS_)
#error KS.H must be included before KSMEDIA.H
#endif // !defined(_KS_)

#if !defined(_KSMEDIA_)
#define _KSMEDIA_

typedef struct {
  KSPROPERTY Property;
  KSMULTIPLE_ITEM MultipleItem;
} KSMULTIPLE_DATA_PROP, *PKSMULTIPLE_DATA_PROP;

#define STATIC_KSMEDIUMSETID_MidiBus                                           \
  0x05908040L, 0x3246, 0x11D0, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("05908040-3246-11D0-A5D6-28DB04C10000",
                  KSMEDIUMSETID_MidiBus);
#define KSMEDIUMSETID_MidiBus DEFINE_GUIDNAMED(KSMEDIUMSETID_MidiBus)

#define STATIC_KSMEDIUMSETID_VPBus                                             \
  0xA18C15ECL, 0xCE43, 0x11D0, 0xAB, 0xE7, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("A18C15EC-CE43-11D0-ABE7-00A0C9223196", KSMEDIUMSETID_VPBus);
#define KSMEDIUMSETID_VPBus DEFINE_GUIDNAMED(KSMEDIUMSETID_VPBus)

#define STATIC_KSINTERFACESETID_Media                                          \
  0x3A13EB40L, 0x30A7, 0x11D0, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("3A13EB40-30A7-11D0-A5D6-28DB04C10000",
                  KSINTERFACESETID_Media);
#define KSINTERFACESETID_Media DEFINE_GUIDNAMED(KSINTERFACESETID_Media)

typedef enum {
  KSINTERFACE_MEDIA_MUSIC,
  KSINTERFACE_MEDIA_WAVE_BUFFERED,
  KSINTERFACE_MEDIA_WAVE_QUEUED
} KSINTERFACE_MEDIA;

#if !defined(INIT_USBAUDIO_MID)
// {4e1cecd2-1679-463b-a72f-a5bf64c86eba}
#define INIT_USBAUDIO_MID(guid, id)                                            \
  {                                                                            \
    (guid)->Data1 = 0x4e1cecd2 + (USHORT)(id);                                 \
    (guid)->Data2 = 0x1679;                                                    \
    (guid)->Data3 = 0x463b;                                                    \
    (guid)->Data4[0] = 0xa7;                                                   \
    (guid)->Data4[1] = 0x2f;                                                   \
    (guid)->Data4[2] = 0xa5;                                                   \
    (guid)->Data4[3] = 0xbf;                                                   \
    (guid)->Data4[4] = 0x64;                                                   \
    (guid)->Data4[5] = 0xc8;                                                   \
    (guid)->Data4[6] = 0x6e;                                                   \
    (guid)->Data4[7] = 0xba;                                                   \
  }
#define EXTRACT_USBAUDIO_MID(guid) (USHORT)((guid)->Data1 - 0x4e1cecd2)
#define DEFINE_USBAUDIO_MID_GUID(id)                                           \
  0x4e1cecd2 + (USHORT)(id), 0x1679, 0x463b, 0xa7, 0x2f, 0xa5, 0xbf, 0x64,     \
      0xc8, 0x6e, 0xba

#define IS_COMPATIBLE_USBAUDIO_MID(guid)                                       \
  (((guid)->Data1 >= 0x4e1cecd2) && ((guid)->Data1 < 0x4e1cecd2 + 0xffff) &&   \
   ((guid)->Data2 == 0x1679) && ((guid)->Data3 == 0x463b) &&                   \
   ((guid)->Data4[0] == 0xa7) && ((guid)->Data4[1] == 0x2f) &&                 \
   ((guid)->Data4[2] == 0xa5) && ((guid)->Data4[3] == 0xbf) &&                 \
   ((guid)->Data4[4] == 0x64) && ((guid)->Data4[5] == 0xc8) &&                 \
   ((guid)->Data4[6] == 0x6e) && ((guid)->Data4[7] == 0xba))
#endif // !defined(INIT_USBAUDIO_MID)

#if !defined(INIT_USBAUDIO_PID)
// {abcc5a5e-c263-463b-a72f-a5bf64c86eba}
#define INIT_USBAUDIO_PID(guid, id)                                            \
  {                                                                            \
    (guid)->Data1 = 0xabcc5a5e + (USHORT)(id);                                 \
    (guid)->Data2 = 0xc263;                                                    \
    (guid)->Data3 = 0x463b;                                                    \
    (guid)->Data4[0] = 0xa7;                                                   \
    (guid)->Data4[1] = 0x2f;                                                   \
    (guid)->Data4[2] = 0xa5;                                                   \
    (guid)->Data4[3] = 0xbf;                                                   \
    (guid)->Data4[4] = 0x64;                                                   \
    (guid)->Data4[5] = 0xc8;                                                   \
    (guid)->Data4[6] = 0x6e;                                                   \
    (guid)->Data4[7] = 0xba;                                                   \
  }
#define EXTRACT_USBAUDIO_PID(guid) (USHORT)((guid)->Data1 - 0xabcc5a5e)
#define DEFINE_USBAUDIO_PID_GUID(id)                                           \
  0xabcc5a5e + (USHORT)(id), 0xc263, 0x463b, 0xa7, 0x2f, 0xa5, 0xbf, 0x64,     \
      0xc8, 0x6e, 0xba

#define IS_COMPATIBLE_USBAUDIO_PID(guid)                                       \
  (((guid)->Data1 >= 0xabcc5a5e) && ((guid)->Data1 < 0xabcc5a5e + 0xffff) &&   \
   ((guid)->Data2 == 0xc263) && ((guid)->Data3 == 0x463b) &&                   \
   ((guid)->Data4[0] == 0xa7) && ((guid)->Data4[1] == 0x2f) &&                 \
   ((guid)->Data4[2] == 0xa5) && ((guid)->Data4[3] == 0xbf) &&                 \
   ((guid)->Data4[4] == 0x64) && ((guid)->Data4[5] == 0xc8) &&                 \
   ((guid)->Data4[6] == 0x6e) && ((guid)->Data4[7] == 0xba))
#endif // !defined(INIT_USBAUDIO_PID)

#if !defined(INIT_USBAUDIO_PRODUCT_NAME)
// {FC575048-2E08-463B-A72F-A5BF64C86EBA}
#define INIT_USBAUDIO_PRODUCT_NAME(guid, vid, pid, strIndex)                   \
  {                                                                            \
    (guid)->Data1 = 0XFC575048 + (USHORT)(vid);                                \
    (guid)->Data2 = 0x2E08 + (USHORT)(pid);                                    \
    (guid)->Data3 = 0x463B + (USHORT)(strIndex);                               \
    (guid)->Data4[0] = 0xA7;                                                   \
    (guid)->Data4[1] = 0x2F;                                                   \
    (guid)->Data4[2] = 0xA5;                                                   \
    (guid)->Data4[3] = 0xBF;                                                   \
    (guid)->Data4[4] = 0x64;                                                   \
    (guid)->Data4[5] = 0xC8;                                                   \
    (guid)->Data4[6] = 0x6E;                                                   \
    (guid)->Data4[7] = 0xBA;                                                   \
  }
#define DEFINE_USBAUDIO_PRODUCT_NAME(vid, pid, strIndex)                       \
  0xFC575048 + (USHORT)(vid), 0x2E08 + (USHORT)(pid),                          \
      0x463B + (USHORT)(strIndex), 0xA7, 0x2F, 0xA5, 0xBF, 0x64, 0xC8, 0x6E,   \
      0xBA
#endif // !defined(INIT_USBAUDIO_PRODUCT_NAME)

// USB Component ID
#define STATIC_KSCOMPONENTID_USBAUDIO                                          \
  0x8F1275F0, 0x26E9, 0x4264, 0xBA, 0x4D, 0x39, 0xFF, 0xF0, 0x1D, 0x94, 0xAA
DEFINE_GUIDSTRUCT("8F1275F0-26E9-4264-BA4D-39FFF01D94AA",
                  KSCOMPONENTID_USBAUDIO);
#define KSCOMPONENTID_USBAUDIO DEFINE_GUIDNAMED(KSCOMPONENTID_USBAUDIO)

// USB Terminals
#define INIT_USB_TERMINAL(guid, id)                                            \
  {                                                                            \
    (guid)->Data1 = 0xDFF219E0 + (USHORT)(id);                                 \
    (guid)->Data2 = 0xF70F;                                                    \
    (guid)->Data3 = 0x11D0;                                                    \
    (guid)->Data4[0] = 0xb9;                                                   \
    (guid)->Data4[1] = 0x17;                                                   \
    (guid)->Data4[2] = 0x00;                                                   \
    (guid)->Data4[3] = 0xa0;                                                   \
    (guid)->Data4[4] = 0xc9;                                                   \
    (guid)->Data4[5] = 0x22;                                                   \
    (guid)->Data4[6] = 0x31;                                                   \
    (guid)->Data4[7] = 0x96;                                                   \
  }
#define EXTRACT_USB_TERMINAL(guid) (USHORT)((guid)->Data1 - 0xDFF219E0)
#define DEFINE_USB_TERMINAL_GUID(id)                                           \
  0xDFF219E0 + (USHORT)(id), 0xF70F, 0x11D0, 0xB9, 0x17, 0x00, 0xA0, 0xC9,     \
      0x22, 0x31, 0x96

#define STATIC_KSNODETYPE_MICROPHONE DEFINE_USB_TERMINAL_GUID(0x0201)
DEFINE_GUIDSTRUCT("DFF21BE1-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_MICROPHONE);
#define KSNODETYPE_MICROPHONE DEFINE_GUIDNAMED(KSNODETYPE_MICROPHONE)

#define STATIC_KSNODETYPE_DESKTOP_MICROPHONE DEFINE_USB_TERMINAL_GUID(0x0202)
DEFINE_GUIDSTRUCT("DFF21BE2-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_DESKTOP_MICROPHONE);
#define KSNODETYPE_DESKTOP_MICROPHONE                                          \
  DEFINE_GUIDNAMED(KSNODETYPE_DESKTOP_MICROPHONE)

#define STATIC_KSNODETYPE_PERSONAL_MICROPHONE DEFINE_USB_TERMINAL_GUID(0x0203)
DEFINE_GUIDSTRUCT("DFF21BE3-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_PERSONAL_MICROPHONE);
#define KSNODETYPE_PERSONAL_MICROPHONE                                         \
  DEFINE_GUIDNAMED(KSNODETYPE_PERSONAL_MICROPHONE)

#define STATIC_KSNODETYPE_OMNI_DIRECTIONAL_MICROPHONE                          \
  DEFINE_USB_TERMINAL_GUID(0x0204)
DEFINE_GUIDSTRUCT("DFF21BE4-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_OMNI_DIRECTIONAL_MICROPHONE);
#define KSNODETYPE_OMNI_DIRECTIONAL_MICROPHONE                                 \
  DEFINE_GUIDNAMED(KSNODETYPE_OMNI_DIRECTIONAL_MICROPHONE)

#define STATIC_KSNODETYPE_MICROPHONE_ARRAY DEFINE_USB_TERMINAL_GUID(0x0205)
DEFINE_GUIDSTRUCT("DFF21BE5-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_MICROPHONE_ARRAY);
#define KSNODETYPE_MICROPHONE_ARRAY                                            \
  DEFINE_GUIDNAMED(KSNODETYPE_MICROPHONE_ARRAY)

#define STATIC_KSNODETYPE_PROCESSING_MICROPHONE_ARRAY                          \
  DEFINE_USB_TERMINAL_GUID(0x0206)
DEFINE_GUIDSTRUCT("DFF21BE6-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_PROCESSING_MICROPHONE_ARRAY);
#define KSNODETYPE_PROCESSING_MICROPHONE_ARRAY                                 \
  DEFINE_GUIDNAMED(KSNODETYPE_PROCESSING_MICROPHONE_ARRAY)

#define STATIC_KSCATEGORY_MICROPHONE_ARRAY_PROCESSOR                           \
  0x830a44f2, 0xa32d, 0x476b, 0xbe, 0x97, 0x42, 0x84, 0x56, 0x73, 0xb3, 0x5a
DEFINE_GUIDSTRUCT("830a44f2-a32d-476b-be97-42845673b35a",
                  KSCATEGORY_MICROPHONE_ARRAY_PROCESSOR);
#define KSCATEGORY_MICROPHONE_ARRAY_PROCESSOR                                  \
  DEFINE_GUIDNAMED(KSCATEGORY_MICROPHONE_ARRAY_PROCESSOR)

#define STATIC_KSNODETYPE_SPEAKER DEFINE_USB_TERMINAL_GUID(0x0301)
DEFINE_GUIDSTRUCT("DFF21CE1-F70F-11D0-B917-00A0C9223196", KSNODETYPE_SPEAKER);
#define KSNODETYPE_SPEAKER DEFINE_GUIDNAMED(KSNODETYPE_SPEAKER)

#define STATIC_KSNODETYPE_HEADPHONES DEFINE_USB_TERMINAL_GUID(0x0302)
DEFINE_GUIDSTRUCT("DFF21CE2-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_HEADPHONES);
#define KSNODETYPE_HEADPHONES DEFINE_GUIDNAMED(KSNODETYPE_HEADPHONES)

#define STATIC_KSNODETYPE_HEAD_MOUNTED_DISPLAY_AUDIO                           \
  DEFINE_USB_TERMINAL_GUID(0x0303)
DEFINE_GUIDSTRUCT("DFF21CE3-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_HEAD_MOUNTED_DISPLAY_AUDIO);
#define KSNODETYPE_HEAD_MOUNTED_DISPLAY_AUDIO                                  \
  DEFINE_GUIDNAMED(KSNODETYPE_HEAD_MOUNTED_DISPLAY_AUDIO)

#define STATIC_KSNODETYPE_DESKTOP_SPEAKER DEFINE_USB_TERMINAL_GUID(0x0304)
DEFINE_GUIDSTRUCT("DFF21CE4-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_DESKTOP_SPEAKER);
#define KSNODETYPE_DESKTOP_SPEAKER DEFINE_GUIDNAMED(KSNODETYPE_DESKTOP_SPEAKER)

#define STATIC_KSNODETYPE_ROOM_SPEAKER DEFINE_USB_TERMINAL_GUID(0x0305)
DEFINE_GUIDSTRUCT("DFF21CE5-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_ROOM_SPEAKER);
#define KSNODETYPE_ROOM_SPEAKER DEFINE_GUIDNAMED(KSNODETYPE_ROOM_SPEAKER)

#define STATIC_KSNODETYPE_COMMUNICATION_SPEAKER DEFINE_USB_TERMINAL_GUID(0x0306)
DEFINE_GUIDSTRUCT("DFF21CE6-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_COMMUNICATION_SPEAKER);
#define KSNODETYPE_COMMUNICATION_SPEAKER                                       \
  DEFINE_GUIDNAMED(KSNODETYPE_COMMUNICATION_SPEAKER)

#define STATIC_KSNODETYPE_LOW_FREQUENCY_EFFECTS_SPEAKER                        \
  DEFINE_USB_TERMINAL_GUID(0x0307)
DEFINE_GUIDSTRUCT("DFF21CE7-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_LOW_FREQUENCY_EFFECTS_SPEAKER);
#define KSNODETYPE_LOW_FREQUENCY_EFFECTS_SPEAKER                               \
  DEFINE_GUIDNAMED(KSNODETYPE_LOW_FREQUENCY_EFFECTS_SPEAKER)

#define STATIC_KSNODETYPE_HANDSET DEFINE_USB_TERMINAL_GUID(0x0401)
DEFINE_GUIDSTRUCT("DFF21DE1-F70F-11D0-B917-00A0C9223196", KSNODETYPE_HANDSET);
#define KSNODETYPE_HANDSET DEFINE_GUIDNAMED(KSNODETYPE_HANDSET)

#define STATIC_KSNODETYPE_HEADSET DEFINE_USB_TERMINAL_GUID(0x0402)
DEFINE_GUIDSTRUCT("DFF21DE2-F70F-11D0-B917-00A0C9223196", KSNODETYPE_HEADSET);
#define KSNODETYPE_HEADSET DEFINE_GUIDNAMED(KSNODETYPE_HEADSET)

#define STATIC_KSNODETYPE_SPEAKERPHONE_NO_ECHO_REDUCTION                       \
  DEFINE_USB_TERMINAL_GUID(0x0403)
DEFINE_GUIDSTRUCT("DFF21DE3-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_SPEAKERPHONE_NO_ECHO_REDUCTION);
#define KSNODETYPE_SPEAKERPHONE_NO_ECHO_REDUCTION                              \
  DEFINE_GUIDNAMED(KSNODETYPE_SPEAKERPHONE_NO_ECHO_REDUCTION)

#define STATIC_KSNODETYPE_ECHO_SUPPRESSING_SPEAKERPHONE                        \
  DEFINE_USB_TERMINAL_GUID(0x0404)
DEFINE_GUIDSTRUCT("DFF21DE4-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_ECHO_SUPPRESSING_SPEAKERPHONE);
#define KSNODETYPE_ECHO_SUPPRESSING_SPEAKERPHONE                               \
  DEFINE_GUIDNAMED(KSNODETYPE_ECHO_SUPPRESSING_SPEAKERPHONE)

#define STATIC_KSNODETYPE_ECHO_CANCELING_SPEAKERPHONE                          \
  DEFINE_USB_TERMINAL_GUID(0x0405)
DEFINE_GUIDSTRUCT("DFF21DE5-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_ECHO_CANCELING_SPEAKERPHONE);
#define KSNODETYPE_ECHO_CANCELING_SPEAKERPHONE                                 \
  DEFINE_GUIDNAMED(KSNODETYPE_ECHO_CANCELING_SPEAKERPHONE)

#define STATIC_KSNODETYPE_PHONE_LINE DEFINE_USB_TERMINAL_GUID(0x0501)
DEFINE_GUIDSTRUCT("DFF21EE1-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_PHONE_LINE);
#define KSNODETYPE_PHONE_LINE DEFINE_GUIDNAMED(KSNODETYPE_PHONE_LINE)

#define STATIC_KSNODETYPE_TELEPHONE DEFINE_USB_TERMINAL_GUID(0x0502)
DEFINE_GUIDSTRUCT("DFF21EE2-F70F-11D0-B917-00A0C9223196", KSNODETYPE_TELEPHONE);
#define KSNODETYPE_TELEPHONE DEFINE_GUIDNAMED(KSNODETYPE_TELEPHONE)

#define STATIC_KSNODETYPE_DOWN_LINE_PHONE DEFINE_USB_TERMINAL_GUID(0x0503)
DEFINE_GUIDSTRUCT("DFF21EE3-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_DOWN_LINE_PHONE);
#define KSNODETYPE_DOWN_LINE_PHONE DEFINE_GUIDNAMED(KSNODETYPE_DOWN_LINE_PHONE)

#define STATIC_KSNODETYPE_ANALOG_CONNECTOR DEFINE_USB_TERMINAL_GUID(0x601)
DEFINE_GUIDSTRUCT("DFF21FE1-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_ANALOG_CONNECTOR);
#define KSNODETYPE_ANALOG_CONNECTOR                                            \
  DEFINE_GUIDNAMED(KSNODETYPE_ANALOG_CONNECTOR)

#define STATIC_KSNODETYPE_DIGITAL_AUDIO_INTERFACE                              \
  DEFINE_USB_TERMINAL_GUID(0x0602)
DEFINE_GUIDSTRUCT("DFF21FE2-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_DIGITAL_AUDIO_INTERFACE);
#define KSNODETYPE_DIGITAL_AUDIO_INTERFACE                                     \
  DEFINE_GUIDNAMED(KSNODETYPE_DIGITAL_AUDIO_INTERFACE)

#define STATIC_KSNODETYPE_LINE_CONNECTOR DEFINE_USB_TERMINAL_GUID(0x0603)
DEFINE_GUIDSTRUCT("DFF21FE3-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_LINE_CONNECTOR);
#define KSNODETYPE_LINE_CONNECTOR DEFINE_GUIDNAMED(KSNODETYPE_LINE_CONNECTOR)

#define STATIC_KSNODETYPE_LEGACY_AUDIO_CONNECTOR                               \
  DEFINE_USB_TERMINAL_GUID(0x0604)
DEFINE_GUIDSTRUCT("DFF21FE4-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_LEGACY_AUDIO_CONNECTOR);
#define KSNODETYPE_LEGACY_AUDIO_CONNECTOR                                      \
  DEFINE_GUIDNAMED(KSNODETYPE_LEGACY_AUDIO_CONNECTOR)

#define STATIC_KSNODETYPE_SPDIF_INTERFACE DEFINE_USB_TERMINAL_GUID(0x0605)
DEFINE_GUIDSTRUCT("DFF21FE5-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_SPDIF_INTERFACE);
#define KSNODETYPE_SPDIF_INTERFACE DEFINE_GUIDNAMED(KSNODETYPE_SPDIF_INTERFACE)

#define STATIC_KSNODETYPE_1394_DA_STREAM DEFINE_USB_TERMINAL_GUID(0x0606)
DEFINE_GUIDSTRUCT("DFF21FE6-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_1394_DA_STREAM);
#define KSNODETYPE_1394_DA_STREAM DEFINE_GUIDNAMED(KSNODETYPE_1394_DA_STREAM)

#define STATIC_KSNODETYPE_1394_DV_STREAM_SOUNDTRACK                            \
  DEFINE_USB_TERMINAL_GUID(0x0607)
DEFINE_GUIDSTRUCT("DFF21FE7-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_1394_DV_STREAM_SOUNDTRACK);
#define KSNODETYPE_1394_DV_STREAM_SOUNDTRACK                                   \
  DEFINE_GUIDNAMED(KSNODETYPE_1394_DV_STREAM_SOUNDTRACK)

#define STATIC_KSNODETYPE_LEVEL_CALIBRATION_NOISE_SOURCE                       \
  DEFINE_USB_TERMINAL_GUID(0x0701)
DEFINE_GUIDSTRUCT("DFF220E1-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_LEVEL_CALIBRATION_NOISE_SOURCE);
#define KSNODETYPE_LEVEL_CALIBRATION_NOISE_SOURCE                              \
  DEFINE_GUIDNAMED(KSNODETYPE_LEVEL_CALIBRATION_NOISE_SOURCE)

#define STATIC_KSNODETYPE_EQUALIZATION_NOISE DEFINE_USB_TERMINAL_GUID(0x0702)
DEFINE_GUIDSTRUCT("DFF220E2-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_EQUALIZATION_NOISE);
#define KSNODETYPE_EQUALIZATION_NOISE                                          \
  DEFINE_GUIDNAMED(KSNODETYPE_EQUALIZATION_NOISE)

#define STATIC_KSNODETYPE_CD_PLAYER DEFINE_USB_TERMINAL_GUID(0x0703)
DEFINE_GUIDSTRUCT("DFF220E3-F70F-11D0-B917-00A0C9223196", KSNODETYPE_CD_PLAYER);
#define KSNODETYPE_CD_PLAYER DEFINE_GUIDNAMED(KSNODETYPE_CD_PLAYER)

#define STATIC_KSNODETYPE_DAT_IO_DIGITAL_AUDIO_TAPE                            \
  DEFINE_USB_TERMINAL_GUID(0x0704)
DEFINE_GUIDSTRUCT("DFF220E4-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_DAT_IO_DIGITAL_AUDIO_TAPE);
#define KSNODETYPE_DAT_IO_DIGITAL_AUDIO_TAPE                                   \
  DEFINE_GUIDNAMED(KSNODETYPE_DAT_IO_DIGITAL_AUDIO_TAPE)

#define STATIC_KSNODETYPE_DCC_IO_DIGITAL_COMPACT_CASSETTE                      \
  DEFINE_USB_TERMINAL_GUID(0x0705)
DEFINE_GUIDSTRUCT("DFF220E5-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_DCC_IO_DIGITAL_COMPACT_CASSETTE);
#define KSNODETYPE_DCC_IO_DIGITAL_COMPACT_CASSETTE                             \
  DEFINE_GUIDNAMED(KSNODETYPE_DCC_IO_DIGITAL_COMPACT_CASSETTE)

#define STATIC_KSNODETYPE_MINIDISK DEFINE_USB_TERMINAL_GUID(0x0706)
DEFINE_GUIDSTRUCT("DFF220E6-F70F-11D0-B917-00A0C9223196", KSNODETYPE_MINIDISK);
#define KSNODETYPE_MINIDISK DEFINE_GUIDNAMED(KSNODETYPE_MINIDISK)

#define STATIC_KSNODETYPE_ANALOG_TAPE DEFINE_USB_TERMINAL_GUID(0x0707)
DEFINE_GUIDSTRUCT("DFF220E7-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_ANALOG_TAPE);
#define KSNODETYPE_ANALOG_TAPE DEFINE_GUIDNAMED(KSNODETYPE_ANALOG_TAPE)

#define STATIC_KSNODETYPE_PHONOGRAPH DEFINE_USB_TERMINAL_GUID(0x0708)
DEFINE_GUIDSTRUCT("DFF220E8-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_PHONOGRAPH);
#define KSNODETYPE_PHONOGRAPH DEFINE_GUIDNAMED(KSNODETYPE_PHONOGRAPH)

#define STATIC_KSNODETYPE_VCR_AUDIO DEFINE_USB_TERMINAL_GUID(0x0708)
DEFINE_GUIDSTRUCT("DFF220E9-F70F-11D0-B917-00A0C9223196", KSNODETYPE_VCR_AUDIO);
#define KSNODETYPE_VCR_AUDIO DEFINE_GUIDNAMED(KSNODETYPE_VCR_AUDIO)

#define STATIC_KSNODETYPE_VIDEO_DISC_AUDIO DEFINE_USB_TERMINAL_GUID(0x070A)
DEFINE_GUIDSTRUCT("DFF220EA-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_VIDEO_DISC_AUDIO);
#define KSNODETYPE_VIDEO_DISC_AUDIO                                            \
  DEFINE_GUIDNAMED(KSNODETYPE_VIDEO_DISC_AUDIO)

#define STATIC_KSNODETYPE_DVD_AUDIO DEFINE_USB_TERMINAL_GUID(0x070B)
DEFINE_GUIDSTRUCT("DFF220EB-F70F-11D0-B917-00A0C9223196", KSNODETYPE_DVD_AUDIO);
#define KSNODETYPE_DVD_AUDIO DEFINE_GUIDNAMED(KSNODETYPE_DVD_AUDIO)

#define STATIC_KSNODETYPE_TV_TUNER_AUDIO DEFINE_USB_TERMINAL_GUID(0x070C)
DEFINE_GUIDSTRUCT("DFF220EC-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_TV_TUNER_AUDIO);
#define KSNODETYPE_TV_TUNER_AUDIO DEFINE_GUIDNAMED(KSNODETYPE_TV_TUNER_AUDIO)

#define STATIC_KSNODETYPE_SATELLITE_RECEIVER_AUDIO                             \
  DEFINE_USB_TERMINAL_GUID(0x070D)
DEFINE_GUIDSTRUCT("DFF220ED-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_SATELLITE_RECEIVER_AUDIO);
#define KSNODETYPE_SATELLITE_RECEIVER_AUDIO                                    \
  DEFINE_GUIDNAMED(KSNODETYPE_SATELLITE_RECEIVER_AUDIO)

#define STATIC_KSNODETYPE_CABLE_TUNER_AUDIO DEFINE_USB_TERMINAL_GUID(0x070E)
DEFINE_GUIDSTRUCT("DFF220EE-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_CABLE_TUNER_AUDIO);
#define KSNODETYPE_CABLE_TUNER_AUDIO                                           \
  DEFINE_GUIDNAMED(KSNODETYPE_CABLE_TUNER_AUDIO)

#define STATIC_KSNODETYPE_DSS_AUDIO DEFINE_USB_TERMINAL_GUID(0x070F)
DEFINE_GUIDSTRUCT("DFF220EF-F70F-11D0-B917-00A0C9223196", KSNODETYPE_DSS_AUDIO);
#define KSNODETYPE_DSS_AUDIO DEFINE_GUIDNAMED(KSNODETYPE_DSS_AUDIO)

#define STATIC_KSNODETYPE_RADIO_RECEIVER DEFINE_USB_TERMINAL_GUID(0x0710)
DEFINE_GUIDSTRUCT("DFF220F0-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_RADIO_RECEIVER);
#define KSNODETYPE_RADIO_RECEIVER DEFINE_GUIDNAMED(KSNODETYPE_RADIO_RECEIVER)

#define STATIC_KSNODETYPE_RADIO_TRANSMITTER DEFINE_USB_TERMINAL_GUID(0x0711)
DEFINE_GUIDSTRUCT("DFF220F1-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_RADIO_TRANSMITTER);
#define KSNODETYPE_RADIO_TRANSMITTER                                           \
  DEFINE_GUIDNAMED(KSNODETYPE_RADIO_TRANSMITTER)

#define STATIC_KSNODETYPE_MULTITRACK_RECORDER DEFINE_USB_TERMINAL_GUID(0x0712)
DEFINE_GUIDSTRUCT("DFF220F2-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_MULTITRACK_RECORDER);
#define KSNODETYPE_MULTITRACK_RECORDER                                         \
  DEFINE_GUIDNAMED(KSNODETYPE_MULTITRACK_RECORDER)

#define STATIC_KSNODETYPE_SYNTHESIZER DEFINE_USB_TERMINAL_GUID(0x0713)
DEFINE_GUIDSTRUCT("DFF220F3-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_SYNTHESIZER);
#define KSNODETYPE_SYNTHESIZER DEFINE_GUIDNAMED(KSNODETYPE_SYNTHESIZER)

// Microsoft's WDMAUD virtual swsynth pin name guid

#define STATIC_KSNODETYPE_SWSYNTH                                              \
  0x423274A0L, 0x8B81, 0x11D1, 0xA0, 0x50, 0x00, 0x00, 0xF8, 0x00, 0x47, 0x88
DEFINE_GUIDSTRUCT("423274A0-8B81-11D1-A050-0000F8004788", KSNODETYPE_SWSYNTH);
#define KSNODETYPE_SWSYNTH DEFINE_GUIDNAMED(KSNODETYPE_SWSYNTH)

// Microsoft's SWMIDI midi pin and node name guid

#define STATIC_KSNODETYPE_SWMIDI                                               \
  0xCB9BEFA0L, 0xA251, 0x11D1, 0xA0, 0x50, 0x00, 0x00, 0xF8, 0x00, 0x47, 0x88
DEFINE_GUIDSTRUCT("CB9BEFA0-A251-11D1-A050-0000F8004788", KSNODETYPE_SWMIDI);
#define KSNODETYPE_SWMIDI DEFINE_GUIDNAMED(KSNODETYPE_SWMIDI)

#define STATIC_KSNODETYPE_DRM_DESCRAMBLE                                       \
  0xFFBB6E3FL, 0xCCFE, 0x4D84, 0x90, 0xD9, 0x42, 0x14, 0x18, 0xB0, 0x3A, 0x8E
DEFINE_GUIDSTRUCT("FFBB6E3F-CCFE-4D84-90D9-421418B03A8E",
                  KSNODETYPE_DRM_DESCRAMBLE);
#define KSNODETYPE_DRM_DESCRAMBLE DEFINE_GUIDNAMED(KSNODETYPE_DRM_DESCRAMBLE)

// General categories
#define STATIC_KSCATEGORY_AUDIO                                                \
  0x6994AD04L, 0x93EF, 0x11D0, 0xA3, 0xCC, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("6994AD04-93EF-11D0-A3CC-00A0C9223196", KSCATEGORY_AUDIO);
#define KSCATEGORY_AUDIO DEFINE_GUIDNAMED(KSCATEGORY_AUDIO)

#define STATIC_KSCATEGORY_VIDEO                                                \
  0x6994AD05L, 0x93EF, 0x11D0, 0xA3, 0xCC, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("6994AD05-93EF-11D0-A3CC-00A0C9223196", KSCATEGORY_VIDEO);
#define KSCATEGORY_VIDEO DEFINE_GUIDNAMED(KSCATEGORY_VIDEO)

#define STATIC_KSCATEGORY_TEXT                                                 \
  0x6994AD06L, 0x93EF, 0x11D0, 0xA3, 0xCC, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("6994AD06-93EF-11D0-A3CC-00A0C9223196", KSCATEGORY_TEXT);
#define KSCATEGORY_TEXT DEFINE_GUIDNAMED(KSCATEGORY_TEXT)

#define STATIC_KSCATEGORY_NETWORK                                              \
  0x67C9CC3CL, 0x69C4, 0x11D2, 0x87, 0x59, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("67C9CC3C-69C4-11D2-8759-00A0C9223196", KSCATEGORY_NETWORK);
#define KSCATEGORY_NETWORK DEFINE_GUIDNAMED(KSCATEGORY_NETWORK)

#define STATIC_KSCATEGORY_TOPOLOGY                                             \
  0xDDA54A40L, 0x1E4C, 0x11D1, 0xA0, 0x50, 0x40, 0x57, 0x05, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("DDA54A40-1E4C-11D1-A050-405705C10000", KSCATEGORY_TOPOLOGY);
#define KSCATEGORY_TOPOLOGY DEFINE_GUIDNAMED(KSCATEGORY_TOPOLOGY)

#define STATIC_KSCATEGORY_VIRTUAL                                              \
  0x3503EAC4L, 0x1F26, 0x11D1, 0x8A, 0xB0, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("3503EAC4-1F26-11D1-8AB0-00A0C9223196", KSCATEGORY_VIRTUAL);
#define KSCATEGORY_VIRTUAL DEFINE_GUIDNAMED(KSCATEGORY_VIRTUAL)

#define STATIC_KSCATEGORY_ACOUSTIC_ECHO_CANCEL                                 \
  0xBF963D80L, 0xC559, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("BF963D80-C559-11D0-8A2B-00A0C9255AC1",
                  KSCATEGORY_ACOUSTIC_ECHO_CANCEL);
#define KSCATEGORY_ACOUSTIC_ECHO_CANCEL                                        \
  DEFINE_GUIDNAMED(KSCATEGORY_ACOUSTIC_ECHO_CANCEL)

#define STATIC_KSCATEGORY_SYSAUDIO                                             \
  0xA7C7A5B1L, 0x5AF3, 0x11D1, 0x9C, 0xED, 0x00, 0xA0, 0x24, 0xBF, 0x04, 0x07
DEFINE_GUIDSTRUCT("A7C7A5B1-5AF3-11D1-9CED-00A024BF0407", KSCATEGORY_SYSAUDIO);
#define KSCATEGORY_SYSAUDIO DEFINE_GUIDNAMED(KSCATEGORY_SYSAUDIO)

#define STATIC_KSCATEGORY_WDMAUD                                               \
  0x3E227E76L, 0x690D, 0x11D2, 0x81, 0x61, 0x00, 0x00, 0xF8, 0x77, 0x5B, 0xF1
DEFINE_GUIDSTRUCT("3E227E76-690D-11D2-8161-0000F8775BF1", KSCATEGORY_WDMAUD);
#define KSCATEGORY_WDMAUD DEFINE_GUIDNAMED(KSCATEGORY_WDMAUD)

#define STATIC_KSCATEGORY_AUDIO_GFX                                            \
  0x9BAF9572L, 0x340C, 0x11D3, 0xAB, 0xDC, 0x00, 0xA0, 0xC9, 0x0A, 0xB1, 0x6F
DEFINE_GUIDSTRUCT("9BAF9572-340C-11D3-ABDC-00A0C90AB16F", KSCATEGORY_AUDIO_GFX);
#define KSCATEGORY_AUDIO_GFX DEFINE_GUIDNAMED(KSCATEGORY_AUDIO_GFX)

#define STATIC_KSCATEGORY_AUDIO_SPLITTER                                       \
  0x9EA331FAL, 0xB91B, 0x45F8, 0x92, 0x85, 0xBD, 0x2B, 0xC7, 0x7A, 0xFC, 0xDE
DEFINE_GUIDSTRUCT("9EA331FA-B91B-45F8-9285-BD2BC77AFCDE",
                  KSCATEGORY_AUDIO_SPLITTER);
#define KSCATEGORY_AUDIO_SPLITTER DEFINE_GUIDNAMED(KSCATEGORY_AUDIO_SPLITTER)

#define STATIC_KSCATEGORY_SYNTHESIZER STATIC_KSNODETYPE_SYNTHESIZER
#define KSCATEGORY_SYNTHESIZER KSNODETYPE_SYNTHESIZER

#define STATIC_KSCATEGORY_DRM_DESCRAMBLE STATIC_KSNODETYPE_DRM_DESCRAMBLE
#define KSCATEGORY_DRM_DESCRAMBLE KSNODETYPE_DRM_DESCRAMBLE

#define STATIC_KSCATEGORY_AUDIO_DEVICE                                         \
  0xFBF6F530L, 0x07B9, 0x11D2, 0xA7, 0x1E, 0x00, 0x00, 0xF8, 0x00, 0x47, 0x88
DEFINE_GUIDSTRUCT("FBF6F530-07B9-11D2-A71E-0000F8004788",
                  KSCATEGORY_AUDIO_DEVICE);
#define KSCATEGORY_AUDIO_DEVICE DEFINE_GUIDNAMED(KSCATEGORY_AUDIO_DEVICE)

#define STATIC_KSCATEGORY_PREFERRED_WAVEOUT_DEVICE                             \
  0xD6C5066EL, 0x72C1, 0x11D2, 0x97, 0x55, 0x00, 0x00, 0xF8, 0x00, 0x47, 0x88
DEFINE_GUIDSTRUCT("D6C5066E-72C1-11D2-9755-0000F8004788",
                  KSCATEGORY_PREFERRED_WAVEOUT_DEVICE);
#define KSCATEGORY_PREFERRED_WAVEOUT_DEVICE                                    \
  DEFINE_GUIDNAMED(KSCATEGORY_PREFERRED_WAVEOUT_DEVICE)

#define STATIC_KSCATEGORY_PREFERRED_WAVEIN_DEVICE                              \
  0xD6C50671L, 0x72C1, 0x11D2, 0x97, 0x55, 0x00, 0x00, 0xF8, 0x00, 0x47, 0x88
DEFINE_GUIDSTRUCT("D6C50671-72C1-11D2-9755-0000F8004788",
                  KSCATEGORY_PREFERRED_WAVEIN_DEVICE);
#define KSCATEGORY_PREFERRED_WAVEIN_DEVICE                                     \
  DEFINE_GUIDNAMED(KSCATEGORY_PREFERRED_WAVEIN_DEVICE)

#define STATIC_KSCATEGORY_PREFERRED_MIDIOUT_DEVICE                             \
  0xD6C50674L, 0x72C1, 0x11D2, 0x97, 0x55, 0x00, 0x00, 0xF8, 0x00, 0x47, 0x88
DEFINE_GUIDSTRUCT("D6C50674-72C1-11D2-9755-0000F8004788",
                  KSCATEGORY_PREFERRED_MIDIOUT_DEVICE);
#define KSCATEGORY_PREFERRED_MIDIOUT_DEVICE                                    \
  DEFINE_GUIDNAMED(KSCATEGORY_PREFERRED_MIDIOUT_DEVICE)

// Special pin category for wdmaud

#define STATIC_KSCATEGORY_WDMAUD_USE_PIN_NAME                                  \
  0x47A4FA20L, 0xA251, 0x11D1, 0xA0, 0x50, 0x00, 0x00, 0xF8, 0x00, 0x47, 0x88
DEFINE_GUIDSTRUCT("47A4FA20-A251-11D1-A050-0000F8004788",
                  KSCATEGORY_WDMAUD_USE_PIN_NAME);
#define KSCATEGORY_WDMAUD_USE_PIN_NAME                                         \
  DEFINE_GUIDNAMED(KSCATEGORY_WDMAUD_USE_PIN_NAME)

// Escalante Platform Interface

#define STATIC_KSCATEGORY_ESCALANTE_PLATFORM_DRIVER                            \
  0x74f3aea8L, 0x9768, 0x11d1, 0x8e, 0x07, 0x00, 0xa0, 0xc9, 0x5e, 0xc2, 0x2e
DEFINE_GUIDSTRUCT("74f3aea8-9768-11d1-8e07-00a0c95ec22e",
                  KSCATEGORY_ESCALANTE_PLATFORM_DRIVER);
#define KSCATEGORY_ESCALANTE_PLATFORM_DRIVER                                   \
  DEFINE_GUIDNAMED(KSCATEGORY_ESCALANTE_PLATFORM_DRIVER)

// -- major types ---

// 'vids' == MEDIATYPE_Video,
#define STATIC_KSDATAFORMAT_TYPE_VIDEO                                         \
  0x73646976L, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
DEFINE_GUIDSTRUCT("73646976-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_TYPE_VIDEO);
#define KSDATAFORMAT_TYPE_VIDEO DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_VIDEO)

// 'auds' == MEDIATYPE_Audio
#define STATIC_KSDATAFORMAT_TYPE_AUDIO                                         \
  0x73647561L, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
DEFINE_GUIDSTRUCT("73647561-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_TYPE_AUDIO);
#define KSDATAFORMAT_TYPE_AUDIO DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_AUDIO)

// 'txts' == MEDIATYPE_Text
#define STATIC_KSDATAFORMAT_TYPE_TEXT                                          \
  0x73747874L, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
DEFINE_GUIDSTRUCT("73747874-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_TYPE_TEXT);
#define KSDATAFORMAT_TYPE_TEXT DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_TEXT)

#if !defined(DEFINE_WAVEFORMATEX_GUID)
#define DEFINE_WAVEFORMATEX_GUID(x)                                            \
  (USHORT)(x), 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
#endif

#define STATIC_KSDATAFORMAT_SUBTYPE_WAVEFORMATEX                               \
  0x00000000L, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
DEFINE_GUIDSTRUCT("00000000-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_SUBTYPE_WAVEFORMATEX);
#define KSDATAFORMAT_SUBTYPE_WAVEFORMATEX                                      \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_WAVEFORMATEX)

#define INIT_WAVEFORMATEX_GUID(Guid, x)                                        \
  {                                                                            \
    *(Guid) = KSDATAFORMAT_SUBTYPE_WAVEFORMATEX;                               \
    (Guid)->Data1 = (USHORT)(x);                                               \
  }

#define EXTRACT_WAVEFORMATEX_ID(Guid) (USHORT)((Guid)->Data1)

#define IS_VALID_WAVEFORMATEX_GUID(Guid)                                       \
  (!memcmp(((PUSHORT) & KSDATAFORMAT_SUBTYPE_WAVEFORMATEX) + 1,                \
           ((PUSHORT)(Guid)) + 1, sizeof(GUID) - sizeof(USHORT)))

#if !defined(INIT_MMREG_MID)
//{d5a47fa7-6d98-11d1-a21a-00a0c9223196}
#define INIT_MMREG_MID(guid, id)                                               \
  {                                                                            \
    (guid)->Data1 = 0xd5a47fa7 + (USHORT)(id);                                 \
    (guid)->Data2 = 0x6d98;                                                    \
    (guid)->Data3 = 0x11d1;                                                    \
    (guid)->Data4[0] = 0xa2;                                                   \
    (guid)->Data4[1] = 0x1a;                                                   \
    (guid)->Data4[2] = 0x00;                                                   \
    (guid)->Data4[3] = 0xa0;                                                   \
    (guid)->Data4[4] = 0xc9;                                                   \
    (guid)->Data4[5] = 0x22;                                                   \
    (guid)->Data4[6] = 0x31;                                                   \
    (guid)->Data4[7] = 0x96;                                                   \
  }
#define EXTRACT_MMREG_MID(guid) (USHORT)((guid)->Data1 - 0xd5a47fa7)
#define DEFINE_MMREG_MID_GUID(id)                                              \
  0xd5a47fa7 + (USHORT)(id), 0x6d98, 0x11d1, 0xa2, 0x1a, 0x00, 0xa0, 0xc9,     \
      0x22, 0x31, 0x96

#define IS_COMPATIBLE_MMREG_MID(guid)                                          \
  (((guid)->Data1 >= 0xd5a47fa7) && ((guid)->Data1 < 0xd5a47fa7 + 0xffff) &&   \
   ((guid)->Data2 == 0x6d98) && ((guid)->Data3 == 0x11d1) &&                   \
   ((guid)->Data4[0] == 0xa2) && ((guid)->Data4[1] == 0x1a) &&                 \
   ((guid)->Data4[2] == 0x00) && ((guid)->Data4[3] == 0xa0) &&                 \
   ((guid)->Data4[4] == 0xc9) && ((guid)->Data4[5] == 0x22) &&                 \
   ((guid)->Data4[6] == 0x31) && ((guid)->Data4[7] == 0x96))
#endif // !defined(INIT_MMREG_MID)

#if !defined(INIT_MMREG_PID)
//{e36dc2ac-6d9a-11d1-a21a-00a0c9223196}
#define INIT_MMREG_PID(guid, id)                                               \
  {                                                                            \
    (guid)->Data1 = 0xe36dc2ac + (USHORT)(id);                                 \
    (guid)->Data2 = 0x6d9a;                                                    \
    (guid)->Data3 = 0x11d1;                                                    \
    (guid)->Data4[0] = 0xa2;                                                   \
    (guid)->Data4[1] = 0x1a;                                                   \
    (guid)->Data4[2] = 0x00;                                                   \
    (guid)->Data4[3] = 0xa0;                                                   \
    (guid)->Data4[4] = 0xc9;                                                   \
    (guid)->Data4[5] = 0x22;                                                   \
    (guid)->Data4[6] = 0x31;                                                   \
    (guid)->Data4[7] = 0x96;                                                   \
  }
#define EXTRACT_MMREG_PID(guid) (USHORT)((guid)->Data1 - 0xe36dc2ac)
#define DEFINE_MMREG_PID_GUID(id)                                              \
  0xe36dc2ac + (USHORT)(id), 0x6d9a, 0x11d1, 0xa2, 0x1a, 0x00, 0xa0, 0xc9,     \
      0x22, 0x31, 0x96

#define IS_COMPATIBLE_MMREG_PID(guid)                                          \
  (((guid)->Data1 >= 0xe36dc2ac) && ((guid)->Data1 < 0xe36dc2ac + 0xffff) &&   \
   ((guid)->Data2 == 0x6d9a) && ((guid)->Data3 == 0x11d1) &&                   \
   ((guid)->Data4[0] == 0xa2) && ((guid)->Data4[1] == 0x1a) &&                 \
   ((guid)->Data4[2] == 0x00) && ((guid)->Data4[3] == 0xa0) &&                 \
   ((guid)->Data4[4] == 0xc9) && ((guid)->Data4[5] == 0x22) &&                 \
   ((guid)->Data4[6] == 0x31) && ((guid)->Data4[7] == 0x96))
#endif // !defined(INIT_MMREG_PID)

#define STATIC_KSDATAFORMAT_SUBTYPE_ANALOG                                     \
  0x6dba3190L, 0x67bd, 0x11cf, 0xa0, 0xf7, 0x00, 0x20, 0xaf, 0xd1, 0x56, 0xe4
DEFINE_GUIDSTRUCT("6dba3190-67bd-11cf-a0f7-0020afd156e4",
                  KSDATAFORMAT_SUBTYPE_ANALOG);
#define KSDATAFORMAT_SUBTYPE_ANALOG                                            \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_ANALOG)

#define STATIC_KSDATAFORMAT_SUBTYPE_PCM                                        \
  DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_PCM)
DEFINE_GUIDSTRUCT("00000001-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_SUBTYPE_PCM);
#define KSDATAFORMAT_SUBTYPE_PCM DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_PCM)

#if defined(_INC_MMREG)
#define STATIC_KSDATAFORMAT_SUBTYPE_IEEE_FLOAT                                 \
  DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_IEEE_FLOAT)
DEFINE_GUIDSTRUCT("00000003-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_SUBTYPE_IEEE_FLOAT);
#define KSDATAFORMAT_SUBTYPE_IEEE_FLOAT                                        \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)

#define STATIC_KSDATAFORMAT_SUBTYPE_DRM                                        \
  DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_DRM)
DEFINE_GUIDSTRUCT("00000009-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_SUBTYPE_DRM);
#define KSDATAFORMAT_SUBTYPE_DRM DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_DRM)

#define STATIC_KSDATAFORMAT_SUBTYPE_ALAW                                       \
  DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_ALAW)
DEFINE_GUIDSTRUCT("00000006-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_SUBTYPE_ALAW);
#define KSDATAFORMAT_SUBTYPE_ALAW DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_ALAW)

#define STATIC_KSDATAFORMAT_SUBTYPE_MULAW                                      \
  DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_MULAW)
DEFINE_GUIDSTRUCT("00000007-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_SUBTYPE_MULAW);
#define KSDATAFORMAT_SUBTYPE_MULAW DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_MULAW)

#define STATIC_KSDATAFORMAT_SUBTYPE_ADPCM                                      \
  DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_ADPCM)
DEFINE_GUIDSTRUCT("00000002-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_SUBTYPE_ADPCM);
#define KSDATAFORMAT_SUBTYPE_ADPCM DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_ADPCM)

#define STATIC_KSDATAFORMAT_SUBTYPE_MPEG                                       \
  DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_MPEG)
DEFINE_GUIDSTRUCT("00000050-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_SUBTYPE_MPEG);
#define KSDATAFORMAT_SUBTYPE_MPEG DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_MPEG)
#endif // defined(_INC_MMREG)

#define STATIC_KSDATAFORMAT_SPECIFIER_VC_ID                                    \
  0xAD98D184L, 0xAAC3, 0x11D0, 0xA4, 0x1C, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("AD98D184-AAC3-11D0-A41C-00A0C9223196",
                  KSDATAFORMAT_SPECIFIER_VC_ID);
#define KSDATAFORMAT_SPECIFIER_VC_ID                                           \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_VC_ID)

#define STATIC_KSDATAFORMAT_SPECIFIER_WAVEFORMATEX                             \
  0x05589f81L, 0xc356, 0x11ce, 0xbf, 0x01, 0x00, 0xaa, 0x00, 0x55, 0x59, 0x5a
DEFINE_GUIDSTRUCT("05589f81-c356-11ce-bf01-00aa0055595a",
                  KSDATAFORMAT_SPECIFIER_WAVEFORMATEX);
#define KSDATAFORMAT_SPECIFIER_WAVEFORMATEX                                    \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)

#define STATIC_KSDATAFORMAT_SPECIFIER_DSOUND                                   \
  0x518590a2L, 0xa184, 0x11d0, 0x85, 0x22, 0x00, 0xc0, 0x4f, 0xd9, 0xba, 0xf3
DEFINE_GUIDSTRUCT("518590a2-a184-11d0-8522-00c04fd9baf3",
                  KSDATAFORMAT_SPECIFIER_DSOUND);
#define KSDATAFORMAT_SPECIFIER_DSOUND                                          \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_DSOUND)

#if defined(_INC_MMSYSTEM) || defined(_INC_MMREG)
#if !defined(PACK_PRAGMAS_NOT_SUPPORTED)
#include <pshpack1.h>
#endif
typedef struct {
  KSDATAFORMAT DataFormat;
  WAVEFORMATEX WaveFormatEx;
} KSDATAFORMAT_WAVEFORMATEX, *PKSDATAFORMAT_WAVEFORMATEX;

#ifndef _WAVEFORMATEXTENSIBLE_
#define _WAVEFORMATEXTENSIBLE_
typedef struct {
  WAVEFORMATEX Format;
  union {
    WORD wValidBitsPerSample; /* bits of precision  */
    WORD wSamplesPerBlock;    /* valid if wBitsPerSample==0 */
    WORD wReserved;           /* If neither applies, set to zero. */
  } Samples;
  DWORD dwChannelMask; /* which channels are */
                       /* present in stream  */
  GUID SubFormat;
} WAVEFORMATEXTENSIBLE, *PWAVEFORMATEXTENSIBLE;
#endif // !_WAVEFORMATEXTENSIBLE_

#if !defined(WAVE_FORMAT_EXTENSIBLE)
#define WAVE_FORMAT_EXTENSIBLE 0xFFFE
#endif // !defined(WAVE_FORMAT_EXTENSIBLE)

// DirectSound buffer description
typedef struct {
  ULONG Flags;
  ULONG Control;
  WAVEFORMATEX WaveFormatEx;
} KSDSOUND_BUFFERDESC, *PKSDSOUND_BUFFERDESC;

// DirectSound format
typedef struct {
  KSDATAFORMAT DataFormat;
  KSDSOUND_BUFFERDESC BufferDesc;
} KSDATAFORMAT_DSOUND, *PKSDATAFORMAT_DSOUND;

#if !defined(PACK_PRAGMAS_NOT_SUPPORTED)
#include <poppack.h>
#endif
#endif // defined(_INC_MMSYSTEM) || defined(_INC_MMREG)

// DirectSound buffer flags
#define KSDSOUND_BUFFER_PRIMARY 0x00000001
#define KSDSOUND_BUFFER_STATIC 0x00000002
#define KSDSOUND_BUFFER_LOCHARDWARE 0x00000004
#define KSDSOUND_BUFFER_LOCSOFTWARE 0x00000008

// DirectSound buffer control flags
#define KSDSOUND_BUFFER_CTRL_3D 0x00000001
#define KSDSOUND_BUFFER_CTRL_FREQUENCY 0x00000002
#define KSDSOUND_BUFFER_CTRL_PAN 0x00000004
#define KSDSOUND_BUFFER_CTRL_VOLUME 0x00000008
#define KSDSOUND_BUFFER_CTRL_POSITIONNOTIFY 0x00000010

typedef struct {
#if defined(_NTDDK_)
  ULONGLONG PlayOffset;
  ULONGLONG WriteOffset;
#else  // !_NTDDK_
  DWORDLONG PlayOffset;
  DWORDLONG WriteOffset;
#endif // !_NTDDK_
} KSAUDIO_POSITION, *PKSAUDIO_POSITION;

//===========================================================================
// DirectSound3D HAL

typedef struct _DS3DVECTOR {
  union {
    FLOAT x;
    FLOAT dvX;
  };
  union {
    FLOAT y;
    FLOAT dvY;
  };
  union {
    FLOAT z;
    FLOAT dvZ;
  };
} DS3DVECTOR, *PDS3DVECTOR;

//===========================================================================
//===========================================================================

// KSPROPSETID_DirectSound3DListener : {437B3414-D060-11d0-8583-00C04FD9BAF3}

#define STATIC_KSPROPSETID_DirectSound3DListener                               \
  0x437b3414L, 0xd060, 0x11d0, 0x85, 0x83, 0x00, 0xc0, 0x4f, 0xd9, 0xba, 0xf3
DEFINE_GUIDSTRUCT("437b3414-d060-11d0-8583-00c04fd9baf3",
                  KSPROPSETID_DirectSound3DListener);
#define KSPROPSETID_DirectSound3DListener                                      \
  DEFINE_GUIDNAMED(KSPROPSETID_DirectSound3DListener)

typedef enum {
  KSPROPERTY_DIRECTSOUND3DLISTENER_ALL,
  KSPROPERTY_DIRECTSOUND3DLISTENER_POSITION,
  KSPROPERTY_DIRECTSOUND3DLISTENER_VELOCITY,
  KSPROPERTY_DIRECTSOUND3DLISTENER_ORIENTATION,
  KSPROPERTY_DIRECTSOUND3DLISTENER_DISTANCEFACTOR,
  KSPROPERTY_DIRECTSOUND3DLISTENER_ROLLOFFFACTOR,
  KSPROPERTY_DIRECTSOUND3DLISTENER_DOPPLERFACTOR,
  KSPROPERTY_DIRECTSOUND3DLISTENER_BATCH,
  KSPROPERTY_DIRECTSOUND3DLISTENER_ALLOCATION
} KSPROPERTY_DIRECTSOUND3DLISTENER;

typedef struct {
  DS3DVECTOR Position;
  DS3DVECTOR Velocity;
  DS3DVECTOR OrientFront;
  DS3DVECTOR OrientTop;
  FLOAT DistanceFactor;
  FLOAT RolloffFactor;
  FLOAT DopplerFactor;
} KSDS3D_LISTENER_ALL, *PKSDS3D_LISTENER_ALL;

typedef struct {
  DS3DVECTOR Front;
  DS3DVECTOR Top;
} KSDS3D_LISTENER_ORIENTATION, *PKSDS3D_LISTENER_ORIENTATION;

//===========================================================================
//===========================================================================
// KSPROPSETID_DirectSound3DBuffer : {437B3411-D060-11d0-8583-00C04FD9BAF3}

#define STATIC_KSPROPSETID_DirectSound3DBuffer                                 \
  0x437b3411L, 0xd060, 0x11d0, 0x85, 0x83, 0x00, 0xc0, 0x4f, 0xd9, 0xba, 0xf3
DEFINE_GUIDSTRUCT("437b3411-d060-11d0-8583-00c04fd9baf3",
                  KSPROPSETID_DirectSound3DBuffer);
#define KSPROPSETID_DirectSound3DBuffer                                        \
  DEFINE_GUIDNAMED(KSPROPSETID_DirectSound3DBuffer)

typedef enum {
  KSPROPERTY_DIRECTSOUND3DBUFFER_ALL,
  KSPROPERTY_DIRECTSOUND3DBUFFER_POSITION,
  KSPROPERTY_DIRECTSOUND3DBUFFER_VELOCITY,
  KSPROPERTY_DIRECTSOUND3DBUFFER_CONEANGLES,
  KSPROPERTY_DIRECTSOUND3DBUFFER_CONEORIENTATION,
  KSPROPERTY_DIRECTSOUND3DBUFFER_CONEOUTSIDEVOLUME,
  KSPROPERTY_DIRECTSOUND3DBUFFER_MINDISTANCE,
  KSPROPERTY_DIRECTSOUND3DBUFFER_MAXDISTANCE,
  KSPROPERTY_DIRECTSOUND3DBUFFER_MODE
} KSPROPERTY_DIRECTSOUND3DBUFFER;

typedef struct {
  DS3DVECTOR Position;
  DS3DVECTOR Velocity;
  ULONG InsideConeAngle;
  ULONG OutsideConeAngle;
  DS3DVECTOR ConeOrientation;
  LONG ConeOutsideVolume;
  FLOAT MinDistance;
  FLOAT MaxDistance;
  ULONG Mode;
} KSDS3D_BUFFER_ALL, *PKSDS3D_BUFFER_ALL;

typedef struct {
  ULONG InsideConeAngle;
  ULONG OutsideConeAngle;
} KSDS3D_BUFFER_CONE_ANGLES, *PKSDS3D_BUFFER_CONE_ANGLES;

#define KSAUDIO_STEREO_SPEAKER_GEOMETRY_HEADPHONE (-1)
#define KSAUDIO_STEREO_SPEAKER_GEOMETRY_MIN 5
#define KSAUDIO_STEREO_SPEAKER_GEOMETRY_NARROW 10
#define KSAUDIO_STEREO_SPEAKER_GEOMETRY_WIDE 20
#define KSAUDIO_STEREO_SPEAKER_GEOMETRY_MAX 180

#define KSDSOUND_3D_MODE_NORMAL 0x00000000
#define KSDSOUND_3D_MODE_HEADRELATIVE 0x00000001
#define KSDSOUND_3D_MODE_DISABLE 0x00000002

typedef struct {
  KSDATARANGE DataRange;
  ULONG MaximumChannels;
  ULONG MinimumBitsPerSample;
  ULONG MaximumBitsPerSample;
  ULONG MinimumSampleFrequency;
  ULONG MaximumSampleFrequency;
} KSDATARANGE_AUDIO, *PKSDATARANGE_AUDIO;

//---------------------------------------------------------------------------

#define STATIC_KSDATAFORMAT_SUBTYPE_RIFF                                       \
  0x4995DAEEL, 0x9EE6, 0x11D0, 0xA4, 0x0E, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("4995DAEE-9EE6-11D0-A40E-00A0C9223196",
                  KSDATAFORMAT_SUBTYPE_RIFF);
#define KSDATAFORMAT_SUBTYPE_RIFF DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_RIFF)

#define STATIC_KSDATAFORMAT_SUBTYPE_RIFFWAVE                                   \
  0xe436eb8bL, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70
DEFINE_GUIDSTRUCT("e436eb8b-524f-11ce-9f53-0020af0ba770",
                  KSDATAFORMAT_SUBTYPE_RIFFWAVE);
#define KSDATAFORMAT_SUBTYPE_RIFFWAVE                                          \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_RIFFWAVE)

//===========================================================================
//===========================================================================

#define STATIC_KSPROPSETID_Bibliographic                                       \
  0x07BA150EL, 0xE2B1, 0x11D0, 0xAC, 0x17, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("07BA150E-E2B1-11D0-AC17-00A0C9223196",
                  KSPROPSETID_Bibliographic);
#define KSPROPSETID_Bibliographic DEFINE_GUIDNAMED(KSPROPSETID_Bibliographic)

// Repeatable tags contain all entries within the property, each preceeded by
// length
typedef enum {
  KSPROPERTY_BIBLIOGRAPHIC_LEADER = 'RDL ',
  KSPROPERTY_BIBLIOGRAPHIC_LCCN = '010 ',
  KSPROPERTY_BIBLIOGRAPHIC_ISBN = '020 ',
  KSPROPERTY_BIBLIOGRAPHIC_ISSN = '220 ',
  KSPROPERTY_BIBLIOGRAPHIC_CATALOGINGSOURCE = '040 ',
  KSPROPERTY_BIBLIOGRAPHIC_MAINPERSONALNAME = '001 ',
  KSPROPERTY_BIBLIOGRAPHIC_MAINCORPORATEBODY = '011 ',
  KSPROPERTY_BIBLIOGRAPHIC_MAINMEETINGNAME = '111 ',
  KSPROPERTY_BIBLIOGRAPHIC_MAINUNIFORMTITLE = '031 ',
  KSPROPERTY_BIBLIOGRAPHIC_UNIFORMTITLE = '042 ',
  KSPROPERTY_BIBLIOGRAPHIC_TITLESTATEMENT = '542 ',
  KSPROPERTY_BIBLIOGRAPHIC_VARYINGFORMTITLE = '642 ',
  KSPROPERTY_BIBLIOGRAPHIC_PUBLICATION = '062 ',
  KSPROPERTY_BIBLIOGRAPHIC_PHYSICALDESCRIPTION = '003 ',
  KSPROPERTY_BIBLIOGRAPHIC_ADDEDENTRYTITLE = '044 ',
  KSPROPERTY_BIBLIOGRAPHIC_SERIESSTATEMENT = '094 ',
  KSPROPERTY_BIBLIOGRAPHIC_GENERALNOTE = '005 ',
  KSPROPERTY_BIBLIOGRAPHIC_BIBLIOGRAPHYNOTE = '405 ',
  KSPROPERTY_BIBLIOGRAPHIC_CONTENTSNOTE = '505 ',
  KSPROPERTY_BIBLIOGRAPHIC_CREATIONCREDIT = '805 ',
  KSPROPERTY_BIBLIOGRAPHIC_CITATION = '015 ',
  KSPROPERTY_BIBLIOGRAPHIC_PARTICIPANT = '115 ',
  KSPROPERTY_BIBLIOGRAPHIC_SUMMARY = '025 ',
  KSPROPERTY_BIBLIOGRAPHIC_TARGETAUDIENCE = '125 ',
  KSPROPERTY_BIBLIOGRAPHIC_ADDEDFORMAVAILABLE = '035 ',
  KSPROPERTY_BIBLIOGRAPHIC_SYSTEMDETAILS = '835 ',
  KSPROPERTY_BIBLIOGRAPHIC_AWARDS = '685 ',
  KSPROPERTY_BIBLIOGRAPHIC_ADDEDENTRYPERSONALNAME = '006 ',
  KSPROPERTY_BIBLIOGRAPHIC_ADDEDENTRYTOPICALTERM = '056 ',
  KSPROPERTY_BIBLIOGRAPHIC_ADDEDENTRYGEOGRAPHIC = '156 ',
  KSPROPERTY_BIBLIOGRAPHIC_INDEXTERMGENRE = '556 ',
  KSPROPERTY_BIBLIOGRAPHIC_INDEXTERMCURRICULUM = '856 ',
  KSPROPERTY_BIBLIOGRAPHIC_ADDEDENTRYUNIFORMTITLE = '037 ',
  KSPROPERTY_BIBLIOGRAPHIC_ADDEDENTRYRELATED = '047 ',
  KSPROPERTY_BIBLIOGRAPHIC_SERIESSTATEMENTPERSONALNAME = '008 ',
  KSPROPERTY_BIBLIOGRAPHIC_SERIESSTATEMENTUNIFORMTITLE = '038 '
} KSPROPERTY_BIBLIOGRAPHIC;

#define STATIC_KSPROPSETID_TopologyNode                                        \
  0x45FFAAA1L, 0x6E1B, 0x11D0, 0xBC, 0xF2, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00
DEFINE_GUIDSTRUCT("45FFAAA1-6E1B-11D0-BCF2-444553540000",
                  KSPROPSETID_TopologyNode);
#define KSPROPSETID_TopologyNode DEFINE_GUIDNAMED(KSPROPSETID_TopologyNode)

typedef enum {
  KSPROPERTY_TOPOLOGYNODE_ENABLE = 1,
  KSPROPERTY_TOPOLOGYNODE_RESET
} KSPROPERTY_TOPOLOGYNODE;

//===========================================================================

#if defined(_NTDDK_)
typedef NTSTATUS(CALLBACK *PRTAUDIOGETPOSITION)(IN PFILE_OBJECT PinFileObject,
                                                OUT PUCHAR *ppPlayPosition,
                                                OUT PLONG plOffset);
#endif // defined(_NTDDK_)

#define STATIC_KSPROPSETID_RtAudio                                             \
  0xa855a48c, 0x2f78, 0x4729, 0x90, 0x51, 0x19, 0x68, 0x74, 0x6b, 0x9e, 0xef
DEFINE_GUIDSTRUCT("A855A48C-2F78-4729-9051-1968746B9EEF", KSPROPSETID_RtAudio);
#define KSPROPSETID_RtAudio DEFINE_GUIDNAMED(KSPROPSETID_RtAudio)

typedef enum { KSPROPERTY_RTAUDIO_GETPOSITIONFUNCTION } KSPROPERTY_RTAUDIO;

//===========================================================================
#define STATIC_KSPROPSETID_DrmAudioStream                                      \
  0x2f2c8ddd, 0x4198, 0x4fac, 0xba, 0x29, 0x61, 0xbb, 0x5, 0xb7, 0xde, 0x6
DEFINE_GUIDSTRUCT("2F2C8DDD-4198-4fac-BA29-61BB05B7DE06",
                  KSPROPSETID_DrmAudioStream);
#define KSPROPSETID_DrmAudioStream DEFINE_GUIDNAMED(KSPROPSETID_DrmAudioStream)

typedef enum { KSPROPERTY_DRMAUDIOSTREAM_CONTENTID } KSPROPERTY_DRMAUDIOSTREAM;

//===========================================================================
#define STATIC_KSPROPSETID_Audio                                               \
  0x45FFAAA0L, 0x6E1B, 0x11D0, 0xBC, 0xF2, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00
DEFINE_GUIDSTRUCT("45FFAAA0-6E1B-11D0-BCF2-444553540000", KSPROPSETID_Audio);
#define KSPROPSETID_Audio DEFINE_GUIDNAMED(KSPROPSETID_Audio)

typedef enum {
  KSPROPERTY_AUDIO_LATENCY = 1,
  KSPROPERTY_AUDIO_COPY_PROTECTION,
  KSPROPERTY_AUDIO_CHANNEL_CONFIG,
  KSPROPERTY_AUDIO_VOLUMELEVEL,
  KSPROPERTY_AUDIO_POSITION,
  KSPROPERTY_AUDIO_DYNAMIC_RANGE,
  KSPROPERTY_AUDIO_QUALITY,
  KSPROPERTY_AUDIO_SAMPLING_RATE,
  KSPROPERTY_AUDIO_DYNAMIC_SAMPLING_RATE,
  KSPROPERTY_AUDIO_MIX_LEVEL_TABLE,
  KSPROPERTY_AUDIO_MIX_LEVEL_CAPS,
  KSPROPERTY_AUDIO_MUX_SOURCE,
  KSPROPERTY_AUDIO_MUTE,
  KSPROPERTY_AUDIO_BASS,
  KSPROPERTY_AUDIO_MID,
  KSPROPERTY_AUDIO_TREBLE,
  KSPROPERTY_AUDIO_BASS_BOOST,
  KSPROPERTY_AUDIO_EQ_LEVEL,
  KSPROPERTY_AUDIO_NUM_EQ_BANDS,
  KSPROPERTY_AUDIO_EQ_BANDS,
  KSPROPERTY_AUDIO_AGC,
  KSPROPERTY_AUDIO_DELAY,
  KSPROPERTY_AUDIO_LOUDNESS,
  KSPROPERTY_AUDIO_WIDE_MODE,
  KSPROPERTY_AUDIO_WIDENESS,
  KSPROPERTY_AUDIO_REVERB_LEVEL,
  KSPROPERTY_AUDIO_CHORUS_LEVEL,
  KSPROPERTY_AUDIO_DEV_SPECIFIC,
  KSPROPERTY_AUDIO_DEMUX_DEST,
  KSPROPERTY_AUDIO_STEREO_ENHANCE,
  KSPROPERTY_AUDIO_MANUFACTURE_GUID,
  KSPROPERTY_AUDIO_PRODUCT_GUID,
  KSPROPERTY_AUDIO_CPU_RESOURCES,
  KSPROPERTY_AUDIO_STEREO_SPEAKER_GEOMETRY,
  KSPROPERTY_AUDIO_SURROUND_ENCODE,
  KSPROPERTY_AUDIO_3D_INTERFACE,
  KSPROPERTY_AUDIO_PEAKMETER,
  KSPROPERTY_AUDIO_ALGORITHM_INSTANCE,
  KSPROPERTY_AUDIO_FILTER_STATE,
  KSPROPERTY_AUDIO_PREFERRED_STATUS
} KSPROPERTY_AUDIO;

// Audio quality constants
#define KSAUDIO_QUALITY_WORST 0x0
#define KSAUDIO_QUALITY_PC 0x1
#define KSAUDIO_QUALITY_BASIC 0x2
#define KSAUDIO_QUALITY_ADVANCED 0x3

// Audio CPU resource constants
#define KSAUDIO_CPU_RESOURCES_NOT_HOST_CPU 0x00000000
#define KSAUDIO_CPU_RESOURCES_HOST_CPU 0x7FFFFFFF

typedef struct {
  BOOL fCopyrighted;
  BOOL fOriginal;
} KSAUDIO_COPY_PROTECTION, *PKSAUDIO_COPY_PROTECTION;

typedef struct {
  LONG ActiveSpeakerPositions;
} KSAUDIO_CHANNEL_CONFIG, *PKSAUDIO_CHANNEL_CONFIG;

// Speaker Positions:
#define SPEAKER_FRONT_LEFT 0x1
#define SPEAKER_FRONT_RIGHT 0x2
#define SPEAKER_FRONT_CENTER 0x4
#define SPEAKER_LOW_FREQUENCY 0x8
#define SPEAKER_BACK_LEFT 0x10
#define SPEAKER_BACK_RIGHT 0x20
#define SPEAKER_FRONT_LEFT_OF_CENTER 0x40
#define SPEAKER_FRONT_RIGHT_OF_CENTER 0x80
#define SPEAKER_BACK_CENTER 0x100
#define SPEAKER_SIDE_LEFT 0x200
#define SPEAKER_SIDE_RIGHT 0x400
#define SPEAKER_TOP_CENTER 0x800
#define SPEAKER_TOP_FRONT_LEFT 0x1000
#define SPEAKER_TOP_FRONT_CENTER 0x2000
#define SPEAKER_TOP_FRONT_RIGHT 0x4000
#define SPEAKER_TOP_BACK_LEFT 0x8000
#define SPEAKER_TOP_BACK_CENTER 0x10000
#define SPEAKER_TOP_BACK_RIGHT 0x20000

// Bit mask locations reserved for future use
#define SPEAKER_RESERVED 0x7FFC0000

// Used to specify that any possible permutation of speaker configurations
#define SPEAKER_ALL 0x80000000

// DirectSound Speaker Config
#define KSAUDIO_SPEAKER_DIRECTOUT 0
#define KSAUDIO_SPEAKER_MONO (SPEAKER_FRONT_CENTER)
#define KSAUDIO_SPEAKER_STEREO (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT)
#define KSAUDIO_SPEAKER_QUAD                                                   \
  (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_BACK_LEFT |              \
   SPEAKER_BACK_RIGHT)
#define KSAUDIO_SPEAKER_SURROUND                                               \
  (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_FRONT_CENTER |           \
   SPEAKER_BACK_CENTER)
#define KSAUDIO_SPEAKER_5POINT1                                                \
  (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_FRONT_CENTER |           \
   SPEAKER_LOW_FREQUENCY | SPEAKER_BACK_LEFT | SPEAKER_BACK_RIGHT)
#define KSAUDIO_SPEAKER_7POINT1                                                \
  (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_FRONT_CENTER |           \
   SPEAKER_LOW_FREQUENCY | SPEAKER_BACK_LEFT | SPEAKER_BACK_RIGHT |            \
   SPEAKER_FRONT_LEFT_OF_CENTER | SPEAKER_FRONT_RIGHT_OF_CENTER)
#define KSAUDIO_SPEAKER_5POINT1_SURROUND                                       \
  (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_FRONT_CENTER |           \
   SPEAKER_LOW_FREQUENCY | SPEAKER_SIDE_LEFT | SPEAKER_SIDE_RIGHT)
#define KSAUDIO_SPEAKER_7POINT1_SURROUND                                       \
  (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_FRONT_CENTER |           \
   SPEAKER_LOW_FREQUENCY | SPEAKER_BACK_LEFT | SPEAKER_BACK_RIGHT |            \
   SPEAKER_SIDE_LEFT | SPEAKER_SIDE_RIGHT)
// The following are obsolete 5.1 and 7.1 settings (they lack side speakers).
// Note this means that the default 5.1 and 7.1 settings
// (KSAUDIO_SPEAKER_5POINT1 and KSAUDIO_SPEAKER_7POINT1 are similarly obsolete
// but are unchanged for compatibility reasons).
#define KSAUDIO_SPEAKER_5POINT1_BACK KSAUDIO_SPEAKER_5POINT1
#define KSAUDIO_SPEAKER_7POINT1_WIDE KSAUDIO_SPEAKER_7POINT1

// DVD Speaker Positions
#define KSAUDIO_SPEAKER_GROUND_FRONT_LEFT SPEAKER_FRONT_LEFT
#define KSAUDIO_SPEAKER_GROUND_FRONT_CENTER SPEAKER_FRONT_CENTER
#define KSAUDIO_SPEAKER_GROUND_FRONT_RIGHT SPEAKER_FRONT_RIGHT
#define KSAUDIO_SPEAKER_GROUND_REAR_LEFT SPEAKER_BACK_LEFT
#define KSAUDIO_SPEAKER_GROUND_REAR_RIGHT SPEAKER_BACK_RIGHT
#define KSAUDIO_SPEAKER_TOP_MIDDLE SPEAKER_TOP_CENTER
#define KSAUDIO_SPEAKER_SUPER_WOOFER SPEAKER_LOW_FREQUENCY

typedef struct {
  ULONG QuietCompression;
  ULONG LoudCompression;
} KSAUDIO_DYNAMIC_RANGE, *PKSAUDIO_DYNAMIC_RANGE;

typedef struct {
  BOOL Mute;
  LONG Level;
} KSAUDIO_MIXLEVEL, *PKSAUDIO_MIXLEVEL;

typedef struct {
  BOOL Mute;
  LONG Minimum;
  LONG Maximum;
  LONG Reset;
} KSAUDIO_MIX_CAPS, *PKSAUDIO_MIX_CAPS;

typedef struct {
  ULONG InputChannels;
  ULONG OutputChannels;
  KSAUDIO_MIX_CAPS Capabilities[1];
} KSAUDIO_MIXCAP_TABLE, *PKSAUDIO_MIXCAP_TABLE;

typedef enum {
  SE_TECH_NONE,
  SE_TECH_ANALOG_DEVICES_PHAT,
  SE_TECH_CREATIVE,
  SE_TECH_NATIONAL_SEMI,
  SE_TECH_YAMAHA_YMERSION,
  SE_TECH_BBE,
  SE_TECH_CRYSTAL_SEMI,
  SE_TECH_QSOUND_QXPANDER,
  SE_TECH_SPATIALIZER,
  SE_TECH_SRS,
  SE_TECH_PLATFORM_TECH,
  SE_TECH_AKM,
  SE_TECH_AUREAL,
  SE_TECH_AZTECH,
  SE_TECH_BINAURA,
  SE_TECH_ESS_TECH,
  SE_TECH_HARMAN_VMAX,
  SE_TECH_NVIDEA,
  SE_TECH_PHILIPS_INCREDIBLE,
  SE_TECH_TEXAS_INST,
  SE_TECH_VLSI_TECH
} SE_TECHNIQUE;

typedef struct {
  SE_TECHNIQUE Technique;
  ULONG Center;
  ULONG Depth;
  ULONG Reserved;
} KSAUDIO_STEREO_ENHANCE, *PKSAUDIO_STEREO_ENHANCE;

typedef enum { // preferred device index
  KSPROPERTY_SYSAUDIO_NORMAL_DEFAULT = 0,
  KSPROPERTY_SYSAUDIO_PLAYBACK_DEFAULT,
  KSPROPERTY_SYSAUDIO_RECORD_DEFAULT,
  KSPROPERTY_SYSAUDIO_MIDI_DEFAULT,
  KSPROPERTY_SYSAUDIO_MIXER_DEFAULT
} KSPROPERTY_SYSAUDIO_DEFAULT_TYPE;

typedef struct {
  BOOL Enable;
  KSPROPERTY_SYSAUDIO_DEFAULT_TYPE DeviceType;
  ULONG Flags;
  ULONG Reserved;
} KSAUDIO_PREFERRED_STATUS, *PKSAUDIO_PREFERRED_STATUS;
//===========================================================================
// Topology Node Type GUIDs

#define STATIC_KSNODETYPE_DAC                                                  \
  0x507AE360L, 0xC554, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("507AE360-C554-11D0-8A2B-00A0C9255AC1", KSNODETYPE_DAC);
#define KSNODETYPE_DAC DEFINE_GUIDNAMED(KSNODETYPE_DAC)

#define STATIC_KSNODETYPE_ADC                                                  \
  0x4D837FE0L, 0xC555, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("4D837FE0-C555-11D0-8A2B-00A0C9255AC1", KSNODETYPE_ADC);
#define KSNODETYPE_ADC DEFINE_GUIDNAMED(KSNODETYPE_ADC)

#define STATIC_KSNODETYPE_SRC                                                  \
  0x9DB7B9E0L, 0xC555, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("9DB7B9E0-C555-11D0-8A2B-00A0C9255AC1", KSNODETYPE_SRC);
#define KSNODETYPE_SRC DEFINE_GUIDNAMED(KSNODETYPE_SRC)

#define STATIC_KSNODETYPE_SUPERMIX                                             \
  0xE573ADC0L, 0xC555, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("E573ADC0-C555-11D0-8A2B-00A0C9255AC1", KSNODETYPE_SUPERMIX);
#define KSNODETYPE_SUPERMIX DEFINE_GUIDNAMED(KSNODETYPE_SUPERMIX)

#define STATIC_KSNODETYPE_MUX                                                  \
  0x2CEAF780L, 0xC556, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("2CEAF780-C556-11D0-8A2B-00A0C9255AC1", KSNODETYPE_MUX);
#define KSNODETYPE_MUX DEFINE_GUIDNAMED(KSNODETYPE_MUX)

#define STATIC_KSNODETYPE_DEMUX                                                \
  0xC0EB67D4L, 0xE807, 0x11D0, 0x95, 0x8A, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("C0EB67D4-E807-11D0-958A-00C04FB925D3", KSNODETYPE_DEMUX);
#define KSNODETYPE_DEMUX DEFINE_GUIDNAMED(KSNODETYPE_DEMUX)

#define STATIC_KSNODETYPE_SUM                                                  \
  0xDA441A60L, 0xC556, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("DA441A60-C556-11D0-8A2B-00A0C9255AC1", KSNODETYPE_SUM);
#define KSNODETYPE_SUM DEFINE_GUIDNAMED(KSNODETYPE_SUM)

#define STATIC_KSNODETYPE_MUTE                                                 \
  0x02B223C0L, 0xC557, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("02B223C0-C557-11D0-8A2B-00A0C9255AC1", KSNODETYPE_MUTE);
#define KSNODETYPE_MUTE DEFINE_GUIDNAMED(KSNODETYPE_MUTE)

#define STATIC_KSNODETYPE_VOLUME                                               \
  0x3A5ACC00L, 0xC557, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("3A5ACC00-C557-11D0-8A2B-00A0C9255AC1", KSNODETYPE_VOLUME);
#define KSNODETYPE_VOLUME DEFINE_GUIDNAMED(KSNODETYPE_VOLUME)

#define STATIC_KSNODETYPE_TONE                                                 \
  0x7607E580L, 0xC557, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("7607E580-C557-11D0-8A2B-00A0C9255AC1", KSNODETYPE_TONE);
#define KSNODETYPE_TONE DEFINE_GUIDNAMED(KSNODETYPE_TONE)

#define STATIC_KSNODETYPE_EQUALIZER                                            \
  0x9D41B4A0L, 0xC557, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("9D41B4A0-C557-11D0-8A2B-00A0C9255AC1", KSNODETYPE_EQUALIZER);
#define KSNODETYPE_EQUALIZER DEFINE_GUIDNAMED(KSNODETYPE_EQUALIZER)

#define STATIC_KSNODETYPE_AGC                                                  \
  0xE88C9BA0L, 0xC557, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("E88C9BA0-C557-11D0-8A2B-00A0C9255AC1", KSNODETYPE_AGC);
#define KSNODETYPE_AGC DEFINE_GUIDNAMED(KSNODETYPE_AGC)

#define STATIC_KSNODETYPE_NOISE_SUPPRESS                                       \
  0xe07f903f, 0x62fd, 0x4e60, 0x8c, 0xdd, 0xde, 0xa7, 0x23, 0x66, 0x65, 0xb5
DEFINE_GUIDSTRUCT("E07F903F-62FD-4e60-8CDD-DEA7236665B5",
                  KSNODETYPE_NOISE_SUPPRESS);
#define KSNODETYPE_NOISE_SUPPRESS DEFINE_GUIDNAMED(KSNODETYPE_NOISE_SUPPRESS)

#define STATIC_KSNODETYPE_DELAY                                                \
  0x144981E0L, 0xC558, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("144981E0-C558-11D0-8A2B-00A0C9255AC1", KSNODETYPE_DELAY);
#define KSNODETYPE_DELAY DEFINE_GUIDNAMED(KSNODETYPE_DELAY)

#define STATIC_KSNODETYPE_LOUDNESS                                             \
  0x41887440L, 0xC558, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("41887440-C558-11D0-8A2B-00A0C9255AC1", KSNODETYPE_LOUDNESS);
#define KSNODETYPE_LOUDNESS DEFINE_GUIDNAMED(KSNODETYPE_LOUDNESS)

#define STATIC_KSNODETYPE_PROLOGIC_DECODER                                     \
  0x831C2C80L, 0xC558, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("831C2C80-C558-11D0-8A2B-00A0C9255AC1",
                  KSNODETYPE_PROLOGIC_DECODER);
#define KSNODETYPE_PROLOGIC_DECODER                                            \
  DEFINE_GUIDNAMED(KSNODETYPE_PROLOGIC_DECODER)

#define STATIC_KSNODETYPE_STEREO_WIDE                                          \
  0xA9E69800L, 0xC558, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("A9E69800-C558-11D0-8A2B-00A0C9255AC1",
                  KSNODETYPE_STEREO_WIDE);
#define KSNODETYPE_STEREO_WIDE DEFINE_GUIDNAMED(KSNODETYPE_STEREO_WIDE)

#define STATIC_KSNODETYPE_STEREO_ENHANCE                                       \
  0xAF6878ACL, 0xE83F, 0x11D0, 0x95, 0x8A, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("AF6878AC-E83F-11D0-958A-00C04FB925D3",
                  KSNODETYPE_STEREO_ENHANCE);
#define KSNODETYPE_STEREO_ENHANCE DEFINE_GUIDNAMED(KSNODETYPE_STEREO_ENHANCE)

#define STATIC_KSNODETYPE_REVERB                                               \
  0xEF0328E0L, 0xC558, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("EF0328E0-C558-11D0-8A2B-00A0C9255AC1", KSNODETYPE_REVERB);
#define KSNODETYPE_REVERB DEFINE_GUIDNAMED(KSNODETYPE_REVERB)

#define STATIC_KSNODETYPE_CHORUS                                               \
  0x20173F20L, 0xC559, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("20173F20-C559-11D0-8A2B-00A0C9255AC1", KSNODETYPE_CHORUS);
#define KSNODETYPE_CHORUS DEFINE_GUIDNAMED(KSNODETYPE_CHORUS)

#define STATIC_KSNODETYPE_3D_EFFECTS                                           \
  0x55515860L, 0xC559, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("55515860-C559-11D0-8A2B-00A0C9255AC1",
                  KSNODETYPE_3D_EFFECTS);
#define KSNODETYPE_3D_EFFECTS DEFINE_GUIDNAMED(KSNODETYPE_3D_EFFECTS)

#define STATIC_KSNODETYPE_ACOUSTIC_ECHO_CANCEL                                 \
  STATIC_KSCATEGORY_ACOUSTIC_ECHO_CANCEL
#define KSNODETYPE_ACOUSTIC_ECHO_CANCEL KSCATEGORY_ACOUSTIC_ECHO_CANCEL

#define STATIC_KSALGORITHMINSTANCE_SYSTEM_ACOUSTIC_ECHO_CANCEL                 \
  0x1c22c56dL, 0x9879, 0x4f5b, 0xa3, 0x89, 0x27, 0x99, 0x6d, 0xdc, 0x28, 0x10
DEFINE_GUIDSTRUCT("1C22C56D-9879-4f5b-A389-27996DDC2810",
                  KSALGORITHMINSTANCE_SYSTEM_ACOUSTIC_ECHO_CANCEL);
#define KSALGORITHMINSTANCE_SYSTEM_ACOUSTIC_ECHO_CANCEL                        \
  DEFINE_GUIDNAMED(KSALGORITHMINSTANCE_SYSTEM_ACOUSTIC_ECHO_CANCEL)

#define STATIC_KSALGORITHMINSTANCE_SYSTEM_NOISE_SUPPRESS                       \
  0x5ab0882eL, 0x7274, 0x4516, 0x87, 0x7d, 0x4e, 0xee, 0x99, 0xba, 0x4f, 0xd0
DEFINE_GUIDSTRUCT("5AB0882E-7274-4516-877D-4EEE99BA4FD0",
                  KSALGORITHMINSTANCE_SYSTEM_NOISE_SUPPRESS);
#define KSALGORITHMINSTANCE_SYSTEM_NOISE_SUPPRESS                              \
  DEFINE_GUIDNAMED(KSALGORITHMINSTANCE_SYSTEM_NOISE_SUPPRESS)

#define STATIC_KSALGORITHMINSTANCE_SYSTEM_AGC                                  \
  0x950e55b9L, 0x877c, 0x4c67, 0xbe, 0x8, 0xe4, 0x7b, 0x56, 0x11, 0x13, 0xa
DEFINE_GUIDSTRUCT("950E55B9-877C-4c67-BE08-E47B5611130A",
                  KSALGORITHMINSTANCE_SYSTEM_AGC);
#define KSALGORITHMINSTANCE_SYSTEM_AGC                                         \
  DEFINE_GUIDNAMED(KSALGORITHMINSTANCE_SYSTEM_AGC)

#define STATIC_KSALGORITHMINSTANCE_SYSTEM_MICROPHONE_ARRAY_PROCESSOR           \
  0xB6F5A0A0L, 0x9E61, 0x4F8C, 0x91, 0xE3, 0x76, 0xCF, 0xF, 0x3C, 0x47, 0x1F
DEFINE_GUIDSTRUCT("B6F5A0A0-9E61-4f8c-91E3-76CF0F3C471F",
                  KSALGORITHMINSTANCE_SYSTEM_MICROPHONE_ARRAY_PROCESSOR);
#define KSALGORITHMINSTANCE_SYSTEM_MICROPHONE_ARRAY_PROCESSOR                  \
  DEFINE_GUIDNAMED(KSALGORITHMINSTANCE_SYSTEM_MICROPHONE_ARRAY_PROCESSOR)

#define STATIC_KSNODETYPE_MICROPHONE_ARRAY_PROCESSOR                           \
  STATIC_KSCATEGORY_MICROPHONE_ARRAY_PROCESSOR
#define KSNODETYPE_MICROPHONE_ARRAY_PROCESSOR                                  \
  KSCATEGORY_MICROPHONE_ARRAY_PROCESSOR

#define STATIC_KSNODETYPE_DEV_SPECIFIC                                         \
  0x941C7AC0L, 0xC559, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1
DEFINE_GUIDSTRUCT("941C7AC0-C559-11D0-8A2B-00A0C9255AC1",
                  KSNODETYPE_DEV_SPECIFIC);
#define KSNODETYPE_DEV_SPECIFIC DEFINE_GUIDNAMED(KSNODETYPE_DEV_SPECIFIC)

#define STATIC_KSNODETYPE_PROLOGIC_ENCODER                                     \
  0x8074C5B2L, 0x3C66, 0x11D2, 0xB4, 0x5A, 0x30, 0x78, 0x30, 0x2C, 0x20, 0x30
DEFINE_GUIDSTRUCT("8074C5B2-3C66-11D2-B45A-3078302C2030",
                  KSNODETYPE_PROLOGIC_ENCODER);
#define KSNODETYPE_PROLOGIC_ENCODER                                            \
  DEFINE_GUIDNAMED(KSNODETYPE_PROLOGIC_ENCODER)
#define KSNODETYPE_SURROUND_ENCODER KSNODETYPE_PROLOGIC_ENCODER

#define STATIC_KSNODETYPE_PEAKMETER                                            \
  0xa085651eL, 0x5f0d, 0x4b36, 0xa8, 0x69, 0xd1, 0x95, 0xd6, 0xab, 0x4b, 0x9e
DEFINE_GUIDSTRUCT("A085651E-5F0D-4b36-A869-D195D6AB4B9E", KSNODETYPE_PEAKMETER);
#define KSNODETYPE_PEAKMETER DEFINE_GUIDNAMED(KSNODETYPE_PEAKMETER)

//===========================================================================
// Topology Node Name GUIDs for common audio nodes
#define STATIC_KSAUDFNAME_BASS                                                 \
  0x185FEDE0L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDE0-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_BASS);
#define KSAUDFNAME_BASS DEFINE_GUIDNAMED(KSAUDFNAME_BASS)

#define STATIC_KSAUDFNAME_TREBLE                                               \
  0x185FEDE1L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDE1-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_TREBLE);
#define KSAUDFNAME_TREBLE DEFINE_GUIDNAMED(KSAUDFNAME_TREBLE)

#define STATIC_KSAUDFNAME_3D_STEREO                                            \
  0x185FEDE2L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDE2-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_3D_STEREO);
#define KSAUDFNAME_3D_STEREO DEFINE_GUIDNAMED(KSAUDFNAME_3D_STEREO)

#define STATIC_KSAUDFNAME_MASTER_VOLUME                                        \
  0x185FEDE3L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDE3-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_MASTER_VOLUME);
#define KSAUDFNAME_MASTER_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_MASTER_VOLUME)

#define STATIC_KSAUDFNAME_MASTER_MUTE                                          \
  0x185FEDE4L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDE4-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_MASTER_MUTE);
#define KSAUDFNAME_MASTER_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_MASTER_MUTE)

#define STATIC_KSAUDFNAME_WAVE_VOLUME                                          \
  0x185FEDE5L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDE5-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_WAVE_VOLUME);
#define KSAUDFNAME_WAVE_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_WAVE_VOLUME)

#define STATIC_KSAUDFNAME_WAVE_MUTE                                            \
  0x185FEDE6L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDE6-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_WAVE_MUTE);
#define KSAUDFNAME_WAVE_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_WAVE_MUTE)

#define STATIC_KSAUDFNAME_MIDI_VOLUME                                          \
  0x185FEDE7L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDE7-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_MIDI_VOLUME);
#define KSAUDFNAME_MIDI_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_MIDI_VOLUME)

#define STATIC_KSAUDFNAME_MIDI_MUTE                                            \
  0x185FEDE8L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDE8-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_MIDI_MUTE);
#define KSAUDFNAME_MIDI_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_MIDI_MUTE)

#define STATIC_KSAUDFNAME_CD_VOLUME                                            \
  0x185FEDE9L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDE9-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_CD_VOLUME);
#define KSAUDFNAME_CD_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_CD_VOLUME)

#define STATIC_KSAUDFNAME_CD_MUTE                                              \
  0x185FEDEAL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDEA-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_CD_MUTE);
#define KSAUDFNAME_CD_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_CD_MUTE)

#define STATIC_KSAUDFNAME_LINE_VOLUME                                          \
  0x185FEDEBL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDEB-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_LINE_VOLUME);
#define KSAUDFNAME_LINE_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_LINE_VOLUME)

#define STATIC_KSAUDFNAME_LINE_MUTE                                            \
  0x185FEDECL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDEC-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_LINE_MUTE);
#define KSAUDFNAME_LINE_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_LINE_MUTE)

#define STATIC_KSAUDFNAME_MIC_VOLUME                                           \
  0x185FEDEDL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDED-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_MIC_VOLUME);
#define KSAUDFNAME_MIC_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_MIC_VOLUME)

#define STATIC_KSAUDFNAME_MIC_MUTE                                             \
  0x185FEDEEL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDEE-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_MIC_MUTE);
#define KSAUDFNAME_MIC_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_MIC_MUTE)

#define STATIC_KSAUDFNAME_RECORDING_SOURCE                                     \
  0x185FEDEFL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDEF-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_RECORDING_SOURCE);
#define KSAUDFNAME_RECORDING_SOURCE                                            \
  DEFINE_GUIDNAMED(KSAUDFNAME_RECORDING_SOURCE)

#define STATIC_KSAUDFNAME_PC_SPEAKER_VOLUME                                    \
  0x185FEDF0L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDF0-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_PC_SPEAKER_VOLUME);
#define KSAUDFNAME_PC_SPEAKER_VOLUME                                           \
  DEFINE_GUIDNAMED(KSAUDFNAME_PC_SPEAKER_VOLUME)

#define STATIC_KSAUDFNAME_PC_SPEAKER_MUTE                                      \
  0x185FEDF1L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDF1-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_PC_SPEAKER_MUTE);
#define KSAUDFNAME_PC_SPEAKER_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_PC_SPEAKER_MUTE)

#define STATIC_KSAUDFNAME_MIDI_IN_VOLUME                                       \
  0x185FEDF2L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDF2-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_MIDI_IN_VOLUME);
#define KSAUDFNAME_MIDI_IN_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_MIDI_IN_VOLUME)

#define STATIC_KSAUDFNAME_CD_IN_VOLUME                                         \
  0x185FEDF3L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDF3-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_CD_IN_VOLUME);
#define KSAUDFNAME_CD_IN_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_CD_IN_VOLUME)

#define STATIC_KSAUDFNAME_LINE_IN_VOLUME                                       \
  0x185FEDF4L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDF4-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_LINE_IN_VOLUME);
#define KSAUDFNAME_LINE_IN_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_LINE_IN_VOLUME)

#define STATIC_KSAUDFNAME_MIC_IN_VOLUME                                        \
  0x185FEDF5L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDF5-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_MIC_IN_VOLUME);
#define KSAUDFNAME_MIC_IN_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_MIC_IN_VOLUME)

#define STATIC_KSAUDFNAME_WAVE_IN_VOLUME                                       \
  0x185FEDF6L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDF6-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_WAVE_IN_VOLUME);
#define KSAUDFNAME_WAVE_IN_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_WAVE_IN_VOLUME)

#define STATIC_KSAUDFNAME_VOLUME_CONTROL                                       \
  0x185FEDF7L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDF7-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_VOLUME_CONTROL);
#define KSAUDFNAME_VOLUME_CONTROL DEFINE_GUIDNAMED(KSAUDFNAME_VOLUME_CONTROL)

#define STATIC_KSAUDFNAME_MIDI                                                 \
  0x185FEDF8L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDF8-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_MIDI);
#define KSAUDFNAME_MIDI DEFINE_GUIDNAMED(KSAUDFNAME_MIDI)

#define STATIC_KSAUDFNAME_LINE_IN                                              \
  0x185FEDF9L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDF9-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_LINE_IN);
#define KSAUDFNAME_LINE_IN DEFINE_GUIDNAMED(KSAUDFNAME_LINE_IN)

#define STATIC_KSAUDFNAME_RECORDING_CONTROL                                    \
  0x185FEDFAL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDFA-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_RECORDING_CONTROL);
#define KSAUDFNAME_RECORDING_CONTROL                                           \
  DEFINE_GUIDNAMED(KSAUDFNAME_RECORDING_CONTROL)

#define STATIC_KSAUDFNAME_CD_AUDIO                                             \
  0x185FEDFBL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDFB-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_CD_AUDIO);
#define KSAUDFNAME_CD_AUDIO DEFINE_GUIDNAMED(KSAUDFNAME_CD_AUDIO)

#define STATIC_KSAUDFNAME_AUX_VOLUME                                           \
  0x185FEDFCL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDFC-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_AUX_VOLUME);
#define KSAUDFNAME_AUX_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_AUX_VOLUME)

#define STATIC_KSAUDFNAME_AUX_MUTE                                             \
  0x185FEDFDL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDFD-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_AUX_MUTE);
#define KSAUDFNAME_AUX_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_AUX_MUTE)

#define STATIC_KSAUDFNAME_AUX                                                  \
  0x185FEDFEL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDFE-9905-11D1-95A9-00C04FB925D3", KSAUDFNAME_AUX);
#define KSAUDFNAME_AUX DEFINE_GUIDNAMED(KSAUDFNAME_AUX)

#define STATIC_KSAUDFNAME_PC_SPEAKER                                           \
  0x185FEDFFL, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEDFF-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_PC_SPEAKER);
#define KSAUDFNAME_PC_SPEAKER DEFINE_GUIDNAMED(KSAUDFNAME_PC_SPEAKER)

#define STATIC_KSAUDFNAME_WAVE_OUT_MIX                                         \
  0x185FEE00L, 0x9905, 0x11D1, 0x95, 0xA9, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("185FEE00-9905-11D1-95A9-00C04FB925D3",
                  KSAUDFNAME_WAVE_OUT_MIX);
#define KSAUDFNAME_WAVE_OUT_MIX DEFINE_GUIDNAMED(KSAUDFNAME_WAVE_OUT_MIX)

#define STATIC_KSAUDFNAME_MONO_OUT                                             \
  0xf9b41dc3L, 0x96e2, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("F9B41DC3-96E2-11d2-AC4C-00C04F8EFB68", KSAUDFNAME_MONO_OUT);
#define KSAUDFNAME_MONO_OUT DEFINE_GUIDNAMED(KSAUDFNAME_MONO_OUT)

#define STATIC_KSAUDFNAME_STEREO_MIX                                           \
  0xdff077L, 0x96e3, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("00DFF077-96E3-11d2-AC4C-00C04F8EFB68",
                  KSAUDFNAME_STEREO_MIX);
#define KSAUDFNAME_STEREO_MIX DEFINE_GUIDNAMED(KSAUDFNAME_STEREO_MIX)

#define STATIC_KSAUDFNAME_MONO_MIX                                             \
  0xdff078L, 0x96e3, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("00DFF078-96E3-11d2-AC4C-00C04F8EFB68", KSAUDFNAME_MONO_MIX);
#define KSAUDFNAME_MONO_MIX DEFINE_GUIDNAMED(KSAUDFNAME_MONO_MIX)

#define STATIC_KSAUDFNAME_MONO_OUT_VOLUME                                      \
  0x1ad247ebL, 0x96e3, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("1AD247EB-96E3-11d2-AC4C-00C04F8EFB68",
                  KSAUDFNAME_MONO_OUT_VOLUME);
#define KSAUDFNAME_MONO_OUT_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_MONO_OUT_VOLUME)

#define STATIC_KSAUDFNAME_MONO_OUT_MUTE                                        \
  0x1ad247ecL, 0x96e3, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("1AD247EC-96E3-11d2-AC4C-00C04F8EFB68",
                  KSAUDFNAME_MONO_OUT_MUTE);
#define KSAUDFNAME_MONO_OUT_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_MONO_OUT_MUTE)

#define STATIC_KSAUDFNAME_STEREO_MIX_VOLUME                                    \
  0x1ad247edL, 0x96e3, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("1AD247ED-96E3-11d2-AC4C-00C04F8EFB68",
                  KSAUDFNAME_STEREO_MIX_VOLUME);
#define KSAUDFNAME_STEREO_MIX_VOLUME                                           \
  DEFINE_GUIDNAMED(KSAUDFNAME_STEREO_MIX_VOLUME)

#define STATIC_KSAUDFNAME_STEREO_MIX_MUTE                                      \
  0x22b0eafdL, 0x96e3, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("22B0EAFD-96E3-11d2-AC4C-00C04F8EFB68",
                  KSAUDFNAME_STEREO_MIX_MUTE);
#define KSAUDFNAME_STEREO_MIX_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_STEREO_MIX_MUTE)

#define STATIC_KSAUDFNAME_MONO_MIX_VOLUME                                      \
  0x22b0eafeL, 0x96e3, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("22B0EAFE-96E3-11d2-AC4C-00C04F8EFB68",
                  KSAUDFNAME_MONO_MIX_VOLUME);
#define KSAUDFNAME_MONO_MIX_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_MONO_MIX_VOLUME)

#define STATIC_KSAUDFNAME_MONO_MIX_MUTE                                        \
  0x2bc31d69L, 0x96e3, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("2BC31D69-96E3-11d2-AC4C-00C04F8EFB68",
                  KSAUDFNAME_MONO_MIX_MUTE);
#define KSAUDFNAME_MONO_MIX_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_MONO_MIX_MUTE)

#define STATIC_KSAUDFNAME_MICROPHONE_BOOST                                     \
  0x2bc31d6aL, 0x96e3, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("2BC31D6A-96E3-11d2-AC4C-00C04F8EFB68",
                  KSAUDFNAME_MICROPHONE_BOOST);
#define KSAUDFNAME_MICROPHONE_BOOST                                            \
  DEFINE_GUIDNAMED(KSAUDFNAME_MICROPHONE_BOOST)

#define STATIC_KSAUDFNAME_ALTERNATE_MICROPHONE                                 \
  0x2bc31d6bL, 0x96e3, 0x11d2, 0xac, 0x4c, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("2BC31D6B-96E3-11d2-AC4C-00C04F8EFB68",
                  KSAUDFNAME_ALTERNATE_MICROPHONE);
#define KSAUDFNAME_ALTERNATE_MICROPHONE                                        \
  DEFINE_GUIDNAMED(KSAUDFNAME_ALTERNATE_MICROPHONE)

#define STATIC_KSAUDFNAME_3D_DEPTH                                             \
  0x63ff5747L, 0x991f, 0x11d2, 0xac, 0x4d, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("63FF5747-991F-11d2-AC4D-00C04F8EFB68", KSAUDFNAME_3D_DEPTH);
#define KSAUDFNAME_3D_DEPTH DEFINE_GUIDNAMED(KSAUDFNAME_3D_DEPTH)

#define STATIC_KSAUDFNAME_3D_CENTER                                            \
  0x9f0670b4L, 0x991f, 0x11d2, 0xac, 0x4d, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("9F0670B4-991F-11d2-AC4D-00C04F8EFB68", KSAUDFNAME_3D_CENTER);
#define KSAUDFNAME_3D_CENTER DEFINE_GUIDNAMED(KSAUDFNAME_3D_CENTER)

#define STATIC_KSAUDFNAME_VIDEO_VOLUME                                         \
  0x9b46e708L, 0x992a, 0x11d2, 0xac, 0x4d, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("9B46E708-992A-11d2-AC4D-00C04F8EFB68",
                  KSAUDFNAME_VIDEO_VOLUME);
#define KSAUDFNAME_VIDEO_VOLUME DEFINE_GUIDNAMED(KSAUDFNAME_VIDEO_VOLUME)

#define STATIC_KSAUDFNAME_VIDEO_MUTE                                           \
  0x9b46e709L, 0x992a, 0x11d2, 0xac, 0x4d, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("9B46E709-992A-11d2-AC4D-00C04F8EFB68",
                  KSAUDFNAME_VIDEO_MUTE);
#define KSAUDFNAME_VIDEO_MUTE DEFINE_GUIDNAMED(KSAUDFNAME_VIDEO_MUTE)

#define STATIC_KSAUDFNAME_VIDEO                                                \
  0x915daec4L, 0xa434, 0x11d2, 0xac, 0x52, 0x0, 0xc0, 0x4f, 0x8e, 0xfb, 0x68
DEFINE_GUIDSTRUCT("915DAEC4-A434-11d2-AC52-00C04F8EFB68", KSAUDFNAME_VIDEO);
#define KSAUDFNAME_VIDEO DEFINE_GUIDNAMED(KSAUDFNAME_VIDEO)

#define STATIC_KSAUDFNAME_PEAKMETER                                            \
  0x57e24340L, 0xfc5b, 0x4612, 0xa5, 0x62, 0x72, 0xb1, 0x1a, 0x29, 0xdf, 0xae
DEFINE_GUIDSTRUCT("57E24340-FC5B-4612-A562-72B11A29DFAE", KSAUDFNAME_PEAKMETER);
#define KSAUDFNAME_PEAKMETER DEFINE_GUIDNAMED(KSAUDFNAME_PEAKMETER)

// Internal topology node pin definitions

#define KSNODEPIN_STANDARD_IN 1
#define KSNODEPIN_STANDARD_OUT 0

#define KSNODEPIN_SUM_MUX_IN 1 // can be >= 1
#define KSNODEPIN_SUM_MUX_OUT 0

#define KSNODEPIN_DEMUX_IN 0
#define KSNODEPIN_DEMUX_OUT 1 // can be >= 1

#define KSNODEPIN_AEC_RENDER_IN 1
#define KSNODEPIN_AEC_RENDER_OUT 0
#define KSNODEPIN_AEC_CAPTURE_IN 2
#define KSNODEPIN_AEC_CAPTURE_OUT 3

//===========================================================================
//===========================================================================

#define STATIC_KSMETHODSETID_Wavetable                                         \
  0xDCEF31EBL, 0xD907, 0x11D0, 0x95, 0x83, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("DCEF31EB-D907-11D0-9583-00C04FB925D3",
                  KSMETHODSETID_Wavetable);
#define KSMETHODSETID_Wavetable DEFINE_GUIDNAMED(KSMETHODSETID_Wavetable)

typedef enum {
  KSMETHOD_WAVETABLE_WAVE_ALLOC,
  KSMETHOD_WAVETABLE_WAVE_FREE,
  KSMETHOD_WAVETABLE_WAVE_FIND,
  KSMETHOD_WAVETABLE_WAVE_WRITE
} KSMETHOD_WAVETABLE;

typedef struct {
  KSIDENTIFIER Identifier; // wave identifier
  ULONG Size;              // wave size
  BOOL Looped;             // wave looped flag
  ULONG LoopPoint;         // wave loop point
  BOOL InROM;              // wave InROM flag
  KSDATAFORMAT Format;     // wave format
} KSWAVETABLE_WAVE_DESC, *PKSWAVETABLE_WAVE_DESC;

//===========================================================================
//===========================================================================

/*
    Property sets and items
*/

//===========================================================================
//===========================================================================

#define STATIC_KSPROPSETID_Acoustic_Echo_Cancel                                \
  0xd7a4af8bL, 0x3dc1, 0x4902, 0x91, 0xea, 0x8a, 0x15, 0xc9, 0x0e, 0x05, 0xb2
DEFINE_GUIDSTRUCT("D7A4AF8B-3DC1-4902-91EA-8A15C90E05B2",
                  KSPROPSETID_Acoustic_Echo_Cancel);
#define KSPROPSETID_Acoustic_Echo_Cancel                                       \
  DEFINE_GUIDNAMED(KSPROPSETID_Acoustic_Echo_Cancel)

typedef enum {
  KSPROPERTY_AEC_NOISE_FILL_ENABLE = 0,
  KSPROPERTY_AEC_STATUS,
  KSPROPERTY_AEC_MODE
} KSPROPERTY_AEC;

#define AEC_STATUS_FD_HISTORY_UNINITIALIZED 0x0
#define AEC_STATUS_FD_HISTORY_CONTINUOUSLY_CONVERGED 0x1
#define AEC_STATUS_FD_HISTORY_PREVIOUSLY_DIVERGED 0x2
#define AEC_STATUS_FD_CURRENTLY_CONVERGED 0x8

#define AEC_MODE_PASS_THROUGH 0x0
#define AEC_MODE_HALF_DUPLEX 0x1
#define AEC_MODE_FULL_DUPLEX 0x2

//===========================================================================
//===========================================================================

#define STATIC_KSPROPSETID_Wave_Queued                                         \
  0x16a15b10L, 0x16f0, 0x11d0, 0xa1, 0x95, 0x00, 0x20, 0xaf, 0xd1, 0x56, 0xe4
DEFINE_GUIDSTRUCT("16a15b10-16f0-11d0-a195-0020afd156e4",
                  KSPROPSETID_Wave_Queued);
#define KSPROPSETID_Wave_Queued DEFINE_GUIDNAMED(KSPROPSETID_Wave_Queued)

#define KSPROPERTY_WAVE_QUEUED_POSITION 0x00000001

#define STATIC_KSMETHODSETID_Wave_Queued                                       \
  0x7432c160L, 0x8827, 0x11cf, 0xa1, 0x02, 0x00, 0x20, 0xaf, 0xd1, 0x56, 0xe4
DEFINE_GUIDSTRUCT("7432c160-8827-11cf-a102-0020afd156e4",
                  KSMETHODSETID_Wave_Queued);
#define KSMETHODSETID_Wave_Queued DEFINE_GUIDNAMED(KSMETHODSETID_Wave_Queued)

#define KSMETHOD_WAVE_QUEUED_BREAKLOOP 0x00000001

#define STATIC_KSPROPSETID_Wave                                                \
  0x924e54b0L, 0x630f, 0x11cf, 0xad, 0xa7, 0x08, 0x00, 0x3e, 0x30, 0x49, 0x4a
DEFINE_GUIDSTRUCT("924e54b0-630f-11cf-ada7-08003e30494a", KSPROPSETID_Wave);
#define KSPROPSETID_Wave DEFINE_GUIDNAMED(KSPROPSETID_Wave)

typedef enum {
  KSPROPERTY_WAVE_COMPATIBLE_CAPABILITIES,
  KSPROPERTY_WAVE_INPUT_CAPABILITIES,
  KSPROPERTY_WAVE_OUTPUT_CAPABILITIES,
  KSPROPERTY_WAVE_BUFFER,
  KSPROPERTY_WAVE_FREQUENCY,
  KSPROPERTY_WAVE_VOLUME,
  KSPROPERTY_WAVE_PAN
} KSPROPERTY_WAVE;

typedef struct {
  ULONG ulDeviceType;
} KSWAVE_COMPATCAPS, *PKSWAVE_COMPATCAPS;

#define KSWAVE_COMPATCAPS_INPUT 0x00000000
#define KSWAVE_COMPATCAPS_OUTPUT 0x00000001

typedef struct {
  ULONG MaximumChannelsPerConnection;
  ULONG MinimumBitsPerSample;
  ULONG MaximumBitsPerSample;
  ULONG MinimumSampleFrequency;
  ULONG MaximumSampleFrequency;
  ULONG TotalConnections;
  ULONG ActiveConnections;
} KSWAVE_INPUT_CAPABILITIES, *PKSWAVE_INPUT_CAPABILITIES;

typedef struct {
  ULONG MaximumChannelsPerConnection;
  ULONG MinimumBitsPerSample;
  ULONG MaximumBitsPerSample;
  ULONG MinimumSampleFrequency;
  ULONG MaximumSampleFrequency;
  ULONG TotalConnections;
  ULONG StaticConnections;
  ULONG StreamingConnections;
  ULONG ActiveConnections;
  ULONG ActiveStaticConnections;
  ULONG ActiveStreamingConnections;
  ULONG Total3DConnections;
  ULONG Static3DConnections;
  ULONG Streaming3DConnections;
  ULONG Active3DConnections;
  ULONG ActiveStatic3DConnections;
  ULONG ActiveStreaming3DConnections;
  ULONG TotalSampleMemory;
  ULONG FreeSampleMemory;
  ULONG LargestFreeContiguousSampleMemory;
} KSWAVE_OUTPUT_CAPABILITIES, *PKSWAVE_OUTPUT_CAPABILITIES;

typedef struct {
  LONG LeftAttenuation;
  LONG RightAttenuation;
} KSWAVE_VOLUME, *PKSWAVE_VOLUME;

#define KSWAVE_BUFFER_ATTRIBUTEF_LOOPING 0x00000001
#define KSWAVE_BUFFER_ATTRIBUTEF_STATIC 0x00000002

typedef struct {
  ULONG Attributes;
  ULONG BufferSize;
  PVOID BufferAddress;
} KSWAVE_BUFFER, *PKSWAVE_BUFFER;

//===========================================================================
//===========================================================================

#define STATIC_KSMUSIC_TECHNOLOGY_PORT                                         \
  0x86C92E60L, 0x62E8, 0x11CF, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("86C92E60-62E8-11CF-A5D6-28DB04C10000",
                  KSMUSIC_TECHNOLOGY_PORT);
#define KSMUSIC_TECHNOLOGY_PORT DEFINE_GUIDNAMED(KSMUSIC_TECHNOLOGY_PORT)

#define STATIC_KSMUSIC_TECHNOLOGY_SQSYNTH                                      \
  0x0ECF4380L, 0x62E9, 0x11CF, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("0ECF4380-62E9-11CF-A5D6-28DB04C10000",
                  KSMUSIC_TECHNOLOGY_SQSYNTH);
#define KSMUSIC_TECHNOLOGY_SQSYNTH DEFINE_GUIDNAMED(KSMUSIC_TECHNOLOGY_SQSYNTH)

#define STATIC_KSMUSIC_TECHNOLOGY_FMSYNTH                                      \
  0x252C5C80L, 0x62E9, 0x11CF, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("252C5C80-62E9-11CF-A5D6-28DB04C10000",
                  KSMUSIC_TECHNOLOGY_FMSYNTH);
#define KSMUSIC_TECHNOLOGY_FMSYNTH DEFINE_GUIDNAMED(KSMUSIC_TECHNOLOGY_FMSYNTH)

#define STATIC_KSMUSIC_TECHNOLOGY_WAVETABLE                                    \
  0x394EC7C0L, 0x62E9, 0x11CF, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("394EC7C0-62E9-11CF-A5D6-28DB04C10000",
                  KSMUSIC_TECHNOLOGY_WAVETABLE);
#define KSMUSIC_TECHNOLOGY_WAVETABLE                                           \
  DEFINE_GUIDNAMED(KSMUSIC_TECHNOLOGY_WAVETABLE)

#define STATIC_KSMUSIC_TECHNOLOGY_SWSYNTH                                      \
  0x37407736L, 0x3620, 0x11D1, 0x85, 0xD3, 0x00, 0x00, 0xF8, 0x75, 0x43, 0x80
DEFINE_GUIDSTRUCT("37407736-3620-11D1-85D3-0000F8754380",
                  KSMUSIC_TECHNOLOGY_SWSYNTH);
#define KSMUSIC_TECHNOLOGY_SWSYNTH DEFINE_GUIDNAMED(KSMUSIC_TECHNOLOGY_SWSYNTH)

#define STATIC_KSPROPSETID_WaveTable                                           \
  0x8539E660L, 0x62E9, 0x11CF, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("8539E660-62E9-11CF-A5D6-28DB04C10000",
                  KSPROPSETID_WaveTable);
#define KSPROPSETID_WaveTable DEFINE_GUIDNAMED(KSPROPSETID_WaveTable)

typedef enum {
  KSPROPERTY_WAVETABLE_LOAD_SAMPLE,
  KSPROPERTY_WAVETABLE_UNLOAD_SAMPLE,
  KSPROPERTY_WAVETABLE_MEMORY,
  KSPROPERTY_WAVETABLE_VERSION
} KSPROPERTY_WAVETABLE;

typedef struct {
  KSDATARANGE DataRange;
  GUID Technology;
  ULONG Channels;
  ULONG Notes;
  ULONG ChannelMask;
} KSDATARANGE_MUSIC, *PKSDATARANGE_MUSIC;

//===========================================================================

#define STATIC_KSEVENTSETID_Cyclic                                             \
  0x142C1AC0L, 0x072A, 0x11D0, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("142C1AC0-072A-11D0-A5D6-28DB04C10000", KSEVENTSETID_Cyclic);
#define KSEVENTSETID_Cyclic DEFINE_GUIDNAMED(KSEVENTSETID_Cyclic)

typedef enum {
  KSEVENT_CYCLIC_TIME_INTERVAL,
} KSEVENT_CYCLIC_TIME;

#define STATIC_KSPROPSETID_Cyclic                                              \
  0x3FFEAEA0L, 0x2BEE, 0x11CF, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("3FFEAEA0-2BEE-11CF-A5D6-28DB04C10000", KSPROPSETID_Cyclic);
#define KSPROPSETID_Cyclic DEFINE_GUIDNAMED(KSPROPSETID_Cyclic)

typedef enum {
  KSPROPERTY_CYCLIC_POSITION,
} KSPROPERTY_CYCLIC;

//===========================================================================
#define STATIC_KSEVENTSETID_AudioControlChange                                 \
  0xE85E9698L, 0xFA2F, 0x11D1, 0x95, 0xBD, 0x00, 0xC0, 0x4F, 0xB9, 0x25, 0xD3
DEFINE_GUIDSTRUCT("E85E9698-FA2F-11D1-95BD-00C04FB925D3",
                  KSEVENTSETID_AudioControlChange);
#define KSEVENTSETID_AudioControlChange                                        \
  DEFINE_GUIDNAMED(KSEVENTSETID_AudioControlChange)

typedef enum {
  KSEVENT_CONTROL_CHANGE,
} KSEVENT_AUDIO_CONTROL_CHANGE;

//===========================================================================

#define STATIC_KSEVENTSETID_LoopedStreaming                                    \
  0x4682B940L, 0xC6EF, 0x11D0, 0x96, 0xD8, 0x00, 0xAA, 0x00, 0x51, 0xE5, 0x1D
DEFINE_GUIDSTRUCT("4682B940-C6EF-11D0-96D8-00AA0051E51D",
                  KSEVENTSETID_LoopedStreaming);
#define KSEVENTSETID_LoopedStreaming                                           \
  DEFINE_GUIDNAMED(KSEVENTSETID_LoopedStreaming)

typedef enum {
  KSEVENT_LOOPEDSTREAMING_POSITION,
} KSEVENT_LOOPEDSTREAMING;

typedef struct {
  KSEVENTDATA KsEventData;
#if defined(_NTDDK_)
  ULONGLONG Position;
#else  // !_NTDDK_
  DWORDLONG Position;
#endif // !_NTDDK_
} LOOPEDSTREAMING_POSITION_EVENT_DATA, *PLOOPEDSTREAMING_POSITION_EVENT_DATA;

// @@BEGIN_DDKSPLIT
//===========================================================================
#define STATIC_KSEVENTSETID_Sysaudio                                           \
  0x04800320L, 0x4491, 0x11D1, 0xA0, 0x50, 0x40, 0x57, 0x05, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("04800320-4491-11D1-A050-405705C10000",
                  KSEVENTSETID_Sysaudio);
#define KSEVENTSETID_Sysaudio DEFINE_GUIDNAMED(KSEVENTSETID_Sysaudio)

typedef enum {
  KSEVENT_SYSAUDIO_ADDREMOVE_DEVICE,
  KSEVENT_SYSAUDIO_CHANGE_DEVICE
} KSEVENT_SYSAUDIO;
// @@END_DDKSPLIT

//===========================================================================
#define STATIC_KSPROPSETID_Sysaudio                                            \
  0xCBE3FAA0L, 0xCC75, 0x11D0, 0xB4, 0x65, 0x00, 0x00, 0x1A, 0x18, 0x18, 0xE6
DEFINE_GUIDSTRUCT("CBE3FAA0-CC75-11D0-B465-00001A1818E6", KSPROPSETID_Sysaudio);
#define KSPROPSETID_Sysaudio DEFINE_GUIDNAMED(KSPROPSETID_Sysaudio)

typedef enum {
  KSPROPERTY_SYSAUDIO_DEVICE_COUNT = 1,
  KSPROPERTY_SYSAUDIO_DEVICE_FRIENDLY_NAME = 2,
  KSPROPERTY_SYSAUDIO_DEVICE_INSTANCE = 3,
  KSPROPERTY_SYSAUDIO_DEVICE_INTERFACE_NAME = 4,
  KSPROPERTY_SYSAUDIO_SELECT_GRAPH = 5,
  KSPROPERTY_SYSAUDIO_CREATE_VIRTUAL_SOURCE = 6,
  KSPROPERTY_SYSAUDIO_DEVICE_DEFAULT = 7,
  // @@BEGIN_DDKSPLIT
  KSPROPERTY_SYSAUDIO_ALWAYS_CREATE_VIRTUAL_SOURCE = 8,
  KSPROPERTY_SYSAUDIO_ADDREMOVE_LOCK = 9,
  KSPROPERTY_SYSAUDIO_ADDREMOVE_UNLOCK = 10,
  KSPROPERTY_SYSAUDIO_RENDER_PIN_INSTANCES = 11,
  KSPROPERTY_SYSAUDIO_RENDER_CONNECTION_INDEX = 12,
  KSPROPERTY_SYSAUDIO_CREATE_VIRTUAL_SOURCE_ONLY = 13,
  // @@END_DDKSPLIT
  KSPROPERTY_SYSAUDIO_INSTANCE_INFO = 14,
  // @@BEGIN_DDKSPLIT
  KSPROPERTY_SYSAUDIO_PREFERRED_DEVICE = 15,
  // @@END_DDKSPLIT
  KSPROPERTY_SYSAUDIO_COMPONENT_ID = 16,
  // @@BEGIN_DDKSPLIT
  KSPROPERTY_SYSAUDIO_ADDREMOVE_GFX = 17
  // @@END_DDKSPLIT
} KSPROPERTY_SYSAUDIO;

typedef struct {
  KSPROPERTY Property;
  GUID PinCategory;
  GUID PinName;
} SYSAUDIO_CREATE_VIRTUAL_SOURCE, *PSYSAUDIO_CREATE_VIRTUAL_SOURCE;

// @@BEGIN_DDKSPLIT
typedef struct {
  BOOL Enable;
  HANDLE hGfx;
  ULONG ulOrder; // Order of the GFX
  ULONG ulType;  // Type of the GFX
  ULONG ulFlags;
  ULONG ulDeviceNameOffset;   // DeviceInterface on which this GFX needs to be
                              // attached
  ULONG ulFriendlyNameOffset; // Friendly name of the GFX
} SYSAUDIO_GFX, *PSYSAUDIO_GFX;

#define GFX_DEVICETYPE_RENDER 1
#define GFX_DEVICETYPE_CAPTURE 2
// @@END_DDKSPLIT

typedef struct {
  KSPROPERTY Property;
  ULONG PinId;
  ULONG NodeId;
  ULONG Flags;
  ULONG Reserved;
} SYSAUDIO_SELECT_GRAPH, *PSYSAUDIO_SELECT_GRAPH;

typedef struct {
  KSPROPERTY Property;
  ULONG Flags;
  ULONG DeviceNumber;
} SYSAUDIO_INSTANCE_INFO, *PSYSAUDIO_INSTANCE_INFO;

#define SYSAUDIO_FLAGS_DONT_COMBINE_PINS 0x00000001

// @@BEGIN_DDKSPLIT
typedef struct {
  KSPROPERTY Property;
  ULONG Flags;
  ULONG Index; // KSPROPERTY_SYSAUDIO_DEFAULT_TYPE
} SYSAUDIO_PREFERRED_DEVICE, *PSYSAUDIO_PREFERRED_DEVICE;

#define SYSAUDIO_FLAGS_CLEAR_PREFERRED 0x00000002
// @@END_DDKSPLIT

#define STATIC_KSPROPSETID_Sysaudio_Pin                                        \
  0xA3A53220L, 0xC6E4, 0x11D0, 0xB4, 0x65, 0x00, 0x00, 0x1A, 0x18, 0x18, 0xE6
DEFINE_GUIDSTRUCT("A3A53220-C6E4-11D0-B465-00001A1818E6",
                  KSPROPSETID_Sysaudio_Pin);
#define KSPROPSETID_Sysaudio_Pin DEFINE_GUIDNAMED(KSPROPSETID_Sysaudio_Pin)

typedef enum {
  // @@BEGIN_DDKSPLIT
  KSPROPERTY_SYSAUDIO_TOPOLOGY_CONNECTION_INDEX = 0,
  // @@END_DDKSPLIT
  KSPROPERTY_SYSAUDIO_ATTACH_VIRTUAL_SOURCE = 1,
  // @@BEGIN_DDKSPLIT
  KSPROPERTY_SYSAUDIO_PIN_VOLUME_NODE = 2
  // @@END_DDKSPLIT
} KSPROPERTY_SYSAUDIO_PIN;

typedef struct {
  KSPROPERTY Property;
  ULONG MixerPinId;
  ULONG Reserved;
} SYSAUDIO_ATTACH_VIRTUAL_SOURCE, *PSYSAUDIO_ATTACH_VIRTUAL_SOURCE;

//===========================================================================
typedef struct {
  KSPROPERTY Property;
  ULONG NodeId;
  ULONG Reserved;
} KSNODEPROPERTY, *PKSNODEPROPERTY;

typedef struct {
  KSNODEPROPERTY NodeProperty;
  LONG Channel; // value to get or set
  ULONG Reserved;
} KSNODEPROPERTY_AUDIO_CHANNEL, *PKSNODEPROPERTY_AUDIO_CHANNEL;

typedef struct {
  KSNODEPROPERTY NodeProperty;
  ULONG DevSpecificId;
  ULONG DeviceInfo;
  ULONG Length;
} KSNODEPROPERTY_AUDIO_DEV_SPECIFIC, *PKSNODEPROPERTY_AUDIO_DEV_SPECIFIC;

typedef struct {
  KSNODEPROPERTY NodeProperty;
  PVOID ListenerId;
#ifndef _WIN64
  ULONG Reserved;
#endif // _WIN64
} KSNODEPROPERTY_AUDIO_3D_LISTENER, *PKSNODEPROPERTY_AUDIO_3D_LISTENER;

typedef struct {
  KSNODEPROPERTY NodeProperty;
  PVOID AppContext;
  ULONG Length;
#ifndef _WIN64
  ULONG Reserved;
#endif // _WIN64
} KSNODEPROPERTY_AUDIO_PROPERTY, *PKSNODEPROPERTY_AUDIO_PROPERTY;

//===========================================================================
// {79A9312E-59AE-43b0-A350-8B05284CAB24}
#define STATIC_KSPROPSETID_AudioGfx                                            \
  0x79a9312eL, 0x59ae, 0x43b0, 0xa3, 0x50, 0x8b, 0x5, 0x28, 0x4c, 0xab, 0x24
DEFINE_GUIDSTRUCT("79A9312E-59AE-43b0-A350-8B05284CAB24", KSPROPSETID_AudioGfx);
#define KSPROPSETID_AudioGfx DEFINE_GUIDNAMED(KSPROPSETID_AudioGfx)

typedef enum {
  KSPROPERTY_AUDIOGFX_RENDERTARGETDEVICEID,
  KSPROPERTY_AUDIOGFX_CAPTURETARGETDEVICEID
} KSPROPERTY_AUDIOGFX;

//===========================================================================

#define STATIC_KSPROPSETID_Linear                                              \
  0x5A2FFE80L, 0x16B9, 0x11D0, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("5A2FFE80-16B9-11D0-A5D6-28DB04C10000", KSPROPSETID_Linear);
#define KSPROPSETID_Linear DEFINE_GUIDNAMED(KSPROPSETID_Linear)

typedef enum {
  KSPROPERTY_LINEAR_POSITION,
} KSPROPERTY_LINEAR;

//===========================================================================

//
// Midi definitions
//

/*
    Formats
*/

#define STATIC_KSDATAFORMAT_TYPE_MUSIC                                         \
  0xE725D360L, 0x62CC, 0x11CF, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("E725D360-62CC-11CF-A5D6-28DB04C10000",
                  KSDATAFORMAT_TYPE_MUSIC);
#define KSDATAFORMAT_TYPE_MUSIC DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_MUSIC)

// 'mids' == MEDIATYPE_Midi
#define STATIC_KSDATAFORMAT_TYPE_MIDI                                          \
  0x7364696DL, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
DEFINE_GUIDSTRUCT("7364696D-0000-0010-8000-00aa00389b71",
                  KSDATAFORMAT_TYPE_MIDI);
#define KSDATAFORMAT_TYPE_MIDI DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_MIDI)

#define STATIC_KSDATAFORMAT_SUBTYPE_MIDI                                       \
  0x1D262760L, 0xE957, 0x11CF, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("1D262760-E957-11CF-A5D6-28DB04C10000",
                  KSDATAFORMAT_SUBTYPE_MIDI);
#define KSDATAFORMAT_SUBTYPE_MIDI DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_MIDI)

#define STATIC_KSDATAFORMAT_SUBTYPE_MIDI_BUS                                   \
  0x2CA15FA0L, 0x6CFE, 0x11CF, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00
DEFINE_GUIDSTRUCT("2CA15FA0-6CFE-11CF-A5D6-28DB04C10000",
                  KSDATAFORMAT_SUBTYPE_MIDI_BUS);
#define KSDATAFORMAT_SUBTYPE_MIDI_BUS                                          \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_MIDI_BUS)

#define STATIC_KSDATAFORMAT_SUBTYPE_RIFFMIDI                                   \
  0x4995DAF0L, 0x9EE6, 0x11D0, 0xA4, 0x0E, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("4995DAF0-9EE6-11D0-A40E-00A0C9223196",
                  KSDATAFORMAT_SUBTYPE_RIFFMIDI);
#define KSDATAFORMAT_SUBTYPE_RIFFMIDI                                          \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_RIFFMIDI)

/*
    KSDATAFORMAT_SUBTYPE_DIRECTMUSIC
    see DMusicKS.h
*/

// WARNING! This structure MUST be dword aligned
// regardless of the number of data bytes.

typedef struct {
  ULONG TimeDeltaMs; // Delta Milliseconds from the previous midiformat
                     // in the packet. The first midiformat in the packet
                     // is a delta from the PTS in the KSSTREAM_HEADER.
  ULONG ByteCount;   // Number of bytes of data that follow this struct.
} KSMUSICFORMAT, *PKSMUSICFORMAT;

//
// This entire set of MPEG Standard/Dialect Guids are obsolete. Do not use them.
//
//====================================================================================================
//====================================================================================================
// The following official MPEG Formats, Subtypes and Specifiers are listed as
// required or optional These official MPEG GUIDs are the preferred method of
// supporting MPEG/AC-3 media types in new code. Older MPEG GUIDs should also be
// supported for compatibilty, but these new modes are still required.
//====================================================================================================
//====================================================================================================

/*
This is a summary of what media types/specifiers will be required for all
DVD+DSS+DVB+DTV MPEG decoders. These media types are what the decoder driver
must accept, hardware support for all of these media types may or may not
actually be provided by the decoder natively.  These media types are intended to
define the "officially" supported MPEG/AC-3 media types that all WHQL certified
decoders must implement.  This specifically includes driver and/or hardware
support for all the required standards and dialects.

All MPEG video decoders must support all of the MPEG video modes shown as
[required] below. All MPEG audio decoders must support all of the MPEG audio
modes shown as [required] below. All AC-3 audio decoders must support all of the
AC-3 audio modes shown as [required] below. The line items shown as [optional]
need not be implemented, but are possible formats that might be implemented.

Note that the input/output pin formats are defined by 2 or 3 GUIDs: TYPE,
SUBTYPE, and maybe SPECIFIER. The specifiers are included if the data format is
a "dialect" that needs to be differentiated during decoding. The decoder MUST be
prepared to deal with ALL requests for _required_ "Standard" formats OR
_required_ "Dialects".

STATIC_KSDATAFORMAT_TYPE_STANDARD_ELEMENTARY_STREAM         [required]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_VIDEO            [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_VIDEO           [optional]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_AUDIO            [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_AUDIO           [optional]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_VIDEO            [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_VIDEO           [required]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_AUDIO            [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_AUDIO           [optional]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_AC3_AUDIO              [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_AC3_AUDIO             [optional]
STATIC_KSDATAFORMAT_TYPE_STANDARD_PES_PACKET                [required]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_VIDEO            [optional]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_VIDEO           [optional]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_AUDIO            [optional]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_AUDIO           [optional]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_VIDEO            [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_VIDEO           [required]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_AUDIO            [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_AUDIO           [required]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_AC3_AUDIO              [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_AC3_AUDIO             [optional]
STATIC_KSDATAFORMAT_TYPE_STANDARD_PACK_HEADER               [required]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_VIDEO            [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_VIDEO           [required]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_AUDIO            [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_AUDIO           [optional]
    STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_AC3_AUDIO              [required]
        STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_AC3_AUDIO             [optional]

Note that the SPECIFIER GUIDs normally identify particular versions of MPEG such
as DSS and DVD. This approach was taken to minimize the number of
DSS/DVB/DVD/DTV etc. media SUBTYPES. These specifiers are currently required to
disambiguate MPEG syntax _parsing_ by the decoder using alternate parsing
routines or downloadable firmware or hardware decode settings.

In the future these specifiers will be extended to cover new KS MPEG flavors
such as DVB and DTV. Thus, the optional specifiers will be subject to
clarification and/or definition as they are needed.

Important note: Per the ITU MPEG specs, MPEG 2 media may contain pure MPEG 1
syntax and any "MPEG 2" PES packets may actually contain MPEG 1 payloads and
MPEG 1 syntax.  Some MPEG broadcasts can revert from MPEG2 to MPEG1 format data
at their discretion, without warning.

CAUTION: Decoders MUST attempt to process MPEG data AS SOON AS POSSIBLE after
reception. In particular, elementary MPEG or MPEG PES packet streams should not
be aggregated into DVD "pack headers" internally before submission to the codec
hardware if AT ALL POSSIBLE.  The reason is that mpeg data may need to be
processed immediately but there may be no additional MPEG data forthcoming to
fill up the PES packet OR DVD "pack" in a timely fashion.  This is particularly
true of MPEG dialects that utilize "repeat field signally" to reuse the last
decoded MPEG video field.

*/

/////////////////////////////////////////////////////////////////////////
// The major data type GUIDs that define the data packet encapsulation //
/////////////////////////////////////////////////////////////////////////

// STATIC_KSDATAFORMAT_TYPE_STANDARD_ELEMENTARY_STREAM
#define STATIC_KSDATAFORMAT_TYPE_STANDARD_ELEMENTARY_STREAM                    \
  0x36523b11L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B11-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_TYPE_STANDARD_ELEMENTARY_STREAM);
#define KSDATAFORMAT_TYPE_STANDARD_ELEMENTARY_STREAM                           \
  DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_STANDARD_ELEMENTARY_STREAM)

// STATIC_KSDATAFORMAT_TYPE_STANDARD_PES_PACKET
#define STATIC_KSDATAFORMAT_TYPE_STANDARD_PES_PACKET                           \
  0x36523b12L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B12-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_TYPE_STANDARD_PES_PACKET);
#define KSDATAFORMAT_TYPE_STANDARD_PES_PACKET                                  \
  DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_STANDARD_PES_PACKET)

// STATIC_KSDATAFORMAT_TYPE_STANDARD_PACK_HEADER
#define STATIC_KSDATAFORMAT_TYPE_STANDARD_PACK_HEADER                          \
  0x36523b13L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B13-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_TYPE_STANDARD_PACK_HEADER);
#define KSDATAFORMAT_TYPE_STANDARD_PACK_HEADER                                 \
  DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_STANDARD_PACK_HEADER)

///////////////////////////////////////////////////////////////////////////////
// The minor data subtype GUIDs that define the exact class of the data type.//
///////////////////////////////////////////////////////////////////////////////

// STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_VIDEO
#define STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_VIDEO                       \
  0x36523b21L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B21-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_VIDEO);
#define KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_VIDEO                              \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_VIDEO)

// STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_AUDIO
#define STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_AUDIO                       \
  0x36523b22L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B22-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_AUDIO);
#define KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_AUDIO                              \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_AUDIO)

// STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_VIDEO
#define STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_VIDEO                       \
  0x36523b23L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B23-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_VIDEO);
#define KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_VIDEO                              \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_VIDEO)

// STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_AUDIO
#define STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_AUDIO                       \
  0x36523b24L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B24-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_AUDIO);
#define KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_AUDIO                              \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_AUDIO)

// STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_AC3_AUDIO
#define STATIC_KSDATAFORMAT_SUBTYPE_STANDARD_AC3_AUDIO                         \
  0x36523b25L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B25-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_SUBTYPE_STANDARD_AC3_AUDIO);
#define KSDATAFORMAT_SUBTYPE_STANDARD_AC3_AUDIO                                \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_STANDARD_AC3_AUDIO)

///////////////////////////////////////////////////////////////////////////////
// The low-level specifier GUIDs that define the flavor of the data subtype. //
// Some SUBTYPES, notably MPEG2_VIDEO, MPEG2_AUDIO have different dialects.  //
// These specifiers are intended to be accompanied by a specifier structure. //
///////////////////////////////////////////////////////////////////////////////

// STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_VIDEO
#define STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_VIDEO                      \
  0x36523b31L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B31-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_VIDEO);
#define KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_VIDEO                             \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_VIDEO)

// STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_AUDIO
#define STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_AUDIO                      \
  0x36523b32L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B32-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_AUDIO);
#define KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_AUDIO                             \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_DIALECT_MPEG1_AUDIO)

// STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_VIDEO    Associated with
// KS_MPEGVIDEOINFO2 defined later
#define STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_VIDEO                      \
  0x36523b33L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B33-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_VIDEO);
#define KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_VIDEO                             \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_VIDEO)

// STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_AUDIO    Associated with
// KS_MPEGAUDIOINFO defined later
#define STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_AUDIO                      \
  0x36523b34L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B34-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_AUDIO);
#define KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_AUDIO                             \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_DIALECT_MPEG2_AUDIO)

// STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_AC3_AUDIO
#define STATIC_KSDATAFORMAT_SPECIFIER_DIALECT_AC3_AUDIO                        \
  0x36523b35L, 0x8ee5, 0x11d1, 0x8c, 0xa3, 0x00, 0x60, 0xb0, 0x57, 0x66, 0x4a
DEFINE_GUIDSTRUCT("36523B35-8EE5-11d1-8CA3-0060B057664A",
                  KSDATAFORMAT_SPECIFIER_DIALECT_AC3_AUDIO);
#define KSDATAFORMAT_SPECIFIER_DIALECT_AC3_AUDIO                               \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_DIALECT_AC3_AUDIO)

//====================================================================================================
//====================================================================================================
//                              *** COMPATIBILITY WARNING ***
// The *following* older DSS, MPEG, DVD & AC-3 GUID definitions are retained for
// backward compability. These MPEG GUIDs should also be supported for
// compatibilty, but the above newer modes are still required.
//====================================================================================================
//====================================================================================================

//
// DSS definitions
//

#define STATIC_KSDATAFORMAT_SUBTYPE_DSS_VIDEO                                  \
  0xa0af4f81L, 0xe163, 0x11d0, 0xba, 0xd9, 0x00, 0x60, 0x97, 0x44, 0x11, 0x1a
DEFINE_GUIDSTRUCT("a0af4f81-e163-11d0-bad9-00609744111a",
                  KSDATAFORMAT_SUBTYPE_DSS_VIDEO);
#define KSDATAFORMAT_SUBTYPE_DSS_VIDEO                                         \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_DSS_VIDEO)

#define STATIC_KSDATAFORMAT_SUBTYPE_DSS_AUDIO                                  \
  0xa0af4f82L, 0xe163, 0x11d0, 0xba, 0xd9, 0x00, 0x60, 0x97, 0x44, 0x11, 0x1a
DEFINE_GUIDSTRUCT("a0af4f82-e163-11d0-bad9-00609744111a",
                  KSDATAFORMAT_SUBTYPE_DSS_AUDIO);
#define KSDATAFORMAT_SUBTYPE_DSS_AUDIO                                         \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_DSS_AUDIO)

//
// End of obsolete MPEG definitions.
//

//
// mpeg 1 definitions
//
#define STATIC_KSDATAFORMAT_SUBTYPE_MPEG1Packet                                \
  0xe436eb80, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70
DEFINE_GUIDSTRUCT("e436eb80-524f-11ce-9F53-0020af0ba770",
                  KSDATAFORMAT_SUBTYPE_MPEG1Packet);
#define KSDATAFORMAT_SUBTYPE_MPEG1Packet                                       \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_MPEG1Packet)

#define STATIC_KSDATAFORMAT_SUBTYPE_MPEG1Payload                               \
  0xe436eb81, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70
DEFINE_GUIDSTRUCT("e436eb81-524f-11ce-9F53-0020af0ba770",
                  KSDATAFORMAT_SUBTYPE_MPEG1Payload);
#define KSDATAFORMAT_SUBTYPE_MPEG1Payload                                      \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_MPEG1Payload)

// MEDIASUBTYPE_MPEG1Video
#define STATIC_KSDATAFORMAT_SUBTYPE_MPEG1Video                                 \
  0xe436eb86, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70
DEFINE_GUIDSTRUCT("e436eb86-524f-11ce-9f53-0020af0ba770",
                  KSDATAFORMAT_SUBTYPE_MPEG1Video);
#define KSDATAFORMAT_SUBTYPE_MPEG1Video                                        \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_MPEG1Video)

// FORMAT_MPEGVideo
#define STATIC_KSDATAFORMAT_SPECIFIER_MPEG1_VIDEO                              \
  0x05589f82L, 0xc356, 0x11ce, 0xbf, 0x01, 0x00, 0xaa, 0x00, 0x55, 0x59, 0x5a
DEFINE_GUIDSTRUCT("05589f82-c356-11ce-bf01-00aa0055595a",
                  KSDATAFORMAT_SPECIFIER_MPEG1_VIDEO);
#define KSDATAFORMAT_SPECIFIER_MPEG1_VIDEO                                     \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_MPEG1_VIDEO)

//
// mpeg 2 definitions
//
#define STATIC_KSDATAFORMAT_TYPE_MPEG2_PES                                     \
  0xe06d8020L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d8020-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_TYPE_MPEG2_PES);
#define KSDATAFORMAT_TYPE_MPEG2_PES                                            \
  DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_MPEG2_PES)

#define STATIC_KSDATAFORMAT_TYPE_MPEG2_PROGRAM                                 \
  0xe06d8022L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d8022-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_TYPE_MPEG2_PROGRAM);
#define KSDATAFORMAT_TYPE_MPEG2_PROGRAM                                        \
  DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_MPEG2_PROGRAM)

#define STATIC_KSDATAFORMAT_TYPE_MPEG2_TRANSPORT                               \
  0xe06d8023L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d8023-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_TYPE_MPEG2_TRANSPORT);
#define KSDATAFORMAT_TYPE_MPEG2_TRANSPORT                                      \
  DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_MPEG2_TRANSPORT)

#define STATIC_KSDATAFORMAT_SUBTYPE_MPEG2_VIDEO                                \
  0xe06d8026L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d8026-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SUBTYPE_MPEG2_VIDEO);
#define KSDATAFORMAT_SUBTYPE_MPEG2_VIDEO                                       \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_MPEG2_VIDEO)

// use MPEGVIDEOINFO2 (defined below) with KSDATAFORMAT_SPECIFIER_MPEG2_VIDEO
#define STATIC_KSDATAFORMAT_SPECIFIER_MPEG2_VIDEO                              \
  0xe06d80e3L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d80e3-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SPECIFIER_MPEG2_VIDEO);
#define KSDATAFORMAT_SPECIFIER_MPEG2_VIDEO                                     \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_MPEG2_VIDEO)

//
// Mpeg2 video properties
//

#define STATIC_KSPROPSETID_Mpeg2Vid                                            \
  0xC8E11B60L, 0x0CC9, 0x11D0, 0xBD, 0x69, 0x00, 0x35, 0x05, 0xC1, 0x03, 0xA9
DEFINE_GUIDSTRUCT("C8E11B60-0CC9-11D0-BD69-003505C103A9", KSPROPSETID_Mpeg2Vid);
#define KSPROPSETID_Mpeg2Vid DEFINE_GUIDNAMED(KSPROPSETID_Mpeg2Vid)

typedef enum {
  KSPROPERTY_MPEG2VID_MODES,        // available output modes of decoder
  KSPROPERTY_MPEG2VID_CUR_MODE,     // current mode of the decoder
  KSPROPERTY_MPEG2VID_4_3_RECT,     // output coordinates for 4:3 source
  KSPROPERTY_MPEG2VID_16_9_RECT,    // output coordinates for 16:9 source
  KSPROPERTY_MPEG2VID_16_9_PANSCAN, // pan and scan vectors
} KSPROPERTY_MPEG2VID;

//
// bit field definitions for MPEG2 VIDEO mode
//

#define KSMPEGVIDMODE_PANSCAN 0x0001
#define KSMPEGVIDMODE_LTRBOX 0x0002
#define KSMPEGVIDMODE_SCALE 0x0004

//
// rectangle definitions for the 4/3 and 16/9 cropping properties of
// the MPEG2Video decoder
//

typedef struct _KSMPEGVID_RECT {
  ULONG StartX;
  ULONG StartY;
  ULONG EndX;
  ULONG EndY;
} KSMPEGVID_RECT, *PKSMPEGVID_RECT;

//
// Params for pan / scan
//

//
// MPEG2 Audio definition
//

#define STATIC_KSDATAFORMAT_SUBTYPE_MPEG2_AUDIO                                \
  0xe06d802bL, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d802b-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SUBTYPE_MPEG2_AUDIO);
#define KSDATAFORMAT_SUBTYPE_MPEG2_AUDIO                                       \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_MPEG2_AUDIO)

#define STATIC_KSDATAFORMAT_SPECIFIER_MPEG2_AUDIO                              \
  0xe06d80e5L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d80e5-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SPECIFIER_MPEG2_AUDIO);
#define KSDATAFORMAT_SPECIFIER_MPEG2_AUDIO                                     \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_MPEG2_AUDIO)

//
// DVD LPCM Audio definition
//

#define STATIC_KSDATAFORMAT_SUBTYPE_LPCM_AUDIO                                 \
  0xe06d8032L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d8032-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SUBTYPE_LPCM_AUDIO);
#define KSDATAFORMAT_SUBTYPE_LPCM_AUDIO                                        \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_LPCM_AUDIO)

#define STATIC_KSDATAFORMAT_SPECIFIER_LPCM_AUDIO                               \
  0xe06d80e6L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d80e6-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SPECIFIER_LPCM_AUDIO);
#define KSDATAFORMAT_SPECIFIER_LPCM_AUDIO                                      \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_LPCM_AUDIO)

//
// AC-3 definition
//

#define STATIC_KSDATAFORMAT_SUBTYPE_AC3_AUDIO                                  \
  0xe06d802cL, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d802c-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SUBTYPE_AC3_AUDIO);
#define KSDATAFORMAT_SUBTYPE_AC3_AUDIO                                         \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_AC3_AUDIO)

#define STATIC_KSDATAFORMAT_SPECIFIER_AC3_AUDIO                                \
  0xe06d80e4L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d80e4-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SPECIFIER_AC3_AUDIO);
#define KSDATAFORMAT_SPECIFIER_AC3_AUDIO                                       \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_AC3_AUDIO)

#define STATIC_KSPROPSETID_AC3                                                 \
  0xBFABE720L, 0x6E1F, 0x11D0, 0xBC, 0xF2, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00
DEFINE_GUIDSTRUCT("BFABE720-6E1F-11D0-BCF2-444553540000", KSPROPSETID_AC3);
#define KSPROPSETID_AC3 DEFINE_GUIDNAMED(KSPROPSETID_AC3)

typedef enum {
  KSPROPERTY_AC3_ERROR_CONCEALMENT = 1,
  KSPROPERTY_AC3_ALTERNATE_AUDIO,
  KSPROPERTY_AC3_DOWNMIX,
  KSPROPERTY_AC3_BIT_STREAM_MODE,
  KSPROPERTY_AC3_DIALOGUE_LEVEL,
  KSPROPERTY_AC3_LANGUAGE_CODE,
  KSPROPERTY_AC3_ROOM_TYPE
} KSPROPERTY_AC3;

typedef struct {
  BOOL fRepeatPreviousBlock;
  BOOL fErrorInCurrentBlock;
} KSAC3_ERROR_CONCEALMENT, *PKSAC3_ERROR_CONCEALMENT;

typedef struct {
  BOOL fStereo;
  ULONG DualMode;
} KSAC3_ALTERNATE_AUDIO, *PKSAC3_ALTERNATE_AUDIO;

#define KSAC3_ALTERNATE_AUDIO_1 1
#define KSAC3_ALTERNATE_AUDIO_2 2
#define KSAC3_ALTERNATE_AUDIO_BOTH 3

typedef struct {
  BOOL fDownMix;
  BOOL fDolbySurround;
} KSAC3_DOWNMIX, *PKSAC3_DOWNMIX;

typedef struct {
  LONG BitStreamMode;
} KSAC3_BIT_STREAM_MODE, *PKSAC3_BIT_STREAM_MODE;

#define KSAC3_SERVICE_MAIN_AUDIO 0
#define KSAC3_SERVICE_NO_DIALOG 1
#define KSAC3_SERVICE_VISUALLY_IMPAIRED 2
#define KSAC3_SERVICE_HEARING_IMPAIRED 3
#define KSAC3_SERVICE_DIALOG_ONLY 4
#define KSAC3_SERVICE_COMMENTARY 5
#define KSAC3_SERVICE_EMERGENCY_FLASH 6
#define KSAC3_SERVICE_VOICE_OVER 7

typedef struct {
  ULONG DialogueLevel;
} KSAC3_DIALOGUE_LEVEL, *PKSAC3_DIALOGUE_LEVEL;

typedef struct {
  BOOL fLargeRoom;
} KSAC3_ROOM_TYPE, *PKSAC3_ROOM_TYPE;

//
// DTS and SDDS definitions (media subtype GUIDs)
//
#define STATIC_KSDATAFORMAT_SUBTYPE_DTS_AUDIO                                  \
  0xe06d8033L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d8033-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SUBTYPE_DTS_AUDIO);
#define KSDATAFORMAT_SUBTYPE_DTS_AUDIO                                         \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_DTS_AUDIO)

#define STATIC_KSDATAFORMAT_SUBTYPE_SDDS_AUDIO                                 \
  0xe06d8034L, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d8034-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SUBTYPE_SDDS_AUDIO);
#define KSDATAFORMAT_SUBTYPE_SDDS_AUDIO                                        \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_SDDS_AUDIO)

//
// audio decoder output properties
//

#define STATIC_KSPROPSETID_AudioDecoderOut                                     \
  0x6ca6e020L, 0x43bd, 0x11d0, 0xbd, 0x6a, 0x00, 0x35, 0x05, 0xc1, 0x03, 0xa9
DEFINE_GUIDSTRUCT("6ca6e020-43bd-11d0-bd6a-003505c103a9",
                  KSPROPSETID_AudioDecoderOut);
#define KSPROPSETID_AudioDecoderOut                                            \
  DEFINE_GUIDNAMED(KSPROPSETID_AudioDecoderOut)

typedef enum {
  KSPROPERTY_AUDDECOUT_MODES,    // available output modes of decoder
  KSPROPERTY_AUDDECOUT_CUR_MODE, // current mode of the decoder
} KSPROPERTY_AUDDECOUT;

#define KSAUDDECOUTMODE_STEREO_ANALOG 0x0001
#define KSAUDDECOUTMODE_PCM_51 0x0002
#define KSAUDDECOUTMODE_SPDIFF 0x0004

//
// subpicture definition
//

#define STATIC_KSDATAFORMAT_SUBTYPE_SUBPICTURE                                 \
  0xe06d802dL, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea
DEFINE_GUIDSTRUCT("e06d802d-db46-11cf-b4d1-00805f6cbbea",
                  KSDATAFORMAT_SUBTYPE_SUBPICTURE);
#define KSDATAFORMAT_SUBTYPE_SUBPICTURE                                        \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_SUBPICTURE)

#define STATIC_KSPROPSETID_DvdSubPic                                           \
  0xac390460L, 0x43af, 0x11d0, 0xbd, 0x6a, 0x00, 0x35, 0x05, 0xc1, 0x03, 0xa9
DEFINE_GUIDSTRUCT("ac390460-43af-11d0-bd6a-003505c103a9",
                  KSPROPSETID_DvdSubPic);
#define KSPROPSETID_DvdSubPic DEFINE_GUIDNAMED(KSPROPSETID_DvdSubPic)

typedef enum {
  KSPROPERTY_DVDSUBPIC_PALETTE,
  KSPROPERTY_DVDSUBPIC_HLI,
  KSPROPERTY_DVDSUBPIC_COMPOSIT_ON, // TRUE for subpicture is displayed
} KSPROPERTY_DVDSUBPIC;

typedef struct _KS_DVD_YCrCb {
  UCHAR Reserved;
  UCHAR Y;
  UCHAR Cr;
  UCHAR Cb;
} KS_DVD_YCrCb, *PKS_DVD_YCrCb;

/* The KS_DVD_YUV structure is now superseded by KS_DVD_YCrCb above and is
   here for backward compatibility only */

typedef struct _KS_DVD_YUV {
  UCHAR Reserved;
  UCHAR Y;
  UCHAR V;
  UCHAR U;
} KS_DVD_YUV, *PKS_DVD_YUV;

typedef struct _KSPROPERTY_SPPAL {
  KS_DVD_YUV sppal[16];
} KSPROPERTY_SPPAL, *PKSPROPERTY_SPPAL;

typedef struct _KS_COLCON {
  UCHAR emph1col : 4;
  UCHAR emph2col : 4;
  UCHAR backcol : 4;
  UCHAR patcol : 4;
  UCHAR emph1con : 4;
  UCHAR emph2con : 4;
  UCHAR backcon : 4;
  UCHAR patcon : 4;

} KS_COLCON, *PKS_COLCON;

typedef struct _KSPROPERTY_SPHLI {
  USHORT HLISS;
  USHORT Reserved;
  ULONG StartPTM; // start presentation time in x/90000
  ULONG EndPTM;   // end PTM in x/90000
  USHORT StartX;
  USHORT StartY;
  USHORT StopX;
  USHORT StopY;
  KS_COLCON ColCon; // color contrast description (4 bytes as given in HLI)
} KSPROPERTY_SPHLI, *PKSPROPERTY_SPHLI;

typedef BOOL KSPROPERTY_COMPOSIT_ON, *PKSPROPERTY_COMPOSIT_ON;

#define STATIC_KSPROPSETID_CopyProt                                            \
  0x0E8A0A40L, 0x6AEF, 0x11D0, 0x9E, 0xD0, 0x00, 0xA0, 0x24, 0xCA, 0x19, 0xB3
DEFINE_GUIDSTRUCT("0E8A0A40-6AEF-11D0-9ED0-00A024CA19B3", KSPROPSETID_CopyProt);
#define KSPROPSETID_CopyProt DEFINE_GUIDNAMED(KSPROPSETID_CopyProt)

typedef enum {

  KSPROPERTY_DVDCOPY_CHLG_KEY = 0x01,
  KSPROPERTY_DVDCOPY_DVD_KEY1,
  KSPROPERTY_DVDCOPY_DEC_KEY2,
  KSPROPERTY_DVDCOPY_TITLE_KEY,
  KSPROPERTY_COPY_MACROVISION,
  KSPROPERTY_DVDCOPY_REGION,
  KSPROPERTY_DVDCOPY_SET_COPY_STATE,
  KSPROPERTY_DVDCOPY_DISC_KEY = 0x80

} KSPROPERTY_COPYPROT;

typedef struct _KS_DVDCOPY_CHLGKEY {
  BYTE ChlgKey[10];
  BYTE Reserved[2];
} KS_DVDCOPY_CHLGKEY, *PKS_DVDCOPY_CHLGKEY;

typedef struct _KS_DVDCOPY_BUSKEY {
  BYTE BusKey[5];
  BYTE Reserved[1];
} KS_DVDCOPY_BUSKEY, *PKS_DVDCOPY_BUSKEY;

typedef struct _KS_DVDCOPY_DISCKEY {
  BYTE DiscKey[2048];
} KS_DVDCOPY_DISCKEY, *PKS_DVDCOPY_DISCKEY;

typedef struct _KS_DVDCOPY_REGION {
  UCHAR Reserved;
  UCHAR RegionData;
  UCHAR Reserved2[2];
} KS_DVDCOPY_REGION, *PKS_DVDCOPY_REGION;

typedef struct _KS_DVDCOPY_TITLEKEY {
  ULONG KeyFlags;
  ULONG ReservedNT[2];
  UCHAR TitleKey[6];
  UCHAR Reserved[2];
} KS_DVDCOPY_TITLEKEY, *PKS_DVDCOPY_TITLEKEY;

typedef struct _KS_COPY_MACROVISION {
  ULONG MACROVISIONLevel;
} KS_COPY_MACROVISION, *PKS_COPY_MACROVISION;

typedef struct _KS_DVDCOPY_SET_COPY_STATE {
  ULONG DVDCopyState;
} KS_DVDCOPY_SET_COPY_STATE, *PKS_DVDCOPY_SET_COPY_STATE;

typedef enum {
  KS_DVDCOPYSTATE_INITIALIZE,       // indicates we are starting a full
                                    // copy protection sequence.
  KS_DVDCOPYSTATE_INITIALIZE_TITLE, // indicates we are starting a title
                                    // key copy protection sequence
  KS_DVDCOPYSTATE_AUTHENTICATION_NOT_REQUIRED,
  KS_DVDCOPYSTATE_AUTHENTICATION_REQUIRED,
  KS_DVDCOPYSTATE_DONE,
} KS_DVDCOPYSTATE;

typedef enum {
  KS_MACROVISION_DISABLED,
  KS_MACROVISION_LEVEL1,
  KS_MACROVISION_LEVEL2,
  KS_MACROVISION_LEVEL3
} KS_COPY_MACROVISION_LEVEL,
    *PKS_COPY_MACROVISION_LEVEL;

//
// CGMS Copy Protection Flags
//

#define KS_DVD_CGMS_RESERVED_MASK 0x00000078

#define KS_DVD_CGMS_COPY_PROTECT_MASK 0x00000018
#define KS_DVD_CGMS_COPY_PERMITTED 0x00000000
#define KS_DVD_CGMS_COPY_ONCE 0x00000010
#define KS_DVD_CGMS_NO_COPY 0x00000018

#define KS_DVD_COPYRIGHT_MASK 0x00000040
#define KS_DVD_NOT_COPYRIGHTED 0x00000000
#define KS_DVD_COPYRIGHTED 0x00000040

#define KS_DVD_SECTOR_PROTECT_MASK 0x00000020
#define KS_DVD_SECTOR_NOT_PROTECTED 0x00000000
#define KS_DVD_SECTOR_PROTECTED 0x00000020

//===========================================================================
// The following MUST match the structures in WinGDI.h and AMVideo.h
//===========================================================================

#define STATIC_KSCATEGORY_TVTUNER                                              \
  0xa799a800L, 0xa46d, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0x24, 0x01, 0xdc, 0xd4
DEFINE_GUIDSTRUCT("a799a800-a46d-11d0-a18c-00a02401dcd4", KSCATEGORY_TVTUNER);
#define KSCATEGORY_TVTUNER DEFINE_GUIDNAMED(KSCATEGORY_TVTUNER)

#define STATIC_KSCATEGORY_CROSSBAR                                             \
  0xa799a801L, 0xa46d, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0x24, 0x01, 0xdc, 0xd4
DEFINE_GUIDSTRUCT("a799a801-a46d-11d0-a18c-00a02401dcd4", KSCATEGORY_CROSSBAR);
#define KSCATEGORY_CROSSBAR DEFINE_GUIDNAMED(KSCATEGORY_CROSSBAR)

#define STATIC_KSCATEGORY_TVAUDIO                                              \
  0xa799a802L, 0xa46d, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0x24, 0x01, 0xdc, 0xd4
DEFINE_GUIDSTRUCT("a799a802-a46d-11d0-a18c-00a02401dcd4", KSCATEGORY_TVAUDIO);
#define KSCATEGORY_TVAUDIO DEFINE_GUIDNAMED(KSCATEGORY_TVAUDIO)

#define STATIC_KSCATEGORY_VPMUX                                                \
  0xa799a803L, 0xa46d, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0x24, 0x01, 0xdc, 0xd4
DEFINE_GUIDSTRUCT("a799a803-a46d-11d0-a18c-00a02401dcd4", KSCATEGORY_VPMUX);
#define KSCATEGORY_VPMUX DEFINE_GUIDNAMED(KSCATEGORY_VPMUX)

#define STATIC_KSCATEGORY_VBICODEC                                             \
  0x07dad660L, 0x22f1, 0x11d1, 0xa9, 0xf4, 0x00, 0xc0, 0x4f, 0xbb, 0xde, 0x8f
DEFINE_GUIDSTRUCT("07dad660-22f1-11d1-a9f4-00c04fbbde8f", KSCATEGORY_VBICODEC);
#define KSCATEGORY_VBICODEC DEFINE_GUIDNAMED(KSCATEGORY_VBICODEC)

// SUBTYPE_VPVideo
#define STATIC_KSDATAFORMAT_SUBTYPE_VPVideo                                    \
  0x5a9b6a40L, 0x1a22, 0x11d1, 0xba, 0xd9, 0x0, 0x60, 0x97, 0x44, 0x11, 0x1a
DEFINE_GUIDSTRUCT("5a9b6a40-1a22-11d1-bad9-00609744111a",
                  KSDATAFORMAT_SUBTYPE_VPVideo);
#define KSDATAFORMAT_SUBTYPE_VPVideo                                           \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_VPVideo)

// SUBTYPE_VPVBI
#define STATIC_KSDATAFORMAT_SUBTYPE_VPVBI                                      \
  0x5a9b6a41L, 0x1a22, 0x11d1, 0xba, 0xd9, 0x0, 0x60, 0x97, 0x44, 0x11, 0x1a
DEFINE_GUIDSTRUCT("5a9b6a41-1a22-11d1-bad9-00609744111a",
                  KSDATAFORMAT_SUBTYPE_VPVBI);
#define KSDATAFORMAT_SUBTYPE_VPVBI DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_VPVBI)

// FORMAT_VideoInfo
#define STATIC_KSDATAFORMAT_SPECIFIER_VIDEOINFO                                \
  0x05589f80L, 0xc356, 0x11ce, 0xbf, 0x01, 0x00, 0xaa, 0x00, 0x55, 0x59, 0x5a
DEFINE_GUIDSTRUCT("05589f80-c356-11ce-bf01-00aa0055595a",
                  KSDATAFORMAT_SPECIFIER_VIDEOINFO);
#define KSDATAFORMAT_SPECIFIER_VIDEOINFO                                       \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_VIDEOINFO)

// FORMAT_VideoInfo2
#define STATIC_KSDATAFORMAT_SPECIFIER_VIDEOINFO2                               \
  0xf72a76A0L, 0xeb0a, 0x11d0, 0xac, 0xe4, 0x00, 0x00, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("f72a76A0-eb0a-11d0-ace4-0000c0cc16ba",
                  KSDATAFORMAT_SPECIFIER_VIDEOINFO2);
#define KSDATAFORMAT_SPECIFIER_VIDEOINFO2                                      \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_VIDEOINFO2)

// MEDIATYPE_AnalogVideo
#define STATIC_KSDATAFORMAT_TYPE_ANALOGVIDEO                                   \
  0x0482dde1L, 0x7817, 0x11cf, 0x8a, 0x03, 0x00, 0xaa, 0x00, 0x6e, 0xcb, 0x65
DEFINE_GUIDSTRUCT("0482dde1-7817-11cf-8a03-00aa006ecb65",
                  KSDATAFORMAT_TYPE_ANALOGVIDEO);
#define KSDATAFORMAT_TYPE_ANALOGVIDEO                                          \
  DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_ANALOGVIDEO)

// FORMAT_AnalogVideo
#define STATIC_KSDATAFORMAT_SPECIFIER_ANALOGVIDEO                              \
  0x0482dde0L, 0x7817, 0x11cf, 0x8a, 0x03, 0x00, 0xaa, 0x00, 0x6e, 0xcb, 0x65
DEFINE_GUIDSTRUCT("0482dde0-7817-11cf-8a03-00aa006ecb65",
                  KSDATAFORMAT_SPECIFIER_ANALOGVIDEO);
#define KSDATAFORMAT_SPECIFIER_ANALOGVIDEO                                     \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_ANALOGVIDEO)

// MEDIATYPE_AnalogAudio
#define STATIC_KSDATAFORMAT_TYPE_ANALOGAUDIO                                   \
  0x0482dee1L, 0x7817, 0x11cf, 0x8a, 0x03, 0x00, 0xaa, 0x00, 0x6e, 0xcb, 0x65
DEFINE_GUIDSTRUCT("0482DEE1-7817-11cf-8a03-00aa006ecb65",
                  KSDATAFORMAT_TYPE_ANALOGAUDIO);
#define KSDATAFORMAT_TYPE_ANALOGAUDIO                                          \
  DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_ANALOGAUDIO)

// FORMAT_VBI
#define STATIC_KSDATAFORMAT_SPECIFIER_VBI                                      \
  0xf72a76e0L, 0xeb0a, 0x11d0, 0xac, 0xe4, 0x00, 0x00, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("f72a76e0-eb0a-11d0-ace4-0000c0cc16ba",
                  KSDATAFORMAT_SPECIFIER_VBI);
#define KSDATAFORMAT_SPECIFIER_VBI DEFINE_GUIDNAMED(KSDATAFORMAT_SPECIFIER_VBI)

// MEDIATYPE_VBI
#define STATIC_KSDATAFORMAT_TYPE_VBI                                           \
  0xf72a76e1L, 0xeb0a, 0x11d0, 0xac, 0xe4, 0x00, 0x00, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("f72a76e1-eb0a-11d0-ace4-0000c0cc16ba",
                  KSDATAFORMAT_TYPE_VBI);
#define KSDATAFORMAT_TYPE_VBI DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_VBI)

// SUBTYPE_RAW8
#define STATIC_KSDATAFORMAT_SUBTYPE_RAW8                                       \
  0xca20d9a0, 0x3e3e, 0x11d1, 0x9b, 0xf9, 0x0, 0xc0, 0x4f, 0xbb, 0xde, 0xbf
DEFINE_GUIDSTRUCT("ca20d9a0-3e3e-11d1-9bf9-00c04fbbdebf",
                  KSDATAFORMAT_SUBTYPE_RAW8);
#define KSDATAFORMAT_SUBTYPE_RAW8 DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_RAW8)

// MEDIASUBTYPE_CC
#define STATIC_KSDATAFORMAT_SUBTYPE_CC                                         \
  0x33214cc1, 0x11f, 0x11d2, 0xb4, 0xb1, 0x0, 0xa0, 0xd1, 0x2, 0xcf, 0xbe
DEFINE_GUIDSTRUCT("33214CC1-011F-11D2-B4B1-00A0D102CFBE",
                  KSDATAFORMAT_SUBTYPE_CC);
#define KSDATAFORMAT_SUBTYPE_CC DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_CC)

// MEDIASUBTYPE_NABTS
#define STATIC_KSDATAFORMAT_SUBTYPE_NABTS                                      \
  0xf72a76e2L, 0xeb0a, 0x11d0, 0xac, 0xe4, 0x00, 0x00, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("f72a76e2-eb0a-11d0-ace4-0000c0cc16ba",
                  KSDATAFORMAT_SUBTYPE_NABTS);
#define KSDATAFORMAT_SUBTYPE_NABTS DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_NABTS)

// MEDIASUBTYPE_TELETEXT
#define STATIC_KSDATAFORMAT_SUBTYPE_TELETEXT                                   \
  0xf72a76e3L, 0xeb0a, 0x11d0, 0xac, 0xe4, 0x00, 0x00, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("f72a76e3-eb0a-11d0-ace4-0000c0cc16ba",
                  KSDATAFORMAT_SUBTYPE_TELETEXT);
#define KSDATAFORMAT_SUBTYPE_TELETEXT                                          \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_TELETEXT)

/* constants for the biCompression field */
#define KS_BI_RGB 0L
#define KS_BI_RLE8 1L
#define KS_BI_RLE4 2L
#define KS_BI_BITFIELDS 3L

typedef struct tagKS_RGBQUAD { // rgbq
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved;
} KS_RGBQUAD, *PKS_RGBQUAD;

/* constants for palettes */
#define KS_iPALETTE_COLORS 256 // Maximum colours in palette
#define KS_iEGA_COLORS 16      // Number colours in EGA palette
#define KS_iMASK_COLORS 3      // Maximum three components
#define KS_iTRUECOLOR 16       // Minimum true colour device
#define KS_iRED 0              // Index position for RED mask
#define KS_iGREEN 1            // Index position for GREEN mask
#define KS_iBLUE 2             // Index position for BLUE mask
#define KS_iPALETTE 8          // Maximum colour depth using a palette
#define KS_iMAXBITS 8          // Maximum bits per colour component
#define KS_SIZE_EGA_PALETTE (KS_iEGA_COLORS * sizeof(KS_RGBQUAD))
#define KS_SIZE_PALETTE (KS_iPALETTE_COLORS * sizeof(KS_RGBQUAD))

typedef struct tagKS_BITMAPINFOHEADER {
  DWORD biSize;
  LONG biWidth;
  LONG biHeight;
  WORD biPlanes;
  WORD biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG biXPelsPerMeter;
  LONG biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} KS_BITMAPINFOHEADER, *PKS_BITMAPINFOHEADER;

// Used for true colour images that also have a palette

typedef struct tag_KS_TRUECOLORINFO {
  DWORD dwBitMasks[KS_iMASK_COLORS];
  KS_RGBQUAD bmiColors[KS_iPALETTE_COLORS];
} KS_TRUECOLORINFO, *PKS_TRUECOLORINFO;

#define KS_WIDTHBYTES(bits) ((DWORD)(((bits) + 31) & (~31)) / 8)
#define KS_DIBWIDTHBYTES(bi)                                                   \
  (DWORD) KS_WIDTHBYTES((DWORD)(bi).biWidth *(DWORD)(bi).biBitCount)
#define KS__DIBSIZE(bi) (KS_DIBWIDTHBYTES(bi) * (DWORD)(bi).biHeight)
#define KS_DIBSIZE(bi)                                                         \
  ((bi).biHeight < 0 ? (-1) * (KS__DIBSIZE(bi)) : KS__DIBSIZE(bi))

typedef LONGLONG REFERENCE_TIME;

// The BITMAPINFOHEADER contains all the details about the video stream such
// as the actual image dimensions and their pixel depth. A source filter may
// also request that the sink take only a section of the video by providing a
// clipping rectangle in rcSource. In the worst case where the sink filter
// forgets to check this on connection it will simply render the whole thing
// which isn't a disaster. Ideally a sink filter will check the rcSource and
// if it doesn't support image extraction and the rectangle is not empty then
// it will reject the connection. A filter should use SetRectEmpty to reset a
// rectangle to all zeroes (and IsRectEmpty to later check the rectangle).
// The rcTarget specifies the destination rectangle for the video, for most
// source filters they will set this to all zeroes, a downstream filter may
// request that the video be placed in a particular area of the buffers it
// supplies in which case it will call QueryAccept with a non empty target

typedef struct tagKS_VIDEOINFOHEADER {

  RECT rcSource;                  // The bit we really want to use
  RECT rcTarget;                  // Where the video should go
  DWORD dwBitRate;                // Approximate bit data rate
  DWORD dwBitErrorRate;           // Bit error rate for this stream
  REFERENCE_TIME AvgTimePerFrame; // Average time per frame (100ns units)

  KS_BITMAPINFOHEADER bmiHeader;

} KS_VIDEOINFOHEADER, *PKS_VIDEOINFOHEADER;

// !!! WARNING !!!
// DO NOT use the following structure unless you are sure that the
// BITMAPINFOHEADER has a normal biSize == sizeof(BITMAPINFOHEADER) !
// !!! WARNING !!!

typedef struct tagKS_VIDEOINFO {

  RECT rcSource;                  // The bit we really want to use
  RECT rcTarget;                  // Where the video should go
  DWORD dwBitRate;                // Approximate bit data rate
  DWORD dwBitErrorRate;           // Bit error rate for this stream
  REFERENCE_TIME AvgTimePerFrame; // Average time per frame (100ns units)

  KS_BITMAPINFOHEADER bmiHeader;

  union {
    KS_RGBQUAD bmiColors[KS_iPALETTE_COLORS]; // Colour palette
    DWORD dwBitMasks[KS_iMASK_COLORS];        // True colour masks
    KS_TRUECOLORINFO TrueColorInfo;           // Both of the above
  };

} KS_VIDEOINFO, *PKS_VIDEOINFO;

#define KS_SIZE_MASKS (KS_iMASK_COLORS * sizeof(DWORD))
#define KS_SIZE_PREHEADER (FIELD_OFFSET(KS_VIDEOINFOHEADER, bmiHeader))

// For normal size
// #define KS_SIZE_VIDEOHEADER (sizeof(KS_BITMAPINFOHEADER) + KS_SIZE_PREHEADER)
// !!! for abnormal biSizes
#define KS_SIZE_VIDEOHEADER(pbmi) ((pbmi)->bmiHeader.biSize + KS_SIZE_PREHEADER)

// VBI
// Used for NABTS, CC, Intercast, WST
typedef struct tagKS_VBIINFOHEADER {
  ULONG StartLine;           // inclusive
  ULONG EndLine;             // inclusive
  ULONG SamplingFrequency;   // Hz.
  ULONG MinLineStartTime;    // microSec * 100 from HSync LE
  ULONG MaxLineStartTime;    // microSec * 100 from HSync LE
  ULONG ActualLineStartTime; // microSec * 100 from HSync LE
  ULONG ActualLineEndTime;   // microSec * 100 from HSync LE
  ULONG VideoStandard;       // KS_AnalogVideoStandard*
  ULONG SamplesPerLine;
  ULONG StrideInBytes; // May be > SamplesPerLine
  ULONG BufferSize;    // Bytes
} KS_VBIINFOHEADER, *PKS_VBIINFOHEADER;

// VBI Sampling Rates
#define KS_VBIDATARATE_NABTS (5727272L)
#define KS_VBIDATARATE_CC (503493L) // ~= 1/1.986125e-6
#define KS_VBISAMPLINGRATE_4X_NABTS ((long)(4 * KS_VBIDATARATE_NABTS))
#define KS_VBISAMPLINGRATE_47X_NABTS ((long)(27000000))
#define KS_VBISAMPLINGRATE_5X_NABTS ((long)(5 * KS_VBIDATARATE_NABTS))

#define KS_47NABTS_SCALER                                                      \
  (KS_VBISAMPLINGRATE_47X_NABTS / (double)KS_VBIDATARATE_NABTS)

// Analog video variant - Use this when the format is FORMAT_AnalogVideo
//
// rcSource defines the portion of the active video signal to use
// rcTarget defines the destination rectangle
//    both of the above are relative to the dwActiveWidth and dwActiveHeight
//    fields
// dwActiveWidth is currently set to 720 for all formats (but could change for
// HDTV) dwActiveHeight is 483 for NTSC and 575 for PAL/SECAM  (but could change
// for HDTV)

typedef struct tagKS_AnalogVideoInfo {
  RECT rcSource;        // Width max is 720, height varies w/ TransmissionStd
  RECT rcTarget;        // Where the video should go
  DWORD dwActiveWidth;  // Always 720 (CCIR-601 active samples per line)
  DWORD dwActiveHeight; // 483 for NTSC, 575 for PAL/SECAM
  REFERENCE_TIME AvgTimePerFrame; // Normal ActiveMovie units (100 nS)
} KS_ANALOGVIDEOINFO, *PKS_ANALOGVIDEOINFO;

//===========================================================================
// Data packet passed on Analog video stream channel change
//===========================================================================

#define KS_TVTUNER_CHANGE_BEGIN_TUNE 0x0001L // Starting a tuning operation
#define KS_TVTUNER_CHANGE_END_TUNE 0x0002L   // Ending a tuning operation

typedef struct tagKS_TVTUNER_CHANGE_INFO {
  DWORD dwFlags; // KS_TVTUNER_CHANGE_*
  DWORD dwCountryCode;
  DWORD dwAnalogVideoStandard; // KS_AnalogVideoStandard
  DWORD dwChannel;
} KS_TVTUNER_CHANGE_INFO, *PKS_TVTUNER_CHANGE_INFO;

//===========================================================================
// Video format blocks
//===========================================================================

typedef enum {
  KS_MPEG2Level_Low,
  KS_MPEG2Level_Main,
  KS_MPEG2Level_High1440,
  KS_MPEG2Level_High
} KS_MPEG2Level;

typedef enum {
  KS_MPEG2Profile_Simple,
  KS_MPEG2Profile_Main,
  KS_MPEG2Profile_SNRScalable,
  KS_MPEG2Profile_SpatiallyScalable,
  KS_MPEG2Profile_High
} KS_MPEG2Profile;

#define KS_INTERLACE_IsInterlaced                                              \
  0x00000001 // if 0, other interlace bits are irrelevent
#define KS_INTERLACE_1FieldPerSample                                           \
  0x00000002 // else 2 fields per media sample
#define KS_INTERLACE_Field1First                                               \
  0x00000004 // else Field 2 is first;  top field in PAL is field 1, top field
             // in NTSC is field 2?
#define KS_INTERLACE_UNUSED 0x00000008 //
#define KS_INTERLACE_FieldPatternMask                                          \
  0x00000030 // use this mask with AMINTERLACE_FieldPat*
#define KS_INTERLACE_FieldPatField1Only                                        \
  0x00000000 // Data never contains a Field2
#define KS_INTERLACE_FieldPatField2Only                                        \
  0x00000010 // Data never contains a Field1
#define KS_INTERLACE_FieldPatBothRegular                                       \
  0x00000020 // There will be a Field2 for every Field1 (required for Weave?)
#define KS_INTERLACE_FieldPatBothIrregular                                     \
  0x00000030 // Random pattern of Field1s and Field2s
#define KS_INTERLACE_DisplayModeMask 0x000000c0
#define KS_INTERLACE_DisplayModeBobOnly 0x00000000
#define KS_INTERLACE_DisplayModeWeaveOnly 0x00000040
#define KS_INTERLACE_DisplayModeBobOrWeave 0x00000080

#define KS_MPEG2_DoPanScan                                                     \
  0x00000001 // if set, the MPEG-2 video decoder should crop output image
//  based on pan-scan vectors in picture_display_extension
//  and change the picture aspect ratio accordingly.
#define KS_MPEG2_DVDLine21Field1                                               \
  0x00000002 // if set, the MPEG-2 decoder must be able to produce an output
//  pin for DVD style closed caption data found in GOP layer of field 1
#define KS_MPEG2_DVDLine21Field2                                               \
  0x00000004 // if set, the MPEG-2 decoder must be able to produce an output
//  pin for DVD style closed caption data found in GOP layer of field 2
#define KS_MPEG2_SourceIsLetterboxed                                           \
  0x00000008 // if set, indicates that black bars have been encoded in the top
//  and bottom of the video.
#define KS_MPEG2_FilmCameraMode                                                \
  0x00000010 // if set, indicates "film mode" used for 625/50 content.  If
             // cleared,
//  indicates that "camera mode" was used.
#define KS_MPEG2_LetterboxAnalogOut                                            \
  0x00000020 // if set and this stream is sent to an analog output, it should
//  be letterboxed.  Streams sent to VGA should be letterboxed only by
//  renderers.
#define KS_MPEG2_DSS_UserData                                                  \
  0x00000040 // if set, the MPEG-2 decoder must process DSS style user data
#define KS_MPEG2_DVB_UserData                                                  \
  0x00000080 // if set, the MPEG-2 decoder must process DVB style user data
#define KS_MPEG2_27MhzTimebase                                                 \
  0x00000100 // if set, the PTS,DTS timestamps advance at 27MHz rather than
             // 90KHz

typedef struct tagKS_VIDEOINFOHEADER2 {
  RECT rcSource;
  RECT rcTarget;
  DWORD dwBitRate;
  DWORD dwBitErrorRate;
  REFERENCE_TIME AvgTimePerFrame;
  DWORD dwInterlaceFlags;   // use AMINTERLACE_* defines. Reject connection if
                            // undefined bits are not 0
  DWORD dwCopyProtectFlags; // use AMCOPYPROTECT_* defines. Reject connection if
                            // undefined bits are not 0
  DWORD dwPictAspectRatioX; // X dimension of picture aspect ratio, e.g. 16 for
                            // 16x9 display
  DWORD dwPictAspectRatioY; // Y dimension of picture aspect ratio, e.g.  9 for
                            // 16x9 display
  DWORD dwReserved1;        // must be 0; reject connection otherwise
  DWORD dwReserved2;        // must be 0; reject connection otherwise
  KS_BITMAPINFOHEADER bmiHeader;
} KS_VIDEOINFOHEADER2, *PKS_VIDEOINFOHEADER2;

typedef struct tagKS_MPEG1VIDEOINFO {
  KS_VIDEOINFOHEADER hdr; // Compatible with VIDEOINFO
  DWORD dwStartTimeCode;  // 25-bit Group of pictures time code at start of data
  DWORD cbSequenceHeader; // Length in bytes of bSequenceHeader
  BYTE bSequenceHeader[1]; // Sequence header including quantization matrices if
                           // any
} KS_MPEG1VIDEOINFO, *PKS_MPEG1VIDEOINFO;

#define KS_MAX_SIZE_MPEG1_SEQUENCE_INFO 140
#define KS_SIZE_MPEG1VIDEOINFO(pv)                                             \
  (FIELD_OFFSET(KS_MPEG1VIDEOINFO, bSequenceHeader[0]) + (pv)->cbSequenceHeader)
#define KS_MPEG1_SEQUENCE_INFO(pv) ((const BYTE *)(pv)->bSequenceHeader)

typedef struct tagKS_MPEGVIDEOINFO2 {
  KS_VIDEOINFOHEADER2 hdr;
  DWORD dwStartTimeCode;  //  ?? not used for DVD ??
  DWORD cbSequenceHeader; // is 0 for DVD (no sequence header)
  DWORD dwProfile;        // use enum MPEG2Profile
  DWORD dwLevel;          // use enum MPEG2Level
  DWORD dwFlags; // use AMMPEG2_* defines.  Reject connection if undefined bits
                 // are not 0
  DWORD bSequenceHeader[1]; // DWORD instead of Byte for alignment purposes
                            //   For MPEG-2, if a sequence_header is included,
                            //   the sequence_extension should also be included
} KS_MPEGVIDEOINFO2, *PKS_MPEGVIDEOINFO2;

#define KS_SIZE_MPEGVIDEOINFO2(pv)                                             \
  (FIELD_OFFSET(KS_MPEGVIDEOINFO2, bSequenceHeader[0]) + (pv)->cbSequenceHeader)
#define KS_MPEG1_SEQUENCE_INFO(pv) ((const BYTE *)(pv)->bSequenceHeader)

//===========================================================================
// Audio format blocks
//===========================================================================

// if set, the PTS,DTS timestamps advance at 27MHz rather than 90KHz
#define KS_MPEGAUDIOINFO_27MhzTimebase 0x00000001

typedef struct tagKS_MPEAUDIOINFO {
  DWORD dwFlags;     // use KS_MPEGAUDIOINFO_* defines.  Reject connection if
                     // undefined bits are not 0
  DWORD dwReserved1; // must be 0; reject connection otherwise
  DWORD dwReserved2; // must be 0; reject connection otherwise
  DWORD dwReserved3; // must be 0; reject connection otherwise
} KS_MPEGAUDIOINFO, *PKS_MPEGAUDIOINFO;

//===========================================================================
// Video DATAFORMATs
//===========================================================================

typedef struct tagKS_DATAFORMAT_VIDEOINFOHEADER {
  KSDATAFORMAT DataFormat;
  KS_VIDEOINFOHEADER VideoInfoHeader;
} KS_DATAFORMAT_VIDEOINFOHEADER, *PKS_DATAFORMAT_VIDEOINFOHEADER;

typedef struct tagKS_DATAFORMAT_VIDEOINFOHEADER2 {
  KSDATAFORMAT DataFormat;
  KS_VIDEOINFOHEADER2 VideoInfoHeader2;
} KS_DATAFORMAT_VIDEOINFOHEADER2, *PKS_DATAFORMAT_VIDEOINFOHEADER2;

typedef struct tagKS_DATAFORMAT_VIDEOINFO_PALETTE {
  KSDATAFORMAT DataFormat;
  KS_VIDEOINFO VideoInfo;
} KS_DATAFORMAT_VIDEOINFO_PALETTE, *PKS_DATAFORMAT_VIDEOINFO_PALETTE;

typedef struct tagKS_DATAFORMAT_VBIINFOHEADER {
  KSDATAFORMAT DataFormat;
  KS_VBIINFOHEADER VBIInfoHeader;
} KS_DATAFORMAT_VBIINFOHEADER, *PKS_DATAFORMAT_VBIINFOHEADER;

typedef struct _KS_VIDEO_STREAM_CONFIG_CAPS {
  GUID guid;            // will be MEDIATYPE_Video
  ULONG VideoStandard;  // logical OR of all AnalogVideoStandards
                        // supported
  SIZE InputSize;       // the inherent size of the incoming signal
                        // (every pixel unique)
  SIZE MinCroppingSize; // smallest rcSrc cropping rect allowed
  SIZE MaxCroppingSize; // largest rcSrc cropping rect allowed
  int CropGranularityX; // granularity of cropping size
  int CropGranularityY;
  int CropAlignX; // alignment of cropping rect
  int CropAlignY;
  SIZE MinOutputSize;     // smallest bitmap stream can produce
  SIZE MaxOutputSize;     // largest  bitmap stream can produce
  int OutputGranularityX; // granularity of output bitmap size
  int OutputGranularityY;
  int StretchTapsX;          // 0, no stretch, 1 pix dup, 2 interp, ...
  int StretchTapsY;          //    Describes quality of hardware scaler
  int ShrinkTapsX;           //
  int ShrinkTapsY;           //
  LONGLONG MinFrameInterval; // 100 nS units
  LONGLONG MaxFrameInterval;
  LONG MinBitsPerSecond;
  LONG MaxBitsPerSecond;
} KS_VIDEO_STREAM_CONFIG_CAPS, *PKS_VIDEO_STREAM_CONFIG_CAPS;

//===========================================================================
// Video DATARANGEs
//===========================================================================

typedef struct tagKS_DATARANGE_VIDEO {
  KSDATARANGE DataRange;
  BOOL bFixedSizeSamples;       // all samples same size?
  BOOL bTemporalCompression;    // all I frames?
  DWORD StreamDescriptionFlags; // KS_VIDEO_DESC_*
  DWORD MemoryAllocationFlags;  // KS_VIDEO_ALLOC_*
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_VIDEOINFOHEADER VideoInfoHeader; // default format
} KS_DATARANGE_VIDEO, *PKS_DATARANGE_VIDEO;

typedef struct tagKS_DATARANGE_VIDEO2 {
  KSDATARANGE DataRange;
  BOOL bFixedSizeSamples;       // all samples same size?
  BOOL bTemporalCompression;    // all I frames?
  DWORD StreamDescriptionFlags; // KS_VIDEO_DESC_*
  DWORD MemoryAllocationFlags;  // KS_VIDEO_ALLOC_*
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_VIDEOINFOHEADER2 VideoInfoHeader; // default format
} KS_DATARANGE_VIDEO2, *PKS_DATARANGE_VIDEO2;

typedef struct tagKS_DATARANGE_MPEG1_VIDEO {
  KSDATARANGE DataRange;
  BOOL bFixedSizeSamples;       // all samples same size?
  BOOL bTemporalCompression;    // all I frames?
  DWORD StreamDescriptionFlags; // KS_VIDEO_DESC_*
  DWORD MemoryAllocationFlags;  // KS_VIDEO_ALLOC_*
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_MPEG1VIDEOINFO VideoInfoHeader; // default format
} KS_DATARANGE_MPEG1_VIDEO, *PKS_DATARANGE_MPEG1_VIDEO;

typedef struct tagKS_DATARANGE_MPEG2_VIDEO {
  KSDATARANGE DataRange;
  BOOL bFixedSizeSamples;       // all samples same size?
  BOOL bTemporalCompression;    // all I frames?
  DWORD StreamDescriptionFlags; // KS_VIDEO_DESC_*
  DWORD MemoryAllocationFlags;  // KS_VIDEO_ALLOC_*
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_MPEGVIDEOINFO2 VideoInfoHeader; // default format
} KS_DATARANGE_MPEG2_VIDEO, *PKS_DATARANGE_MPEG2_VIDEO;

typedef struct tagKS_DATARANGE_VIDEO_PALETTE {
  KSDATARANGE DataRange;
  BOOL bFixedSizeSamples;       // all samples same size?
  BOOL bTemporalCompression;    // all I frames?
  DWORD StreamDescriptionFlags; // KS_VIDEO_DESC_*
  DWORD MemoryAllocationFlags;  // KS_VIDEO_ALLOC_*
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_VIDEOINFO VideoInfo; // default format
} KS_DATARANGE_VIDEO_PALETTE, *PKS_DATARANGE_VIDEO_PALETTE;

typedef struct tagKS_DATARANGE_VIDEO_VBI {
  KSDATARANGE DataRange;
  BOOL bFixedSizeSamples;       // all samples same size?
  BOOL bTemporalCompression;    // all I frames?
  DWORD StreamDescriptionFlags; // KS_VIDEO_DESC_*
  DWORD MemoryAllocationFlags;  // KS_VIDEO_ALLOC_*
  KS_VIDEO_STREAM_CONFIG_CAPS ConfigCaps;
  KS_VBIINFOHEADER VBIInfoHeader; // default format
} KS_DATARANGE_VIDEO_VBI, *PKS_DATARANGE_VIDEO_VBI;

typedef struct tagKS_DATARANGE_ANALOGVIDEO {
  KSDATARANGE DataRange;
  KS_ANALOGVIDEOINFO AnalogVideoInfo;
} KS_DATARANGE_ANALOGVIDEO, *PKS_DATARANGE_ANALOGVIDEO;

//===========================================================================
// StreamDescriptionFlags
//
// These define the "purpose" of each video stream
//===========================================================================

#define KS_VIDEOSTREAM_PREVIEW 0x0001  // Preview stream
#define KS_VIDEOSTREAM_CAPTURE 0x0002  // Capture stream
#define KS_VIDEOSTREAM_VBI 0x0010      // Field1 VBI
#define KS_VIDEOSTREAM_NABTS 0x0020    // Field1 NABTS
#define KS_VIDEOSTREAM_CC 0x0100       // Closed Captioning
#define KS_VIDEOSTREAM_EDS 0x0200      // Extended Data Services
#define KS_VIDEOSTREAM_TELETEXT 0x0400 // Field1 Teletext only
#define KS_VIDEOSTREAM_STILL 0x1000    // Still image input
#define KS_VIDEOSTREAM_IS_VPE 0x8000   // Is a VPE based stream?

// MemoryAllocationFlags
#define KS_VIDEO_ALLOC_VPE_SYSTEM 0x0001  // VPE surface in system memory
#define KS_VIDEO_ALLOC_VPE_DISPLAY 0x0002 // VPE surface in display memory
#define KS_VIDEO_ALLOC_VPE_AGP 0x0004     // VPE surface in AGP memory

//////////////////////////////////////////////////////////////
// Capture driver VBI property sets
//////////////////////////////////////////////////////////////

// {F162C607-7B35-496f-AD7F-2DCA3B46B718}
#define STATIC_KSPROPSETID_VBICAP_PROPERTIES                                   \
  0xf162c607, 0x7b35, 0x496f, 0xad, 0x7f, 0x2d, 0xca, 0x3b, 0x46, 0xb7, 0x18
DEFINE_GUIDSTRUCT("F162C607-7B35-496f-AD7F-2DCA3B46B718",
                  KSPROPSETID_VBICAP_PROPERTIES);
#define KSPROPSETID_VBICAP_PROPERTIES                                          \
  DEFINE_GUIDNAMED(KSPROPSETID_VBICAP_PROPERTIES)

typedef enum {
  KSPROPERTY_VBICAP_PROPERTIES_PROTECTION = 0x01,
} KSPROPERTY_VBICAP;

typedef struct _VBICAP_PROPERTIES_PROTECTION_S {
  KSPROPERTY Property;
  ULONG StreamIndex; // Index of stream
  ULONG Status;
} VBICAP_PROPERTIES_PROTECTION_S, *PVBICAP_PROPERTIES_PROTECTION_S;
#define KS_VBICAP_PROTECTION_MV_PRESENT 0x0001L
#define KS_VBICAP_PROTECTION_MV_HARDWARE 0x0002L
#define KS_VBICAP_PROTECTION_MV_DETECTED 0x0004L

/***************************************************************************/
/* VBI Related GUIDs, structs and properties for codecs(generic, cc, nabts)*/
/***************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////
// IP/NABTS Protocol Reserved Group IDs - Overall Range 0x800-0x8FF [Decimal
// 2048-2079] Intervening values(0-F) are used if there are multiple providers
// at a particular tier
///////////////////////////////////////////////////////////////////////////////////////

// Used by individual content creators in show footage/data
#define KS_NABTS_GROUPID_ORIGINAL_CONTENT_BASE 0x800
#define KS_NABTS_GROUPID_ORIGINAL_CONTENT_ADVERTISER_BASE 0x810

// Used by production company in finished show data
#define KS_NABTS_GROUPID_PRODUCTION_COMPANY_CONTENT_BASE 0x820
#define KS_NABTS_GROUPID_PRODUCTION_COMPANY_ADVERTISER_BASE 0x830

// Used by broadcast syndicates in syndicated show data
#define KS_NABTS_GROUPID_SYNDICATED_SHOW_CONTENT_BASE 0x840
#define KS_NABTS_GROUPID_SYNDICATED_SHOW_ADVERTISER_BASE 0x850

// Used by tv networks in network television data
#define KS_NABTS_GROUPID_NETWORK_WIDE_CONTENT_BASE 0x860
#define KS_NABTS_GROUPID_NETWORK_WIDE_ADVERTISER_BASE 0x870

// Used by telvision stations in local programming data
#define KS_NABTS_GROUPID_TELEVISION_STATION_CONTENT_BASE 0x880
#define KS_NABTS_GROUPID_TELEVISION_STATION_ADVERTISER_BASE 0x890

// Used by cable system in cable head-end originated data
#define KS_NABTS_GROUPID_LOCAL_CABLE_SYSTEM_CONTENT_BASE 0x8A0
#define KS_NABTS_GROUPID_LOCAL_CABLE_SYSTEM_ADVERTISER_BASE 0x8B0

// The values between 0x8C0 - 0x8EF are reserved for future expansion

// Used by Microsoft for Testing purposes (0x8F0 - 0x8FF)
#define KS_NABTS_GROUPID_MICROSOFT_RESERVED_TEST_DATA_BASE 0x8F0

//////////////////////////////////////////////////////////////
// Stream Format FEC-corrected NABTS bundles
//////////////////////////////////////////////////////////////

#define STATIC_KSDATAFORMAT_TYPE_NABTS                                         \
  0xe757bca0, 0x39ac, 0x11d1, 0xa9, 0xf5, 0x0, 0xc0, 0x4f, 0xbb, 0xde, 0x8f
DEFINE_GUIDSTRUCT("E757BCA0-39AC-11d1-A9F5-00C04FBBDE8F",
                  KSDATAFORMAT_TYPE_NABTS);
#define KSDATAFORMAT_TYPE_NABTS DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_NABTS)

#define STATIC_KSDATAFORMAT_SUBTYPE_NABTS_FEC                                  \
  0xe757bca1, 0x39ac, 0x11d1, 0xa9, 0xf5, 0x0, 0xc0, 0x4f, 0xbb, 0xde, 0x8f
DEFINE_GUIDSTRUCT("E757BCA1-39AC-11d1-A9F5-00C04FBBDE8F",
                  KSDATAFORMAT_SUBTYPE_NABTS_FEC);
#define KSDATAFORMAT_SUBTYPE_NABTS_FEC                                         \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_NABTS_FEC)

//////////////////////////////////////////////////////////////
// NABTS Bundle data structure definition
//////////////////////////////////////////////////////////////

#define MAX_NABTS_VBI_LINES_PER_FIELD 11
#define NABTS_LINES_PER_BUNDLE 16
#define NABTS_PAYLOAD_PER_LINE 28
#define NABTS_BYTES_PER_LINE 36

typedef struct _NABTSFEC_BUFFER {
  ULONG dataSize;
  USHORT groupID;
  USHORT Reserved;
  UCHAR data[NABTS_LINES_PER_BUNDLE * NABTS_PAYLOAD_PER_LINE];
} NABTSFEC_BUFFER, *PNABTSFEC_BUFFER;

//////////////////////////////////////////////////////////////
// vbi codec filtering pin properties
//////////////////////////////////////////////////////////////

#define STATIC_KSPROPSETID_VBICodecFiltering                                   \
  0xcafeb0caL, 0x8715, 0x11d0, 0xbd, 0x6a, 0x00, 0x35, 0xc0, 0xed, 0xba, 0xbe
DEFINE_GUIDSTRUCT("cafeb0ca-8715-11d0-bd6a-0035c0edbabe",
                  KSPROPSETID_VBICodecFiltering);
#define KSPROPSETID_VBICodecFiltering                                          \
  DEFINE_GUIDNAMED(KSPROPSETID_VBICodecFiltering)

typedef enum {
  KSPROPERTY_VBICODECFILTERING_SCANLINES_REQUESTED_BIT_ARRAY = 0x01,
  KSPROPERTY_VBICODECFILTERING_SCANLINES_DISCOVERED_BIT_ARRAY,
  KSPROPERTY_VBICODECFILTERING_SUBSTREAMS_REQUESTED_BIT_ARRAY,
  KSPROPERTY_VBICODECFILTERING_SUBSTREAMS_DISCOVERED_BIT_ARRAY,
  KSPROPERTY_VBICODECFILTERING_STATISTICS,
} KSPROPERTY_VBICODECFILTERING;

typedef struct _VBICODECFILTERING_SCANLINES {
  DWORD DwordBitArray[32]; // An array of scanline bits 0..1024(32*32)
} VBICODECFILTERING_SCANLINES, *PVBICODECFILTERING_SCANLINES;

typedef struct _VBICODECFILTERING_NABTS_SUBSTREAMS {
  DWORD
      SubstreamMask[128]; // An array of 4096 bits (one for each NABTS GroupID)
} VBICODECFILTERING_NABTS_SUBSTREAMS, *PVBICODECFILTERING_NABTS_SUBSTREAMS;

typedef struct _VBICODECFILTERING_CC_SUBSTREAMS {
  DWORD SubstreamMask; // An array of 32 bits (see KS_CC_SUBSTREAM *)
} VBICODECFILTERING_CC_SUBSTREAMS, *PVBICODECFILTERING_CC_SUBSTREAMS;

// These KS_CC_SUBSTREAM_* bitmasks are used with
// VBICODECFILTERING_CC_SUBSTREAMS
#define KS_CC_SUBSTREAM_ODD 0x0001L  // Unfiltered Field 1 Data
#define KS_CC_SUBSTREAM_EVEN 0x0002L // Unfiltered Field 2 Data

// The following flags describe CC field 1 substreams: CC1,CC2,TT1,TT2
#define KS_CC_SUBSTREAM_FIELD1_MASK 0x00F0L
#define KS_CC_SUBSTREAM_SERVICE_CC1 0x0010L
#define KS_CC_SUBSTREAM_SERVICE_CC2 0x0020L
#define KS_CC_SUBSTREAM_SERVICE_T1 0x0040L
#define KS_CC_SUBSTREAM_SERVICE_T2 0x0080L

// The following flags describe CC field 2 substreams: CC3,CC4,TT3,TT4,XDS
#define KS_CC_SUBSTREAM_FIELD2_MASK 0x1F00L
#define KS_CC_SUBSTREAM_SERVICE_CC3 0x0100L
#define KS_CC_SUBSTREAM_SERVICE_CC4 0x0200L
#define KS_CC_SUBSTREAM_SERVICE_T3 0x0400L
#define KS_CC_SUBSTREAM_SERVICE_T4 0x0800L
#define KS_CC_SUBSTREAM_SERVICE_XDS 0x1000L

// Special Note: field 1 or 2 substreams are usually on found on field 1 and 2
// respectively If the VBI odd/even polarity is reversed, the correct filtered
// data will still be found.

///////////////////////////////////////////////////////////////////
// Hardware decoded CC stream format
///////////////////////////////////////////////////////////////////

#define CC_MAX_HW_DECODE_LINES 12
typedef struct _CC_BYTE_PAIR {
  BYTE Decoded[2];
  USHORT Reserved;
} CC_BYTE_PAIR, *PCC_BYTE_PAIR;

typedef struct _CC_HW_FIELD {
  VBICODECFILTERING_SCANLINES ScanlinesRequested;
  ULONG fieldFlags; // KS_VBI_FLAG_FIELD1,2
  LONGLONG PictureNumber;
  CC_BYTE_PAIR Lines[CC_MAX_HW_DECODE_LINES];
} CC_HW_FIELD, *PCC_HW_FIELD;

///////////////////////////////////////////////////////////////////
// Raw NABTS stream format (TYPE_NABTS, SUBTYPE_NABTS)
///////////////////////////////////////////////////////////////////

// These low-level structures are byte packed( -Zp1 )
#if !defined(PACK_PRAGMAS_NOT_SUPPORTED)
#include <pshpack1.h>
#endif
typedef struct _NABTS_BUFFER_LINE {
  BYTE Confidence;
  BYTE Bytes[NABTS_BYTES_PER_LINE];
} NABTS_BUFFER_LINE, *PNABTS_BUFFER_LINE;

#define NABTS_BUFFER_PICTURENUMBER_SUPPORT 1
typedef struct _NABTS_BUFFER {
  VBICODECFILTERING_SCANLINES ScanlinesRequested;
  LONGLONG PictureNumber;
  NABTS_BUFFER_LINE NabtsLines[MAX_NABTS_VBI_LINES_PER_FIELD];
} NABTS_BUFFER, *PNABTS_BUFFER;
#if !defined(PACK_PRAGMAS_NOT_SUPPORTED)
#include <poppack.h>
#endif

//////////////////////////////////////////////////////////////
// WST Codec Teletext Media Sample Format
//////////////////////////////////////////////////////////////

#define WST_TVTUNER_CHANGE_BEGIN_TUNE 0x1000L // Starting a tuning operation
#define WST_TVTUNER_CHANGE_END_TUNE 0x2000L   // Ending a tuning operation

#define MAX_WST_VBI_LINES_PER_FIELD 17
#define WST_BYTES_PER_LINE 42

typedef struct _WST_BUFFER_LINE {
  BYTE Confidence;
  BYTE Bytes[WST_BYTES_PER_LINE];
} WST_BUFFER_LINE, *PWST_BUFFER_LINE;

typedef struct _WST_BUFFER {
  VBICODECFILTERING_SCANLINES ScanlinesRequested;
  WST_BUFFER_LINE WstLines[MAX_WST_VBI_LINES_PER_FIELD];
} WST_BUFFER, *PWST_BUFFER;

//
// Common codec statistics
//

typedef struct _VBICODECFILTERING_STATISTICS_COMMON {
  DWORD InputSRBsProcessed;   // upstream SRBs received
  DWORD OutputSRBsProcessed;  // downstream SRBs sent
  DWORD SRBsIgnored;          // SRBs ignored due to no requests
  DWORD InputSRBsMissing;     // SRBs dropped upstream
  DWORD OutputSRBsMissing;    // Output dropped because no SRB pending
  DWORD OutputFailures;       // dropped because of other failure
  DWORD InternalErrors;       // could not process due to int. failure
  DWORD ExternalErrors;       // could not process due to ext. failure
  DWORD InputDiscontinuities; // discontinuities received
  DWORD DSPFailures;          // DSP confidence failure
  DWORD TvTunerChanges;   // number of received KS_TVTUNER_CHANGE_BEGIN_TUNE and
                          // KS_TVTUNER_CHANGE_END_TUNE pairs.
  DWORD VBIHeaderChanges; // number of received KS_VBI_FLAG_VBIINFOHEADER_CHANGE
  DWORD LineConfidenceAvg; // Average of all DSP confidence results
  DWORD BytesOutput;       // Bytes sent downstream
} VBICODECFILTERING_STATISTICS_COMMON, *PVBICODECFILTERING_STATISTICS_COMMON;

typedef struct _VBICODECFILTERING_STATISTICS_COMMON_PIN {
  DWORD SRBsProcessed;     // SRBs sent/received
  DWORD SRBsIgnored;       // SRBs ignored due to filtering
  DWORD SRBsMissing;       // SRBs not sent/received
  DWORD InternalErrors;    // could not send/receive due to int. failure
  DWORD ExternalErrors;    // could not send/receive due to ext. failure
  DWORD Discontinuities;   // discontinuities received/sent
  DWORD LineConfidenceAvg; // Average of all DSP confidence results for this pin
  DWORD BytesOutput;       // Bytes sent downstream
} VBICODECFILTERING_STATISTICS_COMMON_PIN,
    *PVBICODECFILTERING_STATISTICS_COMMON_PIN;

//
// Codec-specific statistics - NABTS
//

typedef struct _VBICODECFILTERING_STATISTICS_NABTS {
  VBICODECFILTERING_STATISTICS_COMMON Common; // Generic VBI statistics
  DWORD FECBundleBadLines;                    // Un-FEC-correctable lines
  DWORD FECQueueOverflows;     // Number of times FEC queue overflowed
  DWORD FECCorrectedLines;     // Lines CSUM corrected by FEC
  DWORD FECUncorrectableLines; // FEC input lines not CSUM correctable
  DWORD BundlesProcessed;      // Bundles received from FEC
  DWORD BundlesSent2IP;        // Bundles sent to IP driver
  DWORD FilteredLines;         // Lines processed and then dropped
                               // because no one was interested
} VBICODECFILTERING_STATISTICS_NABTS, *PVBICODECFILTERING_STATISTICS_NABTS;

typedef struct _VBICODECFILTERING_STATISTICS_NABTS_PIN {
  VBICODECFILTERING_STATISTICS_COMMON_PIN Common; // Generic VBI pin statistics
} VBICODECFILTERING_STATISTICS_NABTS_PIN,
    *PVBICODECFILTERING_STATISTICS_NABTS_PIN;

//
// Codec-specific statistics - Closed Caption
//

typedef struct _VBICODECFILTERING_STATISTICS_CC {
  VBICODECFILTERING_STATISTICS_COMMON Common; // Generic VBI statistics
} VBICODECFILTERING_STATISTICS_CC, *PVBICODECFILTERING_STATISTICS_CC;

typedef struct _VBICODECFILTERING_STATISTICS_CC_PIN {
  VBICODECFILTERING_STATISTICS_COMMON_PIN Common; // Generic VBI pin statistics
} VBICODECFILTERING_STATISTICS_CC_PIN, *PVBICODECFILTERING_STATISTICS_CC_PIN;

//
// Codec-specific statistics - Closed Caption
//

typedef struct _VBICODECFILTERING_STATISTICS_TELETEXT {
  VBICODECFILTERING_STATISTICS_COMMON Common; // Generic VBI statistics
} VBICODECFILTERING_STATISTICS_TELETEXT,
    *PVBICODECFILTERING_STATISTICS_TELETEXT;

typedef struct _VBICODECFILTERING_STATISTICS_TELETEXT_PIN {
  VBICODECFILTERING_STATISTICS_COMMON_PIN Common; // Generic VBI pin statistics
} VBICODECFILTERING_STATISTICS_TELETEXT_PIN,
    *PVBICODECFILTERING_STATISTICS_TELETEXT_PIN;

////////////////////////////////////////////////////////////////////////////
// VBI codec property structures(based on KSPROPERTY_VBICODECFILTERING enum)
////////////////////////////////////////////////////////////////////////////

// *** Most codecs support this property
//    KSPROPERTY_VBICODECFILTERING_SCANLINES_REQUESTED_BIT_ARRAY
//    KSPROPERTY_VBICODECFILTERING_SCANLINES_DISCOVERED_BIT_ARRAY,
typedef struct {
  KSPROPERTY Property;
  VBICODECFILTERING_SCANLINES Scanlines;
} KSPROPERTY_VBICODECFILTERING_SCANLINES_S,
    *PKSPROPERTY_VBICODECFILTERING_SCANLINES_S;

// *** NABTS codecs support this property
//    KSPROPERTY_VBICODECFILTERING_SUBSTREAMS_REQUESTED_BIT_ARRAY,
//    KSPROPERTY_VBICODECFILTERING_SUBSTREAMS_DISCOVERED_BIT_ARRAY,
typedef struct {
  KSPROPERTY Property;
  VBICODECFILTERING_NABTS_SUBSTREAMS Substreams;
} KSPROPERTY_VBICODECFILTERING_NABTS_SUBSTREAMS_S,
    *PKSPROPERTY_VBICODECFILTERING_NABTS_SUBSTREAMS_S;

// *** Closed captioning codecs support this property
//    KSPROPERTY_VBICODECFILTERING_SUBSTREAMS_REQUESTED_BIT_ARRAY,
//    KSPROPERTY_VBICODECFILTERING_SUBSTREAMS_DISCOVERED_BIT_ARRAY,
typedef struct {
  KSPROPERTY Property;
  VBICODECFILTERING_CC_SUBSTREAMS Substreams;
} KSPROPERTY_VBICODECFILTERING_CC_SUBSTREAMS_S,
    *PKSPROPERTY_VBICODECFILTERING_CC_SUBSTREAMS_S;

// *** Most codecs support these versions of the global and pin properties
//    KSPROPERTY_VBICODECFILTERING_STATISTICS
typedef struct {
  KSPROPERTY Property;
  VBICODECFILTERING_STATISTICS_COMMON Statistics;
} KSPROPERTY_VBICODECFILTERING_STATISTICS_COMMON_S,
    *PKSPROPERTY_VBICODECFILTERING_STATISTICS_COMMON_S;

typedef struct {
  KSPROPERTY Property;
  VBICODECFILTERING_STATISTICS_COMMON_PIN Statistics;
} KSPROPERTY_VBICODECFILTERING_STATISTICS_COMMON_PIN_S,
    *PKSPROPERTY_VBICODECFILTERING_STATISTICS_COMMON_PIN_S;

// *** NABTS codecs support this version of the global and pin properties
//    KSPROPERTY_VBICODECFILTERING_STATISTICS
typedef struct {
  KSPROPERTY Property;
  VBICODECFILTERING_STATISTICS_NABTS Statistics;
} KSPROPERTY_VBICODECFILTERING_STATISTICS_NABTS_S,
    *PKSPROPERTY_VBICODECFILTERING_STATISTICS_NABTS_S;

typedef struct {
  KSPROPERTY Property;
  VBICODECFILTERING_STATISTICS_NABTS_PIN Statistics;
} KSPROPERTY_VBICODECFILTERING_STATISTICS_NABTS_PIN_S,
    *PKSPROPERTY_VBICODECFILTERING_STATISTICS_NABTS_PIN_S;

// *** Closed captioning codecs support this version of the global and pin
// properties
//    KSPROPERTY_VBICODECFILTERING_STATISTICS

typedef struct {
  KSPROPERTY Property;
  VBICODECFILTERING_STATISTICS_CC Statistics;
} KSPROPERTY_VBICODECFILTERING_STATISTICS_CC_S,
    *PKSPROPERTY_VBICODECFILTERING_STATISTICS_CC_S;

typedef struct {
  KSPROPERTY Property;
  VBICODECFILTERING_STATISTICS_CC_PIN Statistics;
} KSPROPERTY_VBICODECFILTERING_STATISTICS_CC_PIN_S,
    *PKSPROPERTY_VBICODECFILTERING_STATISTICS_CC_PIN_S;

// Standard Pin Names for the video capture filter
//===========================================================================

#define STATIC_PINNAME_VIDEO_CAPTURE                                           \
  0xfb6c4281, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
#define STATIC_PINNAME_CAPTURE STATIC_PINNAME_VIDEO_CAPTURE
DEFINE_GUIDSTRUCT("FB6C4281-0353-11d1-905F-0000C0CC16BA",
                  PINNAME_VIDEO_CAPTURE);
#define PINNAME_VIDEO_CAPTURE DEFINE_GUIDNAMED(PINNAME_VIDEO_CAPTURE)
#define PINNAME_CAPTURE PINNAME_VIDEO_CAPTURE

#define STATIC_PINNAME_VIDEO_CC_CAPTURE                                        \
  0x1aad8061, 0x12d, 0x11d2, 0xb4, 0xb1, 0x0, 0xa0, 0xd1, 0x2, 0xcf, 0xbe
#define STATIC_PINNAME_CC_CAPTURE STATIC_PINNAME_VIDEO_CC_CAPTURE
DEFINE_GUIDSTRUCT("1AAD8061-012D-11d2-B4B1-00A0D102CFBE",
                  PINNAME_VIDEO_CC_CAPTURE);
#define PINNAME_VIDEO_CC_CAPTURE DEFINE_GUIDNAMED(PINNAME_VIDEO_CC_CAPTURE)

#define STATIC_PINNAME_VIDEO_NABTS_CAPTURE                                     \
  0x29703660, 0x498a, 0x11d2, 0xb4, 0xb1, 0x0, 0xa0, 0xd1, 0x2, 0xcf, 0xbe
#define STATIC_PINNAME_NABTS_CAPTURE STATIC_PINNAME_VIDEO_NABTS_CAPTURE
DEFINE_GUIDSTRUCT("29703660-498A-11d2-B4B1-00A0D102CFBE",
                  PINNAME_VIDEO_NABTS_CAPTURE);
#define PINNAME_VIDEO_NABTS_CAPTURE                                            \
  DEFINE_GUIDNAMED(PINNAME_VIDEO_NABTS_CAPTURE)

#define STATIC_PINNAME_VIDEO_PREVIEW                                           \
  0xfb6c4282, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
#define STATIC_PINNAME_PREVIEW STATIC_PINNAME_VIDEO_PREVIEW
DEFINE_GUIDSTRUCT("FB6C4282-0353-11d1-905F-0000C0CC16BA",
                  PINNAME_VIDEO_PREVIEW);
#define PINNAME_VIDEO_PREVIEW DEFINE_GUIDNAMED(PINNAME_VIDEO_PREVIEW)
#define PINNAME_PREVIEW PINNAME_VIDEO_PREVIEW

#define STATIC_PINNAME_VIDEO_ANALOGVIDEOIN                                     \
  0xfb6c4283, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("FB6C4283-0353-11d1-905F-0000C0CC16BA",
                  PINNAME_VIDEO_ANALOGVIDEOIN);
#define PINNAME_VIDEO_ANALOGVIDEOIN                                            \
  DEFINE_GUIDNAMED(PINNAME_VIDEO_ANALOGVIDEOIN)

#define STATIC_PINNAME_VIDEO_VBI                                               \
  0xfb6c4284, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("FB6C4284-0353-11d1-905F-0000C0CC16BA", PINNAME_VIDEO_VBI);
#define PINNAME_VIDEO_VBI DEFINE_GUIDNAMED(PINNAME_VIDEO_VBI)

#define STATIC_PINNAME_VIDEO_VIDEOPORT                                         \
  0xfb6c4285, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("FB6C4285-0353-11d1-905F-0000C0CC16BA",
                  PINNAME_VIDEO_VIDEOPORT);
#define PINNAME_VIDEO_VIDEOPORT DEFINE_GUIDNAMED(PINNAME_VIDEO_VIDEOPORT)

#define STATIC_PINNAME_VIDEO_NABTS                                             \
  0xfb6c4286, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("FB6C4286-0353-11d1-905F-0000C0CC16BA", PINNAME_VIDEO_NABTS);
#define PINNAME_VIDEO_NABTS DEFINE_GUIDNAMED(PINNAME_VIDEO_NABTS)

#define STATIC_PINNAME_VIDEO_EDS                                               \
  0xfb6c4287, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("FB6C4287-0353-11d1-905F-0000C0CC16BA", PINNAME_VIDEO_EDS);
#define PINNAME_VIDEO_EDS DEFINE_GUIDNAMED(PINNAME_VIDEO_EDS)

#define STATIC_PINNAME_VIDEO_TELETEXT                                          \
  0xfb6c4288, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("FB6C4288-0353-11d1-905F-0000C0CC16BA",
                  PINNAME_VIDEO_TELETEXT);
#define PINNAME_VIDEO_TELETEXT DEFINE_GUIDNAMED(PINNAME_VIDEO_TELETEXT)

#define STATIC_PINNAME_VIDEO_CC                                                \
  0xfb6c4289, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("FB6C4289-0353-11d1-905F-0000C0CC16BA", PINNAME_VIDEO_CC);
#define PINNAME_VIDEO_CC DEFINE_GUIDNAMED(PINNAME_VIDEO_CC)

#define STATIC_PINNAME_VIDEO_STILL                                             \
  0xfb6c428A, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("FB6C428A-0353-11d1-905F-0000C0CC16BA", PINNAME_VIDEO_STILL);
#define PINNAME_VIDEO_STILL DEFINE_GUIDNAMED(PINNAME_VIDEO_STILL)

#define STATIC_PINNAME_VIDEO_TIMECODE                                          \
  0xfb6c428B, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("FB6C428B-0353-11d1-905F-0000C0CC16BA",
                  PINNAME_VIDEO_TIMECODE);
#define PINNAME_VIDEO_TIMECODE DEFINE_GUIDNAMED(PINNAME_VIDEO_TIMECODE)

#define STATIC_PINNAME_VIDEO_VIDEOPORT_VBI                                     \
  0xfb6c428C, 0x353, 0x11d1, 0x90, 0x5f, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("FB6C428C-0353-11d1-905F-0000C0CC16BA",
                  PINNAME_VIDEO_VIDEOPORT_VBI);
#define PINNAME_VIDEO_VIDEOPORT_VBI                                            \
  DEFINE_GUIDNAMED(PINNAME_VIDEO_VIDEOPORT_VBI)

//===========================================================================
// KSSTREAM_HEADER extensions for digital video
//===========================================================================

#define KS_VIDEO_FLAG_FRAME 0x0000L // Frame or Field (default is frame)
#define KS_VIDEO_FLAG_FIELD1 0x0001L
#define KS_VIDEO_FLAG_FIELD2 0x0002L

#define KS_VIDEO_FLAG_I_FRAME 0x0000L // I, B, or P (default is I)
#define KS_VIDEO_FLAG_P_FRAME 0x0010L
#define KS_VIDEO_FLAG_B_FRAME 0x0020L

typedef struct tagKS_FRAME_INFO {
  ULONG ExtendedHeaderSize; // Size of this extended header
  DWORD dwFrameFlags;       // Field1, Field2, or Frame
  LONGLONG PictureNumber;
  LONGLONG DropCount;

  // The following are only set when using OverlayMixer
  HANDLE hDirectDraw;    // user mode DDraw handle
  HANDLE hSurfaceHandle; // user mode surface handle
  RECT DirectDrawRect;   // portion of surface locked
  // Reserved fields, never reference these
  DWORD Reserved1;
  DWORD Reserved2;
  DWORD Reserved3;
  DWORD Reserved4;
} KS_FRAME_INFO, *PKS_FRAME_INFO;

//===========================================================================
// KSSTREAM_HEADER extensions for VBI
//===========================================================================

#define KS_VBI_FLAG_FIELD1 0x0001L
#define KS_VBI_FLAG_FIELD2 0x0002L

#define KS_VBI_FLAG_MV_PRESENT 0x0100L
#define KS_VBI_FLAG_MV_HARDWARE 0x0200L
#define KS_VBI_FLAG_MV_DETECTED 0x0400L

#define KS_VBI_FLAG_TVTUNER_CHANGE 0x0010L       // TvTunerChangeInfo is valid
#define KS_VBI_FLAG_VBIINFOHEADER_CHANGE 0x0020L // VBIInfoHeader is valid

typedef struct tagKS_VBI_FRAME_INFO {
  ULONG ExtendedHeaderSize; // Size of this extended header
  DWORD dwFrameFlags;       // Field1, Field2, or Frame; & etc
  LONGLONG PictureNumber;   // Test only?
  LONGLONG DropCount;       // Test only?
  DWORD dwSamplingFrequency;
  KS_TVTUNER_CHANGE_INFO TvTunerChangeInfo;
  KS_VBIINFOHEADER VBIInfoHeader;
} KS_VBI_FRAME_INFO, *PKS_VBI_FRAME_INFO;

//===========================================================================
// Analog video formats, used with:
//      Analog Video Decoders
//      TVTuners
//      Analog Video Encoders
//
// XXX_STANDARDS_SUPPORTED returns a bitmask
//===========================================================================

typedef enum {
  KS_AnalogVideo_None = 0x00000000,     // This is a digital sensor
  KS_AnalogVideo_NTSC_M = 0x00000001,   //        75 IRE Setup
  KS_AnalogVideo_NTSC_M_J = 0x00000002, // Japan,  0 IRE Setup
  KS_AnalogVideo_NTSC_433 = 0x00000004,

  KS_AnalogVideo_PAL_B = 0x00000010,
  KS_AnalogVideo_PAL_D = 0x00000020,
  KS_AnalogVideo_PAL_G = 0x00000040,
  KS_AnalogVideo_PAL_H = 0x00000080,
  KS_AnalogVideo_PAL_I = 0x00000100,
  KS_AnalogVideo_PAL_M = 0x00000200,
  KS_AnalogVideo_PAL_N = 0x00000400,

  KS_AnalogVideo_PAL_60 = 0x00000800,

  KS_AnalogVideo_SECAM_B = 0x00001000,
  KS_AnalogVideo_SECAM_D = 0x00002000,
  KS_AnalogVideo_SECAM_G = 0x00004000,
  KS_AnalogVideo_SECAM_H = 0x00008000,
  KS_AnalogVideo_SECAM_K = 0x00010000,
  KS_AnalogVideo_SECAM_K1 = 0x00020000,
  KS_AnalogVideo_SECAM_L = 0x00040000,
  KS_AnalogVideo_SECAM_L1 = 0x00080000,

  KS_AnalogVideo_PAL_N_COMBO = 0x00100000
} KS_AnalogVideoStandard;

#define KS_AnalogVideo_NTSC_Mask 0x00000007
#define KS_AnalogVideo_PAL_Mask 0x00100FF0
#define KS_AnalogVideo_SECAM_Mask 0x000FF000

//===========================================================================
// Property set definitions
// The comments show whether a given property is:
//      R  : READ only
//      w  : WRITE only
//      RW : READ / WRITE
//      O  : Optional (return E_UNSUPPORTED if you don't handle this)
//===========================================================================

#define STATIC_PROPSETID_ALLOCATOR_CONTROL                                     \
  0x53171960, 0x148e, 0x11d2, 0x99, 0x79, 0x0, 0x0, 0xc0, 0xcc, 0x16, 0xba
DEFINE_GUIDSTRUCT("53171960-148E-11d2-9979-0000C0CC16BA",
                  PROPSETID_ALLOCATOR_CONTROL);
#define PROPSETID_ALLOCATOR_CONTROL                                            \
  DEFINE_GUIDNAMED(PROPSETID_ALLOCATOR_CONTROL)
typedef enum {
  KSPROPERTY_ALLOCATOR_CONTROL_HONOR_COUNT,  // R O (will allocate exactly this
                                             // number of buffers)
  KSPROPERTY_ALLOCATOR_CONTROL_SURFACE_SIZE, // R O (return 2 DWORDs specifying
                                             // surface size)
  // W I (informn a capture driver whether interleave capture is possible or
  //      not - a value of 1 means that interleaved capture is supported)
  KSPROPERTY_ALLOCATOR_CONTROL_CAPTURE_CAPS,

  // R O (if value == 1, then the ovmixer will turn on the DDVP_INTERLEAVE
  //      flag thus allowing interleaved capture of the video)
  KSPROPERTY_ALLOCATOR_CONTROL_CAPTURE_INTERLEAVE,
} KSPROPERTY_ALLOCATOR_CONTROL;

typedef struct {
  // KSPROPERTY Property;
  ULONG CX;
  ULONG CY;
} KSPROPERTY_ALLOCATOR_CONTROL_SURFACE_SIZE_S,
    *PKSPROPERTY_ALLOCATOR_CONTROL_SURFACE_SIZE_S;

typedef struct {
  // KSPROPERTY Property;
  ULONG InterleavedCapSupported;
} KSPROPERTY_ALLOCATOR_CONTROL_CAPTURE_CAPS_S,
    *PKSPROPERTY_ALLOCATOR_CONTROL_CAPTURE_CAPS_S;

typedef struct {
  // KSPROPERTY Property;
  ULONG InterleavedCapPossible;
} KSPROPERTY_ALLOCATOR_CONTROL_CAPTURE_INTERLEAVE_S,
    *PKSPROPERTY_ALLOCATOR_CONTROL_CAPTURE_INTERLEAVE_S;

//===========================================================================

#define STATIC_PROPSETID_VIDCAP_VIDEOPROCAMP                                   \
  0xC6E13360L, 0x30AC, 0x11d0, 0xa1, 0x8c, 0x00, 0xA0, 0xC9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("C6E13360-30AC-11d0-A18C-00A0C9118956",
                  PROPSETID_VIDCAP_VIDEOPROCAMP);
#define PROPSETID_VIDCAP_VIDEOPROCAMP                                          \
  DEFINE_GUIDNAMED(PROPSETID_VIDCAP_VIDEOPROCAMP)

typedef enum {
  KSPROPERTY_VIDEOPROCAMP_BRIGHTNESS,               // RW O
  KSPROPERTY_VIDEOPROCAMP_CONTRAST,                 // RW O
  KSPROPERTY_VIDEOPROCAMP_HUE,                      // RW O
  KSPROPERTY_VIDEOPROCAMP_SATURATION,               // RW O
  KSPROPERTY_VIDEOPROCAMP_SHARPNESS,                // RW O
  KSPROPERTY_VIDEOPROCAMP_GAMMA,                    // RW O
  KSPROPERTY_VIDEOPROCAMP_COLORENABLE,              // RW O
  KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE,             // RW O
  KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION,   // RW O
  KSPROPERTY_VIDEOPROCAMP_GAIN,                     // RW O
  KSPROPERTY_VIDEOPROCAMP_DIGITAL_MULTIPLIER,       // RW O
  KSPROPERTY_VIDEOPROCAMP_DIGITAL_MULTIPLIER_LIMIT, // RW O
  KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE_COMPONENT,   // RW O
  KSPROPERTY_VIDEOPROCAMP_POWERLINE_FREQUENCY       // RW O
} KSPROPERTY_VIDCAP_VIDEOPROCAMP;

typedef struct {
  KSPROPERTY Property;
  LONG Value;         // Value to set or get
  ULONG Flags;        // KSPROPERTY_VIDEOPROCAMP_FLAGS_*
  ULONG Capabilities; // KSPROPERTY_VIDEOPROCAMP_FLAGS_*
} KSPROPERTY_VIDEOPROCAMP_S, *PKSPROPERTY_VIDEOPROCAMP_S;

typedef struct {
  KSP_NODE NodeProperty;
  LONG Value;         // Value to set or get
  ULONG Flags;        // KSPROPERTY_VIDEOPROCAMP_FLAGS_*
  ULONG Capabilities; // KSPROPERTY_VIDEOPROCAMP_FLAGS_*
} KSPROPERTY_VIDEOPROCAMP_NODE_S, *PKSPROPERTY_VIDEOPROCAMP_NODE_S;

typedef struct {
  KSPROPERTY Property;
  LONG Value1;
  ULONG Flags;
  ULONG Capabilities;
  LONG Value2;
} KSPROPERTY_VIDEOPROCAMP_S2, *PKSPROPERTY_VIDEOPROCAMP_S2;

typedef struct {
  KSP_NODE NodeProperty;
  LONG Value1;
  ULONG Flags;
  ULONG Capabilities;
  LONG Value2;
} KSPROPERTY_VIDEOPROCAMP_NODE_S2, *PKSPROPERTY_VIDEOPROCAMP_NODE_S2;

#define KSPROPERTY_VIDEOPROCAMP_FLAGS_AUTO 0X0001L
#define KSPROPERTY_VIDEOPROCAMP_FLAGS_MANUAL 0X0002L

//===========================================================================

#define STATIC_PROPSETID_VIDCAP_SELECTOR                                       \
  0x1ABDAECA, 0x68B6, 0x4F83, 0x93, 0x71, 0xB4, 0x13, 0x90, 0x7C, 0x7B, 0x9F
DEFINE_GUIDSTRUCT("1ABDAECA-68B6-4F83-9371-B413907C7B9F",
                  PROPSETID_VIDCAP_SELECTOR);
#define PROPSETID_VIDCAP_SELECTOR DEFINE_GUIDNAMED(PROPSETID_VIDCAP_SELECTOR)

typedef enum {
  KSPROPERTY_SELECTOR_SOURCE_NODE_ID, // RW
  KSPROPERTY_SELECTOR_NUM_SOURCES     // R
} KSPROPERTY_VIDCAP_SELECTOR,
    *PKSPROPERTY_VIDCAP_SELECTOR;

typedef struct {
  KSPROPERTY Property;
  LONG Value; // Value to set or get
  ULONG Flags;
  ULONG Capabilities;
} KSPROPERTY_SELECTOR_S, *PKSPROPERTY_SELECTOR_S;

typedef struct {
  KSP_NODE NodeProperty;
  LONG Value; // Value to set or get
  ULONG Flags;
  ULONG Capabilities;
} KSPROPERTY_SELECTOR_NODE_S, *PKSPROPERTY_SELECTOR_NODE_S;

//===========================================================================

#define STATIC_PROPSETID_TUNER                                                 \
  0x6a2e0605L, 0x28e4, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0xc9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("6a2e0605-28e4-11d0-a18c-00a0c9118956", PROPSETID_TUNER);
#define PROPSETID_TUNER DEFINE_GUIDNAMED(PROPSETID_TUNER)

typedef enum {
  KSPROPERTY_TUNER_CAPS,      // R  -overall device capabilities
  KSPROPERTY_TUNER_MODE_CAPS, // R  -capabilities in this mode
  KSPROPERTY_TUNER_MODE,      // RW -set a mode (TV, FM, AM, DSS)
  KSPROPERTY_TUNER_STANDARD,  // R  -get TV standard (only if TV mode)
  KSPROPERTY_TUNER_FREQUENCY, // RW -set/get frequency
  KSPROPERTY_TUNER_INPUT,     // RW -select an input
  KSPROPERTY_TUNER_STATUS,    // R  -tuning status
  KSPROPERTY_TUNER_IF_MEDIUM  // R O-Medium for IF or Transport Pin
} KSPROPERTY_TUNER;

typedef enum {
  KSPROPERTY_TUNER_MODE_TV = 0X0001,
  KSPROPERTY_TUNER_MODE_FM_RADIO = 0X0002,
  KSPROPERTY_TUNER_MODE_AM_RADIO = 0X0004,
  KSPROPERTY_TUNER_MODE_DSS = 0X0008,
  KSPROPERTY_TUNER_MODE_ATSC = 0X0010, // also used for DVB-T, DVB-C
} KSPROPERTY_TUNER_MODES;

// Describes how the device tunes.  Only one of these flags may be set
// in KSPROPERTY_TUNER_MODE_CAPS_S.Strategy

// Describe how the driver should attempt to tune:
// EXACT:   just go to the frequency specified (no fine tuning)
// FINE:    (slow) do an exhaustive search for the best signal
// COARSE:  (fast) use larger frequency jumps to just determine if any signal

typedef enum {
  KS_TUNER_TUNING_EXACT = 1, // No fine tuning
  KS_TUNER_TUNING_FINE,      // Fine grained search
  KS_TUNER_TUNING_COARSE,    // Coarse search
} KS_TUNER_TUNING_FLAGS;

typedef enum {
  KS_TUNER_STRATEGY_PLL = 0X01,             // Tune by PLL offset
  KS_TUNER_STRATEGY_SIGNAL_STRENGTH = 0X02, // Tune by signal strength
  KS_TUNER_STRATEGY_DRIVER_TUNES = 0X04,    // Driver does fine tuning
} KS_TUNER_STRATEGY;

typedef struct {
  KSPROPERTY Property;
  ULONG ModesSupported;          // KS_PROPERTY_TUNER_MODES_*
  KSPIN_MEDIUM VideoMedium;      // GUID_NULL (no pin), or GUID
  KSPIN_MEDIUM TVAudioMedium;    // GUID_NULL (no pin), or GUID
  KSPIN_MEDIUM RadioAudioMedium; // GUID_NULL (no pin), or GUID
} KSPROPERTY_TUNER_CAPS_S, *PKSPROPERTY_TUNER_CAPS_S;

typedef struct {
  KSPROPERTY Property;
  KSPIN_MEDIUM IFMedium; // GUID_NULL (no pin), or GUID
} KSPROPERTY_TUNER_IF_MEDIUM_S, *PKSPROPERTY_TUNER_IF_MEDIUM_S;

typedef struct {
  KSPROPERTY Property;
  ULONG Mode;               // IN: KSPROPERTY_TUNER_MODE
  ULONG StandardsSupported; // KS_AnalogVideo_* (if TV or DSS)
  ULONG MinFrequency;       // Hz
  ULONG MaxFrequency;       // Hz
  ULONG TuningGranularity;  // Hz
  ULONG NumberOfInputs;     // count of inputs
  ULONG SettlingTime;       // milliSeconds
  ULONG Strategy;           // KS_TUNER_STRATEGY
} KSPROPERTY_TUNER_MODE_CAPS_S, *PKSPROPERTY_TUNER_MODE_CAPS_S;

typedef struct {
  KSPROPERTY Property;
  ULONG Mode; // IN: KSPROPERTY_TUNER_MODE
} KSPROPERTY_TUNER_MODE_S, *PKSPROPERTY_TUNER_MODE_S;

typedef struct {
  KSPROPERTY Property;
  ULONG Frequency;       // Hz
  ULONG LastFrequency;   // Hz (last known good)
  ULONG TuningFlags;     // KS_TUNER_TUNING_FLAGS
  ULONG VideoSubChannel; // DSS
  ULONG AudioSubChannel; // DSS
  ULONG Channel;         // VBI decoders
  ULONG Country;         // VBI decoders
} KSPROPERTY_TUNER_FREQUENCY_S, *PKSPROPERTY_TUNER_FREQUENCY_S;

typedef struct {
  KSPROPERTY Property;
  ULONG Standard; // KS_AnalogVideo_*
} KSPROPERTY_TUNER_STANDARD_S, *PKSPROPERTY_TUNER_STANDARD_S;

typedef struct {
  KSPROPERTY Property;
  ULONG InputIndex; // 0 to (n-1) inputs
} KSPROPERTY_TUNER_INPUT_S, *PKSPROPERTY_TUNER_INPUT_S;

typedef struct {
  KSPROPERTY Property;
  ULONG CurrentFrequency; // Hz
  ULONG PLLOffset;        // if Strategy.KS_TUNER_STRATEGY_PLL
  ULONG SignalStrength;   // if Stretegy.KS_TUNER_STRATEGY_SIGNAL_STRENGTH
  ULONG Busy;             // TRUE if in the process of tuning
} KSPROPERTY_TUNER_STATUS_S, *PKSPROPERTY_TUNER_STATUS_S;

#define STATIC_EVENTSETID_TUNER                                                \
  0x6a2e0606L, 0x28e4, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0xc9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("6a2e0606-28e4-11d0-a18c-00a0c9118956", EVENTSETID_TUNER);
#define EVENTSETID_TUNER DEFINE_GUIDNAMED(EVENTSETID_TUNER)

typedef enum { KSEVENT_TUNER_CHANGED } KSEVENT_TUNER;

//===========================================================================

// USB Video Class Definitions

#define STATIC_KSNODETYPE_VIDEO_STREAMING                                      \
  0xDFF229E1L, 0xF70F, 0x11D0, 0xB9, 0x17, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("DFF229E1-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_VIDEO_STREAMING);
#define KSNODETYPE_VIDEO_STREAMING DEFINE_GUIDNAMED(KSNODETYPE_VIDEO_STREAMING)

#define STATIC_KSNODETYPE_VIDEO_INPUT_TERMINAL                                 \
  0xDFF229E2L, 0xF70F, 0x11D0, 0xB9, 0x17, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("DFF229E2-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_VIDEO_INPUT_TERMINAL);
#define KSNODETYPE_VIDEO_INPUT_TERMINAL                                        \
  DEFINE_GUIDNAMED(KSNODETYPE_VIDEO_INPUT_TERMINAL)

#define STATIC_KSNODETYPE_VIDEO_OUTPUT_TERMINAL                                \
  0xDFF229E3L, 0xF70F, 0x11D0, 0xB9, 0x17, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("DFF229E3-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_VIDEO_OUTPUT_TERMINAL);
#define KSNODETYPE_VIDEO_OUTPUT_TERMINAL                                       \
  DEFINE_GUIDNAMED(KSNODETYPE_VIDEO_OUTPUT_TERMINAL)

#define STATIC_KSNODETYPE_VIDEO_SELECTOR                                       \
  0xDFF229E4L, 0xF70F, 0x11D0, 0xB9, 0x17, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("DFF229E4-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_VIDEO_SELECTOR);
#define KSNODETYPE_VIDEO_SELECTOR DEFINE_GUIDNAMED(KSNODETYPE_VIDEO_SELECTOR)

#define STATIC_KSNODETYPE_VIDEO_PROCESSING                                     \
  0xDFF229E5L, 0xF70F, 0x11D0, 0xB9, 0x17, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("DFF229E5-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_VIDEO_PROCESSING);
#define KSNODETYPE_VIDEO_PROCESSING                                            \
  DEFINE_GUIDNAMED(KSNODETYPE_VIDEO_PROCESSING)

#define STATIC_KSNODETYPE_VIDEO_CAMERA_TERMINAL                                \
  0xDFF229E6L, 0xF70F, 0x11D0, 0xB9, 0x17, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("DFF229E6-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_VIDEO_CAMERA_TERMINAL);
#define KSNODETYPE_VIDEO_CAMERA_TERMINAL                                       \
  DEFINE_GUIDNAMED(KSNODETYPE_VIDEO_CAMERA_TERMINAL)

#define STATIC_KSNODETYPE_VIDEO_INPUT_MTT                                      \
  0xDFF229E7L, 0xF70F, 0x11D0, 0xB9, 0x17, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("DFF229E7-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_VIDEO_INPUT_MTT);
#define KSNODETYPE_VIDEO_INPUT_MTT DEFINE_GUIDNAMED(KSNODETYPE_VIDEO_INPUT_MTT)

#define STATIC_KSNODETYPE_VIDEO_OUTPUT_MTT                                     \
  0xDFF229E8L, 0xF70F, 0x11D0, 0xB9, 0x17, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("DFF229E8-F70F-11D0-B917-00A0C9223196",
                  KSNODETYPE_VIDEO_OUTPUT_MTT);
#define KSNODETYPE_VIDEO_OUTPUT_MTT                                            \
  DEFINE_GUIDNAMED(KSNODETYPE_VIDEO_OUTPUT_MTT)

//===========================================================================

#define STATIC_PROPSETID_VIDCAP_VIDEOENCODER                                   \
  0x6a2e0610L, 0x28e4, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0xc9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("6a2e0610-28e4-11d0-a18c-00a0c9118956",
                  PROPSETID_VIDCAP_VIDEOENCODER);
#define PROPSETID_VIDCAP_VIDEOENCODER                                          \
  DEFINE_GUIDNAMED(PROPSETID_VIDCAP_VIDEOENCODER)

typedef enum {
  KSPROPERTY_VIDEOENCODER_CAPS,           // R
  KSPROPERTY_VIDEOENCODER_STANDARD,       // RW
  KSPROPERTY_VIDEOENCODER_COPYPROTECTION, // RW O
  KSPROPERTY_VIDEOENCODER_CC_ENABLE,      // RW O
} KSPROPERTY_VIDCAP_VIDEOENCODER;

typedef struct {
  KSPROPERTY Property;
  LONG Value;         // value to get or set
  ULONG Flags;        //
  ULONG Capabilities; //
} KSPROPERTY_VIDEOENCODER_S, *PKSPROPERTY_VIDEOENCODER_S;

//===========================================================================

#define STATIC_PROPSETID_VIDCAP_VIDEODECODER                                   \
  0xC6E13350L, 0x30AC, 0x11d0, 0xA1, 0x8C, 0x00, 0xA0, 0xC9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("C6E13350-30AC-11d0-A18C-00A0C9118956",
                  PROPSETID_VIDCAP_VIDEODECODER);
#define PROPSETID_VIDCAP_VIDEODECODER                                          \
  DEFINE_GUIDNAMED(PROPSETID_VIDCAP_VIDEODECODER)

typedef enum {
  KSPROPERTY_VIDEODECODER_CAPS,          // R
  KSPROPERTY_VIDEODECODER_STANDARD,      // RW
  KSPROPERTY_VIDEODECODER_STATUS,        // R
  KSPROPERTY_VIDEODECODER_OUTPUT_ENABLE, // Rw O
  KSPROPERTY_VIDEODECODER_VCR_TIMING,    // RW O
} KSPROPERTY_VIDCAP_VIDEODECODER;

typedef enum {
  KS_VIDEODECODER_FLAGS_CAN_DISABLE_OUTPUT = 0X0001,  // VP Output can tri-stae
  KS_VIDEODECODER_FLAGS_CAN_USE_VCR_LOCKING = 0X0002, // VCR PLL timings
  KS_VIDEODECODER_FLAGS_CAN_INDICATE_LOCKED =
      0X0004, // Can indicate valid signal
} KS_VIDEODECODER_FLAGS;

typedef struct {
  KSPROPERTY Property;
  ULONG StandardsSupported; // KS_AnalogVideo_*
  ULONG Capabilities;       // KS_VIDEODECODER_FLAGS_*
  ULONG SettlingTime;       // milliseconds
  ULONG HSyncPerVSync;      // Number of HSync Pulses per VSync
} KSPROPERTY_VIDEODECODER_CAPS_S, *PKSPROPERTY_VIDEODECODER_CAPS_S;

typedef struct {
  KSPROPERTY Property;
  ULONG NumberOfLines; // 525 or 625 lines detected
  ULONG SignalLocked;  // TRUE if signal is locked
} KSPROPERTY_VIDEODECODER_STATUS_S, *PKSPROPERTY_VIDEODECODER_STATUS_S;

typedef struct {
  KSPROPERTY Property;
  ULONG Value; // Get or set a value
} KSPROPERTY_VIDEODECODER_S, *PKSPROPERTY_VIDEODECODER_S;

#define STATIC_EVENTSETID_VIDEODECODER                                         \
  0x6a2e0621L, 0x28e4, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0xc9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("6a2e0621-28e4-11d0-a18c-00a0c9118956",
                  EVENTSETID_VIDEODECODER);
#define EVENTSETID_VIDEODECODER DEFINE_GUIDNAMED(EVENTSETID_VIDEODECODER)

typedef enum { KSEVENT_VIDEODECODER_CHANGED } KSEVENT_VIDEODECODER;

//===========================================================================

#define STATIC_PROPSETID_VIDCAP_CAMERACONTROL                                  \
  0xC6E13370L, 0x30AC, 0x11d0, 0xa1, 0x8C, 0x00, 0xA0, 0xC9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("C6E13370-30AC-11d0-A18C-00A0C9118956",
                  PROPSETID_VIDCAP_CAMERACONTROL);
#define PROPSETID_VIDCAP_CAMERACONTROL                                         \
  DEFINE_GUIDNAMED(PROPSETID_VIDCAP_CAMERACONTROL)

typedef enum {
  KSPROPERTY_CAMERACONTROL_PAN,               // RW O
  KSPROPERTY_CAMERACONTROL_TILT,              // RW O
  KSPROPERTY_CAMERACONTROL_ROLL,              // RW O
  KSPROPERTY_CAMERACONTROL_ZOOM,              // RW O
  KSPROPERTY_CAMERACONTROL_EXPOSURE,          // RW O
  KSPROPERTY_CAMERACONTROL_IRIS,              // RW O
  KSPROPERTY_CAMERACONTROL_FOCUS,             // RW O
  KSPROPERTY_CAMERACONTROL_SCANMODE,          // RW O
  KSPROPERTY_CAMERACONTROL_PRIVACY,           // RW O
  KSPROPERTY_CAMERACONTROL_PANTILT,           // RW O
  KSPROPERTY_CAMERACONTROL_PAN_RELATIVE,      // RW O
  KSPROPERTY_CAMERACONTROL_TILT_RELATIVE,     // RW O
  KSPROPERTY_CAMERACONTROL_ROLL_RELATIVE,     // RW O
  KSPROPERTY_CAMERACONTROL_ZOOM_RELATIVE,     // RW O
  KSPROPERTY_CAMERACONTROL_EXPOSURE_RELATIVE, // RW O
  KSPROPERTY_CAMERACONTROL_IRIS_RELATIVE,     // RW O
  KSPROPERTY_CAMERACONTROL_FOCUS_RELATIVE,    // RW O
  KSPROPERTY_CAMERACONTROL_PANTILT_RELATIVE,  // RW O
  KSPROPERTY_CAMERACONTROL_FOCAL_LENGTH       // R O
} KSPROPERTY_VIDCAP_CAMERACONTROL;

typedef struct {
  KSPROPERTY Property;
  LONG Value;         // value to get or set
  ULONG Flags;        // KSPROPERTY_CAMERACONTROL_FLAGS_*
  ULONG Capabilities; // KSPROPERTY_CAMERACONTROL_FLAGS_*
} KSPROPERTY_CAMERACONTROL_S, *PKSPROPERTY_CAMERACONTROL_S;

typedef struct {
  KSP_NODE NodeProperty;
  LONG Value;         // value to get or set
  ULONG Flags;        // KSPROPERTY_CAMERACONTROL_FLAGS_*
  ULONG Capabilities; // KSPROPERTY_CAMERACONTROL_FLAGS_*
} KSPROPERTY_CAMERACONTROL_NODE_S, PKSPROPERTY_CAMERACONTROL_NODE_S;

typedef struct {
  KSPROPERTY Property;
  LONG Value1;
  ULONG Flags;
  ULONG Capabilities;
  LONG Value2;
} KSPROPERTY_CAMERACONTROL_S2, *PKSPROPERTY_CAMERACONTROL_S2;

typedef struct {
  KSP_NODE NodeProperty;
  LONG Value1;
  ULONG Flags;
  ULONG Capabilities;
  LONG Value2;
} KSPROPERTY_CAMERACONTROL_NODE_S2, *PKSPROPERTY_CAMERACONTROL_NODE_S2;

typedef struct {
  KSPROPERTY Property;
  LONG lOcularFocalLength;
  LONG lObjectiveFocalLengthMin;
  LONG lObjectiveFocalLengthMax;
} KSPROPERTY_CAMERACONTROL_FOCAL_LENGTH_S,
    *PKSPROPERTY_CAMERACONTROL_FOCAL_LENGTH_S;

typedef struct {
  KSNODEPROPERTY NodeProperty;
  LONG lOcularFocalLength;
  LONG lObjectiveFocalLengthMin;
  LONG lObjectiveFocalLengthMax;
} KSPROPERTY_CAMERACONTROL_NODE_FOCAL_LENGTH_S,
    *PKSPROPERTY_CAMERACONTROL_NODE_FOCAL_LENGTH_S;

#define KSPROPERTY_CAMERACONTROL_FLAGS_AUTO 0X0001L
#define KSPROPERTY_CAMERACONTROL_FLAGS_MANUAL 0X0002L

#define KSPROPERTY_CAMERACONTROL_FLAGS_ABSOLUTE 0X0000L
#define KSPROPERTY_CAMERACONTROL_FLAGS_RELATIVE 0X0010L

#ifndef __EDevCtrl__
#define __EDevCtrl__
//===========================================================================

#define STATIC_PROPSETID_EXT_DEVICE                                            \
  0xB5730A90L, 0x1A2C, 0x11cf, 0x8c, 0x23, 0x00, 0xAA, 0x00, 0x6B, 0x68, 0x14
DEFINE_GUIDSTRUCT("B5730A90-1A2C-11cf-8C23-00AA006B6814", PROPSETID_EXT_DEVICE);
#define PROPSETID_EXT_DEVICE DEFINE_GUIDNAMED(PROPSETID_EXT_DEVICE)

typedef enum {
  KSPROPERTY_EXTDEVICE_ID,           // R
  KSPROPERTY_EXTDEVICE_VERSION,      // R
  KSPROPERTY_EXTDEVICE_POWER_STATE,  // RW
  KSPROPERTY_EXTDEVICE_PORT,         // R
  KSPROPERTY_EXTDEVICE_CAPABILITIES, // R
} KSPROPERTY_EXTDEVICE;

typedef struct tagDEVCAPS {
  LONG CanRecord;
  LONG CanRecordStrobe;
  LONG HasAudio;
  LONG HasVideo;
  LONG UsesFiles;
  LONG CanSave;
  LONG DeviceType;
  LONG TCRead;
  LONG TCWrite;
  LONG CTLRead;
  LONG IndexRead;
  LONG Preroll;
  LONG Postroll;
  LONG SyncAcc;
  LONG NormRate;
  LONG CanPreview;
  LONG CanMonitorSrc;
  LONG CanTest;
  LONG VideoIn;
  LONG AudioIn;
  LONG Calibrate;
  LONG SeekType;
  LONG SimulatedHardware;
} DEVCAPS, *PDEVCAPS;

typedef struct {
  KSPROPERTY Property;
  union {
    DEVCAPS Capabilities;        // Device capabilities
    ULONG DevPort;               // 1394, USB, etc.
    ULONG PowerState;            // On, standby or off
    WCHAR pawchString[MAX_PATH]; // Version
    DWORD NodeUniqueID[2];       // Unique NodeID
  } u;
} KSPROPERTY_EXTDEVICE_S, *PKSPROPERTY_EXTDEVICE_S;

//===========================================================================

#define STATIC_PROPSETID_EXT_TRANSPORT                                         \
  0xA03CD5F0L, 0x3045, 0x11cf, 0x8c, 0x44, 0x00, 0xAA, 0x00, 0x6B, 0x68, 0x14
DEFINE_GUIDSTRUCT("A03CD5F0-3045-11cf-8C44-00AA006B6814",
                  PROPSETID_EXT_TRANSPORT);
#define PROPSETID_EXT_TRANSPORT DEFINE_GUIDNAMED(PROPSETID_EXT_TRANSPORT)

typedef enum {
  KSPROPERTY_EXTXPORT_CAPABILITIES,       // (R)  Transport specific capability
  KSPROPERTY_EXTXPORT_INPUT_SIGNAL_MODE,  // (RW) Input signal: e.g.
                                          // dvsd/NTSC/PAL, dvsl/NTSC/PAL,
                                          // MPEG2-TS etc
  KSPROPERTY_EXTXPORT_OUTPUT_SIGNAL_MODE, // (RW) Output signal: e.g.
                                          // dvsd/NTSC/PAL, dvsl/NTSC/PAL,
                                          // MPEG2-TS etc
  KSPROPERTY_EXTXPORT_LOAD_MEDIUM,        // (RW) Eject, open tray, close tray
  KSPROPERTY_EXTXPORT_MEDIUM_INFO,  // (R)  Cassettte type, tape grade and write
                                    // protection
  KSPROPERTY_EXTXPORT_STATE,        // (RW) Current transport mode and state
  KSPROPERTY_EXTXPORT_STATE_NOTIFY, // (RW) Notify of transport mode and state
                                    // change
  KSPROPERTY_EXTXPORT_TIMECODE_SEARCH, // (W)  Search to a specific timecode on
                                       // a tape
  KSPROPERTY_EXTXPORT_ATN_SEARCH, // (W)  Search to a specific absolute track
                                  // number (ATN) on a tape
  KSPROPERTY_EXTXPORT_RTC_SEARCH, // (W)  Search to a specific relative time
                                  // counter (RTC) on a tape
  KSPROPERTY_RAW_AVC_CMD,         // (RW) Issue a raw AVC commnad
} KSPROPERTY_EXTXPORT;

typedef struct tagTRANSPORTSTATUS {
  LONG Mode;
  LONG LastError;
  LONG RecordInhibit;
  LONG ServoLock;
  LONG MediaPresent;
  LONG MediaLength;
  LONG MediaSize;
  LONG MediaTrackCount;
  LONG MediaTrackLength;
  LONG MediaTrackSide;
  LONG MediaType;
  LONG LinkMode;
  LONG NotifyOn;
} TRANSPORTSTATUS, *PTRANSPORTSTATUS;

typedef struct tagTRANSPORTBASICPARMS {
  LONG TimeFormat;
  LONG TimeReference;
  LONG Superimpose;
  LONG EndStopAction;
  LONG RecordFormat;
  LONG StepFrames;
  LONG SetpField;
  LONG Preroll;
  LONG RecPreroll;
  LONG Postroll;
  LONG EditDelay;
  LONG PlayTCDelay;
  LONG RecTCDelay;
  LONG EditField;
  LONG FrameServo;
  LONG ColorFrameServo;
  LONG ServoRef;
  LONG WarnGenlock;
  LONG SetTracking;
  TCHAR VolumeName[40];
  LONG Ballistic[20];
  LONG Speed;
  LONG CounterFormat;
  LONG TunerChannel;
  LONG TunerNumber;
  LONG TimerEvent;
  LONG TimerStartDay;
  LONG TimerStartTime;
  LONG TimerStopDay;
  LONG TimerStopTime;
} TRANSPORTBASICPARMS, *PTRANSPORTBASICPARMS;

typedef struct tagTRANSPORTVIDEOPARMS {
  LONG OutputMode;
  LONG Input;
} TRANSPORTVIDEOPARMS, *PTRANSPORTVIDEOPARMS;

typedef struct tagTRANSPORTAUDIOPARMS {
  LONG EnableOutput;
  LONG EnableRecord;
  LONG EnableSelsync;
  LONG Input;
  LONG MonitorSource;
} TRANSPORTAUDIOPARMS, *PTRANSPORTAUDIOPARMS;

typedef struct {
  BOOL MediaPresent;
  ULONG MediaType;
  BOOL RecordInhibit;
} MEDIUM_INFO, *PMEDIUM_INFO;

typedef struct {
  ULONG Mode;
  ULONG State;
} TRANSPORT_STATE, *PTRANSPORT_STATE;

typedef struct {
  KSPROPERTY Property;
  union {
    ULONG Capabilities;
    ULONG SignalMode;
    ULONG LoadMedium;
    MEDIUM_INFO MediumInfo;
    TRANSPORT_STATE XPrtState;
    struct {
      BYTE frame;
      BYTE second;
      BYTE minute;
      BYTE hour;
    } Timecode;
    DWORD dwTimecode;
    DWORD dwAbsTrackNumber;
    struct {
      ULONG PayloadSize;
      BYTE Payload[512];
    } RawAVC;
  } u;

} KSPROPERTY_EXTXPORT_S, *PKSPROPERTY_EXTXPORT_S;

typedef struct {
  KSP_NODE NodeProperty;
  union {
    ULONG Capabilities;
    ULONG SignalMode;
    ULONG LoadMedium;
    MEDIUM_INFO MediumInfo;
    TRANSPORT_STATE XPrtState;
    struct {
      BYTE frame;
      BYTE second;
      BYTE minute;
      BYTE hour;
    } Timecode;
    DWORD dwTimecode;
    DWORD dwAbsTrackNumber;
    struct {
      ULONG PayloadSize;
      BYTE Payload[512];
    } RawAVC;
  } u;

} KSPROPERTY_EXTXPORT_NODE_S, *PKSPROPERTY_EXTXPORT_NODE_S;

//===========================================================================

#define STATIC_PROPSETID_TIMECODE_READER                                       \
  0x9B496CE1L, 0x811B, 0x11cf, 0x8C, 0x77, 0x00, 0xAA, 0x00, 0x6B, 0x68, 0x14
DEFINE_GUIDSTRUCT("9B496CE1-811B-11cf-8C77-00AA006B6814",
                  PROPSETID_TIMECODE_READER);
#define PROPSETID_TIMECODE_READER DEFINE_GUIDNAMED(PROPSETID_TIMECODE_READER)

typedef enum {
  KSPROPERTY_TIMECODE_READER, // (R) Timecode for the current tape position
  KSPROPERTY_ATN_READER,      // (R) Absolute track number for the current tape
                              // position
  KSPROPERTY_RTC_READER,      // (R) Relative time counter for the current tape
                              // position
} KSPROPERTY_TIMECODE;

#ifndef TIMECODE_DEFINED
#define TIMECODE_DEFINED
typedef union _timecode {
  struct {
    WORD wFrameRate;
    WORD wFrameFract;
    DWORD dwFrames;
  };
  DWORDLONG qw;
} TIMECODE;
typedef TIMECODE *PTIMECODE;

typedef struct tagTIMECODE_SAMPLE {
  LONGLONG qwTick;
  TIMECODE timecode;
  DWORD dwUser;
  DWORD dwFlags;
} TIMECODE_SAMPLE;

typedef TIMECODE_SAMPLE *PTIMECODE_SAMPLE;

#endif /* TIMECODE_DEFINED */

typedef struct {
  KSPROPERTY Property;
  TIMECODE_SAMPLE TimecodeSamp;
} KSPROPERTY_TIMECODE_S, *PKSPROPERTY_TIMECODE_S;

typedef struct {
  KSP_NODE NodeProperty;
  TIMECODE_SAMPLE TimecodeSamp;
} KSPROPERTY_TIMECODE_NODE_S, *PKSPROPERTY_TIMECODE_NODE_S;

//===========================================================================

#define STATIC_KSEVENTSETID_EXTDEV_Command                                     \
  0x109c7988L, 0xb3cb, 0x11d2, 0xb4, 0x8e, 0x00, 0x60, 0x97, 0xb3, 0x39, 0x1b
DEFINE_GUIDSTRUCT("109c7988-b3cb-11d2-b48e-006097b3391b",
                  KSEVENTSETID_EXTDEV_Command);
#define KSEVENTSETID_EXTDEV_Command                                            \
  DEFINE_GUIDNAMED(KSEVENTSETID_EXTDEV_Command)

typedef enum {
  KSEVENT_EXTDEV_COMMAND_NOTIFY_INTERIM_READY,  // Final response is ready for
                                                // notify command
  KSEVENT_EXTDEV_COMMAND_CONTROL_INTERIM_READY, // Final response is ready for
                                                // control command.
  KSEVENT_EXTDEV_COMMAND_BUSRESET,              // A bus reset has occured.
  KSEVENT_EXTDEV_TIMECODE_UPDATE,               // Timecode has changed.
  KSEVENT_EXTDEV_OPERATION_MODE_UPDATE,  // Operting mode (VCR,Camera, etc.) has
                                         // changed.
  KSEVENT_EXTDEV_TRANSPORT_STATE_UPDATE, // Transport state has changed.
  KSEVENT_EXTDEV_NOTIFY_REMOVAL,         // Device was surprise removal.
  KSEVENT_EXTDEV_NOTIFY_MEDIUM_CHANGE,   // Tape medium is removed or added.
} KSEVENT_DEVCMD;

#endif // __EDevCtrl__

//===========================================================================

#define STATIC_PROPSETID_VIDCAP_CROSSBAR                                       \
  0x6a2e0640L, 0x28e4, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0xc9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("6a2e0640-28e4-11d0-a18c-00a0c9118956",
                  PROPSETID_VIDCAP_CROSSBAR);
#define PROPSETID_VIDCAP_CROSSBAR DEFINE_GUIDNAMED(PROPSETID_VIDCAP_CROSSBAR)

typedef enum {
  KSPROPERTY_CROSSBAR_CAPS,      // R
  KSPROPERTY_CROSSBAR_PININFO,   // R
  KSPROPERTY_CROSSBAR_CAN_ROUTE, // R
  KSPROPERTY_CROSSBAR_ROUTE,     // RW
} KSPROPERTY_VIDCAP_CROSSBAR;

typedef struct {
  KSPROPERTY Property;
  ULONG NumberOfInputs;  // the number of audio and video input pins
  ULONG NumberOfOutputs; // the number of audio and video output pins
} KSPROPERTY_CROSSBAR_CAPS_S, *PKSPROPERTY_CROSSBAR_CAPS_S;

typedef struct {
  KSPROPERTY Property;
  KSPIN_DATAFLOW Direction; // KSPIN_DATAFLOW_IN or KSPIN_DATAFLOW_OUT?
  ULONG Index;              // Which pin to return data for?
  ULONG PinType;            // KS_PhysConn_Video_* or KS_PhysConn_Audio_*
  ULONG RelatedPinIndex;    // For video pins, this is the related audio pin
  KSPIN_MEDIUM Medium;      // Identifies the hardware connection
} KSPROPERTY_CROSSBAR_PININFO_S, *PKSPROPERTY_CROSSBAR_PININFO_S;

typedef struct {
  KSPROPERTY Property;
  ULONG IndexInputPin;  // Zero based index of the input pin
  ULONG IndexOutputPin; // Zero based index of the output pin
  ULONG CanRoute;       // returns non-zero on CAN_ROUTE if routing is possible
} KSPROPERTY_CROSSBAR_ROUTE_S, *PKSPROPERTY_CROSSBAR_ROUTE_S;

#define STATIC_EVENTSETID_CROSSBAR                                             \
  0x6a2e0641L, 0x28e4, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0xc9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("6a2e0641-28e4-11d0-a18c-00a0c9118956", EVENTSETID_CROSSBAR);
#define EVENTSETID_CROSSBAR DEFINE_GUIDNAMED(EVENTSETID_CROSSBAR)

typedef enum { KSEVENT_CROSSBAR_CHANGED } KSEVENT_CROSSBAR;

// The following IDs should match the AM equivalents
typedef enum {
  KS_PhysConn_Video_Tuner = 1,
  KS_PhysConn_Video_Composite,
  KS_PhysConn_Video_SVideo,
  KS_PhysConn_Video_RGB,
  KS_PhysConn_Video_YRYBY,
  KS_PhysConn_Video_SerialDigital,
  KS_PhysConn_Video_ParallelDigital,
  KS_PhysConn_Video_SCSI,
  KS_PhysConn_Video_AUX,
  KS_PhysConn_Video_1394,
  KS_PhysConn_Video_USB,
  KS_PhysConn_Video_VideoDecoder,
  KS_PhysConn_Video_VideoEncoder,
  KS_PhysConn_Video_SCART,

  KS_PhysConn_Audio_Tuner = 4096,
  KS_PhysConn_Audio_Line,
  KS_PhysConn_Audio_Mic,
  KS_PhysConn_Audio_AESDigital,
  KS_PhysConn_Audio_SPDIFDigital,
  KS_PhysConn_Audio_SCSI,
  KS_PhysConn_Audio_AUX,
  KS_PhysConn_Audio_1394,
  KS_PhysConn_Audio_USB,
  KS_PhysConn_Audio_AudioDecoder,
} KS_PhysicalConnectorType;

//===========================================================================

#define STATIC_PROPSETID_VIDCAP_TVAUDIO                                        \
  0x6a2e0650L, 0x28e4, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0xc9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("6a2e0650-28e4-11d0-a18c-00a0c9118956",
                  PROPSETID_VIDCAP_TVAUDIO);
#define PROPSETID_VIDCAP_TVAUDIO DEFINE_GUIDNAMED(PROPSETID_VIDCAP_TVAUDIO)

typedef enum {
  KSPROPERTY_TVAUDIO_CAPS,                     // R
  KSPROPERTY_TVAUDIO_MODE,                     // RW
  KSPROPERTY_TVAUDIO_CURRENTLY_AVAILABLE_MODES // R
} KSPROPERTY_VIDCAP_TVAUDIO;

#define KS_TVAUDIO_MODE_MONO 0x0001   // Mono
#define KS_TVAUDIO_MODE_STEREO 0x0002 // Stereo
#define KS_TVAUDIO_MODE_LANG_A 0x0010 // Primary language
#define KS_TVAUDIO_MODE_LANG_B 0x0020 // 2nd avail language
#define KS_TVAUDIO_MODE_LANG_C 0x0040 // 3rd avail language

typedef struct {
  KSPROPERTY Property;
  ULONG Capabilities; // Bitmask of KS_TVAUDIO_MODE_*
  KSPIN_MEDIUM InputMedium;
  KSPIN_MEDIUM OutputMedium;
} KSPROPERTY_TVAUDIO_CAPS_S, *PKSPROPERTY_TVAUDIO_CAPS_S;

typedef struct {
  KSPROPERTY Property;
  ULONG Mode; // KS_TVAUDIO_MODE_*
} KSPROPERTY_TVAUDIO_S, *PKSPROPERTY_TVAUDIO_S;

#define STATIC_KSEVENTSETID_VIDCAP_TVAUDIO                                     \
  0x6a2e0651L, 0x28e4, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0xc9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("6a2e0651-28e4-11d0-a18c-00a0c9118956",
                  KSEVENTSETID_VIDCAP_TVAUDIO);
#define KSEVENTSETID_VIDCAP_TVAUDIO                                            \
  DEFINE_GUIDNAMED(KSEVENTSETID_VIDCAP_TVAUDIO)

typedef enum {
  KSEVENT_TVAUDIO_CHANGED,
} KSEVENT_TVAUDIO;

//===========================================================================
#define STATIC_PROPSETID_VIDCAP_VIDEOCOMPRESSION                               \
  0xC6E13343L, 0x30AC, 0x11d0, 0xA1, 0x8C, 0x00, 0xA0, 0xC9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("C6E13343-30AC-11d0-A18C-00A0C9118956",
                  PROPSETID_VIDCAP_VIDEOCOMPRESSION);
#define PROPSETID_VIDCAP_VIDEOCOMPRESSION                                      \
  DEFINE_GUIDNAMED(PROPSETID_VIDCAP_VIDEOCOMPRESSION)

typedef enum {
  KSPROPERTY_VIDEOCOMPRESSION_GETINFO,              // R
  KSPROPERTY_VIDEOCOMPRESSION_KEYFRAME_RATE,        // RW
  KSPROPERTY_VIDEOCOMPRESSION_PFRAMES_PER_KEYFRAME, // RW
  KSPROPERTY_VIDEOCOMPRESSION_QUALITY,              // RW
  KSPROPERTY_VIDEOCOMPRESSION_OVERRIDE_KEYFRAME,    // W
  KSPROPERTY_VIDEOCOMPRESSION_OVERRIDE_FRAME_SIZE,  // W
  KSPROPERTY_VIDEOCOMPRESSION_WINDOWSIZE,           // RW
} KSPROPERTY_VIDCAP_VIDEOCOMPRESSION;

typedef enum {
  KS_CompressionCaps_CanQuality = 1,
  KS_CompressionCaps_CanCrunch = 2,
  KS_CompressionCaps_CanKeyFrame = 4,
  KS_CompressionCaps_CanBFrame = 8,
  KS_CompressionCaps_CanWindow = 0x10,
} KS_CompressionCaps;

typedef struct {
  KSPROPERTY Property;
  // Note, no VersionString!
  // Note, no DescriptionString!
  ULONG StreamIndex;            // zero based index of stream
  LONG DefaultKeyFrameRate;     // Key frame rate
  LONG DefaultPFrameRate;       // Predeicted frames per Key frame
  LONG DefaultQuality;          // 0 to 10000
  LONG NumberOfQualitySettings; // How many discreet quality settings?
  LONG Capabilities;            // KS_CompressionCaps_*
} KSPROPERTY_VIDEOCOMPRESSION_GETINFO_S,
    *PKSPROPERTY_VIDEOCOMPRESSION_GETINFO_S;

typedef struct {
  KSPROPERTY Property;
  ULONG StreamIndex; // zero based index of stream
  LONG Value;        // value to get or set
} KSPROPERTY_VIDEOCOMPRESSION_S, *PKSPROPERTY_VIDEOCOMPRESSION_S;

//===========================================================================
// MEDIASUBTYPE_Overlay
#define STATIC_KSDATAFORMAT_SUBTYPE_OVERLAY                                    \
  0xe436eb7fL, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70
DEFINE_GUIDSTRUCT("e436eb7f-524f-11ce-9f53-0020af0ba770",
                  KSDATAFORMAT_SUBTYPE_OVERLAY);
#define KSDATAFORMAT_SUBTYPE_OVERLAY                                           \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_OVERLAY)

#define STATIC_KSPROPSETID_OverlayUpdate                                       \
  0x490EA5CFL, 0x7681, 0x11D1, 0xA2, 0x1C, 0x00, 0xA0, 0xC9, 0x22, 0x31, 0x96
DEFINE_GUIDSTRUCT("490EA5CF-7681-11D1-A21C-00A0C9223196",
                  KSPROPSETID_OverlayUpdate);
#define KSPROPSETID_OverlayUpdate DEFINE_GUIDNAMED(KSPROPSETID_OverlayUpdate)

typedef enum {
  KSPROPERTY_OVERLAYUPDATE_INTERESTS,
  KSPROPERTY_OVERLAYUPDATE_CLIPLIST = 0x1,
  KSPROPERTY_OVERLAYUPDATE_PALETTE = 0x2,
  KSPROPERTY_OVERLAYUPDATE_COLORKEY = 0x4,
  KSPROPERTY_OVERLAYUPDATE_VIDEOPOSITION = 0x8,
  KSPROPERTY_OVERLAYUPDATE_DISPLAYCHANGE = 0x10,
  KSPROPERTY_OVERLAYUPDATE_COLORREF = 0x10000000
} KSPROPERTY_OVERLAYUPDATE;

typedef struct {
  ULONG PelsWidth;
  ULONG PelsHeight;
  ULONG BitsPerPel;
  WCHAR DeviceID[1];
} KSDISPLAYCHANGE, *PKSDISPLAYCHANGE;

#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_INTERESTS(Handler)                \
  DEFINE_KSPROPERTY_ITEM(KSPROPERTY_OVERLAYUPDATE_INTERESTS, (Handler),        \
                         sizeof(KSPROPERTY), sizeof(ULONG), NULL, NULL, 0,     \
                         NULL, NULL, 0)

#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_PALETTE(Handler)                  \
  DEFINE_KSPROPERTY_ITEM(KSPROPERTY_OVERLAYUPDATE_PALETTE, NULL,               \
                         sizeof(KSPROPERTY), 0, (Handler), NULL, 0, NULL,      \
                         NULL, 0)

#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_COLORKEY(Handler)                 \
  DEFINE_KSPROPERTY_ITEM(KSPROPERTY_OVERLAYUPDATE_COLORKEY, NULL,              \
                         sizeof(KSPROPERTY), sizeof(COLORKEY), (Handler),      \
                         NULL, 0, NULL, NULL, 0)

#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_CLIPLIST(Handler)                 \
  DEFINE_KSPROPERTY_ITEM(KSPROPERTY_OVERLAYUPDATE_CLIPLIST, NULL,              \
                         sizeof(KSPROPERTY),                                   \
                         2 * sizeof(RECT) + sizeof(RGNDATAHEADER), (Handler),  \
                         NULL, 0, NULL, NULL, 0)

#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_VIDEOPOSITION(Handler)            \
  DEFINE_KSPROPERTY_ITEM(KSPROPERTY_OVERLAYUPDATE_VIDEOPOSITION, NULL,         \
                         sizeof(KSPROPERTY), 2 * sizeof(RECT), (Handler),      \
                         NULL, 0, NULL, NULL, 0)

#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_DISPLAYCHANGE(Handler)            \
  DEFINE_KSPROPERTY_ITEM(KSPROPERTY_OVERLAYUPDATE_DISPLAYCHANGE, NULL,         \
                         sizeof(KSPROPERTY), sizeof(KSDISPLAYCHANGE),          \
                         (Handler), NULL, 0, NULL, NULL, 0)

#define DEFINE_KSPROPERTY_ITEM_OVERLAYUPDATE_COLORREF(Handler)                 \
  DEFINE_KSPROPERTY_ITEM(KSPROPERTY_OVERLAYUPDATE_COLORREF, (Handler),         \
                         sizeof(KSPROPERTY), sizeof(COLORREF), NULL, NULL, 0,  \
                         NULL, NULL, 0)

//===========================================================================
#define STATIC_PROPSETID_VIDCAP_VIDEOCONTROL                                   \
  0x6a2e0670L, 0x28e4, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0xc9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("6a2e0670-28e4-11d0-a18c-00a0c9118956",
                  PROPSETID_VIDCAP_VIDEOCONTROL);
#define PROPSETID_VIDCAP_VIDEOCONTROL                                          \
  DEFINE_GUIDNAMED(PROPSETID_VIDCAP_VIDEOCONTROL)

typedef enum {
  KSPROPERTY_VIDEOCONTROL_CAPS,              // R
  KSPROPERTY_VIDEOCONTROL_ACTUAL_FRAME_RATE, // R O
  KSPROPERTY_VIDEOCONTROL_FRAME_RATES,       // R O
  KSPROPERTY_VIDEOCONTROL_MODE,              // RWO
} KSPROPERTY_VIDCAP_VIDEOCONTROL;

typedef enum {
  KS_VideoControlFlag_FlipHorizontal = 0x0001,
  KS_VideoControlFlag_FlipVertical = 0x0002,
  KS_Obsolete_VideoControlFlag_ExternalTriggerEnable =
      0x0010, // ***WARNING *** Flag msimatch with DSHOW.
  KS_Obsolete_VideoControlFlag_Trigger =
      0x0020, // ***WARNING *** Flag msimatch with DSHOW.
  KS_VideoControlFlag_ExternalTriggerEnable = 0x0004,
  KS_VideoControlFlag_Trigger = 0x0008,
} KS_VideoControlFlags;

typedef struct {
  KSPROPERTY Property;
  ULONG StreamIndex;
  ULONG VideoControlCaps; // KS_VideoControlFlags_*
} KSPROPERTY_VIDEOCONTROL_CAPS_S, *PKSPROPERTY_VIDEOCONTROL_CAPS_S;

typedef struct {
  KSPROPERTY Property;
  ULONG StreamIndex;
  LONG Mode; // KS_VideoControlFlags_*
} KSPROPERTY_VIDEOCONTROL_MODE_S, *PKSPROPERTY_VIDEOCONTROL_MODE_S;

typedef struct {
  KSPROPERTY Property;
  ULONG StreamIndex;                     // Index of stream
  ULONG RangeIndex;                      // Index of range
  SIZE Dimensions;                       // Size of image
  LONGLONG CurrentActualFrameRate;       // Only correct if pin is open
  LONGLONG CurrentMaxAvailableFrameRate; // Max Rate temporarily limited on USB
                                         // or 1394?
} KSPROPERTY_VIDEOCONTROL_ACTUAL_FRAME_RATE_S,
    *PKSPROPERTY_VIDEOCONTROL_ACTUAL_FRAME_RATE_S;

// KSPROPERTY_VIDEOCONTROL_FRAME_RATES returns a list of available frame rates
// in 100 nS units
typedef struct {
  KSPROPERTY Property;
  ULONG StreamIndex; // Index of stream
  ULONG RangeIndex;  // Index of range
  SIZE Dimensions;   // Size of image
} KSPROPERTY_VIDEOCONTROL_FRAME_RATES_S,
    *PKSPROPERTY_VIDEOCONTROL_FRAME_RATES_S;

//===========================================================================
#define STATIC_PROPSETID_VIDCAP_DROPPEDFRAMES                                  \
  0xC6E13344L, 0x30AC, 0x11d0, 0xa1, 0x8c, 0x00, 0xa0, 0xc9, 0x11, 0x89, 0x56
DEFINE_GUIDSTRUCT("C6E13344-30AC-11d0-A18C-00A0C9118956",
                  PROPSETID_VIDCAP_DROPPEDFRAMES);
#define PROPSETID_VIDCAP_DROPPEDFRAMES                                         \
  DEFINE_GUIDNAMED(PROPSETID_VIDCAP_DROPPEDFRAMES)

typedef enum {
  KSPROPERTY_DROPPEDFRAMES_CURRENT // R
} KSPROPERTY_VIDCAP_DROPPEDFRAMES;

typedef struct {
  KSPROPERTY Property;
  LONGLONG PictureNumber; // Current Picture Number
  LONGLONG DropCount;     // Count of frames dropped
  ULONG AverageFrameSize; // Average size of frames captured
} KSPROPERTY_DROPPEDFRAMES_CURRENT_S, *PKSPROPERTY_DROPPEDFRAMES_CURRENT_S;

//===========================================================================
// VPE

#define STATIC_KSPROPSETID_VPConfig                                            \
  0xbc29a660L, 0x30e3, 0x11d0, 0x9e, 0x69, 0x00, 0xc0, 0x4f, 0xd7, 0xc1, 0x5b
DEFINE_GUIDSTRUCT("bc29a660-30e3-11d0-9e69-00c04fd7c15b", KSPROPSETID_VPConfig);
#define KSPROPSETID_VPConfig DEFINE_GUIDNAMED(KSPROPSETID_VPConfig)

#define STATIC_KSPROPSETID_VPVBIConfig                                         \
  0xec529b00L, 0x1a1f, 0x11d1, 0xba, 0xd9, 0x0, 0x60, 0x97, 0x44, 0x11, 0x1a
DEFINE_GUIDSTRUCT("ec529b00-1a1f-11d1-bad9-00609744111a",
                  KSPROPSETID_VPVBIConfig);
#define KSPROPSETID_VPVBIConfig DEFINE_GUIDNAMED(KSPROPSETID_VPVBIConfig)

// Both of the above property sets use the same list of properties below

typedef enum {
  KSPROPERTY_VPCONFIG_NUMCONNECTINFO,
  KSPROPERTY_VPCONFIG_GETCONNECTINFO,
  KSPROPERTY_VPCONFIG_SETCONNECTINFO,
  KSPROPERTY_VPCONFIG_VPDATAINFO,
  KSPROPERTY_VPCONFIG_MAXPIXELRATE,
  KSPROPERTY_VPCONFIG_INFORMVPINPUT,
  KSPROPERTY_VPCONFIG_NUMVIDEOFORMAT,
  KSPROPERTY_VPCONFIG_GETVIDEOFORMAT,
  KSPROPERTY_VPCONFIG_SETVIDEOFORMAT,
  KSPROPERTY_VPCONFIG_INVERTPOLARITY,
  KSPROPERTY_VPCONFIG_DECIMATIONCAPABILITY, // E_NOTIMPL for VBI
  KSPROPERTY_VPCONFIG_SCALEFACTOR,          // E_NOTIMPL for VBI
  KSPROPERTY_VPCONFIG_DDRAWHANDLE,
  KSPROPERTY_VPCONFIG_VIDEOPORTID,
  KSPROPERTY_VPCONFIG_DDRAWSURFACEHANDLE,
  KSPROPERTY_VPCONFIG_SURFACEPARAMS
} KSPROPERTY_VPCONFIG;

//=========================
// IBasicAudio
//
#define STATIC_CLSID_KsIBasicAudioInterfaceHandler                             \
  0xb9f8ac3e, 0x0f71, 0x11d2, 0xb7, 0x2c, 0x00, 0xc0, 0x4f, 0xb6, 0xbd, 0x3d
DEFINE_GUIDSTRUCT("b9f8ac3e-0f71-11d2-b72c-00c04fb6bd3d",
                  CLSID_KsIBasicAudioInterfaceHandler);
#define CLSID_KsIBasicAudioInterfaceHandler                                    \
  DEFINE_GUIDNAMED(CLSID_KsIBasicAudioInterfaceHandler)

#if defined(__IVPType__)

typedef struct {
  AMVPSIZE Size;
  DWORD MaxPixelsPerSecond;
  DWORD Reserved;
} KSVPMAXPIXELRATE, *PKSVPMAXPIXELRATE;

typedef struct {
  KSPROPERTY Property;
  AMVPSIZE Size;
} KSVPSIZE_PROP, *PKSVPSIZE_PROP;

typedef struct {
  DWORD dwPitch;
  DWORD dwXOrigin;
  DWORD dwYOrigin;
} KSVPSURFACEPARAMS, *PKSVPSURFACEPARAMS;

#else // !defined(__IVPType__)

#if !defined(__DDRAW_INCLUDED__)

//==========================================================================
// The following definitions must be in sync with DDraw.h in DirectX SDK
//==========================================================================

/*
 * The FourCC code is valid.
 */
#define DDPF_FOURCC 0x00000004l

typedef struct _DDPIXELFORMAT {
  DWORD dwSize;   // size of structure
  DWORD dwFlags;  // pixel format flags
  DWORD dwFourCC; // (FOURCC code)
  union {
    DWORD dwRGBBitCount;     // how many bits per pixel (BD_1,2,4,8,16,24,32)
    DWORD dwYUVBitCount;     // how many bits per pixel (BD_4,8,16,24,32)
    DWORD dwZBufferBitDepth; // how many bits for z buffers (BD_8,16,24,32)
    DWORD dwAlphaBitDepth;   // how many bits for alpha channels (BD_1,2,4,8)
  };
  union {
    DWORD dwRBitMask; // mask for red bit
    DWORD dwYBitMask; // mask for Y bits
  };
  union {
    DWORD dwGBitMask; // mask for green bits
    DWORD dwUBitMask; // mask for U bits
  };
  union {
    DWORD dwBBitMask; // mask for blue bits
    DWORD dwVBitMask; // mask for V bits
  };
  union {
    DWORD dwRGBAlphaBitMask; // mask for alpha channel
    DWORD dwYUVAlphaBitMask; // mask for alpha channel
    DWORD dwRGBZBitMask;     // mask for Z channel
    DWORD dwYUVZBitMask;     // mask for Z channel
  };
} DDPIXELFORMAT, *LPDDPIXELFORMAT;

#endif // !defined(__DDRAW_INCLUDED__)

//==========================================================================
// End of DDraw.h header info
//==========================================================================

//==========================================================================
// The following definitions must be in sync with DVP.h in DirectX SDK
//==========================================================================

#if !defined(__DVP_INCLUDED__)

typedef struct _DDVIDEOPORTCONNECT {
  DWORD dwSize;      // size of the DDVIDEOPORTCONNECT structure
  DWORD dwPortWidth; // Width of the video port
  GUID guidTypeID;   // Description of video port connection
  DWORD dwFlags;     // Connection flags
  DWORD dwReserved1; // Reserved, set to zero.
} DDVIDEOPORTCONNECT, *LPDDVIDEOPORTCONNECT;

#define DDVPTYPE_E_HREFH_VREFH                                                 \
  0x54F39980L, 0xDA60, 0x11CF, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8

#define DDVPTYPE_E_HREFL_VREFL                                                 \
  0xE09C77E0L, 0xDA60, 0x11CF, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8

#endif // !defined(__DVP_INCLUDED__)

//==========================================================================
// End of DVP.h header info
//==========================================================================

//==========================================================================
// The following definitions must be in sync with VPType.h in AM 2.0 SDK
//==========================================================================

// pixel aspect ratios corresponding to a 720x480 NTSC image or a 720x576 image
typedef enum // AMPixAspectRatio
{ KS_PixAspectRatio_NTSC4x3,
  KS_PixAspectRatio_NTSC16x9,
  KS_PixAspectRatio_PAL4x3,
  KS_PixAspectRatio_PAL16x9,
} KS_AMPixAspectRatio;

typedef enum // AMVP_SELECTFORMATBY
{ KS_AMVP_DO_NOT_CARE,
  KS_AMVP_BEST_BANDWIDTH,
  KS_AMVP_INPUT_SAME_AS_OUTPUT } KS_AMVP_SELECTFORMATBY;

typedef enum // AMVP_MODE
{ KS_AMVP_MODE_WEAVE,
  KS_AMVP_MODE_BOBINTERLEAVED,
  KS_AMVP_MODE_BOBNONINTERLEAVED,
  KS_AMVP_MODE_SKIPEVEN,
  KS_AMVP_MODE_SKIPODD } KS_AMVP_MODE;

typedef struct tagKS_AMVPDIMINFO // AMVPDIMINFO
{
  DWORD dwFieldWidth;  // [out] field width
  DWORD dwFieldHeight; // [out] field height
  DWORD dwVBIWidth;    // [out] VBI data width
  DWORD dwVBIHeight;   // [out] VBI data height
  RECT rcValidRegion;  // [out] valid rect for data cropping
} KS_AMVPDIMINFO, *PKS_AMVPDIMINFO;

typedef struct tagKS_AMVPDATAINFO // AMVPDATAINFO
{
  DWORD dwSize;                 // Size of the struct
  DWORD dwMicrosecondsPerField; // Time taken by each field
  KS_AMVPDIMINFO amvpDimInfo;   // Dimensional Information
  DWORD dwPictAspectRatioX;     // Pict aspect ratio in X dimn
  DWORD dwPictAspectRatioY;     // Pict aspect ratio in Y dimn
  BOOL bEnableDoubleClock;      // Videoport should enable double clocking
  BOOL bEnableVACT;             // Videoport should use an external VACT signal
  BOOL bDataIsInterlaced;       // Indicates that the signal is interlaced
  LONG lHalfLinesOdd;           // number of halflines in the odd field
  BOOL bFieldPolarityInverted;  // Device inverts the polarity by default
  DWORD dwNumLinesInVREF;       // Number of lines of data in VREF
  LONG lHalfLinesEven;          // number of halflines in the even field
  DWORD dwReserved1;            // Reserved for future use
} KS_AMVPDATAINFO, *PKS_AMVPDATAINFO;

typedef struct tagKS_AMVPSIZE // AMVPSIZE
{
  DWORD dwWidth;  // [in] width in pixels
  DWORD dwHeight; // [in] height in pixels
} KS_AMVPSIZE, *PKS_AMVPSIZE;

//==========================================================================
// End of VPType.h header info
//==========================================================================

typedef struct {
  KS_AMVPSIZE Size;
  DWORD MaxPixelsPerSecond;
  DWORD Reserved;
} KSVPMAXPIXELRATE, *PKSVPMAXPIXELRATE;

typedef struct {
  KSPROPERTY Property;
  KS_AMVPSIZE Size;
} KSVPSIZE_PROP, *PKSVPSIZE_PROP;

typedef struct {
  DWORD dwPitch;
  DWORD dwXOrigin;
  DWORD dwYOrigin;
} KSVPSURFACEPARAMS, *PKSVPSURFACEPARAMS;

#endif // !defined(__IVPType__)

//
//  IVPNotify event notification
//
#define STATIC_KSEVENTSETID_VPNotify                                           \
  0x20c5598eL, 0xd3c8, 0x11d0, 0x8d, 0xfc, 0x00, 0xc0, 0x4f, 0xd7, 0xc0, 0x8b
DEFINE_GUIDSTRUCT("20c5598e-d3c8-11d0-8dfc-00c04fd7c08b",
                  KSEVENTSETID_VPNotify);
#define KSEVENTSETID_VPNotify DEFINE_GUIDNAMED(KSEVENTSETID_VPNotify)

typedef enum {
  KSEVENT_VPNOTIFY_FORMATCHANGE,
} KSEVENT_VPNOTIFY;

//
//  VIDCAPTOSTI event notification
//
#define STATIC_KSEVENTSETID_VIDCAPTOSTI                                        \
  0xdb47de20, 0xf628, 0x11d1, 0xba, 0x41, 0x0, 0xa0, 0xc9, 0xd, 0x2b, 0x5
DEFINE_GUIDSTRUCT("DB47DE20-F628-11d1-BA41-00A0C90D2B05",
                  KSEVENTSETID_VIDCAPTOSTI);
#define KSEVENTSETID_VIDCAPNotify DEFINE_GUIDNAMED(KSEVENTSETID_VIDCAPTOSTI)

typedef enum {
  KSEVENT_VIDCAPTOSTI_EXT_TRIGGER,
  KSEVENT_VIDCAP_AUTO_UPDATE,
  KSEVENT_VIDCAP_SEARCH
} KSEVENT_VIDCAPTOSTI;

//
// Extension Unit Properties
//
typedef enum {
  KSPROPERTY_EXTENSION_UNIT_INFO,                  // (R)
  KSPROPERTY_EXTENSION_UNIT_CONTROL,               // (RW)
  KSPROPERTY_EXTENSION_UNIT_PASS_THROUGH = 0xffff, // (RW)
} KSPROPERTY_EXTENSION_UNIT,
    *PKSPROPERTY_EXTENSION_UNIT;

//
//  IVPVBINotify event notification
//
#define STATIC_KSEVENTSETID_VPVBINotify                                        \
  0xec529b01L, 0x1a1f, 0x11d1, 0xba, 0xd9, 0x0, 0x60, 0x97, 0x44, 0x11, 0x1a
DEFINE_GUIDSTRUCT("ec529b01-1a1f-11d1-bad9-00609744111a",
                  KSEVENTSETID_VPVBINotify);
#define KSEVENTSETID_VPVBINotify DEFINE_GUIDNAMED(KSEVENTSETID_VPVBINotify)

typedef enum {
  KSEVENT_VPVBINOTIFY_FORMATCHANGE,
} KSEVENT_VPVBINOTIFY;

//
// closed caption information
//

#define STATIC_KSDATAFORMAT_TYPE_AUXLine21Data                                 \
  0x670aea80L, 0x3a82, 0x11d0, 0xb7, 0x9b, 0x00, 0xaa, 0x00, 0x37, 0x67, 0xa7
DEFINE_GUIDSTRUCT("670aea80-3a82-11d0-b79b-00aa003767a7",
                  KSDATAFORMAT_TYPE_AUXLine21Data);
#define KSDATAFORMAT_TYPE_AUXLine21Data                                        \
  DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_AUXLine21Data)

#define STATIC_KSDATAFORMAT_SUBTYPE_Line21_BytePair                            \
  0x6e8d4a22L, 0x310c, 0x11d0, 0xb7, 0x9a, 0x00, 0xaa, 0x00, 0x37, 0x67, 0xa7
DEFINE_GUIDSTRUCT("6e8d4a22-310c-11d0-b79a-00aa003767a7",
                  KSDATAFORMAT_SUBTYPE_Line21_BytePair);
#define KSDATAFORMAT_SUBTYPE_Line21_BytePair                                   \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_Line21_BytePair)

#define STATIC_KSDATAFORMAT_SUBTYPE_Line21_GOPPacket                           \
  0x6e8d4a23L, 0x310c, 0x11d0, 0xb7, 0x9a, 0x00, 0xaa, 0x00, 0x37, 0x67, 0xa7
DEFINE_GUIDSTRUCT("6e8d4a23-310c-11d0-b79a-00aa003767a7",
                  KSDATAFORMAT_SUBTYPE_Line21_GOPPacket);
#define KSDATAFORMAT_SUBTYPE_Line21_GOPPacket                                  \
  DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_Line21_GOPPacket)

typedef struct _KSGOP_USERDATA {
  ULONG sc;
  ULONG reserved1;
  BYTE cFields;
  CHAR l21Data[3];
} KSGOP_USERDATA, *PKSGOP_USERDATA;

//
// DVD encrypted PACK format type definition
//

#define STATIC_KSDATAFORMAT_TYPE_DVD_ENCRYPTED_PACK                            \
  0xed0b916a, 0x044d, 0x11d1, 0xaa, 0x78, 0x00, 0xc0, 0x4f, 0xc3, 0x1d, 0x60
DEFINE_GUIDSTRUCT("ed0b916a-044d-11d1-aa78-00c04fc31d60",
                  KSDATAFORMAT_TYPE_DVD_ENCRYPTED_PACK);
#define KSDATAFORMAT_TYPE_DVD_ENCRYPTED_PACK                                   \
  DEFINE_GUIDNAMED(KSDATAFORMAT_TYPE_DVD_ENCRYPTED_PACK)

#define KS_AM_UseNewCSSKey 0x1

// -----------------------------------------------------------------------
// KS_AM_KSPROPSETID_TSRateChange property set definitions for time stamp
// rate changes.
// -----------------------------------------------------------------------

#define STATIC_KSPROPSETID_TSRateChange                                        \
  0xa503c5c0, 0x1d1d, 0x11d1, 0xad, 0x80, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0

DEFINE_GUIDSTRUCT("A503C5C0-1D1D-11D1-AD80-444553540000",
                  KSPROPSETID_TSRateChange);
#define KSPROPSETID_TSRateChange DEFINE_GUIDNAMED(KSPROPSETID_TSRateChange)
typedef enum {
  KS_AM_RATE_SimpleRateChange = 1, // rw, use KS_AM_SimpleRateChange
  KS_AM_RATE_ExactRateChange = 2,  // rw, use KS_AM_ExactRateChange
  KS_AM_RATE_MaxFullDataRate = 3,  // r, use KS_AM_MaxFullDataRate
  KS_AM_RATE_Step = 4              // w, use KS_AM_Step
} KS_AM_PROPERTY_TS_RATE_CHANGE;

typedef struct {
  // this is the simplest mechanism to set a time stamp rate change on
  // a filter (simplest for the person setting the rate change, harder
  // for the filter doing the rate change).
  REFERENCE_TIME StartTime; // stream time at which to start this rate
  LONG Rate;                // new rate * 10000 (decimal)
} KS_AM_SimpleRateChange, *PKS_AM_SimpleRateChange;

typedef struct {
  REFERENCE_TIME OutputZeroTime; // input TS that maps to zero output TS
  LONG Rate;                     // new rate * 10000 (decimal)
} KS_AM_ExactRateChange, *PKS_AM_ExactRateChange;

typedef LONG KS_AM_MaxFullDataRate; // rate * 10000 (decimal)

typedef DWORD KS_AM_Step; // number of frame to step

//===========================================================================
// ENCODER API DEFINITIONS
//===========================================================================

#define STATIC_KSCATEGORY_ENCODER                                              \
  0x19689bf6, 0xc384, 0x48fd, 0xad, 0x51, 0x90, 0xe5, 0x8c, 0x79, 0xf7, 0xb
DEFINE_GUIDSTRUCT("19689BF6-C384-48fd-AD51-90E58C79F70B", KSCATEGORY_ENCODER);
#define KSCATEGORY_ENCODER DEFINE_GUIDNAMED(KSCATEGORY_ENCODER)

#define STATIC_KSCATEGORY_MULTIPLEXER                                          \
  0x7a5de1d3, 0x1a1, 0x452c, 0xb4, 0x81, 0x4f, 0xa2, 0xb9, 0x62, 0x71, 0xe8
DEFINE_GUIDSTRUCT("7A5DE1D3-01A1-452c-B481-4FA2B96271E8",
                  KSCATEGORY_MULTIPLEXER);
#define KSCATEGORY_MULTIPLEXER DEFINE_GUIDNAMED(KSCATEGORY_MULTIPLEXER)

#ifndef __ENCODER_API_GUIDS__
#define __ENCODER_API_GUIDS__

#define STATIC_ENCAPIPARAM_BITRATE                                             \
  0x49cc4c43, 0xca83, 0x4ad4, 0xa9, 0xaf, 0xf3, 0x69, 0x6a, 0xf6, 0x66, 0xdf
DEFINE_GUIDSTRUCT("49CC4C43-CA83-4ad4-A9AF-F3696AF666DF", ENCAPIPARAM_BITRATE);
#define ENCAPIPARAM_BITRATE DEFINE_GUIDNAMED(ENCAPIPARAM_BITRATE)

#define STATIC_ENCAPIPARAM_PEAK_BITRATE                                        \
  0x703f16a9, 0x3d48, 0x44a1, 0xb0, 0x77, 0x1, 0x8d, 0xff, 0x91, 0x5d, 0x19
DEFINE_GUIDSTRUCT("703F16A9-3D48-44a1-B077-018DFF915D19",
                  ENCAPIPARAM_PEAK_BITRATE);
#define ENCAPIPARAM_PEAK_BITRATE DEFINE_GUIDNAMED(ENCAPIPARAM_PEAK_BITRATE)

#define STATIC_ENCAPIPARAM_BITRATE_MODE                                        \
  0xee5fb25c, 0xc713, 0x40d1, 0x9d, 0x58, 0xc0, 0xd7, 0x24, 0x1e, 0x25, 0xf
DEFINE_GUIDSTRUCT("EE5FB25C-C713-40d1-9D58-C0D7241E250F",
                  ENCAPIPARAM_BITRATE_MODE);
#define ENCAPIPARAM_BITRATE_MODE DEFINE_GUIDNAMED(ENCAPIPARAM_BITRATE_MODE)

#define STATIC_CODECAPI_CHANGELISTS                                            \
  0x62b12acf, 0xf6b0, 0x47d9, 0x94, 0x56, 0x96, 0xf2, 0x2c, 0x4e, 0x0b, 0x9d
DEFINE_GUIDSTRUCT("62B12ACF-F6B0-47D9-9456-96F22C4E0B9D", CODECAPI_CHANGELISTS);
#define CODECAPI_CHANGELISTS DEFINE_GUIDNAMED(CODECAPI_CHANGELISTS)

#define STATIC_CODECAPI_VIDEO_ENCODER                                          \
  0x7112e8e1, 0x3d03, 0x47ef, 0x8e, 0x60, 0x03, 0xf1, 0xcf, 0x53, 0x73, 0x01
DEFINE_GUIDSTRUCT("7112E8E1-3D03-47EF-8E60-03F1CF537301",
                  CODECAPI_VIDEO_ENCODER);
#define CODECAPI_VIDEO_ENCODER DEFINE_GUIDNAMED(CODECAPI_VIDEO_ENCODER)

#define STATIC_CODECAPI_AUDIO_ENCODER                                          \
  0xb9d19a3e, 0xf897, 0x429c, 0xbc, 0x46, 0x81, 0x38, 0xb7, 0x27, 0x2b, 0x2d
DEFINE_GUIDSTRUCT("B9D19A3E-F897-429C-BC46-8138B7272B2D",
                  CODECAPI_AUDIO_ENCODER);
#define CODECAPI_AUDIO_ENCODER DEFINE_GUIDNAMED(CODECAPI_AUDIO_ENCODER)

#define STATIC_CODECAPI_SETALLDEFAULTS                                         \
  0x6c5e6a7c, 0xacf8, 0x4f55, 0xa9, 0x99, 0x1a, 0x62, 0x81, 0x09, 0x05, 0x1b
DEFINE_GUIDSTRUCT("6C5E6A7C-ACF8-4F55-A999-1A628109051B",
                  CODECAPI_SETALLDEFAULTS);
#define CODECAPI_SETALLDEFAULTS DEFINE_GUIDNAMED(CODECAPI_SETALLDEFAULTS)

#define STATIC_CODECAPI_ALLSETTINGS                                            \
  0x6a577e92, 0x83e1, 0x4113, 0xad, 0xc2, 0x4f, 0xce, 0xc3, 0x2f, 0x83, 0xa1
DEFINE_GUIDSTRUCT("6A577E92-83E1-4113-ADC2-4FCEC32F83A1", CODECAPI_ALLSETTINGS);
#define CODECAPI_ALLSETTINGS DEFINE_GUIDNAMED(CODECAPI_ALLSETTINGS)

#define STATIC_CODECAPI_SUPPORTSEVENTS                                         \
  0x0581af97, 0x7693, 0x4dbd, 0x9d, 0xca, 0x3f, 0x9e, 0xbd, 0x65, 0x85, 0xa1
DEFINE_GUIDSTRUCT("0581AF97-7693-4DBD-9DCA-3F9EBD6585A1",
                  CODECAPI_SUPPORTSEVENTS);
#define CODECAPI_SUPPORTSEVENTS DEFINE_GUIDNAMED(CODECAPI_SUPPORTSEVENTS)

#define STATIC_CODECAPI_CURRENTCHANGELIST                                      \
  0x1cb14e83, 0x7d72, 0x4657, 0x83, 0xfd, 0x47, 0xa2, 0xc5, 0xb9, 0xd1, 0x3d
DEFINE_GUIDSTRUCT("1CB14E83-7D72-4657-83FD-47A2C5B9D13D",
                  CODECAPI_CURRENTCHANGELIST);
#define CODECAPI_CURRENTCHANGELIST DEFINE_GUIDNAMED(CODECAPI_CURRENTCHANGELIST)

#endif // __ENCODER_API_GUIDS__

#ifndef __ENCODER_API_DEFINES__
#define __ENCODER_API_DEFINES__

typedef enum {

  //
  // Bit rate used for encoding is constant
  //
  ConstantBitRate = 0,

  //
  // Bit rate used for encoding is variable with the specified bitrate used
  // as a guaranteed average over a specified window.  The default window
  // size is considered to be 5 minutes.
  //
  VariableBitRateAverage,

  //
  // Bit rate used for encoding is variable with the specified bitrate used
  // as an average with a peak not to exceed the specified peak bitrate over
  // a specified window.  The default window size is considered to be 500ms
  // (classically one GOP).
  //
  VariableBitRatePeak

} VIDEOENCODER_BITRATE_MODE;

#endif // __ENCODER_API_DEFINES__

#endif // !defined(_KSMEDIA_)
