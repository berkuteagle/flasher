plugin_name = 'stlink'
plugin_full_name = '@0@-@1@'.format(plugin_name, api_version)

shared_library(
  plugin_full_name,
  files('stlink.c'),
  include_directories: [include_directories('.'), flasher_lib_include],
  dependencies: [flasher_dep, libpeas_dep, glib_dep],
  link_with: flasher_lib,
  c_args: project_c_args,
  install_dir: plugins_install_dir,
  install: true,
)

custom_target(
  plugin_full_name,
  input: plugin_name + '.plugin.in',
  output: plugin_full_name + '.plugin',
  command: msgfmt_plugin_cmd,
  install: true,
  install_dir: plugins_install_dir
)
