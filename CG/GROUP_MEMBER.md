# Computer Graphics Group Project

## Group Members

1. **Menwuyelet Temesgen** — UGR/34920/16 — Sec. 5
2. **Yohannes Desta** — UGR/35682/16 — Sec. 5
3. **Nuredin Wario** — UGR/35196/16 — Sec. 6
4. **Biniyam Teku** — UGR/34102/16 — Sec. 6
5. **Betel Habtemariam** — UGR/34042/16 — Sec. 6


## How to Compile and Run the Applications

The following instructions explain how to compile and run the **Chess board** and **Race Car** OpenGL applications using `g++` and **GLUT**.

### Prerequisites

* C++ compiler (`g++`)
* OpenGL libraries installed
* GLUT / FreeGLUT installed

On Linux (Ubuntu/Debian), you can install required packages using:

```bash
sudo apt update
sudo apt install build-essential freeglut3-dev
```

### Compile Commands

#### 1. Compile `boat_chess.cpp`

```bash
g++ chess.cpp -o boat_chess -lGL -lGLU -lglut
```

#### 2. Compile `raceCar.cpp`

```bash
g++ raceCar.cpp -o raceCar -lGL -lGLU -lglut
```

### Run Commands

After successful compilation, run the applications using:

```bash
./chess
```

```bash
./raceCar
```

### Notes

* Make sure you are in the same directory as the `.cpp` files when running the commands.
* If you encounter permission issues, use:

```bash
chmod +x boat_chess raceCar
```

* On Windows, compilation requires **MinGW** and **FreeGLUT** properly configured.
