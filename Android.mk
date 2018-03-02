LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    audioTools.cpp
LOCAL_SHARED_LIBRARIES := \
    liblog \
    libutils \
    libmedia \
    libaudioclient

LOCAL_CFLAGS += -Wno-multichar -Werror -Wall
LOCAL_CLANG := true
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= audioTools

include $(BUILD_EXECUTABLE)

include $(call all-makefiles-under,$(LOCAL_PATH))