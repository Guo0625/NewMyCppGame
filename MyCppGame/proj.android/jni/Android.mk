LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos/audio/include)


LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp
LOCAL_ARM_MODE := arm

LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog

LOCAL_CFLAGS += -D__STDC_CONSTANT_MACROS -Wl,-Map=test.map -g

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_SRC_FILES := MyCppGame/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../libs
LOCAL_SRC_FILES +=\
                   ../../libs/GeometricRecognizer.cpp
                   
                  
# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
