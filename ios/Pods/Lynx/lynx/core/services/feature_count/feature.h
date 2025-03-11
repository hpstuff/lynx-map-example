// Copyright 2023 The Lynx Authors. All rights reserved.

#ifndef CORE_SERVICES_FEATURE_COUNT_FEATURE_H_
#define CORE_SERVICES_FEATURE_COUNT_FEATURE_H_

//!!!!! DO NOT MODIFY
//!!!!! See `tools/feature_count/README.md`
#include <cstdint>
namespace lynx {
namespace tasm {
namespace report {
static constexpr const uint32_t kAllFeaturesCount = 72;

enum LynxFeature : uint32_t {
  CPP_ENABLE_LYNX_NETWORK = 0,
  CPP_ENABLE_NEW_ANIMATOR_TRUE = 1,
  CPP_ENABLE_NEW_ANIMATOR_IOS = 2,
  CPP_ENABLE_NEW_ANIMATOR_FALSE = 3,
  CPP_ENABLE_NEW_GESTURE = 4,
  CPP_DISABLE_PERF_COLLECTOR = 5,
  CPP_LIST_NEW_ARCH_NOT_ENABLED = 6,
  CPP_ENABLE_NATIVE_LIST = 7,
  CPP_FE_CUSTOM_EVENT_BUBBLE_BUG = 8,
  CPP_FE_CUSTOM_EVENT_PARAMETER_BUG = 9,
  CPP_UI_CUSTOM_EVENT_PARAMETER_BUG = 10,
  CPP_ENABLE_NEW_ANIMATOR_DEFAULT = 11,
  CPP_USE_RADON = 12,
  CPP_DISABLE_SUPPORT_COMPONENT_JS = 13,
  CPP_DISABLE_EVENT_REFACTOR = 14,
  CPP_DISABLE_MULTI_TOUCH = 15,
  CPP_USE_GRID_DISPLAY = 16,
  CPP_USE_RELATIVE_DISPLAY = 17,
  CPP_ENABLE_CLASS_MERGE = 18,
  CPP_USE_LEGACY_LEPUS_BRIDGE_SYNC = 19,
  CPP_USE_LEGACY_LEPUS_BRIDGE_ASYNC = 20,
  CPP_USE_NATIVE_PROMISE = 21,
  CPP_ENABLE_CREATE_UI_ASYNC = 22,
  CPP_ENABLE_PSEUDO_SELECTOR = 23,
  CPP_ENABLE_PLACE_HOLDER_STYLE = 24,
  CPP_ENABLE_BEFORE_AFTER_PSEUDO = 25,
  CPP_ENABLE_PSEUDO_NOT_CSS = 26,
  CPP_ENABLE_HIGH_REFRESH_RATE = 27,
  CPP_ENABLE_PSEUDO_CHILD_CSS = 28,
  CPP_ENABLE_EXTERNAL_CLASS_CSS = 29,
  CPP_LIST_NODE = 30,
  TYPESCRIPT_BUNDLE_SUPPORT_LOAD_SCRIPT = 31,
  OBJC_IMPLICIT_ANIMATION = 32,
  OBJC_PAGE_RTL = 33,
  OBJC_PAGE_RTL_WITH_LIST = 34,
  OBJC_DISABLE_NEW_TRANSFORM_ORIGIN_IOS = 35,
  OBJC_AUTO_RESUME_ANIMATION = 36,
  OBJC_LAYOUT_ANIMATION_CREATE = 37,
  OBJC_LAYOUT_ANIMATION_UPDATE = 38,
  OBJC_LAYOUT_ANIMATION_DELETE = 39,
  OBJC_ENTER_TRANSITION_NAME = 40,
  OBJC_EXIT_TRANSITION_NAME = 41,
  OBJC_PAUSE_TRANSITION_NAME = 42,
  OBJC_RESUME_TRANSITION_NAME = 43,
  OBJC_UPDATE_FONT_SCALE = 44,
  OBJC_DISABLE_REUSE_ANIMATION_STATE = 45,
  OBJC_LIST_IOS_RECURSIVE_LAYOUT = 46,
  OBJC_LIST_IOS_DISABLE_SCROLL_ANIM_DURING_LAYOUT = 47,
  OBJC_LIST_IOS_USE_SCROLLER = 48,
  OBJC_LIST_PAGING_ENABLE = 49,
  OBJC_DISABLE_TOUCH_REFACTOR = 50,
  OBJC_SET_THEME_IOS = 51,
  OBJC_GET_THEME_IOS = 52,
  OBJC_UI_OWNER_RELEASE_ON_CHILD_THREAD = 53,
  OBJC_ENABLE_ASYNC_LIST = 54,
  JAVA_HARDWARE_LAYER = 55,
  JAVA_NEW_SWIPER_NOT_ENABLED = 56,
  JAVA_LAYOUT_ANIMATION_CREATE_ANDROID = 57,
  JAVA_LAYOUT_ANIMATION_UPDATE_ANDROID = 58,
  JAVA_LAYOUT_ANIMATION_DELETE_ANDROID = 59,
  JAVA_ENTER_TRANSITION_NAME_ANDROID = 60,
  JAVA_EXIT_TRANSITION_NAME_ANDROID = 61,
  JAVA_PAUSE_TRANSITION_NAME_ANDROID = 62,
  JAVA_RESUME_TRANSITION_NAME_ANDROID = 63,
  JAVA_UPDATE_FONT_SCALE = 64,
  JAVA_DISABLE_REUSE_ANIMATION_STATE = 65,
  JAVA_DISABLE_FOLDVIEW_STOP_TOUCH_STOP_FLING = 66,
  JAVA_ASYNC_REDIRECT = 67,
  JAVA_ENABLE_ASYNC_REQUEST_IMAGE = 68,
  JAVA_SET_THEME_ANDROID = 69,
  JAVA_GET_THEME_ANDROID = 70,
  JAVA_ENABLE_ASYNC_LIST = 71,
};

inline const char* LynxFeatureToString(LynxFeature feature) {
  switch (feature) {
    case CPP_ENABLE_LYNX_NETWORK: {
      return "cpp_enable_lynx_network";
    }
    case CPP_ENABLE_NEW_ANIMATOR_TRUE: {
      return "cpp_enable_new_animator_true";
    }
    case CPP_ENABLE_NEW_ANIMATOR_IOS: {
      return "cpp_enable_new_animator_ios";
    }
    case CPP_ENABLE_NEW_ANIMATOR_FALSE: {
      return "cpp_enable_new_animator_false";
    }
    case CPP_ENABLE_NEW_GESTURE: {
      return "cpp_enable_new_gesture";
    }
    case CPP_DISABLE_PERF_COLLECTOR: {
      return "cpp_disable_perf_collector";
    }
    case CPP_LIST_NEW_ARCH_NOT_ENABLED: {
      return "cpp_list_new_arch_not_enabled";
    }
    case CPP_ENABLE_NATIVE_LIST: {
      return "cpp_enable_native_list";
    }
    case CPP_FE_CUSTOM_EVENT_BUBBLE_BUG: {
      return "cpp_fe_custom_event_bubble_bug";
    }
    case CPP_FE_CUSTOM_EVENT_PARAMETER_BUG: {
      return "cpp_fe_custom_event_parameter_bug";
    }
    case CPP_UI_CUSTOM_EVENT_PARAMETER_BUG: {
      return "cpp_ui_custom_event_parameter_bug";
    }
    case CPP_ENABLE_NEW_ANIMATOR_DEFAULT: {
      return "cpp_enable_new_animator_default";
    }
    case CPP_USE_RADON: {
      return "cpp_use_radon";
    }
    case CPP_DISABLE_SUPPORT_COMPONENT_JS: {
      return "cpp_disable_support_component_js";
    }
    case CPP_DISABLE_EVENT_REFACTOR: {
      return "cpp_disable_event_refactor";
    }
    case CPP_DISABLE_MULTI_TOUCH: {
      return "cpp_disable_multi_touch";
    }
    case CPP_USE_GRID_DISPLAY: {
      return "cpp_use_grid_display";
    }
    case CPP_USE_RELATIVE_DISPLAY: {
      return "cpp_use_relative_display";
    }
    case CPP_ENABLE_CLASS_MERGE: {
      return "cpp_enable_class_merge";
    }
    case CPP_USE_LEGACY_LEPUS_BRIDGE_SYNC: {
      return "cpp_use_legacy_lepus_bridge_sync";
    }
    case CPP_USE_LEGACY_LEPUS_BRIDGE_ASYNC: {
      return "cpp_use_legacy_lepus_bridge_async";
    }
    case CPP_USE_NATIVE_PROMISE: {
      return "cpp_use_native_promise";
    }
    case CPP_ENABLE_CREATE_UI_ASYNC: {
      return "cpp_enable_create_ui_async";
    }
    case CPP_ENABLE_PSEUDO_SELECTOR: {
      return "cpp_enable_pseudo_selector";
    }
    case CPP_ENABLE_PLACE_HOLDER_STYLE: {
      return "cpp_enable_place_holder_style";
    }
    case CPP_ENABLE_BEFORE_AFTER_PSEUDO: {
      return "cpp_enable_before_after_pseudo";
    }
    case CPP_ENABLE_PSEUDO_NOT_CSS: {
      return "cpp_enable_pseudo_not_css";
    }
    case CPP_ENABLE_HIGH_REFRESH_RATE: {
      return "cpp_enable_high_refresh_rate";
    }
    case CPP_ENABLE_PSEUDO_CHILD_CSS: {
      return "cpp_enable_pseudo_child_css";
    }
    case CPP_ENABLE_EXTERNAL_CLASS_CSS: {
      return "cpp_enable_external_class_css";
    }
    case CPP_LIST_NODE: {
      return "cpp_list_node";
    }
    case TYPESCRIPT_BUNDLE_SUPPORT_LOAD_SCRIPT: {
      return "typescript_bundle_support_load_script";
    }
    case OBJC_IMPLICIT_ANIMATION: {
      return "objc_implicit_animation";
    }
    case OBJC_PAGE_RTL: {
      return "objc_page_rtl";
    }
    case OBJC_PAGE_RTL_WITH_LIST: {
      return "objc_page_rtl_with_list";
    }
    case OBJC_DISABLE_NEW_TRANSFORM_ORIGIN_IOS: {
      return "objc_disable_new_transform_origin_ios";
    }
    case OBJC_AUTO_RESUME_ANIMATION: {
      return "objc_auto_resume_animation";
    }
    case OBJC_LAYOUT_ANIMATION_CREATE: {
      return "objc_layout_animation_create";
    }
    case OBJC_LAYOUT_ANIMATION_UPDATE: {
      return "objc_layout_animation_update";
    }
    case OBJC_LAYOUT_ANIMATION_DELETE: {
      return "objc_layout_animation_delete";
    }
    case OBJC_ENTER_TRANSITION_NAME: {
      return "objc_enter_transition_name";
    }
    case OBJC_EXIT_TRANSITION_NAME: {
      return "objc_exit_transition_name";
    }
    case OBJC_PAUSE_TRANSITION_NAME: {
      return "objc_pause_transition_name";
    }
    case OBJC_RESUME_TRANSITION_NAME: {
      return "objc_resume_transition_name";
    }
    case OBJC_UPDATE_FONT_SCALE: {
      return "objc_update_font_scale";
    }
    case OBJC_DISABLE_REUSE_ANIMATION_STATE: {
      return "objc_disable_reuse_animation_state";
    }
    case OBJC_LIST_IOS_RECURSIVE_LAYOUT: {
      return "objc_list_ios_recursive_layout";
    }
    case OBJC_LIST_IOS_DISABLE_SCROLL_ANIM_DURING_LAYOUT: {
      return "objc_list_ios_disable_scroll_anim_during_layout";
    }
    case OBJC_LIST_IOS_USE_SCROLLER: {
      return "objc_list_ios_use_scroller";
    }
    case OBJC_LIST_PAGING_ENABLE: {
      return "objc_list_paging_enable";
    }
    case OBJC_DISABLE_TOUCH_REFACTOR: {
      return "objc_disable_touch_refactor";
    }
    case OBJC_SET_THEME_IOS: {
      return "objc_set_theme_ios";
    }
    case OBJC_GET_THEME_IOS: {
      return "objc_get_theme_ios";
    }
    case OBJC_UI_OWNER_RELEASE_ON_CHILD_THREAD: {
      return "objc_ui_owner_release_on_child_thread";
    }
    case OBJC_ENABLE_ASYNC_LIST: {
      return "objc_enable_async_list";
    }
    case JAVA_HARDWARE_LAYER: {
      return "java_hardware_layer";
    }
    case JAVA_NEW_SWIPER_NOT_ENABLED: {
      return "java_new_swiper_not_enabled";
    }
    case JAVA_LAYOUT_ANIMATION_CREATE_ANDROID: {
      return "java_layout_animation_create_android";
    }
    case JAVA_LAYOUT_ANIMATION_UPDATE_ANDROID: {
      return "java_layout_animation_update_android";
    }
    case JAVA_LAYOUT_ANIMATION_DELETE_ANDROID: {
      return "java_layout_animation_delete_android";
    }
    case JAVA_ENTER_TRANSITION_NAME_ANDROID: {
      return "java_enter_transition_name_android";
    }
    case JAVA_EXIT_TRANSITION_NAME_ANDROID: {
      return "java_exit_transition_name_android";
    }
    case JAVA_PAUSE_TRANSITION_NAME_ANDROID: {
      return "java_pause_transition_name_android";
    }
    case JAVA_RESUME_TRANSITION_NAME_ANDROID: {
      return "java_resume_transition_name_android";
    }
    case JAVA_UPDATE_FONT_SCALE: {
      return "java_update_font_scale";
    }
    case JAVA_DISABLE_REUSE_ANIMATION_STATE: {
      return "java_disable_reuse_animation_state";
    }
    case JAVA_DISABLE_FOLDVIEW_STOP_TOUCH_STOP_FLING: {
      return "java_disable_foldview_stop_touch_stop_fling";
    }
    case JAVA_ASYNC_REDIRECT: {
      return "java_async_redirect";
    }
    case JAVA_ENABLE_ASYNC_REQUEST_IMAGE: {
      return "java_enable_async_request_image";
    }
    case JAVA_SET_THEME_ANDROID: {
      return "java_set_theme_android";
    }
    case JAVA_GET_THEME_ANDROID: {
      return "java_get_theme_android";
    }
    case JAVA_ENABLE_ASYNC_LIST: {
      return "java_enable_async_list";
    }
    default: {
      return "";
    }
  };
}

}  // namespace report
}  // namespace tasm
}  // namespace lynx
//!!!!! DO NOT MODIFY
//!!!!! See `tools/feature_count/README.md`

#endif  // CORE_SERVICES_FEATURE_COUNT_FEATURE_H_
