LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPP_EXTENSION := .cpp .cc
LOCAL_MODULE    := icpeapi
LOCAL_SRC_FILES := icpeapi.cpp

ifeq ($(TARGET_ARCH_ABI),x86)
    LOCAL_CFLAGS += -ffast-math -mtune=atom -mssse3 -mfpmath=sse
endif

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := ICPEMAIN
LOCAL_SRC_FILES_RAW := $(shell find icpe/ -name '*.cpp') $(shell find icpe/ -name '*.c')
LOCAL_SRC_FILES := $(LOCAL_SRC_FILES_RAW:icpe/%=%)
TARGET_NO_UNDEFINED_LDFLAGS :=

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := tinysubstrate
LOCAL_SRC_FILES := lib/libtinysubstrate.so
include $(PREBUILT_SHARED_LIBRARY)

#include $(CLEAR_VARS)
#LOCAL_MODULE := minecraftpe
#LOCAL_SRC_FILES := lib/libminecraftpe.so
#include $(PREBUILT_SHARED_LIBRARY)
