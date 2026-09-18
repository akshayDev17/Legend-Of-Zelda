Graphics Zelda 3d Game
=========================

## Setup (macOS)

The game is written in C++ with OpenGL 3.3 Core and uses GLFW, GLEW and GLM.

### Prerequisites

* Xcode Command Line Tools (`xcode-select --install`)
* [Homebrew](https://brew.sh)

### Install dependencies

```bash
brew install cmake pkg-config glfw glew glm
```

### Build

```bash
cmake -S . -B build -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DCMAKE_CXX_FLAGS="-DGLM_ENABLE_EXPERIMENTAL"
cmake --build build -j
```

* `CMAKE_POLICY_VERSION_MINIMUM=3.5` lets CMake 4.x accept this project's old `cmake_minimum_required(VERSION 2.8)`.
* `GLM_ENABLE_EXPERIMENTAL` is required by recent GLM versions for the `glm/gtx/*` headers.

### Run

```bash
cd build
./graphics_asgn1
```

Run the game from inside `build/`, because it loads the `Sample_GL.vert` and `Sample_GL.frag` shaders from the current directory.

## Controls of the game:

* w,s,a,d = move forward,backward,left,right.
* p = fire cannon
* v  = change camera view
* mouse = for helicopter camera
* up  = disembark from boat
* up,down,left,right = move forward,backward,left,right for Link.
* b = when close to the boat, link will board it,
* press v to adjust after boarding the boat.




## Instructions while playing the game:

* The objective of the game is to score as much as possible before the game ends.
* Score can be increased by collecting gifts and killing monsters.
* Boat initially has 10 health points, displayed in the form of a bar, that reduces on collision with the rocks or the sea monsters.
* Health point bar: red region = 0-3hp, yellow region = 4-6hp, green region = 6-10 hp.
* Game ends when the boat loses all its health.
* Boat has a canon which is used to throw cannonballs on the monsters and the rocks.
* After killing some sea monsters, a boss monster will appear, and has a big reward once its killed.
* Boss inflicts more damage than the normal monster, hence be careful when closing in on it.
* Both kinds of monsters approach the boat.
* Giflts are present on floating barrels.
* multiplier meter = used for increasing score multiplier to 1.5X .
* Gifts include:
  * Health bonus
  * Multiplier bonus to 1.5X
* The score is shown via a seven segment display.



## Bonus:

* Game world is extended till infinity.
* If all rocks and monsters are avoided/killed, then the player can reach an island, exit the boat and collect the treasure, which has a value of upto 100points.

