# Artificial Intelligence Sessional

Lab work for **CSE-4202 Artificial Intelligence Sessional**, a lab course in the B.Sc. in CSE at BAUET (Bangladesh Army University of Engineering & Technology), written in the first half of 2024. Each lab implements a classic AI or machine-learning algorithm, mostly from scratch, in a Jupyter notebook; three labs also have a C or C++ version.

## Contents

### Day 1: Linear regression

| File | What it does |
| --- | --- |
| [Linear_Equation.ipynb](Day%201/Linear_Equation.ipynb) | Fits y = a1·x + a0 to four points by least squares with NumPy, then predicts y for a value you enter |
| [Linear_Equation.c](Day%201/Linear_Equation.c) | The same calculation in C |

### Day 2: K-nearest neighbours

| File | What it does |
| --- | --- |
| [KNN_classifier_V2.ipynb](Day%202/KNN_classifier_V2.ipynb) | A `KNNClassifier` class written with NumPy (k = 5), trained and tested on the Iris dataset (80/20 split) and compared with scikit-learn's `KNeighborsClassifier` |

### Day 3: A* search

| File | What it does |
| --- | --- |
| [A_Star_Algorithm.ipynb](Day%203/A_Star_Algorithm.ipynb) | A* search from Arad to Bucharest on the Romania road map, with straight-line distances to Bucharest as the heuristic; prints the path and its cost |
| [Huristic_Search_A_Star_Algorithm.cpp](Day%203/Huristic_Search_A_Star_Algorithm.cpp) | A* in C++ that reads the heuristics, edges, source and destination from standard input; the Romania map input is in a comment at the end of the file |

### Day 4: K-means clustering

| File | What it does |
| --- | --- |
| [K_means_algorithm.ipynb](Day%204/K_means_algorithm.ipynb) | K-means on seven 2-D points with NumPy (k = 3, random initial centroids) |
| [K_means_algorithm.cpp](Day%204/K_means_algorithm.cpp) | K-means in C++ with centroids you enter; prints the distances, clusters and updated centroids at every step. Sample inputs for k = 2 and k = 3 are in comments at the end |

### Day 5: Fuzzy logic

| File | What it does |
| --- | --- |
| [Fuzzy_Logic.ipynb](Day%205/Fuzzy_Logic.ipynb) | The tipping problem with scikit-fuzzy: food quality and service rated 0–10 give a tip of 0–25% through three fuzzy rules |

## Tech stack

- Python 3 in Jupyter notebooks: NumPy, Matplotlib, scikit-learn, scikit-fuzzy
- C and C++ for the console versions

## Getting started

Install the notebook dependencies and open the folder in Jupyter:

```bash
pip install notebook numpy matplotlib scikit-learn scikit-fuzzy
jupyter notebook
```

Compile and run the C and C++ programs with GCC (the C++ files include `<bits/stdc++.h>`, which is GCC-specific):

```bash
gcc "Day 1/Linear_Equation.c" -o linear_equation
g++ "Day 3/Huristic_Search_A_Star_Algorithm.cpp" -o astar
g++ "Day 4/K_means_algorithm.cpp" -o kmeans
```

The C++ programs read their input without prompts, so paste the sample input from the end of each file.

## Author

Md Arik Rayhan — [mdarikrayhan.com](https://mdarikrayhan.com)

## License

[MIT](LICENSE)
