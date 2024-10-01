# FdF

This project focuses on creating a simple wireframe model representation of a 3D landscape by linking various points (`x`, `y`, `z`) in an isometric projection. I used the `MLX42` graphic library to implement this project.

## Program Workflow:
<ol>
  <li><a href="#Input">Input Validation</a></li>
  <li><a href="#Parsing">Map Parsing</a></li>
  <li><a href="#MapConv">Map Conversion</a></li>
  <li><a href="#Set">Setting Coordinates</a></li>
  <li><a href="#Scaling">Scaling Point Values</a></li>
  <li><a href="#Rotating">Rotating Points</a></li>
  <li><a href="#2D">2D Projection Conversion</a></li>
  <li><a href="#Moving">Centering and Moving Points</a></li>
  <li><a href="#Drawing">Line Drawing</a></li>
  <li><a href="#Hooks">Setting up Keyboard and Mouse Controls</a></li>
</ol>

##

<ul>
  <li><a href="#Grade">Grade</a></li>
  <li><a href="#Instructions">Instructions</a></li>
</ul>

##

### <h3 id="Input">1. Input Validation</h3>
In this stage, the program checks that exactly one argument (a text file with the `.fdf` extension) has been passed. It also verifies that the file can be opened and read.

### <h3 id="Parsing">2. Map Parsing</h3>
The program reads the file using the get_next_line function and stores the content in an array of strings. It also counts the number of rows and columns in the map.

### <h3 id="MapConv">3. Map Conversion</h3>
Here, the map is converted into a struct containing height (`z`) values. The array of strings is transformed into a `point` struct, storing the numeric values. If the map includes colors (separated by `commas`), the program converts these into `RGBA` format. If no color is specified, default colors are applied based on the `z` value. The memory used in the previous step is then freed.

### <h3 id="Set">4. Setting Coordinates</h3>
This step fills the 'point' struct with corresponding `x` and `y` coordinates.

### <h3 id="Scaling">5. Scaling Point Values</h3>
In this phase, the points are scaled according to the total number of points in the map. This controls the spacing between points. Zooming and height scaling examples are provided below:

`Zooming:`

![FdF zooming](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/Fdf_zoom.gif)

`Height scaling:`

![Height scaling](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/Fdf_scale_z.gif)

### <h3 id="Rotating">6. Rotating Points</h3>
After scaling, matrix rotation formulas are applied to change the model's angle along the:

<ul>
  <li>x-axis</li>
  <li>y-axis</li>
  <li>z-axis</li>
</ul>

<b>Important!</b> The original angle values are stored before rotation.
Rotation examples are provided below:

`x-axis:`

![Rotate X](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/FdF_x_rot.gif)

`y-axis:`

![Rotate Y](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/FdF_y_rot.gif)

`z-axis:`

![Rotate Z](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/FdF_z_rot.gif)

### <h3 id="2D">7. 2D Projection Conversion</h3>
The program converts the 3D coordinates into either isometric or orthographic projections.
Examples of different projections are shown below:

`isometric:`

![Isometry](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/isometry.png)

`orthographic top-down view:`

![Orthographic top](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/top_view.png)

`orthographic right-side view:`

![Orthographic right](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/right_view.png)

`orthographic front-side view:`

![Orthographic front](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/front_view.png)

### <h3 id="Moving">8. Centering and Moving Points</h3>
Next, the model is moved to avoid image cropping by aligning it with the left and top edges of the screen. It is also centered based on the window size. User-controlled movement is added in this phase.
Moving example is shown below:

`Moving:`

![FdF mooving](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/Fdf_move.gif)

### <h3 id="Drawing">9. Line Drawing</h3>
This section uses the `DDA` (Digital Differential Analyzer) algorithm to draw lines. First, horizontal lines are drawn, followed by vertical lines.

### <h3 id="Hooks">10. Setting up Keyboard and Mouse Controls</h3>
Here, keys and mouse controls are configured to change between `isometric` and `orthographic` projections, `move` the model, `rotate` it, `zoom`, and `adjust the height scaling`.

After closing the program (by pressing `ESC` or clicking the `Close` button), all allocated memory is cleaned up.

## <h2 id="Grade">Grade</h2>
Since I implemented actions like moving, scaling, and rotating, I received the maximum score for this project.

![Grade](https://github.com/FPyMEHTAPIU/FdF/blob/main/media/grade.jpg)

## <h2 id="Instructions">Instructions</h2>
Use the `make` command to build the project, then run `./fdf` with a text file that has a `.fdf` extension. I recommend running it with `make bonus` so you can perform some transformations on the model. ;)
