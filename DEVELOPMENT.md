# Development
---
---
- **5/6/20** Added all functionality. An ice table can now be 
    solved. Added code to help with displaying the solved ice
    table onto the GUI. Test cases were added to test methods 
    for the IceSolver class.
---
- **5/5/20** Changed a couple helper functions to avoid repetitive
    code. PopulateEquationData() works properly and reads in the
    chemical equation, initial reactant concentrations, initial
    product concentrations, and the Ka value.
---
- **5/4/20** Finished quadratic formula helper function. Used
    a stringstream to split an equation every time the '+' 
    character appeared. The atof method was used to convert
    from string to double and aided in calculations. 
---
- **4/30/20** Added functionality to solve a simple Ice Table
    problem. Also created an IceSolver class that aids in solving
    an Ice Table. Several helper functions are in the IceSolver
    class that help solve these problems such as SolveQuadratic()
    and ParseConcentrations(); 
    
    Need to complete the following:
    
   -[X] Solve simple Ice Table
    
   -[X] Be able to solve more complex Ice Tables
    
   -[X] Use and fill out helper functions that aid in solving
          complex Ice Tables.
          
   -[X] Try to fix input from GUI, if not just output a solved
          Ice Table.
---
- **4/28/20** Added documentation throughout the project
    to make code more comprehensible. 
---
- **4/27/20** Tried creating a struct to better handle input
    from ImGui. Did not work, decided to focus on the
    actual solving and be able to solve an Ice Table problem.
    Will get back to the GUI input later. May just take input
    from a file and output via the GUI.
---
- **4/23/20** Able to use the ImGui cinder block, but 
    the InputText method is not taking in and storing input.
---
- **4/21/20** Setup Cinder-ImGui cinder block
---
- **4/19/20** Downloaded project
---
