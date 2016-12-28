LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := tinysubstrate
LOCAL_SRC_FILES := libtinysubstrate.so
include $(PREBUILT_SHARED_LIBRARY)
