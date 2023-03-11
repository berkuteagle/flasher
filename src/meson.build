api_version = '1.0'

libpeas_dep = dependency('libpeas-1.0')
glib_dep = dependency('glib-2.0')
libusb_dep = dependency('libusb-1.0')

subdir('lib')

flasher_sources = files(
  'flasher.c',
  'flasher-application.c',
  'flasher-window.c',
)

flasher_include = [include_directories('.'), flasher_lib_include]

flasher_dependencies = [
  dependency('gtk4'),
  dependency('libadwaita-1'),
  glib_dep,
  flasher_dep
]

flasher_sources += gnome.compile_resources('flasher-resources',
  'flasher.gresource.xml',
  c_name: 'flasher'
)

subdir('plugins')

executable(
            'flasher',
      flasher_sources,
  include_directories: flasher_include,
         dependencies: flasher_dependencies,
              install: true,
)
