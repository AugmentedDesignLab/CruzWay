from deap import base, creator, tools
import random
import sys
import pipeline

print("########inside evolution.py##########")
#Initializing a population
creator.create("Fitness", base.Fitness, weights=(1.0,))
creator.create("Individual", list, fitness=creator.Fitness)

toolbox = base.Toolbox()

#register has one argument as an alias and sucessive argument lists are assigned to the preceding argument
toolbox.register("random_turnlanes", random.randint, 1, 3)
toolbox.register("random_incoming", random.randint, 2, 6)
toolbox.register("random_number_of_lanes", random.randrange, 2, 8, 2)
toolbox.register("individual", tools.initCycle, creator.Individual,
                 (toolbox.random_turnlanes, toolbox.random_incoming, toolbox.random_number_of_lanes), n=1)
toolbox.register("population", tools.initRepeat, list, toolbox.individual)

#Create a population
population = toolbox.population(n=3)
pipeline.parameter_values = population
pipeline.main()

#Test for fitness
