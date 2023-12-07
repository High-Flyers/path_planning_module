# path_planning_module
Creating a trajectory from the start point to the end point, in an environment with obstacles. A very popular problem, especially among autonomous vehicles.

**Gotowe rozwiązania:**
- AStar - Brak sensownej biblioteki. Na potrzeby zawodów zaimplementowaliśmy swoją własną wersję AUAV 2023. Jest to najpopularniejszy algorytm wykorzystywany w path planningu, ze względu na szybkość i działanie w przestrzeni zapewniającej znalezienie optymalnej ścieżki.
- RRT, RRT* itp. - OMPL popularna biblioteka do C++ (opcja Python Bindings), skupia się ona jedynie wokół algorytmów próbkujących przestrzeń, w której operują (użyta w AUAV 2022). Algorytmy te nie są ograniczone do rozdzielczości przestrzeni, jednak są one z reguły wolniejsze, nie znajdują optymalnego rozwiązania, przez co wymagają optymalizacji ścieżki (np. Path Smoothing, który może prowadzić do stworzenia ścieżki z kolizją).


**Wymagania:**
- Wydzielić wspólny interfejs do rozwiązań.
- Walidacja ścieżki (sprawdzanie, czy ścieżka nie ma kolizji z otoczeniem).
- Replanning ścieżki od miejsca kolizji na trajektorii.
- Tworzenie przestrzeni do sprawdzania kolizji (np. octomap).
- Planowanie ścieżki bez kolizji od punktu A do B.

**To Do: AStar 2D**

- **Point2D struct ( read from file ) :**
```cpp
  struct Point2D {
    double x,y;
    Point2D( double x, double y) : x(x), y(y) {}
  }
```
  
- **Function to calculate movement costs between two points:** 
  ```cpp
  double calculateCost(Point2D from, Point2D to);
  ```
- **Function to calculate heuristics (e.g., Euclidean distance) between a given point and the goal:**
  ```cpp
  double calculateHeuristic(Point2D current, Point2D goal);
   ```
- **Function to check the validity of points in space (whether a point is accessible for movement):**
  ```cpp
  bool isValidPoint(Point2D point);
  ```
- **Function to return information about visited nodes:**
  ```cpp
  vector<Point2D> getVisitedNodes();
  ```
- **Set / Get**
    - ```cpp
      void setCostFactors(double movementCost, double heuristicWeight);
      ```
    - ```cpp
      double getMovementCost();
      ```
    - ```cpp
      double getHeuristicWeight();
      ```
- **Path Finding Algorithm:**
  ```cpp
  vector<Point2D> findPath(Point2D start, Point2D goal);
  ```

# Documentation

## `double A_star_2D::calculateHeuristic(Point2D current, Point2D goal)`

This function calculates the heuristic value (estimated cost) using the Euclidean distance between the current point and the goal point in a two-dimensional space.

### Parameters:
- `current`: The current point in the 2D space.
- `goal`: The goal point to which the algorithm is navigating.

### Return Value:
- Returns a `double` representing the Euclidean distance between the current point and the goal.

### Example Usage:
```cpp
A_star_2D astar;
Point2D currentPoint(1.0, 2.0);
Point2D goalPoint(5.0, 6.0);
double heuristicValue = astar.calculateHeuristic(currentPoint, goalPoint);
```

## `void A_star_2D::setCostFactors(double movementCost, double heuristicWeight)`

This function allows the adjustment of key parameters in the A* algorithm related to movement costs and heuristic weight.

### Parameters:
- `movementCost`: The cost associated with moving from one point to an adjacent point in the 2D space. It influences the pathfinding algorithm by determining the cost of transitions between points.
- `heuristicWeight`: The weight assigned to the heuristic function. It affects how much the estimated cost (heuristic) influences the choice of the next point during the pathfinding process.

### Usage:
```cpp
A_star_2D astar;
astar.setCostFactors(1.5, 2.0);
```

### Example Explanation:

In the example above, the setCostFactors function is used to set the movement cost to 1.5 and the heuristic weight to 2.0.
Adjusting these parameters can impact the behavior of the A* algorithm, allowing flexibility in adapting the algorithm to different scenarios.

### Notes:

The movementCost and heuristicWeight parameters should be positive values.
Experimentation with different parameter values may be necessary to find the most suitable configuration for a specific use case.

## `double A_star_2D::getMovementCost()`

This function retrieves the current movement cost value set for the A* algorithm.

### Return Value:
- Returns a `double` representing the current movement cost.

### Usage:
```cpp
A_star_2D astar;
double currentMovementCost = astar.getMovementCost();
```

## `double A_star_2D::getHeuristicWeight()`

This function retrieves the current heuristic weight value set for the A* algorithm.

### Return Value:
- Returns a `double` representing the current heuristic weight.

### Usage:
```cpp
A_star_2D astar;
double currentHeuristicWeight = astar.getHeuristicWeight();
```