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

**To Do: A* 2D**

- * Point2D struct ( read from file ) : *
``cpp
  struct Point2D {
    double x,y;
    Point2D( double x, double y) : x(x), y(y) {}
  }
``
  
- *Function to calculate movement costs between two points:* 
  ``cpp
  double calculateCost(Point2D from, Point2D to);
  ``
- *Function to calculate heuristics (e.g., Euclidean distance) between a given point and the goal:*
  ``cpp
  double calculateHeuristic(Point2D current, Point2D goal);
 ``
- *Function to check the validity of points in space (whether a point is accessible for movement):*
  ``cpp
  bool isValidPoint(Point2D point);
  ``
- *Function to return information about visited nodes:*
  ``cpp
  vector<Point2D> getVisitedNodes();
  ``
- *Set / Get*
    - ``cpp void setCostFactors(double movementCost, double heuristicWeight); ``
    - ``cpp double getMovementCost(); ``
    - ``cpp double getHeuristicWeight(); ``
- *Path Finding Algorithm: *
  ``cpp
  vector<Point2D> findPath(Point2D start, Point2D goal);
  ``
   
  
    
