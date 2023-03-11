flasher_lib_sources = files(
  'flasher-object.c',
  'flasher-device-extension.c',
  'flasher-file-extension.c',
  'flasher-plugins-engine.c',
  'flasher-extension.c',
  'flasher-memory-map.c',
  'flasher-target.c',
  'flasher-file.c',
  'flasher-device.c',
)

flasher_lib_headers = files(
  'flasher-object.h',
  'flasher-device-extension.h',
  'flasher-file-extension.h',
  'flasher-memory-map.h',
  'flasher-target.h',
  'flasher-file.h',
  'flasher-device.h',
  'flasher-extension.h',
)

flasher_lib_dependencies = [
  glib_dep,
  libpeas_dep,
  libusb_dep,
  dependency('gobject-introspection-1.0')
]

flasher_lib_name = 'flasher-@0@'.format(api_version)

install_headers(
  flasher_lib_headers,
  install_dir: get_option('includedir') / flasher_lib_name / 'flasher',
)

flasher_lib = shared_library(
  flasher_lib_name,
  flasher_lib_sources,
  include_directories: flasher_lib_include,
  dependencies: flasher_lib_dependencies,
  c_args: project_c_args,
  install_dir: join_paths(get_option('prefix'), get_option('libdir')),
  install: true,
)

flasher_dep = declare_dependency(
  include_directories: flasher_lib_include,
  link_with: flasher_lib,
)
