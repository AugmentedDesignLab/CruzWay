import os
import subprocess
import sys

parameter_values = []
"""
output, input = subprocess.Popen(["C:\\Users\\iparanja\\Desktop\\cement\\IntGen\\env\\Scripts\\activate.bat",
                                          "&", "cd", "C:\\Users\\iparanja\\Documents\\Unreal Projects\\NewS2U\\Sumo2Unreal_4.22\\Road_Network_Files\\road_intersections",
                                          "&", "intgen", "-in", "4", "-cr", "True", "-tl", "1",
                                          "&", "netgenerate", "--intgen-specs", "--intgen-specs.file=output.json", "--output-file=four_one_0.xml",
                                          "&", "intgen", "-in", "5", "-cr", "True","-tl", "2",
                                          "&", "netgenerate", "--intgen-specs", "--intgen-specs.file=output.json", "--output-file=four_one_1.xml",
                                          "&", "intgen", "-in", "3", "-cr", "True","-tl", "1",
                                          "&", "netgenerate", "--intgen-specs", "--intgen-specs.file=output.json", "--output-file=four_one_2.xml",
                                          ], stdout=subprocess.PIPE).communicate()
print(output)
"""



def main():
    road_file_string = "--output-file=four_one_"
     #A list of turn_lane_inputs
    print("number of possible turn lanes...\n")
    print(parameter_values)
    for i in range(len(parameter_values)):
        road_file_string = road_file_string + str(i) + ".xml"
        print(road_file_string)
        output, input = subprocess.Popen(["C:\\Users\\iparanja\\Desktop\\cement\\IntGen\\env\\Scripts\\activate.bat",
                                          "&", "cd", "C:\\Users\\iparanja\\Documents\\Unreal Projects\\NewS2U\\Sumo2Unreal_4.22\\Road_Network_Files\\road_intersections",
                                          "&", "intgen", "-in", str(parameter_values[i][1]), "-cr", "True", "-tl", str(parameter_values[i][0]), 
                                          "ind-roads", "--roaddetails", str(parameter_values[i][1]), str(parameter_values[i][2]), "100",  
                                          "&", "netgenerate", "--intgen-specs", "--intgen-specs.file=output.json", road_file_string,
                                          ], stdout=subprocess.PIPE).communicate()
        print(output)
        old_string = str(i) + ".xml"
        road_file_string = road_file_string.replace(old_string, "")












#unreal.SystemLibrary.draw_debug_box(unreal.EditorLevelLibrary.get_editor_world(), unreal.Vector(0.0, 0.0, 0.0), unreal.Vector(5.0, 5.0, 5.0), unreal.LinearColor.BLUE, rotation=[0.0, 0.0, 0.0], duration=60.0, thickness=5.0)
#unreal.SystemLibrary.draw_debug_string(unreal.EditorLevelLibrary.get_editor_world(), unreal.Vector(20.0, 0.0, 0.0), "HERE", test_base_actor=None, text_color=unreal.LinearColor.BLUE, duration=60.0)
#unreal.SystemLibrary.draw_debug_line(unreal.EditorLevelLibrary.get_editor_world(), unreal.Vector(20.0, 0.0, 0.0), unreal.Vector(50.0, 0.0, 0.0), unreal.LinearColor.BLUE, duration=60.0, thickness=5.0)
