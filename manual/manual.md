---
documentclass: article
fontsize: 10pt
geometry:
  - margin=1cm
subparagraph: yes
title: no
numbersections: yes
graphics: yes
secnumdepth: 2
pagestyle: empty
output:
  pdf_document
header-includes:
  - |
    ````{=latex}
    \usepackage{kotex}
    \usepackage{tikz}
    ````
  - |
    ````{=latex}
    \newif\ifspecific
    \specifictrue
    \newcommand{\clearifspecific}{\ifspecific \clearpage \fi}
    ````
  - |
    ````{=latex}
    \usepackage{float}
    \newif\iffigure
    \figuretrue
    \graphicspath{ {./figures/} }
    \newcommand{\simplefig}[2]{\iffigure \begin{figure}[H] \centering #1 \caption{#2} \end{figure} \fi}
    \newcommand{\simplegraphic}[1]{\includegraphics[height=3.5cm]{#1}}
    ````
---

<!-- SECTION CPU -->

# Basic Hierarchy

## Finite State Machines

There are two main finite state machine models: the Moore model and the Mealy model.
Each model is declared in `FSM_(model).hpp`.

Both models are derived from the base class `FSM`, declared in `FSM.hpp`.
The FSM class composes the following basic components.

- a number of `States`
- an unified input
- an unified output

The FSM base class is templated with the input and output class form; the reasons elaborated soon.

## States

Similar with the FSMs, there are two kinds of states needed, one for each FSM kind.
Each state class is delcared in `State_(Model).hpp`.

Both models are derived from the base class `State`, declared in `State.hpp`.
The FSM class composes the following basic components.

- a unique numbered key generated for identification.
- a (optional) name for identification.
- a function that executes for each input.

# Construction of FSM

To make a custom FSM, first make an instance of the desired FSM class.

Then, add new `States` into the instance.
In order to find and call the next `State`, the `State` class contains the information of the contained FSM class.
Therefore, one `State` instance should only be assigned to one `FSM` instance only, as inserting a `State` instance will link the instance and modify the internals.

# State Transition

The overall execution is done when an input is given to the FSM.
When given an input to the FSM, the FSM will first find the `State` it is currently on, pass the input to the `State`, get the result and the next `State` of the FSM.

The `State` executes the inner codes and find and call the next `State` instance.
The `FSM` will catch this call and switch its state.

<!-- !SECTION -->

\clearpage