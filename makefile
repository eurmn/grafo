all: graph

graph: graph.cpp
    g++ -o graph graph.cpp

run: graph
    ./graph

clean:
    rm -f graph