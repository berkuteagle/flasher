flasher_sources = [
  'main.c',
  'flasher-application.c',
  'flasher-window.c',
]

flasher_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1'),
  dependency('libpeas-1.0'),
]

flasher_sources += gnome.compile_resources('flasher-resources',
  'flasher.gresource.xml',
  c_name: 'flasher'
)

executable('flasher', flasher_sources,
  dependencies: flasher_deps,
       install: true,
)
