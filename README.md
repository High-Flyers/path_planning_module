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
