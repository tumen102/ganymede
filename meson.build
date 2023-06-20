project('ganymede', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

incdir = include_directories('/home/keepalive/imgui/backends', '/home/keepalive/imgui')

glfw_lib = subproject('glfw').get_variable('glfw_dep')
gl = dependency('gl')

files = files(
	'main.cpp'
)

executable('ganymede',
	files,
	include_directories : incdir,
	dependencies : [glfw_lib, gl],
	install : true)
