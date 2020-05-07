# Chemistry ICE Table Solver

## Project Purpose
This project solves a chemistry ICE (Initial, Change, Equilibirum)
table problem. It takes in a string that contains a chemical 
equation, initial reactant and product concentrations, and a K 
value and displays a solved ICE table.
---
## ICE Table Display
 ####ICE Table:
       
        Must have a ':' character after each reactant or product and a comma separating the chemical equation, initial
        concentrations, and the K value.
        
        Sample Usage:
        
        In my_app.cc just change the string in the constructor of a given IceSolver object to contain the necessary
        information.
        
        IceSolver example("HC2H3O2:->:C2H3O2-:+:H+, 0.20, 0.00, 0.00, 1.8e-05");
                   
        Unsolved ICE Table: 
        
                       [HC2H3O2]       [H+]        [C2H3O2-] 
        Initial          0.20          0.0            0.0
       
        Change            -x           +x             +x
       
        Equilibrium    0.20 - x        x              x
       
        Solve for x to find equilibrium concentrations
        
        Solved ICE Table:
        
                       [HC2H3O2]       [H+]        [C2H3O2-] 
        Initial          0.2000        0.0000         0.000
               
        Change          -0.00199      +0.00199       +0.00199
               
        Equilibrium      0.198         0.0199         0.0199

---
## External Cinder Block
This a cinder project and uses the
[Cinder-ImGui](https://github.com/simongeilfus/Cinder-ImGui)
cinder block to display the solved ICE Table.
This [guide](https://courses.grainger.illinois.edu/cs126/sp2020/notes/cmake/)
shows the steps on how to set up this cinder block.

---

