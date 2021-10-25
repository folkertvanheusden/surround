# CMake file for DISTRHO Plugins #
# ------------------------------ #

dpf_add_plugin(d_surround
  TARGETS ladspa lv2 vst2
  FILES_DSP
      surround.cpp)

target_include_directories(
  d_surround PUBLIC ".")
