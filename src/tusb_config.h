#ifndef TUSB_CONFIG_H
#define TUSB_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

// Board specific
#define CFG_TUSB_RHPORT0_MODE   OPT_MODE_DEVICE
#define CFG_TUSB_OS             OPT_OS_NONE

// CFG_TUSB_DEBUG for debug logging (0=off, 1=errors, 2=warnings, 3=info)
#define CFG_TUSB_DEBUG          0

// USB DMA on RP2040
#define CFG_TUSB_MEM_SECTION
#define CFG_TUSB_MEM_ALIGN      __attribute__ ((aligned(4)))

// Device Configuration
#define CFG_TUD_ENDPOINT0_SIZE  64

// Enabled device classes
#define CFG_TUD_HID             1
#define CFG_TUD_CDC             0
#define CFG_TUD_MSC             0
#define CFG_TUD_MIDI            0
#define CFG_TUD_VENDOR          0

// HID buffer size
#define CFG_TUD_HID_EP_BUFSIZE  16

#ifdef __cplusplus
}
#endif

#endif 
