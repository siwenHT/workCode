LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
$(warning young path is: $(LOCAL_PATH))
LOCAL_MODULE := young_static
LOCAL_MODULE_FILENAME := libyoung
LOCAL_SRC_FILES := tolua++/Young_binding.cpp	\
                   GUI/ScrollView/YGirdView.cpp	\
				   GUI/ScrollView/YGirdView_binding.cpp	\
				   GUI/ScrollView/YGirdViewCell.cpp	\
				   GUI/ScrollView/YGirdViewCell_binding.cpp	\
				   GUI/ScrollView/YScrollView.cpp	\
				   GUI/ScrollView/YScrollView_binding.cpp		   
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/
LOCAL_C_INCLUDES := $(LOCAL_PATH)/
LOCAL_WHOLE_STATIC_LIBRARIES := cocos2d_lua_static
include $(BUILD_STATIC_LIBRARY)
