LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)	
LOCAL_MODULE := libRenderSystem_OGL
LOCAL_SRC_FILES := $(ENGINE_ROOT_LOCAL)/sdk/RenderSystem_OGL/android/$(TARGET_ARCH_ABI)/libRenderSystem_OGL.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libAppPlayJNI

$(info Android_.mk LOCAL_PATH : $(LOCAL_PATH))

$(info Android_.mk FILE_LIST before : $(FILE_LIST))
FILE_LIST := $(wildcard $(LOCAL_PATH)/*cpp)
$(info Android_.mk FILE_LIST after : $(FILE_LIST))

$(info Android_.mk LOCAL_SRC_FILES before : $(LOCAL_SRC_FILES))
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(ENGINE_ROOT_LOCAL)/AppPlay/Common/jni/Common.cpp
# LOCAL_SRC_FILES += $(ENGINE_ROOT_LOCAL)/AppPlay/Common/jni/org_appplay_lua_LuaInterface.cpp
$(info Android_.mk LOCAL_SRC_FILES after : $(LOCAL_SRC_FILES))

$(info Android_.mk LOCAL_WHOLE_STATIC_LIBRARIES before : $(LOCAL_WHOLE_STATIC_LIBRARIES))
#LOCAL_WHOLE_STATIC_LIBRARIES += ScriptSupport
LOCAL_WHOLE_STATIC_LIBRARIES := iworld
LOCAL_WHOLE_STATIC_LIBRARIES += libOgreMain
LOCAL_WHOLE_STATIC_LIBRARIES += OgreMainExt
LOCAL_WHOLE_STATIC_LIBRARIES += libRenderSystem_OGL
$(info Android_.mk LOCAL_WHOLE_STATIC_LIBRARIES after : $(LOCAL_WHOLE_STATIC_LIBRARIES))

$(info Android_.mk LOCAL_STATIC_LIBRARIES before : $(LOCAL_STATIC_LIBRARIES))
LOCAL_STATIC_LIBRARIES := raknet
# LOCAL_STATIC_LIBRARIES += websockets
# LOCAL_STATIC_LIBRARIES += OgreMain
# LOCAL_STATIC_LIBRARIES += libOgreMain
LOCAL_STATIC_LIBRARIES += libMiniwAr
# LOCAL_STATIC_LIBRARIES += libopencv_imgproc
# LOCAL_STATIC_LIBRARIES += libopencv_core
# LOCAL_STATIC_LIBRARIES += libtbb
$(info Android_.mk LOCAL_STATIC_LIBRARIES after : $(LOCAL_STATIC_LIBRARIES))

$(info Android_.mk TARGET_ARCH_ABI : $(TARGET_ARCH_ABI))

$(info Android_.mk LOCAL_SHARED_LIBRARIES before : $(LOCAL_SHARED_LIBRARIES))
LOCAL_SHARED_LIBRARIES += fmod
#LOCAL_SHARED_LIBRARIES += libGCloudVoice
LOCAL_SHARED_LIBRARIES += youme_voice_engine


$(info Android_.mk LOCAL_SHARED_LIBRARIES after : $(LOCAL_SHARED_LIBRARIES))


$(info Android_.mk LOCAL_C_INCLUDES before : $(LOCAL_C_INCLUDES))
LOCAL_C_INCLUDES := $(ENGINE_ROOT_LOCAL)/AppPlay/Common/jni/ \
		$(ENGINE_ROOT_LOCAL)/OgreMainExt/ \
		$(ENGINE_ROOT_LOCAL)/OgreMainExt/Android/ \
		$(ENGINE_ROOT_LOCAL)/OgreMain/ \
		$(ENGINE_ROOT_LOCAL)/ScriptSupport/ \
		$(ENGINE_ROOT_LOCAL)/iworld/ \
        $(ENGINE_ROOT_LOCAL)/sdk/smartar/libminiwar/jni/opencv/include/
$(info Android_.mk LOCAL_C_INCLUDES after : $(LOCAL_C_INCLUDES))

LOCAL_LDLIBS := -llog -lGLESv2  -ljnigraphics -lz

LOCAL_LDFLAGS := -Wl,--allow-multiple-definition

LOCAL_CFLAGS := -std=c++11

LOCAL_CPPFLAGS := -fexceptions

ifeq "$(NDK_DEBUG)" "0"
# ================ release ================
# LOCAL_CFLAGS := -O3  -Os
LOCAL_CFLAGS += -O3  -Os

LOCAL_CPPFLAGS +=  -O3  -Os
# ================ release ================
else
# ================ debug ================
# LOCAL_CFLAGS := -O0
# LOCAL_CFLAGS += -O0
LOCAL_CFLAGS += -O3
# LOCAL_CFLAGS += -Os
# ------------------------- 定义 -------------------------
# LOCAL_CFLAGS +=  -Wundef
LOCAL_CFLAGS += -Wunknown-pragmas 
LOCAL_CFLAGS += -Wunused
LOCAL_CFLAGS += -Wunused-function
LOCAL_CFLAGS += -Wunused-label
# LOCAL_CFLAGS += -Wunused-parameter
LOCAL_CFLAGS += -Wunused-variable
LOCAL_CFLAGS += -Wunused-value
LOCAL_CFLAGS += -Wunused-but-set-parameter
LOCAL_CFLAGS += -Wunused-but-set-variable
# LOCAL_CFLAGS += -Wunused-local-typedefs
LOCAL_CFLAGS += -Wunused-result
LOCAL_CFLAGS += -Wunused-macros
# LOCAL_CFLAGS += -Wunused-const-variable=2
# LOCAL_CFLAGS += -Wodr
# ------------------------- 类、结构体、数据结构 -------------------------
LOCAL_CFLAGS += -Wlarger-than=1024
LOCAL_CFLAGS += -Wframe-larger-than=1024
LOCAL_CFLAGS += -Wfree-nonheap-object
LOCAL_CFLAGS += -Wstack-usage=1024
# LOCAL_CFLAGS += -Wscalar-storage-order
LOCAL_CFLAGS += -Wmissing-field-initializers
LOCAL_CFLAGS += -Wpacked
LOCAL_CFLAGS += -Wpacked-bitfield-compat
# LOCAL_CFLAGS += -Wpacked-not-aligned
# LOCAL_CFLAGS += -Wpadded
LOCAL_CFLAGS += -Wstack-protector
# ------------------------- 变量 -------------------------
LOCAL_CFLAGS += -Wnonnull  
LOCAL_CFLAGS += -Wvolatile-register-var  
LOCAL_CFLAGS += -Wtype-limits  
LOCAL_CFLAGS += -Wuninitialized
LOCAL_CFLAGS += -Wmaybe-uninitialized
# warning: 'va_start' has undefined behavior with reference types [-Wvarargs]
LOCAL_CFLAGS += -Wvarargs
# Warn for variables that might be changed by longjmp or vfork.
LOCAL_CFLAGS += -Wclobbered  
# LOCAL_CFLAGS += -Wabsolute-value
LOCAL_CFLAGS += -Waddress
LOCAL_CFLAGS += -Wmultichar
# ------------------------- 运算 -------------------------
LOCAL_CFLAGS += -Wenum-compare
# LOCAL_CFLAGS += -Wenum-conversion
# int i = i;
LOCAL_CFLAGS += -Winit-self
LOCAL_CFLAGS += -Wparentheses  
LOCAL_CFLAGS += -Wsizeof-pointer-memaccess 
LOCAL_CFLAGS += -Wstrict-aliasing  
# LOCAL_CFLAGS += -Wfloat-equal
# int i = 3;
# int ans = (++i)+(++i)+(++i);
# 序列点代码
LOCAL_CFLAGS += -Wsequence-point  
LOCAL_CFLAGS += -Wdiv-by-zero
LOCAL_CFLAGS += -Wlogical-op
# LOCAL_CFLAGS += -Wlogical-not-parentheses
LOCAL_CFLAGS += -Woverflow
# LOCAL_CFLAGS += -Wrestrict
LOCAL_CFLAGS += -Wvector-operation-performance
LOCAL_CFLAGS += -Woverlength-strings
# LOCAL_CFLAGS += -Wshift-count-negative
# LOCAL_CFLAGS += -Wshift-count-overflow
# LOCAL_CFLAGS += -Wshift-overflow=1
# LOCAL_CFLAGS += -Wstring-compare
# LOCAL_CFLAGS += -Wstringop-overflow=2
# LOCAL_CFLAGS += -Wno-stringop-truncation
# ------------------------- 数组 -------------------------
# LOCAL_CFLAGS += -Warray-bounds=1
LOCAL_CFLAGS += -Wvla
# ------------------------- 类型转换 -------------------------
# LOCAL_CFLAGS += -Wsign-compare
# LOCAL_CFLAGS += -Wconversion-null
# LOCAL_CFLAGS += -Wconversion
# LOCAL_CFLAGS += -Warith-conversion
# LOCAL_CFLAGS += -Wfloat-conversion
# LOCAL_CFLAGS += -Wsign-conversion
# LOCAL_CFLAGS += -Wbool-compare 
# LOCAL_CFLAGS += -Wbool-operation  
# LOCAL_CFLAGS += -Wint-conversion
# LOCAL_CFLAGS += -Wpointer-compare
# LOCAL_CFLAGS += -Wcast-qual
# LOCAL_CFLAGS += -Wcast-align=strict
# LOCAL_CFLAGS += -Wcast-function-type  
# LOCAL_CFLAGS +=  -Wwrite-strings
# LOCAL_CFLAGS += -Wincompatible-pointer-types
# LOCAL_CFLAGS += -Wlto-type-mismatch
# ------------------------- 函数 -------------------------
LOCAL_CFLAGS += -Winline
# LOCAL_CFLAGS += -Wignored-qualifiers 
LOCAL_CFLAGS += -Wempty-body  
LOCAL_CFLAGS += -Wunreachable-code
LOCAL_CFLAGS += -Wreturn-type
LOCAL_CFLAGS += -Wsuggest-attribute=pure
LOCAL_CFLAGS += -Wsuggest-attribute=const
LOCAL_CFLAGS += -Wsuggest-attribute=noreturn
# LOCAL_CFLAGS += -Wmissing-noreturn
# LOCAL_CFLAGS += -Wsuggest-attribute=malloc
LOCAL_CFLAGS += -Wsuggest-attribute=format
# LOCAL_CFLAGS += -Wmissing-format-attribute
# LOCAL_CFLAGS += -Wsuggest-attribute=cold
# LOCAL_CFLAGS += -Walloc-zero
# LOCAL_CFLAGS += -Walloc-size-larger-than=1024
# LOCAL_CFLAGS += -Wattribute-alias=1
# LOCAL_CFLAGS += -Wdiscarded-qualifiers
# LOCAL_CFLAGS += -Wdiscarded-array-qualifiers
LOCAL_CFLAGS += -Wpointer-arith
LOCAL_CFLAGS += -Waggregate-return
# LOCAL_CFLAGS += -Wbuiltin-declaration-mismatch
LOCAL_CFLAGS += -Wmissing-declarations
# ------------------------- 宏 -------------------------
# LOCAL_CFLAGS += -Wexpansion-to-defined
LOCAL_CFLAGS += -Wendif-labels
# LOCAL_CFLAGS += -Wno-endif-labels
# LOCAL_CFLAGS += -Wdate-time
LOCAL_CFLAGS += -Wbuiltin-macro-redefined
LOCAL_CFLAGS += -Wvariadic-macros
# ------------------------- switch -------------------------
LOCAL_CFLAGS += -Wswitch-default
LOCAL_CFLAGS += -Wswitch-enum
# LOCAL_CFLAGS += -Wswitch-bool
# LOCAL_CFLAGS += -Wswitch-outside-range
# LOCAL_CFLAGS += -Wswitch-unreachable
# LOCAL_CFLAGS += -Wswitch
# LOCAL_CFLAGS += -Werror=switch
# LOCAL_CFLAGS += -Wno-error=switch
# ------------------------- 语句 -------------------------
# LOCAL_CFLAGS += -Wduplicated-branches
# LOCAL_CFLAGS += -Wduplicated-cond
LOCAL_CFLAGS += -Wunsafe-loop-optimizations
LOCAL_CFLAGS += -Wc++11-compat
# LOCAL_CFLAGS += -Wdangling-else
LOCAL_CFLAGS += -Waggressive-loop-optimizations
LOCAL_CFLAGS += -Winvalid-pch
# LOCAL_CFLAGS += -Wpedantic
# A pointer is compared against integer zero with <, <=, >, or >=.
# (C++ only) An enumerator and a non-enumerator both appear in a conditional expression.
# (C++ only) Ambiguous virtual bases.
# (C++ only) Subscripting an array that has been declared register.
# (C++ only) Taking the address of a variable that has been declared register.
# (C++ only) A base class is not initialized in the copy constructor of a derived class.
# LOCAL_CFLAGS += -Wextra
# ------------------------- 注释 -------------------------
LOCAL_CFLAGS += -Wcomment
LOCAL_CFLAGS += -Wcomments
LOCAL_CFLAGS += -Wtrigraphs

# LOCAL_CFLAGS += -Wformat-security
LOCAL_CFLAGS += -Wformat=0
# LOCAL_CFLAGS += -Wreorder   
LOCAL_CFLAGS += -Wstrict-overflow=4
LOCAL_CFLAGS += -Winvalid-memory-model
# Warn about code affected by ABI changes.
LOCAL_CFLAGS += -Wabi
# LOCAL_CFLAGS += -Wshadow-ivar
# LOCAL_CFLAGS += -Wshadow=local
# LOCAL_CFLAGS += -Wshadow=compatible-local
# LOCAL_CFLAGS += -Wshadow=global
# ------------------------- 报错开关 -------------------------
# 把所有的警告都视为错误处理。
# LOCAL_CFLAGS += -Werror
# This option causes the compiler to abort compilation on the first error occurred rather than trying to keep going and printing further error messages.
LOCAL_CFLAGS += -Wfatal-errors

# LOCAL_CFLAGS += -Wcatch-value
# valid for C/ObjC but not for C++
# LOCAL_CFLAGS += -Wimplicit
# LOCAL_CFLAGS += -Wimplicit-int
# LOCAL_CFLAGS += -Wimplicit-function-declaration
# LOCAL_CFLAGS += -Wold-style-declaration
# LOCAL_CFLAGS += -Woverride-init  
# LOCAL_CFLAGS += -Woverride-init-side-effects
# LOCAL_CFLAGS += -Wpointer-sign  
# LOCAL_CFLAGS += -Wstrict-prototypes
# LOCAL_CFLAGS += -Wno-strict-prototypes
# LOCAL_CFLAGS += -Wbad-function-cast
# LOCAL_CFLAGS += -Wunsuffixed-float-constants
# LOCAL_CFLAGS += -Wmissing-parameter-type
# LOCAL_CFLAGS += -Wmissing-prototypes
# LOCAL_CFLAGS += -Wjump-misses-init
# LOCAL_CFLAGS += -Wnested-externs
# LOCAL_CFLAGS += -Wtraditional
# LOCAL_CFLAGS += -Wtraditional-conversion 
# LOCAL_CFLAGS += -Wdeclaration-after-statement


# unknown
# LOCAL_CFLAGS += -Wdeprecated-copy 
# LOCAL_CFLAGS += -Wimplicit-fallthrough=3 
# LOCAL_CFLAGS += -Wmultistatement-macros
# LOCAL_CFLAGS += -Wzero-length-bounds
# LOCAL_CFLAGS += -Wlogical-not-parentheses
# LOCAL_CFLAGS += -Wmemset-elt-size 
# LOCAL_CFLAGS += -Wmemset-transposed-args
# LOCAL_CFLAGS += -Wmisleading-indentation
# LOCAL_CFLAGS += -Wmissing-attributes
# LOCAL_CFLAGS += -Wmissing-brace
# LOCAL_CFLAGS += -Wopenmp-simd 
# LOCAL_CFLAGS += -Wpessimizing-move
# LOCAL_CFLAGS += -Wrestrict   
# LOCAL_CFLAGS += -Wtautological-compare  
# LOCAL_CFLAGS += -Wmissing-parameter-types
# LOCAL_CFLAGS += -Wnonnull-compare  
# LOCAL_CFLAGS += -Wsizeof-pointer-div 
# LOCAL_CFLAGS += -Wsuggest-final-types
# LOCAL_CFLAGS += -Wredundant-move
# LOCAL_CFLAGS += -Wshift-negative-value 
# LOCAL_CFLAGS += -Wformat-overflow
# LOCAL_CFLAGS += -Wformat-truncation
# LOCAL_CFLAGS += -Wint-in-bool-context

LOCAL_CPPFLAGS += -fexpensive-optimizations
LOCAL_CPPFLAGS += -fomit-frame-pointer
LOCAL_CPPFLAGS += -fstack-protector
LOCAL_CPPFLAGS += -fsigned-char
LOCAL_CPPFLAGS += -fsyntax-only
LOCAL_CPPFLAGS += -fmax-errors=0
LOCAL_CPPFLAGS += -fstrict-aliasing
LOCAL_CPPFLAGS += -ftree-vrp
# 默认值
LOCAL_CPPFLAGS += -finline-limit=600
# LOCAL_CPPFLAGS += -freorder-blocks
# LOCAL_CPPFLAGS += -freorder-functions
# ================ debug ================
endif

LOCAL_CFLAGS += -Wno-deprecated
LOCAL_CFLAGS += -Wno-deprecated-declarations
LOCAL_CFLAGS += -Wno-int-to-pointer-cast
LOCAL_CFLAGS += -Wreturn-local-addr
LOCAL_CFLAGS +=  -Wwrite-strings

LOCAL_CPPFLAGS += -Wno-deprecated
LOCAL_CPPFLAGS += -Wno-deprecated-declarations
LOCAL_CPPFLAGS += -Wno-int-to-pointer-cast
LOCAL_CPPFLAGS += -Wreturn-local-addr
LOCAL_CPPFLAGS +=  -Wwrite-strings
LOCAL_CPPFLAGS += -frtti
LOCAL_CPPFLAGS += -fvisibility=hidden

include $(BUILD_SHARED_LIBRARY)

# $(call import-module, OgreMainExt)
# $(call import-module, OgreMain)
#$(call import-module, ScriptSupport)
#$(call import-module, RenderSystem_OGL)
$(call import-module, RakNet/android/jni)
$(call import-module, iworld)
# $(call import-module, ../deps/libwebsockets)
