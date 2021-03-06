import json
import evolution
from deap import base, creator, tools


with open('Data/intersectionScores.json') as file:
    j = json.load(file)

i=0
for ind in evolution.population:
    ind.fitness.values = j["intersection" + str(i)]["forking_points"]
    i += 1
    print(ind.fitness)

selected = tools.selBest(evolution.population, 2)
print(selected)	