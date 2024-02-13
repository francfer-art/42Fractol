![Banner](https://raw.githubusercontent.com/15Galan/42_project-readmes/master/banners/cursus/projects/fract-ol-dark.png)

<p align="center">
  <img src="https://raw.githubusercontent.com/mcombeau/mcombeau/main/42_badges/fract-olm.png" alt="Fractol Logo">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-brightgreen" alt="Fractol Score">
</p>

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#Prerequisites)
- [Usage](#Usage)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Avaliable Parameters](#avaliable-parameters)
- [Bonus](#bonus)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Fract'ol is a project in Computer Graphics focusing on rendering fractals using the MiniLibX library. This program allows users to explore and visualize the Mandelbrot set and the Julia set, with options to customize the Julia set by passing different parameters.

## Features

```
Renders the Mandelbrot set and the Julia set.
Zoom in and out using the mouse wheel, allowing exploration within the limits of the computer.
Creates different Julia sets by passing parameters through the command line.
Smooth window management, including switching between windows and minimizing.
Provides a clean exit when pressing ESC or clicking on the window's close button.
Utilizes colors to represent the depth of each fractal, with options for psychedelic effects.
```

## Prerequisites

MiniLibX library. You can use either the version available on the school machines or install it using its sources.

## Usage

MAke sure you have Xquartz installed in your machine.
```
Clone the repository.
Make sure you have Xquartz installed in your machine.
Compile the program using the provided Makefile.
Run the executable with optional parameters to specify the type of fractal to display and additional rendering options.
```

## Avaliable Parameters

If no parameter is provided or if the parameter is invalid, the program displays a list of available parameters and exits properly.
Additional parameters can be used as rendering options.

## Usage Example

```bash
make
./fractol [fractal_type] [rendering_options]
```
```
Replace [fractal_type] with the type of fractal to display (e.g., mandelbrot, julia).
Replace [rendering_options] with any additional rendering options (optional).
```

## Controls

```
Use the mouse wheel to zoom in and out.
Press ESC to close the window and quit the program cleanly.
Click on the close button on the window's frame to close the window and quit the program cleanly.
W / ⭡: Up
S / ⭣: Down
A / ⭠: Left
D / ⭢: Right
+ / -: Increase / Decrease Rendering Iterations
```

## Bonus Features

Additional Fractal: You can explore more than just the Mandelbrot and Julia sets with over a hundred different types of fractals available online. In this case i added burning, rose and newton sets!
Dynamic Zoom: The zoom follows the actual mouse position, providing a more intuitive exploration experience.
View Movement: Navigate through the fractals by pressing the arrow keys to move the view.
Color Range Shift: The color range dynamically shifts, enhancing the visual appeal of the fractals.

```bash
make bonus
./fractol_bonus [fractal_type]
```
```
Replace [fractal_type] with the type of fractal to display (e.g., burning, rose, newton).
```

## Contributing

Contributions are welcome! If you have improvements or additional features to suggest, please open an issue or submit a pull request. Follow the Contribution Guidelines for more details.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

