flasher_sources = [
  'flasher.c',
  'flasher-application.c',
  'flasher-application-activatable.c',
  'flasher-window.c',
]

flasher_include = include_directories('.')

flasher_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1'),
  dependency('libpeas-1.0'),
]

flasher_sources += gnome.compile_resources('flasher-resources',
  'flasher.gresource.xml',
  c_name: 'flasher'
)

subdir('plugins')

executable('flasher', flasher_sources,
  include_directories: flasher_include,
         dependencies: flasher_deps,
              install: true,
)
