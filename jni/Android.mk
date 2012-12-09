LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := reversi
LOCAL_SRC_FILES := main.cpp
LOCAL_SRC_FILES := isValid.cpp
LOCAL_SRC_FILES := canConquer.cpp
LOCAL_SRC_FILES := ConquerDirection.cpp
LOCAL_SRC_FILES := checkLine.cpp 
LOCAL_SRC_FILES := op.cpp
LOCAL_SRC_FILES := isEmpty.cpp

include $(BUILD_SHARED_LIBRARY)