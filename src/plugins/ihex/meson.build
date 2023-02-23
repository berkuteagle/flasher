plugin_name = 'ihex-@0@'.format(api_version)

msgfmt_plugin_cmd = [
  find_program('msgfmt'),
  '--desktop',
  '--keyword=Name',
  '--keyword=Description',
  '--template=@INPUT@',
  '-d', join_paths(meson.project_build_root(), 'po'),
  '--output=@OUTPUT@'
]

shared_module(
  plugin_name,
  files('flasher-ihex.c'),
  include_directories: [include_directories('.'), flasher_lib_include],
  dependencies: [flasher_dep, libpeas_dep, glib_dep],
  link_with: flasher_lib,
  c_args: project_c_args,
  install_dir: join_paths(get_option('prefix'), get_option('libdir'), 'flasher', 'plugins'),
  install: true,
)

custom_target(
  plugin_name,
  input: plugin_name + '.plugin.in',
  output: plugin_name + '.plugin',
  command: msgfmt_plugin_cmd,
  install: true,
  install_dir: join_paths(get_option('prefix'), get_option('libdir'), 'flasher', 'plugins')
)
