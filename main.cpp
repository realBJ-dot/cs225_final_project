#include "edge.h"
#include "graph.h"
#include <fstream>
#include "util.h"

using std::ifstream;

int main() {
  std::cout << "test main file" << std::endl;
  // process the dataset to graph
  Graph g_ = Graph(true, true);
  /**
   * load airport data. use i as a counter to keep track of different part of 
   * airport information
   */
  ifstream wordsFile("data/airports.dat");
  string word;
  if (wordsFile.is_open()) {
      /* Reads a line from `wordsFile` into `word` until the file ends. */
      while (getline(wordsFile, word)) {
          std::string part;
          std::istringstream ss(word);
          int counter = 0;
          string id;
          float latitude;
          float longitude;
          /** split single line on ','.
           * process information of a single airport 
           */
          while(std::getline(ss, part, ',')) {
             if (counter == 0) {
               id = part;
             } else if (counter == 6) {
               latitude = atof(part.c_str());
             } else if (counter == 7) {
               longitude = atof(part.c_str());
             }
             counter++;
          }
          Vertex v_ = Vertex(id, latitude, longitude);
          g_.insertVertex(v_);
      }
      
  }
  /**
   * load route data. use i as a counter to keep track of different part of 
   * routes information
   */
  ifstream wordsFile_("data/routes.dat");
  string word_;
  if (wordsFile_.is_open()) {
      /* Reads a line from `wordsFile` into `word` until the file ends. */
      while (getline(wordsFile_, word_)) {
          std::string part_;
          std::istringstream ss_(word_);
          int counter_ = 0;
          string source;
          string destination;
          /** split single line on ','.
          * process information of a single route 
           */
          while(std::getline(ss_, part_, ',')) {
            if (counter_ == 3) {
              source = part_;
            } else if (counter_ == 5) {
              destination = part_;
            }
            counter_++;  
          }
          Vertex s = Vertex(source);
          Vertex d = Vertex(destination);
          g_.insertEdge(s, d);
          
          
          
          
          
      }
  }


  /*set weight of edges as of distance*/
  for (auto e : g_.getEdges()) {
    double lat1 = e.source.getLatitude();
    double lng1 = e.source.getLongitude();
    double lat2 = e.dest.getLatitude();
    double lng2 = e.dest.getLongitude();
    double weight = distance_helper(lat1, lng1, lat2, lng2);
    g_.setEdgeWeight(e.source, e.dest, weight);
  }


  
  /**
   * collect user input to decided which algorithm to run
   */
  string choice;
  bool end = false;
  while (!end) {
    std::cout << "Please choose the algorithm you want to run" << std::endl;
    std::cout << "The available algorithms are: " << std::endl;
    std::cout << "DFS/BFS traversal (enter DFS for DFS and BFS for BFS)" << std::endl;
    std::cout << "Shortest path between two points (enter shortest_path)" << std::endl;
    std::cout << "Project onto map based on Openflight dataset (enter visualization)" << std::endl;
    std::cin >> choice;
    if (choice == "DFS") {
      // will be replaced later, place holder for now
      std::cout << "running DFS" << std::endl;
      end = true;
    } else if (choice == "BFS") {
      // will be replaced later, place holder for now
      std::cout << "running BFS" << std::endl;
      end = true;
    } else if (choice == "shortest_path") {
      // will be replaced later, place holder for now
      std::cout << "running shortest path" << std::endl;
      end = true;
    } else if (choice == "visualization") {
      // will be replaced later, place holder for now
      std::cout << "running visualization" << std::endl;
      end = true;
    } else {
      std::cout << "invalid choice, please try again" << std::endl;
    }
  }
  return 0;
}
