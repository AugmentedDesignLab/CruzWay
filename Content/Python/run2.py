import subprocess

"""
Add path to environment for intgen and python packages
"""
path_to_env_activate = "C:\\Users\\iparanja\\Desktop\\cement\\IntGen\\env\\Scripts\\activate.bat"
path_to_python_scripts = "C:\\Users\\iparanja\\Documents\\Unreal Projects\\NewS2U\\Sumo2Unreal_4.22\\Content\\Python"

output, input = subprocess.Popen([path_to_env_activate,
                                          "&", "cd", path_to_python_scripts,
                                          "&", "py", "selection.py",
                                          ], stdout=subprocess.PIPE).communicate()
print(output)
