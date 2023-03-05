msgfmt_plugin_cmd = [
  find_program('msgfmt'),
  '--desktop',
  '--keyword=Name',
  '--keyword=Description',
  '--template=@INPUT@',
  '-d', join_paths(meson.project_build_root(), 'po'),
  '--output=@OUTPUT@'
]

plugins_install_dir = join_paths(get_option('prefix'), get_option('libdir'), 'flasher', 'plugins')

subdir('ihex')
subdir('stlink')
