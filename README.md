# Filler

Filler is a game between two AIs that run inside a simple VM (filler_vm).
Each turn both AIs are given randomly generated blocks to place on a square grid.
With each of these pieces the AI's job is to cover the largest part of the grid,
common strategies include cutting off you opponent, or trying to surround him,
predict where he will go to flash there before he will.
I used a heatmap base on two heuristics :
  - boxes directly around the opponnent have high value
  - boxes around the the 3/4 and 1/4 of the map horizontally and vertically are given value to
      give the AI more liberty, so that it isn't solely stuck on the opponent player's positions
 After finding the places in the map with value, the heatmap is "smoothed out" so that the AI can give value 
 to boxes around the important areas

    ./usage : ./filler_vm -f [map] -p1 ./[player one's AI] -p2 [player two's AI]
    or an example command could be
    ./filler_vm -f maps/map02 -p1 ./jucapik.filler -p2 AIs/cpoulet.filler | ./shower.filler
  
  The Ai I submitted for this project is jucapik.filler and the visualizer if shower.filler.
  When in the visualizer, Press the keys P or O to advance in the battle.
  

I was given 124/100 (maximum grade is 125/100) for this project.

Made using only malloc, free, exit, open and close and functions from the SDL library for the visualizer.
