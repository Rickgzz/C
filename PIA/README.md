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

The main structure of the code consists of a series of questions in a loop that collects all the input data in a couple of Structs, separating them depending on how the component is connected.

After you have finished entering the components, the code will take all the data storage in the Structs and perform all the operations to get the expected values from the circuit.

### Structs

```
struct SERIE{

    int num;
    float resistance, voltage, current;

} SERIE[MAX];
```
* Here is were all the data related to the components connected in series will be storage, such as the component numbers, their individual resistance value, current and voltage.



```
struct PARALLEL{

    int num;
    float resistance, voltage, current;
    
} PARALLEL[MAX];
```
* Here is were all the data related to the components connected in parallel will be storage, such as the component numbers, their individual resistance value, current and voltage.

### Functions

```
void SumRes(float*, float*, int, int);
```
* The function *SumRes* is responsible for all the operations necessary to obtain the equivalent resistances of the components in parallel and to obtain the total resistance of the circuit.
  
```
void ValSerie(float*, int);
```
* The *ValSerie* function performs the necessary operations to obtain the individual values of each component in series.

```
void ValParallel(float*, float*, float*, float*, int);
```
* The *ValParallel* function first corroborates that exist components in parallel, if there are then continues to obtain the values given each component.

```
void PrintValues(float, float, float, int, int);
```
* The *PrintValues* function is responsible for printing both the total values of the circuit and the values of each component in it.


## Outputs

<p align="center">
<img src="https://github.com/Rickgzz/C/blob/main/Exercises/outputs.png">
</p>

The Outputs of the program are divided in 3 groups:


* First all the total values of the circuit will be printed.

* Then the all the individual values of each component conected in series will follow.

* Finally, if the circuit previously entered with has components connected in parallel, in this section all the values of each component will be printed.

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

**Watch a video of the code in action: [here](https://youtu.be/2JyMlISdWv0)**

