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

# The Base



<!-- !SECTION -->

\clearpage