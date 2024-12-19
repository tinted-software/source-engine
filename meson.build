project(
  'source-engine',
  'c',
  'cpp',
  default_options: [
    'c_std=c2x',
    'cpp_std=c++26',
    'warning_level=3',
  ]
)

cc = meson.get_compiler('cpp')

thread_dep = dependency('threads')
execinfo_dep = cc.find_library('execinfo', required: false)

subdir('tier0')
