LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := reversi
LOCAL_SRC_FILES := main.cpp
LOCAL_SRC_FILES += isValid.cpp
LOCAL_SRC_FILES += ConquerDirection.cpp
LOCAL_SRC_FILES += checkLine.cpp 
LOCAL_SRC_FILES += op.cpp
LOCAL_SRC_FILES += isEmpty.cpp
LOCAL_SRC_FILES += Conquer.cpp
LOCAL_SRC_FILES += canConquerUp.cpp
LOCAL_SRC_FILES += canConquerDown.cpp
LOCAL_SRC_FILES += canConquerLeft.cpp
LOCAL_SRC_FILES += canConquerRight.cpp
LOCAL_SRC_FILES += canConquerDL.cpp
LOCAL_SRC_FILES += canConquerDR.cpp
LOCAL_SRC_FILES += canConquerUL.cpp
LOCAL_SRC_FILES += canConquerUR.cpp

include $(BUILD_SHARED_LIBRARY)