# top level project rules for the msm8610 project
#
LOCAL_DIR := $(GET_LOCAL_DIR)

TARGET := msm8610

MODULES += app/aboot

ifeq ($(TARGET_BUILD_VARIANT),user)
DEBUG := 0
else
DEBUG := 1
endif

EMMC_BOOT := 1
ENABLE_SDHCI_SUPPORT := 1

#DEFINES += WITH_DEBUG_DCC=1
DEFINES += WITH_DEBUG_UART=1
DEFINES += WITH_DEBUG_LOG_BUF=1
#DEFINES += WITH_DEBUG_FBCON=1
DEFINES += DEVICE_TREE=1
#DEFINES += MMC_BOOT_BAM=1
#DEFINES += CRYPTO_BAM=1
DEFINES += ABOOT_IGNORE_BOOT_HEADER_ADDRS=1

DEFINES += ABOOT_FORCE_KERNEL_ADDR=0x00008000
DEFINES += ABOOT_FORCE_RAMDISK_ADDR=0x02000000
DEFINES += ABOOT_FORCE_TAGS_ADDR=0x01e00000

#Disable thumb mode
#TODO: The gold linker has issues generating correct
#thumb interworking code for LK. Confirm that the issue
#is with the linker and file a bug report.
ENABLE_THUMB := false

ifeq ($(ENABLE_SDHCI_SUPPORT),1)
DEFINES += MMC_SDHCI_SUPPORT=1
endif
