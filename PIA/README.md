# ELECTRIC CIRCUITS CALCULATOR


The main purpose of this program is to calculate the voltage, current and resistance of our circuits and for each component in it. 


The circuits can be connected in: 
 

* **SERIES**
* **PARALLEL**
* **MIXED**

<p align="center">
<img src="https://github.com/Rickgzz/C/blob/main/Exercises/example2.png">
</p>

## Structure

The principal structure of the code consist on a serie of question in a loop that collect all the input data in a couple of Structs, separating them depending of how the component is conected.

Once you have finished introduccing components, the code take them...

## Structs

```
struct SERIE{

    int num;
    float resistance, voltage, current;

} SERIE[MAX];
```
```
struct PARALLEL{

    int num;
    float resistance, voltage, current;
    
} PARALLEL[MAX];
```

## Functions

```
void SumRes(float*, float*, int, int);
```

```
void ValSerie(float*, int);
```

```
void ValParallel(float*, float*, float*, float*, int);
```

```
void PrintValues(float, float, float, int, int);
```

## Series & Parallel circuits

## Outputs

<p align="center">
<img src="https://github.com/Rickgzz/C/blob/main/Exercises/outputs.png">
</p>


## Execution

Files needed to run the code:

* [main.c](https://github.com/Rickgzz/C/blob/main/PIA/Project/mainV8.c)
* [functions.c](https://github.com/Rickgzz/C/blob/main/PIA/Project/functions.c)
* [header.h](https://github.com/Rickgzz/C/blob/main/PIA/Project/header.h)

Also is recomended to use VS Code.

## References
```
*  Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988). 
*  Examples made in class.
*  c-refcard.
```

## Author

| ID | Career | Name |
| ------------ | ------------ | ------------ |
| 1895539 | IME | Ricardo Gael Gonzalez Varela |


## Demo

**Watch a video of the code in action: [here](https://www.youtube.com/watch?v=dQw4w9WgXcQ)**

