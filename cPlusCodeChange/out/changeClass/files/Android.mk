LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
$(warning young path is: $(LOCAL_PATH))
LOCAL_MODULE := young_static
LOCAL_MODULE_FILENAME := libyoung
LOCAL_SRC_FILES := tolua++/Young_binding.cpp	\
                   GUI/ScrollView/inspiredPass.cpp	\
				   GUI/ScrollView/inspiredPass_binding.cpp	\
				   GUI/ScrollView/sensibleApplication.cpp	\
				   GUI/ScrollView/sensibleApplication_binding.cpp	\
				   GUI/ScrollView/increasedTable.cpp	\
				   GUI/ScrollView/increasedTable_binding.cpp		   
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/
LOCAL_C_INCLUDES := $(LOCAL_PATH)/
LOCAL_WHOLE_STATIC_LIBRARIES := cocos2d_lua_static
include $(BUILD_STATIC_LIBRARY)
